/*****************************************************************************
 Copyright 2021-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_macsecdrv_ifc Interface
    @ingroup grp_macsecdrv

    @addtogroup grp_macsecdrv_ifc
    @{
    @file macsec.h

    @brief MACSec driver interface
    This file defines MACSec Driver interfaces

    @version 0.1 Initial revision
*/

#ifndef MACSEC_H
#define MACSEC_H

#include <stdint.h>
#include <bcm_comp.h>
#include <crypto_secy_types.h>

/**
    @name MACSec driver API IDs
    @{
    @brief API IDs for MACSec driver
*/
#define BRCM_SWARCH_MACSEC_HWIDTYPE_TYPE                        (0x8001U) /**< @brief #MACSEC_HwIDType                */
#define BRCM_SWARCH_MACSEC_SECYHDLTYPE_TYPE                     (0x8002U) /**< @brief #MACSEC_SecYHdlType             */
#define BRCM_SWARCH_MACSEC_SAHDLTYPE_TYPE                       (0x8003U) /**< @brief #MACSEC_SAHdlType               */
#define BRCM_SWARCH_MACSEC_RULEHDLTYPE_TYPE                     (0x8004U) /**< @brief #MACSEC_RuleHdlType             */
#define BRCM_SWARCH_MACSEC_AN_TYPE                              (0x8005U) /**< @brief #MACSEC_ANType                  */
#define BRCM_SWARCH_MACSEC_MACSPEED_TYPE                        (0x8006U) /**< @brief #MACSEC_MacSpeedType            */
#define BRCM_SWARCH_MACSEC_INIT_PROC                            (0x8007U) /**< @brief #MACSEC_Init                    */
#define BRCM_SWARCH_MACSEC_ADD_CPRULE_OPT0_PROC                 (0x8008U) /**< @brief #MACSEC_AddCPRuleOpt0           */
#define BRCM_SWARCH_MACSEC_ADD_CPRULE_OPT1_PROC                 (0x8009U) /**< @brief #MACSEC_AddCPRuleOpt1           */
#define BRCM_SWARCH_MACSEC_CREATE_SECY_PROC                     (0x800AU) /**< @brief #MACSEC_CreateSecY              */
#define BRCM_SWARCH_MACSEC_GET_CIPHER_CAP_PROC                  (0x800BU) /**< @brief #MACSEC_GetCipherCap            */
#define BRCM_SWARCH_MACSEC_SET_CIPHER_SUITE_PROC                (0x800CU) /**< @brief #MACSEC_SetCipherSuite          */
#define BRCM_SWARCH_MACSEC_CREATE_TX_SC_PROC                    (0x800DU) /**< @brief #MACSEC_CreateTxSC              */
#define BRCM_SWARCH_MACSEC_CREATE_RX_SC_PROC                    (0x800EU) /**< @brief #MACSEC_CreateRxSC              */
#define BRCM_SWARCH_MACSEC_ADD_SECYLOOKUP_RULE_PROC             (0x800FU) /**< @brief #MACSEC_AddSecYLookupRule       */
#define BRCM_SWARCH_MACSEC_CREATE_TX_SA_PROC                    (0x8010U) /**< @brief #MACSEC_CreateTxSA              */
#define BRCM_SWARCH_MACSEC_CREATE_RX_SA_PROC                    (0x8011U) /**< @brief #MACSEC_CreateRxSA              */
#define BRCM_SWARCH_MACSEC_SET_PNTHRESHOLD_PROC                 (0x8012U) /**< @brief #MACSEC_SetPNThreshold          */
#define BRCM_SWARCH_MACSEC_SAENABLE_PROC                        (0x8013U) /**< @brief #MACSEC_SAEnable                */
#define BRCM_SWARCH_MACSEC_SADISABLE_PROC                       (0x8014U) /**< @brief #MACSEC_SADisable               */
#define BRCM_SWARCH_MACSEC_SET_PROTECT_FRAME_PROC               (0x8015U) /**< @brief #MACSEC_SetProtectFrame         */
#define BRCM_SWARCH_MACSEC_SET_REPLAY_PROTECT_PROC              (0x8016U) /**< @brief #MACSEC_SetReplayProtect        */
#define BRCM_SWARCH_MACSEC_SET_FRAME_VALIDATE_PROC              (0x8017U) /**< @brief #MACSEC_SetFrameValidate        */
#define BRCM_SWARCH_MACSEC_SAGET_STATUS_PROC                    (0x8018U) /**< @brief #MACSEC_SAGetStatus             */
#define BRCM_SWARCH_MACSEC_SAGET_NEXT_PN_PROC                   (0x8019U) /**< @brief #MACSEC_SAGetNextPN             */
#define BRCM_SWARCH_MACSEC_SASET_NEXT_PN_PROC                   (0x801AU) /**< @brief #MACSEC_SASetNextPN             */
#define BRCM_SWARCH_MACSEC_GET_SECYSTATS_PROC                   (0x801BU) /**< @brief #MACSEC_GetSecYStats            */
#define BRCM_SWARCH_MACSEC_GET_TX_SCSTATS_PROC                  (0x801CU) /**< @brief #MACSEC_GetTxSCStats            */
#define BRCM_SWARCH_MACSEC_GET_RX_SCSTATS_PROC                  (0x801DU) /**< @brief #MACSEC_GetRxSCStats            */
#define BRCM_SWARCH_MACSEC_REMOVE_CPRULE_PROC                   (0x801FU) /**< @brief #MACSEC_RemoveCPRule            */
#define BRCM_SWARCH_MACSEC_REMOVE_SECYLOOKUP_RULE_PROC          (0x8020U) /**< @brief #MACSEC_RemoveSecYLookupRule    */
#define BRCM_SWARCH_MACSEC_DELETE_TX_SC_PROC                    (0x8021U) /**< @brief #MACSEC_DeleteTxSC              */
#define BRCM_SWARCH_MACSEC_DELETE_RX_SC_PROC                    (0x8022U) /**< @brief #MACSEC_DeleteRxSC              */
#define BRCM_SWARCH_MACSEC_DELETE_SA_PROC                       (0x8023U) /**< @brief #MACSEC_DeleteSA                */
#define BRCM_SWARCH_MACSEC_DELETE_SECY_PROC                     (0x8024U) /**< @brief #MACSEC_DeleteSecY              */
#define BRCM_SWARCH_MACSEC_DE_INIT_PROC                         (0x8025U) /**< @brief #MACSEC_DeInit                  */
#define BRCM_SWARCH_MACSEC_GET_CIPHER_SUITE_PROC                (0x8026U) /**< @brief #MACSEC_GetCipherSuite          */
#define BRCM_SWARCH_MACSEC_EN_CTRL_PORT_PROC                    (0x8027U) /**< @brief #MACSEC_EnableCtrlPort          */
#define BRCM_SWARCH_MACSEC_DIS_CTRL_PORT_PROC                   (0x8028U) /**< @brief #MACSEC_DisableCtrlPort         */
#define BRCM_SWARCH_MACSEC_GET_PROT_STATUS_PROC                 (0x8029U) /**< @brief #MACSEC_GetPortStatus           */
/** @} */

