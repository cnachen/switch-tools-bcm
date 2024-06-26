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
    @defgroup grp_crypto_aead_ifc AEAD Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_aead_ifc
    @{

    @limitations None

    @file crypto_aead.h
    @brief Crypto AEAD Interface
    This header file contains the interface functions to invoke AEAD operations
    @version 0.1 Initial Version
*/

#ifndef CRYPTO_AEAD_H
#define CRYPTO_AEAD_H

#include <crypto_common.h>
#include <msg_queue.h>
#include <crypto_memory.h>

/**
    @name Crypto AEAD Architecture IDs
    @{
    @brief Architecture IDs for Crypto AEAD routines
*/
#define BRCM_SWARCH_CRYPTO_AEAD_MAX_PAYLOAD_SIZE_MACRO         (0x8501U) /**< @brief #CRYPTO_AEAD_MAX_PAYLOAD_SIZE         */
#define BRCM_SWARCH_CRYPTO_AEAD_MAX_TAG_LEN_MACRO              (0x8502U) /**< @brief #CRYPTO_AEAD_MAX_TAG_LEN              */
#define BRCM_SWARCH_CRYPTO_AEAD_TYPE                           (0x8503U) /**< @brief #CRYPTO_AeadType                      */
#define BRCM_SWARCH_CRYPTO_AEAD_TAG_DESC_ENCRYPT_AND_TAG_TYPE  (0x8504U) /**< @brief #CRYPTO_AeadTagDescEncryptAndTagType  */
#define BRCM_SWARCH_CRYPTO_AEAD_TAG_DESC_DECRYPT_AND_AUTH_TYPE (0x8505U) /**< @brief #CRYPTO_AeadTagDescDecryptAndAuthType */
#define BRCM_SWARCH_CRYPTO_AEAD_TAG_DESC_UNION_TYPE            (0x8506U) /**< @brief #CRYPTO_AeadTagDescUnionType          */
#define BRCM_SWARCH_CRYPTO_AEAD_INIT_TYPE                      (0x8507U) /**< @brief #CRYPTO_AeadInitType                  */
#define BRCM_SWARCH_CRYPTO_AEAD_UPDATE_TYPE                    (0x8508U) /**< @brief #CRYPTO_AeadUpdateType                */
#define BRCM_SWARCH_CRYPTO_AEAD_RESPONSE_TYPE                  (0x8509U) /**< @brief #CRYPTO_AeadResponseType              */
#define BRCM_SWARCH_CRYPTO_AEAD_MSG_UNION_TYPE                 (0x850AU) /**< @brief #CRYPTO_AeadMsgUnionType              */
#define BRCM_SWARCH_CRYPTO_AEAD_MSG_TYPE                       (0x850BU) /**< @brief #CRYPTO_AeadMsgType                   */
#define BRCM_SWARCH_CRYPTO_AEAD_INIT_PROC                      (0x850CU) /**< @brief #CRYPTO_AeadInit                      */
#define BRCM_SWARCH_CRYPTO_AEAD_UPDATE_PROC                    (0x850DU) /**< @brief #CRYPTO_AeadUpdate                    */
#define BRCM_SWARCH_CRYPTO_AEAD_STATUS_PROC                    (0x850EU) /**< @brief #CRYPTO_AeadStatus                    */
#define BRCM_SWARCH_CRYPTO_AEAD_CANCEL_PROC                    (0x850FU) /**< @brief #CRYPTO_AeadCancel                    */
#define BRCM_SWARCH_CRYPTO_AEAD_HASH_INIT_TYPE                 (0x8510U) /**< @brief #CRYPTO_AeadHashInitType              */
#define BRCM_SWARCH_CRYPTO_AEAD_HASH_UPDATE_TYPE               (0x8511U) /**< @brief #CRYPTO_AeadHashUpdateType            */
/** @} */

/**
    @brief Maximum size of CRYPTO Aead payload in bytes

    @trace #BRCM_SWREQ_CRYPTO
*/
#define CRYPTO_AEAD_MAX_PAYLOAD_SIZE        (128UL)

/**
    @brief Maximum length of the authentication tag supported by this library

    @trace #BRCM_SWREQ_CRYPTO
*/
#define CRYPTO_AEAD_MAX_TAG_LEN             (64UL)

/**
    @name CRYPTO AEAD Message IDs
    @{
    @brief Message IDs for exchange on message queues

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef uint8_t CRYPTO_AeadType;
#define CRYPTO_AEAD_INIT                    (1U)
#define CRYPTO_AEAD_UPDATE                  (2U)
#define CRYPTO_AEAD_HASH_INIT               (3U)
#define CRYPTO_AEAD_HASH_UPDATE             (4U)
#define CRYPTO_AEAD_HASH_FINISH             (5U)
/** @} */

/**
    @brief Tag description for encrypt and tag operation

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef struct sCRYPTO_AeadTagDescEncryptAndTagType {
    uint32_t        tagLen;         /**< @brief Length of the tag to generate               */
    uint8_t         *tag;           /**< @brief Buffer to write the computed authentication
                                            tag into. The Asynchronously updated after the
                                            last #CRYPTO_AeadUpdate is issued               */
} CRYPTO_AeadTagDescEncryptAndTagType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadTagDescEncryptAndTagType, 8UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief Tag description for decrypt and auth operation

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef struct sCRYPTO_AeadTagDescDecryptAndAuthType {
    uint32_t        tagLen;         /**< @brief Authentication tag length                   */
    const uint8_t   *tag;           /**< @brief Pointer to the authentication tag           */
} CRYPTO_AeadTagDescDecryptAndAuthType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadTagDescDecryptAndAuthType, 8UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief Tag description union

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef union uCRYPTO_AeadTagDescUnionType {
    CRYPTO_AeadTagDescEncryptAndTagType     tagDescEncAndTag;   /**< @brief Tag description for encrypt and tag     */
    CRYPTO_AeadTagDescDecryptAndAuthType    tagDescDecAndAuth;  /**< @brief Tag description for decrypt and auth    */
} CRYPTO_AeadTagDescUnionType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadTagDescUnionType, 8UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief AEAD Init Structure

    The AEAD algorithm that is setup for execution is determined by the
    combination of various parameters in this type. To setup an algorithm,
    following combinations should be used. All other combinations (that are
    not listed below) are considered invalid. A valid combination is not necessarily
    supported on a given platform.

    NIST SP800-38D, GCM encrypt and tag with the AES cipher:
        encKeyHdl points to a valid AES key, must be setup with #CMEM_USAGE_SIGN | #CMEM_USAGE_ENCRYPT
        macKeyHdl should be #CMEM_HDL_INVALID
        encAlgMode should be #CRYPTO_ALGMODE_GCM_ENC_AND_TAG
        macAlgMode should be #CRYPTO_ALGMODE_NONE
        (aadLen + cryptLen) > 0
        12 bytes of IV
        12 bytes of IV expected
        tagDesc.tagDescEncAndTag.tagLen should be 16

    NIST SP800-38D, GCM decrypt and authenticate with the AES cipher:
        encKeyHdl points to a valid AES key, must be setup with #CMEM_USAGE_VERIFY | #CMEM_USAGE_DECRYPT
        macKeyHdl should be #CMEM_HDL_INVALID
        encAlgMode should be #CRYPTO_ALGMODE_GCM_DEC_AND_AUTH
        macAlgMode should be #CRYPTO_ALGMODE_NONE
        (aadLen + cryptLen) > 0
        12 bytes of IV expected
        tagDesc.tagDescDecAndAuth.tagLen should be 16

    NIST SP800-38B, AES CMAC tag generation:
        encKeyHdl should be #CMEM_HDL_INVALID
        macKeyHdl points to a valid AES key, must be setup with #CMEM_USAGE_SIGN
        encAlgMode should be #CRYPTO_ALGMODE_NONE
        macAlgMode should be #CRYPTO_ALGMODE_AES_CMAC_TAG
        cryptLen should be zero
        aadLen > 0
        tagDesc.tagDescEncAndTag.tagLen should be in the range (0, 16]

    NIST SP800-38B, AES CMAC tag authentication:
        encKeyHdl should be #CMEM_HDL_INVALID
        macKeyHdl points to a valid AES key, must be setup with #CMEM_USAGE_VERIFY
        encAlgMode should be #CRYPTO_ALGMODE_NONE
        macAlgMode should be #CRYPTO_ALGMODE_AES_CMAC_AUTH
        cryptLen should be zero
        aadLen > 0
        tagDesc.tagDescDecAndAuth.tagLen should in the range (0, 16]

    AES-CTR encryption with HMAC-SHA tag generation (Ordering: Encrypt and then MAC):
        encKeyHdl points to a valid AES key, must be setup with #CMEM_USAGE_ENCRYPT
        encAlgMode should be #CRYPTO_ALGMODE_CTR_ENC
        macKeyHdl points to a valid HMAC key, must be setup with #CMEM_USAGE_SIGN
        macAlgMode should be #CRYPTO_ALGMODE_HMAC_TAG
        (aadLen + cryptLen) > 0
        if cryptLen > 0
            (aadLen % BLOCKSIZE(HASH_ALGORITHM)) should be zero 0
        16 bytes of IV expected
        tagDesc.tagDescEncAndTag.tagLen should be the 32 for HMAC-SHA256 and 48 for HMAC-SHA384

    AES-CTR decryption with HMAC-SHA tag authentication (Ordering: Inverse of Encrypt and then MAC):
        encKeyHdl points to a valid AES key, must be setup with #CMEM_USAGE_DECRYPT
        encAlgMode should be #CRYPTO_ALGMODE_CTR_DEC
        macKeyHdl points to a valid HMAC key, must be setup with #CMEM_USAGE_VERIFY
        macAlgMode should be #CRYPTO_ALGMODE_HMAC_AUTH
        (aadLen + cryptLen) > 0
        if cryptLen > 0
            (aadLen % BLOCKSIZE(HASH_ALGORITHM)) should be zero 0
        16 bytes of IV expected
        tagDesc.tagDescDecAndAuth.tagLen should be the 32 for HMAC-SHA256 and 48 for HMAC-SHA384

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_AeadInitType {
    MSGQ_HdlType                ctxHdl;         /**< @brief Session Handle                              */
    CMEM_HdlType                encKeyHdl;      /**< @brief Encrypt/decrypt key handle                  */
    CMEM_HdlType                macKeyHdl;      /**< @brief MAC key handle                              */
    CRYPTO_AlgModeType          encAlgMode;     /**< @brief Encrypt/decrypt algorithm mode              */
    CRYPTO_AlgModeType          macAlgMode;     /**< @brief MAC algorithm mode                          */
    uint32_t                    ivLen;          /**< @brief Length of the IV                            */
    uint8_t                     iv[16UL];       /**< @brief Pointer to the memory holding the IV to use */
    uint32_t                    aadLen;         /**< @brief AAD length                                  */
    uint32_t                    cryptLen;       /**< @brief Crypt length                                */
    uint32_t                    encKeyAuthLen;  /**< @brief Key Authorization length                    */
    const uint8_t               *encKeyAuth;    /**< @brief Key Authorization value                     */
    uint32_t                    macKeyAuthLen;  /**< @brief Key Authorization length                    */
    const uint8_t               *macKeyAuth;    /**< @brief Key Authorization value                     */
    CRYPTO_AeadTagDescUnionType tagDesc;        /**< @brief Tag description                             */
    uint32_t                    reserved;       /**< @brief Reserved                                    */
} CRYPTO_AeadInitType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadInitType, 88UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief AEAD Update Structure

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_AeadUpdateType {
    MSGQ_HdlType        ctxHdl;                 /**< @brief Session Handle              */
    uint32_t            chunkLen;               /**< @brief Chunk length                */
    const uint8_t       *chunkInputData;        /**< @brief Chunk data pointer (input)  */
    uint8_t             *chunkOutputData;       /**< @brief Chunk data pointer (output) */
    uint32_t            reserved;               /**< @brief Reserved field              */
} CRYPTO_AeadUpdateType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadUpdateType, 24UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief Hash Init Structure

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_AeadHashInitType {
    MSGQ_HdlType        ctxHdl;     /**< @brief Session Handle      */
    CRYPTO_HashFuncType hashFunc;   /**< @brief Hash Type           */
    uint32_t            reserved;   /**< @brief Reserved            */
} CRYPTO_AeadHashInitType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadHashInitType, 16UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief Hash Update Structure

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_AeadHashUpdateType {
    MSGQ_HdlType        ctxHdl;                 /**< @brief Session Handle              */
    uint32_t            chunkLen;               /**< @brief Chunk Size (input)          */
    const uint8_t       *chunkInputData;        /**< @brief Chunk data pointer (input)  */
    uint32_t            reserved;               /**< @brief Reserved field              */
    uint32_t            reserved1;              /**< @brief Reserved field              */
} CRYPTO_AeadHashUpdateType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadHashUpdateType, 24UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief AEAD command response

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_AeadResponseType {
    MSGQ_HdlType                        ctxHdl;              /**< @brief Session Handle                              */
    uint32_t                            status;              /**< @brief Command status                              */
    uint32_t                            reserved;            /**< @brief Reserved                                    */
    CRYPTO_AeadTagDescEncryptAndTagType clientEncAndTagDesc; /**< @brief Client supplied encrypt and tag description */
    uint8_t                             tag[CRYPTO_AEAD_MAX_TAG_LEN];   /**< @brief Generated tag                    */
} CRYPTO_AeadResponseType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadResponseType, 88UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief Union encapsulating all messages

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef union uCRYPTO_AeadMsgUnionType {
    CRYPTO_AeadInitType         init;       /**< @brief Init message                */
    CRYPTO_AeadUpdateType       update;     /**< @brief Update message              */
    CRYPTO_AeadResponseType     response;   /**< @brief Response message            */
    CRYPTO_AeadHashInitType     hashInit;   /**< @brief Hash Init message           */
    CRYPTO_AeadHashUpdateType   hashUpdate; /**< @brief Hash Update message         */
    CRYPTO_AeadHashUpdateType   hashFinish; /**< @brief Hash Finish message         */
} CRYPTO_AeadMsgUnionType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadMsgUnionType, 88UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/**
    @brief AEAD message type

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef struct sCRYPTO_AeadMsgType {
    uint32_t                    magic;      /**< @brief Magic               */
    BCM_CmdType                 id;         /**< @brief Command ID          */
    int32_t                     status;     /**< @brief Status              */
    uint32_t                    reserved;   /**< @brief Reserved            */
    CRYPTO_AeadMsgUnionType     u;          /**< @brief Message union       */
} CRYPTO_AeadMsgType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_AeadMsgType, 104UL, CRYPTO_AEAD_MAX_PAYLOAD_SIZE)

