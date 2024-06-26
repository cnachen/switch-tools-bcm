/*****************************************************************************
 Copyright 2017-2023 Broadcom Limited.  All rights reserved.

 This program is the proprietary software of Broadcom Limited and/or its
 licensors, and may only be used, duplicated, modified or distributed pursuant
 to the terms and conditions of a separate, written license agreement executed
 between you and Broadcom (an "Authorized License").

 Except as set forth in an Authorized License, Broadcom grants no license
 (express or implied), right to use, or waiver of any kind with respect to the
 Software, and Broadcom expressly reserves all rights in and to the Software
 and all intellectual property rights therein.  IF YOU HAVE NO AUTHORIZED
 LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD
 IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.

  Except as expressly set forth in the Authorized License,
 1. This program, including its structure, sequence and organization,
    constitutes the valuable trade secrets of Broadcom, and you shall use all
    reasonable efforts to protect the confidentiality thereof, and to use this
    information only in connection with your use of Broadcom integrated
    circuit products.

 2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
    TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND ALL IMPLIED
    WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A
    PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS,
    QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION.
    YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR PERFORMANCE OF THE
    SOFTWARE.

 3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR ITS
    LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL, INDIRECT,
    OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY WAY RELATING TO
    YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS
    OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1, WHICHEVER
    IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING ANY FAILURE OF
    ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
******************************************************************************/

/**
    @defgroup grp_abstract_err Error Reporting
    @ingroup grp_abstract

    @addtogroup grp_abstract_err
    @{
    All Components use these errors as error return types.
    <BR>All Components use BCM_ReportError function for reporting errors.

    @file bcm_err.h
    @brief BCM Error Types
    This header file contains the interface functions for error types
    and error reporting function.
    @version 1.0 Initial Version
*/


#ifndef BCM_ERR_H
#define BCM_ERR_H

