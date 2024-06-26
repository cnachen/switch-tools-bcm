/*****************************************************************************
 Copyright 2016-2021 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ets_ifc Interface
    @ingroup grp_ets

    @addtogroup grp_ets_ifc
    @{

    @section sec_ets_fsm State Machine
    @image html etslib_state.png "State Machine"
    The state machine for ETS library is depicted above. It also depicts the
    APIs which cause the state transition and which APIs are allowed to be
    called in the different states. ETS has the following states:
    <ul>
        <li> ETS_STATE_RESET: This is the default state of ETS on power up.
           This is also the state once the module is de-initialized. In this
           state the protocol does not run and the module will not respond to
           any gPTP packets, nor will it transmit any gPTP packets. None of the
           APIs to fetch the module statistics, status or retrieval of time will
           work in this state
        </li>
        <li> ETS_STATE_RUNNING: This is the state of the module once the
           initialization command is received. The protocol is running and the
           module will both initiate transmission of packets as well as respond
           to received packets. In this state, the module can be queried for
           statistics, status and network time.
        </li>
    </ul>

    @section sec_ets_seq Sequence Diagrams
    @image html etslib_api_seq.png "Sequence Diagram"
    Above figure depicts a typical flow of application to interact with ETS

    @section sec_ets_assumptions Assumptions
    <ul>
        <li> The “.bss” section is initialized with zeroes </li>
        <li> Only AVnu Automotive mode of operation is supported. IEEE mode of
          operation is not supported </li>
        <li> Network interface provides hardware timestamps for ingress and
             egress gPTP event packets based on the Ethernet time </li>
    </ul>

    @section sec_comp_requirements Requirements
    <ul>
        <li> Ethernet/Switch driver is integrated into the system </li>
        <li> Ethernet/Switch driver should be initialized before ETS module is
             started </li>
        <li> 1588 initialization of the hardware should be performed before the
             ETS module is started </li>
    </ul>

    @section sec_comp_perf Performance & Memory

    | Performance       | Description                                       |
    |:-----------------:|:-------------------------------------------------:|
    | CPU Load          |   NA                                              |
    | Memory Bandwidth  |   NA                                              |
    | HW Utilization    |   NA                                              |

    @includedoc etslib_all.dep

    @limitations None

    @file ets.h
    @brief Application interface for ETS library
    This file provides the interface/APIs which can be used to initialize,
    de-initialize the ETS subsystem. It also contains APIs to query for
    parameters and statistics
    @version 1.25 Imported from MS Word document
*/

#ifndef ETS_H
#define ETS_H

#include <stdint.h>
#include "ets_config.h"
#include <ethernet_ets.h>
#include <xcvr_common.h>
#include <ethernet_time.h>

/**
    @name ETS Library API IDs
    @{
    @brief API IDs for ETS Library
 */
#define BRCM_SWARCH_ETS_MAXPDUSIZE_MACRO                 (0x8901U)    /**< @brief #ETS_MAX_PDU_SIZE             */
#define BRCM_SWARCH_ETS_STATE_TYPE                       (0x8902U)    /**< @brief #ETS_StateType                */
#define BRCM_SWARCH_ETS_INIT_PROC                        (0x8903U)    /**< @brief #ETS_Init                     */
#define BRCM_SWARCH_ETS_DEINIT_PROC                      (0x8904U)    /**< @brief #ETS_DeInit                   */
#define BRCM_SWARCH_ETS_GETSTATS_PROC                    (0x8905U)    /**< @brief #ETS_GetStats                 */
#define BRCM_SWARCH_ETS_GETCURRENTTIME_PROC              (0x8906U)    /**< @brief #ETS_GetCurrentTime           */
#define BRCM_SWARCH_ETS_SETGLOBALTIME_PROC               (0x8907U)    /**< @brief #ETS_SetGlobalTime            */
#define BRCM_SWARCH_ETS_GETGRANDMASTERRATERATIO_PROC     (0x8908U)    /**< @brief #ETS_GetGrandMasterRateRatio  */
#define BRCM_SWARCH_ETS_GETSTATE_PROC                    (0x8909U)    /**< @brief #ETS_GetState                 */
#define BRCM_SWARCH_ETS_RXPACKET_PROC                    (0x890AU)    /**< @brief #ETS_RxPacket                 */
#define BRCM_SWARCH_ETS_TXCONFIRMATION_PROC              (0x890BU)    /**< @brief #ETS_TxConfirmation           */
#define BRCM_SWARCH_ETS_PROCESSTIMER_PROC                (0x890CU)    /**< @brief #ETS_ProcessTimerEvent        */
#define BRCM_SWARCH_ETS_RESETSTATS_PROC                  (0x890DU)    /**< @brief #ETS_ResetStats               */
#define BRCM_SWARCH_ETS_GETGLOBALSTATUS_PROC             (0x890EU)    /**< @brief #ETS_GetGlobalStatus          */
#define BRCM_SWARCH_ETS_ISGPTPEVENTMSG_PROC              (0x8910U)    /**< @brief #ETS_IsGptpEventMsg           */
#define BRCM_SWARCH_ETS_ENABLERECORDNOTIFICATION_PROC    (0x8911U)    /**< @brief #ETS_EnableRecordNotification */
#define BRCM_SWARCH_ETS_SETPORTENABLE_PROC               (0x8914U)    /**< @brief #ETS_SetPortEnable            */
#define BRCM_SWARCH_ETS_SETDOMAINENABLE_PROC             (0x8915U)    /**< @brief #ETS_SetDomainEnable          */
#define BRCM_SWARCH_ETS_UPDATELINKSTATECHANGE_PROC       (0x8916U)    /**< @brief #ETS_UpdateLinkStateChange    */
#define BRCM_SWARCH_ETS_TIMESTAMPINFO_TYPE               (0x8917U)    /**< @brief #ETS_TimestampInfoType        */
#define BRCM_SWARCH_ETS_PUSHTSINFONWEVENTQUEUE_PROC      (0x8918U)    /**< @brief #ETS_PushTSInfoToNwEventQueue */
#define BRCM_SWARCH_ETS_FINDDOMAININDEX_PROC             (0x8919U)    /**< @brief #ETS_FindDomainIndex           */
/** @} */