/** @brief Crypto AEAD initialization

    Initializes an AEAD Context based on key, algorithm and message size,

    @behavior Async, Re-entrant

    @pre Crypto AEAD module is in initialized state

    @param[inout]   aInitInfo               AEAD Initialization Info
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aCtxHdl                 Context Handle
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Success
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          All AEAD contexts are busy
    @retval         #BCM_ERR_INVAL_PARAMS   (aInitInfo is NULL) or (aCtxHdl is NULL)

    @post None

    @trace #BRCM_SWREQ_CRYPTO

    @limitations None
*/
int32_t CRYPTO_AeadInit(const CRYPTO_AeadInitType *const aInitInfo, const uint32_t aClientMask, MSGQ_HdlType *const aCtxHdl, MSGQ_HdlType *const aJobHdl);

/** Update the AEAD context

    Update the message digest computation and perform the necessary crypt
    operations

    @behavior Async, Re-entrant

    @pre AEAD Context is created and initialized using #CRYPTO_AeadInit

    @param[in]      aCtxHdl                 Context Handle
    @param[in]      aUpdateInfo             AEAD update information with message
    @param[out]     aJobHdl                 Job Handle (may be NULL)

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Update request posted to AEAD Module
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_NOMEM          Contexts Queue is full
    @retval         #BCM_ERR_INVAL_PARAMS   aUpdateInfo is NULL

    @post None

    @trace #BRCM_SWREQ_CRYPTO

    @limitations
        -# This API cannot process the AAD and CRYPT data simultaneously in one invocation.
            So, AAD needs to be processed first by invoking this API for zero or more times.
            This is to be followed by the invocations to process the CRYPT data.
        -# For AAD processing, except for the case where this API is called to process the last data chunk,
            the chunk sizes this API can process are only the multiples of underlying MAC algorithm's block
            size (16 bytes for GMAC used with GCM).
        -# For CRYPT processing, except for the case where this API is called to process the last data chunk,
            the chunk sizes this API can process are only the multiples of underlying cipher's block size
            (16 bytes for AES-GCM for instance)
*/
int32_t CRYPTO_AeadUpdate(const MSGQ_HdlType aCtxHdl, const CRYPTO_AeadUpdateType *const aUpdateInfo, MSGQ_HdlType *const aJobHdl);

