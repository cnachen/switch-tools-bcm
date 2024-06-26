/*****************************************************************************
 Copyright 2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_xcvrm ETHXCVRM abstract Interface
    @ingroup grp_transceiver_abstract

    @addtogroup grp_xcvrm
    @{

    @file xcvr_tc10.h

    @brief Ethernet Service: ETHXCVRM Interface
    This file contains the interfaces for the Ethernet abstract for ETHXCVRM

    @version 1.0 Initial version
*/

#ifndef XCVR_TC10_H
#define XCVR_TC10_H

#include <xcvr_common.h>
/**
    @name ETHXCVRM API IDs
    @{
    @brief API IDs for ETHXCVRM
*/
#define BRCM_SWARCH_ETHXCVRM_CMDID_TYPE                  (0x8300U)    /**< @brief #ETHXCVRM_CmdIdType          */
#define BRCM_SWARCH_ETHXCVRM_TC10PORT_TYPE               (0x8301U)    /**< @brief #ETHXCVRM_TC10PortType       */
#define BRCM_SWARCH_ETHXCVRM_MAX_PAYLOAD_SIZE_MACRO      (0x8302U)    /**< @brief #ETHXCVRM_MAX_PAYLOAD_SIZE   */
#define BRCM_SWARCH_ETHXCVRM_ID_OF_MACRO                 (0x8303U)    /**< @brief #ETHXCVRM_ID_OF              */
#define BRCM_SWARCH_ETHXCVRM_TC10STATUS_TYPE             (0x8304U)    /**< @brief #ETHXCVRM_TC10StatusType     */
#define BRCM_SWARCH_ETHXCVRM_TC10FWDMAP_TYPE             (0x8305U)    /**< @brief #ETHXCVRM_TC10FwdMapType     */
#define BRCM_SWARCH_ETHXCVRM_TC10REQUESTSLEEP_PROC       (0x8306U)    /**< @brief #ETHXCVRM_Tc10RequestSleep   */
#define BRCM_SWARCH_ETHXCVRM_TC10REQUESTWAKEUP_PROC      (0x8307U)    /**< @brief #ETHXCVRM_Tc10RequestWakeUp  */
#define BRCM_SWARCH_ETHXCVRM_TC10FORWARDWAKEUP_PROC      (0x8308U)    /**< @brief #ETHXCVRM_Tc10ForwardWakeUp  */
#define BRCM_SWARCH_ETHXCVRM_TC10GETFORWARDMAP_PROC      (0x8309U)    /**< @brief #ETHXCVRM_Tc10GetForwardMap  */
#define BRCM_SWARCH_ETHXCVRM_TC10GETSTATUS_PROC          (0x830AU)    /**< @brief #ETHXCVRM_Tc10GetStatus      */
#define BRCM_SWARCH_ETHXCVRM_TC10REQUESTSLEEPALL_PROC    (0x830BU)    /**< @brief #ETHXCVRM_Tc10RequestSleepAll*/
#define BRCM_SWARCH_ETHXCVRM_TC10WAKEUPTYPE_TYPE         (0x830CU)    /**< @brief #ETHXCVRM_TC10WakeUpType     */
#define BRCM_SWARCH_ETHXCVRM_TC10REQUESTFORCESLEEP_PROC  (0x830DU)    /**< @brief #ETHXCVRM_Tc10RequestForceSleep */
#define BRCM_SWARCH_ETHXCVRM_TC10REQUESTSLEEPABORT_PROC  (0x830EU)    /**< @brief #ETHXCVRM_Tc10RequestSleepAbort */
#define BRCM_SWARCH_ETHXCVRM_TC10ALLOWSLEEPREQUEST_TYPE  (0x830FU)    /**< @brief #ETHXCVRM_TC10AllowSleepRequestType */
#define BRCM_SWARCH_ETHXCVRM_TC10ALLOWSLEEPREQUEST_PROC  (0x8310U)    /**< @brief #ETHXCVRM_Tc10AllowSleepRequest */
#define BRCM_SWARCH_ETHXCVRM_TC10COMMITOTPCFG_PROC       (0x8311U)    /**< @brief #ETHXCVRM_Tc10CommitOtpConfig */
#define BRCM_SWARCH_ETHXCVRM_TC10GETOTPCFG_PROC          (0x8312U)    /**< @brief #ETHXCVRM_Tc10GetOtpConfig   */
#define BRCM_SWARCH_ETHXCVRM_TC10ALLOW_MDI_WAKE_TYPE     (0x8313U)    /**< @brief #ETHXCVRM_TC10AllowMdiWakeType */
#define BRCM_SWARCH_ETHXCVRM_TC10_ALLOW_MDI_WAKE_PROC    (0x8314U)    /**< @brief #ETHXCVRM_Tc10AllowMdiWake */
/** @} */