/**
    @name MACSEC_HwIDType;
    @{
    @brief MACsec hardware index type

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE
*/
typedef uint32_t MACSEC_HwIDType;       /**< @brief  MACsec hardware index type */
/** @} */

/**
    @name SecY Handle type
    @{
    @brief MACsec SecY handle returned by the driver when SecY is created.

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE
*/
typedef BCM_HandleType MACSEC_SecYHdlType;       /**< @brief SecY Handle type */
/** @} */

/**
    @name MACSEC_SAHandleType
    @{
    @brief Secure association handle type
    Handle returned by the driver when SA is created

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE
*/
typedef BCM_HandleType MACSEC_SAHdlType;

/** @} */

/**
    @name MACSEC_RuleHdlType
    @{
    @brief rule Handle type
    Handle returned by the driver when a rule is created.

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE
*/
typedef BCM_HandleType MACSEC_RuleHdlType;
/** @} */

/**
    @name MACSEC_ANType
    @{
    @brief Association number type
    2-bit Association number mask and max values

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE
*/
typedef uint8_t MACSEC_ANType;
#define MACSEC_AN_MASK      (3U)
#define MACSEC_AN_MAX       (3U)
/** @} */

/**
    @name MACSEC_MacSpeedType
    @{
    @brief MAC speed types
    MAC Speed configuration values

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE
*/
typedef uint32_t MACSEC_MacSpeedType;
#define MACSEC_MACSPEED_100MBPS     (1UL)   /**< @brief 100 Mbps speed */
#define MACSEC_MACSPEED_1000MBPS    (2UL)   /**< @brief 1 Gbps speed */
#define MACSEC_MACSPEED_2500MBPS    (3UL)   /**< @brief 2.5 Gbps speed */
/** @} */

