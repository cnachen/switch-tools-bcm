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
    @defgroup grp_arc_mpu_ifc ARC MPU management routines
    @ingroup grp_arc

    @addtogroup grp_arc_mpu_ifc
    @{
    Helper macros and function prototypes to manage an MPU
    on an ARC based CPU

    @file arc_mpu.h
    @brief Interface File
    This header file contains helper macros and function prototypes
    to manage an MPU on an ARC based CPU
    @version 0.1 Initial Version
*/
#ifndef ARC_MPU_H
#define ARC_MPU_H

#include <stdint.h>
#include <mpu.h>

/**
    @name ARC MPU management helper routines Architecture IDs
    @{
    @brief Architecture IDs for the ARC MPU management helpers
*/
#define BRCM_SWARCH_MPU_ARC_REGION_ATTR_TYPE            (0x8201U)   /**< @brief #MPU_ArcRegionAttrType                          */
#define BRCM_SWARCH_MPU_ARC_REGION_ACCESS_ATTR_TYPE     (0x8202U)   /**< @brief #MPU_ArcRegionAccessAttrType                    */
#define BRCM_SWARCH_MPU_ARC_REGION_SIZE_ATTR_TYPE       (0x8203U)   /**< @brief #MPU_ArcRegionSizeAttrType                      */
#define BRCM_SWARCH_MPU_ARC_GET_REGION_SIZE_MACRO       (0x8204U)   /**< @brief #MPU_ARC_GET_REGION_SIZE_LOG2_FROM_SIZE_ATTR    */
#define BRCM_SWARCH_MPU_ARC_MAX_REGIONS_MACRO           (0x8205U)   /**< @brief #MPU_ARC_MAX_REGIONS                            */
/** @} */

/**
    @{
    @brief MPU region attributes

    @trace #BRCM_SWREQ_MPU_ABSTRACTION_ARC
*/
typedef uint32_t MPU_ArcRegionAttrType;
#define MPU_ARC_REGION_ATTR_SIZE_SHIFT                  (0UL)
#define MPU_ARC_REGION_ATTR_SIZE_MASK                   (0x1FUL)
#define MPU_ARC_REGION_ATTR_ACCESS_SHIFT                (8UL)
#define MPU_ARC_REGION_ATTR_ACCESS_MASK                 (0x3F00UL)
#define MPU_ARC_REGION_ATTR_INVALID_BITS_MASK           (0xFFFFC0E0UL)
/** @} */

/**
    @{
    @brief MPU region access attributes

    @trace #BRCM_SWREQ_MPU_ABSTRACTION_ARC
*/
typedef uint32_t MPU_ArcRegionAccessAttrType;
#define MPU_ARC_REGION_ACCESS_ATTR_USER_EXECUTE_BIT     ( 1UL << MPU_ARC_REGION_ATTR_ACCESS_SHIFT)
#define MPU_ARC_REGION_ACCESS_ATTR_USER_WRITE_BIT       ( 2UL << MPU_ARC_REGION_ATTR_ACCESS_SHIFT)
#define MPU_ARC_REGION_ACCESS_ATTR_USER_READ_BIT        ( 4UL << MPU_ARC_REGION_ATTR_ACCESS_SHIFT)
#define MPU_ARC_REGION_ACCESS_ATTR_KERNEL_EXECUTE_BIT   ( 8UL << MPU_ARC_REGION_ATTR_ACCESS_SHIFT)
#define MPU_ARC_REGION_ACCESS_ATTR_KERNEL_WRITE_BIT     (16UL << MPU_ARC_REGION_ATTR_ACCESS_SHIFT)
#define MPU_ARC_REGION_ACCESS_ATTR_KERNEL_READ_BIT      (32UL << MPU_ARC_REGION_ATTR_ACCESS_SHIFT)
/** @} */

/**
    @{
    @brief MPU region size attributes

    @trace #BRCM_SWREQ_MPU_ABSTRACTION_ARC
*/
typedef uint32_t MPU_ArcRegionSizeAttrType;
#define MPU_ARC_REGION_SIZE_ATTR_32B                    (0x04UL)
#define MPU_ARC_REGION_SIZE_ATTR_64B                    (0x05UL)
#define MPU_ARC_REGION_SIZE_ATTR_128B                   (0x06UL)
#define MPU_ARC_REGION_SIZE_ATTR_256B                   (0x07UL)
#define MPU_ARC_REGION_SIZE_ATTR_512B                   (0x08UL)
#define MPU_ARC_REGION_SIZE_ATTR_1K                     (0x09UL)
#define MPU_ARC_REGION_SIZE_ATTR_2K                     (0x0AUL)
#define MPU_ARC_REGION_SIZE_ATTR_4K                     (0x0BUL)
#define MPU_ARC_REGION_SIZE_ATTR_8K                     (0x0CUL)
#define MPU_ARC_REGION_SIZE_ATTR_16K                    (0x0DUL)
#define MPU_ARC_REGION_SIZE_ATTR_32K                    (0x0EUL)
#define MPU_ARC_REGION_SIZE_ATTR_64K                    (0x0FUL)
#define MPU_ARC_REGION_SIZE_ATTR_128K                   (0x10UL)
#define MPU_ARC_REGION_SIZE_ATTR_256K                   (0x11UL)
#define MPU_ARC_REGION_SIZE_ATTR_512K                   (0x12UL)
#define MPU_ARC_REGION_SIZE_ATTR_1M                     (0x13UL)
#define MPU_ARC_REGION_SIZE_ATTR_2M                     (0x14UL)
#define MPU_ARC_REGION_SIZE_ATTR_4M                     (0x15UL)
#define MPU_ARC_REGION_SIZE_ATTR_8M                     (0x16UL)
#define MPU_ARC_REGION_SIZE_ATTR_16M                    (0x17UL)
#define MPU_ARC_REGION_SIZE_ATTR_32M                    (0x18UL)
#define MPU_ARC_REGION_SIZE_ATTR_64M                    (0x19UL)
#define MPU_ARC_REGION_SIZE_ATTR_128M                   (0x1AUL)
#define MPU_ARC_REGION_SIZE_ATTR_256M                   (0x1BUL)
#define MPU_ARC_REGION_SIZE_ATTR_512M                   (0x1CUL)
#define MPU_ARC_REGION_SIZE_ATTR_1G                     (0x1DUL)
#define MPU_ARC_REGION_SIZE_ATTR_2G                     (0x1EUL)
#define MPU_ARC_REGION_SIZE_ATTR_4G                     (0x1FUL)
/** @} */

/**
    @{
    @brief Helpers to convert between log2 sizes and the region attributes defined by @ref MPU_ArcRegionSizeAttrType

    @trace #BRCM_SWREQ_MPU_ABSTRACTION_ARC
*/
#define MPU_ARC_GET_REGION_SIZE_LOG2_FROM_SIZE_ATTR(aAttr)      ((aAttr) + 1UL)
#define MPU_ARC_GET_REGION_SIZE_ATTR_FROM_SIZE_LOG2(aSzLog2)    ((aSzLog2) - 1UL)
/** @} */

/**
    @brief MPU max number of supported regions

    @trace #BRCM_SWREQ_MPU_ABSTRACTION_ARC
*/
#define MPU_ARC_MAX_REGIONS                             (16UL)

#endif
/** @} */