#include <stdint.h>
#include <stddef.h>
#include <bcm_comp.h>
/**
    @name BCM Error API IDs
    @{
    @brief API IDs for BCM Error APIs
*/
#define BRCM_SWARCH_BCM_ERR_TYPE                (0x8001U)    /**< @brief #BCM_ErrorType                 */
#define BRCM_SWARCH_BCM_MACRO                   (0x8002U)    /**< @brief #BCM_LOGMASK_KERNEL            */
#define BRCM_SWARCH_BCM_ERR_VERSION_TYPE        (0x8003U)    /**< @brief #BCM_ErrVersionType            */
#define BRCM_SWARCH_BCM_ERR_REPORT_PROC         (0x8004U)    /**< @brief #BCM_ReportError               */
#define BRCM_SWARCH_BCM_ERR_REPORTV2_PROC       (0x8005U)    /**< @brief #BCM_ReportErrorV2             */
#define BRCM_SWARCH_BCM_ERROR_TYPE              (0x8006U)    /**< @brief #BCM_DbgMsgType                */
#define BRCM_SWARCH_BCM_ERR_CUSTOM_MACRO        (0x8007U)    /**< @brief #BCM_ERR_MAX_CUSTOM_VALUES     */
#define BRCM_SWARCH_BCM_INIT_ERROR_PROC         (0x8008U)    /**< @brief #BCM_InitError                 */
#define BRCM_SWARCH_BCM_DEV_INFO_TYPE           (0x8009U)    /**< @brief #BCM_DevInfoType               */
#define BRCM_SWARCH_BCM_BOOT_MODE_IDX_TYPE      (0x800AU)    /**< @brief #BCM_BootModeIdxType           */
#define BRCM_SWARCH_BCM_DBGMSG_PUTRAW_PROC      (0x800BU)    /**< @brief #BCM_DbgMsgPutRaw              */
#define BRCM_SWARCH_BCM_LOG_MSG0_MACRO          (0x800CU)    /**< @brief #BCM_LOG_MSG0                  */
#define BRCM_SWARCH_BCM_LOG_MSG1_MACRO          (0x800DU)    /**< @brief #BCM_LOG_MSG1                  */
#define BRCM_SWARCH_BCM_LOG_MSG2_MACRO          (0x800EU)    /**< @brief #BCM_LOG_MSG2                  */
#define BRCM_SWARCH_BCM_LOG_MSG3_MACRO          (0x800FU)    /**< @brief #BCM_LOG_MSG3                  */
#define BRCM_SWARCH_BCM_LOG_MSG4_MACRO          (0x8010U)    /**< @brief #BCM_LOG_MSG4                  */
#define BRCM_SWARCH_BCM_LOG_MSG_MACRO           (0x8011U)    /**< @brief #BCM_LOG_MSG_MACRO             */
#define BRCM_SWARCH_BCM_LOG_CRITICAL_MACRO      (0x8012U)    /**< @brief #BCM_LOG_CRITICAL              */
#define BRCM_SWARCH_BCM_LOG_ERROR_MACRO         (0x8013U)    /**< @brief #BCM_LOG_ERROR                 */
#define BRCM_SWARCH_BCM_LOG_INFO_MACRO          (0x8014U)    /**< @brief #BCM_LOG_INFO                  */
#define BRCM_SWARCH_BCM_LOG_DEBUG_MACRO         (0x8015U)    /**< @brief #BCM_LOG_DEBUG                 */
#define BRCM_SWARCH_BCM_LOG_MSG_PROC            (0x8016U)    /**< @brief #BCM_LogMsg                    */
#define BRCM_SWARCH_BCM_LOG_LEVEL_TYPE          (0x8017U)    /**< @brief #BCM_LogLevelType              */
#define BRCM_SWARCH_BCM_LOG_MSG0_PROC           (0x8018U)    /**< @brief #BCM_LogMsg0                   */
#define BRCM_SWARCH_BCM_LOG_MSG1_PROC           (0x8019U)    /**< @brief #BCM_LogMsg1                   */
#define BRCM_SWARCH_BCM_LOG_MSG2_PROC           (0x801AU)    /**< @brief #BCM_LogMsg2                   */
#define BRCM_SWARCH_BCM_LOG_MSG3_PROC           (0x801BU)    /**< @brief #BCM_LogMsg3                   */
#define BRCM_SWARCH_BCM_LOG_MSG4_PROC           (0x801CU)    /**< @brief #BCM_LogMsg4                   */
#define BRCM_SWARCH_BCM_LOG_SET_STRING_PROC     (0x801DU)    /**< @brief #BCM_LogSetString              */
#define BRCM_SWARCH_BCM_LOG_SET_STRING_MACRO    (0x801EU)    /**< @brief #BCM_LOG_SET_STRING            */


/** @} */

/**
    @name BCM Error Codes
    @{
    @brief Error return values

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
typedef int32_t BCM_ErrorType;
#define BCM_ERR_OK              (0x0)  /**< @brief No Error                          */
#define BCM_ERR_BUSY            (0x1)  /**< @brief Device or resource busy           */
#define BCM_ERR_NODEV           (0x2)  /**< @brief No device found                   */
#define BCM_ERR_NOT_FOUND       (0x3)  /**< @brief Not Found                         */
#define BCM_ERR_NOMEM           (0x4)  /**< @brief Out of memory                     */
#define BCM_ERR_NOSUPPORT       (0x5)  /**< @brief Not supported                     */
#define BCM_ERR_INVAL_PARAMS    (0x6)  /**< @brief Invalid argument                  */
#define BCM_ERR_INVAL_MAGIC     (0x7)  /**< @brief Invalid magic number              */
#define BCM_ERR_INVAL_STATE     (0x8)  /**< @brief Invalid state                     */
#define BCM_ERR_INVAL_BUF_STATE (0x9)  /**< @brief Invalid buffer state              */
#define BCM_ERR_EAGAIN          (0xA)  /**< @brief Try again                         */
#define BCM_ERR_TIME_OUT        (0xB)  /**< @brief Timeout                           */
#define BCM_ERR_UNINIT          (0xC)  /**< @brief Device or resource not initialized*/
#define BCM_ERR_CANCELLED       (0xD)  /**< @brief Cancel request success            */
#define BCM_ERR_DATA_INTEG      (0xE)  /**< @brief Data integrity error              */
#define BCM_ERR_AUTH_FAILED     (0xF)  /**< @brief Authentication error              */
#define BCM_ERR_VERSION         (0x10) /**< @brief Wrong version of hw/sw            */
#define BCM_ERR_BUS_FAILURE     (0x11) /**< @brief Bus Failure                       */
#define BCM_ERR_NACK            (0x12) /**< @brief NACK error                        */
#define BCM_ERR_MAX_ATTEMPS     (0x13) /**< @brief Maximum num of attempts           */
#define BCM_ERR_UNKNOWN         (0x14) /**< @brief Unknown error                     */
#define BCM_ERR_CUSTOM          (0x15) /**< @brief Module specific error             */
#define BCM_ERR_NOPERM          (0x16) /**< @brief Permission denied                 */
/** @} */

