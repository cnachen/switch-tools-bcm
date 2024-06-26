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

/**
    @defgroup grp_ets_api_ifc API Interface
    @ingroup grp_ets

    @addtogroup grp_ets_api_ifc
    @{

    @file ets_api.h

    @brief ETS API Interface
    This file contains the interfaces for the ETS

    @version 1.0 Initial version
*/

#ifndef ETS_API_H
#define ETS_API_H

#include <bcm_comp.h>

/**
    @name ETS API IDs
    @{
    @brief API IDs for ETS
*/
#define BRCM_SWARCH_ETS_GETDOMAINNUMSTATUSV2_PROC      (0x8101U) /**< @brief #ETS_GetDomainNumStatusV2      */
#define BRCM_SWARCH_ETS_GETPORTNUMSTATUS_PROC          (0x8102U) /**< @brief #ETS_GetPortNumStatus          */
#define BRCM_SWARCH_ETS_GETDOMAINNUMPORTSTATUSV2_PROC  (0x8103U) /**< @brief #ETS_GetDomainNumPortStatusV2  */
/** @} */

/** @brief Retrieve domain status (Updated)

    @pre None

    @behavior Sync, Re-entrant

    @param[in]   aConnHdl             Connection handle (from RPC_Connect)
    @param[in]   aDomainNum           Domain number to retrieve status
    @param[out]  aDomainStatus        Pointer to retrieve the status of #aDomainNum

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK              Status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS    aDomainStatus is NULL
    @retval  #BCM_ERR_NOT_FOUND       aDomainNum is invalid

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS
*/
extern int32_t ETS_GetDomainNumStatusV2(BCM_HandleType aConnHdl,
                                   const ETS_DomainType aDomainNum,
                                   ETS_DomainStatusV2Type* const aDomainStatus);

/** @brief Retrieve ETS Port status

    @pre None

    @behavior Sync, Re-entrant

    @param[in]   aConnHdl             Connection handle (from RPC_Connect)
    @param[in]   aPortNum             Port number
    @param[out]  aPortStatus          Pointer to retrieve the Port status

    Return values are documented in reverse-chronological order
    @retval  #BCM_ERR_OK              Status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS    aStatus is NULL
    @retval  #BCM_ERR_NOT_FOUND       aPortNum is invalid


    @post None

    @limitations The PDelay timestamps might be reported as 0 when
    the port is in the middle of a ongoing transaction

    @trace #BRCM_SWREQ_ETS
*/
extern int32_t ETS_GetPortNumStatus(BCM_HandleType aConnHdl,
                                 const uint32_t aPortNum,
                                 ETS_PortStatusType* const aPortStatus);

/** @brief Retrieve Port and Domain status (Updated)

    @pre None

    @behavior Sync, Re-entrant

    @param[in]   aConnHdl             Connection handle (from RPC_Connect)
    @param[in]   aDomainNum           Domain number
    @param[in]   aPortNum             Port number
    @param[out]  aStatus              Pointer to retrieve the status

    @retval  #BCM_ERR_OK              Status retrieved successfully
    @retval  #BCM_ERR_INVAL_PARAMS    aStatus is NULL
    @retval  #BCM_ERR_NOT_FOUND       aDomainNum/aPortNum is invalid

    @post None

    @limitations None

    @trace #BRCM_SWREQ_ETS
*/
extern int32_t ETS_GetDomainNumPortStatusV2(BCM_HandleType aConnHdl,
                                             const ETS_DomainType aDomainNum,
                                             const uint32_t aPortNum,
                                             ETS_DomainPortStatusV2Type* const aStatus);

#endif /* ETS_API_H */
/** @} */
