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
    @defgroup grp_l3fdrv_ifc L3Forward Interface
    @ingroup grp_l3fdrv

    @addtogroup grp_l3fdrv_ifc
    @{

    @file l3fdrv.h

    @brief Interface for L3 Forward interface
    This file provides the interface/APIs which can be used to initialize,
    configure and add/remove rules to/from the L3 Forward block.

    @version 0.1 Initial version
*/

#ifndef L3FDRV_H
#define L3FDRV_H

#include <stdint.h>
#include <bcm_utils.h>
#include <ethernet_l3fw.h>

/**
    @name L3Forward Driver Architecture IDs
    @{
    @brief Architecture IDs for L3Forward Driver
*/
#define BRCM_SWARCH_L3FDRV_INIT_PROC                            (0x8000U) /**< @brief #L3FDRV_Init                    */
#define BRCM_SWARCH_L3FDRV_ADD_INTERFACE_PROC                   (0x8001U) /**< @brief #L3FDRV_AddInterface            */
#define BRCM_SWARCH_L3FDRV_REMOVE_INTERFACE_PROC                (0x8002U) /**< @brief #L3FDRV_RemoveInterface         */
#define BRCM_SWARCH_L3FDRV_GET_INTERFACE_INFO_PROC              (0x8003U) /**< @brief #L3FDRV_GetInterfaceInfo        */
#define BRCM_SWARCH_L3FDRV_ADD_UNICAST_ROUTE_PROC               (0x8004U) /**< @brief #L3FDRV_AddUnicastRoute         */
#define BRCM_SWARCH_L3FDRV_REMOVE_UNICAST_ROUTE_PROC            (0x8005U) /**< @brief #L3FDRV_RemoveUnicastRoute      */
#define BRCM_SWARCH_L3FDRV_ADD_MULTICAST_GRP_PROC               (0x8006U) /**< @brief #L3FDRV_AddMulticastGrp         */
#define BRCM_SWARCH_L3FDRV_REMOVE_MULTICAST_GRP_PROC            (0x8007U) /**< @brief #L3FDRV_RemoveMulticastGrp      */
#define BRCM_SWARCH_L3FDRV_ADD_MULTICAST_IFC_PROC               (0x8008U) /**< @brief #L3FDRV_AddMulticastIfc         */
#define BRCM_SWARCH_L3FDRV_REMOVE_MULTICAST_IFC_PROC            (0x8009U) /**< @brief #L3FDRV_RemoveMulticastIfc      */
#define BRCM_SWARCH_L3FDRV_SET_MULTICAST_L2PORTS_PROC           (0x800AU) /**< @brief #L3FDRV_SetMulticastL2Ports     */
#define BRCM_SWARCH_L3FDRV_DEINIT_PROC                          (0x800BU) /**< @brief #L3FDRV_Deinit                  */
#define BRCM_SWARCH_L3FDRV_GET_UNICAST_ROUTE_PROC               (0x800CU) /**< @brief #L3FDRV_GetUnicastRoute         */
/** @} */

/** @brief Initialize L3Forward HW and the driver

    @behavior Sync, Re-entrant

    @pre None

    @retval  #BCM_ERR_OK           Initialization successful
    @retval  #BCM_ERR_INVAL_STATE  Driver already initialized

    @post L2F HW and driver initialized

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_Init(void);

/**
    @brief Add L3 Interface

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aIfcCfg      Interface config
    @param[out]    aIfcId       Handle to the interface

    @retval  #BCM_ERR_OK            Interface added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_NOPERM        Given aIfcCfg.port, aIfcCfg.vlanid combination
                                    already present
    @retval  #BCM_ERR_NOMEM         Max interface limit reached
    @retval  #BCM_ERR_INVAL_PARAMS  aIfcCfg.port/aIfcCfg.vlanid is invalid or
                                    aIfcId is NULL or aIfcCfg is NULL or
                                    aIFcCfg.macAddr is not a unicast address

    @post None

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_AddInterface(L3FW_InterfaceCfgType const * const aIfcCfg,
                            L3FW_InterfaceIdType * const aIfcId);

/**
    @brief Remove L3 Interface

    Remove an L3 interface added by L3FW_AddInterface().

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aIfcId   Handle to the interface

    @retval  #BCM_ERR_OK               Interface removed successfully
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS     aIfcId is invalid

    @post None

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_RemoveInterface(L3FW_InterfaceIdType aIfcId);

/**
    @brief Get L3 Interface info

    Get an L3 interface info added by L3FW_AddInterface().

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]    aIfcId       Interface id
    @param[out]   aIfcInfo     Interface information

    @retval  #BCM_ERR_OK               Interface removed successfully
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS     aIfcId is invalid or aIfcInfo is NULL

    @post None

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_GetInterfaceInfo(L3FW_InterfaceIdType aIfcId,
                                L3FW_InterfaceCfgType * const aIfcInfo);

/**
    @brief Add L3 Unicast Route

    This API is used for creating a new unicast route

    @behavior Sync, Non-Reentrant

    @pre One or more interfaces are defined

    @param[in]     aRouteCfg   Unicast route config

    @retval  #BCM_ERR_OK            Unicast route added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_NOMEM         aRouteCfg.routeId is more than max unicast route limit
    @retval  #BCM_ERR_NOPERM        aRouteCfg.routeId is already configured.
                                    Need to #L3FW_RemoveUnicastRoute()
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg.dmac is not a unicast address
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg.ipAddr or aRouteCfg.netMaskPrefix is invalid
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg.ifcId is invalid
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg is NULL

    @post New unicast route is added with given configuration

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_AddUnicastRoute(L3FW_UnicastRouteCfgType const * const aRouteCfg);

/**
    @brief Get L3 Unicast Route

    This API is used for reading an existing unicast route

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aRouteId    Unicast route id. Returned by #L3FDRV_AddUnicastRoute()
    @param[out]    aRouteCfg   Unicast route config

    @retval  #BCM_ERR_OK            Unicast route fetched successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_NOPERM        aRouteCfg.routeId is not configured
    @retval  #BCM_ERR_INVAL_PARAMS  aRouteCfg is NULL

    @post None

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_GetUnicastRoute(L3FW_UnicastRouteIdType aRouteId,
                               L3FW_UnicastRouteCfgType * const aRouteCfg);

/**
    @brief Remove L3 Unicast route.

    This API is used for removing / invalidating the already configured
    unicast route (ipv4 or ipv6)

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aRouteHdl   Unicast route handle. Returned by #L3FW_AddUnicastRoute()

    @retval  #BCM_ERR_OK               Unicast route removed successfully
    @retval  #BCM_ERR_TIME_OUT         HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS     aRouteHdl is invalid

    @post Given unicast route is removed

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_RemoveUnicastRoute(L3FW_UnicastRouteIdType aRouteId);

/**
    @brief Add L3 multicast group

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aMcGrpId  Multicast group rule id

    @retval  #BCM_ERR_OK            Multicast group added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_NOMEM         Max multicast group limit reached
    @retval  #BCM_ERR_NOPERM        Multicast group already added

    @post Given multicast group is created

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_AddMulticastGrp(uint32_t aMcGrpId);

/**
    @brief Remove the existing L3 multicast group

    @behavior Sync, Non-Reentrant

    @pre None

    @param[in]     aMcGrpId  Multicast group id

    @retval  #BCM_ERR_OK            Multicast group removed successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpId is not present

    @post Given multicast group is removed

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_RemoveMulticastGrp(uint32_t aMcGrpId);

/**
    @brief Add the interface to the multicast group

    @behavior Sync, Non-Reentrant

    @pre Multicast group is configured correctly

    @param[in]    aMcGrpHdl Multicast group handle
    @param[in]    aIfcId   Output interface to be subscribed

    @retval  #BCM_ERR_OK            Interface is subscribed to the multicast successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpHdl or aIfcId is invalid

    @post Given interface is added to the multicast group

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_AddMulticastIfc(uint32_t aMcGrpId,
                               L3FW_InterfaceIdType aIfcId);

/**
    @brief Remove the interface from the multicast group

    @behavior Sync, Non-Reentrant

    @pre Multicast group is configured correctly and the
         interface is subscribed.

    @param[in]    aMcGrpHdl  Multicast group handle
    @param[in]    aIfcId    Output interface to be unsubscribed

    @retval  #BCM_ERR_OK            Unsubscribed from multicast
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpHdl or aIfcId is invalid

    @post Given interface is unsubscribed from the multicast group

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_RemoveMulticastIfc(uint32_t aMcGrpId,
                                  L3FW_InterfaceIdType aIfcId);

/**
    @brief Set L2 forwarding port masks to multicast group

    @behavior Sync, Non-Reentrant

    @pre Multicast group is configured correctly

    @param[in]    aMcGrpHdl  Multicast group handle
    @param[in]    aPortMask  Port list in bitmask format

    @retval  #BCM_ERR_OK            Ports added successfully
    @retval  #BCM_ERR_TIME_OUT      HW Access timed out
    @retval  #BCM_ERR_INVAL_PARAMS  aMcGrpHdl is invalid
    @retval  #BCM_ERR_INVAL_PARAMS  aPortMask is invalid (port mask bits out of range)

    @post Given port mask is setup for L2 forwarding

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_SetMulticastL2Ports(uint32_t aMcGrpId,
                                   uint64_t aPortMask);

/** @brief Deinitialize L3Forward HW and the driver

    @behavior Sync, Re-entrant

    @pre Driver initialized

    @retval  #BCM_ERR_OK           Deinit successful
    @retval  #BCM_ERR_UNINIT       Driver not initialized

    @post L2F HW and driver Deinitialized

    @trace #BRCM_SWREQ_L3FDRV

    @limitations None
*/
int32_t L3FDRV_Deinit(void);

#endif /* L3FDRV_H */

/** @} */