/**
    @name Masks for KLOG/ULOG
    @{
    @brief Mask for KLOG and ULOG in Component ID

    When an error is reported by a component, this bit in the component will identify whether the error is reported
    from Privileged context or Unprivileged context

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOGMASK_KERNEL (0x8000U)  /**< @brief mask for routing the error to KLOG */
#define BCM_LOGMASK_USER   (0x7FFFU)  /**< @brief mask for routing the error to ULOG */
/** @} */


/**
    @name Report Error Version
    @{
    @brief Report Error Version State.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
typedef uint32_t BCM_ErrVersionType;              /**< @brief Error Version        */
#define BCM_ERR_VERSION_0    (0UL)                /**< @brief version 1            */
#define BCM_ERR_VERSION_1    (1UL)                /**< @brief version 2            */

/** @} */
/**
    @name Report Error Version
    @{
    @brief Report Error Version State.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
typedef uint32_t BCM_DevInfoType;                        /**< @brief Device Info                     */
#define BCM_DEV_INFO_STACKING_EN_MASK      (0x000FUL)    /**< @brief Stacking Enable Info(EN/DIS)    */
#define BCM_DEV_INFO_STACKING_EN_SHIFT     (0UL)         /**< @brief Stacking Enable shift           */
#define BCM_DEV_INFO_STACKING_MODE_MASK    (0x00F0UL)    /**< @brief Stacking Info(MASTER/SLAVE)     */
#define BCM_DEV_INFO_STACKING_MODE_SHIFT   (4UL)         /**< @brief Stacking shift                  */
#define BCM_DEV_INFO_CPU_MASK              (0x0F00UL)    /**< @brief CPU Info(ARM/ARC)               */
#define BCM_DEV_INFO_CPU_SHIFT             (8UL)         /**< @brief CPU shift                       */
#define BCM_DEV_INFO_CPU_APP               (0x0UL)       /**< @brief Application processor     */
#define BCM_DEV_INFO_CPU_HSM               (0x1UL)       /**< @brief HSM processor             */
/** @} */

/**
    @name Boot mode Type
    @{
    @brief Boot mode Type

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
typedef uint8_t BCM_BootModeIdxType;        /**< @brief Boot mode Type         */
#define BCM_BOOT_MODE_IDX_ROM    (1U)       /**< @brief ROM                    */
#define BCM_BOOT_MODE_IDX_BL     (2U)       /**< @brief BL                     */
#define BCM_BOOT_MODE_IDX_FW     (3U)       /**< @brief FW                     */
/** @} */

/**
    @brief Error reporting - maximum custom values

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_ERR_MAX_CUSTOM_VALUES   (4UL)

/**
    @brief Error information Type

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
typedef struct sBCM_DbgMsgType {
    BCM_ErrVersionType  version;                            /**< @brief 32-bit version   */
    BCM_CompIDType      comp;                               /**< @brief 16-bit comp      */
    BCM_BootModeIdxType bootMode;                           /**< @brief  8-bit bootInfo  */
    uint8_t             instance;                           /**< @brief  8-bit instance  */
    uint64_t            timeMS;                             /**< @brief 64-bit api       */
    uint16_t            api;                                /**< @brief 16-bit api       */
    uint16_t            line;                               /**< @brief 16-bit line      */
    BCM_StateType       state;                              /**< @brief 32-bit state     */
    int32_t             error;                              /**< @brief 32-bit error     */
    uint32_t            custom[BCM_ERR_MAX_CUSTOM_VALUES];  /**< @brief 16 byte custom   */
    BCM_DevInfoType     devInfo;                            /**< @brief 32-bit devInfo   */
    uint32_t            rsvd[4];                            /**< @brief 32 byte reserved */
} BCM_DbgMsgType;


