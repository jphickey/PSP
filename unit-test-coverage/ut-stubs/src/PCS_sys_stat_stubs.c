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
 * @file
 *
 * Auto-Generated stub implementations for functions defined in PCS_sys_stat header
 */

#include <stdarg.h>

#include "PCS_sys_stat.h"
#include "utgenstub.h"

/*
 * ----------------------------------------------------
 * Generated stub function for PCS_open()
 * ----------------------------------------------------
 */
int PCS_open(const char *path, int oflag, ...)
{
    va_list UtStub_ArgList;

    UT_GenStub_SetupReturnBuffer(PCS_open, int);

    UT_GenStub_AddParam(PCS_open, const char *, path);
    UT_GenStub_AddParam(PCS_open, int, oflag);

    va_start(UtStub_ArgList, oflag);
    UT_GenStub_Execute(PCS_open, Va, NULL, UtStub_ArgList);
    va_end(UtStub_ArgList);

    return UT_GenStub_GetReturnValue(PCS_open, int);
}

/*
 * ----------------------------------------------------
 * Generated stub function for PCS_stat()
 * ----------------------------------------------------
 */
int PCS_stat(const char *path, struct PCS_stat *buf)
{
    UT_GenStub_SetupReturnBuffer(PCS_stat, int);

    UT_GenStub_AddParam(PCS_stat, const char *, path);
    UT_GenStub_AddParam(PCS_stat, struct PCS_stat *, buf);

    UT_GenStub_Execute(PCS_stat, Basic, NULL);

    return UT_GenStub_GetReturnValue(PCS_stat, int);
}
