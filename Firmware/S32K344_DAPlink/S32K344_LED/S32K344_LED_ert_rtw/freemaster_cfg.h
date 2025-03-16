/*
 * Copyright 2019-2020, 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * FreeMASTER Communication Driver - User Configuration File
 */

#ifndef __FREEMASTER_CFG_H
#define __FREEMASTER_CFG_H
#include "S32K344_LPUART.h"

// Make sure the FMSTR_TRANSPORT and related low-level communication driver is selected below.
// Also make sure the low-level module and device pins are properly initialized in the main()
// function and that FMSTR_Init() and FMSTR_Poll() functions are called from the main application loop.
// See freemaster_examples/fmstr_uart example application for more information.

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
#define FMSTR_LPUART_BASE              IP_LPUART_6_BASE
#define FMSTR_PLATFORM_CORTEX_M        1                         /* Cortex-M platform (see freemaster.h for list of all supported platforms) */

// Set the demo application configuration
#define FMSTR_DEMO_ENOUGH_ROM          1                         /* Platform has enough ROM to show most of the FreeMASTER features */
#define FMSTR_DEMO_LARGE_ROM           1                         /* Platform has large ROM enough to store the extended data structures used in FreeMASTER demo */
#define FMSTR_DEMO_SUPPORT_I64         1                         /* support for long long type */
#define FMSTR_DEMO_SUPPORT_FLT         1                         /* support for float type */
#define FMSTR_DEMO_SUPPORT_DBL         1                         /* support for double type */

// Enable/Disable FreeMASTER support as a whole
#define FMSTR_DISABLE                  0                         // To disable all FreeMASTER functionalities

// Select interrupt or poll-driven serial communication
#define FMSTR_LONG_INTR                0                         // Complete message processing in interrupt
#define FMSTR_SHORT_INTR               1                         // Queuing done in interrupt
#define FMSTR_POLL_DRIVEN              0                         // No interrupt needed, polling only

// List of standard FreeMASTER transports and their low-level drivers. See more options in src/drivers.
// FMSTR_SERIAL   -   Standard serial transport protocol (Used by various types of UART peripherals as USB CDC implementation)
// FMSTR_PDBDM    -   Packet Driven BDM (direct memory access via JTAG, SWD or BDM debug probes). No low-level driver used.

// Select communication interface
#define FMSTR_TRANSPORT                FMSTR_SERIAL
#define FMSTR_SERIAL_DRV               FMSTR_SERIAL_S32K3XX_LPUART

// Define communication interface base address or leave undefined for runtime setting
//#define FMSTR_SERIAL_BASE LPUART_6_BASE  // Serial base will be assigned in runtime (when FMSTR_USE_UART)
//#define FMSTR_CAN_BASE LPUART_6_BASE     // CAN base will be assigned in runtime (when FMSTR_USE_FLEXCAN)

// FlexCAN-specific, communication message buffers
// #define FMSTR_FLEXCAN_TXMB      0
// #define FMSTR_FLEXCAN_RXMB      1

// Input/output communication buffer size
#define FMSTR_COMM_BUFFER_SIZE         0                         // Set to 0 for "automatic"

// Receive FIFO queue size (use with FMSTR_SHORT_INTR only)
#define FMSTR_COMM_RQUEUE_SIZE         0                         // Set to 0 for "default"

// Support for Application Commands
#define FMSTR_USE_APPCMD               0                         // Enable/disable App.Commands support
#define FMSTR_APPCMD_BUFF_SIZE         0                         // App.Command data buffer size
#define FMSTR_MAX_APPCMD_CALLS         1                         // How many app.cmd callbacks? (0=disable)

// Oscilloscope support
#define FMSTR_USE_SCOPE                1                         // Specify number of supported oscilloscopes
#define FMSTR_MAX_SCOPE_VARS           8                         // Specify maximum number of scope variables per one oscilloscope

// Recorder support
#define FMSTR_USE_RECORDER             0                         // Specify number of supported recorders
#define FMSTR_REC_FLOAT_TRIG           1                         // Enable/disable floating point triggering

// Target-side address translation (TSA)
#define FMSTR_USE_TSA                  0                         // Enable TSA functionality
#define FMSTR_USE_TSA_INROM            0                         // TSA tables declared as const (put to ROM)
#define FMSTR_USE_TSA_SAFETY           0                         // Enable/Disable TSA memory protection
#define FMSTR_USE_TSA_DYNAMIC          0                         // Enable/Disable TSA entries to be added also in runtime

// Pipes as data streaming over FreeMASTER protocol
#define FMSTR_USE_PIPES                1                         // Specify number of supported pipe objects

// Enable/Disable read/write memory commands
#define FMSTR_USE_READMEM              1                         // Enable read memory commands
#define FMSTR_USE_WRITEMEM             1                         // Enable write memory commands
#define FMSTR_USE_WRITEMEMMASK         1                         // Enable write memory bits commands

// Define password for access levels to protect them. AVOID SHORT PASSWORDS in production version.
// Passwords should be at least 20 characters long to prevent dictionary attacks.
// #define FMSTR_RESTRICTED_ACCESS_R_PASSWORD    "r"   // Read-only access level password. Let undefined when no password is required.
// #define FMSTR_RESTRICTED_ACCESS_RW_PASSWORD   "rw"  // Write access level password. Let undefined to set the same as for read-only access level.
// #define FMSTR_RESTRICTED_ACCESS_RWF_PASSWORD  "rwf" // Flash access level password. Let undefined to set the same as for write access level.

// Storing cleartext passwords in Flash memory is not safe, consider storing their SHA1 hash instead
// Even with this option, the hash must be generated from reasonably complex password to prevent dictionary attack.
#define FMSTR_USE_HASHED_PASSWORDS     0                         // When non-zero, the passwords above are specified as a pointer to 20-byte SHA1 hash of password text
#endif                                 /* __FREEMASTER_CFG_H */

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
