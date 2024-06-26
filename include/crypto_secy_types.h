/*****************************************************************************
 Copyright 2022-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_crypto_secy_types_ifc SecY Types
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_secy_types_ifc
    @{

    @file crypto_secy_types.h
    @brief Crypto MAC Security Entity (MACSEC) Types
    This header file contains the Types for Crypto MAC Security Entity (MACSEC)

    @version 1.0 Initial Version
*/

#ifndef CRYPTO_SECY_TYPES_H
#define CRYPTO_SECY_TYPES_H

#include <crypto_common.h>
#include <bcm_comp.h>
#include <bcm_err.h>
#include <bcm_utils.h>

/**
    @name Crypto SecY Architecture IDs
    @{
    @brief Architecture IDs for Crypto SecY
*/

#define BRCM_SWARCH_SECY_TYPE                        (0x8940U) /**< @brief #SECY_IdType                */
#define BRCM_SWARCH_SECY_MACRO                       (0x8941U) /**< @brief #SECY_XPN_SALT_LEN          */
#define BRCM_SWARCH_SECY_HW_CFG_TYPE                 (0x8942U) /**< @brief #SECY_HwCfgType             */
#define BRCM_SWARCH_SECY_VALIDATE_FRAME_TYPE         (0x8943U) /**< @brief #SECY_ValidateFrameType     */
#define BRCM_SWARCH_SECY_RULE_OPT0_TYPE              (0x8944U) /**< @brief #SECY_RuleOpt0Type          */
#define BRCM_SWARCH_SECY_RULE_OPT1_TYPE              (0x8945U) /**< @brief #SECY_RuleOpt1Type          */
#define BRCM_SWARCH_SECY_CFG_TYPE                    (0x8946U) /**< @brief #SECY_CfgType               */
#define BRCM_SWARCH_SECY_CIPHER_TYPE                 (0x8947U) /**< @brief #SECY_CipherType            */
#define BRCM_SWARCH_SECY_CIPHER_CAP_TYPE             (0x8948U) /**< @brief #SECY_CipherCapType         */
#define BRCM_SWARCH_SECY_CONF_OFFSET_TYPE            (0x8949U) /**< @brief #SECY_ConfOffsetType        */
#define BRCM_SWARCH_SECY_RULE_MATCH_TYPE             (0x894AU) /**< @brief #SECY_RuleMatchType         */
#define BRCM_SWARCH_SECY_RULE_DIR_TYPE               (0x894BU) /**< @brief #SECY_RuleDirType           */
#define BRCM_SWARCH_SECY_SCI_TYPE                    (0x894CU) /**< @brief #SECY_SCIType               */
#define BRCM_SWARCH_SECY_KEY_TYPE                    (0x894DU) /**< @brief #SECY_KeyType               */
#define BRCM_SWARCH_SECY_SA_STATUS_TYPE              (0x894EU) /**< @brief #SECY_SAStatusType          */
#define BRCM_SWARCH_SECY_STATS_TYPE                  (0x894FU) /**< @brief #SECY_StatsType             */
#define BRCM_SWARCH_SECY_TXSCSTATS_TYPE              (0x8950U) /**< @brief #SECY_TxSCStatsType         */
#define BRCM_SWARCH_SECY_RXSCSTATS_TYPE              (0x8951U) /**< @brief #SECY_RxSCStatsType         */
#define BRCM_SWARCH_SECY_ID_OF_MACRO                 (0x8952U) /**< @brief #SECY_ID_OF                 */
#define BRCM_SWARCH_SECY_HANDLE_TYPE                 (0x8953U) /**< @brief #SECY_HandleType            */
#define BRCM_SWARCH_SECY_BUS_TYPE                    (0x8954U) /**< @brief #SECY_BusType               */
#define BRCM_SWARCH_SECY_CREATEV2_TYPE               (0x8955U) /**< @brief #SECY_CreateV2Type          */
#define BRCM_SWARCH_SECY_ALLSTATS_TYPE               (0x8956U) /**< @brief #SECY_AllStatsType          */
#define BRCM_SWARCH_SECY_HW_STATUS_TYPE              (0x8957U) /**< @brief #SECY_HwStatusType          */
#define BRCM_SWARCH_SECY_PORT_STATUS_TYPE            (0x8958U) /**< @brief #SECY_PortStatusType        */

#define BRCM_SWARCH_SECY_HW_INIT_MSG_TYPE            (0x8960U) /**< @brief #SECY_HwInitMsgType         */
#define BRCM_SWARCH_SECY_RULE_OPT0_MSG_TYPE          (0x8961U) /**< @brief #SECY_RuleOpt0MsgType       */
#define BRCM_SWARCH_SECY_RULE_OPT1_MSG_TYPE          (0x8962U) /**< @brief #SECY_RuleOpt1MsgType       */
#define BRCM_SWARCH_SECY_HDL_MSG_TYPE                (0x8963U) /**< @brief #SECY_HdlMsgType            */
#define BRCM_SWARCH_SECY_CREATE_MSG_TYPE             (0x8964U) /**< @brief #SECY_CreateMsgType         */
#define BRCM_SWARCH_SECY_GET_CIPHER_MSG_TYPE         (0x8965U) /**< @brief #SECY_GetCipherMsgType      */
#define BRCM_SWARCH_SECY_SET_CIPHER_MSG_TYPE         (0x8966U) /**< @brief #SECY_SetCipherMsgType      */
#define BRCM_SWARCH_SECY_DEBUG_MSG_TYPE              (0x8967U) /**< @brief #SECY_DebugMsgType          */
#define BRCM_SWARCH_SECY_STATS_MSG_TYPE              (0x8968U) /**< @brief #SECY_StatsMsgType          */
#define BRCM_SWARCH_SECY_SC_MSG_TYPE                 (0x8969U) /**< @brief #SECY_SCMsgType             */
#define BRCM_SWARCH_SECY_LOOKUP_RULE_MSG_TYPE        (0x896AU) /**< @brief #SECY_LookupRuleMsgType     */
#define BRCM_SWARCH_SECY_LOOKUP_RULEV2_MSG_TYPE      (0x896BU) /**< @brief #SECY_LookupRuleV2MsgType   */
#define BRCM_SWARCH_SECY_TXSC_STATS_MSG_TYPE         (0x896CU) /**< @brief #SECY_TxSCStatsMsgType      */
#define BRCM_SWARCH_SECY_RX_SC_STATS_MSG_TYPE        (0x896DU) /**< @brief #SECY_RxSCStatsMsgType      */
#define BRCM_SWARCH_SECY_SA_MSG_TYPE                 (0x896EU) /**< @brief #SECY_SAMsgType             */
#define BRCM_SWARCH_SECY_PN_MSG_TYPE                 (0x896FU) /**< @brief #SECY_PNMsgType             */
#define BRCM_SWARCH_SECY_SA_STATUS_MSG_TYPE          (0x8970U) /**< @brief #SECY_SAStatusMsgType       */
#define BRCM_SWARCH_SECY_HW_DEINIT_MSG_TYPE          (0x8971U) /**< @brief #SECY_HwDeinitMsgType       */
#define BRCM_SWARCH_SECY_CREATE_V2_MSG_TYPE          (0x8972U) /**< @brief #SECY_CreateV2MsgType       */
#define BRCM_SWARCH_SECY_CREATESA_V2_MSG_TYPE        (0x8973U) /**< @brief #SECY_CreateSAV2MsgType     */
#define BRCM_SWARCH_SECY_UPDATESA_MSG_TYPE           (0x8974U) /**< @brief #SECY_UpdateSAMsgType       */
#define BRCM_SWARCH_SECY_FULLSTATS_MSG_TYPE          (0x8975U) /**< @brief #SECY_FullStatsMsgType      */
#define BRCM_SWARCH_SECY_SA_EXT_MSG_TYPE             (0x8976U) /**< @brief #SECY_SALocalMsgType        */
#define BRCM_SWARCH_SECY_STATUS_MSG_TYPE             (0x8977U) /**< @brief #SECY_StatusMsgType         */

