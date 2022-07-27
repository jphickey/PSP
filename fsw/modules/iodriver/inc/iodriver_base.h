/*
 *  Copyright (c) 2015, United States government as represented by the
 *  administrator of the National Aeronautics Space Administration.
 *  All rights reserved. This software was created at NASA Glenn
 *  Research Center pursuant to government contracts.
 */

/**
 * \file cfe_psp_iodriver.h
 *
 *  Created on: Sep 29, 2015
 *  Created by: joseph.p.hickey@nasa.gov
 *
 */


#ifndef _IODRIVER_BASE_H_
#define _IODRIVER_BASE_H_

#include <common_types.h>

/**
 * Physical channel location descriptor.
 *
 * For board_instance and board_channel parameters, zero is a reserved value that will be interpreted
 * as "undefined" by the driver code.  For reading/writing configuration values, zero may be used
 * to indicate a "global" device or system-wide configuration that does not apply to a single channel.
 *
 * See the CFE_PSP_IODriver_MapChannel() call to determine channel number to set in here,
 * as each board may have their own unique channel naming conventions.  The integer value that
 * goes in this structure may or may not correlate to the physical device labeling.
 */
typedef struct
{
    uint32 PspModuleId;                 ///< Board driver selection
    uint16 BoardInstance;               ///< Board instance number
    uint16 ChannelNumber;               ///< Subchannel number - optional, set to 0 for devices that do not have multiple channels
} CFE_PSP_IODriver_Location_t;

/**
 * Wrapper for constant arguments, to avoid a compiler warning
 * about arguments differing in const-ness.  Use the inline functions to
 * pass in an immediate/constant value.
 */
typedef union
{
    void *Vptr;
    const void *ConstVptr;
    const char *ConstStr;
    uint32 U32;
} CFE_PSP_IODriver_Arg_t;

static inline CFE_PSP_IODriver_Arg_t CFE_PSP_IODRIVER_VPARG(void *x)                { CFE_PSP_IODriver_Arg_t a; a.Vptr = x; return a; }
static inline CFE_PSP_IODriver_Arg_t CFE_PSP_IODRIVER_CONST_VPARG(const void *x)    { CFE_PSP_IODriver_Arg_t a; a.ConstVptr = x; return a; }
static inline CFE_PSP_IODriver_Arg_t CFE_PSP_IODRIVER_CONST_STR(const char *x)      { CFE_PSP_IODriver_Arg_t a; a.ConstStr = x; return a; }
static inline CFE_PSP_IODriver_Arg_t CFE_PSP_IODRIVER_U32ARG(uint32 x)              { CFE_PSP_IODriver_Arg_t a; a.U32 = x; return a; }

/**
 * Standardized concept of directionality for any device
 *
 * Some code may use these enumeration values as a bitmask -
 * use care when updating to ensure that the values may be used as bitmasks.
 * Specific hardware drivers may or may not implement all modes depending on capabilities.
 */
typedef enum
{
    CFE_PSP_IODRIVER_DIRECTION_DISABLED = 0,                ///< Disabled (inactive, tri-state if possible)
    CFE_PSP_IODRIVER_DIRECTION_INPUT_ONLY = 0x01,           ///< Device/channel is configured for input
    CFE_PSP_IODRIVER_DIRECTION_OUTPUT_ONLY = 0x02,          ///< Device/channel is configured for output
    CFE_PSP_IODRIVER_DIRECTION_INPUT_OUTPUT = 0x03          ///< Input/Output (some HW supports this)
} CFE_PSP_IODriver_Direction_t;



/**
 * Some common values for the device command codes
 * These are some VERY basic ops that many devices may support in some way.
 * Any opcode that is not implemented should return CFE_PSP_ERROR_NOT_IMPLEMENTED
 *
 * Negative return values indicate an error of some type, while return values >= 0 indicate success
 */
enum
{
    CFE_PSP_IODRIVER_NOOP = 0,          /**< Reserved, do nothing */

    /* Start/stop opcodes */
    CFE_PSP_IODRIVER_SET_RUNNING,       /**< uint32 argument, 0=stop 1=start device */
    CFE_PSP_IODRIVER_GET_RUNNING,       /**< no argument, returns positive nonzero (true) if running and zero (false) if stopped, negative on error */

    /* Configuration opcodes */
    CFE_PSP_IODRIVER_SET_CONFIGURATION, /**< const string argument (device-dependent content) */
    CFE_PSP_IODRIVER_GET_CONFIGURATION, /**< void * argument (device-dependent content) */

    /* Sub-channel configuration/mapping opcodes */
    CFE_PSP_IODRIVER_LOOKUP_SUBCHANNEL, /**< const char * argument, looks up ChannelName and returns positive value for channel number, negative value for error */
    CFE_PSP_IODRIVER_SET_DIRECTION,     /**< U32 (CFE_PSP_IODriver_Direction_t) argument as input */
    CFE_PSP_IODRIVER_QUERY_DIRECTION,   /**< U32 (CFE_PSP_IODriver_Direction_t) argument as output */

    /*
     * Placeholders for opcodes that could be implemented across a class of devices.
     * For instance, all ADC/DAC devices should implement a common set of read/write opcodes
     * so that devices can be interchanged without affecting higher-level software
     */
    CFE_PSP_IODRIVER_ANALOG_IO_CLASS_BASE   = 0x00010000,    /**< Opcodes implemented by typical adc/dac devices */
    CFE_PSP_IODRIVER_DIGITAL_IO_CLASS_BASE  = 0x00020000,    /**< Opcodes implemented by gpio (digital logic) devices */
    CFE_PSP_IODRIVER_PACKET_IO_CLASS_BASE   = 0x00030000,    /**< Opcodes implemented by packet/datagram-oriented devices */
    CFE_PSP_IODRIVER_MEMORY_IO_CLASS_BASE   = 0x00040000,    /**< Opcodes implemented by memory/register oriented devices */
    CFE_PSP_IODRIVER_STREAM_IO_CLASS_BASE   = 0x00050000,    /**< Opcodes implemented by data stream oriented devices */

    /**
     * Placeholder for extended opcodes that may be very specific to a single device/device type.
     * This allows the same API call (CFE_PSP_DeviceCommandFunc_t) but
     */
    CFE_PSP_IODRIVER_EXTENDED_BASE         = 0x7FFF0000

};


int32 CFE_PSP_IODriver_FindByName(const char *DriverName, uint32 *PspModuleId);
int32 CFE_PSP_IODriver_Command(const CFE_PSP_IODriver_Location_t *Location, uint32 CommandCode, CFE_PSP_IODriver_Arg_t Arg);


#endif /* _IODRIVER_BASE_H_ */
