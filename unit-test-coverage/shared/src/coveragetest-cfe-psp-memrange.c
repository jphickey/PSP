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
 * \ingroup  vxworks
 */

#include "utassert.h"
#include "utstubs.h"

#include "ut-adaptor-memrange.h"
#include "cfe_psp_memrange_api.h"

void Test_CFE_PSP_MemValidateRange(void)
{
    /* Test Case For:
     * int32 CFE_PSP_MemValidateRange(cpuaddr Address, size_t Size, uint32 MemoryType)
     */
    UtAssert_INT32_EQ(CFE_PSP_MemValidateRange(0, 32, 0), CFE_PSP_INVALID_MEM_TYPE);
    UtAssert_INT32_EQ(CFE_PSP_MemValidateRange(-1, 32, CFE_PSP_MEM_RAM), CFE_PSP_INVALID_MEM_RANGE);
    UtAssert_INT32_EQ(CFE_PSP_MemValidateRange(0, 32, CFE_PSP_MEM_RAM), CFE_PSP_SUCCESS);
}

void Test_CFE_PSP_MemRanges(void)
{
    /* Test Case For:
     * uint32 CFE_PSP_MemRanges(void)
     */
    UtAssert_NONZERO(CFE_PSP_MemRanges());
}

void Test_CFE_PSP_MemRangeSet(void)
{
    /* Test Case For:
     * int32 CFE_PSP_MemRangeSet(uint32 RangeNum, uint32 MemoryType, cpuaddr StartAddr, size_t Size, size_t WordSize,
     * uint32 Attributes)
     */
    UtAssert_INT32_EQ(CFE_PSP_MemRangeSet(0, CFE_PSP_MEM_RAM, 0, 32, 4, 0), CFE_PSP_INVALID_MEM_ATTR);
}

void Test_CFE_PSP_MemRangeGet(void)
{
    /* Test Case For:
     * int32 CFE_PSP_MemRangeGet(uint32 RangeNum, uint32 *MemoryType, cpuaddr *StartAddr, size_t *Size, size_t
     * *WordSize, uint32 *Attributes)
     */
    uint32  MemType;
    cpuaddr StartAddr;
    size_t  MemSize;
    size_t  WordSize;
    uint32  Attribs;

    UtAssert_INT32_EQ(CFE_PSP_MemRangeGet(0, &MemType, &StartAddr, &MemSize, &WordSize, &Attribs), CFE_PSP_SUCCESS);
}
