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

 2. TO THE COMP_MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
    TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND ALL IMPLIED
    WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A
    PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS,
    QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION.
    YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR PERFORMANCE OF THE
    SOFTWARE.

 3. TO THE COMP_MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR ITS
    LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL, INDIRECT,
    OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY WAY RELATING TO
    YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS
    OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1, WHICHEVER
    IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING ANY FAILURE OF
    ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
******************************************************************************/

/**
    @defgroup grp_rpc_notification_ifc DISPATCH notification Interface
    @ingroup grp_rpc_abstract

    @addtogroup grp_rpc_notification_ifc
    @{

    @file rpc_dispatch.h
    @brief DISPATCH notification interface
    and its registration

    @version 0.1 Initial Version
*/

#ifndef RPC_DISPATCH_H
#define RPC_DISPATCH_H

#include <stdint.h>
#include <bcm_err.h>
#include <bcm_comp.h>
#include <bcm_utils.h>

/**
    @name DISPATCH notification Architecture IDs
    @{
    @brief Architecture IDs for DISPATCH notification
*/
#define BRCM_SWARCH_DISPATCH_ID_MACRO                       (0x8D01U)    /**< @brief #DISPATCH_ID                     */
#define BRCM_SWARCH_DISPATCH_ID_TYPE                        (0x8D02U)    /**< @brief #DISPATCH_IDType                 */
#define BRCM_SWARCH_DISPATCH_FILTER_REG_TYPE                (0x8D03U)    /**< @brief #DISPATCH_FilterRegType          */
#define BRCM_SWARCH_DISPATCH_FUNNEL_TYPE                    (0x8D04U)    /**< @brief #DISPATCH_FunnelType             */
#define BRCM_SWARCH_DISPATCH_FILTER_TYPE                    (0x8D05U)    /**< @brief #DISPATCH_FilterType             */
#define BRCM_SWARCH_DISPATCH_CREATEFUNNEL_PROC              (0x8D06U)    /**< @brief #DISPATCH_CreateFunnel           */
#define BRCM_SWARCH_DISPATCH_ADDFILTER_PROC                 (0x8D07U)    /**< @brief #DISPATCH_AddFilter              */
#define BRCM_SWARCH_DISPATCH_REMOVEFILTER_PROC              (0x8D08U)    /**< @brief #DISPATCH_RemoveFilter           */
#define BRCM_SWARCH_DISPATCH_DESTROYFUNNEL_PROC             (0x8D09U)    /**< @brief #DISPATCH_DestroyFunnel          */
#define BRCM_SWARCH_DISPATCH_MSGUNION_TYPE                  (0x8D0AU)    /**< @brief #DISPATCH_MsgUnionType           */
#define BRCM_SWARCH_DISPATCH_SOCKET_NAME_STRING_SIZE_MACRO  (0x8D0BU)    /**< @brief #DISPATCH_SOCKET_NAME_STRING_SIZE*/
#define BRCM_SWARCH_DISPATCH_HDL_TYPE                       (0x8D0CU)    /**< @brief #DISPATCH_HandleType             */
/** @} */

/**
    @brief Macro to construct notification registration commands

    @trace #BRCM_SWREQ_DISPATCH
*/
#define DISPATCH_ID(aId)                    \
    BCM_MSG(BCM_GROUPID_RPC, BCM_RPC_ID, aId)

/**
    @brief Macro to construct notification registration commands

    @trace #BRCM_SWREQ_DISPATCH
*/
#define DISPATCH_SOCKET_NAME_STRING_SIZE    (128UL)

