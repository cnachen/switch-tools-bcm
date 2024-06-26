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
    @defgroup grp_skadrv_ifc SKA driver interface for the crypto-service
    @ingroup grp_skadrv

    @addtogroup grp_skadrv_ifc
    @{
    This header declares the entry-points into the SKA library and the associated API
    objects. The following paragraphs give an overview of the API being defined here.

    The cryptographic operations executed by this library are always associated with
    a context object (#SKADRV_CtxType). A context object encapsulates the crypto algorithm
    state and has a life-cycle attached to it. We shall use the following terminology
    in the rest of the documentation:

        -# All bulk-data processed by this library against a given context during its
           life-cycle shall be referred to as a @b packet.
        -# The library allows the client to break a packet down into multiple @b partial @b packets
           and process them individually. Some reasons why the client may choose
           to do this: reduce latencies, save memory, achieve a scatter-gather effect
           etc.

    A context needs to be initialized before it can be used against any crypto operations.
    This initialization kicks off the life-cycle of that context. The #SKADRV_HashCtxInit,
    #SKADRV_AEADLegacyCtxInit and #SKADRV_AEADCtxInit API's initialize the context and setup the
    appropriate initial states.

    Once the context is initialized, multiple partial packets may be processed against it
    by issuing the #SKADRV_HashUpdate, #SKADRV_AEADUpdateAAD, #SKADRV_AEADUpdateAADTail and
    #SKADRV_AEADUpdatePld API's.

    The last partial packets should be processed with the special #SKADRV_HashFinish,
    #SKADRV_AEADUpdateAADTailAndFinish and #SKADRV_AEADUpdatePldAndFinish API's. This
    transitions the context into a @b DONE state. Once this state is reached, library
    will not accept any furthur partial packets against the context in question.

    If the library encounters an unexpected error from the HW while processing any of
    the submitted partial packets, the corresponding context is immediately moved to
    an @b ERROR state. While the context is in this state, no furthur partial packets
    are accepted from the client for processing. The context will be invalidated
    eventually as described next.

    The context is invalidated in the following cases:
        -# By an explicit call to #SKADRV_HashCtxDeinit or ##SKADRV_AEADCtxDeinit.
        -# The context is in a @b DONE state and all the jobs issued against this context
           have been completed successfully.
        -# The context is in an @b ERROR state and the job scheduler has finished processing
           all the subsequent partial packets that were enqueued against this context.

    The context object may be re-used by the library client only after it has been invalidated.

    @file skadrv.h
    @brief Interface File
    @version 0.1 Initial Version
*/

#ifndef SKADRV_H
#define SKADRV_H

#include <crypto_common.h>
#include <stddef.h>

/**
    @name SKA driver Architecture IDs
    @{
    @brief Architecture IDs for the SKA driver
*/
#define BRCM_SWARCH_SKADRV_CONTEXT_SIZE_MACRO                      (0x8101U) /**< @brief #SKADRV_CONTEXT_SIZE                     */
#define BRCM_SWARCH_SKADRV_PACKET_MAX_SIZE_MACRO                   (0x8102U) /**< @brief #SKADRV_PACKET_MAX_SIZE                  */
#define BRCM_SWARCH_SKADRV_PACKET_PARTIAL_MAX_SIZE_MACRO           (0x8103U) /**< @brief #SKADRV_PACKET_PARTIAL_MAX_SIZE          */
#define BRCM_SWARCH_SKADRV_JOB_HDL_TYPE                            (0x8104U) /**< @brief #SKADRV_JobHdlType                       */
#define BRCM_SWARCH_SKADRV_HASH_CTX_STATE_ID_TYPE                  (0x8105U) /**< @brief #SKADRV_HashCtxStateIdType               */
#define BRCM_SWARCH_SKADRV_AEAD_CTX_STATE_ID_TYPE                  (0x8106U) /**< @brief #SKADRV_AEADCtxStateIdType               */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_ORDERING_TYPE               (0x8107U) /**< @brief #SKADRV_AEADLegacyOrderingType           */
#define BRCM_SWARCH_SKADRV_CTX_TYPE                                (0x8108U) /**< @brief #SKADRV_CtxType                          */
#define BRCM_SWARCH_SKADRV_HASH_CTX_CFG_TYPE                       (0x8109U) /**< @brief #SKADRV_HashCtxCfgType                   */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_CRYPT_CTX_CFG_TYPE          (0x810AU) /**< @brief #SKADRV_AEADLegacyCryptCtxCfgType        */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_AUTH_CTX_CFG_TYPE           (0x810BU) /**< @brief #SKADRV_AEADLegacyAuthCtxCfgType         */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_CTX_CFG_TYPE                (0x810CU) /**< @brief #SKADRV_AEADLegacyCtxCfgType             */
#define BRCM_SWARCH_SKADRV_AEAD_CTX_CFG_TYPE                       (0x810DU) /**< @brief #SKADRV_AEADCtxCfgType                   */
#define BRCM_SWARCH_SKADRV_AEAD_ICV_TYPE                           (0x810EU) /**< @brief #SKADRV_AEADICVType                      */
#define BRCM_SWARCH_SKADRV_INIT_PROC                               (0x810FU) /**< @brief #SKADRV_Init                             */
#define BRCM_SWARCH_SKADRV_DEINIT_PROC                             (0x8110U) /**< @brief #SKADRV_Deinit                           */
#define BRCM_SWARCH_SKADRV_HASH_INIT_CTX_PROC                      (0x8111U) /**< @brief #SKADRV_HashCtxInit                      */
#define BRCM_SWARCH_SKADRV_HASH_UPDATE_PROC                        (0x8112U) /**< @brief #SKADRV_HashUpdate                       */
#define BRCM_SWARCH_SKADRV_HASH_FINISH_PROC                        (0x8113U) /**< @brief #SKADRV_HashFinish                       */
#define BRCM_SWARCH_SKADRV_HASH_GET_JOB_EXEC_RESULT_PROC           (0x8114U) /**< @brief #SKADRV_HashGetJobExecResult             */
#define BRCM_SWARCH_SKADRV_HASH_CTX_DEINIT_PROC                    (0x8115U) /**< @brief #SKADRV_HashCtxDeinit                    */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_CTX_INIT_PROC               (0x8116U) /**< @brief #SKADRV_AEADLegacyCtxInit                */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_UPDATE_AAD_PROC             (0x8117U) /**< @brief #SKADRV_AEADLegacyUpdateAAD              */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_UPDATE_AAD_TAIL_FINISH_PROC (0x8118U) /**< @brief #SKADRV_AEADLegacyUpdateAADTailAndFinish */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_UPDATE_PLD_PROC             (0x8119U) /**< @brief #SKADRV_AEADLegacyUpdatePld              */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_UPDATE_PLD_AND_FINISH_PROC  (0x811AU) /**< @brief #SKADRV_AEADLegacyUpdatePldAndFinish     */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_GET_JOB_EXEC_RESULT_PROC    (0x811BU) /**< @brief #SKADRV_AEADLegacyGetJobExecResult       */
#define BRCM_SWARCH_SKADRV_AEAD_LEGACY_CTX_DEINIT_PROC             (0x811CU) /**< @brief #SKADRV_AEADLegacyCtxDeinit              */
#define BRCM_SWARCH_SKADRV_AEAD_CTX_INIT_PROC                      (0x811DU) /**< @brief #SKADRV_AEADCtxInit                      */
#define BRCM_SWARCH_SKADRV_AEAD_UPDATE_AAD_PROC                    (0x811EU) /**< @brief #SKADRV_AEADUpdateAAD                    */
#define BRCM_SWARCH_SKADRV_AEAD_UPDATE_AAD_TAIL_PROC               (0x811FU) /**< @brief #SKADRV_AEADUpdateAADTail                */
#define BRCM_SWARCH_SKADRV_AEAD_UPDATE_AAD_TAIL_FINISH_PROC        (0x8120U) /**< @brief #SKADRV_AEADUpdateAADTailAndFinish       */
#define BRCM_SWARCH_SKADRV_AEAD_UPDATE_PLD_PROC                    (0x8121U) /**< @brief #SKADRV_AEADUpdatePld                    */
#define BRCM_SWARCH_SKADRV_AEAD_UPDATE_PLD_AND_FINISH_PROC         (0x8122U) /**< @brief #SKADRV_AEADUpdatePldAndFinish           */
#define BRCM_SWARCH_SKADRV_AEAD_GET_JOB_EXEC_RESULT_PROC           (0x8123U) /**< @brief #SKADRV_AEADGetJobExecResult             */
#define BRCM_SWARCH_SKADRV_AEAD_CTX_DEINIT_PROC                    (0x8124U) /**< @brief #SKADRV_AEADCtxDeinit                    */
/** @} */

/**
    @brief SKA context size

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
#define SKADRV_CONTEXT_SIZE (256UL)

/**
    @brief Maximum length of a packet processed during one SKA context lifecycle

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
#define SKADRV_PACKET_MAX_SIZE (16UL * 512UL * 1024UL)

/**
    @brief Maximum length of a partial packet that can be processed by one API invocation

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
#define SKADRV_PACKET_PARTIAL_MAX_SIZE (512UL * 1024UL)

/**
    @{
    @brief SKA job handle type

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef uint64_t SKADRV_JobHdlType;
#define SKADRV_JOB_HDL_INVALID (0ULL)
/** @} */

/**
    @{
    @brief Logical states of an SKA hashing context

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef uint32_t SKADRV_HashCtxStateIdType;
#define SKADRV_HASH_CTX_STATE_ID_PROCESSING (0x1UL)
#define SKADRV_HASH_CTX_STATE_ID_DONE       (0x2UL)
#define SKADRV_HASH_CTX_STATE_ID_ERROR      (0x3UL)
/** @} */

/**
    @{
    @brief Logical states of an SKA AEAD context

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef uint32_t SKADRV_AEADCtxStateIdType;
#define SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING (0x1UL)
#define SKADRV_AEAD_CTX_STATE_ID_AAD_DONE       (0x2UL)
#define SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING (0x3UL)
#define SKADRV_AEAD_CTX_STATE_ID_DONE           (0x4UL)
#define SKADRV_AEAD_CTX_STATE_ID_ERROR          (0x5UL)
/** @} */


/**
    @{
    @brief Crypt and hash ordering to use with an SKA AEAD legacy context

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef uint32_t SKADRV_AEADLegacyOrderingType;
#define SKADRV_AEAD_LEGACY_ORDERING_CRYPT_THEN_AUTH (0x1UL) /**< @brief Run crypt first and then the auth algorithm */
#define SKADRV_AEAD_LEGACY_ORDERING_AUTH_THEN_CRYPT (0x2UL) /**< @brief Run auth first and then the crypt algorithm */
/** @} */

/**
    @brief An opaque SKA context object

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef struct sSKADRV_CtxType {
    uint64_t data[SKADRV_CONTEXT_SIZE / 8UL]; /**< @brief Opaque context data */
} SKADRV_CtxType;

/**
    @brief Hash context configuration

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef struct sSKADRV_HashCtxCfgType {
    CRYPTO_HashFuncType hashFunc; /**< @brief Hash function to execute */
} SKADRV_HashCtxCfgType;

