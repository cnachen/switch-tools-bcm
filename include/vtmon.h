/*****************************************************************************
 Copyright 2016-2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_vtmondrv_ifc Interface
    @ingroup grp_vtmondrv

    @addtogroup grp_vtmondrv_ifc
    @{
    @section sec_vtmon_overview Overview
    @image html vtmon_overview.jpg "Driver overview diagram"
    VTMON driver provides interface to read and monitor the chip
    die-temperature and voltages.

    The following features are supported by VTMON driver:
    -# API to read the die-temperature in Celsius
    -# API to read voltage
    -# Configure high/low temperature threshold notification
    -# Configure high/low voltage threshold notification

    The driver continuously monitors the temperature and voltages and raises
    interrupts when the monitored parameters are below associated low and above
    associated high thresholds.

    @section sec_vtmon_fsm State Machine
    @image html vtmon_state_machine.jpg "Driver state machine"

    @section sec_vtmon_seq Sequence Diagrams
    Below diagram shows the indication callback for temperature. In a similar
    way, voltage notification callbacks are given to the client when the
    thresholds are crossed.
    @image html vtmon_seq_diagram_generic.jpg "Generic use-case sequence diagram"

    @section sec_vtmon_perf Performance & Memory

    | Performance       | Description                                       |
    |:-----------------:|:-------------------------------------------------:|
    | CPU Load          |   NA                                              |
    | Memory Bandwidth  |   NA                                              |
    | HW Utilization    |   NA                                              |

    @includedoc drivers_vtmon.dep

    @limitations None

    @file vtmon.h
    @brief VTMON Driver APIs
    This header file contains the interface for VTMON Driver
    @version 0.50 Imported from docx
*/

#ifndef VTMON_H
#define VTMON_H

#include <stdint.h>
#include <system_dmon.h>

/**
    @name VTMON Driver API IDs
    @{
    @brief API IDs for VTMON driver
*/
#define BRCM_SWARCH_VTMON_VOLT_ID_TYPE              (0x8101U)    /**< @brief #VTMON_VoltIDType            */
#define BRCM_SWARCH_VTMON_TEMP_TYPE                 (0x8102U)    /**< @brief #VTMON_TempType              */
#define BRCM_SWARCH_VTMON_VOLT_TYPE                 (0x8103U)    /**< @brief #VTMON_VoltType              */
#define BRCM_SWARCH_VTMON_TEMP_CONFIG_TYPE          (0x8104U)    /**< @brief #VTMON_TempConfigType        */
#define BRCM_SWARCH_VTMON_VOLT_CONFIG_TYPE          (0x8105U)    /**< @brief #VTMON_VoltConfigType        */
#define BRCM_SWARCH_VTMON_CONFIG_TYPE               (0x8106U)    /**< @brief #VTMON_ConfigType            */
#define BRCM_SWARCH_VTMON_INIT_PROC                 (0x8107U)    /**< @brief #VTMON_Init                  */
#define BRCM_SWARCH_VTMON_DEINIT_PROC               (0x8108U)    /**< @brief #VTMON_Deinit                */
#define BRCM_SWARCH_VTMON_SET_TEMP_MONITOR_PROC     (0x8109U)    /**< @brief #VTMON_SetTemperatureMonitor */
#define BRCM_SWARCH_VTMON_GET_TEMP_PROC             (0x810AU)    /**< @brief #VTMON_GetTemperature        */
#define BRCM_SWARCH_VTMON_SET_VOLT_MONITOR_PROC     (0x810BU)    /**< @brief #VTMON_SetVoltageMonitor     */
#define BRCM_SWARCH_VTMON_GET_VOLT_PROC             (0x810CU)    /**< @brief #VTMON_GetVoltage            */
#define BRCM_SWARCH_VTMON_ENABLE_NOTIFICATION_PROC  (0x810DU)    /**< @brief #VTMON_EnableNotification    */
#define BRCM_SWARCH_VTMON_DISABLE_NOTIFICATION_PROC (0x810EU)    /**< @brief #VTMON_DisableNotification   */
/** @} */

/**
    @name VTMON_VoltIDType
    @{
    @brief Voltage ID type

    @trace #BRCM_SWREQ_VTMON_KERNEL_INTERFACE
*/
typedef uint32_t VTMON_VoltIDType;                  /**< @brief VTMON Voltage ID type */
#define VTMON_VOLT_ID_INVALID               (0UL)   /**< @brief VTMON voltage ID Invalid  */
#define VTMON_VOLT_ID_1V0                   (1UL)   /**< @brief VTMON voltage ID for 1.0V */
#define VTMON_VOLT_ID_1V8                   (2UL)   /**< @brief VTMON voltage ID for 1.8V */
#define VTMON_VOLT_ID_3V3                   (3UL)   /**< @brief VTMON voltage ID for 3.3V */
#define VTMON_VOLT_ID_MAX                   (VTMON_VOLT_ID_3V3) /**< @brief VTMON max voltage ID */
/** @} */

