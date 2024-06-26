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
    @defgroup grp_crypto_mem_ifc Memory Types
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_mem_ifc
    @{

    @file crypto_memory.h
    @brief Crypto Memory Types and Macros
    This header file contains common types and macros for cryptography memory

    @version 0.1 Initial Version
*/

#ifndef CRYPTO_MEMORY_H
#define CRYPTO_MEMORY_H

#include <stdint.h>
#include <bcm_comp.h>
#include <crypto_common.h>

/**
    @name Component Architecture IDs
    @{
    @brief Architecture IDs for Component
*/
#define BRCM_SWARCH_CMEM_HDL_TYPE          (0x8501U)   /**< @brief #CMEM_HdlType               */
#define BRCM_SWARCH_CMEM_KEY_CLASS_ID_TYPE (0x8502U)   /**< @brief #CMEM_KeyClassIdType        */
#define BRCM_SWARCH_CMEM_USAGE_TYPE        (0x8503U)   /**< @brief #CMEM_UsageType             */
/** @} */

/**
    @name Crypto memory handle macros
    @{
    @brief Crypto memory handle macros

    Represented by 32-bits of CRC, 16-bits of random seed, and 16-bits of index.
    Special handles are as described below.

    @trace #BRCM_SWREQ_CMEM
*/
typedef uint64_t CMEM_HdlType;
#define CMEM_HDL_INVALID           (0x00ULL)    /**< @brief Invalid Handle                                            */
#define CMEM_HDL_MVK               (0x01ULL)    /**< @brief Module Manufacturer Verification Key (Public Key in OTP)  */
#define CMEM_HDL_DUK0_CRYPT_IMGL   (0x02ULL)    /**< @brief Device unique encryption key for IMGL/Update modules      */
#define CMEM_HDL_DUK0_AUTH_IMGL    (0x03ULL)    /**< @brief Device unique auth key for IMGL/Update modules            */
#define CMEM_HDL_DUK_TXRX_FLASH    (0x04ULL)    /**< @brief DUK to encrypt/decrypt keys to support secure key storage */
#define CMEM_HDL_MCK0_CRYPT        (0x05ULL)    /**< @brief Symmetric key to decrypt the OTA update images            */
#define CMEM_HDL_MCK0_AUTH         (0x06ULL)    /**< @brief Symmetric key to authenticate the OTA update images       */
/** @} */

/**
    @brief Key class ID

    @trace #BRCM_SWREQ_CMEM
 */
typedef uint16_t CMEM_KeyClassIdType;

/**
    @name Crypto memory usage macros
    @{
    @brief Crypto memory usage macros

    Represented by 32-bit mask

    @trace #BRCM_SWREQ_CMEM
*/
typedef uint32_t CMEM_UsageType;
#define CMEM_USAGE_INVALID         (0UL)           /**< @brief Invalid Usage                            */
#define CMEM_USAGE_DERIV           (1UL << 0UL)    /**< @brief Usable for key-derivation                */
#define CMEM_USAGE_SIGN            (1UL << 1UL)    /**< @brief Usable for cryptographic signing         */
#define CMEM_USAGE_VERIFY          (1UL << 2UL)    /**< @brief Usable for signature verification        */
#define CMEM_USAGE_ENCRYPT         (1UL << 3UL)    /**< @brief Usable for bulk encryption               */
#define CMEM_USAGE_DECRYPT         (1UL << 4UL)    /**< @brief Usable for bulk decryption               */
#define CMEM_USAGE_KEK             (1UL << 5UL)    /**< @brief Usable for key encryption or decryption  */
#define CMEM_USAGE_IV              (1UL << 6UL)    /**< @brief Usable as IV or salt                     */
#define CMEM_USAGE_EXPORT          (1UL << 7UL)    /**< @brief Exportable key                           */
#define CMEM_USAGE_EXPORT_RAW      (1UL << 8UL)    /**< @brief Raw Exportable key                       */
/** @} */

#endif /* CRYPTO_MEMORY_H */
/** @} */
