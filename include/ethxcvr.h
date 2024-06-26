/*****************************************************************************
 Copyright 2016-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_xcvrdrv_ifc Transceiver Interface
    @ingroup grp_xcvrdrv

    @addtogroup grp_xcvrdrv_ifc
    @{

    @file ethxcvr.h
    @brief Ethernet Transceiver interface
    This header file contains the interface functions for Ethernet Transceiver

    @version 1.26 Imported from docx
*/

#ifndef ETHXCVR_H
#define ETHXCVR_H

#include <stddef.h>
#include <inttypes.h>
#include <bcm_err.h>
#include <xcvr_common.h>
#include <xcvr_extphy.h>
#include <ethernet_common.h>

/**
    @name Ethernet Transceiver API IDs
    @{
    @brief API IDs for Ethernet Transceiver
*/
#define BRCM_SWARCH_ETHXCVR_INIT_PROC                  (0x8516U)    /**< @brief #ETHXCVR_Init              */
#define BRCM_SWARCH_ETHXCVR_DEINIT_PROC                (0x8517U)    /**< @brief #ETHXCVR_DeInit            */
#define BRCM_SWARCH_ETHXCVR_SETMODE_PROC               (0x8518U)    /**< @brief #ETHXCVR_SetMode           */
#define BRCM_SWARCH_ETHXCVR_GETMODE_PROC               (0x8519U)    /**< @brief #ETHXCVR_GetMode           */
#define BRCM_SWARCH_ETHXCVR_SETMASTERMODE_PROC         (0x851AU)    /**< @brief #ETHXCVR_SetMasterMode     */
#define BRCM_SWARCH_ETHXCVR_GETMASTERMODE_PROC         (0x851BU)    /**< @brief #ETHXCVR_GetMasterMode     */
#define BRCM_SWARCH_ETHXCVR_GETLINKSTATE_PROC          (0x851CU)    /**< @brief #ETHXCVR_GetLinkState      */
#define BRCM_SWARCH_ETHXCVR_GETSPEED_PROC              (0x851DU)    /**< @brief #ETHXCVR_GetSpeed          */
#define BRCM_SWARCH_ETHXCVR_SETSPEED_PROC              (0x851EU)    /**< @brief #ETHXCVR_SetSpeed          */
#define BRCM_SWARCH_ETHXCVR_GETDUPLEXMODE_PROC         (0x851FU)    /**< @brief #ETHXCVR_GetDuplexMode     */
#define BRCM_SWARCH_ETHXCVR_SETDUPLEXMODE_PROC         (0x8520U)    /**< @brief #ETHXCVR_SetDuplexMode     */
#define BRCM_SWARCH_ETHXCVR_GETFLOWCONTROL_PROC        (0x8521U)    /**< @brief #ETHXCVR_GetFlowControl    */
#define BRCM_SWARCH_ETHXCVR_SETFLOWCONTROL_PROC        (0x8522U)    /**< @brief #ETHXCVR_SetFlowControl    */
#define BRCM_SWARCH_ETHXCVR_GETSQIVALUE_PROC           (0x8523U)    /**< @brief #ETHXCVR_GetSQIValue       */
#define BRCM_SWARCH_ETHXCVR_SETLOOPBACKMODE_PROC       (0x8524U)    /**< @brief #ETHXCVR_SetLoopbackMode   */
#define BRCM_SWARCH_ETHXCVR_GETLOOPBACKMODE_PROC       (0x8525U)    /**< @brief #ETHXCVR_GetLoopbackMode   */
#define BRCM_SWARCH_ETHXCVR_SETJUMBOMODE_PROC          (0x8526U)    /**< @brief #ETHXCVR_SetJumboMode      */
#define BRCM_SWARCH_ETHXCVR_GETJUMBOMODE_PROC          (0x8527U)    /**< @brief #ETHXCVR_GetJumboMode      */
#define BRCM_SWARCH_ETHXCVR_SETAUTONEGMODE_PROC        (0x8528U)    /**< @brief #ETHXCVR_SetAutoNegMode    */
#define BRCM_SWARCH_ETHXCVR_GETAUTONEGSTATUS_PROC      (0x8529U)    /**< @brief #ETHXCVR_GetAutoNegStatus  */
#define BRCM_SWARCH_ETHXCVR_RESTARTAUTONEG_PROC        (0x852AU)    /**< @brief #ETHXCVR_RestartAutoNeg    */
#define BRCM_SWARCH_ETHXCVR_GETSTATS_PROC              (0x852BU)    /**< @brief #ETHXCVR_GetStats          */
#define BRCM_SWARCH_ETHXCVR_STATEHANDLER_PROC          (0x852CU)    /**< @brief #ETHXCVR_StateHandler      */
#define BRCM_SWARCH_ETHXCVR_UPDATEHWSTATUS_PROC        (0x852DU)    /**< @brief #ETHXCVR_UpdateHWStatus    */
#define BRCM_SWARCH_ETHXCVR_GETPORTCONFIG_PROC         (0x852FU)    /**< @brief #ETHXCVR_GetPortConfig     */
#define BRCM_SWARCH_ETHXCVR_GETWAKEUPMODE_PROC         (0x8531U)    /**< @brief #ETHXCVR_GetWakeUpMode     */
#define BRCM_SWARCH_ETHXCVR_GETWAKEUPREASON_PROC       (0x8532U)    /**< @brief #ETHXCVR_GetWakeUpReason   */
#define BRCM_SWARCH_ETHXCVR_IRQHANDLER_PROC            (0x8533U)    /**< @brief #ETHXCVR_IRQHandler        */
#define BRCM_SWARCH_ETHXCVR_LINKCHGINDHANDLER_PROC     (0x8534U)    /**< @brief #ETHXCVR_LinkChgIndHandler */
#define BRCM_SWARCH_ETHXCVR_GETSTATUS_PROC             (0x8536U)    /**< @brief #ETHXCVR_GetStatus         */
#define BRCM_SWARCH_ETHXCVR_GETPHYID_PROC              (0x8537U)    /**< @brief #ETHXCVR_GetPhyID          */
#define BRCM_SWARCH_ETHXCVR_REGREAD_PROC               (0x8538U)    /**< @brief #ETHXCVR_RegRead           */
#define BRCM_SWARCH_ETHXCVR_REGWRITE_PROC              (0x8539U)    /**< @brief #ETHXCVR_RegWrite          */
#define BRCM_SWARCH_ETHXCVR_RUN_CABLE_DIAG_PROC        (0x853AU)    /**< @brief #ETHXCVR_RunCableDiag      */
#define BRCM_SWARCH_ETHXCVR_GET_CABLE_DIAG_RESULT_PROC (0x853BU)    /**< @brief #ETHXCVR_GetCableDiagResult */
#define BRCM_SWARCH_ETHXCVR_NOTIFYLINKSTATUS_PROC      (0x853FU)    /**< @brief #ETHXCVR_NotifyLinkStatus   */
#define BRCM_SWARCH_ETHXCVR_GETHEALTHINFO_PROC         (0x8540U)    /**< @brief #ETHXCVR_GetHealthInfo      */
#define BRCM_SWARCH_ETHXCVR_GETBRPHYBASEADDRNTYPE_PROC (0x8541U)    /**< @brief #ETHXCVR_GetBrPhyBaseAddrNType */
/** @} */