/** @} */

/**
    @brief Macro to Construct SECY CmdID

    @trace #BRCM_SWREQ_SECY
*/
#define SECY_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_CRYPTO, BCM_CSY_ID, aId)
/**
    @name CRYPTO SecY Message IDs
    @{
    @brief Message IDs for exchange on message queues

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_IdType;     /**< @brief Pa message Type */
#define SECY_HW_INIT             SECY_ID_OF(0xC0U) /**< @brief #SECY_HwInitMsgType       #MACSEC_Init                */
#define SECY_ADD_CP_RULE_OPT0    SECY_ID_OF(0xC1U) /**< @brief #SECY_RuleOpt0MsgType     #MACSEC_AddCPRuleOpt0       */
#define SECY_ADD_CP_RULE_OPT1    SECY_ID_OF(0xC2U) /**< @brief #SECY_RuleOpt1MsgType     #MACSEC_AddCPRuleOpt1       */
#define SECY_REM_CP_RULE         SECY_ID_OF(0xC3U) /**< @brief #SECY_HdlMsgType          #MACSEC_RemoveCPRule        */
#define SECY_CTRL_PORT_ENABLE    SECY_ID_OF(0xC4U) /**< @brief #SECY_HdlMsgType                                      */
#define SECY_CTRL_PORT_DISABLE   SECY_ID_OF(0xC5U) /**< @brief #SECY_HdlMsgType                                      */
#define SECY_GET_PORT_STATUS     SECY_ID_OF(0xC6U) /**< @brief #SECY_StatusMsgType                                   */
#define SECY_HW_DEINIT           SECY_ID_OF(0xCFU) /**< @brief #SECY_HwDeinitMsgType     #MACSEC_DeInit              */
#define SECY_CREATE              SECY_ID_OF(0xD0U) /**< @brief #SECY_CreateMsgType       #MACSEC_CreateSecY          */
#define SECY_GET_CIPHER_CAP      SECY_ID_OF(0xD1U) /**< @brief #SECY_GetCipherMsgType    #MACSEC_GetCipherCap        */
#define SECY_SET_CIPHER_SUITE    SECY_ID_OF(0xD2U) /**< @brief #SECY_SetCipherMsgType    #MACSEC_SetCipherSuite      */
#define SECY_ADD_LOOKUP_RULE     SECY_ID_OF(0xD3U) /**< @brief #SECY_LookupRuleMsgType   #MACSEC_AddSecYLookupRule   */
#define SECY_REM_LOOKUP_RULE     SECY_ID_OF(0xD4U) /**< @brief #SECY_HdlMsgType          #MACSEC_RemoveSecYLookupRule*/
#define SECY_GET_STATS           SECY_ID_OF(0xD5U) /**< @brief #SECY_StatsMsgType        #MACSEC_GetSecYStats        */
#define SECY_SET_PROTECT         SECY_ID_OF(0xD6U) /**< @brief #SECY_DebugMsgType        #MACSEC_SetProtectFrame     */
#define SECY_SET_REPLAY_PROTECT  SECY_ID_OF(0xD7U) /**< @brief #SECY_DebugMsgType        #MACSEC_SetReplayProtect    */
#define SECY_SET_VALIDATE_FRAME  SECY_ID_OF(0xD8U) /**< @brief #SECY_DebugMsgType        #MACSEC_SetFrameValidate    */
#define SECY_ADD_LOOKUP_RULE_V2  SECY_ID_OF(0xD9U) /**< @brief #SECY_LookupRuleV2MsgType #MACSEC_AddSecYLookupRule   */
#define SECY_CREATE_V2           SECY_ID_OF(0xDAU) /**< @brief #SECY_CreateV2MsgType                                 */
#define SECY_DELETE              SECY_ID_OF(0xDFU) /**< @brief #SECY_HdlMsgType          #MACSEC_DeleteSecY          */
#define SECY_TXSC_CREATE         SECY_ID_OF(0xE0U) /**< @brief #SECY_SCMsgType           #MACSEC_CreateTxSC          */
#define SECY_RXSC_CREATE         SECY_ID_OF(0xE1U) /**< @brief #SECY_SCMsgType           #MACSEC_CreateRxSC          */
#define SECY_TXSC_GET_STATS      SECY_ID_OF(0xE2U) /**< @brief #SECY_TxSCStatsMsgType    #MACSEC_GetTxSCStats        */
#define SECY_RXSC_GET_STATS      SECY_ID_OF(0xE3U) /**< @brief #SECY_RxSCStatsMsgType    #MACSEC_GetRxSCStats        */
#define SECY_GET_FULL_STATS      SECY_ID_OF(0xE4U) /**< @brief #SECY_FullStatsMsgType                                */
#define SECY_TXSC_DEL            SECY_ID_OF(0xEEU) /**< @brief #SECY_SCMsgType           #MACSEC_DeleteTxSC          */
#define SECY_RXSC_DEL            SECY_ID_OF(0xEFU) /**< @brief #SECY_SCMsgType           #MACSEC_DeleteRxSC          */
#define SECY_TXSA_CREATE         SECY_ID_OF(0xF0U) /**< @brief #SECY_SAMsgType           #MACSEC_CreateTxSA          */
#define SECY_RXSA_CREATE         SECY_ID_OF(0xF1U) /**< @brief #SECY_SAMsgType           #MACSEC_CreateRxSA          */
#define SECY_SA_ENABLE           SECY_ID_OF(0xF2U) /**< @brief #SECY_HdlMsgType          #MACSEC_SAEnable            */
#define SECY_SA_DISABLE          SECY_ID_OF(0xF3U) /**< @brief #SECY_HdlMsgType          #MACSEC_SADisable           */
#define SECY_SA_GET_STATUS       SECY_ID_OF(0xF4U) /**< @brief #SECY_SAStatusMsgType     #MACSEC_SAGetStatus         */
#define SECY_SA_SET_PN_THRLD     SECY_ID_OF(0xF5U) /**< @brief #SECY_PNMsgType           #MACSEC_SetPNThreshold      */
#define SECY_SA_GET_NEXT_PN      SECY_ID_OF(0xF6U) /**< @brief #SECY_PNMsgType           #MACSEC_SAGetNextPN         */
#define SECY_SA_SET_NEXT_PN      SECY_ID_OF(0xF7U) /**< @brief #SECY_PNMsgType           #MACSEC_SASetNextPN         */
#define SECY_TXSA_CREATE_V2      SECY_ID_OF(0xF8U) /**< @brief #SECY_CreateSAV2MsgType                               */
#define SECY_RXSA_CREATE_V2      SECY_ID_OF(0xF9U) /**< @brief #SECY_CreateSAV2MsgType                               */
#define SECY_UPDATE_TXSA         SECY_ID_OF(0xFAU) /**< @brief #SECY_UpdateSAMsgType                                 */
#define SECY_UPDATE_RXSA         SECY_ID_OF(0xFBU) /**< @brief #SECY_UpdateSAMsgType                                 */
#define SECY_TXSA_CREATE_REQ     SECY_ID_OF(0xFCU) /**< @brief #SECY_SALocalMsgType      #MACSEC_CreateTxSA          */
#define SECY_RXSA_CREATE_REQ     SECY_ID_OF(0xFDU) /**< @brief #SECY_SALocalMsgType      #MACSEC_CreateRxSA          */
#define SECY_ACCESS_CTRL_CMDS    SECY_ID_OF(0xFEU) /**< @brief #SECY_SALocalMsgType      #                           */
#define SECY_SA_DELETE           SECY_ID_OF(0xFFU) /**< @brief #SECY_HdlMsgType          #MACSEC_DeleteSA            */
/** @} */