/**
    @brief Maximum size of the 802.1AS PDU
    @trace #BRCM_SWREQ_ETS_TYPES
*/
#define ETS_MAX_PDU_SIZE  (136U)

/**
  @name ETS_StateType
  @{
  @brief ETS State
  @trace #BRCM_SWREQ_ETS_TYPES

*/
typedef uint32_t ETS_StateType;     /**< @brief typedef for ETS state */
#define ETS_STATE_RESET   (0UL) /**< @brief Module in reset state */
#define ETS_STATE_RUNNING (1UL) /**< @brief Module in running state */
/** @} */

/**
    @brief Structure containing the free running and domain timestamps
    @trace #BRCM_SWREQ_ETS_TYPES
*/
typedef struct sETS_TimestampInfoType {
    ETS_TimeType freeTs;        /**< @brief Free running timestamp */
    ETS_TimeType domainTs;      /**< @brief Domain timestamp       */
    uint32_t     freeTsValid;   /**< @brief Flag indicating if the
                                      domain timestamp is valid or
                                      not */
    uint32_t     domainTsValid; /**< @brief Flag indicating if the
                                      domain timestamp is valid or
                                      not */
} ETS_TimestampInfoType;

/** @brief Initialize ETS library

    @pre None

    This API initializes the ETS library and moves it to RUNNING state. The
    protocol operations are started and the library is ready to send and receive
    packets.

    @behavior Sync, Non-reentrant

    @param[in]  aConfig              Configuration parameters

    @retval  #BCM_ERR_OK             Module successfully initialized
    @retval  #BCM_ERR_INVAL_STATE    Global state is not RESET
    @retval  #BCM_ERR_INVAL_PARAMS   aConfig is NULL
    @retval  #BCM_ERR_INVAL_PARAMS   Number of interfaces configured in aConfig is 0
    @retval  #BCM_ERR_INVAL_PARAMS   Number of interfaces configured in aConfig is more
                                     than #ETS_MAX_INTERFACES
    @retval  #BCM_ERR_INVAL_MAGIC    aConfig has invalid magic
    @retval  #BCM_ERR_UNINIT         Unable to retrieve Ethernet MAC address

    @post ETS moves to RUNNING state

    @limitations The library does not perform any validation on the parameters
    in the configuration structure and it is assumed that they are valid and
    consistent.

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_Init(const ETS_ConfigV2Type* const aConfig);

/** @brief De-Initialize ETS library

    @pre ETS is in RUNNING state

    This API de-initializes the ETS library and moves it to RESET state. The
    protocol operations are stopped and the library neither sends packets nor
    responds to received packets.

    @behavior Sync, Non-reentrant

    @retval   #BCM_ERR_OK             Module successfully deinitialized
    @retval   #BCM_ERR_INVAL_STATE    Global state is not RUNNING

    @post ETS moves to RESET state

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_DeInit(void);

/** @brief Retrieve ETS statistics

    @pre ETS is in RUNNING state

    Used to retrieve interface statistics maintained by the ETS library. These
    statistics include both transmit/receive packet counters as well as error
    counters and are useful for debugging issues during operation.

    @behavior Sync, Non-reentrant

    @param[in]   aPortNum             Port number
    @param[in]   aDomain              Domain number
    @param[out]  aStats               Location to populate the statistics
                                      information

    @retval   #BCM_ERR_OK             Statistics successfully retrieved
    @retval   #BCM_ERR_INVAL_STATE    Global state is not RUNNING
    @retval   #BCM_ERR_INVAL_PARAMS   aStats is NULL
    @retval   #BCM_ERR_NOT_FOUND      aPortNum/aDomain is not found in configuration
    @retval   #BCM_ERR_INVAL_MAGIC    Magic number is invalid

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_GetStats(const uint32_t aPortNum,
                     const ETS_DomainType aDomain,
                     ETS_StatsV2Type *const aStats);

/** @brief Reset ETS statistics

    @pre ETS is in RUNNING state

    Used to reset the statistics for a particular interface

    @behavior Sync, Non-reentrant

    @param[in]   aPortNum             Port number
    @param[in]   aDomain              Domain number

    @retval   #BCM_ERR_OK             Statistics successfully reset
    @retval   #BCM_ERR_INVAL_STATE    Global state is not RUNNING
    @retval   #BCM_ERR_NOT_FOUND      aPortNum/aDomain is not found in configuration

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_ResetStats(const uint32_t aPortNum,
                       const ETS_DomainType aDomain);

/** @brief Process incoming 802.1AS PDU

    @pre ETS is in RUNNING state

    This API provides a gPTP PDU received at the network interface to the
    ETS module. Since only gPTP event messages are timestamped in
    the hardware, only they will have a valid timestamp. For other (general)
    messages it is safe to indicate that the timestamp is not valid.

    @behavior Sync, Non-reentrant

    @param[in]   aPortNum              Port number
    @param[in]   aPktData              Pointer to 802.1AS PDU buffer
    @param[in]   aDataLen              Length of 802.1AS PDU
    @param[in]   aDstMacAddr           Destination address in the received PDU
    @param[in]   aTSInfo               Timestamp information
    @param[in]   aVlanId               VLAN Id
    @param[in]   aPcp                  PCP value

    @retval  #BCM_ERR_OK               Packet successfully consumed
    @retval  #BCM_ERR_INVAL_STATE      Global state is not RUNNING
    @retval  #BCM_ERR_INVAL_PARAMS     (aPktData is NULL) or (aTSInfo is NULL)
    @retval  #BCM_ERR_INVAL_PARAMS     aDataLen indicates packet is too small
    @retval  #BCM_ERR_INVAL_PARAMS     Invalid destination MAC address
    @retval  #BCM_ERR_INVAL_PARAMS     Invalid message type
    @retval  #BCM_ERR_NOT_FOUND        aPortNum is invalid
    @retval  #BCM_ERR_NOSUPPORT        TransportSpecific field is not 1

    @post None

    @limitations This function needs to be invoked in the context of the ETS
    protocol task

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_RxPacket(const uint32_t                     aPortNum,
                     const uint8_t* const               aPktData,
                     const uint16_t                     aDataLen,
                     const uint8_t* const               aDstMacAddr,
                     const ETS_TimestampInfoType *const aTSInfo,
                     const uint16_t aVlanId,
                     const uint8_t aPcp);

/** @brief Process timer event

    @pre ETS is in RUNNING state

    This API is invoked periodically to provide the notion of elapsed time to
    ETS module. It needs to be invoked every 15.625 ms.

    @behavior Sync, Non-reentrant

    @retval void

    @post None

    @limitations This function needs to be invoked in the context of the ETS
    protocol task

    @trace #BRCM_SWREQ_ETS_COMMON
*/
void ETS_ProcessTimerEvent(void);

