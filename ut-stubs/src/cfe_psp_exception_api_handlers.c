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
** File: ut_bsp_stubs.c
**
** Purpose:
** Unit test stubs for BSP routines
**
** Notes:
** Minimal work is done, only what is required for unit testing
**
*/

/*
** Includes
*/

#include "cfe_psp.h"
#include "utstubs.h"
#include <string.h>

#include "target_config.h"

void UT_DefaultHandler_CFE_PSP_Exception_GetSummary(void *UserObj, UT_EntryKey_t FuncKey,
                                                    const UT_StubContext_t *Context)
{
    /* int32 CFE_PSP_Exception_GetSummary(uint32 *ContextLogId, osal_id_t *TaskId, char *ReasonBuf, uint32 ReasonSize)
     */
    osal_id_t *TaskId = UT_Hook_GetArgValueByName(Context, "TaskId", osal_id_t *);

    int32 status;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0 && !OS_ObjectIdDefined(*TaskId))
    {
        UT_Stub_CopyToLocal(UT_KEY(CFE_PSP_Exception_GetSummary), TaskId, sizeof(*TaskId));
    }
}

void UT_DefaultHandler_CFE_PSP_Exception_CopyContext(void *UserObj, UT_EntryKey_t FuncKey,
                                                     const UT_StubContext_t *Context)
{
    /* int32 CFE_PSP_Exception_CopyContext(uint32 ContextLogId, void *ContextBuf, uint32 ContextSize) */
    void * ContextBuf  = UT_Hook_GetArgValueByName(Context, "ContextBuf", void *);
    uint32 ContextSize = UT_Hook_GetArgValueByName(Context, "ContextSize", uint32);
    int32  status;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0)
    {
        status = UT_Stub_CopyToLocal(UT_KEY(CFE_PSP_Exception_CopyContext), ContextBuf, ContextSize);
    }
}