/**
    @name CRYPTO SECY Macros
    @{
    @brief Crypto SECY Macros

    @trace #BRCM_SWREQ_SECY
**/
#define SECY_XPN_SALT_LEN    (12UL)
#define SECY_KEY_LEN         (32UL)
#define SECY_KEYID_LEN       (16UL)
#define SECY_MSG_MAX_SIZE    (416UL)
/** @} */

/**
    @brief CRYPTO configuration type

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_HwCfgType {
    uint32_t    checkKaY;   /**< @brief Enable detection of KaY frame
                                (E bit = 1 and C bit = 0 in SecTAG).
                                If set to TRUE, these frames are marked as control
                                frame and shall be handled by KaY.
                                If set to FALSE, these frames will be marked as
                                invalid CRYPTO Tagged frame and will be dropped */
    uint32_t    enableQtagParse; /**< @brief Enable detection of 802.1Q tag
                                (802.1Q tag in clear) */
} SECY_HwCfgType;
BCM_STATIC_SIZE_ASSERT(SECY_HwCfgType, 8, SECY_MSG_MAX_SIZE);

/**
    @name SECY_ValidateFrameType
    @{
    @brief Ingress tagged frame validation options.

    These values are used for 802.1AE compliant processing Frame when no MACsec secure channel is found.
    validation options as defined in section 10.6 of IEEE Std 802.1AE-2018: Media Access Control (MAC) Security

    These options help in staged deployement of macsec in the network system
    Setting frame validation option to NULL also disables frame protection of the SecY.

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_ValidateFrameType;
#define SECY_VALIDATE_FRAME_DISABLED   (0UL) /**< @brief no validation (remove SecTAG and ICV if
                                                            present in the received frame and don't
                                                            discard the frame) */
#define SECY_VALIDATE_FRAME_CHECK      (1UL) /**< @brief check (enable check but don't discard
                                                            the invalid frames) */
#define SECY_VALIDATE_FRAME_STRICT     (2UL) /**< @brief strict check (enable validation
                                                      and discard invalid frames) */
#define SECY_VALIDATE_FRAME_NULL       (3UL) /**< @brief no processing, do not remove SecTAG or
                                                            ICV from frame */
/** @} */

/**
    @name SECY_CipherType
    @{
    @brief Crypto EUI-64 cipher id
    64-bit EUI Cipher IDs as defined by the 802.1AE specification

    @trace #BRCM_SWREQ_SECY
*/
typedef uint64_t SECY_CipherType;
#define SECY_CIPHER_GCM_AES_128         (0x0080C20001000001ULL) /**< @brief GCM AES 128 bit */
#define SECY_CIPHER_GCM_AES_256         (0x0080C20001000002ULL) /**< @brief GCM AES 256 bit */
#define SECY_CIPHER_GCM_AES_XPN_128     (0x0080C20001000003ULL) /**< @brief GCM AES XPN 128 */
#define SECY_CIPHER_GCM_AES_XPN_256     (0x0080C20001000004ULL) /**< @brief GCM AES XPN 256 */
/** @} */

/**
    @name SECY_ConfOffsetType
    @{
    @brief Confidentiality offset
    Confidentiality offsets supported by the cipher suite (bit mask values)

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_ConfOffsetType;
#define SECY_CONF_OFFSET_0             (0U)   /**< @brief confidentiality offset 0 */
#define SECY_CONF_OFFSET_30            (1U)   /**< @brief confidentiality offset 30 */
#define SECY_CONF_OFFSET_50            (2U)   /**< @brief confidentiality offset 50 */
/** @} */