/** @brief Retrieve module state

    @pre None

    This API retrieves the state of ETS. This API should be invoked before
    invoking other APIs to make sure that the module is in the appropriate state

    @behavior Sync, Re-entrant

    @retval  #ETS_STATE_RESET       Module is in RESET state
    @retval  #ETS_STATE_RUNNING     Module is in RUNNING state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_TYPES
*/
ETS_StateType ETS_GetState(void);

/** @brief Handle transmission completion of a gPTP PDU

    @pre ETS is in RUNNING state

    This API provides a transmit confirmation for gPTP PDU transmitted at the
    network interface to the ETS module. Since only gPTP event messages are
    timestamped in the hardware, only they will have a valid timestamp. For
    other messages it is safe to indicate that the timestamp is not valid.

    @behavior Sync, Non-reentrant

    @param[in]   aPortNum              Port number
    @param[in]   aDomainNum            Domain number
    @param[in]   aPktType              802.1as packet identifier
    @param[in]   aTSInfo               Timestamp information

    @retval   #BCM_ERR_OK              Confirmation successfully consumed
    @retval   #BCM_ERR_INVAL_STATE     ETS is in RESET state
    @retval   #BCM_ERR_INVAL_PARAMS    (aTSInfo is NULL)
    @retval   #BCM_ERR_NOT_FOUND       aPortNum/aDomainNum is not found in configuration

    @post None

    @limitations This function needs to be invoked in the context of the ETS
    protocol task

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_TxConfirmation(const uint32_t                     aPortNum,
                           const ETS_DomainType               aDomainNum,
                           const ETS_MsgType                  aPktType,
                           const ETS_TimestampInfoType *const aTSInfo);

/** @brief Set global time

    @pre ETS is in RUNNING state

    This API sets the global time for a grandmaster. This time will be used as
    the base for distributing time in the network. This API can be used to
    synchronize time across multiple time domains. Global time can be moved back
    and forth as required and the ETS module will ensure that the new time
    is propagated in its domain.

    @behavior Sync, Re-entrant

    @param[in]   aDomainNum            Domain number
    @param[in]   aTime                 Time to be set

    @retval  #BCM_ERR_OK               Time set successfully
    @retval  #BCM_ERR_NOT_FOUND        aDomainNum is not found in configuration
    @retval  #BCM_ERR_INVAL_PARAMS     aTime is NULL
    @retval  #BCM_ERR_INVAL_STATE      ETS is in RESET state
    @retval  #BCM_ERR_NOSUPPORT        API invoked for an endpoint in
                                       slave role

    @post None

    @limitations Using this API (during operation of ETS) might
    lead to a jump in the timestamps and would introduce transient errors in the
    peer delay and neighbor rate ratio calculations. The ETS module
    may report errors when it discards these timestamps.

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_SetGlobalTime(const ETS_DomainType      aDomainNum,
                          const ETS_TimeType* const aTime);

/** @brief  Get current time

    @pre ETS is in RUNNING state

    This API retrieves the network time. The state indicates whether this time
    is synchronized to the grandmaster or not.

    @behavior Sync, Reentrant

    @param[in]    aDomainNum           Domain number
    @param[out]   aTime                Location to store time
    @param[out]   aState               Location to store time state

    @retval  #BCM_ERR_OK               Time retrieved successfully
    @retval  #BCM_ERR_NOT_FOUND        aDomainNum is not found in configuration
    @retval  #BCM_ERR_INVAL_PARAMS     (aTime is NULL) or (aState is NULL)
    @retval  #BCM_ERR_INVAL_STATE      ETS is in RESET state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_GetCurrentTime(const ETS_DomainType     aDomainNum,
                           ETS_TimeType* const      aTime,
                           ETS_TimeStateType* const aState);

/** @brief Retrieve cumulative/grandmaster rate ratio

    @pre ETS is in RUNNING state

    Invoked to retrieve the grandmaster rate ratio (expressed) as 2^30
    scale factor fixed point

    @behavior Sync, Re-entrant

    @param[in]   aDomainNum           Domain number
    @param[out]  aGmRateRatio         Location to store the rate ratio

    @retval  #BCM_ERR_OK              Rate ratio retrieved successfully
    @retval  #BCM_ERR_NOT_FOUND       aDomain is not found in configuration
    @retval  #BCM_ERR_INVAL_STATE     ETS is in RESET state
    @retval  #BCM_ERR_INVAL_PARAMS    aGmRateRatio is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_GetGrandMasterRateRatio (const ETS_DomainType aDomainNum,
                                     int32_t* const aGmRateRatio);

/** @brief Retrieve global status

    @pre ETS is in RUNNING state

    Invoked to retrieve the global status

    @behavior Sync, Re-entrant

    @param[out]  aStatus              Location to store the status

    @retval  #BCM_ERR_OK              Status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS    aStatus is NULL
    @retval  #BCM_ERR_INVAL_STATE     ETS is in RESET state
    @retval  #BCM_ERR_INVAL_MAGIC     Magic number is invalid

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_GetGlobalStatus (ETS_GlobalStatusType* const aStatus);

/** @brief Deduce message type

    @pre ETS is in RUNNING state

    Invoked to find if a gPTP PDU is an event or a general message

    @param[in]   aPortNum              Port number
    @param[in]   aPktData              Pointer to 802.1AS PDU buffer
    @param[in]   aDataLen              Length of 802.1AS PDU
    @param[out]  aResponse             Indicates whether the message is of type
                                       event

    @retval  #BCM_ERR_OK               Message type deduced successfully
    @retval  #BCM_ERR_INVAL_PARAMS     (aPktData is NULL) or (packet too short)
    @retval  #BCM_ERR_NOT_FOUND        aPortNum is invalid

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_NIF_CALLBACK
*/
int32_t ETS_IsGptpEventMsg(const uint32_t aPortNum,
                           const uint8_t* const aPktData,
                           const uint16_t aDataLen,
                           uint32_t* const aResponse);

