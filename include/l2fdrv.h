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
    @defgroup grp_l2fdrv_ifc L2Filter Interface
    @ingroup grp_l2fdrv

    @addtogroup grp_l2fdrv_ifc
    @{

    @file l2fdrv.h

    @brief Interface for PSFP
    This file provides the interface/APIs which can be used to initialize,
    configure and add/remove rules to/from the PSFP block.

    @version 0.1 Initial version
*/

#ifndef L2FDRV_H
#define L2FDRV_H

#include <stdint.h>
#include <bcm_utils.h>
#include <ethernet.h>

/**
    @name L2Filter Driver Architecture IDs
    @{
    @brief Architecture IDs for L2Filter Driver
*/
#define BRCM_SWARCH_L2FDRV_INVAL_RULE_INDEX_MACRO      (0x8000U) /**< @brief #L2FDRV_INVAL_RULE_INDEX   */
#define BRCM_SWARCH_L2FDRV_MAX_NUM_RULES_MACRO         (0x8001U) /**< @brief #L2FDRV_MAX_NUM_RULES      */
#define BRCM_SWARCH_L2FDRV_ACTION_TYPE                 (0x8002U) /**< @brief #L2FDRV_ActionFlagType     */
#define BRCM_SWARCH_L2FDRV_DA_LOOKUP_TYPE              (0x8003U) /**< @brief #L2FDRV_DaLookupType       */
#define BRCM_SWARCH_L2FDRV_RULE_KEY_TYPE               (0x8004U) /**< @brief #L2FDRV_RuleKeyType        */
#define BRCM_SWARCH_L2FDRV_RULE_ACTION_TYPE            (0x8005U) /**< @brief #L2FDRV_RuleActionType     */
#define BRCM_SWARCH_L2FDRV_INIT_PROC                   (0x8006U) /**< @brief #L2FDRV_Init               */
#define BRCM_SWARCH_L2FDRV_ADD_RULE_PROC               (0x8007U) /**< @brief #L2FDRV_AddRule            */
#define BRCM_SWARCH_L2FDRV_READ_RULE_PROC              (0x8008U) /**< @brief #L2FDRV_ReadRule           */
#define BRCM_SWARCH_L2FDRV_REMOVE_RULE_PROC            (0x8009U) /**< @brief #L2FDRV_RemoveRule         */
#define BRCM_SWARCH_L2FDRV_GET_ACTIVE_RULES_PROC       (0x800AU) /**< @brief #L2FDRV_GetActiveRules     */
/** @} */

/**
    @brief Invalid rule index

    Used for allocating the index internally

    @trace #BRCM_SWREQ_L2FDRV
*/
#define L2FDRV_INVAL_RULE_INDEX         (0xFFFFFFFFUL)

/**
    @brief Invalid rule index

    Used for allocating the index internally

    @trace #BRCM_SWREQ_L2FDRV_KERNEL_INTERFACE
*/
#define L2FDRV_MAX_NUM_RULES            (64UL)

/**
    @brief L2 filter rule actions

    @{
    @brief Type and macros for L2 filter rule actions

    @trace #BRCM_SWREQ_L2FDRV
*/
typedef uint32_t L2FDRV_ActionFlagType;
#define L2FDRV_ACTION_TX_PORT_FW        0x0001UL  /**< @brief Forward the packet to the TX port mask */
#define L2FDRV_ACTION_IMP_PORT_FW       0x0002UL  /**< @brief Forward the packet only to IMP port.
                                                              If set, TX_PORT_FW is ignored */
#define L2FDRV_ACTION_L3FW_EN           0x0004UL  /**< @brief Enable L3 Forwarding operation */
#define L2FDRV_ACTION_SKIP_VLAN_CHK     0x0008UL  /**< @brief Skip ingress VLAN membership check */
#define L2FDRV_ACTION_SKIP_UNTAG_CHK    0x0010UL  /**< @brief Skip dropping untagged packets */
#define L2FDRV_ACTION_SKIP_ARL_LEARN    0x0020UL  /**< @brief Skip ARL learning */
#define L2FDRV_ACTION_SKIP_UNTAG        0x0040UL  /**< @brief Skip Untagging operation */
#define L2FDRV_ACTION_SKIP_SPN_CHK      0x0080UL  /**< @brief Skip Spanning tree check */
#define L2FDRV_ACTION_SKIP_EAP_CHK      0x0100UL  /**< @brief Skip EAP check */
#define L2FDRV_ACTION_SET_PROTO_TERM    0x0200UL  /**< @brief Set proto_term reason code to pkt */
/** @} */

/**
    @brief DA Lookup type enum

    @{
    @brief DA Lookup type enum

    @trace #BRCM_SWREQ_L2FDRV
*/
typedef uint32_t L2FDRV_DaLookupType;
#define L2FDRV_DA_LOOKUP_UDLH  (0UL)  /**< @brief UDLH – Unicast Destination Lookup Hit */
#define L2FDRV_DA_LOOKUP_MDLH  (1UL)  /**< @brief MDLH – Multicast Destination Lookup Hit */
#define L2FDRV_DA_LOOKUP_MREV  (2UL)  /**< @brief MREV – Reserved Multicast Destination packet */
#define L2FDRV_DA_LOOKUP_BCAST (3UL)  /**< @brief BCAST – Broadcast packet */
#define L2FDRV_DA_LOOKUP_MDLF  (4UL)  /**< @brief MDLF – Multicast Destination Lookup Failure */
#define L2FDRV_DA_LOOKUP_UDLF  (5UL)  /**< @brief UDLF – Unicast Destination Lookup Failure */
/** @} */

/**
    @brief L2Filter Rule Key

    @trace #BRCM_SWREQ_L2FDRV
*/
typedef struct sL2FDRV_RuleKeyType {
    uint32_t rxPortMask;   /**< @brief Rx ports on which this rule is applicable */
    uint8_t  dmac[6];      /**< @brief DMAC match value.
                                       Example Exact match (00:1B:44:11:3A:10)            <BR>
                                       dmac      = { 0x00, 0x1B, 0x44, 0x11, 0x3A, 0x10 } <BR>
                                       dmacRange = 0                                      <BR>
                                       dmacMask  = { 0xFF, 0xFF, 0xFF, 0xFF }
                            */
    uint16_t dmacRange;    /**< @brief Range of DMACs starting for dmac to dmac+dmacRange
                                       Example Range (00:1B:44:11:3A:10 to 00:1B:44:11:3B:10) <BR>
                                       dmac      = { 0x00, 0x1B, 0x44, 0x11, 0x3A, 0x10 }     <BR>
                                       dmacRange = 0x100                                      <BR>
                                       dmacMask  = { don't care }
                            */
    uint8_t  dmacMask[4];  /**< @brief Match mask for least 32 bits of DMAC.
                                    Not applicable when range is non-zero              <BR>
                                    Example match with mask (00:1B:44:11:xx:xx)        <BR>
                                    dmac      = { 0x00, 0x1B, 0x44, 0x11, 0x00, 0x00 } <BR>
                                    dmacRange = 0                                      <BR>
                                    dmacMask  = { 0xFF, 0xFF, 0x00, 0x00 }
                            */
    ETHER_EtherType etherType;  /**< @brief Ether type to match, 0 for no ether type match */
} L2FDRV_RuleKeyType;

/**
    @brief L2Filter Rule Action

    @trace #BRCM_SWREQ_L2FDRV
*/
typedef struct sL2FDRV_RuleActionType {
    L2FDRV_ActionFlagType actionFlags;  /**< @brief Action flags */
    uint32_t              txPortMask;   /**< @brief Tx ports for forwarding.
                                                    Applicable when #L2FDRV_ACTION_TX_PORT_FW action
                                                    is set */
    L2FDRV_DaLookupType   daLukType;    /**< @brief DA Lookup type to be set for the matching packet.
                                                    Applicable when #L2FDRV_ACTION_SET_DA_LUK action
                                                    is enabled */
} L2FDRV_RuleActionType;


/** @brief Initialize L2Filter HW and the driver

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aID             Switch HW index

    @retval  #BCM_ERR_OK           Initialization successful

    @post L2F HW and driver initialized

    @trace #BRCM_SWREQ_L2FDRV

    @limitations None
*/
int32_t L2FDRV_Init(uint32_t aID);

/** @brief Add an L2 Filter rule

    @behavior Sync, Re-entrant

    @pre L2Filter driver initialized

    @param[in]    aID         Switch HW index
    @param[inout] aRuleIndex  Index into the L2 rule table.
                              If #L2FDRV_INVAL_RULE_INDEX, then
                              the index is auto allocated and returned.
    @param[in]    aRuleKey    Rule key
    @param[in]    aAction     Actions for the rule

    @retval  #BCM_ERR_OK           Given rule is added successfully
    @retval  #BCM_ERR_UNINIT       Driver not initialized
    @retval  #BCM_ERR_INVAL_PARAMS aRuleIndex or aRuleKey or aAction is NULL
    @retval  #BCM_ERR_NOMEM        No free slot available for the rule or
                                   given rule index is out of range
    @retval  #BCM_ERR_NOPERM       Given aRuleIndex is not free

    @post L2F HW and driver initialized

    @trace #BRCM_SWREQ_L2FDRV

    @limitations None
*/
int32_t L2FDRV_AddRule(uint32_t aID,
                       uint32_t * const aRuleIndex,
                       L2FDRV_RuleKeyType const * const aRuleKey,
                       L2FDRV_RuleActionType const * const aAction);

/** @brief Read an L2 Filter rule

    @behavior Sync, Re-entrant

    @pre L2Filter driver initialized

    @param[in]    aID         Switch HW index
    @param[in]    aRuleIndex  Index into the L2 rule table.
    @param[inout] aRuleKey    Rule key
    @param[inout] aAction     Actions for the rule

    @retval  #BCM_ERR_OK           Given rule is read successfully
    @retval  #BCM_ERR_UNINIT       Driver not initialized
    @retval  #BCM_ERR_INVAL_PARAMS aRuleKey or aAction is NULL or
                                   aRuleIndex is out of range
    @retval  #BCM_ERR_NOT_FOUND    No rule found in the index

    @post None

    @trace #BRCM_SWREQ_L2FDRV

    @limitations None
*/
int32_t L2FDRV_ReadRule(uint32_t aID,
                        uint32_t aRuleIndex,
                        L2FDRV_RuleKeyType * const aRuleKey,
                        L2FDRV_RuleActionType * const aAction);

/** @brief Remove the given L2 filter rule

    @behavior Sync, Re-entrant

    @pre L2Filter driver initialized

    @param[in]    aID             Switch HW index

    @retval  #BCM_ERR_OK            Initialization successful
    @retval  #BCM_ERR_UNINIT        Driver not initialized
    @retval  #BCM_ERR_INVAL_PARAMS  Rule index out of range
    @retval  #BCM_ERR_NOT_FOUND     No rule found in the index

    @post Given L2F rule removed from the table

    @trace #BRCM_SWREQ_L2FDRV

    @limitations None
*/
int32_t L2FDRV_RemoveRule(uint32_t aID, uint32_t aRuleIndex);

/** @brief Get active rules

    @behavior Sync, Re-entrant

    @pre L2Filter driver initialized

    @param[in]    aID             Switch HW index
    @param[out]   aActiveRules    Bit mask of active rules.
                                  Each bit represents one rule index.
                                  1 = Rule is active, 0 = Rule index is free.
                                  Bits 0 to L2FDRV_MAX_NUM_RULES-1. (Big-endian)
                                  Buffer size (L2FDRV_MAX_NUM_RULES+7UL)/8UL bytes.

    @retval  #BCM_ERR_OK            Initialization successful
    @retval  #BCM_ERR_UNINIT        Driver not initialized
    @retval  #BCM_ERR_INVAL_PARAMS  aActiveRules is NULL

    @post None

    @trace #BRCM_SWREQ_L2FDRV

    @limitations None
*/
int32_t L2FDRV_GetActiveRules(uint32_t aID, uint8_t * const aActiveRules);

#endif /* L2FDRV_H */

/** @} */