/**
    @name SECY_CipherCapType
    @{
    @brief Cipher capabilites types

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_CipherCapType;
#define SECY_CIPHER_CAP_INTEGRITY          (1UL) /**< @brief integrity protection without confidentiality */
#define SECY_CIPHER_CAP_CONFIDENTIALITY    (2UL) /**< @brief integrity with confidentiality */
#define SECY_CIPHER_CAP_CONF_OFFSET        (3UL) /**< @brief integrity with confidentiality offset */
/** @} */

/**
    @name SECY_RuleDirType
    @{
    @brief SECY_RuleDirType
    Control packet rule direction (egress/ingress)

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_RuleDirType;
#define SECY_RULE_DIR_EGRESS       (1U)     /**< @brief Add the rule only for egress direction */
#define SECY_RULE_DIR_INGRESS      (2U)     /**< @brief Add the rule only for ingress direction */
#define SECY_RULE_DIR_BOTH         (3U)     /**< @brief Apply the rule in both the directions */
/** @} */

/**
    @name SECY_RuleMatchType
    @{
    @brief SECY_RuleMatchType
    Packet classification rule match mask. Based on the match type,
    respective fields in the MACSEC_RuleOpt0 fields are used

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_RuleMatchType;
#define SECY_RULE_MATCH_DA_ONLY             (1UL)   /**< @brief Match only DA value
                                                            (#SECY_RuleOpt0Type.macDAStart) */
#define SECY_RULE_MATCH_ETHTYPE_ONLY        (2UL)   /**< @brief match only ethtype in
                                                            (#SECY_RuleOpt0Type.ethType) */
#define SECY_RULE_MATCH_DA_ETHTYPE          (3UL)   /**< @brief Matching both DA and EthType maynot be supported
                                                                on all platform. Same functionality can be achieved
                                                                through the CPRuleOpt1 (refer #sSECY_RuleOpt1Type) */
#define SECY_RULE_MATCH_DA_RANGE_ONLY       (4UL)   /**< @brief match DA range value
                                                             (match is when macDAStart <= MAC_DA <=
                                                              macDAEnd) */
#define SECY_RULE_MATCH_DA_RANGE_ETHTYPE    (5UL)   /**< @brief match DA range and ethType
                                                            (match is when macDAStart <= MAC_DA <=
                                                            macDAEnd & ethertype) */
#define SECY_RULE_MATCH_DA_CONST            (6UL)  /**< @brief match DA const value in
                                                                #SECY_RuleOpt0Type.macDAStart.
                                                                Match happens on 48-bits of the DA. */
/** @} */

/**
    @name SECY_HandleMaskType
    @{
    @brief Handle masks and shifts
    @trace #BRCM_SWREQ_SECY
*/
typedef uint64_t SECY_HandleType;
#define SECY_HANDLE_HASH_SHIFT        (48UL)
#define SECY_HANDLE_HASH_MASK         (0xFFFFULL << SECY_HANDLE_HASH_SHIFT)
#define SECY_HANDLE_SEED_SHIFT        (42UL)
#define SECY_HANDLE_SEED_MASK         (0x1FULL << SECY_HANDLE_SEED_SHIFT)
#define SECY_HANDLE_HWID_SHIFT        (37UL)
#define SECY_HANDLE_HWID_MASK         (0x1FULL << SECY_HANDLE_HWID_SHIFT)
#define SECY_HANDLE_SECYID_SHIFT      (32UL)
#define SECY_HANDLE_SECYID_MASK       (0x1FULL << SECY_HANDLE_SECYID_SHIFT)
#define SECY_HANDLE_AN_SHIFT          (26UL)
#define SECY_HANDLE_AN_MASK           (0x3ULL << SECY_HANDLE_AN_SHIFT)
#define SECY_HANDLE_SCID_SHIFT        (21UL)
#define SECY_HANDLE_SCID_MASK         (0x1FULL << SECY_HANDLE_SCID_SHIFT)
#define SECY_HANDLE_SAID_SHIFT        (16UL)
#define SECY_HANDLE_SAID_MASK         (0x1FULL << SECY_HANDLE_SAID_SHIFT)
#define SECY_HANDLE_RULEID_SHIFT      (8UL)
#define SECY_HANDLE_RULEID_MASK       (0xFFULL << SECY_HANDLE_RULEID_SHIFT)
#define SECY_HANDLE_RULEID_EGRESS_SHIFT (8UL)
#define SECY_HANDLE_RULEID_EGRESS_MASK   (0xFULL << SECY_HANDLE_RULEID_EGRESS_SHIFT)
#define SECY_HANDLE_RULEID_INGRESS_SHIFT (12UL)
#define SECY_HANDLE_RULEID_INGRESS_MASK   (0xFULL << SECY_HANDLE_RULEID_INGRESS_SHIFT)
#define SECY_HANDLE_RULEMATCH_SHIFT   (4UL)
#define SECY_HANDLE_RULEMATCH_MASK    (0xFULL << SECY_HANDLE_RULEMATCH_SHIFT)
#define SECY_HANDLE_RULE_TYPE_SHIFT   (2UL)
#define SECY_HANDLE_RULE_TYPE_MASK    (0x3ULL << SECY_HANDLE_RULE_TYPE_SHIFT)
#define SECY_HANDLE_DIR_SHIFT         (0UL)
#define SECY_HANDLE_DIR_MASK          (0x3ULL << SECY_HANDLE_DIR_SHIFT)
#define SECY_HANDLE_CRC16_POLY        (0x8005U)
#define SECY_HANDLE_TO_PORT(aHandle)  ((aHandle & SECY_HANDLE_HWID_MASK) >> SECY_HANDLE_HWID_SHIFT)
/** @} */

/**
    @name SECY_BusType
    @{
    @brief SECY Bus access Type
    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_BusType;
#define SECY_BUS_MODE_UNDEFINED     (0UL)
#define SECY_BUS_MODE_AXI           (1UL)
#define SECY_BUS_MODE_MDIO          (2UL)
/** @} */

/**
    @brief SCI type

    CRYPTO Secure channel identifier consist of 6-bytes of the
    source mac address and 16-bit of port identifier.

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_SCIType {
    uint8_t macAddr[6UL];
    uint16_t portNum;
} SECY_SCIType;
BCM_STATIC_SIZE_ASSERT(SECY_SCIType, 8, SECY_MSG_MAX_SIZE);

/**
    @brief CRYPTO key type

    MACSec key provided by client during the SA creation. If SecY entity
    is using extended packet number (#SECY_CfgType.xpnEnable is set to true),
    client shall fill 16-bytes of the salt value.
    keyId field is 12-bytes which is associated with specific key and  returned
    while querying the current status of the SA (#SECY_SAStatusType).

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_KeyType {
    uint8_t         sak[SECY_KEY_LEN];        /**< @brief CRYPTO key buffer */
    uint8_t         salt[SECY_XPN_SALT_LEN];  /**< @brief Salt for XPN key
                                                          If XPN cipher is not used
                                                          this parameter shall be set to 0 */
    uint8_t         keyId[SECY_KEYID_LEN];    /**< @brief key identified as defined by 802.1X */
} SECY_KeyType;
BCM_STATIC_SIZE_ASSERT(SECY_KeyType, 60, SECY_MSG_MAX_SIZE);

/**
    @brief CRYPTO rule option 0 type

    This structure defines the control packet rule.
    Based on the ruleMask (#SECY_RuleMatchType), respective fields
    of this structures are matched to classify a packet as control packet.
    When a packet is classified as control packet, it will bypass the encryption/decryption
    engine.

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_RuleOpt0Type {
    SECY_RuleMatchType    ruleMask;       /**< @brief rule match mask */
    uint8_t               macDAStart[6U]; /**< @brief MAC DA to start to match */
    uint8_t               macDAEnd[6U];   /**< @brief MAC DA end to match */
    SECY_RuleDirType      dir;            /**< @brief direction in which rule shall be applied */
    uint16_t              ethType;        /**< @brief Ethertype to match */
    uint8_t               rsvd[2U];
} SECY_RuleOpt0Type;
BCM_STATIC_SIZE_ASSERT(SECY_RuleOpt0Type, 24, SECY_MSG_MAX_SIZE);

