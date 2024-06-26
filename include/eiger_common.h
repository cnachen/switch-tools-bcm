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
    @defgroup grp_xcvr_eiger_common_imp EIGER Driver common Interface
    @ingroup grp_eiger_phy

    @addtogroup grp_xcvr_eiger_common_imp
    @{

    @file eiger_common.h
*/

#ifndef EIGER_COMMON_H
#define EIGER_COMMON_H

#include <xcvr_common.h>
#include <xcvr_functbl.h>

/**
    @name EIGER API IDs
    @{
    @brief API IDs for EIGER driver
*/
#define BRCM_SWARCH_EIGER_BUS_READ_PROC                        (0x8801U)    /**< @brief #EIGER_BusRead            */
#define BRCM_SWARCH_EIGER_BUS_WRITE_PROC                       (0x8802U)    /**< @brief #EIGER_BusWrite           */
#define BRCM_SWARCH_EIGER_IS_SUPPORTED_PROC                    (0x8803U)    /**< @brief #EIGER_IsSupported        */
#define BRCM_SWARCH_EIGER_CHECK_ERR_MACRO                      (0x8804U)    /**< @brief #EIGER_CHECK_ERR          */
#define BRCM_SWARCH_EIGER_CHECK_ERR_VOID_RETURN_MACRO          (0x8805U)    /**< @brief #EIGER_CHECK_ERR_VOID_RETURN */

/** @} */

/**
    @brief Return value Error check

    @trace #BRCM_SWREQ_EIGER
*/
#define EIGER_CHECK_ERR(ret, data)                      \
    if ((BCM_ERR_OK != (ret))) {                        \
        BCM_LOG_ERROR(0U, BCM_STATE_READY, ret, data);  \
        return ret;}

/**
    @brief Return value Error check

    @trace #BRCM_SWREQ_EIGER
*/
#define EIGER_CHECK_ERR_VOID_RETURN(ret, data)          \
    if ((BCM_ERR_OK != (ret))) {                        \
       BCM_LOG_ERROR(0U, BCM_STATE_READY, ret, data);  \
       return;}

/**
    @brief EIGER MDIO read operation.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aHdl        MDIO handle
    @param[in]      aRegAddr    register address for CL22 (5-bits)/ CL45 (16-bits)
    @param[in]      aDevType    5-bit device type for CL45
    @param[in]      aData       Pointer to 16-bit data

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aRegAddr > 31 for CL22 mode
    @retval     #BCM_ERR_INVAL_PARAMS   aDevType > 31
    @retval     #BCM_ERR_INVAL_PARAMS   aData is NULL
    @retval     #BCM_ERR_NOSUPPORT      Operation unsupported as controller is
                                        in slave mode of operation.
    @retval     #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_EIGER
*/
int32_t EIGER_BusRead(BCM_HandleType aHdl, uint16_t aRegAddr, uint8_t aDevType, uint16_t *const aData);

/**
    @brief EIGER  MDIO write operation.

    @behavior Async, Re-entrant

    @pre            None

    @param[in]      aHdl        MDIO handle
    @param[in]      aRegAddr    register address for CL22 (5-bits)/ CL45 (16-bits)
    @param[in]      aDevType    5-bit device type for CL45
    @param[in]      aData       16-bit data to be written to slave device

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aHdl is invalid
    @retval     #BCM_ERR_INVAL_PARAMS   aRegAddr > 31 (CL22 mode)
    @retval     #BCM_ERR_INVAL_PARAMS   aDevType > 31
    @retval     #BCM_ERR_NOSUPPORT      Operation unsupported as controller is
                                        in slave mode of operation.
    @retval     #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_EIGER
*/

int32_t EIGER_BusWrite(BCM_HandleType aHdl, uint16_t aRegAddr, uint8_t aDevType, uint16_t aData);

/**
    @brief EIGER Function type to check if the given PHY is supported by driver.

    @param[in]     aConnHdl     Connection handle (from RPC_Connect)
    @param[out]    aPhyID       Pointer to retrieve table index

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            Table index retrieved successfully
    @retval     #BCM_ERR_NOSUPPORT     No supported function table found

    @post None

    @limitations None

    @trace #BRCM_SWREQ_EIGER
*/
int32_t EIGER_IsSupported(BCM_HandleType aConnHdl, const ETHXCVR_PhyIDType *const aPhyID);

#endif /* EIGER_COMMON_H */
/** @} */
