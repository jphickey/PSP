/*
 *  Copyright (c) 2015, United States government as represented by the
 *  administrator of the National Aeronautics Space Administration.
 *  All rights reserved. This software was created at NASA Glenn
 *  Research Center pursuant to government contracts.
 */

/**
 * \file iodriver_digital_gpio.h
 *
 *  Created on: Sep 30, 2015
 *  Created by: joseph.p.hickey@nasa.gov
 *
 */


#ifndef CFE_PSP_IODRIVER_DIGITAL_GPIO_H_
#define CFE_PSP_IODRIVER_DIGITAL_GPIO_H_

/**
 * Type abstraction for expressing digital logic levels.
 *
 * This value will be filled starting with the LSB. A typical GPIO logic channel is 1 bit, so
 * only the LSB is signficiant and the other bits are not used.
 *
 * This allows single channels up to 8 bits wide, but multiple "channels" could be concatenated
 * using a multi-read/write opcode to allow atomic access to any number of bits.
 */
typedef uint8 CFE_PSP_IODriver_GpioLevel_t;

/**
 * Enumerated names for typical digital 1-bit logic channel states.
 *
 * For convenience / code readability.
 */
enum
{
    CFE_PSP_IODRIVER_GPIO_LOGIC_LOW =  0,
    CFE_PSP_IODRIVER_GPIO_LOGIC_HIGH = 1
};

#ifdef JPHFIX
/**
 * Overall Configuration structure for channel configuration commands.
 *
 * This describes both ADC/DAC (analog) and GPIO (digital logic)
 * channels.  It is returned from the "Get Status" command.
 */
typedef struct
{
    CFE_PSP_IODriver_ChannelType_t ChannelType;      ///< Define the type of channel
    CFE_PSP_IODriver_Direction_t Direction;          ///< Define whether GPIO is input or output
} CFE_PSP_IODriver_ChannelStatus_t;

/**
 * Sample container for multi-channel read/write commands.
 *
 * This is just a pointer to an array, but the array could be ADC codes
 * or digital logic levels.  This allows the same API to be used for both.
 */
typedef union
{
    void *VoidPtr;
    CFE_PSP_IODriver_GpioLevel_t *GpioLev;
} CFE_PSP_IODriver_Sample_t;

#endif

/**
 * Complete API container for gpio read/write commands.
 * This allows reading/writing multiple channels at once with a single entry into the API.
 * As each entry into the API needs to acquire a mutex for serialization, this can be much
 * more efficient to read channels through this means rather than single channel read/write.
 */
typedef struct
{
    uint16 NumChannels;                    ///< Number of channels in the i/o structure (length of "samples" array)
    CFE_PSP_IODriver_GpioLevel_t *Samples;         ///< Array for digital logic levels
} CFE_PSP_IODriver_GpioRdWr_t;

/**
 * Opcodes specific to digital GPIO devices
 */
enum
{
    CFE_PSP_IODRIVER_DIGITAL_IO_NOOP = CFE_PSP_IODRIVER_DIGITAL_IO_CLASS_BASE,

    CFE_PSP_IODRIVER_DIGITAL_IO_READ_CHANNELS,   /**< CFE_PSP_IODriver_GpioRdWr_t argument */
    CFE_PSP_IODRIVER_DIGITAL_IO_WRITE_CHANNELS,  /**< CFE_PSP_IODriver_GpioRdWr_t argument */

    CFE_PSP_IODRIVER_DIGITAL_IO_MAX
};



#endif /* CFE_PSP_IODRIVER_DIGITAL_GPIO_H_ */
