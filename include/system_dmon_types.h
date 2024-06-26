/*****************************************************************************
 Copyright 2018-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_system_dmon_types Types
    @ingroup grp_system_dmon_overview

    @addtogroup grp_system_dmon_types
    @{

    @limitations None

    @file system_dmon_types.h
    @brief System Device Monitor Interface
    This header file contains the interface functions for System Device Monitor Interface

    @version 1.0 Initial Version
*/


#ifndef SYSTEM_DMON_TYPES_H
#define SYSTEM_DMON_TYPES_H

#include <stdint.h>
#include <stdlib.h>
#include <bcm_comp.h>
#include <bcm_utils.h>
#include <nvm_otp_types.h>
#include <system_mcu.h>

/**
    @name System Device Monitor Architecture IDs
    @{
    @brief Architecture IDs for System Device Monitor
*/

#define BRCM_SWARCH_DMON_MACRO                          (0x8800U)   /**< @brief #DMON_MAGIC             */
#define BRCM_SWARCH_DMON_ID_MACRO                       (0x8801U)   /**< @brief #DMON_ID                */
#define BRCM_SWARCH_DMON_ID_TYPE                        (0x8802U)   /**< @brief #DMON_IDType            */
#define BRCM_SWARCH_DMON_SECURITY_MODE_TYPE             (0x8803U)   /**< @brief #DMON_SecurityModeType  */
#define BRCM_SWARCH_DMON_DEVICE_TYPE                    (0x8804U)   /**< @brief #DMON_DeviceType        */
#define BRCM_SWARCH_DMON_CPU_PROFILE_TASK_MAX_MACRO     (0x8805U)   /**< @brief #DMON_CPU_PROFILE_TASK_MAX */

#define BRCM_SWARCH_DMON_PING_MSG_TYPE                  (0x8810U)   /**< @brief #DMON_PingMsgType       */
#define BRCM_SWARCH_DMON_MEM_ACCESS_MSG_TYPE            (0x8811U)   /**< @brief #DMON_MemAccessMsgType  */
#define BRCM_SWARCH_DMON_SW_VERSION_STRLEN_MACRO        (0x8812U)   /**< @brief #DMON_SW_VERSION_STR_LEN*/
#define BRCM_SWARCH_DMON_SW_VERSION_MSG_TYPE            (0x8813U)   /**< @brief #DMON_SwVersionMsgType  */
#define BRCM_SWARCH_DMON_HW_VERSION_MSG_TYPE            (0x8814U)   /**< @brief #DMON_HwVersionMsgType  */
#define BRCM_SWARCH_DMON_REBOOT_MSG_TYPE                (0x8815U)   /**< @brief #DMON_RebootMsgType     */
#define BRCM_SWARCH_DMON_HEART_BEAT_MSG_TYPE            (0x8816U)   /**< @brief #DMON_HeartBeatMsgType  */
#define BRCM_SWARCH_DMON_TIME_TYPE                      (0x8817U)   /**< @brief #DMON_TimeType          */
#define BRCM_SWARCH_DMON_SYNC_MSG_TYPE                  (0x8818U)   /**< @brief #DMON_SyncMsgType       */
#define BRCM_SWARCH_DMON_DEEPSLEEP_MSG_TYPE             (0x8819U)   /**< @brief #DMON_DeepSleepMsgType  */
#define BRCM_SWARCH_DMON_CPU_PROFILE_TYPE               (0x881AU)   /**< @brief #DMON_CPUProfileType     */
#define BRCM_SWARCH_DMON_STOP_MSG_TYPE                  (0x881BU)   /**< @brief #DMON_StopMsgType        */

#define BRCM_SWARCH_DMON_VOLT_TYPE                      (0x8820U)   /**< @brief #DMON_VoltType           */
#define BRCM_SWARCH_DMON_VOLT_MONITOR_EVENT_TYPE        (0x8821U)   /**< @brief #DMON_VoltMonitorEventType*/
#define BRCM_SWARCH_DMON_VOLT_STATUS_TYPE               (0x8822U)   /**< @brief #DMON_VoltStatusType     */
#define BRCM_SWARCH_DMON_TEMP_TYPE                      (0x8823U)   /**< @brief #DMON_TempType           */
#define BRCM_SWARCH_DMON_TEMP_MONITOR_EVENT_TYPE        (0x8824U)   /**< @brief #DMON_TempMonitorEventType*/
#define BRCM_SWARCH_DMON_VOLT_CFG_TYPE                  (0x8825U)   /**< @brief #DMON_VoltCfgType        */
#define BRCM_SWARCH_DMON_TEMP_CFG_TYPE                  (0x8826U)   /**< @brief #DMON_TempCfgType        */
#define BRCM_SWARCH_DMON_SAFETY_CFG_TYPE                (0x8829U)   /**< @brief #DMON_SafetyCfgType      */

