/*****************************************************************************
 Copyright 2021 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_symmcryptlib_ifc SYMMCRYPT library interface
    @ingroup grp_symmcrypt

    @addtogroup grp_symmcryptlib_ifc
    @{
    This header lists the API's that the clients could use to access the
    symmetric crypto accelerator present on the platform

    The hash API provided by this library is expected to be used in INIT->UPDATE->FINISH
    fashion. A typical sequence looks as following:

        SYMMCRYPT_CreateHashContext(SYMMCRYPT_HASH_ALG_SHA256, &ctxHdl)
        while (this data chunk is not last) {
            SYMMCRYPT_HashUpdate(ctxHdl, msgBufLen, msgBuf)
            << Wait for the job to finish >>
        }
        SYMMCRYPT_HashFinish(ctxHdl, lastMsgBufLen, lastMsgBuf, digestBuf)
        << Wait for the job to finish >>

    The computed digest is written to the client provided digestBuf.

    @file symmcrypt_lib.h
    @brief Interface File
    This header file contains the interface functions for the SYMMCRYPT library
    @version 0.1 Initial Version
*/
#ifndef SYMMCRYPT_LIB_H
#define SYMMCRYPT_LIB_H

#include <stdint.h>
#include <crypto_common.h>

/**
    @name SYMMCRYPT library Architecture IDs
    @{
    @brief Architecture IDs for the SYMMCRYPT library
*/
#define BRCM_SWARCH_SYMMCRYPT_CONTEXT_HANDLE_TYPE               (0x8601U)   /**< @brief #SYMMCRYPT_ContextHandleType    */
#define BRCM_SWARCH_SYMMCRYPT_INIT_PROC                         (0x8602U)   /**< @brief #SYMMCRYPT_Init                 */
#define BRCM_SWARCH_SYMMCRYPT_DEINIT_PROC                       (0x8603U)   /**< @brief #SYMMCRYPT_Deinit               */
#define BRCM_SWARCH_SYMMCRYPT_CREATE_HASH_CONTEXT_PROC          (0x8604U)   /**< @brief #SYMMCRYPT_CreateHashContext    */
#define BRCM_SWARCH_SYMMCRYPT_DESTROY_HASH_CONTEXT_PROC         (0x8605U)   /**< @brief #SYMMCRYPT_DestroyHashContext   */
#define BRCM_SWARCH_SYMMCRYPT_HASH_UPDATE_PROC                  (0x8606U)   /**< @brief #SYMMCRYPT_HashUpdate           */
#define BRCM_SWARCH_SYMMCRYPT_HASH_FINISH_PROC                  (0x8607U)   /**< @brief #SYMMCRYPT_HashFinish           */
#define BRCM_SWARCH_SYMMCRYPT_GET_JOB_EXEC_RESULT_PROC          (0x8608U)   /**< @brief #SYMMCRYPT_GetJobExecResult     */
/** @} */

/**
    @brief SYMMCRYPT context handle

    This context handle is invalidated when
        -# The client explicitly issues @ref SYMMCRYPT_DestroyHashContext
        -# Client calls the @ref SYMMCRYPT_HashFinish API
        -# HW error occoured while processing a job issued against this context

    @trace #BRCM_SWREQ_SYMMCRYPT_KERNEL_INTERFACE
*/
typedef uint64_t SYMMCRYPT_ContextHandleType;

/**
    @brief SYMMCRYPT Driver and hardware initialization

    Initialize the SYMMCRYPT driver data structures and setup the
    SYMMCRYPT HW engine

    @behavior Sync, Non-reentrant

    @pre None

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK                 Success
    @retval         #BCM_ERR_UNKNOWN            Driver initialization failed

    @post The driver is ready to accept SYMMCRYPT jobs

    @trace #BRCM_SWREQ_SYMMCRYPT_LIBRARY
*/
int32_t SYMMCRYPT_Init(void);

/**
    @brief SYMMCRYPT Driver and hardware deinit

    Deinit the SYMMCRYPT driver data structures and reset the HW

    @behavior Sync, Non-reentrant

    @pre None

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK                 Success
    @retval         #BCM_ERR_UNKNOWN            Driver deinit failed
    @retval         #BCM_ERR_BUSY               Cannot deinit because a job is in-flight.
                                                Client may retry at a later point

    @post On successful call to this API, HW and all the driver data structures are reset

    @trace #BRCM_SWREQ_SYMMCRYPT_LIBRARY
*/
int32_t SYMMCRYPT_Deinit(void);