/** @brief Initialize transceiver

    This API initializes the transceiver with the given configuration.

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID            Index of the Transceiver
    @param[in]      aConfig        Pointer to transceiver configuration

    @return     void

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_INIT
*/
extern void ETHXCVR_Init(ETHXCVR_IDType aID,
                         const ETHXCVR_PortConfigType *const aConfig);

/** @brief De-initialize transceiver

    This API de-initializes the transceiver driver.

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the Transceiver

    @return     void

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_INIT
*/
extern void ETHXCVR_DeInit(ETHXCVR_IDType aID);

/** @brief Set transceiver mode

    This API sets mode of the transceiver. If aMode is #ETHXCVR_MODE_DOWN, transceiver is disabled by driver
    (both RX/TX disabled). If aMode is #ETHXCVR_MODE_ACTIVE, transceiver is enabled by the driver (both RX/TX active)
    When #ETHXCVR_MODE_ACTIVE is used, it will decide whether to perform full power up (MII Ctrl Power bit) or perform
    local and remote wake up depending on whether the wakeup feature is disabled or not


    @behavior ASync, Non Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[in]      aMode       Mode to be set

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver mode set successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver mode
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_EAGAIN         Transceiver mode can not be set at this
                                        moment. Try again.
    @retval     #BCM_ERR_NOSUPPORT      No Support for the Transceiver mode

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetMode(ETHXCVR_IDType aID,
                               ETHXCVR_ModeType aMode);

/** @brief Get transceiver mode

    This API retrieves the current mode of the Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aMode       Pointer to Mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver mode retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetMode(ETHXCVR_IDType aID,
                               ETHXCVR_ModeType *const aMode);

/** @brief Set transceiver master/slave mode

    This API sets master/slave mode of the transceiver. If aMode is
    #ETHXCVR_MASTER_MODE_EN, transceiver is configured in master
    mode. If aMode is #ETHXCVR_MASTER_MODE_DIS, transceiver is
    configured by driver in slave mode.

    @note Transceiver master/slave mode might not be applicable to all
    type of transceiver. If the mode is not applicable, this
    API shall return #BCM_ERR_NOSUPPORT


    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[in]      aMasterMode Master/slave mode to be set

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Master/slave mode set successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid mode
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Setting master/slave mode is not supported
    @retval     #BCM_ERR_EAGAIN         Master mode can not be set at this
                                        moment. Try again.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetMasterMode(ETHXCVR_IDType aID,
                                     ETHXCVR_BooleanType aMasterMode);

/** @brief Get transceiver master/slave mode

    This API retrieves the current master/slave mode of the Ethernet transceiver.

    @note Transceiver master/slave mode might not be applicable to all
    types of transceivers. If the mode is not applicable, this
    API shall return #BCM_ERR_NOSUPPORT

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aMasterMode Pointer to retrieve master/slave mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Master/slave mode retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Master/slave mode is not supported

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetMasterMode(ETHXCVR_IDType aID,
                                     ETHXCVR_BooleanType *const aMasterMode);

/** @brief Get transceiver link state

    This API retrieves the state of the Ethernet transceiver link.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aLinkState  Pointer to link state

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved transceiver link state
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aLinkState is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetLinkState(ETHXCVR_IDType aID,
                                    ETHXCVR_LinkStateType *const aLinkState);

/** @brief Get transceiver speed

    This API retrieves the current speed of the Ethernet transceiver

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aSpeed      Speed of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved transceiver speed
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aSpeed is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetSpeed(ETHXCVR_IDType aID,
                                ETHXCVR_SpeedType *const aSpeed);

/** @brief Set transceiver speed

    This API set speed of the Ethernet transceiver

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[in]      aSpeed      Speed of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set transceiver speed
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aSpeed is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Setting speed is not supported
    @retval     #BCM_ERR_EAGAIN         Speed can not be changed at this
                                        moment. Try again.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetSpeed(ETHXCVR_IDType aID,
                                ETHXCVR_SpeedType aSpeed);

/** @brief Get duplex mode

    This API retrieves the current duplex mode of the Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aDuplexMode Duplex Mode of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved current duplex mode of the transceiver
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aDuplexMode is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetDuplexMode(ETHXCVR_IDType aID,
                                     ETHXCVR_DuplexModeType *const aDuplexMode);

/** @brief Set transceiver duplex mode

    This API set duplex mode of the Ethernet transceiver

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[in]      aDuplexMode Duplex mode of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set transceiver duplex mode
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aDuplexMode is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Setting duplex mode is not supported
    @retval     #BCM_ERR_EAGAIN         Duplex mode can not be set at this
                                        moment. Try again.

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetDuplexMode(ETHXCVR_IDType aID,
                                     ETHXCVR_DuplexModeType aDuplexMode);

/** @brief Get flow control

    This API retrieves the current flow control of the Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID          Index of the transceiver
    @param[out]     aFlowControl Flow control of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved current flow control of the transceiver
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aFlowControl is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetFlowControl(ETHXCVR_IDType aID,
                                     ETHXCVR_FlowControlType *const aFlowControl);

/** @brief Set transceiver flow control

    This API sets flow control of the Ethernet transceiver

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID          Index of the transceiver
    @param[in]      aFlowControl Flow control of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set transceiver flow control
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aFlowControl  is invalid
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Setting flow control is not supported
    @retval     #BCM_ERR_EAGAIN         Flow control mode can not be set at this
                                        moment. Try again.

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetFlowControl(ETHXCVR_IDType aID,
                                      ETHXCVR_FlowControlType aFlowControl);

/** @brief Get SQI mode

    This API retrieves the SQI value of the established link

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aSQIValue   SQI value of the link

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully returned the SQI value of the link.
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aSQIValue is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetSQIValue(ETHXCVR_IDType aID,
                                   uint32_t *const aSQIValue);

/** @brief Set transceiver loopback mode

    This API sets loopback mode of the transceiver.

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[in]      aMode       Loopback mode to be configured.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Loopback mode set successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid loopback mode
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Setting loopback mode is not supported
    @retval     #BCM_ERR_EAGAIN         Loopback mode can not be set at this
                                        moment. Try again.

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetLoopbackMode(ETHXCVR_IDType aID,
                                       ETHXCVR_BooleanType aMode);

/** @brief Get transceiver loopback mode

    This API retrieves the current loopback mode of the Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aMode       Pointer to retrieve loopback mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Loopback mode retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Loopback mode is not supported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetLoopbackMode(ETHXCVR_IDType aID,
                                       ETHXCVR_BooleanType *const aMode);

/** @brief Set transceiver jumbo mode

    This API sets jumbo mode of the transceiver.

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[in]      aMode       Jumbo mode to be configured.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Jumbo mode set successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid jumbo mode
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Setting jumbo mode is not supported
    @retval     #BCM_ERR_EAGAIN         Jumbo mode can not be set at this
                                        moment. Try again.

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetJumboMode(ETHXCVR_IDType aID,
                                    ETHXCVR_BooleanType aMode);

/** @brief Get transceiver jumbo mode

    This API retrieves the current jumbo packet mode enabled/disabled for
    the Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aJumboMode  Pointer to retrieve jumbo mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Jumbo mode retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aJumboMode is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Jumbo packet mode is not supported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetJumboMode(ETHXCVR_IDType aID,
                                    ETHXCVR_BooleanType *const aJumboMode);

/** @brief Get wake-up mode

    This API Queries the wake-up mode Setting Enabled /Disabled

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aMOde       Pointer to read WakeUp Mode Setting

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Get WakeUp Mode
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      No WakeUp Mode Support

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetWakeUpMode(ETHXCVR_IDType aID,
                                     ETHXCVR_BooleanType *const aMode);

/** @brief Get wakeup Reason

    This API reads and provide the wakeup Reason

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aReason     Pointer to read WakeUp Reason
    @param[in]      aIsClearOnRead FALSE: Retrieves the reason for last wake-up
                                   TRUE: Retrieves the reason for wake-up and clears it

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully Get WakeUp Reason
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      If there is No WakeUp Mode Support
    @retval     #BCM_ERR_INVAL_STATE    Wakeup Mode Disabled
    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetWakeUpReason (ETHXCVR_IDType aID,
                                        ETHXCVR_WakeupReasonType *const aReason,
                                        ETHXCVR_BooleanType aIsClearOnRead);

/** @brief Set auto-negotiation mode

    This API sets the auto-negotiation mode for the transceiver. In case
    aMode is #ETHXCVR_AUTONEGMODE_EN then it also performs auto-negotiation.

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[in]      aMode       Auto-negotiation enable/disable mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Auto-negotiation mode set successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid auto-negotiation mode
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Setting auto-negotiation mode is not supported
    @retval     #BCM_ERR_EAGAIN         Auto-negotiation mode can not be set
                                        at this moment. Try again.

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_SetAutoNegMode(ETHXCVR_IDType aID,
                                      ETHXCVR_BooleanType aMode);

/** @brief Get transceiver auto-negotiation status

    This API retrieves auto-negotiation status of the Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID             Index of the transceiver
    @param[out]     aStatus         Pointer to retrieve status of auto-negotiation

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver auto-negotiation status
                                        retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Auto-negotiation status is not supported

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetAutoNegStatus(ETHXCVR_IDType aID,
                                        ETHXCVR_AutoNegStatusType *const aStatus);

/** @brief Restart auto-negotiation

    This API restarts auto-negotiation for the transceiver

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Auto-negotiation restarted successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_STATE    Auto-negotiation is not enabled
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_NOSUPPORT      Restarting auto-negotiation is not supported

    @post None

    @limitations Set operation could result in hit in traffic on the device

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_RestartAutoNeg(ETHXCVR_IDType aID);

/** @brief Get transceiver statistics

    This API retrieves the statistics of Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aStats      Pointer to retrieve statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver statistics retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aStats is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetStats(ETHXCVR_IDType aID,
                                ETHXCVR_StatsType *const aStats);

/** @brief Transceiver state handler

    This API triggers the transceiver state machine

    @behavior Sync, Non re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver state machine triggered
                                        successfully and is in IDLE state
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_EAGAIN         Transceiver driver state handler is
                                        busy processing previous state. Call
                                        state handler again.
    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_StateHandler(ETHXCVR_IDType aID);

/** @brief Update HW status parameters

    This API triggers the driver to read and cache the HW status parameters

    @behavior Async, Non re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver driver triggered successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_EAGAIN         Transceiver driver can't be triggered at
                                        this moment. Try again.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_UpdateHWStatus(ETHXCVR_IDType aID);

/** @brief Get port config

    This API getches the port config

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver
    @param[out]     aConfig     Pointer to copy the port config

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Config retrived successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aConfig is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetPortConfig(ETHXCVR_IDType aID, ETHXCVR_PortConfigType *const aConfig);

/** @brief Ethernet Xcvr Link IRQ handler

    This API handles Ethernet xcvr link IRQ processing.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aID             Xcvr ID
    @param[out]     aParams         Irq parameters

    @return     void

    @post None

    @note To be used.

    @limitations None

    @snippet eth_osil.c Usage of ETHXCVR_IRQHandler

    @trace #BRCM_SWREQ_ETHXCVR_KERNEL_HANDLER
*/
extern void ETHXCVR_IRQHandler(ETHXCVR_IDType aID, ETHXCVR_IrqParamsType *const aParams);

