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
    @defgroup grp_crypto_key_store_rpc_ifc Crypto key store RPC Interface for host
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_key_store_rpc_ifc
    @{

    @limitations None

    @file crypto_keystore_rpc.h
    @brief Crypto key store RPC Interface for host
    This header file contains the interface functions exposed to the host
    @version 0.1 Initial Version
*/
#ifndef CRYPTO_KEY_STORE_RPC_H
#define CRYPTO_KEY_STORE_RPC_H

#include <crypto_common.h>
#include <msg_queue.h>
#include <crypto_memory.h>

/**
    @name Crypto Keystore RPC Architecture IDs
    @{
    @brief Architecture IDs for Crypto keystore RPC
*/
#define BRCM_SWARCH_KST_HOST_ID_OF_MACRO                     (0x8C01U) /**< @brief #KST_HOST_ID_OF                 */
#define BRCM_SWARCH_KST_HOST_ID_TYPE                         (0x8C02U) /**< @brief #KST_HostIDType                 */
#define BRCM_SWARCH_KST_HOST_GENERATE_AND_SETUP_DUK_MSG_TYPE (0x8C03U) /**< @brief #KST_HostGenerateAndSetupDukMsgType */
#define BRCM_SWARCH_KST_HOST_GENERATE_AND_SETUP_DUK_PROC     (0x8C04U) /**< @brief #KST_HostGenerateAndSetupDuk        */
/** @} */

/**
    @brief Macro to Construct CmdID

    @trace #BRCM_SWREQ_KST
*/
#define KST_HOST_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_CRYPTO, BCM_KSTMOD_ID, aId)

/**
    @name Key store Message IDs
    @{
    @brief Message IDs for exchange on message queues and Host

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_KST
*/
typedef BCM_MsgType KST_HostIDType;     /**< @brief Key store message ID Type */
#define KST_HOST_ID_STATUS_OUT_MASK     (0x10UL)
#define KST_HOST_ID_GEN_AND_SETUP_DUK   KST_HOST_ID_OF(KST_HOST_ID_STATUS_OUT_MASK | 0x01UL) /**< @brief Generate a DUK and write it to the OTP */
/** @} */

/**
    @brief Generate and setup DUK message type

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_HostGenerateAndSetupDukMsgType {
    uint32_t reserved;
} KST_HostGenerateAndSetupDukMsgType;

/** @brief Generate and setup the DUK

    Interface to write public key to OTP rows

    @behavior Sync, None re-entrant

    @pre TBD

    @param[in]    aHdl        Connection handle
                                  - RPC Handle for Host
                                  - Msg Handle for Module
                                  - NULL for Internal Consumption
    @param[in]    aMsg        DUK generate and setup message

    Return values are documented in reverse-chronological order

    @retval      #BCM_ERR_OK              DUK has been generated and has been setup
    @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
    @retval      #BCM_ERR_NOSUPPORT       Requested operation not supported.

    @post TBD

    @trace #BRCM_SWREQ_KST

    @limitations
*/
int32_t KST_HostGenerateAndSetupDuk(BCM_HandleType aHdl, const KST_HostGenerateAndSetupDukMsgType *const aMsg);

#endif /* CRYPTO_KEY_STORE_RPC_H */
/** @} */
