/************************************************************************
 * NASA Docket No. GSC-18,719-1, and identified as “core Flight System: Bootes”
 *
 * Copyright (c) 2020 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/**
 * \file
 *
 *  Created on: Jul 25, 2014
 *      Author: jphickey
 */

#include <stdio.h>
#include <string.h>
#include "osapi.h"

#include "cfe_psp_module.h"

/*
 * When using an OSAL that also supports "opaque object ids", choose values here
 * that will fit in with the OSAL object ID values and not overlap anything.
 */
#ifdef OS_OBJECT_TYPE_USER
#define CFE_PSP_MODULE_BASE       ((OS_OBJECT_TYPE_USER + 0x100) << OS_OBJECT_TYPE_SHIFT)
#define CFE_PSP_MODULE_INDEX_MASK OS_OBJECT_INDEX_MASK
#else
#define CFE_PSP_MODULE_BASE       0x01100000
#define CFE_PSP_MODULE_INDEX_MASK 0xFFFF
#endif

/*
 * Internal/base modules typically should not be the subject
 * of a call to CFE_PSP_Module_FindByName or GetAPI,
 * so they are assigned IDs at the END of the space,
 * this makes them unique but they are otherwise not used
 *
 * Reserve the last 256 entries for base modules
 */
#define CFE_PSP_INTERNAL_MODULE_BASE ((CFE_PSP_MODULE_BASE | CFE_PSP_MODULE_INDEX_MASK) & ~0xFF)

static uint32 CFE_PSP_ConfigPspModuleListLength   = 0;
static uint32 CFE_PSP_StandardPspModuleListLength = 0;

/***************************************************
 *
 * Helper function to initialize a list of modules (not externally called)
 * Returns the number of modules initialized
 */
uint32_t CFE_PSP_ModuleInitList(uint32 BaseId, CFE_StaticModuleLoadEntry_t *ListPtr)
{
    CFE_StaticModuleLoadEntry_t *Entry;
    CFE_PSP_ModuleApi_t *        ApiPtr;
    uint32                       ModuleCount;
    uint32                       ModuleId;

    /*
     * Call the init function for all statically linked modules
     */
    Entry       = ListPtr;
    ModuleCount = 0;
    if (Entry != NULL)
    {
        while (Entry->Name != NULL)
        {
            ApiPtr   = (CFE_PSP_ModuleApi_t *)Entry->Api;
            ModuleId = BaseId + ModuleCount;
            if ((uint32)ApiPtr->ModuleType != CFE_PSP_MODULE_TYPE_INVALID && ApiPtr->Init != NULL)
            {
                printf("CFE_PSP: initializing module \'%s\' with ID %08lx\n", Entry->Name, (unsigned long)ModuleId);
                (*ApiPtr->Init)(ModuleId);
            }
            ++Entry;
            ++ModuleCount;
        }
    }

    return ModuleCount;
}

/***************************************************
 *
 * See prototype for full description
 */
void CFE_PSP_ModuleInit(void)
{
    /* First initialize the fixed set of modules for this PSP */
    CFE_PSP_StandardPspModuleListLength =
        CFE_PSP_ModuleInitList(CFE_PSP_INTERNAL_MODULE_BASE, CFE_PSP_BASE_MODULE_LIST);

    /* Then initialize any user-selected extension modules */
    CFE_PSP_ConfigPspModuleListLength = CFE_PSP_ModuleInitList(CFE_PSP_MODULE_BASE, GLOBAL_CONFIGDATA.PspModuleList);
}

/***************************************************
 *
 * See prototype for full description
 */
int32 CFE_PSP_Module_GetAPIEntry(uint32 PspModuleId, CFE_PSP_ModuleApi_t **API)
{
    int32  Result;
    uint32 LocalId;

    Result = CFE_PSP_INVALID_MODULE_ID;
    if ((PspModuleId & ~CFE_PSP_MODULE_INDEX_MASK) == CFE_PSP_MODULE_BASE)
    {
        /* Last 256 enteries are for internal modules */
        if ((PspModuleId & CFE_PSP_MODULE_INDEX_MASK) >= 0xFF00)
        {
            LocalId = PspModuleId & 0xFF;
            if (LocalId < CFE_PSP_StandardPspModuleListLength)
            {
                *API   = (CFE_PSP_ModuleApi_t *)CFE_PSP_BASE_MODULE_LIST[LocalId].Api;
                Result = CFE_PSP_SUCCESS;
            }
        }
        else
        {
            LocalId = PspModuleId & CFE_PSP_MODULE_INDEX_MASK;
            if (LocalId < CFE_PSP_ConfigPspModuleListLength)
            {
                *API   = (CFE_PSP_ModuleApi_t *)GLOBAL_CONFIGDATA.PspModuleList[LocalId].Api;
                Result = CFE_PSP_SUCCESS;
            }
        }
    }

    return Result;
}

uint32 CFE_PSP_Module_SearchNameInList(CFE_StaticModuleLoadEntry_t *ListPtr, size_t ListLength, bool IsInternal,
                                       const char *ModuleName)
{
    CFE_StaticModuleLoadEntry_t *Entry;
    uint32                       ResultId;
    size_t                       i;

    Entry    = ListPtr;
    ResultId = 0;
    i        = 0;

    while (i < ListLength)
    {
        if (strcmp(Entry->Name, ModuleName) == 0)
        {
            if (IsInternal)
            {
                ResultId = CFE_PSP_INTERNAL_MODULE_BASE;
            }
            else
            {
                ResultId = CFE_PSP_MODULE_BASE;
            }
            ResultId |= (i & CFE_PSP_MODULE_INDEX_MASK);
            break;
        }

        ++Entry;
        ++i;
    }

    return ResultId;
}

/***************************************************
 *
 * See prototype for full description
 */
int32 CFE_PSP_Module_FindByName(const char *ModuleName, uint32 *PspModuleId)
{
    int32  Result;
    uint32 CheckId;

    /* Check global list */
    CheckId = CFE_PSP_Module_SearchNameInList(GLOBAL_CONFIGDATA.PspModuleList, CFE_PSP_ConfigPspModuleListLength, false,
                                              ModuleName);
    if (CheckId == 0)
    {
        CheckId = CFE_PSP_Module_SearchNameInList(CFE_PSP_BASE_MODULE_LIST, CFE_PSP_StandardPspModuleListLength, true,
                                                  ModuleName);
    }

    if (CheckId != 0)
    {
        Result = CFE_PSP_SUCCESS;
    }
    else
    {
        Result = CFE_PSP_INVALID_MODULE_NAME;
    }

    *PspModuleId = CheckId;

    return Result;
}
