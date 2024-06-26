/*****************************************************************************
 Copyright 2022-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_inout_service Service
    @ingroup grp_inout_abstract

    @addtogroup grp_inout_service
    @{

    @file inout_module.h
    @brief IO Service

    @version 0.1 Initial Version
*/

#ifndef INOUT_MODULE_H
#define INOUT_MODULE_H

#include <module.h>

/**
    @name IO Abstract Module Interface Ids
    @{
    @brief Architecture IDs for IO interface abstract Service and Modules
*/
#define BRCM_SWARCH_IOS_SERVICE_GLOBAL       (0x7001U) /**< @brief #IOS_Service      */
#define BRCM_SWARCH_IOM_MODULE_GLOBAL        (0x7002U) /**< @brief #IOM_Module       */
#define BRCM_SWARCH_I2C_MODULE_GLOBAL        (0x7003U) /**< @brief #I2C_Module       */
#define BRCM_SWARCH_MAX9295A_MODULE_GLOBAL   (0x7004U) /**< @brief #MAX9295A_Module  */
#define BRCM_SWARCH_PCA9673_MODULE_GLOBAL    (0x7005U) /**< @brief #PCA9673_Module   */
/** @} */

/**
    @brief IO Service
    @trace #BRCM_SWREQ_IOS
*/
extern const SERVICE_Type IOS_Service;

/**
    @brief Structure for IO module

    @trace #BRCM_SWREQ_IOM
 */
extern const MODULE_Type IOM_Module;

/**
    @brief Structure for I2C module

    @trace #BRCM_SWREQ_I2C
 */
extern const MODULE_Type I2C_Module;

/**
    @brief Structure for MAX9295A module

    @trace #BRCM_SWREQ_MAX9295A
 */
extern const MODULE_Type MAX9295A_Module;

/**
    @brief Structure for PCA9673 module

    @trace #BRCM_SWREQ_PCA9673
 */
extern const MODULE_Type PCA9673_Module;

#endif /* INOUT_MODULE_H */
/** @} */
