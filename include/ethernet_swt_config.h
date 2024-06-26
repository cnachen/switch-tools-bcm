/*****************************************************************************
 Copyright 2021-2022 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ethsrv_swt_ifc Ethernet switch: Config Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethsrv_swt_ifc
    @{

    @file ethswtm_config.h

    @brief Ethernet Service: Switch Interface Config
    This file contains the configuration interfaces for the Ethernet Service specific
    to Switch

    @version 0.1 Initial version
*/

#ifndef ETHSWTM_CFG_H
#define ETHSWTM_CFG_H

#include <ethernet_swt_common.h>
#include <ethernet_swt_arl.h>
#include <ethernet_swt_cfp.h>
#include <ethernet_swt_ext.h>
#include <ethernet_swt_vlan.h>
//#include <ethswt_debug.h>

/**
    @name Ethernet Service Switch API IDs
    @{
    @brief API IDs for Switch in Ethernet Service
*/
#define BRCM_SWARCH_ETHSWT_CONFIG_TYPE              (0x8401U)    /**< @brief #ETHSWT_ConfigType */
#define BRCM_SWARCH_ETHSWT_CONFIG_GLOBAL            (0x8402U)    /**< @brief #ETHSWT_Config     */
#define BRCM_SWARCH_ETHSWT_CONFIGV1_MAGIC_ID_MACRO  (0x8403U)    /**< @brief #ETHSWT_CONFIGV1_MAGIC_ID   */
#define BRCM_SWARCH_ETHSWT_CONFIGV2_MAGIC_ID_MACRO  (0x8404U)    /**< @brief #ETHSWT_CONFIGV2_MAGIC_ID   */
#define BRCM_SWARCH_ETHSWT_CONFIGV1_TYPE            (0x8405U)    /**< @brief #ETHSWT_ConfigV1Type */
#define BRCM_SWARCH_ETHSWT_CONFIGV2_TYPE            (0x8406U)    /**< @brief #ETHSWT_ConfigV2Type */
#define BRCM_SWARCH_ETHSWT_EXTCONFIG_TYPE           (0x8407U)    /**< @brief #ETHSWT_ExtConfigType   */
/** @} */

/**
    @brief Magic number for the configuration structure, containing 'COMM'

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CONFIGV1_MAGIC_ID                        (0x4D4D4F43UL)

/**
    @brief Magic number for the configuration structure, containing 'SWT2'

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CONFIGV2_MAGIC_ID                        (0x53575432UL)

/**
    @brief Switch Core Configuration Type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_ExtConfigType {
    ETHSWT_ExtPortConfigType   portCfgList[ETHSWT_EXT_MAX_PORTS];
                                                               /**< @brief Port configuration list */
    uint32_t                      portCfgListSz;           /**< @brief Number of ports */
    ETHSWT_GlobalSecurityCfgType  globalSecurityCfg;       /**< @brief  Security configuration  */
    ETHSWT_BrcmHdrModeType        brcmHdrMode;             /**< @brief IMP Broadcom header mode */
    ETHSWT_SwitchType             switchType;              /**< @brief Type of switch w.r.t to operation */
} ETHSWT_ExtConfigType;


/**
    @brief ETHSWTM Switch Configuration Type

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef struct COMP_PACKED sETHSWT_ConfigV1Type {
    uint32_t  magicId;                                       /**< @brief Magic number 'COMM' */
    ETHSWT_ExtConfigType extCfg;                            /**< @brief Extension Configuration */
    ETHSWT_VLANConfigV1Type vlanCfg;   /**< @brief VLAN Configuration */
    ETHSWT_ARLConfigV1Type arlCfg;     /**< @brief ARL Configuration */
    ETHSWT_CFPStreamPolicerConfigType streamPolicerCfg;     /**< @brief CFP Stream Policer Configuration */
} ETHSWT_ConfigV1Type;

/**
    @brief ETHSWTM Switch Configuration V2 Type

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef struct COMP_PACKED sETHSWT_ConfigV2Type {
    uint32_t  magicId;                                       /**< @brief Magic number 'SWT2' */
    ETHSWT_ExtConfigType extCfg;                            /**< @brief Extension Configuration */
    ETHSWT_VLANConfigV2Type vlanCfg;   /**< @brief VLAN Configuration */
    ETHSWT_ARLConfigV2Type arlCfg;     /**< @brief ARL Configuration */
    ETHSWT_CFPStreamPolicerConfigType streamPolicerCfg;     /**< @brief CFP Stream Policer Configuration */
} ETHSWT_ConfigV2Type;

/**
    @brief ETHSWTM Switch Configuration Type

    @trace #BRCM_SWREQ_ETHSWT
 */
typedef union uETHSWT_ConfigType {
    ETHSWT_ConfigV1Type cfgV1;
    ETHSWT_ConfigV2Type cfgV2;
} ETHSWT_ConfigType;

/**
    @brief Ethernet Service Switch configuration

    @trace #BRCM_SWREQ_ETHSWT
 */
extern ETHSWT_ConfigType ETHSWT_Config;

#endif /* ETHSWTM_CFG_H */

/** @} */