/**
    @brief Dispatch handle type
    @{

    @trace #BRCM_SWREQ_DISPATCH
*/
typedef BCM_HandleType DISPATCH_HandleType;
#define DISPATCH_HDL_IDX_MASK              (0xFFULL)              /**< @brief Mask for Index in the pool  */
#define DISPATCH_HDL_IDX_SHIFT             (0ULL)                 /**< @brief Shift for Index in the pool */
#define DISPATCH_HDL_TYPE_MASK             (0xF00ULL)             /**< @brief Mask for Type of pool       */
#define DISPATCH_HDL_TYPE_SHIFT            (8ULL)                 /**< @brief Shift for Type of pool      */
#define DISPATCH_HDL_TYPE_NW               (1ULL)                 /**< @brief Local socket type           */
#define DISPATCH_HDL_TYPE_LOCAL            (2ULL)                 /**< @brief Local socket type           */
#define DISPATCH_HDL_TYPE_CMDRESP          (4ULL)                 /**< @brief Cmd-resp socket type        */
#define DISPATCH_HDL_MAGIC_MASK            (0xF000ULL)            /**< @brief Magic mask to avoid invalid handle*/
#define DISPATCH_HDL_KEY_MASK              (0xFFFF0000ULL)        /**< @brief Uniqueness Key Mask         */
#define DISPATCH_HDL_HASH_SHIFT            (16ULL)                /**< @brief Uniqueness Key shift        */
#define DISPATCH_HDL_RX_IFC_IDX_MASK       (0xFF00000000ULL)      /**< @brief Uniqueness Key Mask         */
#define DISPATCH_HDL_RX_IFC_IDX_SHIFT      (32ULL)                /**< @brief Uniqueness Key shift        */
#define DISPATCH_HDL_RX_IFC_CONN_IDX_MASK  (0xFF0000000000ULL)    /**< @brief Uniqueness Key Mask         */
#define DISPATCH_HDL_RX_IFC_CONN_IDX_SHIFT (40ULL)                /**< @brief Uniqueness Key shift        */
#define DISPATCH_HDL_TX_IFC_IDX_MASK       (0xFF000000000000ULL)  /**< @brief Uniqueness Key Mask         */
#define DISPATCH_HDL_TX_IFC_IDX_SHIFT      (48ULL)                /**< @brief Uniqueness Key shift        */
#define DISPATCH_HDL_TX_IFC_CONN_IDX_MASK  (0xFF00000000000000ULL)/**< @brief Uniqueness Key Mask         */
#define DISPATCH_HDL_TX_IFC_CONN_IDX_SHIFT (56ULL)                /**< @brief Uniqueness Key shift        */
#define DISPATCH_HDL_INVALID               (0x0ULL)               /**< @brief Invalid handle              */
/** @} */

/**
    @name DISPATCH command IDs
    @{
    @brief DISPATCH command IDs

    @trace #BRCM_SWREQ_DISPATCH
*/
typedef BCM_MsgType DISPATCH_IDType;                     /**< @brief DISPATCH command Type           */
#define DISPATCH_ID_FUNNEL_CREATE    DISPATCH_ID(0x01U)  /**< @brief #DISPATCH_FunnelType       #NA  */
#define DISPATCH_ID_FILTER_ADD       DISPATCH_ID(0x02U)  /**< @brief #DISPATCH_FilterType       #NA  */
#define DISPATCH_ID_FILTER_REMOVE    DISPATCH_ID(0x03U)  /**< @brief #DISPATCH_FilterType       #NA  */
#define DISPATCH_ID_FUNNEL_DELETE    DISPATCH_ID(0x04U)  /**< @brief #DISPATCH_FunnelType       #NA  */
/** @} */

/**
    @brief DISPATCH notification Funnel payload Type

    Used by controllers to create/delete a notification funnel

    @trace #BRCM_SWREQ_DISPATCH
*/
typedef struct sDISPATCH_FunnelType {
    DISPATCH_HandleType handle;           /**< @brief Handle for the funnel created
                                               (returned during creation)             */
    uint32_t            ipAddr;           /**< @brief IP Address of controller socket
                                               wanting notification messages          */
    uint32_t            portNum;          /**< @brief TCP port number of controller
                                               socket (if applicable)                 */
    uint8_t             sockName[DISPATCH_SOCKET_NAME_STRING_SIZE];  /**< @brief Client to
                                               provide the socket name which was created
                                               before calling the relevant api        */
} DISPATCH_FunnelType;
BCM_STATIC_SIZE_ASSERT(DISPATCH_FunnelType, 144UL, RPC_MSG_PAYLOAD_SZ)

/**
    @name DISPATCH notification Filter Registration values Type
    @{
    @brief DISPATCH notification Filter Registration values

    @trace #BRCM_SWREQ_DISPATCH
*/
typedef uint32_t DISPATCH_FilterRegType;
#define DISPATCH_FILTER_REG_GROUP    (0x01UL)   /**< @brief Get all notification messages
                                                     of this specified groupID only         */
#define DISPATCH_FILTER_REG_COMP     (0x02UL)   /**< @brief Get all notification messages
                                                     of the specified groupID and compID    */
#define DISPATCH_FILTER_REG_CMDID    (0x03UL)   /**< @brief Get all notification messages
                                                     matching the specified groupID,
                                                     compID and cmdID                       */
#define DISPATCH_FILTER_REG_ALL      (0x04UL)   /**< @brief Get all notification messages   */
/** @} */