/**
    @brief Create a SYMMCRYPT driver context

    @behavior Sync, Reentrant

    @pre None

    @param[in]      aHashFunc                   Hash function against which the context is to be created
    @param[out]     aCtxHdl                     Handle to the newly created context.

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK                 On successful context creation
    @retval         #BCM_ERR_INVAL_PARAMS       Invalid hashFunc or NULL aCtxHdl
    @retval         #BCM_ERR_NOMEM              Context creation failed because driver couldn't set aside
                                                the needed amount of memory to create a context

    @limitations
        -# This API only accepts #CRYPTO_HASH_FUNC_SHA256 and #CRYPTO_HASH_FUNC_SHA384
           for the time being

    @trace #BRCM_SWREQ_SYMMCRYPT_LIBRARY
*/
int32_t SYMMCRYPT_CreateHashContext(const CRYPTO_HashFuncType aHashFunc, SYMMCRYPT_ContextHandleType *const aCtxHdl);

/**
    @brief Destroy the SYMMCRYPT driver context

    This function may be called by the clients if they do need
    a SYMMCRYPT context anymore.

    As the documentation of @ref SYMMCRYPT_ContextHandleType notes, the SYMMCRYPT
    context handle is automatically invalidated after a call to @ref SYMMCRYPT_Finish
    or if a HW error was seen when a previously submitted job against
    this context was run. The clients are not expected to call this API
    in those situations.

    @behavior Sync, Reentrant

    @param[in]      aCtxHdl                     Context handle corresponding to the context to
                                                destroy

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS       Invalid context handle
    @retval         #BCM_ERR_OK                 Context has been sucessfully destroyed

    @trace #BRCM_SWREQ_SYMMCRYPT_LIBRARY
*/
int32_t SYMMCRYPT_DestroyHashContext(const SYMMCRYPT_ContextHandleType aCtxHdl);

/**
    @brief Update the hash computations given a new chunk of input data

    @behavior Async, Reentrant

    @pre None

    @param[in]      aCtxHdl                     Context handle against which the SYMMCRYPT job is to be
                                                issued
    @param[in]      aMsgLenBytes                Input data size in bytes
    @param[in]      aMsg                        Buffer containing the input data

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK                 On successful job submission
    @retval         #BCM_ERR_INVAL_PARAMS       aCtxHdl invalid
                                                aMsgLenBytes is zero or non-multiple of hash alg block size
                                                aMsg NULL
    @retval         #BCM_ERR_BUSY               HW is processing a previously submitted job

    @post After successful job submission, the client may query the status of the job execution by calling
            the @ref SYMMCRYPT_GetJobExecResult API.

    @limitations
        -# If the context was setup with a @ref CRYPTO_HASH_FUNC_SHA256 operation, aMsgLenBytes
           parameter should be a multiple of 64 (SHA256 block size). If @ref CRYPTO_HASH_FUNC_SHA384
           were chosen, aMsgLenBytes should be a multiple of 128 bytes.

    @trace #BRCM_SWREQ_SYMMCRYPT_LIBRARY
*/
int32_t SYMMCRYPT_HashUpdate(const SYMMCRYPT_ContextHandleType aCtxHdl, const uint32_t aMsgLenBytes, const uint8_t *const aMsg);

/**
    @brief Finish the hash computations given a the last chunk of input data

    @behavior Async, Reentrant

    @pre None

    @param[in]      aCtxHdl                     Context handle against which the SYMMCRYPT job is to be
                                                issued
    @param[in]      aMsgLenBytes                Input data size in bytes
    @param[in]      aMsg                        Buffer containing the input data
    @param[out]     aDigest                     Buffer to which the computed digest is to be written to

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK                 On successful job submission
    @retval         #BCM_ERR_INVAL_PARAMS       aCtxHdl invalid
                                                aMsgLenBytes is zero or non-multiple of hash alg block size
                                                aMsg NULL
                                                aDigest NULL
    @retval         #BCM_ERR_BUSY               HW is processing a previously submitted job


    @post After successful job submission, the client may query the status of the job execution by calling
            the @ref SYMMCRYPT_GetJobExecResult API. Also, the context handle is invalidated and can no
            longer be used.

    @trace #BRCM_SWREQ_SYMMCRYPT_LIBRARY
*/
int32_t SYMMCRYPT_HashFinish(const SYMMCRYPT_ContextHandleType aCtxHdl, const uint32_t aMsgLenBytes, const uint8_t *const aMsg, uint8_t *const aDigest);

/**
    @brief Get the job execution result

    The API's to run the hash algorithms provided by this library are asynchronous.
    Clients can call this API to check the status of the last submitted job.

    The return value from this API is sticky. It will only change (on calling this
    function) if a new job was sucessfully submitted or if a submitted job finished
    executing.

    @behavior Sync, Reentrant

    @pre None

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK                 Success
    @retval         #BCM_ERR_BUSY               HW is processing a previously submitted job
    @retval         #BCM_ERR_INVAL_STATE        Job execution failed because of a HW error

    @post None

    @trace #BRCM_SWREQ_SYMMCRYPT_LIBRARY
*/
int32_t SYMMCRYPT_GetJobExecResult(void);

#endif /* SYMMCRYPT_LIB_H */
/** @} */