/**
    @brief VTMON temperature

    VTMON temperature type (in Celsius)

    @trace #BRCM_SWREQ_VTMON_KERNEL_INTERFACE
*/
typedef int16_t VTMON_TempType;

/**
    @brief VTMON voltage

    VTMON voltage type (in mV)

    @trace #BRCM_SWREQ_VTMON_KERNEL_INTERFACE
*/
typedef uint16_t VTMON_VoltType;

/**
    @brief Temperature configuration

    @trace #BRCM_SWREQ_VTMON_KERNEL_INTERFACE
*/
typedef struct sVTMON_TempConfigType {
    VTMON_TempType threshLow;   /**< @brief Temperature low threshold value
                                     (in Celsius) */
    VTMON_TempType threshHigh;  /**< @brief Temperature high threshold value
                                     (in Celsius) */
    VTMON_TempType thresh1High;  /**< @brief Temperature high1 threshold value
                                     (in Celsius) */
    DMON_TempMonitorEventType faultEnable;    /**< @brief Fault enable bit mask     */
    DMON_TempMonitorEventType intrEnable;     /**< @brief Interrupt Enable bit mask */
} VTMON_TempConfigType;

/**
    @brief Voltage configuration

    @trace #BRCM_SWREQ_VTMON_KERNEL_INTERFACE
*/
typedef struct sVTMON_VoltConfigType {
    VTMON_VoltIDType ID;                      /**< @brief Voltage ID */
    VTMON_VoltType threshLow;                 /**< @brief Voltage low1 threshold value (in mV)  */
    VTMON_VoltType threshHigh;                /**< @brief Voltage high1 threshold value (in mV) */
    VTMON_VoltType thresh1Low;                /**< @brief Voltage low2 threshold value (in mV)  */
    VTMON_VoltType thresh1High;               /**< @brief Voltage high2 threshold value (in mV) */
    DMON_VoltMonitorEventType faultEnable;    /**< @brief Fault enable bit mask                 */
    DMON_VoltMonitorEventType intrEnable;     /**< @brief Interrupt Enable bit mask             */
} VTMON_VoltConfigType;

/**
    @brief VTMON configuration

    @trace #BRCM_SWREQ_VTMON_KERNEL_INTERFACE
*/
typedef struct sVTMON_ConfigType {
    VTMON_TempConfigType tempConfig;                    /**< @brief Temperature configuration */
    VTMON_VoltConfigType voltConfig[VTMON_VOLT_ID_MAX]; /**< @brief Voltage configuration */
} VTMON_ConfigType;

/** @brief Initialize VTMON driver

    This API initializes VTMON driver and hardware. It configures the thresholds for
    temperature & voltage. Upon initialization, VTMON temp and voltage notification
    is not enabled. User shall enable the notification by calling #VTMON_EnableNotification()
    After initialization of the vtmon hardware, it might take few milliseconds
    before first valid sample is available (Refer to the chip TRM for details about
    the vtmon sampling time)

    @behavior Sync, Non-reentrant

    @pre TBD

    @param[in]      aConfig     VTMON configuration. If aConfig is NULL, VTMON
                                driver is not  initialized

    @return     void

    @post TBD

    @trace  #BRCM_SWREQ_VTMON_INIT

    @limitations None
*/
extern void VTMON_Init(const VTMON_ConfigType *const aConfig);

/** @brief De-initialize VTMON driver

    This API de-initializes VTMON driver.

    @behavior Sync, Non-reentrant

    @pre TBD

    @param          void

    @return     void

    @post TBD

    @trace  #BRCM_SWREQ_VTMON_INIT

    @limitations None
*/
extern void VTMON_Deinit(void);

/** @brief Sets the high threshold temperature

    This API sets the high threshold value for temperature. When
    die-temperature crosses this threshold, client is notified using
    #VTMON_TempNotificationCb callback.

    @behavior Sync, Non-reentrant

    @pre TBD

    @param[in]      aTempHigh   Temperature high threshold value (in Celsius)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   Tempature not in range i.e either
                                        - aTempHigh  < -88 Celsius or
                                        - aTempHigh  > 413 Celsius

    @post TBD

    @trace  #BRCM_SWREQ_VTMON_INIT

    @limitations None
*/
extern int32_t VTMON_SetTemperatureMonitor(const VTMON_TempConfigType *aTempConfig);