/**
    @brief DISPATCH notification Filter payload Type

    Used by controllers to add/remove a notification filter

    @trace #BRCM_SWREQ_DISPATCH
*/
typedef struct sDISPATCH_FilterType {
    DISPATCH_HandleType     handle;     /**< @brief Handle for the funnel created
                                             (returned during creation). In case of
                                             notifications needed on cmd-response path,
                                             then this shall be set to zero during
                                             filter addition.                       */
    DISPATCH_FilterRegType  filter;     /**< @brief Notification message filter     */
    BCM_MsgType             id;         /**< @brief Notification message ID
                                             to be used for filtering (to be filled as
                                             per the bit mask/shift specified in #BCM_MsgType).
                                             This ID shall be interpreted using the value
                                             specified by #DISPATCH_FilterRegType.
                                             Note: value of 'id' is ignored when 'filter'
                                             is set to #DISPATCH_FILTER_REG_ALL     */


} DISPATCH_FilterType;
BCM_STATIC_SIZE_ASSERT(DISPATCH_FilterType, 16UL, RPC_MSG_PAYLOAD_SZ)

/**
    @brief Vlan Union encapsulating all messages

    @trace #BRCM_SWREQ_DISPATCH
*/
typedef union uDISPATCH_MsgUnionType {
    uint32_t              data[RPC_MSG_PAYLOAD_SZ/4UL]; /**< @brief Max Payload size       */
    DISPATCH_FunnelType   funnel;                       /**< @brief Funnel command payload */
    DISPATCH_FilterType   filter;                       /**< @brief Filter command payload */
} DISPATCH_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(DISPATCH_MsgUnionType, RPC_MSG_PAYLOAD_SZ, RPC_MSG_PAYLOAD_SZ)

/** @brief Create a funnel for notifications

    This API creates a funnel using the controller socket information
    for the notifications.

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aFunnel         Socket information for funnel
    @param[out]     aFunnelHandle   Handle to the created funnel

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Funnel created successfully
    @retval     #BCM_ERR_NOMEM          Maximum number of supported funnels already created
    @retval     #BCM_ERR_INVAL_PARAMS   (aFunnel is NULL) or
                                        (aFunnelHandle is NULL) or
                                         invalid values in #aFunnel

    @post None

    @trace #BRCM_SWREQ_DISPATCH

    @limitations None
*/
extern int32_t DISPATCH_CreateFunnel(BCM_HandleType aConnHdl,
                                     DISPATCH_FunnelType *aFunnel,
                                     DISPATCH_HandleType *aFunnelHandle);

/** @brief Add a filter for the notification funnel

    This API adds a filter to the notification funnel. Controlelr is
    free to add one or more filters to a funnel.

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aFunnelHandle   Handle to the created funnel. In case of
                                    notifications needed on cmd-response path,
                                    then this shall be set to zero. Note that
                                    there is no explicit funnel created when
                                    notifications are needed on the
                                    cmd-response path.
    @param[in]      aFilter         Filter to be added

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Filter added successfully
    @retval     #BCM_ERR_NOMEM          Number of permitted filters per funnel
                                        exceeds #DISPATCH_MAX_FILTER_PER_FUNNEL
    @retval     #BCM_ERR_INVAL_PARAMS   (aFilter is NULL) or
                                        (aFunnelHandle is NULL)
                                        (aFunnelHandle is invalid)

    @post None

    @trace #BRCM_SWREQ_DISPATCH

    @limitations None
*/
extern int32_t DISPATCH_AddFilter(BCM_HandleType aConnHdl,
                                  DISPATCH_HandleType aFunnelHandle,
                                  DISPATCH_FilterType *aFilter);

/** @brief Remove a filter from the notification funnel

    This API removes specified all/subset of filter/s added to
    the notification channel.

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aFunnelHandle   Handle to the created funnel. In case of
                                    notifications on the cmd-response path,
                                    then this shall be set to zero.
    @param[in]      aFilter         Filter to be removed

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Filter removed successfully
    @retval     #BCM_ERR_INVAL_PARAMS   (aFilter is NULL) or
                                        (aFunnelHandle is NULL)

    @post None

    @trace #BRCM_SWREQ_DISPATCH

    @limitations None
*/
extern int32_t DISPATCH_RemoveFilter(BCM_HandleType aConnHdl,
                                     DISPATCH_HandleType aFunnelHandle,
                                     DISPATCH_FilterType *aFilter);

/** @brief Delete the funnel

    This API deletes a funnel specified by the handle.

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aFunnelHandle   Handle to the created funnel

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Funnel deleted successfully
    @retval     #BCM_ERR_INVAL_PARAMS   (aFunnelHandle is NULL) or
                                        (aFunnelHandle is invalid)

    @post None

    @trace #BRCM_SWREQ_DISPATCH

    @limitations None
*/
extern int32_t DISPATCH_DestroyFunnel(BCM_HandleType aConnHdl,
                                      DISPATCH_HandleType aFunnelHandle);

#endif /* RPC_DISPATCH_H */
/** @} */