/**
    @brief Initialize MACSec

    Initialize MACSec hardware and driver.

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aHwID       Index of the hardware (depending upon system configuration, this
                                index could be same as index of the switch port (for multiport
                                switch with each port having its own SecY instance) or 0 (for
                                end-points))
    @param[in]      aConfig     Pointer to configuration structure

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              MACSEC initialization was successful
    @return     BCM_ERR_INVAL_PARAMS    aHwID is invalid or
                                        aConfig in NULL or some of the configuration parameters
                                        are not correct.
    @return     BCM_ERR_INVAL_STATE     MACSEC is already initialized.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_Init(BCM_HandleType aConnHdl, MACSEC_HwIDType aHwID, const SECY_HwCfgType *const aConfig);

/**
    @brief Add control packet rule (option 0)

    Add a control packet rule in the hardware and return the handle of the rule.
    Multiple control packet rules (option 0) can be added on a given port (limited by underlying
    hardware resource. Refer to TRM for the details about how many rules are allowed).

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aHwID           Index of the hardware
    @param[in]      aRule           Rule to add
    @param[out]     aRuleHandle     Handle to rule

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Rule was added successfully
    @return     BCM_ERR_INVAL_PARAMS    aHwID is invalid or
                                        aRule is NULL or
                                        aRuleIdx is NULL or
                                        some of the parameters in aRule is not correct.
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_NOMEM           No more space to add new rule
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_AddCPRuleOpt0(BCM_HandleType aConnHdl, MACSEC_HwIDType aHwID,
                             const SECY_RuleOpt0Type *const aRule,
                             MACSEC_RuleHdlType *const aRuleHandle);

/**
    @brief Add control packet rule (Option 1)

    Add a control packet rule in the hardware and return the handle of the rule.
    Multiple control packet rules (option 1) can be added on a given port (limited by underlying
    hardware resource. Refer to TRM for the details about how many rules are allowed).

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aHwID           Index of the hardware
    @param[in]      aRule           Rule to add
    @param[out]     aRuleHdl        Handle to rule

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Rule was added successfully
    @return     BCM_ERR_INVAL_PARAMS    aHwID is invalid or
                                        aRule is NULL or
                                        aRuleIdx is NULL or
                                        some of the parameters in aRule is not correct.
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_NOMEM           No more space to add new rule
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_AddCPRuleOpt1(BCM_HandleType aConnHdl, MACSEC_HwIDType aHwID,
                             const SECY_RuleOpt1Type *const aRule,
                             MACSEC_RuleHdlType *const aRuleHdl);
/**
    @brief Create SecY instance

    Creates a SecY instance and returns the handle to user in
    aSecYHdl parameter.

    @note
    @behavior Sync, Non-Rentrant

    @pre MACSEC hardware is initialized (#MACSEC_Init() returned success)

    @param[in]     aConnHdl             Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]     aID                  MACSEC hardware index on which this SecY instance to
                                        be created.
    @param[in]     aCfg                 SecY configuration.
    @param[out]    aSecYHdl             Handle to SecY instance.

    @return        BCM_ERR_OK           SecY was created successfully and value returned in aSecYHdl
                                        is valid.
    @return        BCM_ERR_UNINIT       MACSEC is not initialized.
    @return        BCM_ERR_INVAL_PARAMS aID is invalid or
                                        aSecYHdl is NULL.
    @return        BCM_ERR_NOMEM        Can not create more SecY instances on this harware port
                                        (aID).
    @return        BCM_ERR_UNKNOWN      Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_CreateSecY(BCM_HandleType aConnHdl, MACSEC_HwIDType aID,
                          const SECY_CfgType *const aCfg,
                          MACSEC_SecYHdlType *const aSecYHdl);
/**
    @brief Get cipher suite capability

    Provides the supported cipher suites and its capabilities.

    @note None

    @behavior Sync, Non-Rentrant

    @pre SecY must be initialized before calling this API

    @param[in]     aConnHdl     Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]     aHwID        Index of the MACSEC hardware.
    @param[in]     aCipherID    ID of the cipher suite for which capability need to be checked.
    @param[out]    aCap         Capability of the cipher suite

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success (value returned in aCap is valid)
    @return     BCM_ERR_INVAL_PARAMS    aHwID is invalid or
                                        aCipherID is invalid or
                                        aCap is NULL.
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_NOSUPPORT       Given cipher (@aCipherID) is not supported by hardware.
    @return     BCM_ERR_UNKNOWN         Integration error.
    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_GetCipherCap(BCM_HandleType aConnHdl, MACSEC_HwIDType aID,
                            SECY_CipherType aCipherID,
                            SECY_CipherCapType *const aCap);

/**
    @brief Set the cipher suite for SecY

    Set the given cipher suite for SecY.

    @note Cipher suite must be supported by the system (MACSEC_GetCipherCap() API has returned
          BCM_ERR_OK for given cipher suite)

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl     Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]     aSecYHdl     SecY handle.
    @param[in]     aCipherID    ID of the cipher suite
    @param[out]    aConfOffset  Confidentiality offset to be used (For XPN cipher suites, this must
                                be set to 0).

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
                                        aCipherID is invalid or
                                        aOffset is invalid.
                                        wrong cipher suite is being selected (for example,
                                        XPN is enabled for SecY for non xpn cipher suites
                                        is being set).
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_NO_SUPPORT      Given cipher (@aCipherID) is not supported.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_SetCipherSuite(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                              SECY_CipherType aCipherID,
                              SECY_ConfOffsetType aOffset);
/**
    @brief Get the cipher suite for SecY

    Get the given cipher suite for SecY.

    @note Cipher suite must be supported by the system

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl     Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]     aSecYHdl     SecY handle.
    @param[out]    aCipherID    ID of the cipher suite
    @param[out]    aConfOffset  Confidentiality offset

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl or aConnHdl is invalid
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_GetCipherSuite(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                              SECY_CipherType* aCipherID,
                              SECY_ConfOffsetType* aOffset);
/**
    @brief Create transmit secure channel

    Create secure transmit channel on given SecY

    @note None

    @behavior Sync, Non-Rentrant

    @pre SecY must be initialized before calling this API

    @param[in]      aConnHdl    Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl    SecY Handle
    @param[in]      aSCI        Secure channel information

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
                                        aSCI is NULL or
                                        aSCI has reserved value (All 0xFF's) or
                                        macaddr field in the SCI is all 0's or
    @return     BCM_ERR_BUSY            Secure channel already created.
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_CreateTxSC(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl, const SECY_SCIType *const aSCI);

/**
    @brief Create receive secure channel

    Create receive secure channel on given SecY

    @note None

    @behavior Sync, Non-Rentrant

    @pre SecY must be initialized before calling this API

    @param[in]      aConnHdl    Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl    SecY Handle.
    @param[in]      aSCI        Secure channel information

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
                                        aSCI is NULL or
                                        aSCI has reserved value (All 0xFF's) or
                                        macaddr field in the SCI is all 0's or
                                        Secure channel already created for same SCI.
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_NOMEM           Can not create more receive channel on this SecY.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_CreateRxSC(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl, const SECY_SCIType *const aSCI);

/**
    @brief Add SecY lookup rule

    Add a rule for SecY lookup and returns rule handle.

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl    SecY Handle
    @param[in]      aRule       Rule to add
    @param[out]     aRuleHdl    Rule Handle

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Rule was added successfully
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
                                        aRule is NULL or
                                        aRuleHdl is NULL or
                                        some of the parameters in aRule is not correct.
    @return     BCM_ERR_UNINIT          MACSEC is not initialized.
    @return     BCM_ERR_NOMEM           No more space to add new rule
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_AddSecYLookupRule(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                                const SECY_RuleOpt1Type *const aRule,
                                MACSEC_RuleHdlType *const aRuleHdl);
/**
    @brief Create transmit secure association

    Create a transmit secure association on given SecY and return the handle of the newly
    created SA.
    When SA is created, it's not enabled. client need to enable the SA by calling #MACSEC_SAEnable
    function.

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl            SecY Handle.
    @param[in]      aAN                 Association number.
    @param[in]      aNextPN             Next PN number incremented by 1 to be used for this SA.
                                        (for example, if first packet has to be send with PN = 1,
                                        this shall be set to 0).
    @param[in]      aSCI                SCI for which SA has to be created
    @param[in]      aSSCI               32-bit SSCI value for this SCI if XPN cipher is used.
                                        example: if SSCI bytes are {0x7A, 0x30, 0xC1, 0x18},
                                        then, aSCCI = (0x7A | 0x30 << 8 | 0xC1 << 16 | 0x18 << 24);
                                        user must ensure that same SSCI is not being used for other
                                        SCI in same SecY.
                                        If XPN cipher is not used for this SecY,
                                        this parameter shall be set to 0.
    @param[in]      aConfidentiality    TRUE: Enable confidentiality protection on this SA
                                        (payload encrypted and ICV is appended)
                                        FALSE: Disable confidentiality protection on this SA
                                        (data flows in plain, ICV is appended for the authentication)
    @param[in]      aKey                key
    @param[out]     aSAHandle           A non-zero SA handle (value is valid only when API
                                        returns BCM_ERR_OK)

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
                                        aAN is > 3 or
                                        aNextPN == 0 or > 0xFFFFFFFF (32-bit) or
                                        aSCI is NULL or SC not created for this SCI (aSCI) or
                                        Duplicate SSCI value for the same SCI or
                                        aSAHandle is NULL.
    @return     BCM_ERR_NOMEM           Out of the resource.
    @return     BCM_ERR_BUSY            Trying to update the active SA (aAN is encodingSA).
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_CreateTxSA(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                          MACSEC_ANType aAN, uint64_t aNextPN,
                          const SECY_SCIType *const aSCI, uint32_t aSSCI,
                          uint32_t aConfidentiality,
                          const SECY_KeyType *const aKey,
                          MACSEC_SAHdlType *const aSAHandle);

/**
    @brief Create receive secure association

    Create a receive secure association on given SecY and returns the handle of the newly
    created SA.

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl            SecY Handle.
    @param[in]      aAN                 Association number.
    @param[in]      aLowestPN           Lowest acceptable PN number for receive SA (must be > 0 and
                                        < 0xFFFFFFFFF for 32-bit PN and < 0xFFFFFFFFFFFFFFFF for
                                        XPN).
    @param[in]      aSCI                SCI for which SA has to be created
    @param[in]      aSSCI               32-bit SSCI value for this SCI if XPN cipher is used.
                                        example: if SSCI bytes are {0x7A, 0x30, 0xC1, 0x18},
                                        then, aSCCI = (0x7A << 24 | 0x30 << 16 | 0xC1 << 8 | 0x18);
                                        user must ensure that same SSCI is not being used for other
                                        SCI in same SecY.
                                        If XPN cipher is not used for this SecY,
                                        this parameter shall be set to 0.
    @param[in]      aKey                key
    @param[out]     aSAHandle           A non-zero SA handle (value is valid only when API
                                        returns BCM_ERR_OK)

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
                                        aAN is > 3 or
                                        aNextPN == 0 or > 0xFFFFFFFF (32-bit) for SecY and XPN is
                                        not enabled or
                                        aSCI is invalid or
                                        aSCI is NULL or SC not created for this SCI (aSCI) or
                                        Duplicate SSCI value for the same SCI (in case of XPN) or
                                        aSAHandle is NULL.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_CreateRxSA(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                          MACSEC_ANType aAN, uint64_t aLowestPN,
                          const SECY_SCIType *const aSCI, uint32_t aSSCI,
                          const SECY_KeyType *const aKey, MACSEC_SAHdlType *const aSAHandle);

/**
    @brief Set PN threshold for transmit SA

    Set packet number threshold for the transmit SA. When transmit sequence number
    (nextPN value) for SA crosses this threshold, a IRQ event bit is set (refer
    to #MACSEC_IRQEventType) by the driver IRQ handler as a return paramter.
    Client shall setup the new SA before the PN expiry.

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl            Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSAHdl              SA handle
    @param[in]      nextPNThrld         Threshold for the nextPN

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aSAHdl is invalid or
                                        nextPNThrld is invalid
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_SetPNThreshold(BCM_HandleType aConnHdl, MACSEC_SAHdlType aSAHdl, uint64_t nextPNThrld);

/**
    @brief Enable Control Port

    @behavior Sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl       SacY Handle

    @return     BCM_ERR_OK              success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid
    @return     BCM_ERR_TIME_OUT        hardware error.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post if returned BCM_ERR_OK then all the SecY Tag PDU is pass for the further processing by SecY Controlled port.

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_EnableCtrlPort(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl);

/**
    @brief Disable Control Port

    @behavior Sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl       SacY Handle

    @return     BCM_ERR_OK              success
    @return     BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid
    @return     BCM_ERR_TIME_OUT        hardware error.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post if returned BCM_ERR_OK then all the SecY Tag PDU is droped.

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_DisableCtrlPort(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl);

/**
    @brief Enable SA

    Enable an inactive SA.
    For transmit, if this is not currently active SA (it's not encoding SA), it will become
    active after API returns (will become encoding SA). If SecY Tx SC was not transmitting, it will
    become ready for transmitting.  Old SA is not automatically deleted and
    Client need to call #SADisable() followed by #DeleteSA() to free-up the resources.
    For receive, if this SA was not already enabled, it will become active. If none of the SAs
    for this SC was active, SC will become active and ready to receive.

    @behavior Sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSAHdl         SA Handle

    @return     BCM_ERR_OK              success
    @return     BCM_ERR_INVAL_PARAMS    aSAHdl is invalid
    @return     BCM_ERR_TIME_OUT        hardware error.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post if returned BCM_ERR_OK, this SA becomes active and all the matching data flow through this
          SA is allowed

    @note   Once this API returns success, previous SA is not automatically removed by the driver.
            User shall delete the SA by calling #MACSEC_DeleteSA() API

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SAEnable(BCM_HandleType aConnHdl, MACSEC_SAHdlType aSAHdl);

/**
    @brief Disable SA

    Disables an active SA.

    @note None

    @behavior Sync, Non-Rentrant

    @pre SA is created using MACSEC_SACreate() API

    @param[in]      aConnHdl       Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSAHdl         SA handle

    @return     BCM_ERR_OK              success
    @return     BCM_ERR_INVAL_PARAMS    aSAHdl is invalid.
    @return     BCM_ERR_INVAL_STATE     SA is not in-use.
    @return     BCM_ERR_TIME_OUT        hardware error.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post if returned BCM_ERR_OK, this SA becomes in-active and all data traffic through this SA is
          dropped

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SADisable(BCM_HandleType aConnHdl, MACSEC_SAHdlType aSAHdl);

/**
    @brief Set frame protection

    Enable/Disable frame protection on this SecY.
    if frame protection is disabled, SecY sends the packet without
    any modification (without SecTAG and encryption).

    @note This API is provided only for debug purpose.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl      Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl      SecY Handle
    @param[in]    aEnable       TRUE: Enable Frame protection
                                FALSE: Disable Frame protection

    @return    BCM_ERR_OK              success
    @return    BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid
    @return    BCM_ERR_UNKNOWN         Integration error.

    @post

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SetProtectFrame(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl, uint32_t aEnable);

/**
    @brief Set replay protection

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

    @param[in]    aConnHdl      Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl      SecY handle
    @param[in]    aEnable       TRUE: Enable replay protection
                                FALSE: Disable replay protection
    @param[in]    aWindow       Replay protection window

    @return    BCM_ERR_OK              success
    @return    BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid
    @return    BCM_ERR_UNKNOWN         Integration error.

    @post

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SetReplayProtect(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                                uint32_t aEnable, uint32_t aWindow);

/**
    @brief Set Frame validate option

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

    @param[in]    aConnHdl          Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl          SecY Handle
    @param[in]    aValideFrame      Validate frame option

    @return    BCM_ERR_OK               success
    @return    BCM_ERR_INVAL_PARAMS     aSecYHdl is invalid or
                                        aValidateFrame is invalid
    @return    BCM_ERR_UNINIT           MACSEC is not initialized.
    @return    BCM_ERR_UNKNOWN          Integration error.

    @post

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SetFrameValidate(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecHdl,
                                SECY_ValidateFrameType aValidateFrame);

/**
    @brief Get SA status

    Read the status of an SA.

    @note

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl      Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSAHdl        SA Handle
    @param[out]   aStatus       Pointer to status structure where SA status is updated

    @return    BCM_ERR_OK               success
    @return    BCM_ERR_INVAL_PARAMS     aSAHdl is invalid or
                                        aStatus is NULL.
    @return    BCM_ERR_UNKNOWN          Integration error.

    @post  None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SAGetStatus(BCM_HandleType aConnHdl, MACSEC_SAHdlType aSAHdl,
                           SECY_SAStatusType *const aStatus);

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
    @note

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl              Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSAHdl                SA handle
    @param[out]   aPN                   PN value

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSAHdl is invalid or
                                        aPN is NULL
    @return       BCM_ERR_UNKNOWN       Integration error.

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SAGetNextPN(BCM_HandleType aConnHdl, MACSEC_SAHdlType aSAHdl, uint64_t *aPN);

/**
    @brief Updates nextPN value for receive SA

    Updates the nextPN value for given receive SA

    @note

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl      Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSAHdl        SA Handle
    @param[in]    aPN           PN value

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSAHdl is invalid or
                                        aPN value is greater than 32-bit and XPN is not enabled
                                        for this SecY.
    @return       BCM_ERR_TIME_OUT      hardware error.
    @return       BCM_ERR_UNKNOWN       Integration error.

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_SASetNextPN(BCM_HandleType aConnHdl, MACSEC_SAHdlType aSAHdl, uint64_t aPN);

/**
    @brief Get SecY stats

    @note

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl      Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl      SecY handle
    @param[out]   aStats        pointer to stats structure

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSecYHdl is invalid or
                                        aStats is NULL or
    @return       BCM_ERR_UNKNOWN       Integration error.

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_GetSecYStats(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                            SECY_StatsType *const aStats);

/**
    @brief Get Transmit secure channel stats

    @note

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl      Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl      SecY index
    @param[in]    aSCI          SCI
    @param[out]   aStats        pointer to stats structure

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSecYHdl is invalid or
                                        aSCI is invalid or
                                        aSCI is not created for this SecY or
                                        aStats is NULL.
    @return       BCM_ERR_UNKNOWN       Integration error.

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_GetTxSCStats(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                            const SECY_SCIType *const aSCI,
                            SECY_TxSCStatsType *const aStats);

/**
    @brief Get receive secure channel stats

    @note

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl      Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl      SecY index
    @param[in]    aSCI          SCI
    @param[out]   aStats        pointer to stats structure

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSecYHdl is invalid or
                                        aSCI is invalid or
                                        aStats is NULL.
    @return       BCM_ERR_UNINIT        MACSEC is not initialized.
    @return       BCM_ERR_UNKNOWN       Integration error.

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_GetRxSCStats(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                            const SECY_SCIType *const aSCI,
                            SECY_RxSCStatsType *const aStats);

/**
    @brief Remove control packet rule

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl     Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]     aHwID        Index of the hardware
    @param[in]     aRuleHdl     Handle to rule

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Rule was removed successfully
    @return     BCM_ERR_INVAL_PARAMS    aHwID is invalid or
                                        aRuleHdl is invalid.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_RemoveCPRule(BCM_HandleType aConnHdl, MACSEC_HwIDType aHwID, MACSEC_RuleHdlType aRuleHdl);

/**
    @brief Remove secure channel lookup rule

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aConnHdl    Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]     aRuleHdl    Rule handle

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Rule was removed successfully
    @return     BCM_ERR_INVAL_PARAMS    aRuleHdl is invalid.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_RemoveSecYLookupRule(BCM_HandleType aConnHdl, MACSEC_RuleHdlType aRuleHdl);

/**
    @brief Delete Transmit SC

    Delete Transmit SC on given SecY.

    @note user shall ensure that all SAs created on this sc are deleted
    before calling this api.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl              Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl              SecY handle
    @param[in]    aSCI                  SCI information

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSecYHdl is invalid or
                                        aSCI is NULL or
                                        aSCI is invalid
    @return       BCM_ERR_UNINIT        MACSEC not initialized
    @return       BCM_ERR_UNKNOWN       integration error

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_DeleteTxSC(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                          const SECY_SCIType *const aSCI);

/**
    @brief Delete Receive SC

    Delete receive SC on given SecY.

    @note user shall ensure that all SAs created on this sc are deleted
    before calling this api.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl              Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSecYHdl              SecY Handle
    @param[in]    aSCI                  SCI information

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSecYHdl is invalid or
                                        aSCI is NULL or
                                        aSCI is invalid.
    @return       BCM_ERR_UNINIT        MACSEC not initialized
    @return       BCM_ERR_UNKNOWN       integration error

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_DeleteRxSC(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl,
                          const SECY_SCIType *const aSCI);

/**
    @brief Delete SA

    Delete SA on given SecY instance.

    @note

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl              Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aSAHdle               SA handle

    @return       BCM_ERR_OK            success
    @return       BCM_ERR_INVAL_PARAMS  aSAHdl is invalid
    @return       BCM_ERR_UNKNOWN       integration error

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_DeleteSA(BCM_HandleType aConnHdl, MACSEC_SAHdlType aSAHdl);

/**
    @brief Delete SecY entity
    Delete SecY entity and free up the resources on the hardware.

    @note

    @behavior Sync, Non-Rentrant

    @pre SecY is in initialized state

    @param[in]      aConnHdl            Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aSecYHdl            SecY Handle

    @return         BCM_ERR_OK              success
    @return         BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid or
    @return         BCM_ERR_UNKNOWN         integration error

    @post   None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_DeleteSecY(BCM_HandleType aConnHdl, MACSEC_SecYHdlType aSecYHdl);

/**
    @brief De-Initialize MACSec

    De-Initialize MACSec hardware and driver.

    @note None

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]      aHwID       Index of the hardware

    Return values are documented in reverse-chronological order
    @return     BCM_ERR_OK              Success
    @return     BCM_ERR_INVAL_PARAMS    aHwID is invalid or
    @return     BCM_ERR_INVAL_STATE     MACSEC is already de-initialized.
    @return     BCM_ERR_UNKNOWN         Integration error.

    @post None

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
int32_t MACSEC_DeInit(BCM_HandleType aConnHdl, MACSEC_HwIDType aHwID);

/**
    @brief Get Secy Port Status of given aID

    @note This API is provided only for debug purpose.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]    aConnHdl              Connection handle (from RPC_Connect/MDIO_Open)
    @param[in]    aHwID                 Index of the hardware
    @param[out]   aSecYPortStatus       Port Status

    @return    BCM_ERR_OK              success
    @return    BCM_ERR_INVAL_PARAMS    aSecYHdl is invalid
    @return    BCM_ERR_UNKNOWN         Integration error.

    @post

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
 */
int32_t MACSEC_GetPortStatus(BCM_HandleType aConnHdl, MACSEC_HwIDType aID, SECY_PortStatusType* const aPortStatus);

#endif /* MACSEC_H */
/** @} */