/** @brief Get the current die-temperature

    This API is used to get the current die-temperature in Celsius.

    @behavior Sync, Re-entrant

    @pre VTMON_Init() must be called before using this API

    @param[out]     aTempConfig Pointer to get current temperature configuration
    @param[out]     aTemp       Pointer to current temperature value

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aTemp is NULL or aTempConfig is NULL
    @retval     #BCM_ERR_INVAL_STATE    API called in #VTMON_STATE_UNINIT state
    @retval     #BCM_ERR_BUSY           If power up delay is not over

    @post TBD

    @note   After initialization of the vtmon hardware, it might take few milliseconds
            before first valid sample is available (Refer to the chip TRM for details about
            the vtmon sampling time). If this API is called before the valid sample is
            available, it will return temprature value as 0.
            It user resposibility to call this API again until
            the valid sample is available or call this API after VTMON sampling time

    @trace  #BRCM_SWREQ_VTMON_TEMP_VOLTAGE

    @limitations None
*/
extern int32_t VTMON_GetTemperature(VTMON_TempConfigType *aTempConfig, VTMON_TempType *const aTemp);

/** @brief Set the high threshold voltage

    This API sets the high threshold value for voltage. When voltage crosses
    this threshold, client is notified using #VTMON_VoltNotificationCb callback.

    @behavior Sync, Non-reentrant

    @pre TBD

    @param[in]      aVoltConfig Voltage configuration

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aVoltID is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid parameters:
                                        - aVoltID is #VTMON_VOLT_ID_3V3 and
                                          aVoltHigh > 4398 mV
                                        - aVoltID si #VTMON_VOLT_ID_1V8 and
                                          aVoltHigh > 2199 mV
                                        - aVoltID is #VTMON_VOLT_ID_1V0 and
                                          aVoltHigh > 2512 mV

    @post TBD

    @trace  #BRCM_SWREQ_VTMON_INIT

    @limitations None
*/
extern int32_t VTMON_SetVoltageMonitor(const VTMON_VoltConfigType *aVoltConfig);

/** @brief Get the current voltage

    This API is used to get the current voltage.

    @behavior Sync, Re-entrant

    @pre VTMON_Init() must be called before using this API

    @param[inout]   aVoltConfig Voltage ID should be filled by caller
                                Other parameters are populated by driver upon return
    @param[out]     aVolt       Pointer to current voltage value

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aVoltID is invalid
    @retval     #BCM_ERR_INVAL_STATE    API called in #VTMON_STATE_UNINIT state
    @retval     #BCM_ERR_BUSY           If power up delay is not over
    @retval     #BCM_ERR_INVAL_PARAMS   aVolt is NULL

    @post TBD

    @note   After initialization of the vtmon hardware, it might take few milliseconds
            before first valid sample is available (Refer to the chip TRM for details about
            the vtmon sampling time). If this API is called before the valid sample is
            available, it will return voltage value as 0.
            It user resposibility to call this API again until
            the valid sample is available or call this API after VTMON sampling time

    @trace  #BRCM_SWREQ_VTMON_TEMP_VOLTAGE

    @limitations None
*/
extern int32_t VTMON_GetVoltage(VTMON_VoltConfigType *aVoltConfig,
                                 VTMON_VoltType *const aVolt);

/** @brief Enable the voltage & temperature interrupt notifications

    API to enable voltage and temperature threshold notifications.
    After the initialization of VTMON, it may take few milli-seconds
    before a valid sample is available. User shall enable the notification
    after the VTMON sample time (refer to TRM for details about sampling
    time for VTMON).
    If this API is called earlier to sampling time, it returns BCM_ERR_BUSY.

    @behavior Sync, Re-entrant

    @pre VTMON_Init() must be called before using this API

    @param      void

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_BUSY           If power up delay is not over
    @retval     #BCM_ERR_INVAL_STATE    If VTMON is powered down
    @retval     #BCM_ERR_INVAL_STATE    If notication already enabled

    @post None

    @note None

    @trace  #BRCM_SWREQ_VTMON_INIT

    @limitations None
*/
extern int32_t VTMON_EnableNotification(void);

/** @brief Disable the voltage & temperature interrupt notifications

    API to disable voltage and temperature threshold notifications.

    @behavior Sync, Re-entrant

    @pre None

    @param      void

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success

    @post None

    @note None

    @trace  #BRCM_SWREQ_VTMON_INIT

    @limitations None
*/
extern int32_t VTMON_DisableNotification(void);

#endif  /* VTMON_H */
/** @} */
