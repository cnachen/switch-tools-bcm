/*****************************************************************************
 Copyright 2020-2021 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_rsa_v2_ifc Interface
    @ingroup grp_rsa_v2

    @addtogroup grp_rsa_v2_ifc
    @{
    @file rsa_v2.h
    @brief rsa SW routines API header
    This file contains the interface function declarations for rsa
    SW routines

    @version 0.1 Initial Version
*/
#ifndef RSA_V2_H
#define RSA_V2_H

#include <stdint.h>
#include <secutils.h>

/**
    @name RSA Architecture IDs
    @{
    @brief Architecture IDs for the RSA API's
*/
#define BRCM_SWARCH_RSA_PADDING_TYPE                    (0x8201U)    /**< @brief #RSA_PaddingType                 */
#define BRCM_SWARCH_RSA_SSA2K_MEM_NUM_WORDS_MACRO       (0x8202U)    /**< @brief #RSA_SSA2K_MEM_NUM_WORDS_SCRATCH */
#define BRCM_SWARCH_RSA_SSA2K_SCRATCH_MEM_TYPE          (0x8203U)    /**< @brief #RSA_SSA2KScratchMemType         */
#define BRCM_SWARCH_RSA_SSA2K_CTX_TYPE                  (0x8204U)    /**< @brief #RSA_SSA2KCtxType                */
#define BRCM_SWARCH_RSA_SSA2K_COMPUTE_CTX_PROC          (0x8205U)    /**< @brief #RSA_SSA2KComputeCtx             */
#define BRCM_SWARCH_RSA_SSA2K_VERIFY_PROC               (0x8206U)    /**< @brief #RSA_SSA2KVerify                 */
#define BRCM_SWARCH_RSA_SSA2K_DECRYPT_SIGNATURE_PROC    (0x8207U)    /**< @brief #RSA_SSA2KDecryptSignature       */
#define BRCM_SWARCH_RSA_SSA2K_EMSA4_VERIFY_PROC         (0x8208U)    /**< @brief #RSA_SSA2KEMSA4Verify            */
/** @} */

/**
    @{
    @brief RSA digest padding types

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
typedef uint32_t RSA_PaddingType;
#define RSA_PADDING_PKCS_V21                                (1UL)   /* PKCS#1 v2.1 encoding */
/** @} */

/**
    @{
    @brief Buffer sizes for RSA SSA2K operations

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
#define RSA_SSA2K_MEM_NUM_WORDS_SCRATCH                     (258UL)
#define RSA_SSA2K_MEM_NUM_WORDS_MODULUS                     (64UL)
#define RSA_SSA2K_MEM_NUM_WORDS_RMODN                       (64UL)
#define RSA_SSA2K_MEM_NUM_WORDS_RRMODN                      (65UL)
/** @} */