/**
    @name Log Levels
    @{
    @brief Levels for Log messages

    These are used for selection of allowed log messages

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
typedef uint16_t BCM_LogLevelType;     /**< @brief Log over Ethernet level Type */
#define BCM_LOG_LEVEL_CRITICAL    (0U)  /**< @brief Only critical errors. */
#define BCM_LOG_LEVEL_ERROR       (1U)  /**< @brief Critical and other errors. */
#define BCM_LOG_LEVEL_INFO        (2U)  /**< @brief Critical errors, other errors and information messages. */
#define BCM_LOG_LEVEL_DEBUG       (3U)  /**< @brief All messages. */
#define BCM_LOG_LEVEL_MAX         (3U)  /**< @brief Maximum level */
/** @} */

/** @brief Report a component error to the system

    This API is called by components to report an error to the system.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aCompID     16-bit component ID
    @param[in]      aInstanceID 8-bit instance ID (starting from 0)
    @param[in]      aApiID      16-bit component specific API or interface ID
    @param[in]      aErrorID    32-bit error ID
    @param[in]      aNumInts    Number of valid entries in aValues
    @param[in]      aValues     Pointer to 32-bit data for print/debug

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT

    @limitations None
*/
void BCM_ReportError(BCM_CompIDType aCompID,
                       uint8_t aInstanceID,
                       uint16_t aApiID,
                       int32_t aErrorID,
                       uint32_t aNumInts,
                       const uint32_t *const aValues);

/** @brief Report a component error to the system

    This API is called by components to report an error to the system.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aCompID     16-bit component ID
    @param[in]      aInstanceID 8-bit instance ID (starting from 0)
    @param[in]      aApiID      16-bit component specific API or interface ID
    @param[in]      aErrorID    32-bit error ID
    @param[in]      aLineNo     32-bit line number
    @param[in]      aState      32-bit state info
    @param[in]      aNumInts    Number of valid entries in aValues
    @param[in]      aValues     Pointer to 32-bit data for print/debug

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT

    @limitations None
*/
void BCM_ReportErrorV2(BCM_CompIDType aCompID,
                       uint8_t aInstanceID,
                       uint16_t aApiID,
                       int32_t aErrorID,
                       uint32_t aLineNo,
                       uint32_t aState,
                       uint32_t aNumInts,
                       const uint32_t *const aValues);

/** @brief Added Remote Debug Mesg to Local Debug Mesg Queue

    This API is called by modules to add an error to the system.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aDebugInfo     Debug Info to add in local system debug queue

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
void BCM_DbgMsgPutRaw(BCM_DbgMsgType* aDebugInfo);

/** @brief Initialize the error module

    This API is used to initialize the error module

    @behavior Sync, Non-reentrant

    @pre None

    @param void

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT

    @limitations None
*/
/*  @event         misra_c_2012_rule_8_6_violation, MISRA C-2012 Declarations and Definitions
    @issue         Function BCM_InitError is declared but never defined.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_8_6_violation] */
extern void BCM_InitError(void);

/** @brief Report log message

    This API is not directly called by modules to add a log message.
    Instead, use #BCM_LOG_CRITICAL, #BCM_LOG_ERROR, #BCM_LOG_INFO, #BCM_LOG_DEBUG.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aMsg           Pointer to the message

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
/*  @event         misra_c_2012_rule_5_8_violation, misra_c_2012_rule_8_6_violation
    @issue         Identifier is already used to represent a function with external linkage.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_5_8_violation] */
/* coverity[misra_c_2012_rule_8_6_violation] */
void BCM_LogMsg(BCM_DbgMsgType* aMsg);

