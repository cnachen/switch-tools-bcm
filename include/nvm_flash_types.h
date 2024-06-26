/*****************************************************************************
 Copyright 2016-2023 Broadcom Limited.  All rights reserved.

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

/** @defgroup grp_nvm_flash_types Flash types
    @ingroup grp_nvm_abstract

    @addtogroup grp_nvm_flash_types
    @{

    @file nvm_flash_types.h
    @brief Interface for FLASH Abstract

    @version 0.1 Initial version
*/

#ifndef NVM_FLASH_TYPES_H
#define NVM_FLASH_TYPES_H

#include <bcm_comp.h>
#include <bcm_utils.h>

/**
    @name NVM FLASH Abstract Interface IDs
    @{
    @brief Interface IDs for NVM FLASH Abstract

*/
#define BRCM_SWARCH_FLASH_HW_ID_TYPE                (0x8000U)   /**< @brief #FLASH_HwIDType           */
#define BRCM_SWARCH_FLASH_ADDR_TYPE                 (0x8001U)   /**< @brief #FLASH_AddrType           */
#define BRCM_SWARCH_FLASH_LEN_TYPE                  (0x8002U)   /**< @brief #FLASH_LenType            */
#define BRCM_SWARCH_FLASH_READ_LANE_TYPE            (0x8003U)   /**< @brief #FLASH_ReadLaneType       */
#define BRCM_SWARCH_FLASH_SPI_MODE_TYPE             (0x8004U)   /**< @brief #FLASH_SPIModeType        */
#define BRCM_SWARCH_FLASH_SPEED_TYPE                (0x8005U)   /**< @brief #FLASH_SpeedType          */
#define BRCM_SWARCH_FLASH_FLSID_TYPE                (0x8006U)   /**< @brief #FLASH_FlsIDType          */
#define BRCM_SWARCH_FLASH_FLSABLE_SECTOR_TYPE       (0x8007U)   /**< @brief #FLASH_FlsableSecType     */
#define BRCM_SWARCH_FLASH_CFG_TYPE                  (0x8008U)   /**< @brief #FLASH_CfgType            */
#define BRCM_SWARCH_FLASH_CFG_TBL_TYPE              (0x8009U)   /**< @brief #FLASH_CfgTblType         */

#define BRCM_SWARCH_FLASH_MAX_SEC_GROUPS_MACRO      (0x8010U)   /**< @brief #FLASH_MAX_SEC_GROUPS     */
/** @} */

/**
    @name FLASH_HwIDType
    @{
    @brief Flash controller ID type

    @trace #BRCM_SWREQ_FLASH
 */
typedef uint32_t FLASH_HwIDType;            /**< @brief FLash controller ID type */
#define FLASH_HW_ID_0               (0UL)   /**< @brief Flash controller 0 */
#define FLASH_HW_ID_1               (1UL)   /**< @brief Flash controller 1 */
/** @} */

/**
    @brief Flash Address Type

    @trace #BRCM_SWREQ_FLASH
*/
typedef uint32_t FLASH_AddrType;

/**
    @brief Flash length type
    This type shall be same as Flash address type as these will be used for
    arithmetics.

    @trace #BRCM_SWREQ_FLASH
 */
typedef uint32_t FLASH_LenType;
#define FLASH_LEN_PAGE        (256UL) /**< @brief Flash page length in bytes */

/**
    @name FLASH_ReadLaneType
    @{
    @brief Flash read lane type

    @trace #BRCM_SWREQ_FLASH
*/
typedef uint32_t FLASH_ReadLaneType;        /**< @brief typedef for flash read lane */
#define FLASH_READ_LANE_SINGLE      (1UL)   /**< @brief Flash single lane read mode */
#define FLASH_READ_LANE_DUAL        (2UL)   /**< @brief Flash dual lane read mode */
#define FLASH_READ_LANE_QUAD        (3UL)   /**< @brief Flash quad lane read mode */
/** @} */

/**
    @name FLASH_SPIModeType
    @{
    @brief Flash SPI mode type

    @trace #BRCM_SWREQ_FLASH
 */
typedef uint32_t FLASH_SPIModeType;         /**< @brief typedef for Flash SPI mode */
#define FLASH_SPI_MODE_0            (1UL)   /**< @brief SPI mode-0 (CPOL = 0, CPHA = 0) */
#define FLASH_SPI_MODE_1            (2UL)   /**< @brief SPI mode-1 (CPOL = 0, CPHA = 1) */
#define FLASH_SPI_MODE_2            (3UL)   /**< @brief SPI mode-2 (CPOL = 1, CPHA = 0) */
#define FLASH_SPI_MODE_3            (4UL)   /**< @brief SPI mode-3 (CPOL = 1, CPHA = 1) */
/** @} */
/**
    @name FLASH_SpeedType
    @{
    @brief Flash speed type

    @trace #BRCM_SWREQ_FLASH
*/
typedef uint32_t FLASH_SpeedType;           /**< @brief typedef for flash speed */
#define FLASH_SPEED_25M         (0UL)   /**< @brief SPI speed = 25MHz */
#define FLASH_SPEED_50M         (1UL)   /**< @brief SPI speed = 50MHz */
#define FLASH_SPEED_62M         (2UL)   /**< @brief SPI speed = 62MHz */
#define FLASH_SPEED_66M         (3UL)   /**< @brief SPI speed = 66MHz */
#define FLASH_SPEED_80M         (4UL)   /**< @brief SPI speed = 80MHz */
/** @} */


