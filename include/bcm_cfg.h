/*****************************************************************************
 Copyright 2012-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_abstract_bcm_cfg BCM Config handling
    @ingroup grp_abstract

    @addtogroup grp_abstract_bcm_cfg
    @{
    @section sec_bcm_cfg_overview Overview

    This file specifies function and types for accessing BCM configuration

    @file bcm_cfg.h

    @brief BCM Config handling

    @version Initial
*/

#ifndef BCM_CFG_H
#define BCM_CFG_H

#include <stdint.h>
#include <bcm_err.h>
#include <bcm_utils.h>

/**
    @name BCM Config handling architecture IDs
    @{
    @brief Architecture IDs for BCM Config handling
*/
#define BRCM_SWARCH_BCM_BOARD_CFG_TYPE         (0x8C01U)    /**< @brief #BCM_BoardCfgType    */
#define BRCM_SWARCH_BCM_BOARD_CFG_HDR_TYPE     (0x8C02U)    /**< @brief #BCM_BoardCfgHdrType */
#define BRCM_SWARCH_BCM_GET_BOARD_CFG_PROC     (0x8C03U)    /**< @brief #BCM_GetBoardCfg     */
#define BRCM_SWARCH_BCM_BOARD_CFG_IMG_GLOBAL   (0x8C04U)    /**< @brief #BCM_BoardCfgImg     */
/** @} */

/**
    @name Board config type
    @{
    @brief Board config type and macros

    @trace #BRCM_SWREQ_BCM_CFG
*/
typedef uint32_t BCM_BoardCfgType;
#define BCM_BOARD_CFG_FLASH        BCM_PACK32('F', 'L', 'S', 'H')
#define BCM_BOARD_CFG_MDIO         BCM_PACK32('M', 'D', 'I', 'O')
#define BCM_BOARD_CFG_GPIO         BCM_PACK32('G', 'P', 'I', 'O')
#define BCM_BOARD_CFG_DDR          BCM_PACK32('D', 'D', 'R', 'M')
#define BCM_BOARD_CFG_CUST         BCM_PACK32('C', 'U', 'S', 'T')
#define BCM_BOARD_CFG_RPC          BCM_PACK32('R', 'P', 'C', '0')
/** @} */

/**
    @brief Board config header

    The header format to be appended to each board config
    structure.

    @trace #BRCM_SWREQ_BCM_CFG
*/
typedef struct sBCM_BoardCfgHdrType {
    uint32_t cfgType;
    uint32_t version;
    uint32_t count;
    uint32_t size;
} BCM_BoardCfgHdrType;

/**
    @brief Board config image

    @trace #BRCM_SWREQ_BCM_CFG
*/
extern const uint8_t BCM_BoardCfgImg[BCM_BOARD_CFG_SIZE - 512UL];

/** @brief Get board config

    @behavior Sync, Re-entrant

    @pre None

    @param[in]    aCfgType   Config type
    @param[in]    aCfgSize   Config structure size
    @param[out]   aCfg       Config structure to store the config
    @param[out]   aVersion   Version of the config structure
    @param[in]    aCfgCount  Config Count

    @retval BCM_ERR_NOT_FOUND    Given configuration not found in the image
    @retval BCM_ERR_INVAL_PARAMS aCfg or aVersion is NULL
    @retval BCM_ERR_OK           Configuration copied successfully

    @post None

    @trace  #BRCM_SWREQ_BCM_CFG
*/
int32_t BCM_GetBoardCfg(BCM_BoardCfgType aCfgType,
                        uint32_t aCfgSize,
                        const void **aCfg,
                        uint32_t *aVersion,
                        uint32_t *aCfgCount);

#endif

/** @} */
