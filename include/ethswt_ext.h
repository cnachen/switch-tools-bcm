/*****************************************************************************
 Copyright 2017-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ethswt_ext_ifc Extensions Interface
    @ingroup grp_ethswt

    @addtogroup grp_ethswt_ext_ifc
    @{

    @file ethswt_ext.h
    @brief Application programmer interface for Ethernet Switch Driver (Misc)

    @version 0.51 Imported from docx
 */

#ifndef ETHSWT_EXT_H
#define ETHSWT_EXT_H

#include <compiler.h>
#include <ethswt_common.h>
#include <ethswt_vlan.h>
#include <ethernet_swt_ext.h>
#include <ethernet_swt_debug.h>

/**
    @name Ethernet Switch driver API IDs
    @{
    @brief API IDs for Ethernet Switch driver
*/
#define BRCM_SWARCH_ETHSWT_PORT_SHAPER_CONFIG_PROC         (0x8B00U)    /**< @brief #ETHSWT_PortShaperConfig       */
#define BRCM_SWARCH_ETHSWT_EXT_CONFIG_PROC                 (0x8B01U)    /**< @brief #ETHSWT_ExtConfigure           */
#define BRCM_SWARCH_ETHSWT_CFG_TYPE                        (0x8B02U)    /**< @brief #ETHSWT_CfgType                */
#define BRCM_SWARCH_ETHSWT_SETPORT_LINKCHANGE_EAPOL_PROC   (0x8B03U)    /**< @brief #ETHSWT_SetPortLinkChangeEAPOL */
#define BRCM_SWARCH_ETHSWT_SETPORT_EAPOL_PROC              (0x8B04U)    /**< @brief #ETHSWT_SetPortEAPOL           */
#define BRCM_SWARCH_ETHSWT_GETPORT_EAPOL_PROC              (0x8B05U)    /**< @brief #ETHSWT_GetPortEAPOL           */
#define BRCM_SWARCH_ETHSWT_SET_PORT_ENABLE_PROC            (0x8B06U)    /**< @brief #ETHSWT_SetPortEnable          */
#define BRCM_SWARCH_ETHSWT_GET_PORT_ENABLE_PROC            (0x8B07U)    /**< @brief #ETHSWT_GetPortEnable          */
/** @} */


/**
    @brief Ethernet switch configuration

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_CfgType {
    ETHSWT_PortCfgType  portCfgList[ETHSWT_PORT_ID_MAX];/**< @brief Configuration list for Switch ports */
    uint32_t            portCfgListSz;                  /**< @brief Size of the port configuration
                                                            list (portCfgList). */
    ETHSWT_GlobalSecurityCfgType globalSecurityCfg;     /**< @brief Security configuration across port */
    ETHSWT_BrcmHdrModeType brcmHdrMode;                 /**< @brief IMP Broadcom header mode */
    ETHSWT_SwitchType switchType;                       /**< @brief Type of switch w.r.t to operation */
} ETHSWT_CfgType;


/** @brief Configure Port Shaper

    This API configures the port shaper

    @behavior Sync, Re-entrant (for different switch index)

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aPortID     Port index
    @param[in]      aShaperCfg  Pointer to shaper configuration

    @return     void

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_EXT

    @limitations None
*/
void ETHSWT_PortShaperConfig(ETHSWT_HwIDType aSwtID,
                             ETHSWT_PortIDType aPortID,
                             const ETHSWT_ShaperCfgType *const aShaperCfg);

/** @brief Initliaze Ethernet switch driver

    This API initializes Ethernet switch driver with given configuration
    parameters.

    @behavior Sync, Re-entrant (for different switch index)

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aConfig     Pointer to switch configuration

    @return     void

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_EXT

    @limitations This API doesn’t perform reset of switch. Switch port are
    enabled by system before initialization of switch driver.
*/
void ETHSWT_ExtConfigure(ETHSWT_HwIDType aSwtID,
            const ETHSWT_CfgType *const aConfig);

