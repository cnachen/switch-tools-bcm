/*****************************************************************************
 Copyright 2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_tls_types  Types
    @ingroup grp_tls_abstract_def

    @addtogroup grp_tls_types
    @{

    @file ethernet_tls_types.h
    @brief TLS interface
    This header file contains the interface functions for TLS

    @version 1.0 Initial Version
*/

#ifndef ETHERNET_TLS_TYPES_H
#define ETHERNET_TLS_TYPES_H

#include <bcm_comp.h>
#include <bcm_msg.h>
#include <stdint.h>
#include <bcm_utils.h>
#include <ethernet_tls_std.h>

/**
    @name TLS Architecture IDs
    @{
    @brief Architecture IDs for TLS
*/
#define BRCM_SWARCH_TLS_ID_OF_MACRO                     (0x7500U) /**< @brief #TLS_ID_OF                     */
#define BRCM_SWARCH_TLS_ID_TYPE                         (0x7501U) /**< @brief #TLS_IdType                    */
#define BRCM_SWARCH_TLS_MSG_MAX_SIZE_MACRO              (0x7502U) /**< @brief #TLS_MSG_MAX_SIZE              */
#define BRCM_SWARCH_TLS_CONN_STATUS_TYPE                (0x7503U) /**< @brief #TLS_ConnStatusType            */
#define BRCM_SWARCH_TLS_GLOBAL_STATUS_TYPE              (0x7504U) /**< @brief #TLS_GlobalStatusType          */
#define BRCM_SWARCH_TLS_MSG_UNION_TYPE                  (0x7505U) /**< @brief #TLS_MsgUnionType              */
#define BRCM_SWARCH_TLS_MSG_TYPE                        (0x7506U) /**< @brief #TLS_MsgType                   */

/** @} */

/**
    @brief Macro to Construct TLS Cmd

    @trace #BRCM_SWREQ_TLS
*/
#define TLS_ID_OF(aId)     BCM_MSG(BCM_GROUPID_ETHSRV, BCM_TLSMOD_ID, aId)

/**
    @name TLS Message IDs
    @{
    @brief Message IDs for exchange on message queues

    @trace #BRCM_SWREQ_TLS
*/
typedef BCM_MsgType TLS_IdType;
#define TLS_ID_GLOBAL_STATUS       TLS_ID_OF(0x00UL)   /**< @brief #TLS_GlobalStatusType                 #TLS_GetStatus */
/** @} */

/**
    @brief Macro to Construct TLS Cmd

    @trace #BRCM_SWREQ_TLS
*/
#define TLS_MSG_MAX_SIZE                (432UL) /**< @brief maximum message size */

/**
    @brief Connection status

    Status and negotiated parameters for one TLS connections

    @trace #BRCM_SWREQ_TLS

*/
typedef struct sTLS_ConnStatusType {
    BCM_CompIDType                      compId;             /**< @brief Component ID */
    TLS_ConnectionType                  conn;               /**< @brief Connection type */
    uint16_t                            portID;             /**< @brief Peer Port ID */
    TLS_VersionType                     version;            /**< @brief Version */
    TLS_CipherSuiteType                 suite;              /**< @brief Cipher suite */
    TLS_NamedCurveType                  curve;              /**< @brief Named curve */
    TLS_SignAlgoType                    signAlgo;           /**< @brief Signature algorithm */
    uint16_t                            reserved[5UL];           /**< @brief Reserved */
} TLS_ConnStatusType;
BCM_STATIC_SIZE_ASSERT(TLS_ConnStatusType, 24UL, 24UL);

/**
    @brief Global status

    Status and negotiated parameters for all the TLS connections

    @trace #BRCM_SWREQ_TLS

*/
typedef struct sTLS_GlobalStatusType {
    TLS_ConnStatusType                  connInfo[16UL];         /**< @brief Connection information */
    uint32_t                            numConnections;         /**< @brief Number of connections */
    uint8_t                             reserved[12UL];         /**< @brief Reserved */
} TLS_GlobalStatusType;
BCM_STATIC_SIZE_ASSERT(TLS_GlobalStatusType, 400UL, TLS_MSG_MAX_SIZE);

/**
    @brief TLS command union encapsulating all messages

    @trace #BRCM_SWREQ_TLS
*/
typedef union uTLS_MsgUnionType {
    TLS_GlobalStatusType   globalStatus;  /**< @brief Get global status */
} TLS_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(TLS_MsgUnionType, 400UL, TLS_MSG_MAX_SIZE);

/**
    @brief TLS command message structure

    @trace #BRCM_SWREQ_TLS
*/
typedef struct sTLS_MsgType {
    TLS_IdType           cmd;        /**< @brief Command ID          */
    int32_t              response;   /**< @brief Response            */
    TLS_MsgUnionType     u;          /**< @brief Message union       */
} TLS_MsgType;
BCM_STATIC_SIZE_ASSERT(TLS_MsgType, 408UL, TLS_MSG_MAX_SIZE);

#endif /* ETHERNET_TLS_TYPES_H */

/** @} */