/**
    @brief Crypt algorithm configuration for an AEAD legacy context

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef struct sSKADRV_AEADLegacyCryptCtxCfgType {
    CRYPTO_KeyType keyType;     /**< @brief Keytype. Must be one of:
                                            -# #CRYPTO_KEY_AES128
                                            -# #CRYPTO_KEY_AES192
                                            -# #CRYPTO_KEY_AES256                                 */
    CRYPTO_AlgModeType algMode; /**< @brief Block cipher mode. Must be one of:
                                            -# #CRYPTO_ALGMODE_CBC_ENC
                                            -# #CRYPTO_ALGMODE_CBC_DEC
                                            -# #CRYPTO_ALGMODE_CTR_ENC
                                            -# #CRYPTO_ALGMODE_CTR_DEC                           */
    const uint8_t *key;         /**< @brief The AES key. The length is inferred from the keyType */
    const uint8_t *iv;          /**< @brief The 16 byte IV                                       */
} SKADRV_AEADLegacyCryptCtxCfgType;

/**
    @brief Authentication algorithm configuration for an AEAD legacy context

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef struct sSKADRV_AEADLegacyAuthCtxCfgType {
    CRYPTO_HashFuncType hashFunc; /**< @brief Hash function to use. Must be one of:
                                        -# #CRYPTO_HASH_FUNC_SHA256
                                        -# #CRYPTO_HASH_FUNC_SHA384                             */
    CRYPTO_AlgModeType algMode;   /**< @brief Auth algorithm mode. Must be one of:
                                        -# #CRYPTO_ALGMODE_HMAC_TAG
                                        -# #CRYPTO_ALGMODE_HMAC_AUTH                            */
    const uint8_t *key;           /**< @brief HMAC key. Key length is fixed to:
                                        -# 32 bytes for the #CRYPTO_HASH_FUNC_SHA256 keyType
                                        -# 48 bytes for the #CRYPTO_HASH_FUNC_SHA384 keyType    */
} SKADRV_AEADLegacyAuthCtxCfgType;