/**
    @brief Scratch memory for the RSA SSA2K operations

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
typedef struct sRSA_SSA2KScratchMemType {
    uint32_t bufferScratch[RSA_SSA2K_MEM_NUM_WORDS_SCRATCH];
} RSA_SSA2KScratchMemType;

/**
    @brief RSA SSA2K context

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
typedef struct sRSA_SSA2KCtxType {
    uint32_t bufferN[RSA_SSA2K_MEM_NUM_WORDS_MODULUS];
    uint32_t bufferRmodN[RSA_SSA2K_MEM_NUM_WORDS_RMODN];
    uint32_t bufferRRmodN[RSA_SSA2K_MEM_NUM_WORDS_RRMODN];
    SECUTILS_BigUintMontCtxType montCtx;
} RSA_SSA2KCtxType;

/** @brief Compute an RSA SSA2K context

    @behavior Sync, reentrant

    @pre None

    @param[in]      aPadding                    Padding type
    @param[in]      aPublicKey                  RSA public key modulus. The public
                                                exponent is assumed to be 65537
    @param[in]      aPubLen                     Length of the public key in bytes
    @param[in]      aRsaSaa2KScratchMem         An instance of @ref RSA_SSA2KScratchMemType
    @param[inout]   aRsaSsa2KCtx                RSA SSA2K context to initialize

    Return values are documented in reverse-chronological order
    @retval         BCM_ERR_OK                  Context initialization success
    @retval         BCM_ERR_INVAL_PARAMS        Invalid padding,
                                                aPublicKey NULL or is not 256 bytes long, or
                                                is an invalid RSA modulus, aRsaSaa2KScratchMem NULL,
                                                aRsaSsa2KCtx is NULL
    @post None

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
int32_t RSA_SSA2KComputeCtx(const RSA_PaddingType aPadding, const uint8_t* const aPublicKey, const uint32_t aPubLen, RSA_SSA2KScratchMemType *const aRsaSaa2KScratchMem, RSA_SSA2KCtxType *const aRsaSsa2KCtx);

/** @brief Execute an RSA SSA2K verification operation

    @behavior Sync, reentrant

    @pre None

    @param[in]      aRsaSsa2KCtx                RSA SSA2K context
    @param[in]      aSignature                  Signature to be verified
    @param[in]      aSigLen                     Signature length in bytes
    @param[in]      aDigest                     Message digest. Hash algorithm used for
                                                digest computation is assumed to be SHA256
    @param[in]      aDigestLen                  Message digest length in bytes
    @param[in]      aRsaSaa2KScratchMem         An instance of @ref RSA_SSA2KScratchMemType

    Return values are documented in reverse-chronological order
    @retval         BCM_ERR_OK                  Signature verification operation sucessful
    @retval         BCM_ERR_AUTH_FAILED         Signature verification operation failed as
                                                the signature and the digest are inconsistent
                                                with one another
    @retval         BCM_ERR_INVAL_PARAMS        Input pointer parametres are NULL or invalid,
                                                aSigLen is not 256, aDigestLen is not 32

    @post None

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
int32_t RSA_SSA2KVerify(const RSA_SSA2KCtxType *const aRsaSsa2KCtx, const uint8_t* const aSignature, uint32_t aSigLen, const uint8_t* const aDigest, const uint32_t aDigestLen, RSA_SSA2KScratchMemType *const aRsaSaa2KScratchMem);


/** @brief Decrypt signature for RSA SSA2K verification operation

    This functionality is implicity performed when RSA_SSA2KVerify
    is invoked. This API is provided for advanced users for specific
    timing purposes

    @behavior Sync, reentrant

    @pre RSA_SSA2KComputeCtx is invoked on context to initialize

    @param[in]      aRsaSsa2KCtx                RSA SSA2K context
    @param[in]      aSignature                  Signature to be verified
    @param[in]      aSigLen                     Signature length in bytes
    @param[in]      aRsaSaa2KScratchMem         An instance of @ref RSA_SSA2KScratchMemType

    Return values are documented in reverse-chronological order
    @retval         BCM_ERR_OK                  Signature decryption operation sucessful
    @retval         BCM_ERR_INVAL_PARAMS        Input pointer parametres are NULL or invalid,
                                                aSigLen is not 256

    @post The decrypted signature is placed in the first 256 bytes in the
        scratch memory

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
int32_t RSA_SSA2KDecryptSignature(const RSA_SSA2KCtxType *const aRsaSsa2KCtx, const uint8_t* const aSignature, uint32_t aSigLen, RSA_SSA2KScratchMemType *const aRsaSaa2KScratchMem);

/** @brief Compare hash for RSA SSA2K verification operation

    This functionality is implicity performed when RSA_SSA2KVerify
    is invoked. This API is provided for advanced users for specific
    timing purposes

    @behavior Sync, reentrant

    @pre The decrypted signature must be placed in the first 256 bytes in the
        scratch memory

    @param[in]      aDigest                     Message digest. Hash algorithm used for
                                                digest computation is assumed to be SHA256
    @param[in]      aDigestLen                  Message digest length in bytes
    @param[in]      aRsaSaa2KScratchMem         An instance of @ref RSA_SSA2KScratchMemType

    Return values are documented in reverse-chronological order
    @retval         BCM_ERR_OK                  Hash comparison sucessful
    @retval         BCM_ERR_AUTH_FAILED         Hash comparison failed as the decrypted
                                                signature and the digest are inconsistent
                                                with one another
    @retval         BCM_ERR_INVAL_PARAMS        Input pointer parametres are NULL or invalid,
                                                aDigestLen is not 32

    @post None

    @trace #BRCM_SWREQ_RSA_SW_ROUTINES
*/
int32_t RSA_SSA2KEMSA4Verify(const uint8_t* const aDigest, const uint32_t aDigestLen, RSA_SSA2KScratchMemType *const aRsaSaa2KScratchMem);

#endif /* RSA_H */

/** @} */
