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
    @defgroup grp_crypto_key_store_local_ifc Crypto key store Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_key_store_local_ifc
    @{

    @limitations None

    @file crypto_keystore_local.h
    @brief Crypto key store Interface
    This header file contains the interface functions to manage Crypto keys
    @version 0.1 Initial Version
*/

#ifndef CRYPTO_KEY_STORE_LOCAL_H
#define CRYPTO_KEY_STORE_LOCAL_H

#include <crypto_common.h>
#include <crypto_keystore.h>

/**
    @name KST message Architecture IDs
    @{
    @brief Architecture IDs for the KST message interface
*/
#define BRCM_SWARCH_KST_MSG_UNION_TYPE      (0x8A01U)    /**< @brief #KST_MsgUnionType      */
#define BRCM_SWARCH_KST_MSG_TYPE            (0x8A02U)    /**< @brief #KST_MsgType           */
/** @} */

/**
    @brief Key management union encapsulating all messages

    @trace #BRCM_SWREQ_KST
*/
typedef union uKST_MsgUnionType {
    KST_CreateZeroKeyType   keyCreateZero;  /**< @brief To create a zero key    */
    KST_CreateRandKeyType   keyCreateRand;  /**< @brief To create a rand key    */
    KST_CreateDHKeyType     keyCreateDH;    /**< @brief To create a key via DH  */
    KST_CreateKDFKeyType    keyCreateKDF;   /**< @brief To create a key via KDF */
    CMEM_HdlType            inKeyHdl;       /**< @brief In key handle           */
    KST_ImportKeyType       keyImport;      /**< @brief Key import              */
    KST_ExportKeyType       keyExport;      /**< @brief Key export              */
    KST_ExportRawKeyType    rawKeyExport;
    KST_GetKeyHdlsType      getKeyHdls;     /**< @brief Get key handle message  */
    KST_GetUserInfoType     getUserInfo;    /**< @brief Get user info           */
    KST_GetExpKeyHdlsType   getExpKeyHdls;  /**< @brief Get exportable key hdls */
} KST_MsgUnionType;
_Static_assert(56UL == sizeof(KST_MsgUnionType),
    "Size assertion for KST_MsgUnionType failed!");

/**
    @brief Crypto key management message structure

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_MsgType {
    KST_IDType           cmd;        /**< @brief Command ID          */
    int32_t              response;   /**< @brief Response            */
    KST_MsgUnionType     u;          /**< @brief Message union       */
} KST_MsgType;
_Static_assert(64UL == sizeof(KST_MsgType),
    "Size assertion for KST_MsgType failed!");

#endif /* CRYPTO_KEY_STORE_LOCAL_H */
/** @} */