/** @brief Set or clear ETS notification status

    @pre ETS is in RUNNING state

    This is indication by host to start/stop sending
    the ETS record/s to host. Once it is set
    by host, ETS starts sending ETS records to host
    until link is up or ETS receive stop indication from host.


    @param[in]   value                 set(1) or clear(0)

    @retval  #BCM_ERR_OK               Start/Stop sending records to host
                                       successfully
    @retval  #BCM_ERR_INVAL_PARAMS     value is not 'TRUE/FALSE'
    @retval  #BCM_ERR_INVAL_STATE      ETS is in RESET state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_EnableRecordNotification(uint32_t value);

/** @brief Enable/disable a port in a particular domain

    @pre ETS is in RUNNING state

    Invoked to enable/disable a port in a particular domain

    @behavior Sync, Re-entrant

    @param[in]   aPortNum             Port number
    @param[in]   aDomainNum           Domain number
    @param[in]   aPortEnable          TRUE: Enabled, FALSE: Disabled

    @retval  #BCM_ERR_OK              Port enabled/disabled successfully
    @retval  #BCM_ERR_NOT_FOUND       aDomainNum/aPortNum is not found
    @retval  #BCM_ERR_INVAL_STATE     ETS is in RESET state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_SetPortEnable (const uint32_t       aPortNum,
                           const ETS_DomainType aDomainNum,
                           const uint32_t       aPortEnable);

/** @brief Enable/disable a domain

    @pre ETS is in RUNNING state

    Invoked to enable/disable a particular domain

    @behavior Sync, Re-entrant

    @param[in]   aDomainNum           Domain number
    @param[in]   aDomainEnable        TRUE: Enabled, FALSE: Disabled

    @retval  #BCM_ERR_OK              Domain enabled/disabled successfully
    @retval  #BCM_ERR_NOT_FOUND       aDomainNum is not found
    @retval  #BCM_ERR_INVAL_STATE     ETS is in RESET state

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_SetDomainEnable(const ETS_DomainType aDomainNum,
                            const uint32_t       aDomainEnable);

/** @brief Update link status

    @pre None

    Used to update the link status mask upon link state changes

    @behavior Sync, Re-entrant

    @param[in]   aLinkUpMask             link up Mask
    @param[in]   aLinkDownMask           Link Down mask

    @retval  #BCM_ERR_OK              On success
    @retval  #BCM_ERR_INVAL_PARAMS    aLinkUpMask/aLinkDownMask is NULL

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_UpdateLinkStateChange(const ETHXCVR_LinkStatusMaskType *aLinkUpMask,
                                  const ETHXCVR_LinkStatusMaskType *aLinkDownMask);

/** @brief Update link status

    @pre None

    Used to Push the TimeStamp Info in Nw Event Queue

    @behavior Sync, Re-entrant

    @param[in]   aNotifyData          TS Info to push to NW Event Queue

    @retval  #BCM_ERR_OK              On success
    @retval  #BCM_ERR_INVAL_PARAMS    aNotifyData is NULL
    @retval  #BCM_ERR_NOT_FOUND       if [pktType,domainNum,seqId, intfIndx] not
                                      found for this packet  in Tx wait Queue

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS_COMMON
*/
int32_t ETS_PushTSInfoToNwEventQueue(const ETTM_NotifyTSType * const aNotifyData);

/** @brief Find the index for an input domain

    This routine returns the index (in the configuration) for an input domain number

    @behavior Sync, Reentrant

    @pre None

    @param[in]   aDomain              Domain number
    @param[out]  aDomainIdx           Domain index

    @retval  #BCM_ERR_OK              Index found for input aDomain
    @retval  #BCM_ERR_INVAL_PARAMS    aDomain is invalid
    @retval  #BCM_ERR_NOT_FOUND       aDomain is not found in configuration

    @post None

    @limitations None
    @trace #BRCM_SWREQ_ETS

*/
int32_t ETS_FindDomainIndex(const ETS_DomainType aDomain, uint32_t *const aDomainIdx);
#endif /* ETS_H */
/** @} */