#define BRCM_SWARCH_DMON_CFG_TYPE                       (0x8840U)   /**< @brief #DMON_CfgType           */
/** @} */

/**
    @brief Device Monitor Max message size

    @trace #BRCM_SWREQ_DMON
*/
#define DMON_MAGIC          (0x4E4F4D44UL)      /**< @brief DMON config magic   */
#define DMON_MAX_MSG_SIZE   (256UL)

/**
    @name DMN ID Macros
    @{
    @brief DMN ID construction macro

    @trace #BRCM_SWREQ_DMON
*/
#define DMON_ID(x)       BCM_MSG(BCM_GROUPID_SYS, BCM_DMN_ID, (x))
#define DMON_ID_ASYNC(x) BCM_MSG_ASYNC(BCM_GROUPID_SYS, BCM_DMN_ID, (x))
/** @} */

/**
    @name DMN Message IDs
    @{
    @brief Message IDs for exchange on message queues and Host

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_DMON
*/
typedef BCM_MsgType DMON_IDType;     /**< @brief DMON message ID Type */
#define DMON_ID_PING             DMON_ID(0x01U)   /**< @brief #DMON_PingMsgType        #None           */
#define DMON_ID_SYNC             DMON_ID(0x02U)   /**< @brief #DMON_SyncMsgType        #None           */
#define DMON_ID_SYNC_WAIT        DMON_ID(0x03U)   /**< @brief #DMON_SyncMsgType        #None           */

#define DMON_ID_MEM_WRITE        DMON_ID(0x10U)   /**< @brief #DMON_MemAccessMsgType   #DBGMEM_Write   */
#define DMON_ID_MEM_READ         DMON_ID(0x11U)   /**< @brief #DMON_MemAccessMsgType   #DBGMEM_Read    */

#define DMON_ID_SW_VERSION       DMON_ID(0x20U)   /**< @brief #DMON_SwVersionMsgType   #None           */
#define DMON_ID_HW_VERSION       DMON_ID(0x21U)   /**< @brief #DMON_HwVersionMsgType...#MCU_GetVersion */
#define DMON_ID_REBOOT           DMON_ID(0x22U)   /**< @brief #DMON_RebootMsgType      #MCU_RebootReq  */
#define DMON_ID_DEEPSLEEP        DMON_ID(0x23U)   /**< @brief #DMON_DeepSleepMsgType   #None           */
#define DMON_ID_LAST_HEART_BEAT  DMON_ID(0x24U)   /**< @brief #DMON_HeartBeatMsgType   #None           */
#define DMON_ID_STOP             DMON_ID(0x25U)   /**< @brief #DMON_StopMsgType        #None           */

#define DMON_ID_VTMON_NOTIFICATION     DMON_ID(0x30U)   /**< @brief #BCM_NotifyDataType      #None           */

#define DMON_ID_HEART_BEAT       DMON_ID_ASYNC(0x01U) /**< @brief #DMON_HeartBeatMsgType   #None       */
/** @} */

/**
   @name Device Master Slave ID
   @{
   @trace #BRCM_SWREQ_DMON
 */
typedef uint32_t DMON_DeviceType;
#define DMON_DEVICE_MASTER          (0UL)  /**< @brief Device master mode */
#define DMON_DEVICE_SLAVE_1         (1UL)  /**< @brief Device ID slave_1 mode */
#define DMON_DEVICE_SLAVE_2         (2UL)  /**< @brief Device ID slave_2 mode */
/** @} */

/**
    @brief Memory Access Message

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_MemAccessMsgType {
    uint32_t        addr;
    uint32_t        width;
    uint32_t        len;
    DMON_DeviceType deviceID;
    uint8_t         data[128UL];
} DMON_MemAccessMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_MemAccessMsgType, 144UL, DMON_MAX_MSG_SIZE)

/**
    @brief Software Version max length

    @trace #BRCM_SWREQ_DMON
*/
#define DMON_SW_VERSION_STR_LEN          (100UL)

