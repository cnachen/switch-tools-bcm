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

/** @defgroup grp_xcvr_abstract_module_ifc XCVR Abstract Module Interface
    @ingroup grp_transceiver_abstract

    @addtogroup grp_xcvr_abstract_module_ifc
    @{

    @file xcvr_module.h
    @brief XCVR Abstract Module Interface

    @version 1.0 Initial version
*/

#ifndef XCVR_MODULE_H
#define XCVR_MODULE_H

#include <module.h>
/**
    @name XCVR Abstract Module Interface IDs
    @{
    @brief Integration Interface IDs for XCVR Abstract Modules
*/
#define BRCM_SWARCH_XCVR_SERVICE_GLOBAL     (0x8101U) /**< @brief #XCVR_Service      */
#define BRCM_SWARCH_XFI_MODULE_GLOBAL       (0x8102U) /**< @brief #XFI_Module        */
#define BRCM_SWARCH_XCVR_MODULE_GLOBAL      (0x8103U) /**< @brief #XCVR_Module       */
/** @} */

/**
    @brief XCVR Service
    @trace #BRCM_SWREQ_XCVR
*/
extern const SERVICE_Type XCVR_Service;

/**
    @brief XFI Module interface function pointers

    @trace #BRCM_SWREQ_XFI
 */
extern const MODULE_Type XFI_Module;

/**
    @brief XCVR Module interface function pointers

    @trace #BRCM_SWREQ_XCVR
 */
extern const MODULE_Type XCVR_Module;

#endif /* XCVR_MODULE_H */
/** @} */
