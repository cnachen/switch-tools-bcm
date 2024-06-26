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
    @defgroup grp_rpc_abstract_types Common Types
    @ingroup grp_rpc_abstract

    @addtogroup grp_rpc_abstract_types
    @{

    @file rpc_types.h
    @brief RPC basic types

    @version 0.1 Initial Version
*/

#ifndef RPC_TYPES_H
#define RPC_TYPES_H

/**
    @name Architecture IDs
    @{
    @brief Architecture IDs

*/
#define BRCM_SWARCH_RPC_MACRO               (0x8001U)   /**< @brief #RPC_CFG_MAGIC      */
#define BRCM_SWARCH_RPC_CFG_VER_TYPE        (0x8002U)   /**< @brief #RPC_CfgVerType     */
#define BRCM_SWARCH_RPC_TRUST_TYPE          (0x8003U)   /**< @brief #RPC_TrustType      */

#define BRCM_SWARCH_RPC_ETH_CFG_TYPE        (0x8020U)   /**< @brief #RPC_EthCfgType     */
#define BRCM_SWARCH_RPC_IPC_CFG_TYPE        (0x8021U)   /**< @brief #RPC_IpcCfgType     */
#define BRCM_SWARCH_RPC_CFG_TYPE            (0x8022U)   /**< @brief #RPC_CfgType        */
/** @} */

/**
    @brief RPC Macros

    @trace #BRCM_SWREQ_RPC
*/
#define RPC_CFG_MAGIC           BCM_PACK32('R', 'P', 'C', 'C')  /**< @brief RPC MAGIC   */
#define RPC_ETH_PORT_MAX        (32UL)          /**< @brief RPC Max ethernet port count */

/**
    @brief RPC config version

    @trace #BRCM_SWREQ_RPC
*/
typedef uint32_t RPC_CfgVerType;
#define RPC_CFG_VER_1_0     (0x00010000UL)  /**< @brief Version 1.0     */

/**
    @brief RPC trust mode

    @note when force mode is set, the connection is assumed trusted always,
    irrespective of MKA or TLS status.

    @trace #BRCM_SWREQ_RPC
*/
typedef uint8_t RPC_TrustType;
#define RPC_TRUST_FORCE_MASK        (0x01U) /**< @brief Force enable trust mask @xsd default:1  */
#define RPC_TRUST_FORCE_SHIFT       (0U)    /**< @brief Force enable trust shift                */
#define RPC_TRUST_MKA_MASK          (0x02U) /**< @brief MKA based enable mask                   */
#define RPC_TRUST_MKA_SHIFT         (1U)    /**< @brief MKA based enable shift                  */
#define RPC_TRUST_TLS_MASK          (0x04U) /**< @brief TLS based enable mask                   */
#define RPC_TRUST_TLS_SHIFT         (2U)    /**< @brief TLS based enable shift                  */

/**
    @brief Ethernet Configuration

    @trace #BRCM_SWREQ_RPC
 */
typedef struct sRPC_EthCfgType {
    uint16_t            tcpDirectPort;  /**< @brief TCP Direct Server port @xsd default:5555   */
    uint16_t            tcpProxyPort;   /**< @brief TCP Proxy Server port @xsd default:61440   */
    uint16_t            tlsDirectPort;  /**< @brief TLS Direct Server port @xsd default:61441  */
    uint16_t            tlsProxyPort;   /**< @brief TLS Proxy Server port @xsd default:61442   */
    RPC_TrustType       ethPortTrust[RPC_ETH_PORT_MAX];/**< @brief port trust mode      */
    uint8_t             reserved[24UL]; /**< @brief Reserved @xsd rsvd                  */
} RPC_EthCfgType;
BCM_STATIC_SIZE_ASSERT(RPC_EthCfgType, 64UL, 64UL)

/**
    @brief IPC Configuration

    @trace #BRCM_SWREQ_RPC
 */
typedef struct sRPC_IpcCfgType {
    RPC_TrustType       ipcTrust;       /**< @brief IPC channel trust mode      */
    uint8_t             reserved[31UL]; /**< @brief Reserved @xsd rsvd          */
} RPC_IpcCfgType;
BCM_STATIC_SIZE_ASSERT(RPC_IpcCfgType, 32UL, 32UL)

/**
    @brief RPC Configuration

    @trace #BRCM_SWREQ_RPC
 */
typedef struct sRPC_CfgType{
    uint32_t            magic;              /**< @brief magic @xsd constant:RPC_CFG_MAGIC       */
    RPC_CfgVerType      version;            /**< @brief version @xsd constant:RPC_CFG_VER_1_0   */
    RPC_EthCfgType      ethCfg;             /**< @brief Ethernet related configuration          */
    RPC_IpcCfgType      ipcCfg;             /**< @brief IPC related configuration               */
    uint8_t             reserved[152UL];    /**< @brief reserved @xsd rsvd                      */
} RPC_CfgType;
BCM_STATIC_SIZE_ASSERT(RPC_CfgType, 256UL, 256UL)


#endif /* RPC_TYPES_H */

/** @} */