/**
    @brief Macro to Construct Ethernet ETHXCVRM Commands

    @trace #BRCM_SWREQ_ETHXCVRM
*/
#define ETHXCVRM_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_XVR_ID, aId)

/**
    @name ETHXCVRM command IDs
    @{
    @brief ETHXCVRM command IDs group

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef uint8_t ETHXCVRM_CmdIdType;                                        /**< @brief ETHXCVRM command message Type   */
#define ETHXCVRM_CMDID_TC10_SLEEP_REQ      ETHXCVRM_ID_OF(0x00U)           /**< @brief #ETHXCVRM_TC10PortType          */
#define ETHXCVRM_CMDID_TC10_WAKEUP_REQ     ETHXCVRM_ID_OF(0x01U)           /**< @brief #ETHXCVRM_TC10PortType          */
#define ETHXCVRM_CMDID_TC10_WAKE_FWD       ETHXCVRM_ID_OF(0x02U)           /**< @brief #ETHXCVRM_TC10PortType          */
#define ETHXCVRM_CMDID_TC10_FWD_MAP_GET    ETHXCVRM_ID_OF(0x03U)           /**< @brief #ETHXCVRM_TC10FwdMapType        */
#define ETHXCVRM_CMDID_TC10_STATUS         ETHXCVRM_ID_OF(0x04U)           /**< @brief #ETHXCVRM_TC10StatusType        */
#define ETHXCVRM_CMDID_TC10_SLEEP_ALL_REQ  ETHXCVRM_ID_OF(0x05U)           /**< @brief #None                           */
#define ETHXCVRM_CMDID_TC10_SLEEP_ABORT_REQ ETHXCVRM_ID_OF(0x06U)          /**< @brief #ETHXCVRM_TC10PortType          */
#define ETHXCVRM_CMDID_TC10_FORCE_SLEEP_REQ ETHXCVRM_ID_OF(0x07U)          /**< @brief #ETHXCVRM_TC10PortType          */
#define ETHXCVRM_CMDID_TC10_ALLOW_SLEEP_REQ ETHXCVRM_ID_OF(0x08U)          /**< @brief #ETHXCVRM_TC10AllowSleepRequestType */
#define ETHXCVRM_CMDID_TC10_COMMIT_OTP_CFG ETHXCVRM_ID_OF(0x09U)           /**< @brief #None                      #? */
#define ETHXCVRM_CMDID_TC10_GET_OTP_CFG    ETHXCVRM_ID_OF(0x0AU)           /**< @brief #None                      #? */
#define ETHXCVRM_CMDID_TC10_ALLOW_MDI_WAKE ETHXCVRM_ID_OF(0x0BU)           /**< @brief #ETHXCVRM_TC10AllowMdiWakeType */
#define ETHXCVRM_CMDID_START               (ETHXCVRM_CMDID_TC10_SLEEP_REQ) /**< @brief ETHXCVRM Command start index    */
#define ETHXCVRM_CMDID_END                 (ETHXCVRM_CMDID_TC10_ALLOW_MDI_WAKE) /**< @brief ETHXCVRM Command end index */
/** @} */

