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

/** @defgroup grp_rpc_v2_net_intf_il NET Interface Integration Guide
    @ingroup grp_rpc_v2_mod

    @addtogroup grp_rpc_v2_net_intf_il
    @{

    @file rpc_net_osil.h
    @brief DISPATCH NET Intferface Integration Interfaces
    This header file contains the integration interface for DISPATCH NET Slave
    and NET Master modules

    @version 1.0 Initial Version
*/

#ifndef DISPATCH_INET_H
#define DISPATCH_INET_H

#include <stdint.h>
#include <inet_cfg.h>
#include <socket.h>

/**
    @name DISPATCH Integration Interface IDs
    @{
    @brief Integration Interface IDs for DISPATCH NET Interface

*/
#define BRCM_SWARCH_DISPATCH_TCPSERVERLISTENER_GLOBAL           (0x9301U)    /**< @brief #DISPATCH_TCPServerListener */
#define BRCM_SWARCH_DISPATCH_TCPSERVERCONN0_GLOBAL              (0x9302U)    /**< @brief #DISPATCH_TCPServerConn0 */
#define BRCM_SWARCH_DISPATCH_TCPCLIENT_GLOBAL                   (0x9303U)    /**< @brief #DISPATCH_TCPClient */
#define BRCM_SWARCH_DISPATCH_NOTIFCLIENT0_GLOBAL                (0x9304U)    /**< @brief #DISPATCH_NotifClient0 */
#define BRCM_SWARCH_DISPATCH_NOTIFCLIENT1_GLOBAL                (0x9305U)    /**< @brief #DISPATCH_NotifClient1 */
#define BRCM_SWARCH_DISPATCH_FUNNELSERVERCONN_GLOBAL            (0x9307U)    /**< @brief #DISPATCH_FunnelServerConn */
#define BRCM_SWARCH_DISPATCH_FUNNELSERVERLISTENER_GLOBAL        (0x9306U)    /**< @brief #DISPATCH_FunnelServerListener */
#define BRCM_SWARCH_DISPATCH_TCPSERVERCONN1_GLOBAL              (0x9307U)    /**< @brief #DISPATCH_TCPServerConn1 */
#define BRCM_SWARCH_DISPATCH_TCPSERVERCONN2_GLOBAL              (0x9308U)    /**< @brief #DISPATCH_TCPServerConn2 */
#define BRCM_SWARCH_DISPATCH_TCPSERVERCONN3_GLOBAL              (0x9309U)    /**< @brief #DISPATCH_TCPServerConn3 */
#define BRCM_SWARCH_DISPATCH_TCPFILECLIENT_GLOBAL               (0x930AU)    /**< @brief #DISPATCH_TCPFileClient */
/** @} */

/**
    @brief TCP server listener end point

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
extern INET_SystemEndPointType const DISPATCH_TCPServerListener;

/**
    @brief TCP server connection end point

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
#if (DISPATCH_TCP_MAX_CLIENT_COUNT > 0UL)
extern INET_SystemEndPointType const DISPATCH_TCPServerConn0;
#endif

/**
    @brief TCP server connection end point

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
#if (DISPATCH_TCP_MAX_CLIENT_COUNT > 1UL)
extern INET_SystemEndPointType const DISPATCH_TCPServerConn1;
#endif

/**
    @brief TCP server listener end point

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
extern INET_SystemEndPointType const DISPATCH_TCPProxyServerListener;

/**
    @brief TCP server connection end point

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
#if (DISPATCH_TCP_MAX_CLIENT_COUNT > 0UL)
extern INET_SystemEndPointType const DISPATCH_TCPProxyServerConn0;
#endif

/**
    @brief TCP server connection end point

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
#if (DISPATCH_TCP_MAX_CLIENT_COUNT > 1UL)
extern INET_SystemEndPointType const DISPATCH_TCPProxyServerConn1;
#endif

/**
    @brief TCP client end point

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
extern INET_SystemEndPointType const DISPATCH_TCPClient;

/**
    @brief Dispatch notification client end point 0

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
extern INET_SystemEndPointType const DISPATCH_NotifClient0;

/**
    @brief Dispatch notification client end point 1

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
extern INET_SystemEndPointType const DISPATCH_NotifClient1;

/**
    @brief Dispatch Funnel server (used on MCM)

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
extern INET_SystemEndPointType const DISPATCH_FunnelServerListener;

/**
    @brief Dispatch Funnel server connection end point (used on MCM)

    @trace #BRCM_SWREQ_DISPATCH_IFC_NET
*/
extern INET_SystemEndPointType const DISPATCH_FunnelServerConn;

#endif /* DISPATCH_INET_H */
/** @} */
