/*****************************************************************************
 Copyright 2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_xcvr_xfidrv_ifc Interface
    @ingroup grp_xcvr_xfidrv

    @addtogroup grp_xcvr_xfidrv_ifc
    @{
    @section xfi_overview Overview

    @file xfi_drv.h

    @brief Application Programmer Interface for XFI module

    This header file contains the APIs for XFI module

    @version 0.1 Initial revision
*/

#ifndef XFI_DRV_H
#define XFI_DRV_H

#include <module.h>
#include <bcm_err.h>

/**
    @name XFI module API IDs
    @{
    @brief API IDs for XFI module
*/
#define BRCM_SWARCH_XFI_INIT_PROC         (0x8000U) /**< @brief #XFI_Init       */
#define BRCM_SWARCH_XFI_MEM_WRITE_PROC    (0x8001U) /**< @brief #XFI_MemWrite   */


/** @} */

/**
    @brief XFI initialize

    @pre None

    @param[in]    aPortMask     Ports to be initialized (bit mask)

    @post given XFI ports are initialized

    @trace #BRCM_SWREQ_XFI_DRV
*/
int32_t XFI_Init(uint32_t aPortMask);

/**
    @brief Write to XFI controller memory

    @pre None

    @param[in]    aAddress     Ports to be initialized (bit mask)

    @post given XFI ports are initialized

    @trace #BRCM_SWREQ_XFI_DRV
*/
int32_t XFI_MemWrite(uint32_t aStartAddr, uint16_t const *aData, uint32_t aNumWords);

#endif /* XFI_H */
/** @} */
