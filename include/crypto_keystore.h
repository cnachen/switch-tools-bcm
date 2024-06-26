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
    @defgroup grp_crypto_key_store_ifc Crypto key store Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_key_store_ifc
    @{

    @limitations None

    @file crypto_keystore.h
    @brief Crypto key store Interface
    This header file contains the interface functions to manage Crypto keys
    @version 0.1 Initial Version
*/

#ifndef CRYPTO_KEY_STORE_H
#define CRYPTO_KEY_STORE_H

#include <crypto_common.h>
#include <msg_queue.h>
#include <crypto_memory.h>
/**
    @name Crypto key management Architecture IDs
    @{
    @brief Architecture IDs for Crypto key management
*/
#define BRCM_SWARCH_KST_MAX_PAYLOAD_SIZE_MACRO              (0x8800U) /**< @brief #KST_MAX_PAYLOAD_SIZE             */
#define BRCM_SWARCH_KST_MAX_BLOB_SIZE_BYTES_MACRO           (0x8801U) /**< @brief #KST_MAX_BLOB_SIZE_BYTES          */
#define BRCM_SWARCH_KST_ID_OF_MACRO                         (0x8802U) /**< @brief #KST_ID_OF                        */
#define BRCM_SWARCH_KST_ID_TYPE                             (0x8803U) /**< @brief #KST_IDType                       */
#define BRCM_SWARCH_KST_CREATE_ZERO_KEY_TYPE                (0x8804U) /**< @brief #KST_CreateZeroKeyType            */
#define BRCM_SWARCH_KST_CREATE_RAND_KEY_TYPE                (0x8805U) /**< @brief #KST_CreateRandKeyType            */
#define BRCM_SWARCH_KST_CREATE_DH_TYPE                      (0x8806U) /**< @brief #KST_CreateDHKeyType              */
#define BRCM_SWARCH_KST_CREATE_KDF_TYPE                     (0x8807U) /**< @brief #KST_CreateKDFKeyType             */
#define BRCM_SWARCH_KST_TXRX_FLASH_KEY_BLOB_HDR_TYPE        (0x8808U) /**< @brief #KST_TxRxFlashKeyBlobHdrType      */
#define BRCM_SWARCH_KST_IMPORT_TYPE                         (0x8809U) /**< @brief #KST_ImportKeyType                */
#define BRCM_SWARCH_KST_EXPORT_TYPE                         (0x880AU) /**< @brief #KST_ExportKeyType                */
#define BRCM_SWARCH_KST_GET_KEYHDLS_TYPE                    (0x880BU) /**< @brief #KST_GetKeyHdlsType               */
#define BRCM_SWARCH_KST_GET_KEY_USER_INFO_TYPE              (0x880CU) /**< @brief #KST_GetUserInfoType              */
#define BRCM_SWARCH_KST_GET_EXP_HDLS_MSG_TYPE               (0x880DU) /**< @brief #KST_GetExpKeyHdlsType            */
#define BRCM_SWARCH_KST_RESPONSE_TYPE                       (0x880EU) /**< @brief #KST_ResponseType                 */
#define BRCM_SWARCH_KST_CREATE_ZERO_PROC                    (0x880FU) /**< @brief #KST_CreateZeroKey                */
#define BRCM_SWARCH_KST_CREATE_RAND_PROC                    (0x8810U) /**< @brief #KST_CreateRandKey                */
#define BRCM_SWARCH_KST_CREATE_DH_PROC                      (0x8811U) /**< @brief #KST_CreateDHKey                  */
#define BRCM_SWARCH_KST_CREATE_KDF_PROC                     (0x8812U) /**< @brief #KST_CreateKDFKey                 */
#define BRCM_SWARCH_KST_GENERATE_AND_SETUP_DUK_PROC         (0x8813U) /**< @brief #KST_GenerateAndSetupDuk          */
#define BRCM_SWARCH_KST_REMOVE_PROC                         (0x8814U) /**< @brief #KST_RemoveKey                    */
#define BRCM_SWARCH_KST_IMPORT_PROC                         (0x8815U) /**< @brief #KST_ImportKey                    */
#define BRCM_SWARCH_KST_EXPORT_PROC                         (0x8816U) /**< @brief #KST_ExportKey                    */
#define BRCM_SWARCH_KST_GET_KEY_USER_INFO_PROC              (0x8817U) /**< @brief #KST_GetKeyUserInfo               */
#define BRCM_SWARCH_KST_GET_KEY_HDLS_PROC                   (0x8818U) /**< @brief #KST_GetKeyHdls                   */
#define BRCM_SWARCH_KST_GET_EXP_KEY_HDLS_PROC               (0x8819U) /**< @brief #KST_GetExpKeyHdls                */
#define BRCM_SWARCH_KST_GET_STATUS_PROC                     (0x881AU) /**< @brief #KST_GetJobStatus                 */
#define BRCM_SWARCH_KST_EXPORT_RAW_TYPE                     (0x881BU) /**< @brief #KST_ExportRawKeyType             */
#define BRCM_SWARCH_KST_EXPORT_RAW_PROC                     (0x881CU) /**< @brief #KST_ExportRawKey                 */
/** @} */

/**
    @brief Maximum size of CRYPTO Key store payload in bytes

    @trace #BRCM_SWREQ_KST
*/
#define KST_MAX_PAYLOAD_SIZE (80UL)

/**
    @brief Maximum size of the blob that the crypto subsystem is able to work with

    @trace #BRCM_SWREQ_KST
*/
#define KST_MAX_BLOB_SIZE_BYTES (2048UL)

/**
    @brief Macro to Construct CmdID

    @trace #BRCM_SWREQ_KST
*/
#define KST_ID_OF(aId) BCM_MSG(BCM_GROUPID_CRYPTO, BCM_KSTMOD_ID, aId)

/**
    @name Key store Message IDs
    @{
    @brief Message IDs for exchange on message queues and Host

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_KST
*/
typedef BCM_MsgType KST_IDType;                        /**< @brief Key store message ID Type                */
#define KST_ID_CREATE_ZERO_KEY       KST_ID_OF(0x01UL) /**< @brief Create a zero key                        */
#define KST_ID_CREATE_RAND_KEY       KST_ID_OF(0x02UL) /**< @brief Create a random key                      */
#define KST_ID_CREATE_DH_KEY         KST_ID_OF(0x03UL) /**< @brief Create a key via Diffie-Hellman exchange */
#define KST_ID_CREATE_KDF_KEY        KST_ID_OF(0x04UL) /**< @brief Create a key via a KDF                   */
#define KST_ID_GEN_AND_SETUP_DUK     KST_ID_OF(0x05UL) /**< @brief Generate a DUK and write it to the OTP   */
#define KST_ID_REMOVE_KEY            KST_ID_OF(0x06UL) /**< @brief Delete a key                             */
#define KST_ID_IMPORT_KEY            KST_ID_OF(0x07UL) /**< @brief Import an encrypted key                  */
#define KST_ID_EXPORT_KEY            KST_ID_OF(0x08UL) /**< @brief Export a key in with encrypted           */
#define KST_ID_GET_USER_INFO         KST_ID_OF(0x09UL) /**< @brief Get the user info against a given key    */
#define KST_ID_GET_KEYHDLS           KST_ID_OF(0x0AUL) /**< @brief Get the key handles                      */
#define KST_ID_GET_EXP_KEYHDLS       KST_ID_OF(0x0BUL) /**< @brief Get exportable key handles               */
#define KST_ID_GET_STATUS            KST_ID_OF(0x0CUL) /**< @brief Get status command                       */
#define KST_ID_EXPORT_KEY_RAW        KST_ID_OF(0x0DUL) /**< @brief Export a key in with encrypted           */
/** @} */

/**
    @brief Args to the #KST_CreateZeroKey API

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_CreateZeroKeyType {
    BCM_CompIDType      compId;     /**< @brief Requester component ID                  */
    CMEM_KeyClassIdType keyClassId; /**< @brief Key class ID                            */
    CRYPTO_KeyType      outKeyType; /**< @brief Output keytype                          */
    CMEM_HdlType        *outKeyHdl; /**< @brief Pointer to the buffer where the
                                                key handle to the allocated key is to be
                                                written to                              */
    uint32_t            rsvd;       /**< @brief Reserved                                */
} KST_CreateZeroKeyType;
BCM_STATIC_SIZE_ASSERT(KST_CreateZeroKeyType, 16UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the #KST_CreateRandKey API

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_CreateRandKeyType {
    BCM_CompIDType      compId;         /**< @brief Requester component ID              */
    CMEM_KeyClassIdType keyClassId;     /**< @brief Key class ID                        */
    CRYPTO_KeyType      outKeyType;     /**< @brief Output keytype                      */
    CMEM_UsageType      outKeyUsage;    /**< @brief Output key usage                    */
    CMEM_HdlType        *outKeyHdl;     /**< @brief Pointer to the buffer where the
                                                        key handle to the allocated key
                                                        is to be written to             */
} KST_CreateRandKeyType;
BCM_STATIC_SIZE_ASSERT(KST_CreateRandKeyType, 16UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the @ref KST_CreateDHKey API

    The key types of the localKeyHdl and the remoteKeyHdl specify the DH algorithm
    to execute to generate the shared secret. Only the following combinations are valid
    (but not necessarily supported on a given platform):

    |                               |                               |                                   |
    | KeyType of the localKeyHdl    | KeyType of the remoteKeyHdl   | DH Algorithm                      |
    |:-----------------------------:|:-----------------------------:|:---------------------------------:|
    | CRYPTO_KEY_ECC_SECP256R1      | CRYPTO_KEY_ECC_SECP256R1      | NIST 800-56A, ECDH on NIST 256R1  |
    |---------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_ECC_SECP384R1      | CRYPTO_KEY_ECC_SECP384R1      | NIST 800-56A, ECDH on NIST 384R1  |
    |---------------------------------------------------------------------------------------------------|

    And the keyHdl's being supplied here must have been created with a #CMEM_USAGE_DERIV usage flag

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_CreateDHKeyType {
    CMEM_HdlType        localKeyHdl;        /**< @brief Local key Handle                    */
    CMEM_HdlType        remoteKeyHdl;       /**< @brief Local key Handle                    */
    BCM_CompIDType      compId;             /**< @brief Requester component ID              */
    CMEM_KeyClassIdType keyClassId;         /**< @brief Key class ID                        */
    CRYPTO_KeyType      outKeyType;         /**< @brief Output key type                     */
    CMEM_UsageType      outKeyUsage;        /**< @brief Output key usage                    */
    uint32_t            localKeyAuthLen;    /**< @brief Local Key Authorization
                                                string length. Can be zero                  */
    uint8_t             *localKeyAuth;      /**< @brief Local Key Authorization value       */
    uint32_t            remoteKeyAuthLen;   /**< @brief Local Key Authorization
                                                string length. Can be zero                  */
    uint8_t             *remoteKeyAuth;     /**< @brief Local Key Authorization value       */
    CMEM_HdlType        *outKeyHdl;         /**< @brief Pointer to the buffer where the
                                                        key handle to the allocated key
                                                        is to be written to                 */
} KST_CreateDHKeyType;
BCM_STATIC_SIZE_ASSERT(KST_CreateDHKeyType, 48UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the @ref KST_CreateKDFKey API

    The key type of the ikm along with the algMode specify the KDF algorithm to execute.
    Only the following combinations are valid (but not necessarily supported on a given platform):

    |                                   |                               |                                       |
    | KeyType of the KeyHDL             | AlgMode                       | Algorithm that is setup               |
    |:---------------------------------:|:-----------------------------:|:-------------------------------------:|
    | CRYPTO_KEY_AES128                 | CRYPTO_ALGMODE_CMAC_KDF_CTR   | NIST 800-108, CTR mode KDF with       |
    | CRYPTO_KEY_AES192                 |                               | AES-CMAC as the PRF                   |
    | CRYPTO_KEY_AES256                 |                               |                                       |
    |-----------------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_HMAC_SHA256            | CRYPTO_ALGMODE_HKDF_EXTRACT   | RFC 5869, HKDF extract algorithm      |
    | CRYPTO_KEY_HMAC_SHA384            |                               |                                       |
    | CRYPTO_KEY_HMAC_SHA512            |                               |                                       |
    |-----------------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_HMAC_SHA256            | CRYPTO_ALGMODE_HKDF_EXPAND    | RFC 5869, HKDF expand algorithm       |
    | CRYPTO_KEY_HMAC_SHA384            |                               |                                       |
    | CRYPTO_KEY_HMAC_SHA512            |                               |                                       |
    |-----------------------------------------------------------------------------------------------------------|

    And the ikm being supplied here must have been created with a #CMEM_USAGE_DERIV usage flag

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_CreateKDFKeyType {
    CMEM_HdlType        ikm;                /**< @brief Key handle to the parent key    */
    CRYPTO_AlgModeType  algMode;            /**< @brief KDF algorithm mode to use       */
    BCM_CompIDType      compId;             /**< @brief Requester component ID          */
    CMEM_KeyClassIdType keyClassId;         /**< @brief Key class ID                    */
    CRYPTO_KeyType      outKeyType;         /**< @brief Output key type                 */
    CMEM_UsageType      outkeyUsage;        /**< @brief Output key usage                */
    uint32_t            ikmAuthLen;         /**< @brief Key Authorization
                                                    string length. Can be zero          */
    uint8_t             *ikmAuth;           /**< @brief Key Authorization value         */
    uint32_t            saltLen;            /**< @brief Salt/info/label length          */
    const uint8_t       *salt;              /**< @brief Salt/info/label or info bits    */
    uint32_t            ctxLen;             /**< @brief Context length                  */
    const uint8_t       *ctx;               /**< @brief Context bits                    */
    CMEM_HdlType        *outKeyHdl;         /**< @brief Pointer to the buffer where the
                                                        key handle to the allocated key
                                                        is to be written to             */
    uint32_t            rsvd;               /**< @brief Reserved                        */
} KST_CreateKDFKeyType;
BCM_STATIC_SIZE_ASSERT(KST_CreateKDFKeyType, 56UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Header for the key blob used to export keys to and import keys from IMGL

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_TxRxFlashKeyBlobHdrType {
    uint32_t            magic;          /**< @brief Header magic                        */
    CRYPTO_AlgModeType  algMode;        /**< @brief Algmode to be used to import/export */
    uint16_t            ivLen;          /**< @brief IV length                           */
    uint16_t            blobSize;       /**< @brief Total blob size                     */
    uint16_t            cryptOffset;    /**< @brief Crypt offset within the blob        */
    uint16_t            authTagOffset;  /**< @brief Auth offset within the blob         */
    uint8_t             iv[48UL];       /**< @brief IV bits                             */
    BCM_CompIDType      compId;         /**< @brief CompID of this key                  */
    CMEM_KeyClassIdType keyClassId;     /**< @brief Key class ID                        */
    CRYPTO_KeyType      keyType;        /**< @brief Key type                            */
    CMEM_UsageType      keyUsage;       /**< @brief Key usage flags                     */
} KST_TxRxFlashKeyBlobHdrType;
BCM_STATIC_SIZE_ASSERT(KST_TxRxFlashKeyBlobHdrType, 76UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the @ref KST_ImportKey API

    The format of the encrypted blob being imported is interpreted
    based on the keytype of the keyHdl and the algMode being specified below.
    Only the following combinations are valid (but not necessarily
    supported on a given platform):

    |                                   |                                   |                                       |
    | KeyType of the KeyHDL             | AlgMode                           | Algorithm used for key import         |
    |:---------------------------------:|:---------------------------------:|:-------------------------------------:|
    | CRYPTO_KEY_AES128                 | CRYPTO_ALGMODE_TXRX_AES_KEYWRAP   | RFC 3394, AES keywrap algorithm       |
    | CRYPTO_KEY_AES192                 |                                   |                                       |
    | CRYPTO_KEY_AES256                 |                                   |                                       |
    |---------------------------------------------------------------------------------------------------------------|
    | Any                               | CRYPTO_ALGMODE_TXRX_FLASH         | BRCM defined (AES-GCM based, EVITA    |
    |                                   |                                   | inspired) key wrapping algorithm to   |
    |                                   |                                   | import the keys stored in a           |
    |                                   |                                   | non-volatile memory                   |
    |---------------------------------------------------------------------------------------------------------------|
    | Invalid keyHdl                    | CRYPTO_ALGMODE_NONE               | Import a raw instance of              |
    |                                   |                                   | @ref CRYPTO_KeyContainerType          |
    |---------------------------------------------------------------------------------------------------------------|

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_ImportKeyType {
    CMEM_HdlType            kdkHdl;         /**< @brief Transport key to use                */
    CRYPTO_AlgModeType      algMode;        /**< @brief Key Import algorithm mode           */
    BCM_CompIDType          compId;         /**< @brief Requester component ID              */
    CMEM_KeyClassIdType     keyClassId;     /**< @brief Key class ID                        */
    CRYPTO_KeyType          outKeyType;     /**< @brief Output key type                     */
    CMEM_UsageType          outKeyUsage;    /**< @brief Output key usage                    */
    uint32_t                tkeyAuthLen;    /**< @brief Transport Key Authorization
                                                    string length. Can be zero              */
    uint8_t                 *tkeyAuth;      /**< @brief Transport Key Authorization value   */
    uint32_t                keyBlobLen;     /**< @brief Length of the encrypted key blob    */
    const uint8_t           *keyBlob;       /**< @brief Encrypted key blob                  */
    CMEM_HdlType            *outKeyHdl;     /**< @brief Pointer to the buffer where the
                                                        key handle to the allocated key
                                                        is to be written to                 */
    uint32_t                rsvd;           /**< @brief Reserved                            */
} KST_ImportKeyType;
BCM_STATIC_SIZE_ASSERT(KST_ImportKeyType, 48UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the @ref KST_ExportKey API

    The format of the encrypted blob being exported is determined
    based on the keytype of the keyHdl and the algMode being specified below.
    Only the following combinations are valid (but not necessarily
    supported on a given platform):

    |                                   |                                   |                                       |
    | KeyType of the KeyHDL             | AlgMode                           | Algorithm used for key import         |
    |:---------------------------------:|:---------------------------------:|:-------------------------------------:|
    | CRYPTO_KEY_AES128                 | CRYPTO_ALGMODE_TXRX_AES_KEYWRAP   | RFC 3394, AES keywrap algorithm       |
    | CRYPTO_KEY_AES192                 |                                   |                                       |
    | CRYPTO_KEY_AES256                 |                                   |                                       |
    |---------------------------------------------------------------------------------------------------------------|
    | Any                               | CRYPTO_ALGMODE_TXRX_FLASH         | BRCM defined (AES-GCM based, EVITA    |
    |                                   |                                   | inspired) key wrapping algorithm to   |
    |                                   |                                   | store the keys in a non-volatile      |
    |                                   |                                   | memory                                |
    |---------------------------------------------------------------------------------------------------------------|
    | Invalid keyHdl                    | CRYPTO_ALGMODE_NONE               | Export a raw instance of              |
    |                                   |                                   | @ref CRYPTO_KeyContainerType. Only    |
    |                                   |                                   | the non-secret bits shall be made     |
    |                                   |                                   | available via this mechanism.         |
    |---------------------------------------------------------------------------------------------------------------|

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_ExportKeyType {
    CMEM_HdlType            kekHdl;         /**< @brief Handle to the decryption key        */
    CMEM_HdlType            keyHdl;         /**< @brief Handle to the key to be exported    */
    CRYPTO_AlgModeType      algMode;        /**< @brief Key export algorithm mode           */
    uint32_t                tkeyAuthLen;    /**< @brief Transport Key Authorization
                                                    string length. Can be zero              */
    uint8_t                 *tkeyAuth;      /**< @brief Transport Key Authorization value   */
    uint32_t                blobBufLen;     /**< @brief Length of the blob buffer           */
    uint32_t                *blobOutLen;    /**< @brief Pointer to the buffer where the
                                                        output blob length is to be written
                                                        to                                  */
    uint8_t                 *blobBuf;       /**< @brief Pointer to the buffer where the
                                                        output blob is to be written to     */
} KST_ExportKeyType;
BCM_STATIC_SIZE_ASSERT(KST_ExportKeyType, 40UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the #KST_ExportRawKey API

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_ExportRawKeyType {
    CMEM_HdlType            keyHdl;         /**< @brief Input  : Handle to the key to be exported    */
    CMEM_UsageType          outKeyUsage;    /**< @brief Input  : Usage of the Output Key             */
    uint32_t                blobBufLen;     /**< @brief Input  : Length of the blob buffer           */
    uint32_t                *blobOutLen;    /**< @brief Output : Pointer to the buffer where the
                                                                 output blob length is to be written
                                                                 to(not implemented)                 */
    CRYPTO_KeyType          *outKeyType;    /**< @brief Output : key type                            */
    uint8_t                 *blobBuf;       /**< @brief Output : Pointer to the buffer where the
                                                                 output blob of size 32 byte is to be
                                                                 written to                          */
    uint32_t                rsvd;           /**< @brief Reserved                                     */
} KST_ExportRawKeyType;
BCM_STATIC_SIZE_ASSERT(KST_ExportRawKeyType, 32UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the #KST_GetKeyHdls API

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_GetKeyHdlsType {
    CMEM_HdlType            *hdlBuf;    /**< @brief Pointer to the buffer where the
                                                key handles are to be written to            */
    uint32_t                *numHdlsOut; /**< @brief Number of handles written into the
                                                provided buffer                             */
    uint32_t                numHdlsBuf; /**< @brief Number of key handles that the provided
                                                buffer can hold                             */
    BCM_CompIDType          compId;     /**< @brief Component ID                            */
    CMEM_KeyClassIdType     keyClassId; /**< @brief Key class ID                            */
} KST_GetKeyHdlsType;
BCM_STATIC_SIZE_ASSERT(KST_GetKeyHdlsType, 16UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the #KST_GetKeyUserInfo API

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_GetUserInfoType {
    CMEM_HdlType            keyHdl;     /**< @brief Key handle                              */
    uint32_t                blobBufLen; /**< @brief Length of the blob buffer               */
    uint32_t                *blobOutLen; /**< @brief Pointer to the buffer where the
                                                    output blob length is to be written
                                                    to                                      */
    uint8_t                 *blobBuf;   /**< @brief Blob buffer                             */
    uint32_t                rsvd;       /**< @brief Reserved                                */
} KST_GetUserInfoType;
BCM_STATIC_SIZE_ASSERT(KST_GetUserInfoType, 24UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Args to the #KST_GetExpKeyHdls API

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_GetExpKeyHdlsType {
    CMEM_HdlType            *hdlBuf;    /**< @brief Pointer to the buffer where the
                                                key handles are to be written to            */
    uint32_t                *numHdlsOut; /**< @brief Number of handles written into the
                                                provided buffer                             */
    uint32_t                numHdlsBuf; /**< @brief Number of key handles that the provided
                                                buffer can hold                             */
    uint32_t                rsvd;       /**< @brief Reserved field                          */
} KST_GetExpKeyHdlsType;
BCM_STATIC_SIZE_ASSERT(KST_GetExpKeyHdlsType, 16UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Response received from the crypto server on completion of API's defined in this header

    @trace #BRCM_SWREQ_KST
*/
typedef struct sKST_ResponseType {
    int32_t             status;         /**< @brief Command status              */
} KST_ResponseType;
BCM_STATIC_SIZE_ASSERT(KST_ResponseType, 4UL, KST_MAX_PAYLOAD_SIZE)

/**
    @brief Create a zero key of the specified key type

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aKeyCreateZeroKeyInfo   Zero key creation params
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aKeyCreateZeroKeyInfo is NULL) or (aJobHdl is NULL)

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if a key creation completed and the key handle has been
                populated correctly into the client provided buffer
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_INVAL_PARAMS if the contents of aKeyCreateZeroKeyInfo are invalid
                or inconsistent with one another
            -# #BCM_ERR_NOSUPPORT if a zero key cannot be created for the given keytype
            -# #BCM_ERR_NOMEM if the key creation failed due to lack of resources in the system

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_CreateZeroKey(const KST_CreateZeroKeyType *const aKeyCreateZeroKeyInfo, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Create a random key of the specified key type and usage

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aKeyCreateRandKeyInfo   Rand key creatation params
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aKeyCreateRandKeyInfo is NULL) or (aJobHdl is NULL)

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if a key creation completed and the key handle has been
                populated correctly into the client provided buffer
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_INVAL_PARAMS if the contents of aKeyCreateRandKeyInfo are invalid or
                inconsistent with one another
            -# #BCM_ERR_NOMEM if the key creation failed due to lack of resources in the system

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_CreateRandKey(const KST_CreateRandKeyType *const aKeyCreateRandKeyInfo, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Create a new key by executing a DH key exchange algorithm

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aKeyCreateDHInfo        Random key creation args
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aKeyCreateDHInfo is NULL)

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if a key creation completed and the key handle has been
                populated correctly into the client provided buffer
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_INVAL_PARAMS if the contents of aKeyCreateDHInfo are invalid or inconsistent
                with one another
            -# #BCM_ERR_NOSUPPORT if the requested DH algorithm is not supported on the execution platform
            -# #BCM_ERR_NOMEM if the key creation failed due to lack of resources in the system
            -# #BCM_ERR_NOPERM if the caller is not allowed to access the specified local or the remote
                key

    @note The @ref CRYPTO_KeyType of the created key will always be of type CRYPTO_KEY_SECRET_XXX,
        where XXX is determined by the DH algorithm executed

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_CreateDHKey(const KST_CreateDHKeyType *const aKeyCreateDHInfo, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Derive a new key from an existing key by executing a KDF function

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aKeyCreateKDFInfo       Random key creation args
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aKeyCreateKDFInfo is NULL)

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if a key creation completed and the key handle has been
                populated correctly into the client provided buffer
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_INVAL_PARAMS if the contents of aKeyCreateDHInfo are invalid or inconsistent
                with one another
            -# #BCM_ERR_NOSUPPORT if the requested DH algorithm is not supported on the execution platform
            -# #BCM_ERR_NOMEM if the key creation failed due to lack of resources in the system
            -# #BCM_ERR_NOPERM if the caller is not allowed to access the specified IKM key

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_CreateKDFKey(const KST_CreateKDFKeyType *const aKeyCreateKDFInfo, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Generate and setup a device uniqie key

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied

    @post On successful submission of a key delete request, #KST_GetJobStatus may be
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if the key was successfully deleted
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_NOSUPPORT if the DUK programming is not supported
            -# #BCM_ERR_NOMEM if the DUK could not be setup on the OTP
            -# #BCM_ERR_UNKNOWN for an unknown error

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
 */
int32_t KST_GenerateAndSetupDuk(uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Delete a Crypto key

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aKeyHdl                Key handle to remove
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aKeyRemoveInfo is NULL)

    @post On successful submission of a key delete request, #KST_GetJobStatus may be
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if the key was successfully deleted
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_NOPERM if the caller is not allowed to delete this key
            -# #BCM_ERR_INVAL_PARAMS if the key handle submitted was invalid

    @limitations Only the keys created during the system runtime (post system initialization)
        shall be allowed to be deleted.

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_RemoveKey(CMEM_HdlType aKeyHdl, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Import an encrypted key

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aKeyImportInfo          Key import args
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aKeyImportInfo is NULL)

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if a key import completed and the key handle has been
                populated correctly into the client provided buffer
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_INVAL_PARAMS if the contents of aKeyImportInfo are invalid or inconsistent
                with one another
            -# #BCM_ERR_NOSUPPORT if the requested operation is not supported
            -# #BCM_ERR_NOMEM if the key creation failed due to lack of resources in the system
            -# #BCM_ERR_AUTH_FAILED if the authenticity of the key being imported could not be
                established

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_ImportKey(const KST_ImportKeyType *const aKeyImportInfo, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Export an encrypted key

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aKeyExportInfo          Key export args
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aKeyExportInfo is NULL)

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if a key export operation completed successfully
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_INVAL_PARAMS if the contents of aKeyExportInfo are invalid or inconsistent
                with one another
            -# #BCM_ERR_NOSUPPORT if the requested operation is not supported
            -# #BCM_ERR_NOMEM if the client provided buffer is not large enough.
                aKeyExportInfo->blobOutLen is still populated to contain the correct value.
                Always set if aKeyExportInfo->blobOutLen is set to anything greater than
                #KST_MAX_BLOB_SIZE_BYTES (irrespective of what aKeyExportInfo->blobBufLen is set to)

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_ExportKey(const KST_ExportKeyType *const aKeyExportInfo, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Export an Raw key

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aRawKeyExportInfo       Key export args
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   (aRawKeyExportInfo is NULL)

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if a key export operation completed successfully
            -# #BCM_ERR_BUSY if the request is still being processed
            -# #BCM_ERR_INVAL_PARAMS if the contents of aKeyExportInfo are invalid or inconsistent
                with one another
            -# #BCM_ERR_NOSUPPORT if the requested operation is not supported
            -# #BCM_ERR_NOMEM if the client provided buffer is not large enough.

    @trace #BRCM_SWREQ_KST

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t KST_ExportRawKey(const KST_ExportRawKeyType *const aRawKeyExportInfo, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Retrieve the user info blob corresponding to a given key handle

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aGetUserInfoMsg         Get user info args
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)


    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if the key handles have been populated into the caller provided
                buffer
            -# #BCM_ERR_NOMEM if the client provided buffer is not large enough.
                aGetUserInfoMsg->blobOutLen is still populated to contain the correct value.
                Always set if aGetUserInfoMsg->blobOutLen is set to anything greater than
                #KST_MAX_BLOB_SIZE_BYTES (irrespective of what aGetUserInfoMsg->blobBufLen is set to)
            -# #BCM_ERR_INVAL_PARAMS if the contents of aGetKeyHdlsInfo are invalid or inconsistent
                with one another

    @trace #BRCM_SWREQ_KST

    @limitations None
*/
int32_t KST_GetKeyUserInfo(const KST_GetUserInfoType *const aGetUserInfoMsg, uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/**
    @brief Retrieve a key handle corresponding to a given component and the component unique ID

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aGetKeyHdlInfo          Info to retrieve the key handle
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)


    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied
    @retval         #BCM_ERR_INVAL_PARAMS   aGetKeyHdlInfo is NULL

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if the key handles have been populated into the caller provided
                buffer
            -# #BCM_ERR_NOMEM if the client provided buffer is not large enough.
                aGetKeyHdlsMsg->numHdlsOut is still populated to the correct value.
                Always set if aGetKeyHdlsMsg->numHdlsOut is set to anything greater than
                #KST_MAX_BLOB_SIZE_BYTES / sizeof(CMEM_HdlType). (irrespective of what
                aGetKeyHdlsInfo->numHdlsBuf is set to)
            -# #BCM_ERR_INVAL_PARAMS if the contents of aGetKeyHdlsInfo are invalid or inconsistent
                with one another

    @trace #BRCM_SWREQ_KST

    @limitations None
*/
int32_t KST_GetKeyHdls(const KST_GetKeyHdlsType *const aGetKeyHdlsInfo, uint32_t aClientMask,
                       MSGQ_HdlType *const aJobHdl);

/**
    @brief Acquire a list of all exportable key handles in the system

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aGetExpKeyHdlsMsg       Get exportable key handles message
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job Handle (may be NULL)


    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Submission failed some of the system resources
                                            needed for submission are occupied

    @post After successful submission of this request, #KST_GetJobStatus may be called
        to get the status of the submission (with the job handle returned by this API).
        The aStatus out param of that API is set to:
            -# #BCM_ERR_OK if the key handles have been populated into the caller provided
                buffer
            -# #BCM_ERR_NOMEM if the client provided buffer is not large enough.
                aGetExpKeyHdlsMsg->numHdlsOut is still populated to the correct value.
                Always set if aGetExpKeyHdlsMsg->numHdlsOut is set to anything greater than
                #KST_MAX_BLOB_SIZE_BYTES / sizeof(CMEM_HdlType). (irrespective of what
                aGetExpKeyHdlsMsg->numHdlsBuf is set to)
            -# #BCM_ERR_INVAL_PARAMS if the contents of aGetExpKeyHdlsMsg are invalid or inconsistent
                with one another

    @trace #BRCM_SWREQ_KST

    @limitations None
*/
int32_t KST_GetExpKeyHdls(const KST_GetExpKeyHdlsType *const aGetExpKeyHdlsMsg,
                          uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/** @brief Get the status of a previously submitted key management job

    @pre None

    @param[in]      aJobHdl                 Job handle
    @param[out]     aStatus                 Job status

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Request processing complete.
                                            Status param populated
    @retval         #BCM_ERR_BUSY           Request is being processed
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_INVAL_PARAMS   aStatus is NULL

    @post On successful return, The returned status value is to be interpreted as
        described in the documentation of the API that submitted the job

    @trace #BRCM_SWREQ_KST

    @limitations None
*/
int32_t KST_GetJobStatus(const MSGQ_HdlType aJobHdl, int32_t *const aStatus);

#endif /* CRYPTO_KEY_STORE_H */
/** @} */