/**
    @brief CRYPTO rule option 1 type

    This structure defines the rule for the packet classification.
    Lookup rule consist of key, data and corresponding key mask and data masks.
    Mask fields can be used to mask out the bits which doesn't need to be compared in the
    key/data fields. For example, if matchMacDAMask is set to {0xFF, 0xFF, 0, 0, 0, 0}, then
    macDA[0] and macDA[1] fields are usedfor comparison.

    frameData field shall be in below format; consider the below frame:
    data = {
    0x84, 0xC5, 0xD5, 0x13, 0xD2, 0xAA,
    0xF6, 0xE5, 0xBB, 0xD2, 0x72, 0x77,
    0x08, 0x00, 0x0F, 0x10, 0x11, 0x12 ... }

    To match only first 32-bit of data:
    frameData[0] = data[12] | data[13] << 8 | data[14] << 16 | data[15] << 24
    matchFrameDataMask[0] = 0xFFFFFFFF

    To match next 24-bit of data also:
    frameData[1] = data[16] | data[17] << 8 | data[18) << 16
    matchFrameDataMask[1] = 0xFFFFFF

    If macSecTagged is set to TRUE, engine will check if the packet has SecTag (along with other
    rule parameters). Note that setting this to TRUE during the control frame rule addition
    will cause MACSec tagged frame to bypass the encryption/decryption (and it is not recommended!!).
    This flag can be set to TRUE during SecY lookup rule addition.

    If vlanTagged is set to TRUE, packets will be checked if they are vlan tagged (for this
    feature to work, Vlan tag parsing must be enabled in the hardware:
    #SECY_HwCfgType.enableQTagParse shall be set to TRUE). As hardware already parsed the VLAN
    etherType (0x8100) so we can skip passing this.
    Frame field shall be in below format:

    VLAN Tagged data = {
    0x84, 0xC5, 0xD5, 0x13, 0xD2, 0xAA,
    0xF6, 0xE5, 0xBB, 0xD2, 0x72, 0x77,
    0x81, 0x00, 0x0F, 0x10, 0x11, 0x12
    0x13, 0x14  ... }

    To match only first 32-bit of data:
    frameData[0] = data[14] | data[15] << 8 | data[16] << 16 | data[17] << 24
    matchFrameDataMask[0] = 0xFFFFFFFF

    To match next 24-bit of data also:
    frameData[1] = data[18] | data[19] << 8 | data[20) << 16
    matchFrameDataMask[1] = 0xFFFFFF

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_RuleOpt1Type {
    uint8_t                 macDA[6U];          /**< @brief MAC DA to match (Only bits which are set
                                                    in matchDAMask are matched) */
    uint8_t                 macSA[6U];          /**< @brief MAC SA to match (only bits which are set
                                                    in matchSAMask are matched) */
    uint32_t                frameData[2U];      /**< @brief frame data after SA to match (only 56
                                                    bits out of 64-bit are compared:
                                                    frameData[31:0], followed by frameData[23:0].
                                                    Only bits which are set in the
                                                    matchFrameDataMask are matched) */
    uint32_t                macSecTagged;       /**< @brief TRUE: check SecTAG detection */
    uint32_t                vlanTagged;         /**< @brief TRUE: detect 802.1Q tagged packet  */
    uint8_t                 matchMacDAMask[6U]; /**< @brief MAC DA mask bits */
    uint8_t                 matchMacSAMask[6U]; /**< @brief MAC SA mask bits */
    uint32_t                matchFrameDataMask[2U]; /**< @brief Frame data mask bits */
    SECY_RuleDirType  dir;                    /**< @brief Rule direction */
} SECY_RuleOpt1Type;
BCM_STATIC_SIZE_ASSERT(SECY_RuleOpt1Type,52, SECY_MSG_MAX_SIZE);

/**
    @brief SecY configuration
    This structure defines the SecY configuration.

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_CfgType {
    uint32_t        xpnEnable;          /**< @brief TRUE: Enable XPN support for this SecY */
    uint32_t        includeSCI;         /**< @brief TRUE: include explicit SCI in transmit frame
                                                    FALSE: don't encode SCI in the SecTAG in
                                                    transmit frames.
                                                    if this field is set to FALSE, it's assumed that
                                                    its point-to-point connection with peer SecY
                                                    (this SecY will can receive from at most one
                                                    peer SecY and only one receive secure channel
                                                    can be created for this SecY). */
    uint8_t         preSecTagAuthStart; /**< @brief Pre-SecTAG Authentication Start.
                                                    Specifies number of bytes from the start of
                                                    the frame to be bypassed without
                                                    CRYPTO protection. */
    uint8_t         preSecTagAuthLen; /**< @brief Pre-SecTAG Authentication Length.
                                                  Specifies number of bytes to be authenticated in
                                                  the pre-SecTAG area. For 802.1AE compliance,
                                                  this value must be set to 12 Bytes, representing
                                                  the length of the MAC SA/DA fields. */
    uint8_t         secTagOffset;     /**< @brief Offset of the SecTAG (location relative to start
                                                  of the frame). For normal operations, this shall be
                                                  set to 12. In case of VLAN in clear (802.1Q tag
                                                  in clear text, this field shall be programmed with
                                                  16 (6 bytes MAC DA + 6 bytes MAC SA + 4 bytes for
                                                  802.1Q tag)) */
    uint8_t         rsvd;
} SECY_CfgType;
BCM_STATIC_SIZE_ASSERT(SECY_CfgType, 12, SECY_MSG_MAX_SIZE);