/**
    @name FLASH_FlsIDType
    @{
    @brief Flash ID type

    Flash ID type
    Bits 23 - 16: Manufacturer ID,
    Bits 15 - 8: Device ID15-8,
    Bits 7 - 0: Device ID7-0

    @trace #BRCM_SWREQ_FLASH
*/
typedef uint32_t FLASH_FlsIDType;           /**< @brief typedef for flash ID */
#define FLASH_FLSID_WINBOND_W25Q16      (0xEF4015UL)    /**< @brief Winbond, W25Q16 flash ID */
#define FLASH_FLSID_WINBOND_W25Q64CV    (0xEF4017UL)    /**< @brief Winbond, W25Q64CV flash ID */
#define FLASH_FLSID_MICRON_N25Q512A     (0x20BA20UL)    /**< @brief Micron, N25Q512A flash ID */
#define FLASH_FLSID_MACRONIX_MX25R32    (0xc22816UL)    /**< @brief Micronix, MX25R3235F flash ID */
#define FLASH_FLSID_MACRONIX_MX25L32    (0xc22016UL)    /**< @brief Micronix, MX25R3233F flash ID */
#define FLASH_FLSID_MACRONIX_MX25L12833 (0xc22018UL)    /**< @brief Micronix, MX25L12833F flash ID */
#define FLASH_FLSID_MICRON_M25P16       (0x202015UL)    /**< @brief Micron, M25P16 flash ID */
#define FLASH_FLSID_UNKNOWN_ID          (0xFFFFFFUL)    /**< @brief Default ID for unknown flash */
/** @} */

/**
    @brief Maximum number of sector groups

    @trace #BRCM_SWREQ_FLASH
 */
#define FLASH_MAX_SEC_GROUPS            (4UL)

/**
    @brief Flash writable sector list

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_FlsableSecType {
    FLASH_AddrType  startAddr;      /**< @brief Start address of writable sectors/subsector @xsd default:0*/
    uint32_t        numSectors;     /**< @brief Number of writable sectors/subsectors @xsd default:0*/
} FLASH_FlsableSecType;

/**
    @brief Flash configuration

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_CfgType {
    uint32_t            size;                       /**< @brief Total flash size in bytes @xsd hex;default:0x400000 */
    uint32_t            pageSize;                   /**< @brief Flash page size in bytes @xsd hex;default:0x100*/
    uint32_t            sectorSize;                 /**< @brief Flash sector size in bytes @xsd hex;default:0x10000*/
    uint32_t            subSectorSize;              /**< @brief Subsector size in bytes @xsd hex;default:0x1000*/
    FLASH_SPIModeType   SPIMode;                    /**< @brief SPI mode @xsd default:FLASH_SPI_MODE_3*/
    FLASH_SpeedType     speed;                      /**< @brief SPI speed @xsd default:FLASH_SPEED_80M*/
    FLASH_ReadLaneType  readLane;                   /**< @brief Number of lane of read operation @xsd default:FLASH_READ_LANE_DUAL*/
    uint32_t            flsableSecListSize;         /**< @brief Size of flashable sector list @xsd count:flsableSecList */
    FLASH_FlsableSecType flsableSecList[FLASH_MAX_SEC_GROUPS];    /**< @brief Pointer to flashable sector list */
    FLASH_FlsIDType     flsID;                      /**< @brief Flash ID                            */
    uint8_t             reserved[64];               /**< @brief Reserved for future use @xsd rsvd   */
} FLASH_CfgType;
BCM_STATIC_SIZE_ASSERT(FLASH_CfgType, 132UL, 132UL)

/**
    @brief FLASH configuration table

    Flash configuration table type. This configuration structure shall be used
    by system integrator to define flash configuration static table to be used
    for flash driver initialization.

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_CfgTblType {
    FLASH_HwIDType  hwID;       /**< @brief Flash controller ID */
    FLASH_CfgType   config;     /**< @brief Flash driver configuration for hwID
                                     flash controller */
} FLASH_CfgTblType;
BCM_STATIC_SIZE_ASSERT(FLASH_CfgTblType, 136UL, 136UL)

#endif /* NVM_FLASH_TYPES_H */
/** @} */
