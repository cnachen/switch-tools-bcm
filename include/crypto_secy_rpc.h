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
    @defgroup grp_crypto_secy_rpc_ifc SecY RPC Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_secy_rpc_ifc
    @{

    @limitations None

    @file crypto_secy_rpc.h
    @brief Crypto MAC Security Entity (MACSEC) Interface
    This header file contains the interface functions for Crypto MAC Security Entity (MACSEC)

    @version 1.0 Initial Version
*/

#ifndef CRYPTO_SECY_RPC_H
#define CRYPTO_SECY_RPC_H

#include <crypto_common.h>
#include <crypto_secy_types.h>
#include <bcm_comp.h>
#include <bcm_err.h>
#include <bcm_utils.h>

/**
    @name Crypto SecY Architecture IDs
    @{
    @brief Architecture IDs for Crypto SecY
*/

#define BRCM_SWARCH_SECY_INIT_PROC                   (0x8304U) /**< @brief #SECY_Init                  */
#define BRCM_SWARCH_SECY_ADDCPRULEOPT0_PROC          (0x8305U) /**< @brief #SECY_AddCPRuleOpt0         */
#define BRCM_SWARCH_SECY_ADDCPRULEOPT1_PROC          (0x8306U) /**< @brief #SECY_AddCPRuleOpt1         */
#define BRCM_SWARCH_SECY_REMOVECPRULE_PROC           (0x8307U) /**< @brief #SECY_RemoveCPRule          */
#define BRCM_SWARCH_SECY_DEINIT_PROC                 (0x8308U) /**< @brief #SECY_Deinit                */
#define BRCM_SWARCH_SECY_CREATESECY_PROC             (0x8309U) /**< @brief #SECY_CreateSecy            */
#define BRCM_SWARCH_SECY_GETCIPHERCAP_PROC           (0x830AU) /**< @brief #SECY_GetCipherCap          */
#define BRCM_SWARCH_SECY_SETCIPHERSUITE_PROC         (0x830BU) /**< @brief #SECY_SetCipherSuite        */
#define BRCM_SWARCH_SECY_ADDSECYLOOKUPRULE_PROC      (0x830CU) /**< @brief #SECY_AddSecYLookupRule     */
#define BRCM_SWARCH_SECY_REMOVESECYLOOKUPRULE_PROC   (0x830DU) /**< @brief #SECY_RemoveSecYLookupRule  */
#define BRCM_SWARCH_SECY_GETSTATS_PROC               (0x830EU) /**< @brief #SECY_GetStats              */
#define BRCM_SWARCH_SECY_SETPROTECTFRAME_PROC        (0x830FU) /**< @brief #SECY_SetProtectFrame       */
#define BRCM_SWARCH_SECY_SETREPLAYPROTECT_PROC       (0x8310U) /**< @brief #SECY_SetReplayProtect      */
#define BRCM_SWARCH_SECY_SETFRAMEVALIDATE_PROC       (0x8311U) /**< @brief #SECY_SetFrameValidate      */
#define BRCM_SWARCH_SECY_DELETESECY_PROC             (0x8312U) /**< @brief #SECY_DeleteSecY            */
#define BRCM_SWARCH_SECY_CREATETXSC_PROC             (0x8313U) /**< @brief #SECY_CreateTxSC            */
#define BRCM_SWARCH_SECY_CREATERXSC_PROC             (0x8314U) /**< @brief #SECY_CreateRxSC            */
#define BRCM_SWARCH_SECY_GETTXSCSTATS_PROC           (0x8315U) /**< @brief #SECY_GetTxSCStats          */
#define BRCM_SWARCH_SECY_GETRXSCSTATS_PROC           (0x8316U) /**< @brief #SECY_GetRxSCStats          */
#define BRCM_SWARCH_SECY_DELETETXSC_PROC             (0x8317U) /**< @brief #SECY_DeleteTxSC            */
#define BRCM_SWARCH_SECY_DELETERXSC_PROC             (0x8318U) /**< @brief #SECY_DeleteRxSC            */
#define BRCM_SWARCH_SECY_CREATETXSA_PROC             (0x8319U) /**< @brief #SECY_CreateTxSA            */
#define BRCM_SWARCH_SECY_CREATERXSA_PROC             (0x831AU) /**< @brief #SECY_CreateRxSA            */
#define BRCM_SWARCH_SECY_ENABLESA_PROC               (0x831BU) /**< @brief #SECY_EnableSA              */
#define BRCM_SWARCH_SECY_DISABLESA_PROC              (0x831CU) /**< @brief #SECY_DisableSA             */
#define BRCM_SWARCH_SECY_GETSASTATUS_PROC            (0x831DU) /**< @brief #SECY_GetSAStatus           */
#define BRCM_SWARCH_SECY_SETPNTHRESHOLD_PROC         (0x831EU) /**< @brief #SECY_SetPNThreshold        */
#define BRCM_SWARCH_SECY_GETSANEXTPN_PROC            (0x831FU) /**< @brief #SECY_GetSANextPN           */
#define BRCM_SWARCH_SECY_SETSANEXTPN_PROC            (0x8320U) /**< @brief #SECY_SetSANextPN           */
#define BRCM_SWARCH_SECY_DELETESA_PROC               (0x8321U) /**< @brief #SECY_DeleteSA              */
#define BRCM_SWARCH_SECY_CREATESECYV2_PROC           (0x8322U) /**< @brief #SECY_CreateSecyV2          */
#define BRCM_SWARCH_SECY_CREATETXSAV2_PROC           (0x8323U) /**< @brief #SECY_CreateTxSAV2          */
#define BRCM_SWARCH_SECY_CREATERXV2_PROC             (0x8324U) /**< @brief #SECY_CreateRxSAV2          */
#define BRCM_SWARCH_SECY_UPDATETXSA_PROC             (0x8325U) /**< @brief #SECY_UpdateTxSA            */
#define BRCM_SWARCH_SECY_UPDATERXSA_PROC             (0x8326U) /**< @brief #SECY_UpdateRxSA            */
#define BRCM_SWARCH_SECY_GETFULLSTATUS_PROC          (0x8327U) /**< @brief #SECY_GetFullStats          */
#define BRCM_SWARCH_SECY_EN_CTRL_PORT_PROC           (0x8328U) /**< @brief #SECY_EnableControlledPort  */
#define BRCM_SWARCH_SECY_DIS_CTRL_PORT_PROC          (0x8329U) /**< @brief #SECY_DisableControlledPort */

/** @} */

/**
    @brief Initialize SecY

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aPort           Port Number
    @param[in]      aCfg            Configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @return     #BCM_ERR_INVAL_PARAMS        aCfg is NULL or invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_Init(BCM_HandleType aConnHdl,uint32_t aPort, const SECY_HwCfgType *const aCfg);

/**
    @brief Add Control packet rule 0

    Add a control packet rule in the hardware and return the handle for the rule.
    Multiple control packet rules (option 0) can be added on a given port (limited by underlying
    hardware resource. Refer to TRM for the details about how many rules are allowed).

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aPort              Port Number
    @param[in]      aRuleOpt           Filtering Rule
    @param[out]     aRuleHdl           Rule Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is NULL or
                                         aRuleOpt is NULL or Invalid
    @return     #BCM_ERR_NOMEM           No more space to add new rule

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_AddCPRuleOpt0(BCM_HandleType aConnHdl, uint32_t aPort,
                                   const SECY_RuleOpt0Type *const aRuleOpt,
                                   BCM_HandleType *const aRuleHdl);

/**
    @brief Add Control packet rule 1

    Add a control packet rule in the hardware and return the handle for the rule.
    Multiple control packet rules (option 1) can be added on a given port (limited by underlying
    hardware resource. Refer to TRM for the details about how many rules are allowed).

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aPort              Port Number
    @param[in]      aRuleOpt           Filtering Rule
    @param[out]     aRuleHdl           Rule Handle



    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is NULL or
                                         aRuleOpt1 is NULL or Invalid
    @return     #BCM_ERR_NOMEM           No more space to add new rule

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_AddCPRuleOpt1(BCM_HandleType aConnHdl, uint32_t aPort,
                                    const SECY_RuleOpt1Type *const aRuleOpt,
                                    BCM_HandleType *const aRuleHdl);

/**
    @brief Remove Control packet Rule

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aRuleHdl           Rule Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_RemoveCPRule(BCM_HandleType aConnHdl, BCM_HandleType aRuleHdl);

/**
    @brief SecY HW De-Init

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aPort           Port Number


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS     Invalid Port

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_Deinit(BCM_HandleType aConnHdl, uint32_t aPort);

/**
    @brief Creates a SecY instance and returns the handle to user in aSecYHdl parameter

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aPort                    Port Number
    @param[in]      aCfg                     SecY Config
    @param[out]     aSecYHdl                 SecY Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is NULL or
                                         aCfg is NULL
    @return     #BCM_ERR_NOMEM           Can not create more SecY instances

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateSecy(BCM_HandleType aConnHdl, uint32_t aPort,
                                   const SECY_CfgType *const aCfg, BCM_HandleType *const aSecYHdl);

/**
    @brief Provides the supported cipher suites and its capabilities

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aPort              Port Number
    @param[in]      aCipherID          Cipher ID
    @param[out]     aCipherCap         Cipher Cap

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aCipherCap is NULL
    @return     #BCM_ERR_NOSUPPORT       Given cipher is not supported by hardware

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetCipherCap(BCM_HandleType aConnHdl, uint32_t aPort,
                                  SECY_CipherType aCipherID, SECY_CipherCapType *const aCipherCap);

/**
    @brief Set the given cipher suite for SecY

    @note Cipher suite must be supported by the system (SECY_GetCipherCap() API has returned
          BCM_ERR_OK for given cipher suite)

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
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
extern int32_t SECY_SetCipherSuite(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                      SECY_CipherType aCipherID, SECY_ConfOffsetType aConOffset);

/**
    @brief Add a rule for SecY lookup and returns rule handle

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl                 Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl                 SecY Handle
    @param[in]      aRuleOpt                 Filtering Rule
    @param[out]     aRuleHdl                 Rule Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is NULL or
                                         aSecYHdl is invalid
                                         aRuleOpt is NULL or Invalid

    @return     BCM_ERR_NOMEM           No more space to add new rule

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_AddSecYLookupRule(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                    const SECY_RuleOpt1Type *const aRuleOpt,
                                    BCM_HandleType *const aRuleHdl);

/**
    @brief Remove Lookup Rule

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl           Connection handle (from RPC_Connect)
    @param[in]     aRuleHdl           Rule Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_RemoveSecYLookupRule(BCM_HandleType aConnHdl, BCM_HandleType aRuleHdl);

/**
    @brief Stats query

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl        SecY Handle
    @param[out]     aStats          stats

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aStats is NULL or
                                         aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetStats(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                              SECY_StatsType *const aStats);

/**
    @brief Set Frame Protect

    Enable/Disable frame protection on this SecY.
    if frame protection is disabled, SecY sends the packet without
    any modification (without SecTAG and encryption).

    @note This API is provided only for debug purpose.
    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl        SecY Handle
    @param[in]      aEnable         Enable Protect


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_SetProtectFrame(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl, uint32_t aEnable);

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

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
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
extern int32_t SECY_SetReplayProtect(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
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

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
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
extern int32_t SECY_SetFrameValidate(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                              SECY_ValidateFrameType aValidate);

/**
    @brief Delete SecY

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl           SecY Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DeleteSecY(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl);

/**
    @brief Create secure transmit channel on given SecY

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
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
extern int32_t SECY_CreateTxSC(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                       const SECY_SCIType *const aSci);

/**
    @brief Create receive secure channel on given SecY

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
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
extern int32_t SECY_CreateRxSC(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                           const SECY_SCIType *const aSci);

/**
    @brief Get TxSC Stats

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI
    @param[out]     aTxStats           TX SCI Stat

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is Invalid or
                                         aTxStats is NULL or
                                         aSci is Invalid


    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetTxSCStats(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                   const SECY_SCIType *const aSci, SECY_TxSCStatsType *const aTxStats);

/**
    @brief Get RxSC Stats

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl           SecY Handle
    @param[in]      aSci               SCI
    @param[out]     aRxStats           RX SCI Stats


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is Invalid or
                                         aRxStats is NULL or
                                         aSci is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetRxSCStats(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                   const SECY_SCIType *const aSci, SECY_RxSCStatsType *const aRxStats);

/**
    @brief Delete TxSC

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
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
extern int32_t SECY_DeleteTxSC(BCM_HandleType aConnHdl,  BCM_HandleType aSecYHdl,
                                       const SECY_SCIType *const aSci);

/**
    @brief Delete RxSC

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
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
extern int32_t SECY_DeleteRxSC(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
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

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect/MDIO_Open)
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
    @param[in]      aKey                key
    @param[out]     aSAHdl              A non-zero SA handle (value is valid only when API
                                        returns BCM_ERR_OK)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or Invalid or
                                         aKey is NULL or Invalid or
                                         aSAHdl is NULL or
                                         aAN is > 3 or
                                         aNextPN is 0 or > 0xFFFFFFFF or
                                         Duplicate SSCI value for the same SCI or
                                         aSecYHdl is Invalid
    @return     #BCM_ERR_BUSY            Trying to update the active SA

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateTxSA(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl, uint32_t aAN,
                                uint64_t aNextPN, const SECY_SCIType *const aSci, uint32_t aSsci,
                                uint32_t aConfidentiality, const SECY_KeyType *const aKey,
                                BCM_HandleType *const aSAHdl);

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

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl            SecY Handle.
    @param[in]      aAN                 Association number.
    @param[in]      aLowestPN           Lowest acceptable PN number for receive SA (must be > 0 and
                                        < 0xFFFFFFFFF for 32-bit PN and < 0xFFFFFFFFFFFFFFFF for
                                        XPN).
    @param[in]      aSci                SCI for which SA has to be created
    @param[in]      aSsci               32-bit SSCI value for this SCI if XPN cipher is used.
                                        If XPN cipher is not used for this SecY,
                                        this parameter shall be set to 0.
    @param[in]      aKey                key
    @param[out]     aSAHdl              A non-zero SA handle (value is valid only when API
                                        returns BCM_ERR_OK)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or Invalid or
                                         aKey is NULL or Invalid or
                                         aSAHdl is NULL or
                                         aAN is > 3 or
                                         aLowestPN is 0 or > 0xFFFFFFFF or
                                         Duplicate SSCI value for the same SCI or
                                         aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateRxSA(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl, uint32_t aAN,
                                uint64_t aLowestPN, const SECY_SCIType *const aSci, uint32_t aSsci,
                                const SECY_KeyType *const aKey, BCM_HandleType *const aSAHdl);

/**
    @brief Enable SecTag Control Port

    Enable the controlled port of the SecY (Set MAC_Operational to TRUE for the controlled port of the SecY).

    @behavior sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl       SecY Handle.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    SecY is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_EnableControlledPort(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl);

/**
    @brief Disable SecTag Control Port

    Disable the controlled port of the SecY (Set MAC_Operational to FALSE for the controlled port of the SecY).

    @behavior sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl       SecY Handle.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    SecY is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DisableControlledPort(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl);

/**
    @brief Enable SA

    Enable an inactive SA.
    For transmit, if this is not currently active SA (it's not encoding SA), it will become
    active after API returns (will become encoding SA). If SecY Tx SC was not transmitting, it will
    become ready for transmitting.  Old SA is not automatically deleted and
    Client need to call #SECY_DisableSA() followed by #SECY_DisableSA() to free-up the resources.
    For receive, if this SA was not already enabled, it will become active. If none of the SAs
    for this SC was active, SC will become active and ready to receive.

    @behavior Sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSAHdl         SA Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_EnableSA(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl);

/**
    @brief Disables an active SA

    @note None

    @behavior Sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSAHdl         SA handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DisableSA(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl);

/**
    @brief Get SA status

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
    @param[in]      aSAHdl           SA Handle
    @param[out]     aStatus          SA Status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aStatus is NULL or
                                         aSAHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetSAStatus(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl,
                                          SECY_SAStatusType *const aStatus);

/**
    @brief Set PN Threshold

    Set packet number threshold for the transmit SA. When transmit sequence number
    (nextPN value) for SA crosses this threshold, a IRQ event is generated which
    could be directly processed by the host (if supported by the board/hardware design).

    This API is provided to signal host software when PN threshold crosses configured
    value so that  MKA/Client can switch to new SA well before expiry.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
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
extern int32_t SECY_SetPNThreshold(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl, uint64_t aPN);

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

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
    @param[in]      aSAHdl           SA Handle
    @param[out]     aPN              Next PN


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSAHdl is invalid or
                                         aPN is NULL

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetSANextPN(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl, uint64_t *aPN);

/**
    @brief Set nextPN value

    Set the next pn for the receive SA (lowest acceptable PN)

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
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
extern int32_t SECY_SetSANextPN(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl, uint64_t aPN);

/**
    @brief Delete SA

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aSAHdl             SA Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aRuleHdl is invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_DeleteSA(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl);

/**
    @brief Create SecY

    Requests the Ethernet Switch to
    1.Update the SecY with Provided SecY configuration
    2.Set Cipher
    3.Create Transmission Secure Channel with the provided SCI
    4.Set Replay Protect
    5.Set Ingress frame validation

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)
    @param[in]      aCreate            SecY Configuration to create
    @param[out]     aSecYHdl           SecY Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSecYHdl is NULL or
                                         aCryptoCfg is NULL or
                                         aSecYCfg is NULL or
                                         aSci is NULL or
                                         aValidate is invalid
    @return     #BCM_ERR_NOSUPPORT       Given cipher is not supported by hardware
    @return     #BCM_ERR_BUSY            Secure channel already created
    @return     #BCM_ERR_NOMEM           No more space to add new rule or
                                         Can not create more SecY instances

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateSecyV2(BCM_HandleType aConnHdl, const SECY_CreateV2Type *const aCreate,
                                 BCM_HandleType *const aSecYHdl);

/**
    @brief Create Transmission Secure Association

    Requests the Ethernet Switch to
    1.Create a transmit secure association on given SecY
    2.Enable Transmission Secure Association and return the handle of the newly created SA.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl              Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl              SecY Handle
    @param[in]      aAN                   Association Number
    @param[in]      aNextPN               Next PN
    @param[in]      aSci                  SCI
    @param[in]      aSsci                 SSCI
    @param[in]      aConfidentiality      Confidentiality
    @param[in]      aKey                  SA Key
    @param[in]      aEnable               TRUE: SA will be created and enabled immediately
                                          FALSE: SA will be created but not enabled.
                                                 SA can be enabled later by calling #SECY_EnableSA or #SECY_UpdateTxSA
    @param[out]     aSAHdl                SA Handle


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or Invalid or
                                         aKey is NULL or Invalid or
                                         aSAHdl is NULL or
                                         aAN is > 3 or
                                         aNextPN is 0 or > 0xFFFFFFFF or
                                         Duplicate SSCI value for the same SCI or
                                         aSecYHdl is Invalid
    @return     #BCM_ERR_BUSY            Trying to add the active SA

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateTxSAV2(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl, uint32_t aAN,
                                  uint64_t aNextPN, const SECY_SCIType *const aSci, uint32_t aSsci,
                                  uint32_t aConfidentiality, const SECY_KeyType *const aKey,
                                  BCM_BoolType aEnable, BCM_HandleType *const aSAHdl);

/**
    @brief Create Reception Secure Association

    Requests the Ethernet Switch to
    1.Create a receive secure association on given SecY
    2.Enable receive Secure Association and returns the handle of the newly created SA.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl              Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl              SecY Handle
    @param[in]      aAN                   Association Number
    @param[in]      aLowestPN             Low PN
    @param[in]      aSci                  SCI
    @param[in]      aSsci                 SSCI
    @param[in]      aKey                  SA Key
    @param[in]      aEnable               TRUE: SA will be created and enabled immediately
                                          FALSE: SA will be created but not enabled.
                                                 SA can be enabled later by calling #SECY_EnableSA or #SECY_UpdateRxSA
    @param[out]     aSAHdl                SA Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aSci is NULL or Invalid or
                                         aKey is NULL or Invalid or
                                         aSAHdl is NULL or
                                         aAN is > 3 or
                                         aLowestPN is 0 or > 0xFFFFFFFF or
                                         Duplicate SSCI value for the same SCI or
                                         aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_CreateRxSAV2(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl, uint32_t aAN,
                                    uint64_t aLowestPN, const SECY_SCIType *const aSci, uint32_t aSsci,
                                    const SECY_KeyType *const aKey, BCM_BoolType aEnable,
                                    BCM_HandleType *const aSAHdl);

/**
    @brief Update TxSA

    Requests the Ethernet Switch to
    Enable Transmission secure association and set PN threshold and OR
    Disable Transmission secure association.

    @behavior Sync, Non-Rentrant

    @pre SA is created/added and in disabled state

    @param[in]      aConnHdl              Connection handle (from RPC_Connect)
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
extern int32_t SECY_UpdateTxSA(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl,
                                uint64_t aPn, BCM_BoolType aEnable);

/**
    @brief Update RxSA

    Requests the Ethernet Switch to
    Enable Receive secure association and set Lowest PN OR
    Disable Receive secure association.

    @behavior Sync, Non-Rentrant

    @pre SA is created/added and in disabled state

    @param[in]      aConnHdl              Connection handle (from RPC_Connect)
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
extern int32_t SECY_UpdateRxSA(BCM_HandleType aConnHdl, BCM_HandleType aSAHdl,
                                uint64_t aPn, BCM_BoolType aEnable);

/**
    @brief Get SecY stats

    Request the Ethernet Switch to provide statistics of
    1.SecY
    2.Transmission Secure Channel
    2.Reception Secure Channel

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect)
    @param[in]      aSecYHdl        SecY Handle
    @param[in]      aTxSci          Tx SCI
    @param[in]      aRxSci          List of RxSCI's for which stats has to be fetched
    @param[in]      aRxSciCount     Total No of RxSCI's for which stats has to be fetched
    @param[out]     aStats          SecY,TxSC and RxSC statistics

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK              Success
    @return     #BCM_ERR_INVAL_PARAMS    aStats is NULL or
                                         aTxSci is NULL or
                                         aRxSci is NULL or
                                         aRxSciCount is '0'
                                         aSecYHdl is Invalid

    @post None

    @trace #BRCM_SWREQ_SECY

    @limitations None
*/
extern int32_t SECY_GetFullStats(BCM_HandleType aConnHdl, BCM_HandleType aSecYHdl,
                                   const SECY_SCIType *const aTxSci, const SECY_SCIType *const aRxSci,
                                   uint32_t aRxSciCount, SECY_AllStatsType *const aStats);
#endif /* CRYPTO_SECY_RPC_H */

/** @} */