/** @brief Ethernet Xcvr change indication handler

    This API handles Ethernet xcvr link change indication processing.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aID             Xcvr ID

    @return     void

    @post None

    @note To be used.

    @limitations None

    @snippet ethsrv_osil.c Usage of ETHXCVR_LinkChgIndHandler

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern void ETHXCVR_LinkChgIndHandler(ETHXCVR_IDType aID);

/** @brief Get transceiver status

    This API retrieves the status of Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID          Index of the transceiver
    @param[out]     aStatus      Pointer to retrieve status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver status retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_GetStatus(ETHXCVR_IDType aID,
                                 ETHXCVR_StatusType *const aStatus);

/** @brief Get transceiver status

    This API retrieves the status of Ethernet transceiver.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID          Index of the transceiver
    @param[out]     aHealthInfo  Pointer to retrieve status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Transceiver status retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
int32_t ETHXCVR_GetHealthInfo(ETHXCVR_IDType aID,
                              ETHXCVR_ExtPhyHealthInfoType* const aHealthInfo);

/** @brief Send the link status notification

    This API sends the Ethernet transceiver link status

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully notification has been sent
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
int32_t ETHXCVR_NotifyLinkStatus(ETHXCVR_IDType aID);

/** @brief Get transceiver identifier

    This API obtains the PHY identifier.

    @behavior Sync, Re-entrant across transceivers

    @pre None

    @param[in]      aID         Index of the Transceiver
    @param[out]     aPhyID      PHY identifier

    @retval     #BCM_ERR_OK             successful
    @retval     #BCM_ERR_INVAL_PARAMS   invalid transceiver id
    @retval     #BCM_ERR_INVAL_PARAMS   aPhyID is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern void ETHXCVR_GetPhyID(ETHXCVR_IDType aID, ETHXCVR_PhyIDType *const aPhyID);

/** @brief Reads a transceiver register

    This API reads the content of the register/memory of transceiver

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver.
    @param[in]      aAddr       Memory address to be read.
    @param[out]     aData       Pointer to the data.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Memory was read successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aData is NULL
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Error while reading the memory.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_STATUS
*/
extern int32_t ETHXCVR_RegRead(ETHXCVR_IDType aID, uint32_t aAddr, uint32_t *const aData);

