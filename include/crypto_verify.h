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
    @defgroup grp_crypto_verify_ifc Verify Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_verify_ifc
    @{

    @section sec_crypto_verify_seq Sequence Diagrams
    @tagseq crypto_verify_direct_client.svg "Direct Client"
    @startseq
    group {label = "CLIENT"; color = "#EFFFFF";  Client;};
    group {label = "CRYPTO API"; color = "#FFEFFF";  VERIFY_API; };
    group {label = "CRYPTO"; color = "#FFFFEF"; MSGQ; VERIFY_Module;};
    Client => VERIFY_API [label = "CRYPTO_VerifyInit", return = "seesionHdl"] {
        VERIFY_API => MSGQ [label = "MSGQ_CtxCreate", return = "seesionHdl"];
        VERIFY_API -> MSGQ [label = "MSGQ_CtxSendMsg", note="Init"] {
            MSGQ  --> VERIFY_Module [label = "signal"] {
                VERIFY_API <--  MSGQ;
            };
        };
    };
    VERIFY_Module => MSGQ [label = "MSGQ_CtxGetMsgIdx", note="Initialize Context"];
    VERIFY_Module => MSGQ [label = "MSGQ_CtxCompleteMsgIdx"];
    Client <-- VERIFY_Module;
    loop {
        Client => VERIFY_API [label = "CRYPTO_VerifyUpdate", return = "jobHdl"] {
            VERIFY_API -> MSGQ [label = "MSGQ_CtxSendMsg", note="non-zero buffer"] {
                MSGQ  --> VERIFY_Module [label = "signal"] {
                    VERIFY_API <--  MSGQ;
                };
            };
        };
        VERIFY_Module => MSGQ [label = "MSGQ_CtxGetMsgIdx", note="Update Context"];
        VERIFY_Module => MSGQ [label = "MSGQ_CtxCompleteMsgIdx"];
        Client <-- VERIFY_Module;
        Client => VERIFY_API [label = "CRYPTO_VerifyStatus", note="for jobHdl"] {
            VERIFY_API => MSGQ [label = "MSGQ_CtxRecvMsg"];
        };
    };
    Client => VERIFY_API [label = "CRYPTO_VerifyFinish"] {
        VERIFY_API -> MSGQ [label = "MSGQ_CtxSendMsg", note="status query"] {
            MSGQ  --> VERIFY_Module [label = "signal"] {
                VERIFY_API <--  MSGQ;
            };
        };
        VERIFY_Module => MSGQ [label = "MSGQ_CtxGetMsgIdx", note="Finalize Context"];
        VERIFY_Module => MSGQ [label = "MSGQ_CtxCompleteMsgIdx"];
        Client <-- VERIFY_Module;
        VERIFY_API => MSGQ [label="MSGQ_GetNextMsgHdl", return="jobHdl"];
        VERIFY_API => MSGQ [label="MSGQ_CtxRecvMsg"];
        VERIFY_API => MSGQ [label="MSGQ_CtxDestroy"];
    };
    @endseq

    @limitations None

    @file crypto_verify.h
    @brief Crypto Verify Interface
    This header file contains the interface functions for crypto based verification
    @version 0.1 Initial Version
*/

#ifndef CRYPTO_VERIRY_H
#define CRYPTO_VERIRY_H

#include <crypto_common.h>
#include <msg_queue.h>
#include <crypto_memory.h>

/**
    @name Crypto Verify Architecture IDs
    @{
    @brief Architecture IDs for Crypto Verify
*/
#define BRCM_SWARCH_CRYPTO_VERIFY_MAX_PAYLOAD_SIZE_MACRO (0x8201U) /**< @brief #CRYPTO_VERIFY_MAX_PAYLOAD_SIZE */
#define BRCM_SWARCH_CRYPTO_VERIFY_MACRO                  (0x8202U) /**< @brief #CRYPTO_VERIFY_MSG_SIZE         */
#define BRCM_SWARCH_CRYPTO_VERIFY_TYPE                   (0x8203U) /**< @brief #CRYPTO_VerifyType              */
#define BRCM_SWARCH_CRYPTO_VERIFY_RAW_INIT_TYPE          (0x8204U) /**< @brief #CRYPTO_VerifyRawInitType       */
#define BRCM_SWARCH_CRYPTO_VERIFY_RAW_UPDATE_TYPE        (0x8205U) /**< @brief #CRYPTO_VerifyRawUpdateType     */
#define BRCM_SWARCH_CRYPTO_VERIFY_INIT_TYPE              (0x8206U) /**< @brief #CRYPTO_VerifyInitType          */
#define BRCM_SWARCH_CRYPTO_VERIFY_UPDATE_TYPE            (0x8207U) /**< @brief #CRYPTO_VerifyUpdateType        */
#define BRCM_SWARCH_CRYPTO_VERIFY_RESPONSE_TYPE          (0x8208U) /**< @brief #CRYPTO_VerifyResponseType      */
#define BRCM_SWARCH_CRYPTO_VERIFY_MSG_UNION_TYPE         (0x8209U) /**< @brief #CRYPTO_VerifyMsgUnionType      */
#define BRCM_SWARCH_CRYPTO_VERIFY_MSG_TYPE               (0x820AU) /**< @brief #CRYPTO_VerifyMsgType           */
#define BRCM_SWARCH_CRYPTO_VERIFY_INIT_PROC              (0x820BU) /**< @brief #CRYPTO_VerifyInit              */
#define BRCM_SWARCH_CRYPTO_VERIFY_UPDATE_PROC            (0x820CU) /**< @brief #CRYPTO_VerifyUpdate            */
#define BRCM_SWARCH_CRYPTO_VERIFY_STATUS_PROC            (0x820DU) /**< @brief #CRYPTO_VerifyStatus            */
#define BRCM_SWARCH_CRYPTO_VERIFY_CANCEL_PROC            (0x820EU) /**< @brief #CRYPTO_VerifyCancel            */
/** @} */

/**
    @brief Maximum size of CRYPTO Verify payload in bytes

    @trace #BRCM_SWREQ_CRYPTO
*/
#define CRYPTO_VERIFY_MAX_PAYLOAD_SIZE        (368UL)

/**
    @name CRYPTO Verify Macros
    @{
    @brief Crypto Verify Macros

    @trace #BRCM_SWREQ_CRYPTO
**/
#define CRYPTO_VERIFY_MSG_SIZE              (368UL) /**< @brief Crypto Verify message Size */
#define CRYPTO_VERIFY_SIGNATURE_MAX_SIZE    (256UL) /**< @brief Crypto Verify Signature max size */
#define CRYPTO_VERIFY_CHUNK_MAX_SIZE        (320UL) /**< @brief Crypto Verify Chunk max size */
/** @} */

/**
    @name CRYPTO Verify Message IDs
    @{
    @brief Message IDs for exchange on message queues

    These are used for interaction over MSGQ interface and RPC commands.
    Hence, this must be within 8-bit space.

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef uint8_t CRYPTO_VerifyType;       /**< @brief Verify message Type */
#define CRYPTO_VERIFY_RAW_INIT     (0U)  /**< @brief Initialize Verify Context   */
#define CRYPTO_VERIFY_RAW_UPDATE   (1U)  /**< @brief Update Verify Context       */
#define CRYPTO_VERIFY_INIT         (8U)  /**< @brief Initialize Verify Context   */
#define CRYPTO_VERIFY_UPDATE       (9U)  /**< @brief Update Verify Context       */
/** @} */

/**
    @brief Verity Raw Init Structure (320 Bytes)

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_VerifyRawInitType {
    CMEM_HdlType        keyHdl;     /**< @brief Key Handle              */
    uint32_t            reserved0;  /**< @brief Reserved                */
    CRYPTO_HashFuncType hashFunc;   /**< @brief Hash Type               */
    CRYPTO_AlgModeType  algMode;    /**< @brief Algorithm mode          */
    uint32_t            msgLength;  /**< @brief Message Length          */
    uint32_t            keyAuthLen; /**< @brief Key Authorization length
                                            must be zero for MVK        */
    BCM_SizeType        sigLen;     /**< @brief Signature Length        */
    uint8_t             keyAuth[CRYPTO_KEY_AUTH_STRING_MAX_SIZE];
                                        /**< @brief Key Authorization value */
    uint8_t             signature[CRYPTO_VERIFY_SIGNATURE_MAX_SIZE];
                                        /**< @brief Signature (input)       */
    uint32_t            reserved[12UL];
} CRYPTO_VerifyRawInitType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_VerifyRawInitType, 368UL, CRYPTO_VERIFY_MAX_PAYLOAD_SIZE);

