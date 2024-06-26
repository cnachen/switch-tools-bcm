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
    @defgroup grp_ethsrv_swtcfp_ifc Ethernet Service: CFP Interface
    @ingroup grp_ethsrv_swt

    @addtogroup grp_ethsrv_swtcfp_ifc
    @{

    @file ethswtm_cfp.h

    @brief Ethernet Service: CFP Interface
    This file contains the interfaces for the Ethernet Service specific
    to CFP

    @version 0.1 Initial version
*/

#ifndef ETHSWTM_CFP_H
#define ETHSWTM_CFP_H

#include <ethernet_swt_cfp.h>

/**
    @name Ethernet Service CFP API IDs
    @{
    @brief API IDs for CFP in Ethernet Service
*/
#define BRCM_SWARCH_ETHSWTM_CFP_PROTOCOL_TYPE            (0x8601U) /**< @brief #ETHSWTM_CFPProtocolType   */
#define BRCM_SWARCH_ETHSWTM_CFP_IP_VERSION_TYPE          (0x8602U) /**< @brief #ETHSWTM_CFPIPVersionType  */
#define BRCM_SWARCH_ETHSWTM_CFPL3KEY_TYPE                (0x8603U) /**< @brief #ETHSWTM_CFPL3KeyType      */
#define BRCM_SWARCH_ETHSWTM_CFP_CONSTRUCT_L3KEY_PROC     (0x8604U) /**< @brief #ETHSWTM_CFPConstructL3Key */
#define BRCM_SWARCH_ETHSWTM_CFP_GET_L3KEY_PROC           (0x8605U) /**< @brief #ETHSWTM_CFPGetL3Key       */
#define BRCM_SWARCH_ETHSWTM_CFPMODULE_GLOBAL             (0x8606U) /**< @brief #ETHSWTM_CFPModule         */
/** @} */

/**
    @brief CFP protocol type defintions

    @trace #BRCM_SWREQ_ETHSWTM_CFP
*/
typedef uint8_t ETHSWTM_CFPProtocolType;    /**< @brief Protocol type                              */
#define ETHSWTM_CFP_PROTOCOL_NONE    (0U)   /**< @brief Do not match protocol field from IP header */
#define ETHSWTM_CFP_PROTOCOL_TCP     (6U)   /**< @brief TCP (RFC793)                               */
#define ETHSWTM_CFP_PROTOCOL_UDP     (17U)  /**< @brief UDP (RFC768)                               */
#define ETHSWTM_CFP_PROTOCOL_SCTP    (132U) /**< @brief SCTP (RFC4960)                             */

/**
    @brief CFP IP version type defintions

    @trace #BRCM_SWREQ_ETHSWTM_CFP
*/
typedef uint32_t ETHSWTM_CFPIPVersionType;      /**< @brief IP version type  */
#define ETHSWTM_CFP_IP_VERSION_IPV4     (0UL)   /**< @brief IPv4             */
#define ETHSWTM_CFP_IP_VERSION_IPV6     (1UL)   /**< @brief IPv6             */

/**
    @brief Structure for CFP L3 Key

    Structure for CFP L3 Key. When this structure used for input key, each members
    holds the input value. When used for mask, The fields which are non zeros
    are used to construct CFP key.

    @trace #BRCM_SWREQ_ETHSWTM_CFP
*/
typedef struct sETHSWTM_CFPL3KeyType {
    ETHSWT_PortMaskType      portMask;      /**< @brief Ports on which the stream
                                                       is expected to ingress */
    ETHER_VLANIDType         vlanID;        /**< @brief VLAN identifier   */
    uint8_t                  smac[6U];      /**< @brief Source MAC        */
    uint8_t                  dmac[6U];      /**< @brief Destination MAC   */
    ETHSWTM_CFPIPVersionType ipVersion;     /**< @brief IP version type   */
    ETHSWT_PCPType           priority;      /**< @brief Priority (PCP)    */
    ETHSWTM_CFPProtocolType  protocol;      /**< @brief Protocol/Next Header. If this has
                                                        the value #ETHSWTM_CFP_PROTOCOL_NONE
                                                        then the sourcePort and destPort
                                                        fields are also ignored. */
    uint16_t                 sourcePort;    /**< @brief Source port number */
    uint16_t                 destPort;      /**< @brief Destination port number */
    uint8_t                  sourceIP[16];  /**< @brief Source IP address:
                                                        4 bytes for IPv4 or 16 bytes for IPv6.
                                                        Interpreted on the basis of IP version.
                                                        Provided in big endian format.
                                                        When used for mask, same bytes are used
                                                        for masking IP. A value of all 0's
                                                        indicates that this field is ignored. */
    uint8_t                  destIP[16];    /**< @brief Destination IP address:
                                                        4 bytes for IPv4 or 16 bytes for IPv6.
                                                        Interpreted on the basis of IP version.
                                                        Provided in big endian format.
                                                        When used for mask, same bytes are used
                                                        for masking IP. A value of all 0's
                                                        indicates that this field is ignored. */
} ETHSWTM_CFPL3KeyType;

/**
    @brief Construct CFP key from L3 key

    This API constructs the CFP key from L3 key input & mask

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aL3Key           Address of the L3 Key input
    @param[in]     aL3KeyMask       Address of the L3 Key mask
    @param[out]    aCfpKey          Address of the CFP Key to be filled

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Key constructed successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aL3Key/aL3KeyMask/aCfpKey is NULL
    @retval  #BCM_ERR_NOSUPPORT        ipVersion in aL3Key is #ETHSWTM_CFP_IP_VERSION_IPV6

    @post None

    @trace #BRCM_SWREQ_ETHSWTM_CFP

    @limitations None
*/
int32_t ETHSWTM_CFPConstructL3Key(ETHSWTM_CFPL3KeyType const *aL3Key,
                                  ETHSWTM_CFPL3KeyType const *aL3KeyMask,
                                  ETHSWT_CFPKeyType *aCfpKey);
/**
    @brief Get L3 key from CFP key

    This API constructs the L3 key and mask from CFP key input

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aCfpKey          Address of the CFP Key to be filled
    @param[out]   aL3Key           Address of the L3 Key input
    @param[out]   aL3KeyMask       Address of the L3 Key mask

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK               Key constructed successfully
    @retval  #BCM_ERR_INVAL_PARAMS     aL3Key/aL3KeyMask/aCfpKey is NULL

    @post None

    @trace #BRCM_SWREQ_ETHSWTM_CFP

    @limitations None
*/
int32_t ETHSWTM_CFPGetL3Key(ETHSWT_CFPKeyType const * const aCfpKey,
                            ETHSWTM_CFPL3KeyType * const aL3Key,
                            ETHSWTM_CFPL3KeyType * const aL3KeyMask);

/**
    @brief Function pointer table for ETHSWTM CFP module

    @trace #BRCM_SWREQ_ETHSWTM_CFP
 */
extern const MODULE_Type ETHSWTM_CFPModule;

#endif /* ETHSWTM_CFP_H */

/** @} */