/** @brief Writes to a transceiver register

    This API writes the content to register/memory of transceiver

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver.
    @param[in]      aAddr       Memory address to be read.
    @param[in]     aData       value to be written.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Memory was written successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_UNKNOWN        Error while writing the memory.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_RegWrite(ETHXCVR_IDType aID, uint32_t aAddr, uint32_t aData);

/** @brief Run cable diagnostics

    This API runs the cable diagnostics procedure on the PHY.
    After the completion, callback indication (#ETHXCVR_CableDiagResultInd)
    is raised by the driver. User shall call #ETHXCVR_GetCableDiagResult to
    obtain the result.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Cable diagnostic started successfully.
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_INVAL_STATE    Transceiver is not in active state.
    @retval     #BCM_ERR_BUSY          Cable diagnostic is running.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/
extern int32_t ETHXCVR_RunCableDiag(ETHXCVR_IDType aID);

/** @brief Get cable diagnostic result

    This API obtains the cable diagnostics result.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver.
    @param[out]     aResult     Pointer to result structure memory.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             success (aResult contains valid result).
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_UNINIT         Transceiver driver is not initialized
    @retval     #BCM_ERR_BUSY          Cable diagnostic is running.

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_RUNTIME_CONFIG
*/

extern int32_t ETHXCVR_GetCableDiagResult(ETHXCVR_IDType aID,
                                          ETHXCVR_CableDiagResultType *const aResult);

/** @brief Get the Base register address of BRPhy block for the given transceiver Id

    This API get the BrPhy block's base register address and the BR type

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aID         Index of the transceiver.
    @param[in]      aConfig     Pointer to port configuration
    @param[out]     aAddr       Base address of the Brphy phy block if not NULL.
    @param[out]     aIsBrphy1g  Boolean if phy is a BRPHY1G if not NULL.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Base Address & Type of the BR Phy retrived successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid transceiver ID
    @retval     #BCM_ERR_INVAL_PARAMS   aConfig is NULL
    @retval     #BCM_ERR_NOSUPPORT      BRPHY or BRPHY 1G is not supported in that port

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVR_KERNEL_HANDLER
*/
int32_t ETHXCVR_GetBrPhyBaseAddrNType(ETHXCVR_IDType aID, const ETHXCVR_PortConfigType *const aConfig, uint32_t *const aAddr, BCM_BoolType *const aIsBrphy1g);
#endif /* ETH_XCVR_H */

/** @} */
