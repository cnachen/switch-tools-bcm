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
    @defgroup grp_ethernet_pae_sync Sync API
    @ingroup grp_ethernet_pae_overview

    @addtogroup grp_ethernet_pae_sync
    @{

    @file ethernet_pae_sync.h
    @brief 802.1X Port Authentication entity Synchronous interface

    @version 1.0 Initial Version
*/

#ifndef ETHERNET_PAE_SYNC_H
#define ETHERNET_PAE_SYNC_H

#include <bcm_comp.h>
#include <stdint.h>
#include <bcm_err.h>
#include <bcm_utils.h>
#include <crypto_secy.h>

/**
    @name PAE Architecture IDs
    @{
    @brief Architecture IDs for 802.1X PAE
*/
#define BRCM_SWARCH_PAE_ENABLE_PROC                 (0x8200U) /**< @brief #PAE_Enable           */
#define BRCM_SWARCH_PAE_DISABLE_PROC                (0x8201U) /**< @brief #PAE_Disable          */

#define BRCM_SWARCH_PAE_SET_NID_CFG_PROC            (0x8210U) /**< @brief #PAE_SetNidCfg        */
#define BRCM_SWARCH_PAE_GET_NID_CFG_PROC            (0x8211U) /**< @brief #PAE_GetNidCfg        */

#define BRCM_SWARCH_PAE_SET_PORT_CFG_PROC           (0x8220U) /**< @brief #PAE_SetPortCfg       */
#define BRCM_SWARCH_PAE_GET_PORT_STATUS_PROC        (0x8221U) /**< @brief #PAE_GetPortStatus    */
#define BRCM_SWARCH_PAE_GET_PORT_STATS_PROC         (0x8222U) /**< @brief #PAE_GetPortStats     */
#define BRCM_SWARCH_PAE_SET_PN_EXFAUSTION_PROC      (0x8223U) /**< @brief #PAE_SetPNExhaustion  */

#define BRCM_SWARCH_PAE_SET_MKA_PART_CFG_PROC       (0x8230U) /**< @brief #PAE_SetMkaPartCfg    */
#define BRCM_SWARCH_PAE_GET_MKA_PART_STATUS_PROC    (0x8231U) /**< @brief #PAE_GetMkaPartStatus */

/** @} */


/**
    @brief Enable PAE System

    This API enables PAE system with the set configurations. This performs
    operation as described by 802.1X MIB ieee8021XPaeSysAccessControl being set to True.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_NOSUPPORT      Command not supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_Enable(BCM_HandleType aConnHdl);

/**
    @brief Disable PAE System

    This API disables PAE system with the set configurations. This performs
    operation as described by 802.1X MIB ieee8021XPaeSysAccessControl being set to False.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl           Connection handle (from RPC_Connect)

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Integration fault
    @retval     #BCM_ERR_NOSUPPORT      Command not supported
    @retval     #BCM_ERR_INVAL_PARAMS   aConnHdl is invalid

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_Disable(BCM_HandleType aConnHdl);

/**
    @brief Set Network Identifier Configuration for the given index

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (example,from RPC_Connect)
    @param[in]      aNidIdx         Network Identifier index
    @param[in]      aNidCfg         NID configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_NOPERM             Permission denied (NID is currently in use)
    @return     #BCM_ERR_NOMEM              aNidIdx is not in range
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aNidCfg is NULL

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_SetNidCfg(BCM_HandleType aConnHdl, uint32_t aNidIdx, const PAE_NidCfgType *const aNidCfg);

/**
    @brief Get Network Identifier Configuration

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (example,from RPC_Connect)
    @param[in]      aNidIdx         Network Identifier index
    @param[out]     aNidCfg         NID configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_NOT_FOUND          No configuration found at aNidIdx
    @return     #BCM_ERR_NOMEM              aNidIdx is not in range
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aNidCfg is NULL

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_GetNidCfg(BCM_HandleType aConnHdl, uint32_t aNidIdx, PAE_NidCfgType *const aNidCfg);

/**
    @brief Set Port configuration

    Sets the port configuration for the given port.

    If #PAE_PORT_ENABLE_AUTO_INIT is set in enabled features (in aPortCfg->enabled),
    and System Access Control is set to true previously, this API performs port initialization
    as described in 802.1X Section 12.9.3.

    If #PAE_PORT_ENABLE_AUTO_INIT is not set,or System Access Control is set to false previously,
    this API preserves the configuration for future use.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (example,from RPC_Connect)
    @param[in]      aPortNum        Port Number
    @param[in]      aPortCfg        Port Configuration
    @param[in]      aKayCfg         KaY Configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOMEM              aPortNum is not in range
    @return     #BCM_ERR_NOPERM             Permission denied
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aPortCfg is NULL
                                            or aKayCfg is NULL

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_SetPortCfg(BCM_HandleType aConnHdl, PAE_PortNumberType aPortNum,
                            const PAE_PortCfgType *const aPortCfg, const PAE_KayCfgType* const aKayCfg);

/**
    @brief Set PN Exhaustion

    Sets the PN Exhaustion for the given port.

    If Lowest Acceptable PN (LLPN) is equal to exceeds the #aPNExhaustion. The Key Server
    shall distribute the fresh SAK as described in 802.1X Section 9.8.

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (example,from RPC_Connect)
    @param[in]      aPortNum        Port Number
    @param[in]      aPNExhaustion   PN Exhaustion Number


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOMEM              aPortNum is not in range
    @return     #BCM_ERR_NOPERM             Permission denied
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aPNExhaustion is invalid

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_SetPNExhaustion(BCM_HandleType aConnHdl, PAE_PortNumberType aPortNum,
                                                            const uint64_t aPNExhaustion);
/**
    @brief Get Port Status

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (example,from RPC_Connect)
    @param[in]      aPortNum        Port Number
    @param[out]     aPortStatus     Port Status
    @param[out]     aKayStatus      KaY Status


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOMEM              aPortNum is not in range
    @return     #BCM_ERR_NOPERM             Permission denied
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aPortStatus is NULL
                                            or aKayStatus is NULL

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_GetPortStatus(BCM_HandleType aConnHdl, PAE_PortNumberType aPortNum,
                        PAE_PortStatusType *const aPortStatus, PAE_KayStatusType* const aKayStatus);

/**
    @brief Get Port Session Stats

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl            Connection handle (example,from RPC_Connect)
    @param[in]      aPortNum            Port Number
    @param[out]     aPortSessionStats   Port Stats


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOMEM              aPortNum is not in range
    @return     #BCM_ERR_NOPERM             Permission denied
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aPortSessionStats is NULL

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_GetPortStats(BCM_HandleType aConnHdl, PAE_PortNumberType aPortNum,
                        PAE_PortSessionStatsType *const aPortSessionStats);

/**
    @brief Set/Add MKA Participant

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (example,from RPC_Connect)
    @param[in]      aMkaPartIdx     MKA Participant index
    @param[in]      aMkaPartCfg     MKA Participant configuration


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOMEM              aMkaPartIdx is not in range
    @return     #BCM_ERR_NOPERM             Permission denied (MKA Participant in use)
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aMkaPartCfg is NULL

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_SetMkaPartCfg(BCM_HandleType aConnHdl, uint32_t aMkaPartIdx,
                                const PAE_MkaPartCfgType *const aMkaPartCfg);


/**
    @brief Get MKA Participant Status

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aConnHdl        Connection handle (example,from RPC_Connect)
    @param[in]      aPortNum        Port Number
    @param[in]      aMkaPartIdx     MKA Participant Index
    @param[in]      aInNumPeers     Maximum number of peers that can be filled into aPeers
    @param[out]     aCkn            CAK Name
    @param[out]     aCknLen         CAK Name Length
    @param[out]     aMkaPartStatus  MKA Participant Status
    @param[out]     aOutNumPeers    Number of Filled peers
    @param[out]     aPeers          Peers


    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Success
    @return     #BCM_ERR_UNKNOWN            Integration error
    @return     #BCM_ERR_NOT_FOUND          Not matching CKN found.
    @return     #BCM_ERR_NOMEM              aPortNum is not in range
    @return     #BCM_ERR_NOPERM             Permission denied
    @return     #BCM_ERR_NOSUPPORT          Command not supported
    @return     #BCM_ERR_INVAL_PARAMS       aConnHdl is invalid
                                            or aMkaPartStatus is NULL

    @post None

    @trace #BRCM_SWREQ_PAE

    @limitations None
*/
extern int32_t PAE_GetMkaPartStatus(BCM_HandleType aConnHdl, PAE_PortNumberType aPortNum,
                                    uint32_t aMkaPartIdx, uint32_t aInNumPeers,
                                    uint32_t *aCknLen, uint8_t * const aCkn,
                                    PAE_MkaPartStatusType *const aMkaPartStatus,
                                    uint32_t *aOutNumPeers, PAE_MkaPeerEntryType * aPeers);



#endif /* ETHERNET_PAE_SYNC_H */

/** @} */