/**
    @brief Software Version

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_SwVersionMsgType {
    char      str[DMON_SW_VERSION_STR_LEN];
} DMON_SwVersionMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_SwVersionMsgType, 100UL, DMON_MAX_MSG_SIZE)

/**
    @name Device Security Mode Type
    @{
    @brief Device security modes

    @trace #BRCM_SWREQ_DMON
*/
typedef uint32_t DMON_SecurityModeType;     /**< @brief typedef for Device Security mode */
#define DMON_SECURITY_MODE_UNKNOWN (0x0UL)  /**< @brief Unknown mode */
#define DMON_SECURITY_MODE_NONE    (0x1UL)  /**< @brief Unsecured */
#define DMON_SECURITY_MODE_ECC     (0x2UL)  /**< @brief Secured through ECC384 */
#define DMON_SECURITY_MODE_ECC384  (0x2UL)  /**< @brief Secured through ECC384 */
#define DMON_SECURITY_MODE_RSA     (0x3UL)  /**< @brief Secured through RSA */
#define DMON_SECURITY_MODE_ECC256  (0x4UL)  /**< @brief Secured through ECC256 */
#define DMON_SECURITY_MODE_MAX     (DMON_SECURITY_MODE_ECC256) /**< @brief Maximum mode value supported */
/** @} */

/**
    @brief Device Monitor HW version information structure

    @trace #BRCM_SWREQ_DMON
 */
typedef struct sDMON_HwVersionMsgType {
    uint32_t                manuf;  /**< @brief manufacturer ID */
    uint32_t                model;  /**< @brief model number */
    uint32_t                rev;    /**< @brief revision number */
    DMON_SecurityModeType   secMode;/**< @brief Security Mode */
} DMON_HwVersionMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_HwVersionMsgType, 16UL, DMON_MAX_MSG_SIZE)

/**
    @brief Ping Message (Response only, Command goes with empty payload)

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_PingMsgType {
    BCM_BootModeType        mode;           /**< @brief mode: ROM/BL/FW             */
    DMON_HwVersionMsgType   version;        /**< @brief HW version                  */
} DMON_PingMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_PingMsgType, 20UL, DMON_MAX_MSG_SIZE)

/**
    @brief Sync Message (Response only, Command goes with empty payload)

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_SyncMsgType {
    BCM_BootModeType            mode;           /**< @brief mode: ROM/BL/FW             */
    BCM_StateType               state;          /**< @brief state: UNINIT/INIT/READY/RUN*/
    DMON_HwVersionMsgType       version;        /**< @brief HW version                  */
    uint64_t                    initTime;       /**< @brief Init Time                   */
    uint64_t                    readyTime;      /**< @brief Ready Time                  */
    uint64_t                    runTime;        /**< @brief Run  Time                   */
    uint8_t                     rsvd[208];
} DMON_SyncMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_SyncMsgType, 256UL, DMON_MAX_MSG_SIZE)

/**
    @brief Reboot Message

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_RebootMsgType {
    uint32_t            reserved[2UL];  /**< @brief left for legacy      */
    uint32_t            delayMs;        /**< @brief delay in milliseconds before rebooting */
} DMON_RebootMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_RebootMsgType, 12UL, DMON_MAX_MSG_SIZE)

/**
    @brief DeepSleep Message

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_DeepSleepMsgType {
    uint32_t            delayMs;        /**< @brief delay in milliseconds before entering deepSleep mode */
} DMON_DeepSleepMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_DeepSleepMsgType, 4UL, DMON_MAX_MSG_SIZE)

/**
    @brief Stop Message

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_StopMsgType {
    uint64_t requestPortMask;       /**< @brief [input]  Mask of ports to be acted upon                                */
    uint32_t timeOutMs;             /**< @brief [input]  Timeout in milli seconds                                      */
    uint8_t  rsvdIn[36UL];          /**< @brief [input]  Reserved fields                                               */

    uint64_t tc10EnabledPortMask;   /**< @brief [output] Mask of ports on which tc10 is enabled                        */
    uint64_t successPortMask;       /**< @brief [output] Mask of ports on which normal operation succeeded.
                                                         When tc10 is enabled on a particular port, this mask indicates
                                                         that LPS handshake through sleep operation was successful.
                                                         Similarly for a non-tc10 port, this mask indicates that the
                                                         administrative mode DOWN was successful.                      */
    uint64_t forcedSuccessPortMask; /**< @brief [output] Mask of ports on which forced operation succeeded.
                                                         When tc10 is enabled on a particular port, this mask indicates
                                                         that forceSleep operation was successful                      */
    uint64_t abortPortMask;         /**< @brief [output] Mask of ports where LPS handshake was aborted by link partner */
    uint64_t timedOutPortMask;      /**< @brief [output] Mask of ports which timed-out                                 */
    uint64_t failedPortMask;        /**< @brief [output] Mask of ports which failed for unknown reasons                */
    uint8_t  rsvdOut[32UL];         /**< @brief Reserved fields                                                        */
} DMON_StopMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_StopMsgType, 128U, DMON_MAX_MSG_SIZE)