/** @brief Helper to update the link state change

    @behavior Sync, Re-entrant (for different switch index)

    @pre Switch driver is initialized

    @param[in]      aSwtID                 Switch index
    @param[in]      aPortID                Switch Port Number

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_INVAL_PARAMS   aSwtID is Invalid or
    @retval     #BCM_ERR_OK             Port link change is updated

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EXT
*/
extern void ETHSWT_SetPortLinkChangeEAPOL(ETHSWT_HwIDType aSwtID, ETHSWT_PortIDType aPortID);

/** @brief Set EAP mode of a Port

    @behavior Sync, Re-entrant (for different switch index)

    @pre Switch driver is initialized

    @param[in]      aSwtID                 Switch index
    @param[in]      aPortID                Switch Port Number
    @param[in]      aEAPMode               EAP Port filtering mode
    @param[in]      aLinkChangeEAPmode     EAP blocking mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set port EAP mode
    @retval     #BCM_ERR_INVAL_PARAMS   aSwtID is Invalid or
                                        aPortID is Invalid or
                                        aEAPMode is invalid or
                                        aEAPBlockingMode is invalid
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION
*/
extern int32_t ETHSWT_SetPortEAPOL(ETHSWT_HwIDType aSwtID,
                                      ETHSWT_PortIDType aPortID,
                                      ETHSWT_ExtEAPBlockingModeType aEAPMode,
                                      ETHSWT_ExtEAPBlockingModeType aLinkChangeEAPmode);

/** @brief Get EAP mode of a Port

    @behavior Sync, Re-entrant (for different switch index)

    @pre Switch driver is initialized

    @param[in]      aSwtID                 Switch index
    @param[in]      aPortID                Switch Port Number
    @param[out]     aCurrEAPMode           Current EAP blocking mode
    @param[out]     aLinkChangeEAPmode     Link change EAP blocking mode config

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set port EAP mode
    @retval     #BCM_ERR_INVAL_PARAMS   aSwtID is Invalid or
                                        aPortID is Invalid or
                                        aCurrEAPMode is NULL or
                                        aLinkChangeEAPmode is NULL
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION
*/
extern int32_t ETHSWT_GetPortEAPOL(ETHSWT_HwIDType aSwtID,
                                      ETHSWT_PortIDType aPortID,
                                      ETHSWT_ExtEAPBlockingModeType *const aCurrEAPMode,
                                      ETHSWT_ExtEAPBlockingModeType *const aLinkChangeEAPmode);

/** @brief Set Port TX/RX enable (at MAC level)

    Enable/Disable TX/RX traffic for a port at MAC level

    @behavior Sync, Re-entrant (for different switch index)

    @pre Switch driver is initialized

    @param[in]      aSwtID       Switch index
    @param[in]      aPortID      Switch Port Number
    @param[in]      aDir         TX/RX direction to be enabled
    @param[in]      aEnable      BCM_BOOL_TRUE = Port tx enabled,
                                 BCM_BOOL_FALSE = Port tx disabled

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully enabled/disabled port TX
    @retval     #BCM_ERR_INVAL_PARAMS   aSwtID is Invalid or
                                        aPortID is Invalid or
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EXT
*/
int32_t ETHSWT_SetPortEnable(ETHSWT_HwIDType aSwtID,
                             ETHSWT_PortIDType aPortID,
                             ETHSWT_TrafficDirType aDir,
                             uint32_t aEnable);

/** @brief Get Port TX/RX (at MAC level) status

    @behavior Sync, Re-entrant (for different switch index)

    @pre Switch driver is initialized

    @param[in]      aSwtID       Switch index
    @param[in]      aPortID      Switch Port Number
    @param[in]      aDir         TX/RX direction to be read
    @param[out]     aEnable      TRUE = TX/RX enabled, FALSE = TX/RX disabled

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully fetched port TX status
    @retval     #BCM_ERR_INVAL_PARAMS   aSwtID is Invalid or
                                        aPortID is Invalid or
                                        aEnable is NULL
                                        aDir is ETHSWT_TRAFFICDIR_BIDIR or invalid
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_EXT
*/
int32_t ETHSWT_GetPortEnable(ETHSWT_HwIDType aSwtID,
                             ETHSWT_PortIDType aPortID,
                             ETHSWT_TrafficDirType aDir,
                             BCM_BoolType * const aEnable);
#endif /* ETHSWT_EXT_H */

/** @} */
