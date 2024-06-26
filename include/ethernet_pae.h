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
    @defgroup grp_ethernet_pae_overview  Port Access Entity
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_pae_overview
    @{
    PAE allows the network administrator or system configurator to restrict the use
    of the IEEE 802 LAN service access points (ports) to secure communication with authenticated
    and authorized systems. Detailed operation of the PAE is fully described in IEEE spec
    802.1X-2020 Clause 12 (here on, where-ever word "specification" is used, it refers to
    IEEE spec 802.1X-2020 specification).

    PAE may operate MKA(MACsec key agreement) for a port authentication, based on the configuration.
    PAE may secure the link using the MACSec. This scope of this section is limited to only MKA based operation.

    PAE configuration consists of below entities
    -# Global configuration
    -# NID configuration
    -# Port Configurations (one per port)
    -# KaY Configuration (one per port, maps one to one with port configuration)
    -# MKA Participant configuration

    @image html ethernet_pae.png

    Global configuration enables system integrators to choose
    -# whether PAE operation is enabled or not (applicable to all ports
    -# MKA Protocol version to be used

    NID configuration enables system integrators to choose
    -# To enable MKA, MACSec and any Broadcom Specific modes of operation
    -# A Vendor specific mode when vendor mode is enabled
    -# NID Name
    -# controls over secure, authenticated and unauthenticated connections

    @note Note that NID Configuration may be used by multiple ports.

    Port configuration enables system integrators to choose to
    -# Enable Logon, MKA and Auto initialization
    -# Enable Point to Point mode
    -# NID Selection

    Each port has a corresponding KaY configuration, enabling system integrators to choose to
    -# Control MACSec desired parameter
    -# Actor priority
    -# MACSec Confidentialy offset
    -# Timeout and Retry count
    -# Hellotime and Lifetime for MKA operation

    MKA Participant configuration enables system integrators to choose to
    -# Select NID for this participant [All ports pointing to this NID can use this participant for MKA operation]
    -# CKN to be used for this participant

    @note When multiple MKA participants are pointing to a single NID, all ports
    associated with that port will sequentially attempt with different Participant entries.
    MKA Participant is ignored if the corresponding key is not found in the Crypto Key Store.

    Applicable configurations may be updated and Port initialization may be retriggered.
    Status and Statistics may be queries for diagnostic purposes.

    @file ethernet_pae.h
    @brief 802.1X Port Authentication entity interface
    This header file contains the interface functions for KaY

    @version 1.0 Initial Version
*/

#ifndef ETHERNET_PAE_H
#define ETHERNET_PAE_H

#include <bcm_comp.h>
#include <stdint.h>
#include <bcm_err.h>
#include <bcm_utils.h>
#include <crypto_secy.h>
#include <ethernet_pae_types.h>
#include <ethernet_pae_sync.h>


#endif /* ETHERNET_PAE_H */

/** @} */
