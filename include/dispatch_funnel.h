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
    @defgroup grp_rpc_v2_tunnel_ifc Dispatch Tunnel Interface
    @ingroup grp_rpc_v2_mod

    @addtogroup grp_rpc_v2_tunnel_ifc
    @{

    @file dispatch_funnel.h
    @brief DISPATCH Tunnel Intferface
    This header file contains the interface for DISPATCH tunnel

    @version 1.0 Initial Version
*/

#ifndef DISPATCH_TUNNEL_H
#define DISPATCH_TUNNEL_H

#include <stdint.h>
#include <dispatch_socket.h>
#include <dispatch_osil.h>
#include <rpc_dispatch.h>
#include <lw_queue.h>

/**
    @name DISPATCH Tunnel Interface IDs
    @{
    @brief Interface IDs for DISPATCH Tunnel Interface

*/
#define BRCM_SWARCH_DISPATCH_FUNNELINSTANCE_TYPE         (0x8402U)    /**< @brief #DISPATCH_FunnelInstanceType    */
#define BRCM_SWARCH_DISPATCH_FUNNELCONTEXT_TYPE          (0x8403U)    /**< @brief #DISPATCH_FunnelContextType     */
#define BRCM_SWARCH_DISPATCH_MODCREATEFUNNEL_PROC        (0x8404U)    /**< @brief #DISPATCH_ModCreateFunnel       */
#define BRCM_SWARCH_DISPATCH_MODDELETEFUNNEL_PROC        (0x8405U)    /**< @brief #DISPATCH_ModDeleteFunnel       */
#define BRCM_SWARCH_DISPATCH_MODADDFILTER_PROC           (0x8406U)    /**< @brief #DISPATCH_ModAddFilter          */
#define BRCM_SWARCH_DISPATCH_MODREMOVEFILTER_PROC        (0x8407U)    /**< @brief #DISPATCH_ModRemoveFilter       */
#define BRCM_SWARCH_DISPATCH_PROCESSEVENT_PROC           (0x8408U)    /**< @brief #DISPATCH_ProcessEvent          */
#define BRCM_SWARCH_DISPATCH_MOD_BIT_MAX_CNT_MACRO       (0x8409U)    /**< @brief #DISPATCH_MOD_BIT_MAX_CNT       */
#define BRCM_SWARCH_DISPATCH_GETFUNNELMSGFROMSLAVE_PROC  (0x840AU)    /**< @brief #DISPATCH_GetFunnelMsgFromSlave */
#define BRCM_SWARCH_DISPATCH_MODSENDNOTIFICATION_PROC    (0x840BU)    /**< @brief #DISPATCH_ModSendNotification   */
#define BRCM_SWARCH_DISPATCH_CHECKIFASYNCPRESENT_PROC    (0x840CU)    /**< @brief #DISPATCH_CheckIfAsyncPresent   */
/** @} */

/**
    @brief DISPATCH Max Memory in No Of Bits

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
#define DISPATCH_MOD_BIT_MAX_CNT        (32UL)

/**
    @brief DISPATCH funnel instance structure

    Used to store context for a network/local funnel

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
typedef struct sDISPATCH_FunnelInstanceType {
    DISPATCH_HandleType             handle;     /**< @brief Handle of allocated funnel */
    DISPATCH_SockContextType        sockCtxt;   /**< @brief Socket context             */
    DISPATCH_FunnelType             funnel;     /**< @brief Funnel information passed
                                                     by controller                     */
    DISPATCH_FilterType             filter[DISPATCH_MAX_FILTER_PER_FUNNEL]; /**< @brief
                                                     Array of filters added for
                                                     the funnel                        */
    uint32_t                        numFilters; /**< @brief Count of active filters    */
    LWQ_BufferType                  notifQ;     /**< @brief Q of Notifications to be
                                                     sent on the funnel                */
} DISPATCH_FunnelInstanceType;

/**
    @brief DISPATCH funnel context structure

    Context of dispatch funnel layer

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
typedef struct sDISPATCH_FunnelContextType {
    uint64_t                        keyCntr;             /**< @brief Variable for adding unique key
                                                             into funnel handle                     */
    uint32_t                        funnelUsageMask;     /**< @brief Network/cmd-resp funnel usage mask */
    DISPATCH_FunnelInstanceType     funnelList[DISPATCH_NET_FUNNEL_COUNT]; /**< @brief Network/cmd-resp
                                                                                funnel list         */
    uint32_t                        localFunnelUsageMask;/**< @brief Local funnel usage mask        */
    DISPATCH_FunnelInstanceType     localFunnel[DISPATCH_LOCAL_FUNNEL_COUNT]; /**< @brief Local
                                                             funnel list                            */
} DISPATCH_FunnelContextType;

