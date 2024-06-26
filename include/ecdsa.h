/*****************************************************************************
 Copyright 2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ecdsa_sw_ifc Interface
    @ingroup grp_ecdsa_sw

    @addtogroup grp_ecdsa_sw_ifc
    @{
    @file ecdsa.h
    @brief ECDSA SW routines API header
    This file contains the interface function declarations for the ECDSA
    SW routines

    @version 0.1 Initial Version
*/
#ifndef ECDSA_H
#define ECDSA_H

#include <secutils.h>

/**
    @name ECDSA Architecture IDs
    @{
    @brief Architecture IDs for the ECDSA API's
*/
#define BRCM_SWARCH_ECC_DOMAIN_TYPE                                 (0x8201U)   /**< @brief #ECC_DomainType                         */
#define BRCM_SWARCH_ECDSA_VERIFY_CONTEXT_SIZE_WORDS_MACRO           (0x8202U)   /**< @brief #ECDSA_VERIFY_CONTEXT_SIZE_WORDS        */
#define BRCM_SWARCH_ECDSA_VERIFY_CONTEXT_TYPE                       (0x8204U)   /**< @brief #ECDSA_VerifyContextType                */
#define BRCM_SWARCH_ECDSA_VERIFY_CONTEXT_INIT_PROC                  (0x8205U)   /**< @brief #ECDSA_VerifyContextInit                */
#define BRCM_SWARCH_ECDSA_VERIFY_CONTEXT_INIT_FROM_COMPRESSED_PROC  (0x8206U)   /**< @brief #ECDSA_VerifyContextInitFromCompressed  */
#define BRCM_SWARCH_ECDSA_VERIFY_PROC                               (0x8207U)   /**< @brief #ECDSA_Verify                           */
/** @} */

/**
    @brief ECC domain type

    @trace #BRCM_SWREQ_ECC_DOMAIN_SW_ROUTINES
*/
typedef uint32_t ECC_DomainType;
#define ECC_DOMAIN_SECP256R1        (1UL)
#define ECC_DOMAIN_SECP384R1        (2UL)

/**
    @brief ECDSA verify context size

    @trace #BRCM_SWREQ_ECDSA_VERIFY_SW_ROUTINES
*/
#define ECDSA_VERIFY_CONTEXT_SIZE_WORDS         (768UL)

/**
    @brief ECDSA verify context type

    @trace #BRCM_SWREQ_ECDSA_VERIFY_SW_ROUTINES
*/
typedef struct sECDSA_VerifyContextType {
    uint32_t ecdsaVerifyCtxOpaqueData[ECDSA_VERIFY_CONTEXT_SIZE_WORDS]; /**< @brief Opaque verify context data  */
} ECDSA_VerifyContextType;

/**
    @brief Initialize an ECDSA verification context

    The implementation uses a significant amount of stack space.
    Callers are expected to ensure that there is about 4K bytes of free stack space
    before issuing this function call.

    @behavior Sync, reentrant

    @pre None

    @param[in]      aECCDomain              ECDSA domain
    @param[in]      aPx                     Public key point X, big-endian integer
    @param[in]      aPy                     Public key point Y, big-endian integer.
    @param[out]     aCtx                    ECDSA verification context to initialize

    Return values are documented in reverse-chronological order
    @retval         BCM_ERR_INVAL_PARAMS    Invalid aECCDomain,
                                            NULL aPx, NULL aPy
                                            Invalid aPx or aPy or both,
                                            aScratchMem NULL,
                                            aCtx NULL
    @retval         BCM_ERR_OK              Context init sucessful

    @post None

    @trace #BRCM_SWREQ_ECDSA_VERIFY_SW_ROUTINES
*/
int32_t ECDSA_VerifyContextInit(const ECC_DomainType aECCDomain, const uint8_t *const aPx, const uint8_t *const aPy, ECDSA_VerifyContextType *const aCtx);

/**
    @brief Initialize an ECDSA verification context from a compressed key

    The implementation uses a significant amount of stack space.
    Callers are expected to ensure that there is about 4K bytes of free stack space
    before issuing this function call.

    @behavior Sync, reentrant

    @pre None

    @param[in]      aECCDomain              ECDSA domain
    @param[in]      aPx                     Public key point X, big-endian integer
    @param[in]      aPubKeyPrefixByte       The one byte prefix of the compressed ECDSA public
                                            key. Can only be 0x2 or 0x3.
                                            0x2 indicates that the Public key point Y is even
                                            0x3 indicates that the Public key point Y is odd
    @param[out]     aCtx                    ECDSA verification context to initialize

    Return values are documented in reverse-chronological order
    @retval         BCM_ERR_INVAL_PARAMS    Invalid aECCDomain,
                                            NULL aPx,
                                            Invalid aPx,
                                            Invalid aPubKeyPrefixByte,
                                            aCtx NULL
    @retval         BCM_ERR_OK              Context init sucessful


    @post None

    @trace #BRCM_SWREQ_ECDSA_VERIFY_SW_ROUTINES
*/
int32_t ECDSA_VerifyContextInitFromCompressed(const ECC_DomainType aECCDomain, const uint8_t *const aPx, const uint8_t aPubKeyPrefixByte, ECDSA_VerifyContextType *const aCtx);

/**
    @brief Execute the ECDSA verification operation

    The implementation uses a significant amount of stack space.
    Callers are expected to ensure that there is about 4K bytes of free stack space
    before issuing this function call.

    @behavior Sync, reentrant

    @pre None

    @param[in]      aCtx                    An initialized ECDSA verification context
    @param[in]      aMsgDigestLen           Message digest length in bytes
    @param[in]      aMsgDigest              Computed digest of the message
    @param[in]      aR                      R coordinate of the signature to be verified, big-endian integer.
                                            The number of bytes to read is determined from the context init
                                            parameters used to init the aCtx
    @param[in]      aS                      S coordinate of the signature to be verified, big-endian integer
                                            The number of bytes to read is determined from the context init
                                            parameters used to init the aCtx

    Return values are documented in reverse-chronological order
    @retval         BCM_ERR_INVAL_PARAMS    aCtx NULL or invalid,
                                            aMsgDigestLen unsupported against the given aCtx,
                                            aMsgDigest NULL,
                                            aR NULL, aS NULL,
                                            aScratchMem NULL
    @retval         BCM_ERR_AUTH_FAILED     Signature verification failed
    @retval         BCM_ERR_OK              Signature verification sucessful

    @post None

    @trace #BRCM_SWREQ_ECDSA_VERIFY_SW_ROUTINES
*/
int32_t ECDSA_Verify(const ECDSA_VerifyContextType *const aCtx, const uint32_t aMsgDigestLen, const uint8_t *const aMsgDigest, const uint8_t *const aR, const uint8_t *const aS);

#endif /* ECDSA_H */
/** @} */

