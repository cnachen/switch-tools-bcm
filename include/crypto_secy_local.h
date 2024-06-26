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
    @defgroup grp_crypto_secy_local_ifc SecY Local Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_secy_local_ifc
    @{

    @limitations None

    @file crypto_secy_local.h
    @brief Crypto MAC Security Entity (MACSEC) Interface
    This header file contains the interface functions for Crypto MAC Security Entity (MACSEC)

    @version 1.0 Initial Version
*/

#ifndef CRYPTO_SECY_LOCAL_H
#define CRYPTO_SECY_LOCAL_H

#include <crypto_common.h>
#include <crypto_secy_types.h>
#include <bcm_comp.h>
#include <bcm_err.h>
#include <bcm_utils.h>
#include <crypto_memory.h>

/**
    @name Crypto SecY Architecture IDs
    @{
    @brief Architecture IDs for Crypto SecY
*/

#define BRCM_SWARCH_SECY_REQ_INIT_PROC                   (0x8704U) /**< @brief #SECY_InitReq                 */
#define BRCM_SWARCH_SECY_REQ_ADDCPRULEOPT0_PROC          (0x8705U) /**< @brief #SECY_AddCPRuleOpt0Req        */
#define BRCM_SWARCH_SECY_REQ_ADDCPRULEOPT1_PROC          (0x8706U) /**< @brief #SECY_AddCPRuleOpt1Req        */
#define BRCM_SWARCH_SECY_REQ_REMOVECPRULE_PROC           (0x8707U) /**< @brief #SECY_RemoveCPRuleReq         */
#define BRCM_SWARCH_SECY_REQ_DEINIT_PROC                 (0x8708U) /**< @brief #SECY_DeinitReq               */
#define BRCM_SWARCH_SECY_REQ_CREATESECY_PROC             (0x8709U) /**< @brief #SECY_CreateSecyReq           */
#define BRCM_SWARCH_SECY_REQ_GETCIPHERCAP_PROC           (0x870AU) /**< @brief #SECY_GetCipherCapReq         */
#define BRCM_SWARCH_SECY_REQ_SETCIPHERSUITE_PROC         (0x870BU) /**< @brief #SECY_SetCipherSuiteReq       */
#define BRCM_SWARCH_SECY_REQ_ADDSECYLOOKUPRULE_PROC      (0x870CU) /**< @brief #SECY_AddSecYLookupRuleReq    */
#define BRCM_SWARCH_SECY_REQ_REMOVESECYLOOKUPRULE_PROC   (0x870DU) /**< @brief #SECY_RemoveSecYLookupRuleReq */
#define BRCM_SWARCH_SECY_REQ_GETSTATS_PROC               (0x870EU) /**< @brief #SECY_GetStatsReq             */
#define BRCM_SWARCH_SECY_REQ_SETPROTECTFRAME_PROC        (0x870FU) /**< @brief #SECY_SetProtectFrameReq      */
#define BRCM_SWARCH_SECY_REQ_SETREPLAYPROTECT_PROC       (0x8710U) /**< @brief #SECY_SetReplayProtectReq     */
#define BRCM_SWARCH_SECY_REQ_SETFRAMEVALIDATE_PROC       (0x8711U) /**< @brief #SECY_SetFrameValidateReq     */
#define BRCM_SWARCH_SECY_REQ_DELETESECY_PROC             (0x8712U) /**< @brief #SECY_DeleteSecYReq           */
#define BRCM_SWARCH_SECY_REQ_CREATETXSC_PROC             (0x8713U) /**< @brief #SECY_CreateTxSCReq           */
#define BRCM_SWARCH_SECY_REQ_CREATERXSC_PROC             (0x8714U) /**< @brief #SECY_CreateRxSCReq           */
#define BRCM_SWARCH_SECY_REQ_GETTXSCSTATS_PROC           (0x8715U) /**< @brief #SECY_GetTxSCStatsReq         */
#define BRCM_SWARCH_SECY_REQ_GETRXSCSTATS_PROC           (0x8716U) /**< @brief #SECY_GetRxSCStatsReq         */
#define BRCM_SWARCH_SECY_REQ_DELETETXSC_PROC             (0x8717U) /**< @brief #SECY_DeleteTxSCReq           */
#define BRCM_SWARCH_SECY_REQ_DELETERXSC_PROC             (0x8718U) /**< @brief #SECY_DeleteRxSCReq           */
#define BRCM_SWARCH_SECY_REQ_CREATETXSA_PROC             (0x8719U) /**< @brief #SECY_CreateTxSAReq           */
#define BRCM_SWARCH_SECY_REQ_CREATERXSA_PROC             (0x871AU) /**< @brief #SECY_CreateRxSAReq           */
#define BRCM_SWARCH_SECY_REQ_ENABLESA_PROC               (0x871BU) /**< @brief #SECY_EnableSAReq             */
#define BRCM_SWARCH_SECY_REQ_DISABLESA_PROC              (0x871CU) /**< @brief #SECY_DisableSAReq            */
#define BRCM_SWARCH_SECY_REQ_GETSASTATUS_PROC            (0x871DU) /**< @brief #SECY_GetSAStatusReq          */
#define BRCM_SWARCH_SECY_REQ_SETPNTHRESHOLD_PROC         (0x871EU) /**< @brief #SECY_SetPNThresholdReq       */
#define BRCM_SWARCH_SECY_REQ_GETSANEXTPN_PROC            (0x871FU) /**< @brief #SECY_GetSANextPNReq          */
#define BRCM_SWARCH_SECY_REQ_SETSANEXTPN_PROC            (0x8720U) /**< @brief #SECY_SetSANextPNReq          */
#define BRCM_SWARCH_SECY_REQ_DELETESA_PROC               (0x8721U) /**< @brief #SECY_DeleteSAReq             */
#define BRCM_SWARCH_SECY_REQ_UPDATETXSA_PROC             (0x8725U) /**< @brief #SECY_UpdateTxSAReq           */
#define BRCM_SWARCH_SECY_REQ_UPDATERXSA_PROC             (0x8726U) /**< @brief #SECY_UpdateRxSAReq           */
#define BRCM_SWARCH_SECY_REQ_GETFULLSTATUS_PROC          (0x8727U) /**< @brief #SECY_GetFullStatsReq         */
#define BRCM_SWARCH_SECY_REQ_GET_STATUS_PROC             (0x8728U) /**< @brief #SECY_GetStatusReq            */
#define BRCM_SWARCH_SECY_REQ_EN_CTRL_PORT_PROC           (0x8729U) /**< @brief #SECY_EnableControlledPortReq */
#define BRCM_SWARCH_SECY_REQ_DIS_CTRL_PORT_PROC          (0x872AU) /**< @brief #SECY_DisableControlledPortReq*/
#define BRCM_SWARCH_SECY_REQ_SET_ACCESS_CTRL_PROC        (0x872BU) /**< @brief #SECY_SetAccessCtrlReq        */
#define BRCM_SWARCH_SECY_REQ_GET_PORT_STATUS_PROC        (0x872CU) /**< @brief #SECY_GetPortStatusReq         */

#define BRCM_SWARCH_SECY_MSG_UNION_TYPE                  (0x8780U) /**< @brief #SECY_MsgUnionType             */
#define BRCM_SWARCH_SECY_MSG_TYPE                        (0x8781U) /**< @brief #SECY_MsgType                  */
#define BRCM_SWARCH_SECY_ACCESS_CTRL_MSG_TYPE            (0x8782U) /**< @brief #SECY_AccessCtrlMsgType        */
#define BRCM_SWARCH_SECY_OWNER_TYPE                      (0x8783U) /**< @brief #SECY_OwnerType                */

/** @} */

/**
    @name SECY_OwnerType;
    @{
    @brief SECY Module Owner Type

    @trace #BRCM_SWREQ_SECY
*/
typedef uint32_t SECY_OwnerType;
#define SECY_OWNER_LOCAL       (0UL)
#define SECY_OWNER_RPC         (1UL)
/** @} */

/**
    @brief SecY Access Control

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_AccessCtrlMsgType {
    SECY_OwnerType      accessOwner;
    uint32_t            port;
} SECY_AccessCtrlMsgType;
BCM_STATIC_SIZE_ASSERT(SECY_AccessCtrlMsgType, 8, SECY_MSG_MAX_SIZE);

/**
    @brief SecY Union encapsulating all messages

    @trace #BRCM_SWREQ_SECY
*/
typedef union uSECY_MsgUnionType {
    uint32_t                        data[SECY_MSG_MAX_SIZE/4UL];
    SECY_HwInitMsgType        hwInit;
    SECY_RuleOpt0MsgType      ruleOpt0;
    SECY_RuleOpt1MsgType      ruleOpt1;
    SECY_GetCipherMsgType     getCipher;
    SECY_HwDeinitMsgType      hwDeinit;
    SECY_CreateMsgType        secYCreate;
    SECY_SetCipherMsgType     setCipher;
    SECY_StatsMsgType         stats;
    SECY_HdlMsgType           hdl;
    SECY_SCMsgType            sc;
    SECY_LookupRuleMsgType    scLookup;
    SECY_LookupRuleV2MsgType  scLookupV2;
    SECY_TxSCStatsMsgType     txScStats;
    SECY_RxSCStatsMsgType     rxScStats;
    SECY_SAMsgType            sa;
    SECY_SALocalMsgType       saExt;
    SECY_PNMsgType            pn;
    SECY_DebugMsgType         debug;
    SECY_SAStatusMsgType      saStatus;
    SECY_CreateV2MsgType      secYCreateV2;
    SECY_CreateSAV2MsgType    addSA;
    SECY_UpdateSAMsgType      updateSA;
    SECY_FullStatsMsgType     fullStats;
    SECY_AccessCtrlMsgType    accessCtrl;
    SECY_StatusMsgType        secyStatus;
} SECY_MsgUnionType;

/**
    @brief Verity Union encapsulating all messages

    @trace #BRCM_SWREQ_SECY
*/
typedef struct sSECY_MsgType {
    uint32_t                    magic;
    BCM_MsgType                 id;
    int32_t                     status;
    uint32_t                    len;
    SECY_MsgUnionType           u;
} SECY_MsgType;

/** @brief Retreive status of SECY Async SecY Request

    This API queries the status of completed crypto SecY commands which were
    previously issued

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aHandle                BCM Handle to retrieve response
    @param[in]   aReplyID               Reply ID (group, comp, cmd)
    @param[in]   aInLen                 Available Length of the reply data payload in bytes
    @param[out]  aReplyData             Pointer to the reply data payload
    @param[out]  aReplyDataLen          Actual Length of the reply data payload in bytes

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK     Command status retrieved successfully

    @post None

    @trace #BRCM_SWREQ_SECY
*/
int32_t SECY_GetStatusReq(BCM_HandleType aHandle, BCM_MsgType aReplyID, uint32_t aInLen,
                             uint8_t *aReplyData, uint32_t *aReplyDataLen);

/**
    @brief Initialize SecY

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl         Handle to query the status
    @param[in]      aPort           Port Number
    @param[in]      aCfg            Configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @return     #BCM_ERR_INVAL_PARAMS        aCfg is NULL or invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_InitReq(BCM_HandleType *aCmdHdl,uint32_t aPort, const SECY_HwCfgType *const aCfg);

/**
    @brief Add Control packet rule 0

    Add a control packet rule in the hardware and return the handle for the rule.
    Multiple control packet rules (option 0) can be added on a given port (limited by underlying
    hardware resource. Refer to TRM for the details about how many rules are allowed).

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aPort              Port Number
    @param[in]      aRuleOpt           Filtering Rule


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleOpt is NULL or Invalid
    @return     #BCM_ERR_NOMEM           No more space to add new rule

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_AddCPRuleOpt0Req(BCM_HandleType *aCmdHdl, uint32_t aPort,
                                   const SECY_RuleOpt0Type *const aRuleOpt);

/**
    @brief Add Control packet rule 1

    Add a control packet rule in the hardware and return the handle for the rule.
    Multiple control packet rules (option 1) can be added on a given port (limited by underlying
    hardware resource. Refer to TRM for the details about how many rules are allowed).

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aPort              Port Number
    @param[in]      aRuleOpt           Filtering Rule



    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleOpt1 is NULL or Invalid
    @return     #BCM_ERR_NOMEM           No more space to add new rule

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_AddCPRuleOpt1Req(BCM_HandleType *aCmdHdl, uint32_t aPort,
                                    const SECY_RuleOpt1Type *const aRuleOpt);

/**
    @brief Remove Control packet Rule

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aRuleHdl           Rule Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_RemoveCPRuleReq(BCM_HandleType *aCmdHdl, BCM_HandleType aRuleHdl);

/**
    @brief SecY HW De-Init

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aPort           Port Number


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS     Invalid Port

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DeinitReq(BCM_HandleType *aCmdHdl, uint32_t aPort);

/**
    @brief Creates a SecY instance

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aPort                    Port Number
    @param[in]      aCfg                     SecY Config

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aCfg is NULL
    @return     #BCM_ERR_NOMEM           Can not create more SecY instances

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateSecyReq(BCM_HandleType *aCmdHdl, uint32_t aPort,
                                   const SECY_CfgType *const aCfg);

/**
    @brief Provides the supported cipher suites and its capabilities

    @behavior Sync, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aPort              Port Number
    @param[in]      aCipherID          Cipher ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_NOSUPPORT       Given cipher is not supported by hardware

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetCipherCapReq(BCM_HandleType *aCmdHdl, uint32_t aPort,
                                  SECY_CipherType aCipherID);

/**
    @brief Set the given cipher suite for SecY

    @note Cipher suite must be supported by the system (SECY_GetCipherCap() API has returned
          BCM_ERR_OK for given cipher suite)

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl         SecY Handle
    @param[in]      aCipherID        Cipher ID
    @param[in]      aConOffset       Confidentiality Offset

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_NOSUPPORT       Given cipher is not supported by hardware

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetCipherSuiteReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                      SECY_CipherType aCipherID, SECY_ConfOffsetType aConOffset);

/**
    @brief Add a rule for SecY lookup and returns rule handle

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl                 SecY Handle
    @param[in]      aRuleOpt                 Filtering Rule


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid
                                         aRuleOpt is NULL or Invalid

    @return     BCM_ERR_NOMEM           No more space to add new rule

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_AddSecYLookupRuleReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                    const SECY_RuleOpt1Type *const aRuleOpt);

/**
    @brief Remove Lookup Rule

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]     aRuleHdl           Rule Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_RemoveSecYLookupRuleReq(BCM_HandleType *aCmdHdl, BCM_HandleType aRuleHdl);

/**
    @brief Stats query

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl        SecY Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetStatsReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl);

/**
    @brief Set Frame Protect

    Enable/Disable frame protection on this SecY.
    if frame protection is disabled, SecY sends the packet without
    any modification (without SecTAG and encryption).

    @note This API is provided only for debug purpose.
    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl        SecY Handle
    @param[in]      aEnable         Enable Protect


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetProtectFrameReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl, uint32_t aEnable);

/**
    @brief Set Replay Protect

    Enable/Disable replay protection on SecY.
    Setting the replay protection option shall be done before the creation of the SA (best
    practice is to set this debug option right after creating the SecY). Setting this option
    has no effect on the existing SAs.
    If replay protection is required to be applied on the SecY which is already receiving,
    SAs must be deleted, then this API shall be called to set the required option and then new SA
    shall be created again.

    @note This API is provided only for debug purpose. Ideally, replay protection shall
           always be enabled in the system.

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl        SecY Handle
    @param[in]      aEnable         Enable Replay Protect
    @param[in]      aWindow         Replay Protect Window

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetReplayProtectReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                       uint32_t aEnable, uint32_t aWindow);

/**
    @brief Set Ingress frame validation

    Set the frame validate option for the ingress.
    Setting the frame validation option shall be done before the creation of the SA (best
    practice is to set this debug option right after creating the SecY). Setting frame
    validation option has no effect on the existing SAs.
    If validation option is required to be applied on the SecY which is already receiving,
    SAs must be deleted, then this API shall be called to set
    the required validation option and then new SA shall be created again.

    @note This API is provided only for debug purpose. Bydefault, when SecY is initialized
    validate frame option is set to STRICT.

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl         SecY Handle
    @param[in]      aValidate        Enable Replay Protect


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
                                         aValidate is invalid
    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetFrameValidateReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                              SECY_ValidateFrameType aValidate);

/**
    @brief Delete SecY

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl           SecY Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DeleteSecYReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl);

/**
    @brief Create secure transmit channel on given SecY

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or
                                         aSecYHdl is Invalid
    @return     #BCM_ERR_BUSY            Secure channel already created

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateTxSCReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                       const SECY_SCIType *const aSci);

/**
    @brief Create receive secure channel on given SecY

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or
                                         aSecYHdl is Invalid
    @return     #BCM_ERR_NOMEM           Can not create more RX channel on this SecY

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateRxSCReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                           const SECY_SCIType *const aSci);

/**
    @brief Get TxSC Stats

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is Invalid or
                                         aSci is Invalid


    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetTxSCStatsReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                   const SECY_SCIType *const aSci);

/**
    @brief Get RxSC Stats

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is Invalid or
                                         aSci is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetRxSCStatsReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                   const SECY_SCIType *const aSci);

/**
    @brief Delete TxSC

    @behavior Sync, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or
                                         aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DeleteTxSCReq(BCM_HandleType *aCmdHdl,  BCM_HandleType aSecYHdl,
                                       const SECY_SCIType *const aSci);

/**
    @brief Delete RxSC

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or
                                         aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DeleteRxSCReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                       const SECY_SCIType *const aSci);

/**
    @brief Create TXSA

    Create a transmit secure association on given SecY and return the handle of the newly
    created SA.
    When SA is created, it's not enabled. client need to enable the SA by calling #SECY_EnableSA
    function.

    Example:
    If XPN Cipher Suit is enabled and
    the Salt is 0xE630E81A48DE86A21C66FA6D
    and SSCI is 0x7A30C118
    then user should pass input to API in below format:

    aKey.salt[] = {E6,30,E8,1A,48,DE,86,A2,1C,66,FA,6D}
    aSsci       = 0x18C1307A (In reverse order)

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl            SecY Handle.
    @param[in]      aAN                 Association number.
    @param[in]      aNextPN             Next PN number incremented by 1 to be used for this SA.
                                        (for example, if first packet has to be send with PN = 1,
                                        this shall be set to 0).
    @param[in]      aSci                SCI for which SA has to be created
    @param[in]      aSsci               32-bit SSCI value for this SCI if XPN cipher is used.
                                        If XPN cipher is not used for this SecY,
                                        this parameter shall be set to 0.
    @param[in]      aConfidentiality    TRUE: Enable confidentiality protection on this SA
                                        (payload encrypted and ICV is appended)
                                        FALSE: Disable confidentiality protection on this SA
                                        (data flows in plain, ICV is appended for the authentication)
    @param[in]      aKeyHdl             key Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or Invalid or
                                         aKey is NULL or Invalid or
                                         aAN is > 3 or
                                         aNextPN is 0 or > 0xFFFFFFFF or
                                         Duplicate SSCI value for the same SCI or
                                         aSecYHdl is Invalid
    @return     #BCM_ERR_BUSY            Trying to update the active SA

    @post API will disable the control port

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateTxSAReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl, uint32_t aAN,
                                uint64_t aNextPN, const SECY_SCIType *const aSci, uint32_t aSsci,
                                uint32_t aConfidentiality,
                                const SECY_KeyType *const aKey, CMEM_HdlType aKeyHdl);

/**
    @brief Create RXSA

    Create a receive secure association on given SecY and returns the handle of the newly
    created SA.

    Example:
    If XPN Cipher Suit is enabled and
    the Salt is 0xE630E81A48DE86A21C66FA6D
    and SSCI is 0x7A30C118
    then user should pass input to API in below format:

    aKey.salt[] = {E6,30,E8,1A,48,DE,86,A2,1C,66,FA,6D}
    aSsci       = 0x18C1307A (In reverse order)

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSecYHdl            SecY Handle.
    @param[in]      aAN                 Association number.
    @param[in]      aLowestPN           Lowest acceptable PN number for receive SA (must be > 0 and
                                        < 0xFFFFFFFFF for 32-bit PN and < 0xFFFFFFFFFFFFFFFF for
                                        XPN).
    @param[in]      aSci                SCI for which SA has to be created
    @param[in]      aSsci               32-bit SSCI value for this SCI if XPN cipher is used.
                                        If XPN cipher is not used for this SecY,
                                        this parameter shall be set to 0.
    @param[in]      aKey                key Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or Invalid or
                                         aKey is NULL or Invalid or
                                         aAN is > 3 or
                                         aLowestPN is 0 or > 0xFFFFFFFF or
                                         Duplicate SSCI value for the same SCI or
                                         aSecYHdl is Invalid

    @post API will disable the control port

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateRxSAReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl, uint32_t aAN,
                                uint64_t aLowestPN, const SECY_SCIType *const aSci, uint32_t aSsci,
                                const SECY_KeyType *const aKey, CMEM_HdlType aKeyHdl);

/**
    @brief Enable SecTag Control Port

    Enable the controlled port of the SecY (Set MAC_Operational to TRUE for the controlled port of the SecY).

    @behavior Async, Non-Rentrant

    @pre SA is created using MACSEC_SACreateReq() API

    @param[out]     aCmdHdl        Handle to query the status
    @param[in]      aSecYHdl       SecY Handle.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    SecY is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_EnableControlledPortReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl);

/**
    @brief Disable SecTag Control Port

    Disable the controlled port of the SecY (Set MAC_Operational to FALSE for the controlled port of the SecY).

    @behavior Async, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[out]     aCmdHdl        Handle to query the status
    @param[in]      aSecYHdl       SecY Handle.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    SecY is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DisableControlledPortReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl);

/**
    @brief Enable SA

    Enable an inactive SA.
    For transmit, if this is not currently active SA (it's not encoding SA), it will become
    active after API returns (will become encoding SA). If SecY Tx SC was not transmitting, it will
    become ready for transmitting.  Old SA is not automatically deleted and
    Client need to call #SECY_DisableSA() followed by #SECY_DisableSA() to free-up the resources.
    For receive, if this SA was not already enabled, it will become active. If none of the SAs
    for this SC was active, SC will become active and ready to receive.

    @behavior Async, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl         SA Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_EnableSAReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl);

/**
    @brief Disables an active SA

    @note None

    @behavior Async, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl         SA handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DisableSAReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl);

/**
    @brief Get SA status

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl           SA Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetSAStatusReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl);

/**
    @brief Set PN Threshold

    Set packet number threshold for the transmit SA. When transmit sequence number
    (nextPN value) for SA crosses this threshold, a IRQ event is generated which
    could be directly processed by the host (if supported by the board/hardware design).

    This API is provided to signal host software when PN threshold crosses configured
    value so that  MKA/Client can switch to new SA well before expiry.

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl           SA Handle
    @param[in]      aPN              PN Threshold


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid or
                                         aPN is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetPNThresholdReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl, uint64_t aPN);

/**
    @brief Get nextPN value

    Reads the nextPN value of the active SA.
    For transmit SA, this returns the PN value of last
    successfully transmitted frame plus 1 (for example, when this
    API was called, last frame which was send had PN value 0x3,
    this API returns 0x4).
    For receive SA, this API return the lowest acceptable PN
    value (for example, when this API was called, SA has successfully
    received a frame with PN value of 0x3, this API returns 0x4).

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl           SA Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid or

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetSANextPNReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl);

/**
    @brief Set nextPN value

    Set the next pn for the receive SA (lowest acceptable PN)

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl           SA Handle
    @param[in]      aPN              Next PN Threshold

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid
                                         aPN value is greater than 32-bit and XPN is not enabled
    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetSANextPNReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl, uint64_t aPN);

/**
    @brief Delete SA

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl             SA Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DeleteSAReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl);

/**
    @brief Update TxSA

    Requests the Ethernet Switch to
    Enable Transmission secure association and set PN threshold and OR
    Disable Transmission secure association.

    @behavior Async, Non-Rentrant

    @pre SA is created/added and in disabled state

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl                SA Handle
    @param[in]      aPn                   PN threshold
    @param[in]      aEnable               Enable/Disable SA


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aPn is NULL or
                                         invalid SA handle

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_UpdateTxSAReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl,
                                uint64_t aPn, BCM_BoolType aEnable);

/**
    @brief Update RxSA

    Requests the Ethernet Switch to
    Enable Receive secure association and set Lowest PN OR
    Disable Receive secure association.

    @behavior Async, Non-Rentrant

    @pre SA is created/added and in disabled state

    @param[out]     aCmdHdl             Handle to query the status
    @param[in]      aSAHdl                SA Handle
    @param[in]      aPn                   lowest PN
    @param[in]      aEnable               Enable/Disable SA


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aPn is NULL or
                                         invalid SA handle

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_UpdateRxSAReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSAHdl,
                                uint64_t aPn, BCM_BoolType aEnable);

/**
    @brief Get SecY stats

    Request the Ethernet Switch to provide statistics of
    1.SecY
    2.Transmission Secure Channel
    2.Reception Secure Channel

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl         Handle to query the status
    @param[in]      aSecYHdl        SecY Handle
    @param[in]      aTxSci          Tx SCI
    @param[in]      aRxSci          List of RxSCI's for which stats has to be fetched
    @param[in]      aRxSciCount     Total No of RxSCI's for which stats has to be fetched

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aTxSci is NULL or
                                         aRxSci is NULL or
                                         aRxSciCount is '0'
                                         aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetFullStatsReq(BCM_HandleType *aCmdHdl, BCM_HandleType aSecYHdl,
                                   const SECY_SCIType *const aTxSci, const SECY_SCIType *const aRxSci,
                                   uint32_t aRxSciCount);

/**
    @brief Enable SECY Commands over RPC

    On boot-up commands from RPC service will be dishonoured

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl         Handle to query the status
    @param[in]      aPort           Port Number
    @param[in]      aAccessOwner    Access Owner

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success

    @post SECY Access module will be changed

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetAccessCtrlReq(BCM_HandleType *aCmdHdl, uint32_t aPort, SECY_OwnerType aAccessOwner);

/**
    @brief Get Port Status Request

    @behavior Async, Non-Rentrant

    @pre None

    @param[out]     aCmdHdl         Handle to query the status
    @param[in]      aPort           Port Number

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aPort is not valid

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetPortStatusReq(BCM_HandleType *aCmdHdl, uint32_t aPort);

#endif /* CRYPTO_SECY_RPC_H */

/** @} */
