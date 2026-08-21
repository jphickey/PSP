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

/*
** Functions
*/

/*****************************************************************************/
/**
** \brief CFE_PSP_Panic stub function
**
** \par Description
**        This function is used to mimic the response of the OS API function
**        CFE_PSP_Panic.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        This function does not return a value.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_Panic(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    int32 ErrorCode = UT_Hook_GetArgValueByName(Context, "ErrorCode", int32);

    UT_Stub_CopyFromLocal(UT_KEY(CFE_PSP_Panic), (uint8 *)&ErrorCode, sizeof(ErrorCode));
}

/*****************************************************************************/
/**
** \brief CFE_PSP_GetProcessorName stub function
**
** \par Description
**        This function is used as a placeholder for the PSP function
**        CFE_PSP_GetProcessorName.  It is set to return a fixed value for the
**        unit tests.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns Default_CpuName or passed in address from buffer
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_GetProcessorName(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    int32       status;
    const char *ptr;

    UT_Stub_GetInt32StatusCode(Context, &status);

    ptr = NULL;
    if (status >= 0 && UT_Stub_CopyToLocal(UT_KEY(CFE_PSP_GetProcessorName), &ptr, sizeof(ptr)) < sizeof(ptr))
    {
        ptr = GLOBAL_CONFIGDATA.Default_CpuName;
    }

    UT_Stub_SetReturnValue(FuncKey, ptr);
}

/*****************************************************************************/
/**
** \brief CFE_PSP_GetTime stub function
**
** \par Description
**        This function is used as a placeholder for the PSP function
**        CFE_PSP_GetTime.  The LocalTime structure is set to the user-defined
**        values in BSP_Time.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        This function does not return a value.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_GetTime(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    OS_time_t *LocalTime = UT_Hook_GetArgValueByName(Context, "LocalTime", OS_time_t *);
    int32      status;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0 && LocalTime != NULL)
    {
        if (UT_Stub_CopyToLocal(UT_KEY(CFE_PSP_GetTime), (uint8 *)LocalTime, sizeof(*LocalTime)) < sizeof(*LocalTime))
        {
            *LocalTime = OS_TimeAssembleFromNanoseconds(100, 200000);
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_WriteToCDS stub function
**
** \par Description
**        This function is used to mimic the response of the PSP function
**        CFE_PSP_WriteToCDS.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns either OS_SUCCESS, OS_ERROR, or a user-defined value.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_WriteToCDS(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    const void *PtrToDataToWrite = UT_Hook_GetArgValueByName(Context, "PtrToDataToWrite", const void *);
    uint32      CDSOffset        = UT_Hook_GetArgValueByName(Context, "CDSOffset", uint32);
    uint32      NumBytes         = UT_Hook_GetArgValueByName(Context, "NumBytes", uint32);

    uint8 *BufPtr;
    size_t CdsSize;
    size_t Position;
    int32  status;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0 && PtrToDataToWrite != NULL)
    {
        UT_GetDataBuffer(UT_KEY(CFE_PSP_WriteToCDS), (void **)&BufPtr, &CdsSize, &Position);
        if (BufPtr != NULL && (CDSOffset + NumBytes) <= CdsSize)
        {
            memcpy(BufPtr + CDSOffset, PtrToDataToWrite, NumBytes);
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_ReadFromCDS stub function
**
** \par Description
**        This function is used to mimic the response of the PSP function
**        CFE_PSP_ReadFromCDS.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns either OS_SUCCESS, OS_ERROR, or a user-defined value.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_ReadFromCDS(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    uint8 *BufPtr;
    size_t CdsSize;
    size_t Position;
    int32  status;

    void  *PtrToDataToRead = UT_Hook_GetArgValueByName(Context, "PtrToDataToRead", void *);
    uint32 CDSOffset       = UT_Hook_GetArgValueByName(Context, "CDSOffset", uint32);
    uint32 NumBytes        = UT_Hook_GetArgValueByName(Context, "NumBytes", uint32);

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0 && PtrToDataToRead != NULL)
    {
        UT_GetDataBuffer(UT_KEY(CFE_PSP_ReadFromCDS), (void **)&BufPtr, &CdsSize, &Position);
        if (BufPtr != NULL && (CDSOffset + NumBytes) <= CdsSize)
        {
            memcpy(PtrToDataToRead, BufPtr + CDSOffset, NumBytes);
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_GetCDSSize stub function
**
** \par Description
**        This function is used to mimic the response of the PSP function
**        CFE_PSP_GetCDSSize.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns either OS_SUCCESS or OS_ERROR.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_GetCDSSize(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    uint32 *SizeOfCDS = UT_Hook_GetArgValueByName(Context, "SizeOfCDS", uint32 *);
    int32   status;
    size_t  TempSize;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0 && SizeOfCDS != NULL)
    {
        UT_GetDataBuffer(UT_KEY(CFE_PSP_GetCDSSize), NULL, &TempSize, NULL);
        *SizeOfCDS = TempSize;
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_GetVolatileDiskMem stub function
**
** \par Description
**        This function is used to mimic the response of the PSP function
**        CFE_PSP_GetVolatileDiskMem.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns either OS_SUCCESS or OS_ERROR.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_GetVolatileDiskMem(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    cpuaddr *PtrToVolDisk  = UT_Hook_GetArgValueByName(Context, "PtrToVolDisk", cpuaddr *);
    uint32  *SizeOfVolDisk = UT_Hook_GetArgValueByName(Context, "SizeOfVolDisk", uint32 *);

    int32  status;
    size_t TempSize;
    void  *TempAddr;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0)
    {
        UT_GetDataBuffer(UT_KEY(CFE_PSP_GetVolatileDiskMem), &TempAddr, &TempSize, NULL);

        if (PtrToVolDisk != NULL)
        {
            *PtrToVolDisk = (cpuaddr)TempAddr;
        }
        if (SizeOfVolDisk != NULL)
        {
            *SizeOfVolDisk = TempSize;
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_Restart stub function
**
** \par Description
**        This function is used as a placeholder for the PSP function
**        CFE_PSP_Restart.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        This function does not return a value.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_Restart(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    uint32 resetType = UT_Hook_GetArgValueByName(Context, "resetType", uint32);

    UT_Stub_CopyFromLocal(UT_KEY(CFE_PSP_Restart), (uint8 *)&resetType, sizeof(resetType));
}

/*****************************************************************************/
/**
** \brief CFE_PSP_Get_Timebase stub function
**
** \par Description
**        This function is used as a placeholder for the PSP function
**        CFE_PSP_Get_Timebase.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        This function does not return a value.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_Get_Timebase(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    uint32 *Tbu = UT_Hook_GetArgValueByName(Context, "Tbu", uint32 *);
    uint32 *Tbl = UT_Hook_GetArgValueByName(Context, "Tbl", uint32 *);

    if (!UT_Stub_GetInt32StatusCode(Context, NULL))
    {
        if (Tbu)
        {
            *Tbu = 0;
        }
        if (Tbl)
        {
            *Tbl = 0;
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_GetResetArea stub function
**
** \par Description
**        This function is used as a placeholder for the PSP function
**        CFE_PSP_GetResetArea.  It returns the user-defined value,
**        UT_StatusBSP.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns a user-defined status value, UT_StatusBSP.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_GetResetArea(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    cpuaddr *PtrToResetArea  = UT_Hook_GetArgValueByName(Context, "PtrToResetArea", cpuaddr *);
    uint32  *SizeOfResetArea = UT_Hook_GetArgValueByName(Context, "SizeOfResetArea", uint32 *);

    int32  status;
    size_t TempSize;
    void  *TempAddr;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0)
    {
        UT_GetDataBuffer(UT_KEY(CFE_PSP_GetResetArea), &TempAddr, &TempSize, NULL);

        if (PtrToResetArea)
        {
            *PtrToResetArea = (cpuaddr)TempAddr;
        }
        if (SizeOfResetArea)
        {
            *SizeOfResetArea = TempSize;
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_GetCFETextSegmentInfo stub function
**
** \par Description
**        This function is used to mimic the response of the PSP function
**        CFE_PSP_GetCFETextSegmentInfo.  The user can adjust the response by
**        setting the values in the BSPGetCFETextRtn structure prior to this
**        function being called.  If the value BSPGetCFETextRtn.count is
**        greater than zero then the counter is decremented; if it then equals
**        zero the return value is set to the user-defined value
**        BSPGetCFETextRtn.value.  OS_SUCCESS is returned otherwise.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns either a user-defined status flag or OS_SUCCESS.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_GetCFETextSizeOfCFESegment(void                   *UserObj,
                                                          UT_EntryKey_t           FuncKey,
                                                          const UT_StubContext_t *Context)
{
    cpuaddr *PtrToCFESegment  = UT_Hook_GetArgValueByName(Context, "PtrToCFESegment", cpuaddr *);
    uint32  *SizeOfCFESegment = UT_Hook_GetArgValueByName(Context, "SizeOfCFESegment", uint32 *);

    static uint32 LocalTextSegment;
    int32         status;
    void         *TempAddr;
    size_t        TempSize;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0)
    {
        UT_GetDataBuffer(UT_KEY(CFE_PSP_GetCFETextSegmentInfo), &TempAddr, &TempSize, NULL);
        if (TempAddr == NULL)
        {
            /* Backup -- Set the pointer and size to anything */
            TempAddr = &LocalTextSegment;
            TempSize = sizeof(LocalTextSegment);
        }

        if (PtrToCFESegment)
        {
            *PtrToCFESegment = (cpuaddr)TempAddr;
        }
        if (SizeOfCFESegment)
        {
            *SizeOfCFESegment = TempSize;
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_GetKernelTextSegmentInfo stub function
**
** \par Description
**        This function is used to mimic the response of the PSP function
**        CFE_PSP_GetKernelTextSegmentInfo.  The user can adjust the response by
**        setting the values in the BSPGetCFETextRtn structure prior to this
**        function being called.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns either a user-defined status flag or OS_SUCCESS.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_GetKernelTextSizeOfKernelSegment(void                   *UserObj,
                                                                UT_EntryKey_t           FuncKey,
                                                                const UT_StubContext_t *Context)
{
    cpuaddr *PtrToKernelSegment  = UT_Hook_GetArgValueByName(Context, "PtrToKernelSegment", cpuaddr *);
    uint32  *SizeOfKernelSegment = UT_Hook_GetArgValueByName(Context, "SizeOfKernelSegment", uint32 *);

    static uint32 LocalTextSegment;
    int32         status;
    void         *TempAddr;
    size_t        TempSize;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0)
    {
        UT_GetDataBuffer(UT_KEY(CFE_PSP_GetKernelTextSegmentInfo), &TempAddr, &TempSize, NULL);
        if (TempAddr == NULL)
        {
            /* Backup -- Set the pointer and size to anything */
            TempAddr = &LocalTextSegment;
            TempSize = sizeof(LocalTextSegment);
        }

        if (PtrToKernelSegment)
        {
            *PtrToKernelSegment = (cpuaddr)TempAddr;
        }
        if (SizeOfKernelSegment)
        {
            *SizeOfKernelSegment = TempSize;
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_MemRead8 stub function
**
** \par Description
**        This function is used as a placeholder for the PSP function
**        CFE_PSP_MemRead8.  It sets the Data variable to a fixed value and
**        always returns OS_SUCCESS.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns OS_SUCCESS.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_MemRead8(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    int32  status;
    uint8 *ByteValue = UT_Hook_GetArgValueByName(Context, "ByteValue", uint8 *);

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0 && ByteValue != NULL)
    {
        if (UT_Stub_CopyToLocal(FuncKey, ByteValue, 1) < 1)
        {
            *ByteValue = 0x01;
        }
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_MemCpy stub function
**
** \par Description
**        This function is used to mimic the response of the OS API function
**        CFE_PSP_MemCpy.  It always returns OS_SUCCESS.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns OS_SUCCESS.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_MemCpy(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    void       *dest = UT_Hook_GetArgValueByName(Context, "dest", void *);
    const void *src  = UT_Hook_GetArgValueByName(Context, "src", const void *);
    uint32      n    = UT_Hook_GetArgValueByName(Context, "n", uint32);
    int32       status;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0)
    {
        /* this is not actually a stub; it actually has to _do_ the intended function */
        memcpy(dest, src, n);
    }
}

/*****************************************************************************/
/**
** \brief CFE_PSP_MemSet stub function
**
** \par Description
**        This function is used to mimic the response of the OS API function
**        CFE_PSP_MemSet.  It always returns OS_SUCCESS.
**
** \par Assumptions, External Events, and Notes:
**        None
**
** \returns
**        Returns OS_SUCCESS.
**
******************************************************************************/
void UT_DefaultHandler_CFE_PSP_MemSet(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    void  *dest  = UT_Hook_GetArgValueByName(Context, "dest", void *);
    uint8  value = UT_Hook_GetArgValueByName(Context, "value", uint8);
    uint32 n     = UT_Hook_GetArgValueByName(Context, "n", uint32);
    int32  status;

    UT_Stub_GetInt32StatusCode(Context, &status);

    if (status >= 0)
    {
        /* this is not actually a stub; it actually has to _do_ the intended function */
        memset(dest, (int)value, (size_t)n);
    }
}

void UT_DefaultHandler_CFE_PSP_Exception_GetSummary(void                   *UserObj,
                                                    UT_EntryKey_t           FuncKey,
                                                    const UT_StubContext_t *Context)
{
    uint32    *ContextLogId = UT_Hook_GetArgValueByName(Context, "ContextLogId", uint32 *);
    osal_id_t *TaskId       = UT_Hook_GetArgValueByName(Context, "TaskId", osal_id_t *);
    char      *ReasonBuf    = UT_Hook_GetArgValueByName(Context, "ReasonBuf", char *);

    int32 status;

    *ContextLogId = 0;
    *ReasonBuf    = 0;

    /* allow the testcase to easily set the taskID output, anything more involved needs a hook */
    if (!UT_Stub_GetInt32StatusCode(Context, &status) && TaskId != NULL)
    {
        if (status >= 0 &&
            UT_Stub_CopyToLocal(UT_KEY(CFE_PSP_Exception_GetSummary), TaskId, sizeof(*TaskId)) < sizeof(*TaskId))
        {
            *TaskId = OS_OBJECT_ID_UNDEFINED;
        }
    }
}

void UT_DefaultHandler_CFE_PSP_Exception_CopyContext(void                   *UserObj,
                                                     UT_EntryKey_t           FuncKey,
                                                     const UT_StubContext_t *Context)
{
    void  *ContextBuf   = UT_Hook_GetArgValueByName(Context, "ContextBuf", void *);
    uint32 ContextSize  = UT_Hook_GetArgValueByName(Context, "ContextSize", uint32);

    int32 status;

    if (!UT_Stub_GetInt32StatusCode(Context, &status) && status >= 0)
    {
        status = UT_Stub_CopyToLocal(UT_KEY(CFE_PSP_Exception_CopyContext), ContextBuf, ContextSize);
        UT_Stub_SetReturnValue(FuncKey, status);
    }
}

/*----------------------------------------------------------------
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
void UT_DefaultHandler_CFE_PSP_GetVersionString(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    static const char DEFAULT[] = "UT";
    void             *Buffer;
    const char       *RetVal;

    UT_GetDataBuffer(UT_KEY(CFE_PSP_GetVersionString), &Buffer, NULL, NULL);
    if (Buffer == NULL)
    {
        RetVal = DEFAULT;
    }
    else
    {
        RetVal = Buffer;
    }

    UT_Stub_SetReturnValue(FuncKey, RetVal);
}

/*----------------------------------------------------------------
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
void UT_DefaultHandler_CFE_PSP_GetVersionCodeName(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    static const char DEFAULT[] = "UT";
    void             *Buffer;
    const char       *RetVal;

    UT_GetDataBuffer(UT_KEY(CFE_PSP_GetVersionCodeName), &Buffer, NULL, NULL);
    if (Buffer == NULL)
    {
        RetVal = DEFAULT;
    }
    else
    {
        RetVal = Buffer;
    }

    UT_Stub_SetReturnValue(FuncKey, RetVal);
}