/**
    @brief  SA status type

    SA status type

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_SAStatusType {
    uint32_t        inUse;              /**< @brief true: SA is use, false: SA not in use */
    uint32_t        ssci;               /**< @brief SSCI value for this SA */
    uint32_t        createdTime;        /**< @brief Time when this SA was created */
    uint32_t        startedTime;        /**< @brief Time when this SA became active */
    uint32_t        stoppedTime;        /**< @brief Time when this SA was stopped */
    uint8_t         keyID[16UL];        /**< @brief SA Key identifier */
} SECY_SAStatusType;
BCM_STATIC_SIZE_ASSERT(SECY_SAStatusType, 36, SECY_MSG_MAX_SIZE);

/**
    @brief SECY_TxSCStatsType

    Transmit Secure channel statistics type

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_TxSCStatsType {
    uint64_t outPktsProtected;      /**< @brief number of packets protected */
    uint64_t outPktsEncrypted;      /**< @brief number of packets encrypted */
} SECY_TxSCStatsType;
BCM_STATIC_SIZE_ASSERT(SECY_TxSCStatsType, 16, SECY_MSG_MAX_SIZE);

/**
    @brief SECY_RxSCStatsType

    Receive secure channel statistics

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_RxSCStatsType {
    uint64_t inPktsLate;           /**< @brief replayProtect is enabled and recv_frame(pn) <
                                               sa->nextPN */
    uint64_t inPktsNotValid;       /**< @brief recv frame is not valid and validateFrames is Strict
                                               or C-bit is set in SecTAG */
    uint64_t inPktsInvalid;        /**< @brief recv frame is not valid and validaFrame is Check */
    uint64_t inPktsDelayed;        /**< @brief recv_frame(pn) < sa->nextPn */
    uint64_t inPktsUnchecked;      /**< @brief recv frame is not valid and
                                               validateFrame == Disabled */
    uint64_t inPktsOK;             /**< @brief packet is valid and recv_frame(pn) > sa->nextPN */
} SECY_RxSCStatsType;
BCM_STATIC_SIZE_ASSERT(SECY_RxSCStatsType, 48, SECY_MSG_MAX_SIZE);

/**
    @brief SecY statistics

    Statistics counters for SecY entity

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_StatsType {
    uint64_t outPktsUntagged;      /**< @brief number of packet which are not protected
                                               (protectFrames == False) */
    uint64_t outPktsTooLong;       /**< @brief number of protected frames (protectFrame == True) whose
                                               length if more than maximum allowed frame length on
                                               interface */
    uint64_t inPktsUntagged;       /**< @brief received frame has no SecTAG and
                                               (validateFrame != Strict) */
    uint64_t inPktsNoTag;          /**< @brief received frame has no SecTAG and
                                               (validateFrame == Strict) */
    uint64_t inPktsBadTag;         /**< @brief received frame has invalid tag or invalid ICV */
    uint64_t inPktsOverrun;        /**< @brief received frame queued for validation but exceeds
                                               selected cipher suite capabilities */
    uint64_t inPktsNoSA;           /**< @brief no active SA is found for this frame and
                                               (validateFrame != Strict) */
    uint64_t inPktsNoSAError;      /**< @brief no active SA is found for this frame and
                                               (validateFrame == Strict) or C-bit == 1 in SecTAG */
    uint64_t outOctetsProtected;   /**< @brief number of octets of user data in tx frame which were
                                               integrity protected but not encrypted */
    uint64_t outOctetsEncrypted;   /**< @brief number of octets of user data in tx frame which were
                                               integrity protected and encrypted */
    uint64_t inOctetsValidated;     /**< @brief Number of octets of User Data recovered from
                                                received frames that were integrity protected but
                                                not encrypted */
    uint64_t inOctetsDecrypted;     /**< @brief Number of octets of User Data recovered from
                                                received frames that were both integrity protected
                                                and encrypted both */
} SECY_StatsType;
BCM_STATIC_SIZE_ASSERT(SECY_StatsType, 96, SECY_MSG_MAX_SIZE);


/**
    @brief SecY HW Init Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_HwInitMsgType {
    uint32_t                   port;           /**< @brief Input: Port Number      */
    SECY_HwCfgType             cfg;            /**< #brief Input: Configuration    */
} SECY_HwInitMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_HwInitMsgType, 12, SECY_MSG_MAX_SIZE);