/**
    @brief Time info

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_TimeType {
    uint32_t    s;
    uint32_t    ns;
} DMON_TimeType;
BCM_STATIC_SIZE_ASSERT(DMON_TimeType, 8UL, DMON_MAX_MSG_SIZE)

/**
    @brief CPU Profile maximum task count

    @trace #BRCM_SWREQ_DMON
*/
#define DMON_CPU_PROFILE_TASK_MAX        (18UL)

/**
    @brief CPU Profile message type for #BCM_NotifyEvent

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_CPUProfileType {
    uint16_t percentage[DMON_CPU_PROFILE_TASK_MAX]; /**< @brief CPU profile % (Stored as x100) */
    uint8_t  totalTasks;                            /**< @brief Total tasks count              */
    uint8_t  idleTaskID;                            /**< @brief Idle task ID                   */
    uint8_t  resv[2];                               /**< @brief Reserved                       */
} DMON_CPUProfileType;
BCM_STATIC_SIZE_ASSERT(DMON_CPUProfileType, 40UL, sizeof(BCM_NotifyDataType))

/**
    @name Voltage
    @{
    @brief Voltage in millivolts

    @trace #BRCM_SWREQ_DMON
*/
typedef uint16_t DMON_VoltType;
#define DMON_VOLT_NONE            (0UL)
#define DMON_VOLT_0V8             (800U)
#define DMON_VOLT_1V0             (1000U)
#define DMON_VOLT_1V8             (1800U)
#define DMON_VOLT_3V3             (3300U)
/** @} */

/**
    @name Voltage monitor event
    @{
    @brief Voltage monitor event

    @trace #BRCM_SWREQ_DMON
*/
typedef uint16_t DMON_VoltMonitorEventType;
#define DMON_VOLT_MONITOR_EVENT_HIGH_THRESH1_MASK      (0x0001U)
#define DMON_VOLT_MONITOR_EVENT_HIGH_THRESH1_SHIFT     (0U)
#define DMON_VOLT_MONITOR_EVENT_HIGH_THRESH2_MASK      (0x0002U)
#define DMON_VOLT_MONITOR_EVENT_HIGH_THRESH2_SHIFT     (1U)
#define DMON_VOLT_MONITOR_EVENT_LOW_THRESH1_MASK       (0x0010U)
#define DMON_VOLT_MONITOR_EVENT_LOW_THRESH1_SHIFT      (4U)
#define DMON_VOLT_MONITOR_EVENT_LOW_THRESH2_MASK       (0x0020U)
#define DMON_VOLT_MONITOR_EVENT_LOW_THRESH2_SHIFT      (5U)
/** @} */

/**
    @brief Voltage Status

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_VoltStatusType {
    DMON_VoltType               nominalValue;
    DMON_VoltMonitorEventType   events;
} DMON_VoltStatusType;
BCM_STATIC_SIZE_ASSERT(DMON_VoltStatusType, 4UL, DMON_MAX_MSG_SIZE)

/**
    @brief Temperature

    @trace #BRCM_SWREQ_DMON
*/
typedef int16_t DMON_TempType;

/**
    @name Temperature monitor event
    @{
    @brief Temperature monitor event

    @trace #BRCM_SWREQ_DMON
*/
typedef uint16_t DMON_TempMonitorEventType;
#define DMON_TEMP_MONITOR_EVENT_THRESH2_MASK      (0x0001U)
#define DMON_TEMP_MONITOR_EVENT_THRESH2_SHIFT     (0U)
#define DMON_TEMP_MONITOR_EVENT_THRESH1_MASK      (0x0002U)
#define DMON_TEMP_MONITOR_EVENT_THRESH1_SHIFT     (1U)
/** @} */