/**
    @brief AEAD legacy context configuration

    For this to describe a valid (and supported) configuration, all the following have to hold:
        -# ordering is valid
        -# cryptCfg holds a valid configuration (refer to #SKADRV_AEADLegacyCryptCtxCfgType)
        -# authCfg holds a valid configuration (refer to #SKADRV_AEADLegacyAuthCtxCfgType)
        -# If one of the two conditions hold:
            -## cryptCfg.algMode = CRYPTO_ALGMODE_*_ENC and authCfg.algMode = CRYPTO_ALGMODE_HMAC_TAG
            -## cryptCfg.algMode = CRYPTO_ALGMODE_*_DEC and authCfg.algMode = CRYPTO_ALGMODE_HMAC_AUTH

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef struct sSKADRV_AEADLegacyCtxCfgType {
    SKADRV_AEADLegacyOrderingType ordering;    /**< @brief Crypt and auth ordering         */
    SKADRV_AEADLegacyCryptCtxCfgType cryptCfg; /**< @brief Crypt algorithm configuration   */
    SKADRV_AEADLegacyAuthCtxCfgType authCfg;   /**< @brief Auth algorithm configuration    */
} SKADRV_AEADLegacyCtxCfgType;

/**
    @brief AEAD context configuration

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef struct sSKADRV_AEADCtxCfgType {
    CRYPTO_KeyType keyType;     /**< @brief Keytype. Must be one of:
                                            -# #CRYPTO_KEY_AES128
                                            -# #CRYPTO_KEY_AES192
                                            -# #CRYPTO_KEY_AES256                                */
    CRYPTO_AlgModeType algMode; /**< @brief Algorithm mode. Must be one of:
                                            -# #CRYPTO_ALGMODE_GCM_ENC_AND_TAG
                                            -# #CRYPTO_ALGMODE_GCM_DEC_AND_AUTH                  */
    const uint8_t *key;         /**< @brief The AES key. The length is inferred from the keyType */
    const uint8_t *iv;          /**< @brief The 12 byte IV                                       */
} SKADRV_AEADCtxCfgType;