/**
    @brief SecY HW Deinit Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_HwDeinitMsgType {
    uint32_t        port;                   /**< @brief Input: Port Number      */
} SECY_HwDeinitMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_HwDeinitMsgType, 4, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Rule Option 0 Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_RuleOpt0MsgType {
    uint32_t                    port;               /**< @brief Input: Port Number      */
    SECY_RuleOpt0Type           rule;               /**< @brief Input: Filtering Rule   */
    uint32_t                    rsvd1;
    BCM_HandleType              ruleHdl;            /**< @brief Output: Rule Handle     */
} SECY_RuleOpt0MsgType;
BCM_STATIC_SIZE_ASSERT(SECY_RuleOpt0MsgType, 40, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Rule Option 1 Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_RuleOpt1MsgType {
    uint32_t                    port;       /**< @brief Input: Port Number      */
    SECY_RuleOpt1Type           rule;       /**< @brief Input: Filtering Rule      */
    BCM_HandleType              ruleHdl;    /**< @brief Output: Rule Handle      */
} SECY_RuleOpt1MsgType;
BCM_STATIC_SIZE_ASSERT(SECY_RuleOpt1MsgType, 64, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Create Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_CreateMsgType {
    uint32_t            port;           /**< @brief Input: Port Number      */
    SECY_CfgType        cfg;            /**< @brief Input: SecY Config      */
    BCM_HandleType      secYHdl;        /**< @brief Output: SecY Handle      */
} SECY_CreateMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_CreateMsgType, 24, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Get Cipher Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_GetCipherMsgType {
    uint32_t                    port;       /**< @brief Input: Port Number      */
    SECY_CipherCapType          cap;        /**< @brief Output: Cipher Cap      */
    SECY_CipherType             cipher;     /**< @brief Input: Cipher Type      */
} SECY_GetCipherMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_GetCipherMsgType, 16, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Set Cipher Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_SetCipherMsgType {
    BCM_HandleType              secYHdl;    /**< @brief Input: SecY Handle      */
    SECY_CipherType             cipher;     /**< @brief Input: Cipher Type      */
    SECY_ConfOffsetType         offset;     /**< @brief Input: Confidentiality Offset   */
    uint32_t                    rsvd;

} SECY_SetCipherMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_SetCipherMsgType, 24, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Create/Delete SC Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_SCMsgType {
    BCM_HandleType          secYHdl;        /**< @brief Input: SecY Handle      */
    SECY_SCIType            sci;            /**< @brief Input: SCI              */
} SECY_SCMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_SCMsgType, 16, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Lookup Rule Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_LookupRuleMsgType {
    BCM_HandleType              secYHdl;    /**< @brief Input: SecY Handle      */
    SECY_RuleOpt1Type           rule;       /**< @brief Input: Filtering Rule   */
    BCM_HandleType              ruleHdl;    /**< @brief Output: Rule Handle      */
} SECY_LookupRuleMsgType;

/**
    @brief SecY Lookup Rule Message Version 2

    Byte boundary is packed for 8byte.

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_LookupRuleV2MsgType {
    BCM_HandleType              secYHdl;    /**< @brief Input: SecY Handle      */
    SECY_RuleOpt1Type           rule;       /**< @brief Input: Filtering Rule   */
    uint32_t                    rsvd;       /**< @brief reserved                */
    BCM_HandleType              ruleHdl;    /**< @brief Output: Rule Handle     */
} SECY_LookupRuleV2MsgType;
BCM_STATIC_SIZE_ASSERT(SECY_LookupRuleV2MsgType, 72, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Create SA Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_SAMsgType {
    BCM_HandleType          secYHdl;        /**< @brief Input: SecY Handle      */
    uint64_t                pn;             /**< @brief Input: next PN for TxSA and lowest PN for RxSA */
    uint32_t                association;    /**< @brief Input: Association Number*/
    uint32_t                ssci;           /**< @brief Input: SSCI             */
    uint32_t                confidentiality;/**< @brief TRUE:  Enable confidentiality protection of user data
                                                        FALSE: Disable confidentiality protection of user data
                                                        (Not used in Rx SA creation)*/
    SECY_SCIType            sci;            /**< @brief Input: SCI              */
    SECY_KeyType            sak;            /**< @brief Input: SA Key           */
    BCM_HandleType          saHdl;          /**< @brief Output: SA Handle       */
} SECY_SAMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_SAMsgType, 104, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Create SA Extension Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_SALocalMsgType {
    BCM_HandleType          secYHdl;        /**< @brief Input: SecY Handle      */
    uint64_t                pn;             /**< @brief Input: next PN for TxSA and lowest PN for RxSA */
    uint32_t                association;    /**< @brief Input: Association Number*/
    uint32_t                ssci;           /**< @brief Input: SSCI             */
    uint32_t                confidentiality;/**< @brief TRUE:  Enable confidentiality protection of user data
                                                        FALSE: Disable confidentiality protection of user data
                                                        (Not used in Rx SA creation)*/
    SECY_SCIType            sci;            /**< @brief Input: SCI              */
    SECY_KeyType            sak;            /**< @brief Input: SA Key           */
    BCM_HandleType          keyHdl;         /**< @brief Input: SAK Key Handle   */
    BCM_HandleType          saHdl;          /**< @brief Output: SA Handle       */
} SECY_SALocalMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_SALocalMsgType, 112, SECY_MSG_MAX_SIZE);

/**
    @brief SecY PN Set/Get/Threshold Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_PNMsgType {
    BCM_HandleType  saHdl;  /**< @brief Input: SA Handle      */
    uint64_t        pn;     /**< @brief Input: PN Threshold for #SECY_SA_SET_PN_THRLD
                                    <br>Input: Next PN for #SECY_SA_SET_NEXT_PN
                                    <br>Output: Next PN for #SECY_SA_GET_NEXT_PN  */
} SECY_PNMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_PNMsgType, 16, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Message for
        -# Enable/Disabe SA
        -# Delete SA
        -# Delete CP Rule
        -# Delete Lookup Rule

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_HdlMsgType {
    uint32_t            port;       /**< @brief Input: port number needed only for CP Rule removal  */
    uint32_t            rsvd1;
    BCM_HandleType      hdl;        /**< @brief Input: SA/Rule Handle      */
} SECY_HdlMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_HdlMsgType, 16, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Debug Message (for protect/replay protect/validate)

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_DebugMsgType {
    BCM_HandleType                  secYHdl;            /**< @brief Input: SecY Handle      */
    uint32_t                        protectEnable;      /**< @brief Input: used only for #SECY_SET_PROTECT    */
    uint32_t                        replayProtectEnable;/**< @brief Input: used only for #SECY_SET_REPLAY_PROTECT    */
    uint32_t                        replayProtectWindow;/**< @brief Input: used only for #SECY_SET_REPLAY_PROTECT    */
    SECY_ValidateFrameType          validate;           /**< @brief Input: used only for #SECY_SET_VALIDATE_FRAME    */
} SECY_DebugMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_DebugMsgType, 24, SECY_MSG_MAX_SIZE);

/**
    @brief SecY SA status query message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_SAStatusMsgType {
    BCM_HandleType          saHdl;  /**< @brief Input: SA Handle        */
    SECY_SAStatusType       status; /**< @brief Output: SA Status       */
    uint32_t                rsvd;
} SECY_SAStatusMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_SAStatusMsgType, 48, SECY_MSG_MAX_SIZE);