/**
    @brief Heartbeat Message

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_HeartBeatMsgType {
    uint32_t                    version;
    uint32_t                    state;
    DMON_TimeType               upTime;
    uint32_t                    count;
    uint32_t                    voltage;
    uint32_t                    voltage_1v0;
    uint32_t                    voltage_1v8;
    uint32_t                    voltage_3v3;
    int32_t                     temperature;
    DMON_VoltStatusType         voltageStatus[4UL];
    DMON_TempMonitorEventType   temperatureEvent;
    MCU_TimeoutFaultType        timeoutFaultStatus;
    MCU_MemoryFaultType         memoryFaultStatus;
    MCU_MiscFaultType           miscFaultStatus;
    DMON_CPUProfileType         cpuProfile;
    uint64_t                    tc10EnableMask;
    uint64_t                    tc10SleepMask;
    uint64_t                    tc10WakeLocalMask;
    uint64_t                    linkStateMask;
    uint64_t                    extPhySafetyEventMask;
    uint32_t                    rsvd[28UL];
} DMON_HeartBeatMsgType;
BCM_STATIC_SIZE_ASSERT(DMON_HeartBeatMsgType, 256UL, DMON_MAX_MSG_SIZE)


/**
    @brief Voltage configuration

    highThresh1 and highThresh2 should be greater than nominalValue.
    lowThresh1 and lowThresh2 must be less than nominalValue.

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_VoltCfgType {
    DMON_VoltType               nominalValue;   /**< @brief Nominal voltage @xsd default:DMON_VOLT_NONE */
    uint16_t                    highThresh1;    /**< @brief High threshold @xsd default:0               */
    uint16_t                    highThresh2;    /**< @brief High threashold @xsd default:0              */
    uint16_t                    lowThresh1;     /**< @brief Low threshold @xsd default:0                */
    uint16_t                    lowThresh2;     /**< @brief Low threshold @xsd default:0                */
    DMON_VoltMonitorEventType   faultEnable;    /**< @brief Fault enable                                */
    DMON_VoltMonitorEventType   intrEnable;     /**< @brief Interrupt Enable                            */
    uint16_t                    reserved;       /**< @brief @xsd rsvd                                   */
} DMON_VoltCfgType;
BCM_STATIC_SIZE_ASSERT(DMON_VoltCfgType, 16UL, 16UL)


/**
    @brief Temperature configuration

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_TempCfgType {
    DMON_TempType               thresh1;        /**< @brief Threshold @xsd default:0        */
    DMON_TempType               thresh2;        /**< @brief Threshold @xsd default:0        */
    DMON_TempMonitorEventType   faultEnable;    /**< @brief Fault enable                    */
    DMON_TempMonitorEventType   intrEnable;     /**< @brief Interrupt Enable                */
    uint32_t                    reserved[2UL];  /**< @brief @xsd rsvd                       */
} DMON_TempCfgType;
BCM_STATIC_SIZE_ASSERT(DMON_TempCfgType, 16UL, 16UL)


/**
    @brief Safety configuration

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_SafetyCfgType {
    DMON_VoltCfgType            volt[6UL];
    DMON_TempCfgType            temperature;
    uint32_t                    reserved0[2UL];     /**< @brief @xsd rsvd       */
    MCU_TimeoutFaultType        timeoutFault;
    MCU_MemoryFaultType         memoryFault;
    MCU_MiscFaultType           miscFault;
    uint16_t                    reserved1;          /**< @brief @xsd rsvd       */
    uint32_t                    reserved2[32UL];    /**< @brief @xsd rsvd       */
} DMON_SafetyCfgType;
BCM_STATIC_SIZE_ASSERT(DMON_SafetyCfgType, 256UL, 256UL)

/**
    @brief Device monitor configuration

    @trace #BRCM_SWREQ_DMON
*/
typedef struct sDMON_CfgType {
    uint32_t                    magic;          /**< @brief Magic number ('D', 'M', 'O', 'N') @xsd constant:DMON_MAGIC      */
    uint32_t                    reserved;       /**< reserved @xsd rsvd                         */
    DMON_SafetyCfgType          safety;
    OTP_CfgType                 otp;
    uint8_t                     reserved1[2296UL];   /**< reserved @xsd rsvd                         */
} DMON_CfgType;
BCM_STATIC_SIZE_ASSERT(DMON_CfgType, 3584UL, 3584UL)

#endif /* SYSTEM_DMON_TYPES_H */
/** @} */
