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

/*
 *
 *    Copyright (c) 2020, United States government as represented by the
 *    administrator of the National Aeronautics Space Administration.
 *    All rights reserved. This software was created at NASA Goddard
 *    Space Flight Center pursuant to government contracts.
 *
 *    This is governed by the NASA Open Source Agreement and may be used,
 *    distributed and modified only according to the terms of that agreement.
 *
 */

/**
 * \file
 * \ingroup  shared
 */

#include "utassert.h"
#include "utstubs.h"

#include "cfe_psp_module.h"

extern uint32_t CFE_PSP_ModuleInitList(uint32 BaseId, CFE_StaticModuleLoadEntry_t *ListPtr);

void Test_CFE_PSP_ModuleInitList(void)
{
    /* Test Case for:
     * uint32_t CFE_PSP_ModuleInitList(uint32 BaseId, CFE_StaticModuleLoadEntry_t *ListPtr)
     */
    CFE_StaticModuleLoadEntry_t ListPtr[1] = {{0}};

    UtAssert_UINT32_EQ(CFE_PSP_ModuleInitList(1, ListPtr), 0);
}

void Test_CFE_PSP_ModuleInit(void)
{
    /* Test Case for:
     * void CFE_PSP_ModuleInit(void)
     */
    UtAssert_VOIDCALL(CFE_PSP_ModuleInit());
}

void Test_CFE_PSP_Module_GetAPIEntry(void)
{
    /* Test Case for:
     * int32 CFE_PSP_Module_GetAPIEntry(uint32 PspModuleId, CFE_PSP_ModuleApi_t **API)
     */
    CFE_PSP_ModuleApi_t *API;

    UtAssert_INT32_EQ(CFE_PSP_Module_GetAPIEntry(0, &API), CFE_PSP_INVALID_MODULE_ID);
}

void Test_CFE_PSP_Module_FindByName(void)
{
    /* Test Case for:
     * int32 CFE_PSP_Module_FindByName(const char *ModuleName, uint32 *PspModuleId)
     */
    uint32 ModuleId;
    UtAssert_INT32_EQ(CFE_PSP_Module_FindByName("UT", &ModuleId), CFE_PSP_INVALID_MODULE_NAME);
}