/**
    @brief Maximum size of ETHXCVRM command payload in bytes

    @trace #BRCM_SWREQ_ETHXCVRM
*/
#define ETHXCVRM_MAX_PAYLOAD_SIZE   (416UL)

/**
    @brief Structure to manage ETHXCVRM TC10 Status

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef struct sETHXCVRM_TC10StatusType {
    uint32_t                id;             /**< @brief Port Number            */
    ETHXCVR_BooleanType     isTC10Enabled;  /**< @brief Boolean to indicate if tc10 is enabled on that port */
    ETHXCVR_StatusType      xcvrStatus;     /**< @brief Transceiver status     */
    ETHXCVR_StatsType       stats;            /**< @brief Statistics information */
} ETHXCVRM_TC10StatusType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_TC10StatusType, 52UL, ETHXCVRM_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage tc10 sleep wake (Defined here to suport backward compatability)

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef struct sETHXCVRM_TC10WakeUpType {
    ETHXCVR_IDType              port;           /**< @brief XCVR identifier    */
    ETHXCVR_WakeupReasonType    reason;         /**< @brief Wakeup Reason      */
    uint8_t                     mode;           /**< @brief Sleep Wake Control */
} ETHXCVRM_TC10WakeUpType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_TC10WakeUpType, 3UL, ETHXCVRM_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage ETHXCVRM TC10 forward Map

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef struct sETHXCVRM_TC10FwdMapType {
    uint64_t             pinFwdMap;                     /**< @brief Pin based Forward Map  */
    uint64_t             phyFwdMap[ETHXCVR_MAX_PORTS + 1UL];  /**< @brief Phy based Forward Map (including one for P7) */
} ETHXCVRM_TC10FwdMapType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_TC10FwdMapType, 144UL, ETHXCVRM_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage ETHXCVRM TC10 port based commands

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef struct sETHXCVRM_TC10PortType {
    uint32_t             id;             /**< @brief Port identifier         */
    uint32_t             reserved[4UL];  /**< @brief Reserved for future use */
} ETHXCVRM_TC10PortType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_TC10PortType, 20UL, ETHXCVRM_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to manage AllowSleepRequest command

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef struct sETHXCVRM_TC10AllowSleepRequestType {
    ETHXCVR_IDType              id;             /**< @brief XCVR identifier    */
    ETHXCVR_BooleanType         mode;           /**< @brief Boolean            */
} ETHXCVRM_TC10AllowSleepRequestType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_TC10AllowSleepRequestType, 2UL, ETHXCVRM_MAX_PAYLOAD_SIZE)

/**
    @brief Structure to for MDI Wake enable command

    @trace #BRCM_SWREQ_ETHXCVRM
*/
typedef struct sETHXCVRM_TC10AllowMdiWakeType {
    ETHXCVR_IDType              id;             /**< @brief XCVR identifier    */
    ETHXCVR_BooleanType         mode;           /**< @brief TRUE = Enable MDI wake,
                                                            FALSE = Disable MDI Wake */
} ETHXCVRM_TC10AllowMdiWakeType;
BCM_STATIC_SIZE_ASSERT(ETHXCVRM_TC10AllowMdiWakeType, 2UL, ETHXCVRM_MAX_PAYLOAD_SIZE)