/**
    @brief SecY Stats query message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_StatsMsgType {
    BCM_HandleType          secYHdl;    /**< @brief Input: SecY Handle      */
    SECY_StatsType          stats;      /**< @brief Output: SecY Stats      */
} SECY_StatsMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_StatsMsgType, 104, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Tx SC Stats query message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_TxSCStatsMsgType {
    BCM_HandleType              secYHdl;    /**< @brief Input: SecY Handle      */
    SECY_SCIType                sci;        /**< @brief Input: SCI              */
    SECY_TxSCStatsType          stats;      /**< @brief Output: SCI Stats       */
} SECY_TxSCStatsMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_TxSCStatsMsgType, 32, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Rx SC Stats query message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_RxSCStatsMsgType {
    BCM_HandleType              secYHdl;    /**< @brief Input: SecY Handle      */
    SECY_SCIType                sci;        /**< @brief Input: SCI              */
    SECY_RxSCStatsType          stats;      /**< @brief Output: SCI Stats       */
} SECY_RxSCStatsMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_RxSCStatsMsgType, 64, SECY_MSG_MAX_SIZE);

/**
    @brief SecY configuration

    Configuration to create SecY, set Ciper suite, create TxSC, set reply protect,
    and validate Frame

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_CreateV2Type {
    uint32_t               port;                /**< @brief Port Number            */
    SECY_CfgType           cfg;                 /**< @brief SecY Config            */
    SECY_CipherType        cipher;              /**< @brief Cipher Type            */
    SECY_ConfOffsetType    offset;              /**< @brief Confidentiality Offset */
    SECY_SCIType           sci;                 /**< @brief SCI to create TxSC     */
    uint32_t               replayProtectEnable; /**< @brief Enable Replay protect  */
    uint32_t               replayProtectWindow; /**< @brief Replay protect window  */
    SECY_ValidateFrameType validate;            /**< @brief Validate Frame         */
} SECY_CreateV2Type;
BCM_STATIC_SIZE_ASSERT(SECY_CreateV2Type, 48, SECY_MSG_MAX_SIZE);

/**
    @brief SecY configuration message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_CreateV2MsgType {
    SECY_CreateV2Type     create;        /**< @brief Input: SecY create parameters */
    BCM_HandleType        secYHdl;       /**< @brief Output: SecY Handle           */
} SECY_CreateV2MsgType;
BCM_STATIC_SIZE_ASSERT(SECY_CreateV2MsgType, 56, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Add SA

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_CreateSAV2MsgType {
    BCM_HandleType          secYHdl;        /**< @brief Input: SecY Handle      */
    uint64_t                pn;             /**< @brief Input: next PN for TxSA and lowest PN for RxSA */
    uint32_t                an;             /**< @brief Input: Association Number  */
    uint32_t                ssci;           /**< @brief Input: SSCI                */
    uint32_t                confidentiality;/**< @brief Not used in Rx SA creation */
    SECY_SCIType            sci;            /**< @brief Input: SCI                 */
    SECY_KeyType            sak;            /**< @brief Input: SA Key              */
    BCM_BoolType            enable;         /**< @brief Input: Enable/Disable SA   */
    uint32_t                rsvd;
    BCM_HandleType          saHdl;          /**< @brief Output: SA Handle          */
} SECY_CreateSAV2MsgType;
BCM_STATIC_SIZE_ASSERT(SECY_CreateSAV2MsgType, 112, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Update SA

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_UpdateSAMsgType {
    BCM_HandleType  saHdl;  /**< @brief Input: SA Handle           */
    uint64_t        pn;     /**< @brief Input: next PN for TxSA
                                            and lowest PN for RxSA */
    BCM_BoolType    enable; /**< @brief Input: Enable/Disable SA   */
    uint32_t          rsvd;
} SECY_UpdateSAMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_UpdateSAMsgType, 24, SECY_MSG_MAX_SIZE);

/**
    @brief SecY all statistics

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_AllStatsType {
    SECY_StatsType          secy;       /**< @brief Output: SecY Stats        */
    SECY_TxSCStatsType      txsc;       /**< @brief Output: Tx SCI Stats      */
    SECY_RxSCStatsType      rxsc[5UL];  /**< @brief Output: Rx SCI Stats      */
} SECY_AllStatsType;
BCM_STATIC_SIZE_ASSERT(SECY_AllStatsType, 352, SECY_MSG_MAX_SIZE);

/**
    @brief SecY get stats

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_FullStatsMsgType {
    BCM_HandleType          secYHdl;         /**< @brief Input: SecY Handle            */
    SECY_SCIType            txSci;           /**< @brief Input: SCI for TxSC           */
    SECY_SCIType            rxSci[5UL];      /**< @brief Input: SCI for RxSC           */
    uint32_t                rxSciCount;      /**< @brief Input: No of SCI for RxSC     */
    uint32_t                rsvd;
    SECY_AllStatsType       stats;           /**< @brief Output: SecY, Tx and Rx Stats */
} SECY_FullStatsMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_FullStatsMsgType, 416, SECY_MSG_MAX_SIZE);



/**
    @brief SecY Get Port Status

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_HwStatusType;
#define SECY_HW_STATUS_SECURED_SHIFT          (0x0UL)
#define SECY_HW_STATUS_SECURED_MASK           (0x1UL << SECY_HW_STATUS_SECURED_SHIFT)
#define SECY_HW_STATUS_CONFIDENTIALITY_SHIFT  (0x1UL)
#define SECY_HW_STATUS_CONFIDENTIALITY_MASK   (0x1UL << SECY_HW_STATUS_CONFIDENTIALITY_SHIFT)
#define SECY_HW_STATUS_OPERATIONAL_SHIFT      (0x2UL)
#define SECY_HW_STATUS_OPERATIONAL_MASK       (0x1UL << SECY_HW_STATUS_OPERATIONAL_SHIFT)

/**
    @brief SecY Get Port Status

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_PortStatusType {
    SECY_CipherType    cipher;               /**< @brief Cipher Suit Info */
    SECY_HwStatusType  hwStatus;             /**< @brief Secy Hardware status
                                                         SECURED : Allowed only Tag Packet
                                                         CONFIDENTIALITY : Data Encription is Enabled
                                                         OPERATIONAL : Control Port is Enabled */
    uint32_t           rsvd[5];
} SECY_PortStatusType;
BCM_STATIC_SIZE_ASSERT(SECY_PortStatusType, 32, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Get Port Status Message

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_StatusMsgType {
    uint32_t                port;             /**< @brief Input: Port Number             */
    uint32_t                rsvd;
    SECY_PortStatusType     portStatus;       /**< @brief Output: Port Status            */
} SECY_StatusMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_StatusMsgType, 40, SECY_MSG_MAX_SIZE);

#endif /* CRYPTO_SECY_TYPES_H */

/** @} */