/**
    @brief Verity Raw Update Structure

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef struct sCRYPTO_VerifyRawUpdateType {
    uint32_t            chunkSize;          /**< @brief Chunk Size          */
    uint8_t             chunkData[CRYPTO_VERIFY_CHUNK_MAX_SIZE];
                                            /**< @brief Chunk data          */
    uint32_t            reserved[11UL];
} CRYPTO_VerifyRawUpdateType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_VerifyRawUpdateType, 368UL, CRYPTO_VERIFY_MAX_PAYLOAD_SIZE);

/**
    @brief Verity Init Structure (320 Bytes)

    The verification algorithm that is setup for execution is determined by the
    combination of the keytype of the keyHdl, hashFunc and algMode specified
    in this init structure. Only the following combinations are valid (but not necessarily
    supported on a given platform):

    |                                   |                           |                               |                                       |
    | KeyType of the KeyHDL             | HashFunc                  | AlgMode                       | Algorithm that is setup               |
    |:---------------------------------:|:-------------------------:|:-----------------------------:|:-------------------------------------:|
    | CRYPTO_KEY_RSA_2K                 | CRYPTO_HASH_FUNC_SHA256   | CRYPTO_ALGMODE_RSA_PKCS1_V15  | RFC 8017, RSASSA-PKCS1-V1_5-VERIFY()  |
    | CRYPTO_KEY_RSA_3K                 |                           |                               | with SHA256 to digest the message.    |
    |                                   |                           |                               | RSA Public exponent is assumed to     |
    |                                   |                           |                               | be 65537.                             |
    |---------------------------------------------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_RSA_2K                 | CRYPTO_HASH_FUNC_SHA256   | CRYPTO_ALGMODE_RSA_PSS        | RFC 8017, RSASSA-PSS-VERIFY()         |
    | CRYPTO_KEY_RSA_3K                 |                           |                               | with SHA256 to digest the message     |
    |                                   |                           |                               | RSA Public exponent is assumed to     |
    |                                   |                           |                               | be 65537.                             |
    |                                   |                           |                               | The hash function used by the NGF1    |
    |                                   |                           |                               | function is SHA256 and the seed       |
    |                                   |                           |                               | length is 32.                         |
    |---------------------------------------------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_ECC_SECP256R1          | CRYPTO_HASH_FUNC_SHA256   | CRYPTO_ALGMODE_NONE           | FIPS 186-4, ECDSA verification on     |
    |                                   |                           |                               | NIST SECP256R1, with SHA256 to digest |
    |                                   |                           |                               | the message                           |
    |---------------------------------------------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_ECC_SECP384R1          | CRYPTO_HASH_FUNC_SHA384   | CRYPTO_ALGMODE_NONE           | FIPS 186-4, ECDSA verification on     |
    |                                   |                           |                               | NIST SECP384R1, with SHA384 to digest |
    |                                   |                           |                               | the message                           |
    |---------------------------------------------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_AES128                 | CRYPTO_HASH_FUNC_NONE     | CRYPTO_ALGMODE_CMAC           | RFC 4493, AES-CMAC tag authentication |
    | CRYPTO_KEY_AES192                 |                           |                               |                                       |
    | CRYPTO_KEY_AES256                 |                           |                               |                                       |
    |---------------------------------------------------------------------------------------------------------------------------------------|
    | CRYPTO_KEY_HMAC_SHA256            | CRYPTO_HASH_FUNC_NONE     | CRYPTO_ALGMODE_NONE           | RFC 2104, HMAC tag authentication     |
    | CRYPTO_KEY_HMAC_SHA384            |                           |                               |                                       |
    | CRYPTO_KEY_HMAC_SHA512            |                           |                               |                                       |
    |---------------------------------------------------------------------------------------------------------------------------------------|

    And the keyHdl being supplied here must have been created with a #CMEM_USAGE_VERIFY usage flag

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_VerifyInitType {
    MSGQ_HdlType        ctxHdl;     /**< @brief Session Handle              */
    CMEM_HdlType        keyHdl;     /**< @brief Key Handle                  */
    uint32_t            keyType;    /**< @brief key type (Legacy field)     */
    CRYPTO_HashFuncType hashFunc;   /**< @brief Hash Type                   */
    CRYPTO_AlgModeType  algMode;    /**< @brief Algorithm mode              */
    uint32_t            msgLength;  /**< @brief Message Length              */
    uint32_t            keyAuthLen; /**< @brief Key Authorization length
                                            must be zero for MVK            */
    BCM_SizeType        sigLen;     /**< @brief Signature Length            */
    uint8_t             *keyAuth;   /**< @brief Key Authorization value     */
    uint8_t             *signature; /**< @brief Signature (input)
                                            Must be an instance of
                                            #CRYPTO_SignatureStorageType    */
    uint32_t            reserved[80UL];
} CRYPTO_VerifyInitType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_VerifyInitType, 368UL, CRYPTO_VERIFY_MAX_PAYLOAD_SIZE);

