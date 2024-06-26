/*****************************************************************************
 Copyright 2020-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_xcvr_baset1drv_inf BASET1 Driver Interface
    @ingroup grp_xcvr_baset1drv

    @addtogroup grp_xcvr_baset1drv_inf
    @{

    @file baset1_phy.h
*/

#ifndef BASET1_PHY_H
#define BASET1_PHY_H

#include <xcvr_common.h>
#include <xcvr_extphy.h>
/**
    @name BRPHY API IDs
    @{
    @brief API IDs for BRPHY driver
*/
#define BRCM_SWARCH_BASET1PHY_DEVADDR_TYPE                              (0x8000U) /**< @brief #BASET1PHY_DevAddrType          */
#define BRCM_SWARCH_BASET1PHY_MASTER_SLAVE_CFG_TYPE                     (0x8001U) /**< @brief #BASET1PHY_MasterSlaveCfgType   */
#define BRCM_SWARCH_BASET1PHY_REG_READ_PROC                             (0x8002U) /**< @brief #BASET1PHY_RegRead              */
#define BRCM_SWARCH_BASET1PHY_REG_WRITE_PROC                            (0x8003U) /**< @brief #BASET1PHY_RegWrite             */
#define BRCM_SWARCH_BASET1PHY_GET_ID_PROC                               (0x8004U) /**< @brief #BASET1PHY_GetID                */
#define BRCM_SWARCH_BASET1PHY_RESET_PHY_PROC                            (0x8005U) /**< @brief #BASET1PHY_ResetPHY             */
#define BRCM_SWARCH_BASET1PHY_SET_LPM_PROC                              (0x8006U) /**< @brief #BASET1PHY_SetLpm               */
#define BRCM_SWARCH_BASET1PHY_GET_LPM_PROC                              (0x8007U) /**< @brief #BASET1PHY_GetLpm               */
#define BRCM_SWARCH_BASET1PHY_AUTO_NEG_CONFIG_PROC                      (0x8008U) /**< @brief #BASET1PHY_AutoNegConfig        */
#define BRCM_SWARCH_BASET1PHY_FORCED_CONFIG_PROC                        (0x8009U) /**< @brief #BASET1PHY_ForcedConfig         */
#define BRCM_SWARCH_BASET1PHY_SET_LOOPBACK_MODE_PROC                    (0x800AU) /**< @brief #BASET1PHY_SetLoopbackMode      */
#define BRCM_SWARCH_BASET1PHY_GET_LOOPBACK_MODE_PROC                    (0x800BU) /**< @brief #BASET1PHY_GetLoopbackMode      */
#define BRCM_SWARCH_BASET1PHY_GET_LINK_STATE_PROC                       (0x800CU) /**< @brief #BASET1PHY_GetLinkState         */
#define BRCM_SWARCH_BASET1PHY_RE_START_AUTO_NEG_PROC                    (0x800DU) /**< @brief #BASET1PHY_ReStartAutoNeg       */
#define BRCM_SWARCH_BASET1PHY_GET_AUTO_NEG_STATUS_PROC                  (0x800EU) /**< @brief #BASET1PHY_GetAutoNegStatus     */
/** @} */

/**
    @brief CL45 port addresses

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER
*/
typedef uint8_t BASET1PHY_DevAddrType;
#define BASET1PHY_DEVADDR_PMAPMD                     (1U)
#define BASET1PHY_DEVADDR_PCS                        (3U)
#define BASET1PHY_DEVADDR_AN                         (7U)
#define BASET1PHY_DEVADDR_MISC                       (30U)

/**
    @brief Master/slave configuration for Auto-neg mode

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER
*/
typedef uint32_t BASET1PHY_MasterSlaveCfgType;
#define BASET1PHY_MASTER_SLAVE_CFG_MASTER_FORCED      (1UL)
#define BASET1PHY_MASTER_SLAVE_CFG_SLAVE_FORCED       (2UL)
#define BASET1PHY_MASTER_SLAVE_CFG_MASTER_PREFERRED   (3UL)
#define BASET1PHY_MASTER_SLAVE_CFG_SLAVE_PREFERRED    (4UL)

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_RegRead(BCM_HandleType aConnHdl, uint32_t aAddr, uint32_t *const aData);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_RegWrite(BCM_HandleType aConnHdl, uint32_t aAddr, uint32_t aData);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_GetID(BCM_HandleType aConnHdl, ETHXCVR_PhyIDType *const aPhyID);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_ResetPHY(BCM_HandleType aConnHdl);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_SetLpm(BCM_HandleType aConnHdl, ETHXCVR_BooleanType aSet);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_GetLpm(BCM_HandleType aConnHdl, uint32_t *const aTrue);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_AutoNegConfig(BCM_HandleType aConnHdl, BASET1PHY_MasterSlaveCfgType aCfg, ETHXCVR_SpeedType aSpeed);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_ForcedConfig(BCM_HandleType aConnHdl, BCM_BoolType aMaster, ETHXCVR_SpeedType aSpeed);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_SetLoopbackMode(BCM_HandleType aConnHdl, ETHXCVR_LoopbackModeType aMode);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_GetLoopbackMode(BCM_HandleType aConnHdl,
                                         ETHXCVR_LoopbackModeType *const aLpMode);
/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_GetLinkState(BCM_HandleType aConnHdl, ETHXCVR_LinkStateType *const aState);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_ReStartAutoNeg(BCM_HandleType aConnHdl);

/**
    @brief

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_BASET1PHY_DRIVER

    @limitations None
*/
extern int32_t BASET1PHY_GetAutoNegStatus(BCM_HandleType aConnHdl, ETHXCVR_ExtPhyAutoNegStatusType *const aStatus);
#endif /* BASET1_PHY_H */

/** @} */
