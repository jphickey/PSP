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
 * \ingroup  modules
 *
 * Coverage test for VxWorks timebase module implementation
 */

#include "utassert.h"
#include "utstubs.h"
#include "uttest.h"

#include "cfe_psp.h"
#include "cfe_psp_config.h"
#include "cfe_psp_module.h"

/* This does not have a prototype */
extern void port_notimpl_Init(uint32 PspModuleId);

void Test_port_notimpl_Init(void)
{
    /*
    Test case for:
    void port_notimpl_Init(uint32 PspModuleId)
    */
    UtAssert_VOIDCALL(port_notimpl_Init(1));
}

void Test_CFE_PSP_PortRead8(void)
{
    /*
    Test Case for:
    int32 CFE_PSP_PortRead8(cpuaddr PortAddress, uint8 *ByteValue)
    */
    uint8 Value;
    UtAssert_INT32_EQ(CFE_PSP_PortRead8(0, &Value), CFE_PSP_ERROR_NOT_IMPLEMENTED);
}

void Test_CFE_PSP_PortWrite8(void)
{
    /*
    Test Case for:
    int32 CFE_PSP_PortWrite8(cpuaddr PortAddress, uint8 ByteValue)
    */
    UtAssert_INT32_EQ(CFE_PSP_PortWrite8(0, 1), CFE_PSP_ERROR_NOT_IMPLEMENTED);
}

void Test_CFE_PSP_PortRead16(void)
{
    /*
    Test Case for:
    int32 CFE_PSP_PortRead16(cpuaddr PortAddress, uint16 *uint16Value)
    */
    uint16 Value;
    UtAssert_INT32_EQ(CFE_PSP_PortRead16(0, &Value), CFE_PSP_ERROR_NOT_IMPLEMENTED);
}

void Test_CFE_PSP_PortWrite16(void)
{
    /*
    Test Case for:
    int32 CFE_PSP_PortWrite16(cpuaddr PortAddress, uint16 uint16Value)
    */
    UtAssert_INT32_EQ(CFE_PSP_PortWrite16(0, 1), CFE_PSP_ERROR_NOT_IMPLEMENTED);
}

void Test_CFE_PSP_PortRead32(void)
{
    /*
    Test Case for:
    int32 CFE_PSP_PortRead32(cpuaddr PortAddress, uint32 *uint32Value)
    */
    uint32 Value;
    UtAssert_INT32_EQ(CFE_PSP_PortRead32(0, &Value), CFE_PSP_ERROR_NOT_IMPLEMENTED);
}

void Test_CFE_PSP_PortWrite32(void)
{
    /*
    Test Case for:
    int32 CFE_PSP_PortWrite32(cpuaddr PortAddress, uint32 uint32Value)
    */
    UtAssert_INT32_EQ(CFE_PSP_PortWrite32(0, 1), CFE_PSP_ERROR_NOT_IMPLEMENTED);
}

/*
 * Macro to add a test case to the list of tests to execute
 */
#define ADD_TEST(test) UtTest_Add(test, NULL, NULL, #test)

/*
 * Register the test cases to execute with the unit test tool
 */
void UtTest_Setup(void)
{
    ADD_TEST(Test_CFE_PSP_PortRead8);
    ADD_TEST(Test_CFE_PSP_PortWrite8);
    ADD_TEST(Test_CFE_PSP_PortRead16);
    ADD_TEST(Test_CFE_PSP_PortWrite16);
    ADD_TEST(Test_CFE_PSP_PortRead32);
    ADD_TEST(Test_CFE_PSP_PortWrite32);
}
