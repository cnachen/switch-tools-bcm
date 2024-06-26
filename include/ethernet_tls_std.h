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
  @defgroup grp_tls_abstract_def TLS Definitions
  @ingroup grp_ethernet_abstract

  @addtogroup grp_tls_abstract_def
  @{
  @file ethernet_tls_std.h
  @brief Common definitions for the TLS

  This file provides the common definitions for the TLS

  @version 0.1 Initial version
*/
#ifndef ETHERNET_TLS_STD_H
#define ETHERNET_TLS_STD_H

#include <stdint.h>

/**
    @name Architecture IDs
    @{
    @brief Architecture IDs for TLS interface
 */
#define BRCM_SWARCH_TLS_VERSION_TYPE                (0x7401U) /**< @brief #TLS_VersionType  */
#define BRCM_SWARCH_TLS_CIPHER_TYPE                 (0x7402U) /**< @brief #TLS_CipherSuiteType  */
#define BRCM_SWARCH_TLS_NAMED_CURVE_TYPE            (0x7403U) /**< @brief #TLS_NamedCurveType  */
#define BRCM_SWARCH_TLS_SIGN_ALGO_TYPE              (0x7404U) /**< @brief #TLS_SignAlgoType  */
#define BRCM_SWARCH_TLS_CONN_TYPE                   (0x7405U) /**< @brief #TLS_ConnectionType  */
/** @} */


/**
    @name TLS_VersionType
    @{
    @brief TLS version identifier

    @trace #BRCM_SWREQ_TLS
*/
typedef uint16_t TLS_VersionType;             /**< @brief typedef for version */
#define TLS_VERSION_1_0         (0x0301U)      /**< @brief TLS version 1.0 */
#define TLS_VERSION_1_1         (0x0302U)      /**< @brief TLS version 1.1 */
#define TLS_VERSION_1_2         (0x0303U)      /**< @brief TLS version 1.2 */
#define TLS_VERSION_1_3         (0x0304U)      /**< @brief TLS version 1.3 */
/** @} */

/**
    @name TLS_CipherSuiteType
    @{
    @brief TLS version based cipher suites

    @trace #BRCM_SWREQ_TLS
*/
typedef uint16_t TLS_CipherSuiteType;          /**< @brief typedef for cipher suite */
#define TLS_CIPHER_INVALID                       (0x0000U)  /**< @brief Invalid  */
#define TLS_CIPHER_1_3_AES_128_GCM_SHA256        (0x1301U)  /**< @brief TLS 1.3 AES 128 GCM SHA256 */
#define TLS_CIPHER_1_3_AES_256_GCM_SHA384        (0x1302U)  /**< @brief TLS 1.3 AES 256 GCM SHA384 */
#define TLS_CIPHER_1_3_CHACHA20_POLY1305_SHA256  (0x1303U)  /**< @brief TLS 1.3 AES CHACHA20 POLY1305 SHA256 @xsd hide */
#define TLS_CIPHER_1_3_AES_128_CCM_SHA256        (0x1304U)  /**< @brief TLS 1.3 AES 128 CCM SHA256 @xsd hide */
#define TLS_CIPHER_1_3_AES_128_CCM_8_SHA256      (0x1305U)  /**< @brief TLS 1.3 AES 128 CCM 8 SHA256 @xsd hide */
/** @} */

/**
    @name TLS_NamedCurveType
    @{
    @brief TLS named curves for common secret generation

    @trace #BRCM_SWREQ_TLS
*/
typedef uint16_t TLS_NamedCurveType;            /**< @brief typedef for named curves */
#define  TLS_NAMED_CURVE_INVALID    (0x0000U)   /**< @brief Invalid */
#define  TLS_NAMED_CURVE_SECP256R1  (0x0017U)   /**< @brief ECDHE secp256r1 */
#define  TLS_NAMED_CURVE_SECP384R1  (0x0018U)   /**< @brief ECDHE secp384r1 */
#define  TLS_NAMED_CURVE_SECP521R1  (0x0019U)   /**< @brief ECDHE secp512r1 @xsd hide */
#define  TLS_NAMED_CURVE_X25519     (0x001DU)   /**< @brief ECDHE x25519 @xsd hide */
#define  TLS_NAMED_CURVE_X448       (0x001EU)   /**< @brief ECDHE x448 @xsd hide */
#define  TLS_NAMED_CURVE_FFDHE2048  (0x0100U)   /**< @brief FFDHE 2048 @xsd hide */
#define  TLS_NAMED_CURVE_FFDHE3072  (0x0101U)   /**< @brief FFDHE 3072 @xsd hide */
#define  TLS_NAMED_CURVE_FFDHE4096  (0x0102U)   /**< @brief FFDHE 4096 @xsd hide */
#define  TLS_NAMED_CURVE_FFDHE6144  (0x0103U)   /**< @brief FFDHE 6144 @xsd hide */
#define  TLS_NAMED_CURVE_FFDHE8192  (0x0104U)   /**< @brief FFDHE 8192 @xsd hide */
/** @} */

/**
    @name TLS_SignAlgoType
    @{
    @brief TLS signature algorithms

    @trace #BRCM_SWREQ_TLS
*/
typedef uint16_t TLS_SignAlgoType;                       /**< @brief typedef for signature algorithm */
#define TLS_SIGN_ALGO_INVALID                (0x0000U)   /**< @brief Invalid */
#define TLS_SIGN_ALGO_RSA_PKCS1_SHA256       (0x0401U)   /**< @brief RSA PKCS1 SHA256       */
#define TLS_SIGN_ALGO_RSA_PKCS1_SHA384       (0x0501U)   /**< @brief RSA PKCS1 SHA384       */
#define TLS_SIGN_ALGO_RSA_PKCS1_SHA512       (0x0601U)   /**< @brief RSA PKCS1 SHA512 @xsd hide */
#define TLS_SIGN_ALGO_ECDSA_SECP256R1_SHA256 (0x0403U)   /**< @brief ECDSA SECP256R1 SHA256 */
#define TLS_SIGN_ALGO_ECDSA_SECP384R1_SHA384 (0x0503U)   /**< @brief ECDSA SECP384R1 SHA384 */
#define TLS_SIGN_ALGO_ECDSA_SECP521R1_SHA512 (0x0603U)   /**< @brief ECDSA SECP521R1 SHA512 @xsd hide */
#define TLS_SIGN_ALGO_RSA_PSS_RSAE_SHA256    (0x0804U)   /**< @brief RSA PSS RSAE SHA256    */
#define TLS_SIGN_ALGO_RSA_PSS_RSAE_SHA384    (0x0805U)   /**< @brief RSA PSS RSAE SHA384    */
#define TLS_SIGN_ALGO_RSA_PSS_RSAE_SHA512    (0x0806U)   /**< @brief RSA PSS RSAE SHA512 @xsd hide */
#define TLS_SIGN_ALGO_ED25519                (0x0807U)   /**< @brief ED25519 @xsd hide */
#define TLS_SIGN_ALGO_ED448                  (0x0808U)   /**< @brief ED448 @xsd hide */
#define TLS_SIGN_ALGO_RSA_PSS_PSS_SHA256     (0x0809U)   /**< @brief RSA PSS PSS SHA256     */
#define TLS_SIGN_ALGO_RSA_PSS_PSS_SHA384     (0x080aU)   /**< @brief RSA PSS PSS SHA384     */
#define TLS_SIGN_ALGO_RSA_PSS_PSS_SHA512     (0x080bU)   /**< @brief RSA PSS PSS SHA512 @xsd hide */
#define TLS_SIGN_ALGO_RSA_PKCS1_SHA1         (0x0201U)   /**< @brief RSA PKCS1 SHA1 @xsd hide */
#define TLS_SIGN_ALGO_ECDSA_SHA1             (0x0203U)   /**< @brief ECDSA SHA1 @xsd hide */
/** @} */

/**
    @name TLS_ConnectionType
    @{
    @brief TLS connection type

    @trace #BRCM_SWREQ_TLS
*/
typedef uint16_t TLS_ConnectionType;  /**< @brief typedef for connection type */
#define TLS_CONN_SERVER               (0x0000U)   /**< @brief Server */
#define TLS_CONN_CLIENT               (0x0001U)   /**< @brief Client */
/** @} */

#endif /* ETHERNET_TLS_STD_H */
/** @} */