/** @brief Internal function to create a funnel

    This API allocates a free funnel and initializes socket using the information
    passed by the controller. In case of funnel for cmd-response path, socket
    operations are not done. Instead they are passed to the dispatch module
    which transmits them over respective interface.

    @pre None

    @param[in]      aCtxt           Pointer to funnel context
    @param[inout]   aFunnel         Socket information for funnel to be created
    @param[in]      aFunnType       Type of funnel to be created (updated only for
                                    notifications on cmd-resp path)
    @param[in]      aRxIfcIdx       Interface on which this request was got
    @param[in]      aRxConnIdx      Connection index of interface on which request was got
    @param[in]      aTxIfcIdx       Interface on which notfn needs to be sent
    @param[in]      aTxConnIdx      Connection index on which notfn needs to be sent

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Funnel created successfully
    @retval     #BCM_ERR_NOMEM          Maximum number of supported funnels already created
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid values in #aFunnel

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
int32_t DISPATCH_ModCreateFunnel(DISPATCH_FunnelContextType *aCtxt,
                                 DISPATCH_FunnelType *aFunnel,
                                 uint64_t aFunnType,
                                 uint32_t aRxIfcIdx, uint32_t aRxIfcConnIdx,
                                 uint32_t aTxIfcIdx, uint32_t aTxIfcConnIdx);

/** @brief Internal function to delete a funnel

    This API frees the funnel indicated by the handle.

    @pre None

    @param[in]      aCtxt           Pointer to funnel context
    @param[in]      aFunnel         Socket information for funnel to be created

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Funnel deleted successfully
    @retval     #BCM_ERR_INVAL_PARAMS   #aFunnelHdl is invalid

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
int32_t DISPATCH_ModDeleteFunnel(DISPATCH_FunnelContextType *aCtxt,
                                 DISPATCH_FunnelType *aFunnel);

/** @brief Internal function to add a filter

    This API adds a filter to the existing funnel.

    @pre None

    @param[in]      aCtxt           Pointer to funnel context
    @param[in]      aFilter         Filter to be added to the funnel
    @param[inout]   aCmdSubState    Command processing sub state used when
                                    filters are being managed at host
    @param[inout]   aHdr            Command handle issued for local command

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Filter added successfully
    @retval     #BCM_ERR_NOMEM          Maximum number of filters already present in funnel
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid value in #aFilter

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
int32_t DISPATCH_ModAddFilter(DISPATCH_FunnelContextType *aCtxt,
                              DISPATCH_FilterType *aFilter,
                              BCM_SubStateType *const aCmdSubState,
                              const MSGQ_MsgHdrType** const aHdr);

/** @brief Internal function to delete a filter

    This API deletes a filter from the existing funnel.

    @pre None

    @param[in]      aCtxt           Pointer to funnel context
    @param[in]      aFilter         Filter to be added to the funnel
    @param[in]      aCmdSubState    Command processing sub state used when
                                    filters are being managed at host
    @param[inout]   aHdr            Command handle issued for local command

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Filter added successfully
    @retval     #BCM_ERR_NOT_FOUND      Filter not found
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid value in #aFilter

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
int32_t DISPATCH_ModRemoveFilter(DISPATCH_FunnelContextType *aCtxt,
                                 DISPATCH_FilterType *aFilter,
                                 BCM_SubStateType *const aCmdSubState,
                                 const MSGQ_MsgHdrType** const aHdr);

/** @brief Event handler function

    This function checks for any notification message that needs to be
    transmitted on a funnel.

    @pre None

    @param[in]      aCtxt           Pointer to funnel context
    @param[inout]   aAsyncBitMask   Pointer to notification list bit mask
    @param[inout]   aNotfnList      Pointer to notification list

    @retval None

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
void DISPATCH_ProcessEvent(DISPATCH_FunnelContextType *aCtxt,
                           uint32_t *aAsyncBitMask,
                           DISPATCH_AsyncMsgType *aNotfnList);

/** @brief Event handler function

    This function checks for any notification message that needs to be
    transmitted on a funnel.

    @pre None

    @param[in]      aInstCtxt       Pointer to funnel instance
    @param[in]      aCmd            Notification message ID

    @retval         1UL             If notification message is valid on the funnel
    @retval         0UL             If notification message is NOT valid on the funnel

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
uint32_t DISPATCH_CheckIfAsyncPresent(DISPATCH_FunnelInstanceType *aInstCtxt,
                                      BCM_MsgType aCmd);

/** @brief Function to read notifications from TCP server

    This function checks for any notification message that is sent by the
    stacking slave to the TCP server that is running on the stacking master.

    @pre None

    @param[in]      aCtxt            Pointer to funnel context
    @param[out]     aMsg             Pointer to mss buffer where data
                                     is to be read

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK          Data read successfully
    @retval     #BCM_ERR_NOMEM       No data present

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
int32_t DISPATCH_GetFunnelMsgFromSlave(DISPATCH_FunnelContextType *aCtxt,
                                       RPC_MsgType *aMsg);

/** @brief Function to send notification

    This function sends the notification message on the specified
    interface and connection index

    @pre None

    @param[in]      aIfcIdx       Interface index
    @param[in]      aConnIdx      Connection index of the interface
    @param[in]      aNotifMsg     Notification message to be sent

    Return values are documented in reverse-chronological order
    @retval void

    @post None

    @trace #BRCM_SWREQ_DISPATCH_MODULE_V2
*/
void DISPATCH_ModSendNotification(uint32_t aIfcIdx,
                                  uint32_t aConnIdx,
                                  RPC_MsgType *aNotifMsg);

#endif /* DISPATCH_TUNNEL_H */
/** @} */