/** @brief Request Port to Sleep

    This API requests a TC10 sleep and implicitly enables accepting further
    sleep requests from link partner

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index will be used as #ETHXCVR_IDType

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Sleep Request Sent Successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10RequestSleep(BCM_HandleType aConnHdl, uint32_t aPortID);

/** @brief Request forceful sleep on a port

    This API forces a TC10 sleep and implicitly enables accepting further
    sleep requests from link partner

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index will be used as #ETHXCVR_IDType

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Force Sleep request issued Successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10RequestForceSleep(BCM_HandleType aConnHdl, uint32_t aPortID);

/** @brief Request Sleep Abort

    This API requests to abort a Sleep request on a #aPortID

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index will be used as #ETHXCVR_IDType

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Sleep Abort Request Sent Successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10RequestSleepAbort(BCM_HandleType aConnHdl, uint32_t aPortID);

/** @brief Request all ports to go to sleep state

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)

    @return response from #RPC_SendRecv

    @post None

    @trace #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10RequestSleepAll(BCM_HandleType aConnHdl);

/** @brief Request Port to WakeUp

    This API sends the Wakeup request on a #aPortID

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index will be used as #ETHXCVR_IDType

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             WakeUp Request Sent Successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10RequestWakeUp(BCM_HandleType aConnHdl, uint32_t aPortID);

/** @brief Request Port to Forward WakeUp Request

    This API sends the WakeUp Forward request on a #aPortID

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aPortID     Port index will be used as #ETHXCVR_IDType

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             WakeUp Forward Request Sent Successfully
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl
    @retval     #BCM_ERR_NOT_FOUND      #aPortID is not found
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10ForwardWakeUp(BCM_HandleType aConnHdl, uint32_t aPortID);

/** @brief Get port TC10 Forward Map

    This API retrieves TC10 forward Map

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[out]     aTC10FwdMap     Pointer to retrieve TC10 Forward Map

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved Port Forward Map
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl or aTC10FwdMap is NULL
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10GetForwardMap(BCM_HandleType aConnHdl,
                                            ETHXCVRM_TC10FwdMapType *const aTC10FwdMap);

/** @brief Get TC10 status

    This API retrieves the TC10 status.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aPortID         Port index will be used as #ETHXCVR_IDType
    @param[out]     aTC10Status     Pointer to retrieve TC10 status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             TC10 status retrieved successfully
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aConnHdl) or
                                        (Invalid aPortID) or
                                        (aTC10Status is NULL)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVRM
*/
extern int32_t ETHXCVRM_Tc10GetStatus(BCM_HandleType aConnHdl, uint32_t aPortID,
                                           ETHXCVRM_TC10StatusType *const aTC10Status);

/** @brief Allow Sleep request

    This API enables/disables accepting sleep requests from remote.
    The default can be setup in the transceiver configuration.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aPortID      Index of the transceiver
    @param[in]     aMode        Boolean to indicate if sleep requests have to be allowed or not

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Completed successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVRM
*/
extern int32_t ETHXCVRM_Tc10AllowSleepRequest(BCM_HandleType aConnHdl,
                                              uint32_t aPortID,
                                              ETHXCVR_BooleanType aMode);

/** @brief Allow MDI Wake

    This API enables/disables accepting wake up request from link partner.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]     aConnHdl     Connection handle from RPC_Connect in the case of external PHYs
                                Hardware instance in case of integrated PHYs
    @param[in]     aPortID      Index of the transceiver
    @param[in]     aMode        Boolean to indicate if wake requests have to be allowed or not

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Completed successfully
    @retval     #BCM_ERR_INVAL_STATE   TC10 control not set to HOST mode through straps
                                       OR TC10 state machine is not in awaken state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETHXCVRM
*/
extern int32_t ETHXCVRM_Tc10AllowMdiWake(BCM_HandleType aConnHdl,
                                         uint32_t aPortID,
                                         ETHXCVR_BooleanType aMode);

/** @brief Commit TC10 config to OTP

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)

    @return response from #RPC_SendRecv

    @post None

    @trace #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10CommitOtpConfig(BCM_HandleType aConnHdl);

/** @brief Get TC10 config from OTP

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)

    @return response from #RPC_SendRecv

    @post None

    @trace #BRCM_SWREQ_ETHXCVRM

    @limitations None
*/
extern int32_t ETHXCVRM_Tc10GetOtpConfig(BCM_HandleType aConnHdl,
                                         ETHXCVR_TC10ConfigType * const aCfg);

#endif /* XCVR_TC10_H */
/** @} */
