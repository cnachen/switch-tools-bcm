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
    @defgroup grp_csrbgdrv_ifc CSRBG driver interface for the crypto-service
    @ingroup grp_csrbg

    @addtogroup grp_csrbgdrv_ifc
    @{
    The crypto-service uses the interface below to inittialize, de-initialize
    and get random bits from the platform's RBG.

    @file csrbg.h
    @brief Interface File
    @version 0.1 Initial Version
*/
#ifndef CSRBG_H
#define CSRBG_H

#include <bcm_comp.h>
#include <bcm_utils.h>
#include <stdint.h>

/**
    @name CSRBG driver Architecture IDs
    @{
    @brief Architecture IDs for the CSRBG driver
*/
#define BRCM_SWARCH_CSRBG_MAX_NUM_RAND_BYTES_MACRO (0x8101U) /**< @brief #CSRBG_MAX_NUM_RAND_BYTES */
#define BRCM_SWARCH_CSRBG_INIT_PROC                (0x8102U) /**< @brief #CSRBG_Init               */
#define BRCM_SWARCH_CSRBG_DEINIT_PROC              (0x8103U) /**< @brief #CSRBG_Deinit             */
#define BRCM_SWARCH_CSRBG_GET_RAND_BYTES_PROC      (0x8104U) /**< @brief #CSRBG_GetRandBytes       */
/** @} */

/**
    @brief Maximum number of random bytes that can be requested via the @ref CSRBG_GetRandBytes API

    @trace #BRCM_SWREQ_CSRBG_KERNEL_INTERFACE
*/
#define CSRBG_MAX_NUM_RAND_BYTES (64UL)

/**
    @brief Initialize the CSRBG driver

    @behaviour Sync, Non-reentrant

    @pre CSRBG driver not initialized

    @retval         #BCM_ERR_OK             Driver initialization complete
    @retval         #BCM_ERR_UNINIT         Driver initialization failed.
                                            The caller may re-try at a later
                                            point in time
    @retval         #BCM_ERR_INVAL_STATE    Driver has already been initialized


    @post The driver is initialized and is ready to generate random bits

    @trace #BRCM_SWREQ_CSRBG_INIT
*/
int32_t CSRBG_Init(void);

/**
    @brief De-init the CSBRG driver

    @behaviour Sync, Non-reentrant

    @pre CSRBG driver initialized

    @retval         #BCM_ERR_OK             Driver de-init complete
    @retval         #BCM_ERR_UNKNOWN        De-init failed

    @post CSRBG driver not initialized

    @trace #BRCM_SWREQ_CSRBG_DEINIT
*/
int32_t CSRBG_Deinit(void);

/**
    @brief Aquire random bits from the platform's RBG

    @behaviour Sync, Non-reentrant

    @pre CSBRG initialized

    @param[in]      aNumBytes               Number of random bytes to populate.
                                            Should be in the range
                                            (0, #CSRBG_MAX_NUM_RAND_BYTES]
    @param[out]     aBuffer                 Buffer into which the random bytes are
                                            to be populated


    @retval         #BCM_ERR_OK             On success
    @retval         #BCM_ERR_INVAL_STATE    Driver has not been initialized
    @retval         #BCM_ERR_INVAL_PARAMS   aNumBytes not in the specified range or
                                            aBuffer is NULL
    @retval         #BCM_ERR_EAGAIN         The system does not have enough entropy to
                                            service this request. The caller may retry
                                            after some time

    @post None

    @trace #BRCM_SWREQ_CSRBG_GET_RAND_BITS
*/
int32_t CSRBG_GetRandBytes(const uint32_t aNumBytes, uint8_t *const aBuffer);

#endif /* CSRBG_H */
/** @} */