/**
    @brief Verity Update Structure

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_VerifyUpdateType {
    MSGQ_HdlType        ctxHdl;     /**< @brief Session Handle      */
    uint32_t            chunkSize;  /**< @brief Chunk Size (input)              */
    uint8_t             *chunkData; /**< @brief Chunk data pointer (input)      */
    uint32_t            reserved[88UL];
} CRYPTO_VerifyUpdateType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_VerifyUpdateType, 368UL, CRYPTO_VERIFY_MAX_PAYLOAD_SIZE);

/**
    @brief Response Structure used for VerifyInit & VerifyUpdate

    @trace #BRCM_SWREQ_CRYPTO
 */
typedef struct sCRYPTO_VerifyResponseType {
    MSGQ_HdlType        ctxHdl;     /**< @brief Session Handle      */
    int32_t             status;     /**< @brief Command status      */
    uint32_t            reserved[89UL];
} CRYPTO_VerifyResponseType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_VerifyResponseType, 368UL, CRYPTO_VERIFY_MAX_PAYLOAD_SIZE);

/**
    @brief Verity Union encapsulating all messages

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef union uCRYPTO_VerifyMsgUnionType {
    uint32_t                  data[CRYPTO_VERIFY_MSG_SIZE/4UL];
    CRYPTO_VerifyInitType     init;      /**< @brief Verify Init command data */
    CRYPTO_VerifyUpdateType   update;    /**< @brief Verify Update command data */
    CRYPTO_VerifyResponseType response;  /**< @beief Response data for either commands */
} CRYPTO_VerifyMsgUnionType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_VerifyMsgUnionType, CRYPTO_VERIFY_MAX_PAYLOAD_SIZE, CRYPTO_VERIFY_MAX_PAYLOAD_SIZE);

