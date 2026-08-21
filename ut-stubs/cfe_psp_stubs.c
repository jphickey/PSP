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
 * Auto-Generated stub implementations for functions defined in cfe_psp header
 */

#include "cfe_psp.h"
#include "utgenstub.h"

void UT_DefaultHandler_CFE_PSP_Exception_CopyContext(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_Exception_GetSummary(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_GetCDSSize(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_GetProcessorName(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_GetResetArea(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_GetTime(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_GetVersionCodeName(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_GetVersionString(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_GetVolatileDiskMem(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_Get_Timebase(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_MemCpy(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_MemRead8(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_MemSet(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_Panic(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_ReadFromCDS(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_Restart(void *, UT_EntryKey_t, const UT_StubContext_t *);
void UT_DefaultHandler_CFE_PSP_WriteToCDS(void *, UT_EntryKey_t, const UT_StubContext_t *);

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_AttachExceptions()
 * ----------------------------------------------------
 */
void CFE_PSP_AttachExceptions(void)
{
    UT_GenStub_Execute(CFE_PSP_AttachExceptions, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Decompress()
 * ----------------------------------------------------
 */
int32 CFE_PSP_Decompress(char *srcFileName, char *dstFileName)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_Decompress, int32);

    UT_GenStub_AddParam(CFE_PSP_Decompress, char *, srcFileName);
    UT_GenStub_AddParam(CFE_PSP_Decompress, char *, dstFileName);

    UT_GenStub_Execute(CFE_PSP_Decompress, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_Decompress, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_EepromPowerDown()
 * ----------------------------------------------------
 */
int32 CFE_PSP_EepromPowerDown(uint32 Bank)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_EepromPowerDown, int32);

    UT_GenStub_AddParam(CFE_PSP_EepromPowerDown, uint32, Bank);

    UT_GenStub_Execute(CFE_PSP_EepromPowerDown, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_EepromPowerDown, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_EepromPowerUp()
 * ----------------------------------------------------
 */
int32 CFE_PSP_EepromPowerUp(uint32 Bank)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_EepromPowerUp, int32);

    UT_GenStub_AddParam(CFE_PSP_EepromPowerUp, uint32, Bank);

    UT_GenStub_Execute(CFE_PSP_EepromPowerUp, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_EepromPowerUp, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_EepromWrite16()
 * ----------------------------------------------------
 */
int32 CFE_PSP_EepromWrite16(cpuaddr MemoryAddress, uint16 uint16Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_EepromWrite16, int32);

    UT_GenStub_AddParam(CFE_PSP_EepromWrite16, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_EepromWrite16, uint16, uint16Value);

    UT_GenStub_Execute(CFE_PSP_EepromWrite16, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_EepromWrite16, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_EepromWrite32()
 * ----------------------------------------------------
 */
int32 CFE_PSP_EepromWrite32(cpuaddr MemoryAddress, uint32 uint32Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_EepromWrite32, int32);

    UT_GenStub_AddParam(CFE_PSP_EepromWrite32, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_EepromWrite32, uint32, uint32Value);

    UT_GenStub_Execute(CFE_PSP_EepromWrite32, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_EepromWrite32, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_EepromWrite8()
 * ----------------------------------------------------
 */
int32 CFE_PSP_EepromWrite8(cpuaddr MemoryAddress, uint8 ByteValue)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_EepromWrite8, int32);

    UT_GenStub_AddParam(CFE_PSP_EepromWrite8, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_EepromWrite8, uint8, ByteValue);

    UT_GenStub_Execute(CFE_PSP_EepromWrite8, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_EepromWrite8, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_EepromWriteDisable()
 * ----------------------------------------------------
 */
int32 CFE_PSP_EepromWriteDisable(uint32 Bank)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_EepromWriteDisable, int32);

    UT_GenStub_AddParam(CFE_PSP_EepromWriteDisable, uint32, Bank);

    UT_GenStub_Execute(CFE_PSP_EepromWriteDisable, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_EepromWriteDisable, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_EepromWriteEnable()
 * ----------------------------------------------------
 */
int32 CFE_PSP_EepromWriteEnable(uint32 Bank)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_EepromWriteEnable, int32);

    UT_GenStub_AddParam(CFE_PSP_EepromWriteEnable, uint32, Bank);

    UT_GenStub_Execute(CFE_PSP_EepromWriteEnable, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_EepromWriteEnable, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Exception_CopyContext()
 * ----------------------------------------------------
 */
int32 CFE_PSP_Exception_CopyContext(uint32 ContextLogId, void *ContextBuf, uint32 ContextSize)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_Exception_CopyContext, int32);

    UT_GenStub_AddParam(CFE_PSP_Exception_CopyContext, uint32, ContextLogId);
    UT_GenStub_AddParam(CFE_PSP_Exception_CopyContext, void *, ContextBuf);
    UT_GenStub_AddParam(CFE_PSP_Exception_CopyContext, uint32, ContextSize);

    UT_GenStub_Execute(CFE_PSP_Exception_CopyContext, Basic, UT_DefaultHandler_CFE_PSP_Exception_CopyContext);

    return UT_GenStub_GetReturnValue(CFE_PSP_Exception_CopyContext, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Exception_GetCount()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_Exception_GetCount(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_Exception_GetCount, uint32);

    UT_GenStub_Execute(CFE_PSP_Exception_GetCount, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_Exception_GetCount, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Exception_GetSummary()
 * ----------------------------------------------------
 */
int32 CFE_PSP_Exception_GetSummary(uint32 *ContextLogId, osal_id_t *TaskId, char *ReasonBuf, uint32 ReasonSize)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_Exception_GetSummary, int32);

    UT_GenStub_AddParam(CFE_PSP_Exception_GetSummary, uint32 *, ContextLogId);
    UT_GenStub_AddParam(CFE_PSP_Exception_GetSummary, osal_id_t *, TaskId);
    UT_GenStub_AddParam(CFE_PSP_Exception_GetSummary, char *, ReasonBuf);
    UT_GenStub_AddParam(CFE_PSP_Exception_GetSummary, uint32, ReasonSize);

    UT_GenStub_Execute(CFE_PSP_Exception_GetSummary, Basic, UT_DefaultHandler_CFE_PSP_Exception_GetSummary);

    return UT_GenStub_GetReturnValue(CFE_PSP_Exception_GetSummary, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_FlushCaches()
 * ----------------------------------------------------
 */
void CFE_PSP_FlushCaches(uint32 type, void *address, uint32 size)
{
    UT_GenStub_AddParam(CFE_PSP_FlushCaches, uint32, type);
    UT_GenStub_AddParam(CFE_PSP_FlushCaches, void *, address);
    UT_GenStub_AddParam(CFE_PSP_FlushCaches, uint32, size);

    UT_GenStub_Execute(CFE_PSP_FlushCaches, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetBuildNumber()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_GetBuildNumber(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetBuildNumber, uint32);

    UT_GenStub_Execute(CFE_PSP_GetBuildNumber, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetBuildNumber, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetCDSSize()
 * ----------------------------------------------------
 */
int32 CFE_PSP_GetCDSSize(uint32 *SizeOfCDS)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetCDSSize, int32);

    UT_GenStub_AddParam(CFE_PSP_GetCDSSize, uint32 *, SizeOfCDS);

    UT_GenStub_Execute(CFE_PSP_GetCDSSize, Basic, UT_DefaultHandler_CFE_PSP_GetCDSSize);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetCDSSize, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetCFETextSegmentInfo()
 * ----------------------------------------------------
 */
int32 CFE_PSP_GetCFETextSegmentInfo(cpuaddr *PtrToCFESegment, uint32 *SizeOfCFESegment)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetCFETextSegmentInfo, int32);

    UT_GenStub_AddParam(CFE_PSP_GetCFETextSegmentInfo, cpuaddr *, PtrToCFESegment);
    UT_GenStub_AddParam(CFE_PSP_GetCFETextSegmentInfo, uint32 *, SizeOfCFESegment);

    UT_GenStub_Execute(CFE_PSP_GetCFETextSegmentInfo, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetCFETextSegmentInfo, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetKernelTextSegmentInfo()
 * ----------------------------------------------------
 */
int32 CFE_PSP_GetKernelTextSegmentInfo(cpuaddr *PtrToKernelSegment, uint32 *SizeOfKernelSegment)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetKernelTextSegmentInfo, int32);

    UT_GenStub_AddParam(CFE_PSP_GetKernelTextSegmentInfo, cpuaddr *, PtrToKernelSegment);
    UT_GenStub_AddParam(CFE_PSP_GetKernelTextSegmentInfo, uint32 *, SizeOfKernelSegment);

    UT_GenStub_Execute(CFE_PSP_GetKernelTextSegmentInfo, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetKernelTextSegmentInfo, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetProcessorId()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_GetProcessorId(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetProcessorId, uint32);

    UT_GenStub_Execute(CFE_PSP_GetProcessorId, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetProcessorId, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetProcessorName()
 * ----------------------------------------------------
 */
const char *CFE_PSP_GetProcessorName(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetProcessorName, const char *);

    UT_GenStub_Execute(CFE_PSP_GetProcessorName, Basic, UT_DefaultHandler_CFE_PSP_GetProcessorName);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetProcessorName, const char *);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetResetArea()
 * ----------------------------------------------------
 */
int32 CFE_PSP_GetResetArea(cpuaddr *PtrToResetArea, uint32 *SizeOfResetArea)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetResetArea, int32);

    UT_GenStub_AddParam(CFE_PSP_GetResetArea, cpuaddr *, PtrToResetArea);
    UT_GenStub_AddParam(CFE_PSP_GetResetArea, uint32 *, SizeOfResetArea);

    UT_GenStub_Execute(CFE_PSP_GetResetArea, Basic, UT_DefaultHandler_CFE_PSP_GetResetArea);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetResetArea, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetRestartType()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_GetRestartType(uint32 *restartSubType)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetRestartType, uint32);

    UT_GenStub_AddParam(CFE_PSP_GetRestartType, uint32 *, restartSubType);

    UT_GenStub_Execute(CFE_PSP_GetRestartType, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetRestartType, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetSpacecraftId()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_GetSpacecraftId(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetSpacecraftId, uint32);

    UT_GenStub_Execute(CFE_PSP_GetSpacecraftId, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetSpacecraftId, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetTime()
 * ----------------------------------------------------
 */
void CFE_PSP_GetTime(OS_time_t *LocalTime)
{
    UT_GenStub_AddParam(CFE_PSP_GetTime, OS_time_t *, LocalTime);

    UT_GenStub_Execute(CFE_PSP_GetTime, Basic, UT_DefaultHandler_CFE_PSP_GetTime);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetTimerLow32Rollover()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_GetTimerLow32Rollover(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetTimerLow32Rollover, uint32);

    UT_GenStub_Execute(CFE_PSP_GetTimerLow32Rollover, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetTimerLow32Rollover, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetTimerTicksPerSecond()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_GetTimerTicksPerSecond(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetTimerTicksPerSecond, uint32);

    UT_GenStub_Execute(CFE_PSP_GetTimerTicksPerSecond, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetTimerTicksPerSecond, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetUserReservedArea()
 * ----------------------------------------------------
 */
int32 CFE_PSP_GetUserReservedArea(cpuaddr *PtrToUserArea, uint32 *SizeOfUserArea)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetUserReservedArea, int32);

    UT_GenStub_AddParam(CFE_PSP_GetUserReservedArea, cpuaddr *, PtrToUserArea);
    UT_GenStub_AddParam(CFE_PSP_GetUserReservedArea, uint32 *, SizeOfUserArea);

    UT_GenStub_Execute(CFE_PSP_GetUserReservedArea, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetUserReservedArea, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetVersionCodeName()
 * ----------------------------------------------------
 */
const char *CFE_PSP_GetVersionCodeName(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetVersionCodeName, const char *);

    UT_GenStub_Execute(CFE_PSP_GetVersionCodeName, Basic, UT_DefaultHandler_CFE_PSP_GetVersionCodeName);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetVersionCodeName, const char *);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetVersionNumber()
 * ----------------------------------------------------
 */
void CFE_PSP_GetVersionNumber(uint8 VersionNumbers[4])
{
    UT_GenStub_Execute(CFE_PSP_GetVersionNumber, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetVersionString()
 * ----------------------------------------------------
 */
const char *CFE_PSP_GetVersionString(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetVersionString, const char *);

    UT_GenStub_Execute(CFE_PSP_GetVersionString, Basic, UT_DefaultHandler_CFE_PSP_GetVersionString);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetVersionString, const char *);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_GetVolatileDiskMem()
 * ----------------------------------------------------
 */
int32 CFE_PSP_GetVolatileDiskMem(cpuaddr *PtrToVolDisk, uint32 *SizeOfVolDisk)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_GetVolatileDiskMem, int32);

    UT_GenStub_AddParam(CFE_PSP_GetVolatileDiskMem, cpuaddr *, PtrToVolDisk);
    UT_GenStub_AddParam(CFE_PSP_GetVolatileDiskMem, uint32 *, SizeOfVolDisk);

    UT_GenStub_Execute(CFE_PSP_GetVolatileDiskMem, Basic, UT_DefaultHandler_CFE_PSP_GetVolatileDiskMem);

    return UT_GenStub_GetReturnValue(CFE_PSP_GetVolatileDiskMem, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Get_Dec()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_Get_Dec(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_Get_Dec, uint32);

    UT_GenStub_Execute(CFE_PSP_Get_Dec, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_Get_Dec, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Get_Timebase()
 * ----------------------------------------------------
 */
void CFE_PSP_Get_Timebase(uint32 *Tbu, uint32 *Tbl)
{
    UT_GenStub_AddParam(CFE_PSP_Get_Timebase, uint32 *, Tbu);
    UT_GenStub_AddParam(CFE_PSP_Get_Timebase, uint32 *, Tbl);

    UT_GenStub_Execute(CFE_PSP_Get_Timebase, Basic, UT_DefaultHandler_CFE_PSP_Get_Timebase);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Get_Timer_Tick()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_Get_Timer_Tick(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_Get_Timer_Tick, uint32);

    UT_GenStub_Execute(CFE_PSP_Get_Timer_Tick, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_Get_Timer_Tick, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_InitSSR()
 * ----------------------------------------------------
 */
int32 CFE_PSP_InitSSR(uint32 bus, uint32 device, char *DeviceName)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_InitSSR, int32);

    UT_GenStub_AddParam(CFE_PSP_InitSSR, uint32, bus);
    UT_GenStub_AddParam(CFE_PSP_InitSSR, uint32, device);
    UT_GenStub_AddParam(CFE_PSP_InitSSR, char *, DeviceName);

    UT_GenStub_Execute(CFE_PSP_InitSSR, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_InitSSR, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Main()
 * ----------------------------------------------------
 */
void CFE_PSP_Main(void)
{
    UT_GenStub_Execute(CFE_PSP_Main, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemCpy()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemCpy(void *dest, const void *src, uint32 n)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemCpy, int32);

    UT_GenStub_AddParam(CFE_PSP_MemCpy, void *, dest);
    UT_GenStub_AddParam(CFE_PSP_MemCpy, const void *, src);
    UT_GenStub_AddParam(CFE_PSP_MemCpy, uint32, n);

    UT_GenStub_Execute(CFE_PSP_MemCpy, Basic, UT_DefaultHandler_CFE_PSP_MemCpy);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemCpy, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemRangeGet()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemRangeGet(uint32   RangeNum,
                          uint32  *MemoryType,
                          cpuaddr *StartAddr,
                          size_t  *Size,
                          size_t  *WordSize,
                          uint32  *Attributes)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemRangeGet, int32);

    UT_GenStub_AddParam(CFE_PSP_MemRangeGet, uint32, RangeNum);
    UT_GenStub_AddParam(CFE_PSP_MemRangeGet, uint32 *, MemoryType);
    UT_GenStub_AddParam(CFE_PSP_MemRangeGet, cpuaddr *, StartAddr);
    UT_GenStub_AddParam(CFE_PSP_MemRangeGet, size_t *, Size);
    UT_GenStub_AddParam(CFE_PSP_MemRangeGet, size_t *, WordSize);
    UT_GenStub_AddParam(CFE_PSP_MemRangeGet, uint32 *, Attributes);

    UT_GenStub_Execute(CFE_PSP_MemRangeGet, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemRangeGet, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemRangeSet()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemRangeSet(uint32  RangeNum,
                          uint32  MemoryType,
                          cpuaddr StartAddr,
                          size_t  Size,
                          size_t  WordSize,
                          uint32  Attributes)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemRangeSet, int32);

    UT_GenStub_AddParam(CFE_PSP_MemRangeSet, uint32, RangeNum);
    UT_GenStub_AddParam(CFE_PSP_MemRangeSet, uint32, MemoryType);
    UT_GenStub_AddParam(CFE_PSP_MemRangeSet, cpuaddr, StartAddr);
    UT_GenStub_AddParam(CFE_PSP_MemRangeSet, size_t, Size);
    UT_GenStub_AddParam(CFE_PSP_MemRangeSet, size_t, WordSize);
    UT_GenStub_AddParam(CFE_PSP_MemRangeSet, uint32, Attributes);

    UT_GenStub_Execute(CFE_PSP_MemRangeSet, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemRangeSet, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemRanges()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_MemRanges(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemRanges, uint32);

    UT_GenStub_Execute(CFE_PSP_MemRanges, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemRanges, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemRead16()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemRead16(cpuaddr MemoryAddress, uint16 *uint16Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemRead16, int32);

    UT_GenStub_AddParam(CFE_PSP_MemRead16, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_MemRead16, uint16 *, uint16Value);

    UT_GenStub_Execute(CFE_PSP_MemRead16, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemRead16, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemRead32()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemRead32(cpuaddr MemoryAddress, uint32 *uint32Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemRead32, int32);

    UT_GenStub_AddParam(CFE_PSP_MemRead32, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_MemRead32, uint32 *, uint32Value);

    UT_GenStub_Execute(CFE_PSP_MemRead32, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemRead32, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemRead8()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemRead8(cpuaddr MemoryAddress, uint8 *ByteValue)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemRead8, int32);

    UT_GenStub_AddParam(CFE_PSP_MemRead8, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_MemRead8, uint8 *, ByteValue);

    UT_GenStub_Execute(CFE_PSP_MemRead8, Basic, UT_DefaultHandler_CFE_PSP_MemRead8);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemRead8, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemSet()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemSet(void *dest, uint8 value, uint32 n)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemSet, int32);

    UT_GenStub_AddParam(CFE_PSP_MemSet, void *, dest);
    UT_GenStub_AddParam(CFE_PSP_MemSet, uint8, value);
    UT_GenStub_AddParam(CFE_PSP_MemSet, uint32, n);

    UT_GenStub_Execute(CFE_PSP_MemSet, Basic, UT_DefaultHandler_CFE_PSP_MemSet);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemSet, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemValidateRange()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemValidateRange(cpuaddr Address, size_t Size, uint32 MemoryType)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemValidateRange, int32);

    UT_GenStub_AddParam(CFE_PSP_MemValidateRange, cpuaddr, Address);
    UT_GenStub_AddParam(CFE_PSP_MemValidateRange, size_t, Size);
    UT_GenStub_AddParam(CFE_PSP_MemValidateRange, uint32, MemoryType);

    UT_GenStub_Execute(CFE_PSP_MemValidateRange, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemValidateRange, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemWrite16()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemWrite16(cpuaddr MemoryAddress, uint16 uint16Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemWrite16, int32);

    UT_GenStub_AddParam(CFE_PSP_MemWrite16, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_MemWrite16, uint16, uint16Value);

    UT_GenStub_Execute(CFE_PSP_MemWrite16, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemWrite16, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemWrite32()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemWrite32(cpuaddr MemoryAddress, uint32 uint32Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemWrite32, int32);

    UT_GenStub_AddParam(CFE_PSP_MemWrite32, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_MemWrite32, uint32, uint32Value);

    UT_GenStub_Execute(CFE_PSP_MemWrite32, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemWrite32, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_MemWrite8()
 * ----------------------------------------------------
 */
int32 CFE_PSP_MemWrite8(cpuaddr MemoryAddress, uint8 ByteValue)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_MemWrite8, int32);

    UT_GenStub_AddParam(CFE_PSP_MemWrite8, cpuaddr, MemoryAddress);
    UT_GenStub_AddParam(CFE_PSP_MemWrite8, uint8, ByteValue);

    UT_GenStub_Execute(CFE_PSP_MemWrite8, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_MemWrite8, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Panic()
 * ----------------------------------------------------
 */
void CFE_PSP_Panic(int32 ErrorCode)
{
    UT_GenStub_AddParam(CFE_PSP_Panic, int32, ErrorCode);

    UT_GenStub_Execute(CFE_PSP_Panic, Basic, UT_DefaultHandler_CFE_PSP_Panic);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_PortRead16()
 * ----------------------------------------------------
 */
int32 CFE_PSP_PortRead16(cpuaddr PortAddress, uint16 *uint16Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_PortRead16, int32);

    UT_GenStub_AddParam(CFE_PSP_PortRead16, cpuaddr, PortAddress);
    UT_GenStub_AddParam(CFE_PSP_PortRead16, uint16 *, uint16Value);

    UT_GenStub_Execute(CFE_PSP_PortRead16, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_PortRead16, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_PortRead32()
 * ----------------------------------------------------
 */
int32 CFE_PSP_PortRead32(cpuaddr PortAddress, uint32 *uint32Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_PortRead32, int32);

    UT_GenStub_AddParam(CFE_PSP_PortRead32, cpuaddr, PortAddress);
    UT_GenStub_AddParam(CFE_PSP_PortRead32, uint32 *, uint32Value);

    UT_GenStub_Execute(CFE_PSP_PortRead32, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_PortRead32, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_PortRead8()
 * ----------------------------------------------------
 */
int32 CFE_PSP_PortRead8(cpuaddr PortAddress, uint8 *ByteValue)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_PortRead8, int32);

    UT_GenStub_AddParam(CFE_PSP_PortRead8, cpuaddr, PortAddress);
    UT_GenStub_AddParam(CFE_PSP_PortRead8, uint8 *, ByteValue);

    UT_GenStub_Execute(CFE_PSP_PortRead8, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_PortRead8, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_PortWrite16()
 * ----------------------------------------------------
 */
int32 CFE_PSP_PortWrite16(cpuaddr PortAddress, uint16 uint16Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_PortWrite16, int32);

    UT_GenStub_AddParam(CFE_PSP_PortWrite16, cpuaddr, PortAddress);
    UT_GenStub_AddParam(CFE_PSP_PortWrite16, uint16, uint16Value);

    UT_GenStub_Execute(CFE_PSP_PortWrite16, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_PortWrite16, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_PortWrite32()
 * ----------------------------------------------------
 */
int32 CFE_PSP_PortWrite32(cpuaddr PortAddress, uint32 uint32Value)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_PortWrite32, int32);

    UT_GenStub_AddParam(CFE_PSP_PortWrite32, cpuaddr, PortAddress);
    UT_GenStub_AddParam(CFE_PSP_PortWrite32, uint32, uint32Value);

    UT_GenStub_Execute(CFE_PSP_PortWrite32, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_PortWrite32, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_PortWrite8()
 * ----------------------------------------------------
 */
int32 CFE_PSP_PortWrite8(cpuaddr PortAddress, uint8 ByteValue)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_PortWrite8, int32);

    UT_GenStub_AddParam(CFE_PSP_PortWrite8, cpuaddr, PortAddress);
    UT_GenStub_AddParam(CFE_PSP_PortWrite8, uint8, ByteValue);

    UT_GenStub_Execute(CFE_PSP_PortWrite8, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_PortWrite8, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_ReadFromCDS()
 * ----------------------------------------------------
 */
int32 CFE_PSP_ReadFromCDS(void *PtrToDataToRead, uint32 CDSOffset, uint32 NumBytes)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_ReadFromCDS, int32);

    UT_GenStub_AddParam(CFE_PSP_ReadFromCDS, void *, PtrToDataToRead);
    UT_GenStub_AddParam(CFE_PSP_ReadFromCDS, uint32, CDSOffset);
    UT_GenStub_AddParam(CFE_PSP_ReadFromCDS, uint32, NumBytes);

    UT_GenStub_Execute(CFE_PSP_ReadFromCDS, Basic, UT_DefaultHandler_CFE_PSP_ReadFromCDS);

    return UT_GenStub_GetReturnValue(CFE_PSP_ReadFromCDS, int32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_Restart()
 * ----------------------------------------------------
 */
void CFE_PSP_Restart(uint32 resetType)
{
    UT_GenStub_AddParam(CFE_PSP_Restart, uint32, resetType);

    UT_GenStub_Execute(CFE_PSP_Restart, Basic, UT_DefaultHandler_CFE_PSP_Restart);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_SetDefaultExceptionEnvironment()
 * ----------------------------------------------------
 */
void CFE_PSP_SetDefaultExceptionEnvironment(void)
{
    UT_GenStub_Execute(CFE_PSP_SetDefaultExceptionEnvironment, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_WatchdogDisable()
 * ----------------------------------------------------
 */
void CFE_PSP_WatchdogDisable(void)
{
    UT_GenStub_Execute(CFE_PSP_WatchdogDisable, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_WatchdogEnable()
 * ----------------------------------------------------
 */
void CFE_PSP_WatchdogEnable(void)
{
    UT_GenStub_Execute(CFE_PSP_WatchdogEnable, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_WatchdogGet()
 * ----------------------------------------------------
 */
uint32 CFE_PSP_WatchdogGet(void)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_WatchdogGet, uint32);

    UT_GenStub_Execute(CFE_PSP_WatchdogGet, Basic, NULL);

    return UT_GenStub_GetReturnValue(CFE_PSP_WatchdogGet, uint32);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_WatchdogInit()
 * ----------------------------------------------------
 */
void CFE_PSP_WatchdogInit(void)
{
    UT_GenStub_Execute(CFE_PSP_WatchdogInit, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_WatchdogService()
 * ----------------------------------------------------
 */
void CFE_PSP_WatchdogService(void)
{
    UT_GenStub_Execute(CFE_PSP_WatchdogService, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_WatchdogSet()
 * ----------------------------------------------------
 */
void CFE_PSP_WatchdogSet(uint32 WatchdogValue)
{
    UT_GenStub_AddParam(CFE_PSP_WatchdogSet, uint32, WatchdogValue);

    UT_GenStub_Execute(CFE_PSP_WatchdogSet, Basic, NULL);
}

/*
 * ----------------------------------------------------
 * Generated stub function for CFE_PSP_WriteToCDS()
 * ----------------------------------------------------
 */
int32 CFE_PSP_WriteToCDS(const void *PtrToDataToWrite, uint32 CDSOffset, uint32 NumBytes)
{
    UT_GenStub_SetupReturnBuffer(CFE_PSP_WriteToCDS, int32);

    UT_GenStub_AddParam(CFE_PSP_WriteToCDS, const void *, PtrToDataToWrite);
    UT_GenStub_AddParam(CFE_PSP_WriteToCDS, uint32, CDSOffset);
    UT_GenStub_AddParam(CFE_PSP_WriteToCDS, uint32, NumBytes);

    UT_GenStub_Execute(CFE_PSP_WriteToCDS, Basic, UT_DefaultHandler_CFE_PSP_WriteToCDS);

    return UT_GenStub_GetReturnValue(CFE_PSP_WriteToCDS, int32);
}
