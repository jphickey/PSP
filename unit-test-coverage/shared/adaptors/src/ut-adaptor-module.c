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
 * \ingroup  adaptors
 *
 */

#include "ut-adaptor-module.h"
#include "target_config.h"
#include "cfe_psp_module.h"

const char *UT_Module_PeekEntryName(bool IsInternal, size_t EntryNum)
{
    CFE_StaticModuleLoadEntry_t *ListPtr;

    if (IsInternal)
    {
        ListPtr = CFE_PSP_BASE_MODULE_LIST;
    }
    else
    {
        ListPtr = GLOBAL_CONFIGDATA.PspModuleList;
    }

    while (EntryNum > 0 && ListPtr != NULL && ListPtr->Name != NULL)
    {
        --EntryNum;
        ++ListPtr;
    }

    if (ListPtr != NULL)
    {
        return ListPtr->Name;
    }

    return NULL;
}