/**
    @brief Verity Union encapsulating all messages

    @trace #BRCM_SWREQ_CRYPTO
*/
typedef struct sCRYPTO_VerifyMsgType {
    uint32_t                    magic;
    BCM_MsgType                 id;
    int32_t                     status;
    uint32_t                    reserved;
    CRYPTO_VerifyMsgUnionType   u;
} CRYPTO_VerifyMsgType;
BCM_STATIC_SIZE_ASSERT(CRYPTO_VerifyMsgType, 384UL, 384UL);

/** @brief Crypto Verification initialization

    Initializes Crypto Verification Context (symmetric or asymmetric) based on a key,
    message size, and signature

    @behavior Async, Re-entrant

    @pre Crypto Verify module is in initialized state (#CRYPTO_VerifyModule)

    @param[inout]   aInitInfo   Verification Initialization Info
    @param[in]      aClientMask Mask with which the caller need to be signalled
    @param[in/out]  aCtxHdl     Context Handle (If valid use the same)
    @param[out]     aJobHdl     Job Handle (may be NULL)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_NOMEM          All Verify contexts are busy
    @retval     #BCM_ERR_INVAL_PARAMS   (aInitInfo is NULL) or (aCtxHdl is NULL)

    @post None

    @trace #BRCM_SWREQ_CRYPTO

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t CRYPTO_VerifyInit(CRYPTO_VerifyInitType *aInitInfo, uint32_t aClientMask,
                            MSGQ_HdlType *aCtxHdl, MSGQ_HdlType *aJobHdl);

/** @brief Update Verify context

    Update hash with in the verify context based on message provided and
    performs verification when complete msgSize is received

    @behavior Async, Re-entrant

    @pre Verify Context is created and initialized using #CRYPTO_VerifyInit

    @param[in]      aCtxHdl         Context Handle
    @param[in]      aUpdateInfo     Verification update information with message
    @param[out]     aJobHdl         Job Handle (may be NULL)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Update request posted to Verify Module
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_NOMEM          Contexts Queue is full
    @retval     #BCM_ERR_INVAL_PARAMS   aUpdateInfo is NULL

    @post None

    @trace #BRCM_SWREQ_CRYPTO

    @limitations
        -# Unless this API is called to process the last data chunk, it can only process
            chunks whose sizes are the multiples of the underlying bulk data processing algorithm's
            block size. So, for SHA256, chunk size needs to be a multiple of 64 bytes. Multiple of 128 bytes
            for SHA384 and SHA512. Multiples of 16 bytes for AES-CMAC algorithms. The last data chunk to be
            processed can be an arbitrary positive integer (of reasonably large size: the maximum size
            is platform dependent). If these conditions are not satisfied the verification operation
            is failed with #BCM_ERR_AUTH_FAILED status code

    @limitations aClientMask must be MODULE_EVENT
*/
int32_t CRYPTO_VerifyUpdate(MSGQ_HdlType aCtxHdl, const CRYPTO_VerifyUpdateType *aUpdateInfo, MSGQ_HdlType *aJobHdl);