/**
    @brief ICV pointer that is either an input to or an output of an AEAD algorithm

    @trace #BRCM_SWREQ_SKADRV_KERNEL_INTERFACE
*/
typedef union uSKADRV_AEADICVType {
    const uint8_t *icvInpPtr; /**< @brief AEAD input pointer  */
    uint8_t *icvOutPtr;       /**< @brief AEAD output pointer */
} SKADRV_AEADICVType;

/**
    @brief Initialize the SKA driver

    @behaviour Sync, Non-reentrant

    @pre SKA driver not initialized

    @retval         #BCM_ERR_OK             Driver initialization complete
    @retval         #BCM_ERR_UNINIT         Driver initialization failed.
    @retval         #BCM_ERR_INVAL_STATE    Driver has already been initialized

    @post The driver is initialized and is ready process other API calls

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_Init(void);

/**
    @brief De-init the SKA driver

    @behaviour Sync, Non-reentrant

    @pre SKA driver initialized

    @retval         #BCM_ERR_OK             Driver de-init complete
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_BUSY           Driver is busy processing the previously
                                            submitted jobs. Driver is not de-init'd
                                            in this case
    @retval         #BCM_ERR_UNKNOWN        De-init failed

    @post SKA driver not initialized

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_Deinit(void);

/**
    @brief Initialize a hashing context

    @behaviour Sync, Non-reentrant

    @pre SKA driver is initialized

    @param[in]      aHashCtxCfg             Hash context configuration
    @param[out]     aCtx                    Context object to initialize


    @retval         #BCM_ERR_OK             Context initialization complete.
                                            aCtx->state = #SKADRV_HASH_CTX_STATE_ID_PROCESSING
                                            aCtx->packetLen = 0
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aHashCtxCfg is NULL or invalid.
                                            aCtx is NULL
    @retval         #BCM_ERR_NOMEM          Not enough system resources are available
                                            to initialize this context

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_HashCtxInit(const SKADRV_HashCtxCfgType *const aHashCtxCfg,
                           SKADRV_CtxType *const aCtx);

/**
    @brief Update the HASH computation with a new partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    A hashing context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be #SKADRV_HASH_CTX_STATE_ID_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
                                            Needs to be a multiple of the hash algorithm's block size
                                            (64 bytes for SHA256 and 128 bytes for SHA384/SHA512).
    @param[in]      aDataIn                 Partial packet data pointer
    @param[out]     aJobHdl                 Handle to the submitted job


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            to process.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    aCtx->state != #SKADRV_HASH_CTX_STATE_ID_PROCESSING or
                                            (aCtx->packetLen + aDataLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_HashGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_HASH_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_HashUpdate(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                          const uint8_t *const aDataIn, SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Update and finish the hash computation with a last partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    A hashing context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be #SKADRV_HASH_CTX_STATE_ID_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
    @param[in]      aDataIn                 Partial packet data pointer.
    @param[out]     aIcvOut                 Memory pointer to which the computed hash is to be
                                            written to.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_HASH_CTX_STATE_ID_DONE.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aIcvOut is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in the #SKADRV_HASH_CTX_STATE_ID_PROCESSING
                                            state.
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_HashGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW. The computed hash is written into the client provided buffer.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_HASH_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_HashFinish(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                          const uint8_t *const aDataIn, uint8_t *const aIcvOut,
                          SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Get a hash job execution result

    @behavior Sync, Reentrant

    @pre SKA driver is initialized

    @param[in]      aJobHdl                 Handle to a submitted job.

    @retval         #BCM_ERR_INVAL_PARAMS   Invalid job handle
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_BUSY           The job is still being processed
    @retval         Others                  Refer to the post-condition documentation
                                            of the API function that generated this jobHdl.

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_HashGetJobExecResult(const SKADRV_JobHdlType aJobHdl);

/**
    @brief De-init a hash context object

    @behaviour Sync, Non-reentrant

    @pre SKA driver is initialized

    @param[in]      aCtx                    Context object to de-init


    @retval         #BCM_ERR_OK             Context de-init complete
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object
    @retval         #BCM_ERR_BUSY           Some jobs issued against the context being
                                            de-init'd are still in flight.

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_HashCtxDeinit(SKADRV_CtxType *const aCtx);

/**
    @brief Initialize a legacy AEAD context

    The "legacy" used in the name here is to distinguish the functionality
    privided by these contexts with the functionality provided by the contexts
    init'd with #SKADRV_AEADCtxInit.

    Modern applications call for combined AEAD modes (AES-GCM, AES-CCM etc). Older
    applications manually combined a cipher and a hash algorithm in a manner that
    is known to be safe. This API allows us to setup these "legacy" AEAD modes.

    @behaviour Sync, Non-reentrant

    @pre SKA driver is initialized

    @param[in]      aAEADLegacyCtxCfg       AEAD legacy context configuration
    @param[out]     aCtx                    Context object to initialize


    @retval         #BCM_ERR_OK             Context initialization complete.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
                                            aCtx->packetLen = 0
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aAEADLegacyCtxCfg is NULL or is invalid
                                            aCtx is NULL
    @retval         #BCM_ERR_NOMEM          Not enough system resources are available
                                            to initialize this context

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADLegacyCtxInit(const SKADRV_AEADLegacyCtxCfgType *const aAEADLegacyCtxCfg,
                                 SKADRV_CtxType *const aCtx);

/**
    @brief Process an AAD legacy partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD legacy context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
                                            Needs to also be a multiple of the authentication algorithm's
                                            block size (64 bytes for SHA256 and 128 bytes for SHA384)
    @param[in]      aDataIn                 Partial packet data pointer.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in the #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
                                            state.
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADLegacyGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADLegacyUpdateAAD(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                                   const uint8_t *const aDataIn, SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Process the last partial packet (which happens to be an AAD legacy paritial packet)

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD legacy context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
    @param[in]      aDataIn                 Partial packet data pointer.
    @param[inout]   aIcv                    If the context is setup with an encrypt and tag AEAD operation,
                                            the computed tag will be written to aICV->icvOutPtr
                                            For decrypt and authenticate operations, the tag from aICV->icvInPtr
                                            is read and is used to authenticate the packet.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_DONE.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aIcv is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in the #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
                                            state.
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADLegacyGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADLegacyUpdateAADTailAndFinish(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                                                const uint8_t *const aDataIn,
                                                SKADRV_AEADICVType aIcv,
                                                SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Process a payload partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD legacy context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be in one of the following:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
                                            Needs to also be a multiple of the authentication algorithm's
                                            block size (64 bytes for SHA256 and 128 bytes for SHA384)
    @param[in]      aDataIn                 Partial packet data input pointer.
    @param[out]     aDataOut                Buffer to which the encrypted/decrypted content is to be
                                            written to.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aDataOut is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in one of the follwoing states:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADLegacyGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW. The encryption/decryption output has been written into the provided buffer.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADLegacyUpdatePld(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                                   const uint8_t *const aDataIn, uint8_t *const aDataOut,
                                   SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Process the last payload partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD legacy context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be in one of the following:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
                                            Needs to be a multiple of 16 if AES-CBC is being used for
                                            encryption/decryption.
    @param[in]      aDataIn                 Partial packet data input pointer.
    @param[out]     aDataOut                Buffer to which the encrypted/decrypted content is to be
                                            written to.
    @param[inout]   aIcv                    If the context is setup with an encrypt and tag AEAD operation,
                                            the computed tag will be written to aICV->icvOutPtr
                                            For decrypt and authenticate operations, the tag from aICV->icvInPtr
                                            is read and is used to authenticate the packet.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_DONE.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aDataOut is NULL.
                                            aICV->icv* is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in one of the follwoing states:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADLegacyGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW. The encryption/decryption output has been written into the provided buffer.
            -# #BCM_ERR_AUTH_FAILED return value indicates that the ICV check failed on the packet.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADLegacyUpdatePldAndFinish(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                                            const uint8_t *const aDataIn, uint8_t *const aDataOut,
                                            SKADRV_AEADICVType aIcv, SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Get an AEAD legacy job execution result

    @behavior Sync, Reentrant

    @pre SKA driver is initialized

    @param[in]      aJobHdl                 Handle to a submitted job.

    @retval         #BCM_ERR_INVAL_PARAMS   Invalid job handle
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_BUSY           The job is still being processed
    @retval         Others                  Refer to the post-condition documentation
                                            of the API function that generated this jobHdl.

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADLegacyGetJobExecResult(const SKADRV_JobHdlType aJobHdl);

/**
    @brief De-init an AEAD legacy context object

    @behaviour Sync, Non-reentrant

    @pre SKA driver is initialized

    @param[in]      aCtx                    Context object to de-init


    @retval         #BCM_ERR_OK             Context de-init complete
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object
    @retval         #BCM_ERR_BUSY           Some jobs issued against the context being
                                            de-init'd are still in flight.

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADLegacyCtxDeinit(SKADRV_CtxType *const aCtx);

/**
    @brief Initialize an AEAD context

    @behaviour Sync, Non-reentrant

    @pre SKA driver is initialized

    @param[in]      aAEADCtxCfg             AEAD context configuration
    @param[out]     aCtx                    Context object to initialize


    @retval         #BCM_ERR_OK             Context initialization complete.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
                                            aCtx->packetLen = 0
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aAEADCtxCfg is NULL or is invalid
                                            aCtx is NULL
    @retval         #BCM_ERR_NOMEM          Not enough system resources are available
                                            to initialize this context

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADCtxInit(const SKADRV_AEADCtxCfgType *const aAEADCtxCfg,
                           SKADRV_CtxType *const aCtx);

/**
    @brief Process an AAD partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
                                            Needs to also be a multiple of the authentication algorithm's
                                            block size (16 bytes for AES-GMAC)
    @param[in]      aDataIn                 Partial packet data pointer.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in the #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
                                            state.
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADUpdateAAD(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                             const uint8_t *const aDataIn, SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Process the last AAD partial packet.

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
    @param[in]      aDataIn                 Partial packet data pointer.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in the #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
                                            state.
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADUpdateAADTail(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                                 const uint8_t *const aDataIn, SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Process the last partial packet (which happens to be an AAD paritial packet)

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
    @param[in]      aDataIn                 Partial packet data pointer.
    @param[inout]   aIcv                    If the context is setup with an encrypt and tag AEAD operation,
                                            the computed tag will be written to aICV->icvOutPtr
                                            For decrypt and authenticate operations, the tag from aICV->icvInPtr
                                            is read and is used to authenticate the packet.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_DONE.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aIcv is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in the #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING
                                            state.
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADUpdateAADTailAndFinish(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                                          const uint8_t *const aDataIn, SKADRV_AEADICVType aIcv,
                                          SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Process a payload partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be in one of the following:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
                                            Needs to also be a multiple of the authentication algorithm's
                                            block size (16 bytes for AES-GMAC)
    @param[in]      aDataIn                 Partial packet data input pointer.
    @param[out]     aDataOut                Buffer to which the encrypted/decrypted content is to be
                                            written to.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aDataOut is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in one of the follwoing states:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW. The encryption/decryption output has been written into the provided buffer.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADUpdatePld(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                             const uint8_t *const aDataIn, uint8_t *const aDataOut,
                             SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Process the last payload partial packet

    @behaviour Async, Non-reentrant

    @pre SKA driver is initialized

    @param[inout]   aCtx                    An AEAD context object against which the
                                            incoming partial packet needs to be processed.
                                            aCtx->state needs to be in one of the following:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
    @param[in]      aDataLen                Length of the partial packet in bytes.
                                            Needs to be in the range (0, #SKADRV_PACKET_PARTIAL_MAX_SIZE].
                                            Needs to be a multiple of 16 if AES-CBC is being used for
                                            encryption/decryption.
    @param[in]      aDataIn                 Partial packet data input pointer.
    @param[out]     aDataOut                Buffer to which the encrypted/decrypted content is to be
                                            written to.
    @param[inout]   aIcv                    If the context is setup with an encrypt and tag AEAD operation,
                                            the computed tag will be written to aICV->icvOutPtr
                                            For decrypt and authenticate operations, the tag from aICV->icvInPtr
                                            is read and is used to authenticate the packet.
    @param[out]     aJobHdl                 Handle to the submitted job.


    @retval         #BCM_ERR_OK             The partial packet has been enqueued for the HW
                                            processing.
                                            aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_DONE.
                                            aCtx->packetLen += aDataLen.
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object.
                                            aDatalen is invalid.
                                            aDataIn is NULL.
                                            aDataOut is NULL.
                                            aICV->icv* is NULL.
                                            aJobHdl is NULL.
    @retval         #BCM_ERR_INVAL_STATE    If the context is not in one of the follwoing states:
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_PROCESSING,
                                            #SKADRV_AEAD_CTX_STATE_ID_AAD_DONE or
                                            #SKADRV_AEAD_CTX_STATE_ID_PLD_PROCESSING
                                            (aDataLen + aCtx->packetLen) > #SKADRV_PACKET_MAX_SIZE
    @retval         #BCM_ERR_NOMEM          The driver job-queue is full and this request cannot be
                                            enqueued at this point.

    @post On successful job submission, #SKADRV_AEADGetJobExecResult should be called by the client
        to check the status of the submission.
            -# #BCM_ERR_OK return value indicates that the submission has been sucessfully processed
               by the HW. The encryption/decryption output has been written into the provided buffer.
            -# #BCM_ERR_AUTH_FAILED return value indicates that the ICV check failed on the packet.
            -# #BCM_ERR_INVAL_STATE error code indicates that an error was encountered while processing the
               partial packet. aCtx->state = #SKADRV_AEAD_CTX_STATE_ID_ERROR

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADUpdatePldAndFinish(SKADRV_CtxType *const aCtx, const uint32_t aDataLen,
                                      const uint8_t *const aDataIn, uint8_t *const aDataOut,
                                      SKADRV_AEADICVType aIcv, SKADRV_JobHdlType *const aJobHdl);

/**
    @brief Get an AEAD job execution result

    @behavior Sync, Reentrant

    @pre SKA driver is initialized

    @param[in]      aJobHdl                 Handle to a submitted job.

    @retval         #BCM_ERR_INVAL_PARAMS   Invalid job handle
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_BUSY           The job is still being processed
    @retval         Others                  Refer to the post-condition documentation
                                            of the API function that generated this jobHdl.

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADGetJobExecResult(const SKADRV_JobHdlType aJobHdl);

/**
    @brief De-init an AEAD context object

    @behaviour Sync, Non-reentrant

    @pre SKA driver is initialized

    @param[in]      aCtx                    Context object to de-init


    @retval         #BCM_ERR_OK             Context de-init complete
    @retval         #BCM_ERR_UNINIT         Driver hasn't been initialized.
    @retval         #BCM_ERR_INVAL_PARAMS   aCtx is NULL or is an invalid context object
    @retval         #BCM_ERR_BUSY           Some jobs issued against the context being
                                            de-init'd are still in flight.

    @post None

    @trace #BRCM_SWREQ_SKADRV_ENTRY_POINTS
*/
int32_t SKADRV_AEADCtxDeinit(SKADRV_CtxType *const aCtx);

#endif
/** @} */
