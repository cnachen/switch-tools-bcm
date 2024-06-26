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
    @defgroup grp_cmem_lib_ifc Memory library interface
    @ingroup grp_cmemmod

    @addtogroup grp_cmem_lib_ifc
    @{

    @file cmem_lib.h

    @brief Crypto Memory Library types and interfaces
    This header file contains common types and macros for cryptography memory
    library

    @version 0.1 Initial Version
*/

#ifndef CMEM_H
#define CMEM_H

#include <stdint.h>
#include <bcm_comp.h>
#include <crypto_common.h>
#include <crypto_memory.h>

/**
    @name Component Architecture IDs
    @{
    @brief Architecture IDs for Component
*/
#define BRCM_SWARCH_CMEM_ALLOC_PARAMS_TYPE            (0x8001U) /**< @brief #CMEM_AllocParamsType       */
#define BRCM_SWARCH_CMEM_KEY_AUX_INFO_TYPE            (0x8002U) /**< @brief #CMEM_KeyAuxInfoType        */
#define BRCM_SWARCH_CMEM_ALLOC_PROC                   (0x8003U) /**< @brief #CMEM_Alloc                 */
#define BRCM_SWARCH_CMEM_FREE_PROC                    (0x8004U) /**< @brief #CMEM_Free                  */
#define BRCM_SWARCH_CMEM_ACQUIRE_PROC                 (0x8005U) /**< @brief #CMEM_Acquire               */
#define BRCM_SWARCH_CMEM_RELEASE_PROC                 (0x8006U) /**< @brief #CMEM_Release               */
#define BRCM_SWARCH_CMEM_GET_AUX_INFO_PROC            (0x8007U) /**< @brief #CMEM_GetAuxInfo            */
#define BRCM_SWARCH_CMEM_GET_HDLS_FROM_COMP_INFO_PROC (0x8008U) /**< @brief #CMEM_GetHdlsFromCompInfo   */
#define BRCM_SWARCH_CMEM_GET_EXPORTABLE_KEY_HDLS_PROC (0x8009U) /**< @brief #CMEM_GetExportableKeyHdls  */
/** @} */

/**
    @brief Crypto Memory Allocate parameters

    Input parameters for memory allocation

    @trace #BRCM_SWREQ_CMEM_MODULE
 */
typedef struct sCMEM_AllocParamsType {
    CRYPTO_KeyType      keyType;      /**< @brief Key information                       */
    CMEM_UsageType      usage;        /**< @brief Key usage                             */
    BCM_CompIDType      compId;       /**< @brief Requester component ID                */
    CMEM_KeyClassIdType keyClassId;   /**< @brief Key class ID                          */
    const uint8_t*      pubKeyData;   /**< @brief Pointer to input public key data      */
    const uint8_t*      privKeyData;  /**< @brief Pointer to input private key data     */
    const uint8_t*      userData;     /**< @brief Pointer to user data                  */
    uint16_t            userDataSize; /**< @brief User data size                        */
} CMEM_AllocParamsType;

/**
    @brief Key auxiliary information

    @trace #BRCM_SWREQ_CMEM_MODULE
 */
typedef struct sCMEM_KeyAuxInfoType {
    CRYPTO_KeyType      keyType;      /**< @brief Key information                       */
    CMEM_UsageType      usage;        /**< @brief Key usage                             */
    BCM_CompIDType      compId;       /**< @brief Requester component ID                */
    CMEM_KeyClassIdType keyClassId;   /**< @brief Key class ID                          */
} CMEM_KeyAuxInfoType;

/**
    @brief Crypto Memory Allocate

    Allocate Crypto Memory

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]      aAllocParams Pointer to input parameters
    @param[inout]   aHdl         Pointer to store the handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_NOMEM               No available memory slot
    @retval     #BCM_ERR_INVAL_PARAMS        aAllocParams is NULL or invalid

    @post None

    @trace #BRCM_SWREQ_CMEM_MODULE

    @limitations None
*/
extern int32_t CMEM_Alloc(const CMEM_AllocParamsType * const aAllocParams, CMEM_HdlType * const aHdl);

/**
    @brief Crypto Memory free

    Free the allocated Crypto Memory

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]   aHdl         Handle to the memory

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_INVAL_PARAMS        aHdl is invalid

    @post None

    @trace #BRCM_SWREQ_CMEM_MODULE

    @limitations None
*/
extern int32_t CMEM_Free(CMEM_HdlType aHdl);

/**
    @brief Acquire Crypto Memory

    Acquire Crypto Memory

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]   aHdl          Handle to the memory
    @param[in]   aModify       Non zero value indicates write operations
    @param[out]  aKeyType      Pointer to store the key type
    @param[out]  aPubKeyData   Pointer to store the public key data
    @param[out]  aPubKeySize   Pointer to store the public key size
    @param[out]  aPrivKeyData  Pointer to store the private key data
    @param[out]  aPrivKeySize  Pointer to store the private key size
    @param[out]  aUserData     Pointer to store the user data
    @param[out]  aUserDataSize Pointer to store the user data size

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_NOPERM              Key can not be acquired for
                                                 given aUsage
    @retval     #BCM_ERR_INVAL_PARAMS        aHdl is invalid
                                             Any of the input pointer param is NULL

    @post None

    @trace #BRCM_SWREQ_CMEM_MODULE

    @limitations None
*/
extern int32_t CMEM_Acquire(CMEM_HdlType aHdl, CMEM_UsageType aUsage,
                            CRYPTO_KeyType *const aKeyType, const uint8_t **const aPubKeyData,
                            uint32_t *const aPubKeySize, const uint8_t **const aPrivKeyData,
                            uint32_t *const aPrivKeySize, const uint8_t **const aUserData,
                            uint32_t *const aUserDataSize);

/**
    @brief Crypto Memory Release

    Release the acquired Crypto Memory

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]   aHdl         Handle to the memory

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_NOPERM              Key is not in acquired state
    @retval     #BCM_ERR_INVAL_PARAMS        aHdl is invalid

    @post None

    @trace #BRCM_SWREQ_CMEM_MODULE

    @limitations None
*/
extern int32_t CMEM_Release(CMEM_HdlType aHdl);

/**
    @brief Get auxiliary key info

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]   aHdl           Handle to the memory
    @param[out]  aKeyAuxInfo    AUX info buffer to fill in

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                  Success
    @retval     #BCM_ERR_INVAL_PARAMS        aHdl is invalid
                                             or aKeyAuxInfo is NULL

    @post None

    @trace #BRCM_SWREQ_CMEM_MODULE

    @limitations None
*/
extern int32_t CMEM_GetAuxInfo(CMEM_HdlType aHdl, CMEM_KeyAuxInfoType *const aKeyAuxInfo);

/**
    @brief Get a list of all the key handles corresponding to a particular component/group ID

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]   aCompId                Component ID
    @param[in]   aKeyClassId            Key class ID
    @param[in]   aKeyHdlBufLen          Length of the provided key handle buffer
    @param[out]  aNumKeyHdls            Number of keys that exist against the provided compID and class ID
    @param[out]  aKeyHdls               Key handle buffer


    @retval     #BCM_ERR_OK             aNumKeyHdls and aKeyHdls have been populated successfully
    @retval     #BCM_ERR_NOMEM          aNumKeyHdls has been populated, but there isn't enough
                                        space in aKeyHdls to populate all the available handles
                                        (or aKeyHdls was NULL to begin with)
    @retval     #BCM_ERR_INVAL_PARAMS   aKeyHdls is NULL
                                        aKeyHdls is NULL but aKeyHdlBufLen is non-zero

    @post None

    @trace #BRCM_SWREQ_CMEM_MODULE

    @limitations None
*/
extern int32_t CMEM_GetHdlsFromCompInfo(const BCM_CompIDType aCompId,
                                        const CMEM_KeyClassIdType aKeyClassId,
                                        const uint32_t aKeyHdlBufLen, uint32_t *const aNumKeyHdls,
                                        CMEM_HdlType *const aKeyHdls);

/**
    @brief Get a list of all the NV key handles active in the CMEM

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]   aKeyHdlBufLen          Length of the key buffer
    @param[out]  aNumExportableKeys     Number of exportportable key handles available in the system
    @param[out]  aExportableKeyHdls     Key handle buffer. Can be NULL.


    @retval     #BCM_ERR_OK             aNumExportableKeys and aExportableKeyHdls have been populated
                                        successfully
    @retval     #BCM_ERR_NOMEM          aNumExportableKeys has been populated, but there isn't enough
                                        space in aExportableKeyHdls to populate all the handles (or
                                        aExportableKeyHdls was NULL to begin with).
    @retval     #BCM_ERR_INVAL_PARAMS   aNumNVKeys is NULL.
                                        aNVKeyHdls is NULL but aKeyHdlBufLen is not zero.

    @post None

    @trace #BRCM_SWREQ_CMEM

    @limitations None
*/
extern int32_t CMEM_GetExportableKeyHdls(const uint32_t aKeyHdlBufLen, uint32_t *const aNumExportableKeys,
                                         CMEM_HdlType *const aExportableKeyHdls);
#endif /* CMEM_H */
/** @} */