/** @brief Query status of proviously posted AEAD job

    @behavior Sync, Re-entrant

    @pre aCtxHdl is created using #CRYPTO_AeadInit and aJobHdl is created using
        #CRYPTO_AeadInit or #CRYPTO_AeadUpdate

    @param[in]      aCtxHdl                 Context Handle
    @param[in]      aJobHdl                 Job Handle (may be #MSGQ_HDL_INVALID)
    @param[out]     aStatus                 AEAD Status

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Request processing complete
    @retval         #BCM_ERR_BUSY           Request is being processed
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_INVAL_PARAMS   aStatus is NULL

    @post When "return value is #BCM_ERR_UNKNOWN" or "return Value is #BCM_ERR_OK and
        aStatus is not BCM_ERR_BUSY", Context is already destroyed

    @note aStatus values are documented in reverse-chronological order
    aStatus is set to #BCM_ERR_OK if AEAD operation completed sucessfully.
    aStatus is set to #BCM_ERR_AUTH_FAILED if the decryption and auth failed the tag authentication
    aStatus is set to #BCM_ERR_NOSUPPORT if the AEAD mechanism is not supported.
    aStatus is set to #BCM_ERR_NOPERM if the client is not permitted to access the specified AEAD key
    aStatus is set to #BCM_ERR_NOT_FOUND if Key is not present (returned only if using special key handles).
    aStatus is set to #BCM_ERR_BUSY if AEAD operation is not complete.
    aStatus is set to #BCM_ERR_INVAL_PARAMS if AEAD operation args were invalid or inconsistent with one another

    @trace #BRCM_SWREQ_CRYPTO

    @limitations None
*/
int32_t CRYPTO_AeadStatus(const MSGQ_HdlType aCtxHdl, const MSGQ_HdlType aJobHdl, int32_t *const aStatus);

/** @brief Cancel the AEAD operation

    @behavior Sync, Re-entrant

    @pre aCtxHdl is created using #CRYPTO_AeadInit

    @param[in]      aCtxHdl                 Context Handle

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Successfully canceled
    @retval         #BCM_ERR_AUTH_FAILED    Task ID of the caller is not matching
                                            with the requestor’s Task ID
    @retval         #BCM_ERR_BUSY           Pending processing on aCtxHdl
    @retval         #BCM_ERR_UNKNOWN        Integration fault

    @post When return value is #BCM_ERR_OK, Context is already destroyed

    @trace #BRCM_SWREQ_CRYPTO

    @limitations None
*/
int32_t CRYPTO_AeadCancel(const MSGQ_HdlType aCtxHdl);

#endif
/** @} */
