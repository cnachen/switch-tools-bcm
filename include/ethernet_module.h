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

/** @defgroup grp_ethernet_abstract_module_ifc Ethernet Abstract Module Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_abstract_module_ifc
    @{

    @file ethernet_module.h
    @brief Ethernet Abstract Module Interface

    @version 1.0 Initial version
*/

#ifndef ETHERNET_MODULE_H
#define ETHERNET_MODULE_H

#include <module.h>

/**
    @name Ethernet Abstract Module Interface IDs
    @{
    @brief Integration Interface IDs for Ethernet Abstract Modules
*/
#define BRCM_SWARCH_ETHERNET_SERVICE_GLOBAL    (0x8F01U) /**< @brief #ETHERNET_Service   */
#define BRCM_SWARCH_NIF_CNTRLRMODULE_GLOBAL    (0x8F02U) /**< @brief #NIF_CntrlrModule   */
#define BRCM_SWARCH_INET_MODULE_GLOBAL         (0x8F03U) /**< @brief #INET_Module        */
#define BRCM_SWARCH_ETHXCVRM_MODULE_GLOBAL     (0x8F04U) /**< @brief #ETHXCVRM_Module    */
#define BRCM_SWARCH_ETTM_MODULE_GLOBAL         (0x8F05U) /**< @brief #ETTM_Module        */
#define BRCM_SWARCH_ETHSWTM_FAMODULE_GLOBAL    (0x8F06U) /**< @brief #ETHSWTM_FAModule   */
#define BRCM_SWARCH_ETSM_MODULE_GLOBAL         (0x8F07U) /**< @brief #ETSM_Module        */
#define BRCM_SWARCH_TFTP_MODULE_GLOBAL         (0x8F08U) /**< @brief #TFTP_Module        */


/** @} */

/**
    @brief Ethernet Service
    @trace #BRCM_SWREQ_ETHERNET
*/
extern const SERVICE_Type ETHERNET_Service;

/**
    @brief Function pointer for NIF Controller and NIF module

    @trace #BRCM_SWREQ_NIF
 */
extern const MODULE_Type NIF_CntrlrModule;

/**
    @brief Function pointers for the INET module

    @trace #BRCM_SWREQ_INET
 */
extern const MODULE_Type INET_Module;

/**
    @brief Function pointers for the TFTP module

    @trace #BRCM_SWREQ_TFTP
 */
extern const MODULE_Type TFTP_Module;

/**
    @brief Function pointer for ETHSRV ethernet transceiver module

    @trace #BRCM_SWREQ_ETHXCVRM
 */
extern const MODULE_Type ETHXCVRM_Module;

/**
    @brief Function pointer for ETHSRV ethernet time module

    @trace #BRCM_SWREQ_ETTM
 */
extern const MODULE_Type ETTM_Module;

/**
    @brief Function pointer table for ETHSWTM FA module

    @trace #BRCM_SWREQ_ETHSWTM
 */
extern const MODULE_Type ETHSWTM_FAModule;

/**
    @brief Function pointer table for ETS module

    @trace #BRCM_SWREQ_ETSM
 */
extern const MODULE_Type ETSM_Module;

#endif /* ETHERNET_MODULE_H */
/** @} */
