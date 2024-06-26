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
    @defgroup grp_macsecdrv_plat_ifc Platform Interface
    @ingroup grp_macsecdrv

    @addtogroup grp_macsecdrv_plat_ifc
    @{
    @file macsec_platform.h

    @brief MACSec driver platform interface
    This file defines MACSec Driver platform interfaces

    @version 0.1 Initial revision
*/

#ifndef MACSEC_PLAT_H
#define MACSEC_PLAT_H

#include <stdint.h>
#include <bcm_comp.h>
#include <crypto_secy_local.h>
#include <crypto_secy_types.h>

/**
    @name MACSec driver API IDs
    @{
    @brief API IDs for MACSec Platform
*/
#define BRCM_SWARCH_MACSEC_GET_BUS_IFC_PROC           (0x8100U) /**< @brief #MACSEC_GetBusIfc              */
#define BRCM_SWARCH_MACSEC_GET_HWID_PROC              (0x8101U) /**< @brief #MACSEC_GetHWId                */
#define BRCM_SWARCH_MACSEC_ENABLE_SYS_INTERRUPT       (0x8102U) /**< @brief #MACSEC_EnableSysInterrupt     */
#define BRCM_SWARCH_MACSEC_DISABLE_SYS_INTERRUPT      (0x8103U) /**< @brief #MACSEC_DisableSysInterrupt    */
#define BRCM_SWARCH_MACSEC_CLEAR_SYS_INTERRUPT        (0x8104U) /**< @brief #MACSEC_ClearSysInterrupt      */
#define BRCM_SWARCH_MACSEC_CONV_PORT2_CTX_IDX_PROC    (0x8105U) /**< @brief #MACSEC_ConvPort2CtxIdx        */
/** @} */

/**
    @brief MACSEC Get MACSec hardware id

    @note None

    @behavior Sync, Rentrant

    @pre None

    @param[in]      aPort       Switch Port number

    Return values are documented in reverse-chronological order
    @return     #MACSEC_HwIDType              MACSEC Hardware Id

    @post None

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE

    @limitations None
*/
MACSEC_HwIDType MACSEC_GetHWId(uint32_t aPort);

/**
    @brief MACSEC Get Bus Interface

    @note None

    @behavior Sync, Rentrant

    @pre None

    @param[in]      aPort       Switch Port number

    Return values are documented in reverse-chronological order
    @return     #SECY_BusType              MACSEC Bus interface

    @post None

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE

    @limitations None
*/
SECY_BusType MACSEC_GetBusIfc(uint32_t aPort);

/**
    @brief MACSEC Enable system (CPU) interrupt

    This API shall enable system side interrupt
    (MACSec interrupt connected to CPU subsystem).
    This API is called by the macsec driver during
    the initialization to enable the system side
    interrupt for the MACSec.

    @note None

    @behavior Sync, Rentrant

    @pre None

    @param[in]      aPort       Switch Port number

    Return values are documented in reverse-chronological order
    @return     void

    @post None

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE

    @limitations None
*/
void MACSEC_EnableSysInterrupt(uint32_t aPort);

/**
    @brief MACSEC disable system interrupt

    This API shall disable the MACSec system side
    interrupt.

    @note None

    @behavior Sync, Rentrant

    @pre None

    @param[in]      aPort       Switch Port number

    Return values are documented in reverse-chronological order
    @return     #SECY_BusType              MACSEC Bus interface

    @post None

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE

    @limitations None
*/
void MACSEC_DisableSysInterrupt(uint32_t aPort);

/**
    @brief MACSEC clear system interrupt

    This API shall clear the MACSec system side interrupt.

    @note None

    @behavior Sync, Rentrant

    @pre None

    @param[in]      aPort       Switch Port number

    Return values are documented in reverse-chronological order
    @return     #SECY_BusType              MACSEC Bus interface

    @post None

    @trace #BRCM_SWREQ_MACSEC_KERNEL_INTERFACE

    @limitations None
*/
void MACSEC_ClearSysInterrupt(uint32_t aPort);

/**
    @brief Get MACSEC context index from port number

    There are only needed number of context memory allocated.
    This function maps the port number to context memory index.

    @param[in]     aPortNum     Port Number

    @return     MACSEC Context Index corresponds to the port number

    @note

    @trace #BRCM_SWREQ_MACSEC_SECY_OPERATIONS

    @limitations None
*/
uint32_t MACSEC_ConvPort2CtxIdx(uint32_t aPortNum);

#endif /* MACSEC_PLAT_H */
/** @} */
