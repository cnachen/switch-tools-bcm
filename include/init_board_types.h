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
    @defgroup grp_initialization_board_types Board Configuration Types
    @ingroup grp_initialization

    @addtogroup grp_initialization_board_types
    @{
    @file init_board_types.h

    @brief Board configuration

    @version Initial
*/

#ifndef INIT_BOARD_TYPES_H
#define INIT_BOARD_TYPES_H

#include <stdint.h>
#include <bcm_err.h>
#include <bcm_utils.h>
#include <nvm_flash_types.h>
#include <rpc_types.h>

/**
    @name BCM Config handling architecture IDs
    @{
    @brief Architecture IDs for BCM Config handling
*/
#define BRCM_SWARCH_BOARD_ACCESS_TYPE           (0x8000U)    /**< @brief #BOARD_AccessType          */
#define BRCM_SWARCH_BOARD_CUSTOM_PROG_TYPE      (0x8001U)    /**< @brief #BOARD_CustomProgType      */

#define BRCM_SWARCH_BOARD_FLASH_V1_CFG_TYPE     (0x8010U)    /**< @brief #BOARD_FlashV1CfgType      */
#define BRCM_SWARCH_BOARD_CUSTOM_PROG_CFG_TYPE  (0x8011U)    /**< @brief #BOARD_CustomProgCfgType   */
#define BRCM_SWARCH_BOARD_RPC_CFG_TYPE          (0x8012U)    /**< @brief #BOARD_RpcCfgType          */

#define BRCM_SWARCH_BOARD_V1_CFG_TYPE           (0x8020U)    /**< @brief #BOARD_V1CfgType           */
/** @} */


/**
    @brief Board config header

    #BCM_BoardCfgHdrType is expected to be the first four words.

    @trace #BRCM_SWREQ_BOARD
*/
typedef struct sBOARD_FlashV1CfgType {
    BCM_BoardCfgType        type;       /**< @brief Config type    @xsd constant:BCM_BOARD_CFG_FLASH*/
    uint32_t                version;    /**< @brief version @xsd constant:0                         */
    uint32_t                count;      /**< @brief count of flash configurations   @xsd constant:1 */
    uint32_t                size;       /**< @brief size of each config element @xsd constant:136   */
    FLASH_CfgTblType        cfg;
} BOARD_FlashV1CfgType;
BCM_STATIC_SIZE_ASSERT(BOARD_FlashV1CfgType, 152UL, 152UL)

/**
    @name Register access type
    @{
    @brief Register access type

    @trace #BRCM_SWREQ_BOARD
*/
typedef uint32_t BOARD_AccessType;
#define BOARD_ACCESS_TYPE_MASK      (0x000000FFUL)
#define BOARD_ACCESS_TYPE_SHIFT     (0x0UL)
#define BOARD_ACCESS_TYPE_NONE      (0x00UL)    /**< @brief No Access           */
#define BOARD_ACCESS_TYPE_AXI32     (0x01UL)    /**< @brief 32-bit AXI access   */
#define BOARD_ACCESS_TYPE_AXI16     (0x02UL)    /**< @brief 16-bit AXI access   */
#define BOARD_ACCESS_TYPE_AXI08     (0x03UL)    /**< @brief 8-bit AXI access    */
#define BOARD_ACCESS_STATE_MASK     (0x0000FF00UL)  /**< @brief Mask @xsd enum:BCM_STATE_UNINIT@UNINIT
                                                        @xsd enum:BCM_STATE_INIT@INIT,BCM_STATE_READY@READY
                                                        @xsd enum:BCM_STATE_RUN@RUN,BCM_STATE_ERROR@ERROR */
#define BOARD_ACCESS_STATE_SHIFT    (0x8UL)     /**< @brief Shift       */
#define BOARD_ACCESS_MODULE_MASK    (0xFFFF0000UL)  /**< @brief Mask @xsd enum:BCM_CompIDType */
#define BOARD_ACCESS_MODULE_SHIFT   (0x10UL)
/** @} */

/**
    @brief Voltage configuration

    *addr = (*addr & ~mask) | (value & mask)

    @trace #BRCM_SWREQ_BOARD
*/
typedef struct sBOARD_CustomProgType {
    BOARD_AccessType    accessMode;     /**< @brief Access mode                              */
    uint32_t            addr;           /**< @brief Address     @xsd hex;default:0x0         */
    uint32_t            value;          /**< @brief value to be written @xsd hex;default:0x0 */
    uint32_t            mask;           /**< @brief mask @xsd hex;default:0xffffffff         */
} BOARD_CustomProgType;
BCM_STATIC_SIZE_ASSERT(BOARD_CustomProgType, 16UL, 16UL)


/**
    @brief Custom programming config

    @trace #BRCM_SWREQ_BOARD
*/
typedef struct sBOARD_CustomProgCfgType {
    BCM_BoardCfgType        type;       /**< @brief Config type    @xsd constant:BCM_BOARD_CFG_CUST */
    uint32_t                version;    /**< @brief version @xsd constant:0                         */
    uint32_t                count;      /**< @brief count of flash configurations   @xsd constant:64*/
    uint32_t                size;       /**< @brief size of each config element @xsd constant:16    */
    BOARD_CustomProgType    cfg[64UL];
} BOARD_CustomProgCfgType;
BCM_STATIC_SIZE_ASSERT(BOARD_CustomProgCfgType, 1040UL, 1040UL)

/**
    @brief RPC config

    @trace #BRCM_SWREQ_BOARD
*/
typedef struct sBOARD_RpcCfgType {
    BCM_BoardCfgType        type;       /**< @brief Config type    @xsd constant:BCM_BOARD_CFG_RPC  */
    uint32_t                version;    /**< @brief version @xsd constant:0                         */
    uint32_t                count;      /**< @brief count of flash configurations   @xsd constant:1 */
    uint32_t                size;       /**< @brief size of each config element @xsd constant:256   */
    RPC_CfgType             cfg;        /**< @brief RPC config                                      */
} BOARD_RpcCfgType;
BCM_STATIC_SIZE_ASSERT(BOARD_RpcCfgType, 272UL, 272UL)
/**
    @brief Board config header

    The header format to be appended to each board config
    structure.

    @trace #BRCM_SWREQ_BOARD
*/
typedef struct sBOARD_V1CfgType {
    BOARD_FlashV1CfgType        flsCfg;     /**< @brief Flash configuration                 */
    BOARD_CustomProgCfgType     custCfg;    /**< @brief Custom programming configuration    */
    BOARD_RpcCfgType            rpcCfg;     /**< @brief RPC configuration                   */
    uint8_t                     reserved[2120UL];   /**< @brief @xsd rsvd                   */
} BOARD_V1CfgType;
BCM_STATIC_SIZE_ASSERT(BOARD_V1CfgType, 3584UL, 3584UL)


#endif

/** @} */