/** @brief Query status of proviously posted job

    @behavior Sync, Re-entrant

    @pre aCtxHdl is created using #CRYPTO_VerifyInit and aJobHdl is created using
        #CRYPTO_VerifyInit or #CRYPTO_VerifyUpdate

    @param[in]      aCtxHdl     Context Handle
    @param[in]      aJobHdl     Job Handle (may be #MSGQ_HDL_INVALID)
    @param[out]     aStatus     Authentication Status

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Request processing complete
    @retval     #BCM_ERR_BUSY           Request is being processed
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_INVAL_PARAMS   aStatus is NULL

    @post When "return value is #BCM_ERR_UNKNOWN" or "return Value is #BCM_ERR_OK and
    aStatus is not BCM_ERR_BUSY", Context is already destroyed


    @note aStatus values are documented in reverse-chronological order
    aStatus is set to #BCM_ERR_OK if authentication success.
    aStatus is set to #BCM_ERR_AUTH_FAILED if authentication failed.
    aStatus is set to #BCM_ERR_NOSUPPORT if authentication mechanism is not supported.
    aStatus is set to #BCM_ERR_NOT_FOUND if Key is not present (returned only if using special key handles).
    aStatus is set to #BCM_ERR_BUSY if authentication is not complete.
    aStatus is set to #BCM_ERR_INVAL_STATE if request is not allowed.

    @trace #BRCM_SWREQ_CRYPTO

    @limitations None
*/
int32_t CRYPTO_VerifyStatus(MSGQ_HdlType aCtxHdl, MSGQ_HdlType aJobHdl, int32_t *aStatus);

/** @brief Cancel the verification

    @behavior Sync, Re-entrant

    @pre aCtxHdl is created using #CRYPTO_VerifyInit

    @param[in]      aCtxHdl     Context Handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully canceled
    @retval     #BCM_ERR_AUTH_FAILED    Task ID of the caller is not matching
                                        with the requestor’s Task ID
    @retval     #BCM_ERR_BUSY           Pending processing on aCtxHdl
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_NOSUPPORT      No support

    @post When "return value is #BCM_ERR_OK" Context is already destroyed

    @trace #BRCM_SWREQ_CRYPTO

    @limitations None
*/
int32_t CRYPTO_VerifyCancel(MSGQ_HdlType aCtxHdl);

#endif /* CRYPTO_VERIRY_H */

/** @} */
