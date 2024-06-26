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
    @defgroup grp_sec_otp_ifc Secure OTP Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_sec_otp_ifc
    @{

    @limitations None

    @file crypto_secotp.h
    @brief Crypto MAC Security Entity (MACSEC) Interface
    This header file contains the interface functions for Crypto MAC Security Entity (MACSEC)

    @version 1.0 Initial Version
*/

#ifndef CRYPTO_SECOTP_H
#define CRYPTO_SECOTP_H

#include <stdint.h>
#include <bcm_comp.h>
#include <crypto_common.h>

/**
    @name Crypto SecY Architecture IDs
    @{
    @brief Architecture IDs for Crypto SecY
*/
#define BRCM_SWARCH_SECOTP_MAX_PAYLOAD_SIZE_MACRO (0x8101U) /**< @brief #SECOTP_MAX_PAYLOAD_SIZE  */
#define BRCM_SWARCH_SECOTP_READ_MVK_PROC          (0x8102U) /**< @brief #SECOTP_ReadMvk           */
#define BRCM_SWARCH_SECOTP_WRITE_MVK_PROC         (0x8103U) /**< @brief #SECOTP_WriteMvk          */

#define BRCM_SWARCH_SECOTP_ID_OF_MACRO            (0x8141U) /**< @brief #SECOTP_ID_OF             */
#define BRCM_SWARCH_SECOTP_CMD_TYPE               (0x8142U) /**< @brief #SECOTP_CmdIDType         */
#define BRCM_SWARCH_SECOTP_MVK_MSG_TYPE           (0x8143U) /**< @brief #SECOTP_MvkMsgType        */
/** @} */

/**
    @brief Maximum size of CRYPTO MACSEC OTP payload in bytes

    @trace #BRCM_SWREQ_SECOTP
*/
#define SECOTP_MAX_PAYLOAD_SIZE        (264UL)

/**
    @brief Secure OTP command ID generation

    @trace #BRCM_SWREQ_SECOTP
 */
#define SECOTP_ID_OF(x)                   BCM_MSG(BCM_GROUPID_CRYPTO, BCM_SOT_ID, (x))

/**
    @name CRYPTO SecY Message IDs
    @{
    @brief Message IDs for exchange on message queues

    @trace #BRCM_SWREQ_SECOTP
*/
typedef uint32_t SECOTP_CmdIDType;     /**< @brief Pa message Type */
#define SECOTP_CMD_MVK_READ        SECOTP_ID_OF(1UL) /**< @brief #SECOTP_MvkDataType */
#define SECOTP_CMD_MVK_WRITE       SECOTP_ID_OF(2UL) /**< @brief #SECOTP_MvkDataType */
#define SECOTP_CMD_READ            SECOTP_ID_OF(0x80UL) /**< @brief #OTPM_ReadMsgType  */
#define SECOTP_CMD_WRITE           SECOTP_ID_OF(0x81UL) /**< @brief #OTPM_WriteMsgType */
/** @} */

/**
    @brief OTP Module MVK Read Write data

    @trace #BRCM_SWREQ_SECOTP
 */
typedef struct sSECOTP_MvkMsgType {
    CRYPTO_KeyType  keyType;         /**< @brief Key type RSA/ECDSA */
    uint32_t        keyLength;       /**< @brief Key length in bytes */
    uint8_t         keyValue[256UL]; /**< @brief Buffer to store the MKV */
} SECOTP_MvkMsgType;
BCM_STATIC_SIZE_ASSERT(SECOTP_MvkMsgType, 264UL, SECOTP_MAX_PAYLOAD_SIZE)

/** @brief Read MVK

  Interface to read public key from OTP rows

  @behavior Sync, None re-entrant

  @pre TBD

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[out]   aMvk       Pointer to the SECOTP_MvkMsgType

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              OTP public key read was successful
  @retval      #BCM_ERR_DATA_INTEG      Public key is Invalid
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOT_FOUND       Not a secure variant
  @retval      #BCM_ERR_NOMEM           aBufSize is less than Public key size
  @retval      #BCM_ERR_NOSUPPORT       Requested operation not supported.
  @retval      #BCM_ERR_INVAL_PARAMS    aMvk is NULL

  @post TBD

  @trace #BRCM_SWREQ_SECOTP

  @limitations

*/
int32_t SECOTP_ReadMvk(BCM_HandleType aHdl, SECOTP_MvkMsgType *const aMvk);

/** @brief Write MVK

  Interface to write public key to OTP rows

  @behavior Sync, None re-entrant

  @pre TBD

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[in]   aMvk       Pointer to the SECOTP_MvkMsgType

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              OTP public key read was successful
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOSUPPORT       Requested operation not supported.
  @retval      #BCM_ERR_INVAL_PARAMS    aMvk is NULL

  @post TBD

  @trace #BRCM_SWREQ_SECOTP

  @limitations

*/
int32_t SECOTP_WriteMvk(BCM_HandleType aHdl, const SECOTP_MvkMsgType *const aMvk);
#endif /* CRYPTO_SECOTP_H */

/** @} */