/** @brief Report log message with no custom data

    This API is not directly called by modules to add a log message.
    Instead, use #BCM_LOG_CRITICAL, #BCM_LOG_ERROR, #BCM_LOG_INFO, #BCM_LOG_DEBUG.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aLogLevel        Log Level as described in #BCM_LogLevelType
    @param[in]     aCompID          Component ID as described in #BCM_CompIDType
    @param[in]     aInstanceID      8-bit instance ID
    @param[in]     aFileID          8-bit File ID (top two nibbles of design ID)
    @param[in]     aLine            Line number within file
    @param[in]     aState           State of the component/module
    @param[in]     aErr             Error code as described in #BCM_ErrorType

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
void BCM_LogMsg0(uint32_t aLogLevel, BCM_CompIDType aCompID, uint8_t aInstanceID,
                    uint16_t aFileID, uint32_t aLine, BCM_StateType aState, BCM_ErrorType aErr);

/** @brief Report log message with one custom data

    This API is not directly called by modules to add a log message.
    Instead, use #BCM_LOG_CRITICAL, #BCM_LOG_ERROR, #BCM_LOG_INFO, #BCM_LOG_DEBUG.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aLogLevel        Log Level as described in #BCM_LogLevelType
    @param[in]     aCompID          Component ID as described in #BCM_CompIDType
    @param[in]     aInstanceID      8-bit instance ID
    @param[in]     aFileID          8-bit File ID (top two nibbles of design ID)
    @param[in]     aLine            Line number within file
    @param[in]     aState           State of the component/module
    @param[in]     aErr             Error code as described in #BCM_ErrorType
    @param[in]     aCustom0         Custom data 0

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
void BCM_LogMsg1(uint32_t aLogLevel, BCM_CompIDType aCompID, uint8_t aInstanceID,
                    uint16_t aFileID, uint32_t aLine, BCM_StateType aState, BCM_ErrorType aErr,
                    uint32_t aCustom0);

/** @brief Report log message with two custom data

    This API is not directly called by modules to add a log message.
    Instead, use #BCM_LOG_CRITICAL, #BCM_LOG_ERROR, #BCM_LOG_INFO, #BCM_LOG_DEBUG.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aLogLevel        Log Level as described in #BCM_LogLevelType
    @param[in]     aCompID          Component ID as described in #BCM_CompIDType
    @param[in]     aInstanceID      8-bit instance ID
    @param[in]     aFileID          8-bit File ID (top two nibbles of design ID)
    @param[in]     aLine            Line number within file
    @param[in]     aState           State of the component/module
    @param[in]     aErr             Error code as described in #BCM_ErrorType
    @param[in]     aCustom0         Custom data 0
    @param[in]     aCustom1         Custom data 1

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
void BCM_LogMsg2(uint32_t aLogLevel, BCM_CompIDType aCompID, uint8_t aInstanceID,
                    uint16_t aFileID, uint32_t aLine, BCM_StateType aState, BCM_ErrorType aErr,
                    uint32_t aCustom0, uint32_t aCustom1);

/** @brief Report log message with three custom data

    This API is not directly called by modules to add a log message.
    Instead, use #BCM_LOG_CRITICAL, #BCM_LOG_ERROR, #BCM_LOG_INFO, #BCM_LOG_DEBUG.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aLogLevel        Log Level as described in #BCM_LogLevelType
    @param[in]     aCompID          Component ID as described in #BCM_CompIDType
    @param[in]     aInstanceID      8-bit instance ID
    @param[in]     aFileID          8-bit File ID (top two nibbles of design ID)
    @param[in]     aLine            Line number within file
    @param[in]     aState           State of the component/module
    @param[in]     aErr             Error code as described in #BCM_ErrorType
    @param[in]     aCustom0         Custom data 0
    @param[in]     aCustom1         Custom data 1
    @param[in]     aCustom2         Custom data 2

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
void BCM_LogMsg3(uint32_t aLogLevel, BCM_CompIDType aCompID, uint8_t aInstanceID,
                    uint16_t aFileID, uint32_t aLine, BCM_StateType aState, BCM_ErrorType aErr,
                    uint32_t aCustom0, uint32_t aCustom1, uint32_t aCustom2);

/** @brief Report log message with four custom data

    This API is not directly called by modules to add a log message.
    Instead, use #BCM_LOG_CRITICAL, #BCM_LOG_ERROR, #BCM_LOG_INFO, #BCM_LOG_DEBUG.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aLogLevel        Log Level as described in #BCM_LogLevelType
    @param[in]     aCompID          Component ID as described in #BCM_CompIDType
    @param[in]     aInstanceID      8-bit instance ID
    @param[in]     aFileID          8-bit File ID (top two nibbles of design ID)
    @param[in]     aLine            Line number within file
    @param[in]     aState           State of the component/module
    @param[in]     aErr             Error code as described in #BCM_ErrorType
    @param[in]     aCustom0         Custom data 0
    @param[in]     aCustom1         Custom data 1
    @param[in]     aCustom2         Custom data 2
    @param[in]     aCustom3         Custom data 3

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
void BCM_LogMsg4(uint32_t aLogLevel, BCM_CompIDType aCompID, uint8_t aInstanceID,
                    uint16_t aFileID, uint32_t aLine, BCM_StateType aState, BCM_ErrorType aErr,
                    uint32_t aCustom0, uint32_t aCustom1, uint32_t aCustom2, uint32_t aCustom3);

/** @brief Set log message string for formatted print

    This API is not directly called by modules to add a log message.
    Instead, use #BCM_LOG_CRITICAL, #BCM_LOG_ERROR, #BCM_LOG_INFO, #BCM_LOG_DEBUG.

    This function need not be implemented if #BCM_LOG_SET_STRING is not set.
    The implementation shall be done using thread local storage to ensure reentrancy.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aStr        Format string

    @return void

    @post None

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
/*  @event         misra_c_2012_rule_5_8_violation, misra_c_2012_rule_8_6_violation
    @issue         Identifier is already used to represent a function with external linkage.
    @risk          None
    @justification Issue reported due to Coverity build configuration. */
