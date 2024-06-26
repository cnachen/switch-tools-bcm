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
    @defgroup grp_xcvr_common_tc10_ifc Ethernet XCVR TC10 Interface
    @ingroup grp_transceiver_abstract

    @addtogroup grp_xcvr_common_tc10_ifc
    @{

    @file xcvr_common_tc10.h

    @brief Ethernet XCVR TC10 Interface
    This file contains the interfaces for the Ethernet XCVR TC10 Module

    @version 1.0 Initial version
*/

#ifndef XCVR_COMMON_TC10_H
#define XCVR_COMMON_TC10_H

#include <string.h>
#include <bcm_err.h>
#include <bcm_utils.h>
#include <xcvr_common.h>
/**
    @name Ethernet XCVR API IDs
    @{
    @brief API IDs for Ethernet XCVR
*/
#define BRCM_SWARCH_ETHXCVR_TC10CONTEXT_GLOBAL           (0x8930U)  /**< @brief #ETHXCVR_TC10Context      */
#define BRCM_SWARCH_ETHXCVR_TC10CONTEXT_TYPE             (0x8931U)  /**< @brief #ETHXCVR_TC10ContextType       */
/** @} */

/**
    @brief TC10 Context Type containing the context of all ports

    @trace #BRCM_SWREQ_ETHXCVR_COMMON
*/
typedef struct sETHXCVR_TC10ContextType {
    uint32_t magic;                                                   /**< @brief Magic - 'TCTX'     */
    ETHXCVR_TC10PortContextType portContext[ETHXCVR_PHY_MAX_ENTRY]; /**< @brief TC10 port context  */
} ETHXCVR_TC10ContextType;

/**
    @brief Transceiver TC10 Context

    @trace #BRCM_SWREQ_ETHXCVR_COMMON
*/
extern ETHXCVR_TC10ContextType ETHXCVR_TC10Context;

#endif /* XCVR_COMMON_H */
/** @} */
