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
    @defgroup grp_crypto_random_ifc Crypto Random Interface
    @ingroup grp_crypto_abstract

    @addtogroup grp_crypto_random_ifc
    @{

    @limitations None

    @file crypto_random.h
    @brief Crypto Random Interface
    This header file contains the interface functions to obtain random bit strings from a TRNG/CSPRNG
    @version 0.1 Initial Version
*/
#ifndef CRYPTO_RANDOM_H
#define CRYPTO_RANDOM_H

#include <msg_queue.h>

/**
    @name Crypto random Architecture IDs
    @{
    @brief Architecture IDs for Crypto random routines
*/
#define BRCM_SWARCH_CSRBG_ID_OF_MACRO            (0x8400U)   /**< @brief #CSRBG_ID_OF                 */
#define BRCM_SWARCH_CSRBG_CMD_TYPE               (0x8401U)   /**< @brief #CSRBG_CmdIDType             */
#define BRCM_SWARCH_CSRBG_MAX_FETCH_BYTES_MACRO  (0x8402U)   /**< @brief #CSRBG_MAX_FETCH_BYTES       */
#define BRCM_SWARCH_CSRBG_GET_BYTES_PROC         (0x8403U)   /**< @brief #CSRBG_GetBytes              */
#define BRCM_SWARCH_CSRBG_GET_STATUS_PROC        (0x8404U)   /**< @brief #CSRBG_GetStatus             */
/** @} */

/**
    @brief Macro to Construct CmdID

    @trace #BRCM_SWREQ_CSRBG
*/
#define CSRBG_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_CRYPTO, BCM_CSRBG_ID, aId)

/**
  @name RBG supported command
  @{
  @brief RBG module supported command

  @trace #BRCM_SWREQ_CSRBG
*/
typedef BCM_MsgType CSRBG_CmdIDType;                      /**< @brief typedef for RBG cmdID */
#define CSRBG_CMD_RPC_GETBYTES           CSRBG_ID_OF(1UL) /**< @brief Get random bytes      */
/** @} */

/**
    @brief Maximum number of random bytes that may be fetched with one #CSRBG_GetBytes invocation

    @trace #BRCM_SWREQ_CSRBG
*/
#define CSRBG_MAX_FETCH_BYTES   (64UL)

/** @brief Submit a request to acquire a few random bytes

    @behavior Async, Re-entrant

    @pre Random module is in initialized state

    @param[in]      aNumBytes               Number of random bytes to fetch
    @param[in]      aClientMask             Mask with which the caller need to be signalled
    @param[out]     aJobHdl                 Job handle

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Request submitted successfully
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_INVAL_PARAMS   (aJobHdl is NULL) or (aNumBytes is more than #CSRBG_MAX_FETCH_BYTES)

    @post On successful submission of this request, #CSRBG_GetStatus
        may be called to get the status of the submitted request

    @trace #BRCM_SWREQ_CSRBG

    @limitations None
*/
int32_t CSRBG_GetBytes(uint32_t aNumBytes, const uint32_t aClientMask, MSGQ_HdlType *const aJobHdl);

/** @brief Get the status of the submitted GetRandomBytes request

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aJobHdl                 RandomGetBytes Job handle
    @param[out]     aBuffer                 Buffer to copy random bytes

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Request processing complete
    @retval         #BCM_ERR_BUSY           Request is being processed
    @retval         #BCM_ERR_UNKNOWN        Integration fault
    @retval         #BCM_ERR_INVAL_PARAMS   aBuffer is NULL or the handles are invalid

    @note aBuffer should be sufficient to hold #CSRBG_MAX_FETCH_BYTES bytes

    @post None

    @trace #BRCM_SWREQ_CSRBG

    @limitations None
*/
int32_t CSRBG_GetStatus(const MSGQ_HdlType aJobHdl, uint8_t *const aBuffer);

#endif
/** @} */