/* coverity[misra_c_2012_rule_5_8_violation] */
/* coverity[misra_c_2012_rule_8_6_violation] */
void BCM_LogSetString(const char* aStr);

/* @start_no_export_python */

/**
    @brief Macro to preserve the log string (could be use a thread local storage for preserving the pointer)

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#ifndef BCM_LOG_SET_STRING
#define BCM_LOG_SET_STRING(aString)
#endif
/**
    @brief Log message Macro with no data value

    This macro will call BCM_LogMsg function with no data value.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_MSG0(aLogLevel, aCompID, aFileID, aInstanceID, aState, aErr, aFormatMsg)    \
    BCM_LOG_SET_STRING(aFormatMsg);                                                         \
    BCM_LogMsg0(aLogLevel, aCompID, aInstanceID, aFileID, __LINE__, aState, aErr);

/**
    @brief Log message Macro with one data value

    This macro will call BCM_LogMsg function with one data value.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_MSG1(aLogLevel, aCompID, aFileID, aInstanceID, aState, aErr, aFormatMsg, aVal0) \
    BCM_LOG_SET_STRING(aFormatMsg);                                                             \
    BCM_LogMsg1(aLogLevel, aCompID, aInstanceID, aFileID, __LINE__, aState, aErr, aVal0);

/**
    @brief Log message Macro with two data values

    This macro will call BCM_LogMsg function with two data values.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_MSG2(aLogLevel, aCompID, aFileID, aInstanceID, aState, aErr, aFormatMsg, aVal0, aVal1)      \
    BCM_LOG_SET_STRING(aFormatMsg);                                                                         \
    BCM_LogMsg2(aLogLevel, aCompID, aInstanceID, aFileID, __LINE__, aState, aErr, aVal0, aVal1);

/**
    @brief Log message Macro with three data values

    This macro will call BCM_LogMsg function with three data value.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_MSG3(aLogLevel, aCompID, aFileID, aInstanceID, aState, aErr, aFormatMsg, aVal0, aVal1, aVal2)   \
    BCM_LOG_SET_STRING(aFormatMsg);                                                                             \
    BCM_LogMsg3(aLogLevel, aCompID, aInstanceID, aFileID, __LINE__, aState, aErr, aVal0, aVal1, aVal2);

/**
    @brief Log message Macro with all four data values

    This macro will call BCM_LogMsg function with all four data values.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_MSG4(aLogLevel, aCompID, aFileID, aInstanceID, aState, aErr, aFormatMsg, aVal0, aVal1, aVal2, aVal3)    \
    BCM_LOG_SET_STRING(aFormatMsg);                                                                                     \
    BCM_LogMsg4(aLogLevel, aCompID, aInstanceID, aFileID, __LINE__, aState, aErr, aVal0, aVal1, aVal2, aVal3);

/**
    @brief Log message Macro

    This macro funcion decides which log message macro should be called.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_MSG_MACRO(_0, _1, _2, _3, _4, _LOG_MSG_MACRO, ...) _LOG_MSG_MACRO

/**
    @brief Critical error log message macro

    This should be used for any critical faults that may lead to unexpected system behavior.
    Use of this macro must be thoroughly reviewed by Tech Lead and SW Architect for relevance.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_CRITICAL(aInstanceID, aState, aErr,...)                                                          \
        BCM_LOG_MSG_MACRO(__VA_ARGS__, BCM_LOG_MSG4, BCM_LOG_MSG3, BCM_LOG_MSG2, BCM_LOG_MSG1, BCM_LOG_MSG0)     \
         (BCM_LOG_LEVEL_CRITICAL, BCM_LogCompID, BCM_LogFileID, aInstanceID, aState, aErr, __VA_ARGS__)

/**
    @brief Non critical error log message macro

    This macro should be used in interface functions of a component and command handlers.
    and state handlers of the modules. Other internal design functions are supposed to use #BCM_LOG_DEBUG.
    This is to ensure that the error messages reported by a component are understandable by external parties,
    as the architecture documentation is available with them and can correlate these messages.
    This macro accepts variable number of arguments and calls BCM_LOG_MSG_MACRO macro function.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_ERROR(aInstanceID, aState, aErr, ...)                                                            \
        BCM_LOG_MSG_MACRO(__VA_ARGS__, BCM_LOG_MSG4, BCM_LOG_MSG3, BCM_LOG_MSG2, BCM_LOG_MSG1, BCM_LOG_MSG0)     \
         (BCM_LOG_LEVEL_ERROR, BCM_LogCompID, BCM_LogFileID, aInstanceID, aState, aErr, __VA_ARGS__)

/**
    @brief Information log message macro

    This should be used for reporting critical state transitions of modules or components.
    This may be used for any dynamic commands that are received and serviced by Dispatch Module.
    Other modules must use BCM_LOG_DEBUG messages.
    state handler does not need to report state transition. It must be taken care by module helpers.
    This must be used by Dispatch module and Module helpers only.
    This macro accepts variable number of arguments and calls BCM_LOG_MSG_MACRO macro function.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_INFO(aInstanceID, aState, ...)                                                                   \
        BCM_LOG_MSG_MACRO(__VA_ARGS__, BCM_LOG_MSG4, BCM_LOG_MSG3, BCM_LOG_MSG2, BCM_LOG_MSG1, BCM_LOG_MSG0)     \
         (BCM_LOG_LEVEL_INFO, BCM_LogCompID, BCM_LogFileID, aInstanceID, aState, BCM_ERR_OK, __VA_ARGS__)

/**
    @brief Debug log message macro

    This macro accepts variable number of arguments and calls BCM_LOG_MSG_MACRO macro function.
    This must be used mostly with the Internal design/static functions.

    @trace #BRCM_SWREQ_BCM_COMPONENT
*/
#define BCM_LOG_DEBUG(aInstanceID, aState, aErr, ...)                                                                  \
        BCM_LOG_MSG_MACRO(__VA_ARGS__, BCM_LOG_MSG4, BCM_LOG_MSG3, BCM_LOG_MSG2, BCM_LOG_MSG1, BCM_LOG_MSG0)     \
         (BCM_LOG_LEVEL_DEBUG, BCM_LogCompID, BCM_LogFileID, aInstanceID, aState, aErr, __VA_ARGS__)

#endif /* BCM_ERR_H */
/* @end_no_export_python */
/** @} */
