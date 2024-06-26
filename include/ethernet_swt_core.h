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
    @defgroup grp_ethernet_swt_core_ifc Switch CORE abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_core_ifc
    @{

    @file ethernet_swt_core.h

    @brief CORE Interface
    This file contains the interfaces for the Ethernet abstract for CORE

    @version 1.0 Initial version
*/

#ifndef ETHERNET_SWT_CORE_H
#define ETHERNET_SWT_CORE_H

#include <ethernet_common.h>
#include <rpc_msg.h>
#include <system_mcu.h>

/**
    @name Switch CORE API IDs
    @{
    @brief API IDs for CORE in Switch
*/
#define BRCM_SWARCH_ETHSWT_CORECMDID_TYPE              (0x8801U)    /**< @brief #ETHSWT_CoreCmdIdType         */
#define BRCM_SWARCH_ETHSWT_COREREGACCESS_TYPE          (0x8802U)    /**< @brief #ETHSWT_CoreRegAccessType     */
#define BRCM_SWARCH_ETHSWT_CORE_MAX_PAYLOAD_SIZE_MACRO (0x8803U)    /**< @brief #ETHSWT_CORE_MAX_PAYLOAD_SIZE */
#define BRCM_SWARCH_ETHSWT_CORE_ID_OF_MACRO            (0x8804U)    /**< @brief #ETHSWT_CORE_ID_OF            */
#define BRCM_SWARCH_ETHSWT_CORE_READ_PROC              (0x8805U)    /**< @brief #ETHSWT_CoreRead              */
#define BRCM_SWARCH_ETHSWT_CORE_WRITE_PROC             (0x8806U)    /**< @brief #ETHSWT_CoreWrite             */
#define BRCM_SWARCH_ETHSWT_CORE_SETDUMBFWD_PROC        (0x8807U)    /**< @brief #ETHSWT_CoreSetDumbFwd        */
#define BRCM_SWARCH_ETHSWT_CORE_GETDUMBFWD_PROC        (0x8808U)    /**< @brief #ETHSWT_CoreGetDumbFwd        */
#define BRCM_SWARCH_ETHSWT_CORE_SETBRCMHDR_PROC        (0x8809U)    /**< @brief #ETHSWT_CoreSetBrcmHdr        */
#define BRCM_SWARCH_ETHSWT_CORE_GETBRCMHDR_PROC        (0x880AU)    /**< @brief #ETHSWT_CoreGetBrcmHdr        */
#define BRCM_SWARCH_ETHSWT_CORE_SETAGETIME_PROC        (0x880BU)    /**< @brief #ETHSWT_CoreSetAgeTime        */
#define BRCM_SWARCH_ETHSWT_CORE_GETAGETIME_PROC        (0x880CU)    /**< @brief #ETHSWT_CoreGetAgeTime        */
#define BRCM_SWARCH_ETHSWT_CORE_SETMGMTMODE_PROC       (0x880DU)    /**< @brief #ETHSWT_CoreSetMgmtMode       */
#define BRCM_SWARCH_ETHSWT_CORE_GETMGMTMODE_PROC       (0x880EU)    /**< @brief #ETHSWT_CoreGetMgmtMode       */
#define BRCM_SWARCH_ETHSWT_CORE_SETIFILTER_PROC        (0x880FU)    /**< @brief #ETHSWT_CoreSetIfilter        */
#define BRCM_SWARCH_ETHSWT_CORE_GETIFILTER_PROC        (0x8810U)    /**< @brief #ETHSWT_CoreGetIfilter        */
/** @} */

/**
    @brief Maximum size of Core command payload in bytes

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CORE_MAX_PAYLOAD_SIZE     (140UL)

/**
    @brief Macro to Construct Ethernet Core Commands

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_CORE_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_CRE_ID, aId)

/**
    @name Switch Core command IDs
    @{
    @brief Switch Core command IDs group

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_CoreCmdIdType;               /**< @brief Core command message Type                        */
#define ETHSWT_CORECMDID_WRITE            ETHSWT_CORE_ID_OF(0x50U)  /**< @brief #ETHSWT_CoreRegAccessType       #ETHSWT_WriteReg */
#define ETHSWT_CORECMDID_READ             ETHSWT_CORE_ID_OF(0x51U)  /**< @brief #ETHSWT_CoreRegAccessType       #ETHSWT_ReadReg  */
/** @} */

/**
    @brief Structure to manage the switch register R/W access.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_CoreRegAccessType{
    uint8_t        data[128UL]; /**< @brief Memory */
    uint32_t       addr;        /**< @brief Address */
    uint32_t       len;         /**< @brief Length of access */
    MCU_DeviceType deviceID;    /**< @brief Device ID */
} ETHSWT_CoreRegAccessType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_CoreRegAccessType, 140UL, ETHSWT_CORE_MAX_PAYLOAD_SIZE)

/** @brief Read switch register

    This API read the switch register and returns the #aData

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aAddr       Register Address
    @param[in]      aDeviceID   Device Address
    @param[out]     aData       Value read from the switch register

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully read register value
    @retval     #BCM_ERR_INVAL_PARAMS   (#aAddr is Invalid) or
                                        (Invalid #aConnHdl) or
                                        (Invalid #aDeviceID) or
                                        (#aData is NULL)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreRead(BCM_HandleType aConnHdl, uint32_t aAddr,
                                        MCU_DeviceType aDeviceID, uint64_t *const aData);

/** @brief Write to Switch register

    This API writes to the switch register.

    @behavior Sync, Non Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aAddr       Register Address
    @param[in]      aDeviceID   Device Address
    @param[in]      aData       Value to write to the switch register

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully written to the switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (#aAddr is Invalid) or
                                        (Invalid #aConnHdl) or
                                        (Invalid #aDeviceID)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreWrite(BCM_HandleType aConnHdl, const uint32_t aAddr,
                                        MCU_DeviceType aDeviceID, uint64_t aData);

/** @brief Set switch dumb forward mode

    This API set dumb forward mode for switch.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aMode       Port dumb forward mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port dumb forward mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreSetDumbFwd(BCM_HandleType aConnHdl, const ETHSWT_DumbFwdModeType aMode);

/** @brief Get dumb forward mode for switch

    This API retrieves dumb forward mode of switch.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[out]     aMode       Pointer to retrieve switch dumb forward mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port dumb forward mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreGetDumbFwd(BCM_HandleType aConnHdl, ETHSWT_DumbFwdModeType *const aMode);

/** @brief Set IMP Broadcom header mode

    This API set Broadcom header mode for IMP (Inband Management Port)

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aMode       IMP Broadcom header mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved Broadcom header mode
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is not within allowed range or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreSetBrcmHdr(BCM_HandleType aConnHdl, const ETHSWT_BrcmHdrModeType aMode);

/** @brief Get Broadcom header mode for IMP (Inband Management Port)

    This API retrieves Broadcom header mode of IMP

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[out]     aMode       Pointer to retrieve IMP Broadcom header mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved IMP Broadcom header mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreGetBrcmHdr(BCM_HandleType aConnHdl, ETHSWT_BrcmHdrModeType *const aMode);

/** @brief Set Switch Age Time

    This API sets switch ARL age time. If 0 value is passed as aAge,
    it disables ARL ageing.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aAge        Switch FDB age time

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set ARL age
    @retval     #BCM_ERR_INVAL_PARAMS   Invalid aConnHdl
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreSetAgeTime(BCM_HandleType aConnHdl,  uint32_t aAge);

/** @brief Retrieve Switch ARL age time

    This API retreives switch ARL age time.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[out]     aAge        Pointer to retrieve FDB age

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved FDB age
    @retval     #BCM_ERR_INVAL_PARAMS   (aAge is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreGetAgeTime(BCM_HandleType aConnHdl, uint32_t *const aAge);

/** @brief Set switch management mode

    This API sets the management mode for switch.
    Refer to the TRM for detailed explaination of managed mode of the switch.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aMode       Management mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved management mode
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is not within allowed range or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreSetMgmtMode(BCM_HandleType aConnHdl, const ETHSWT_MgmtModeType aMode);

/** @brief Get management mode for switch

    This API retrieves the curent operating mode of the switch.
    Refer to the TRM for detailed explaination of managed mode of the switch.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[out]     aMode       Pointer to retrieve switch management mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved management mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreGetMgmtMode(BCM_HandleType aConnHdl, ETHSWT_MgmtModeType *const aMode);

/** @brief Set Switch VLAN ingress filter mode

    This API sets the switch VLAN ingress filter mode.
    With iFilter enabled, a VLAN packet arriving on a port will have no forwarding/learning
    unless the port is a member of that VLAN. SDK sets this by option default on boot-up.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aMode       VLAN Ingress filter mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully set switch
                                        VLAN ingress filter mode
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid VLAN ingress filter mode) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreSetIfilter(BCM_HandleType aConnHdl,
                                        const ETHSWT_VLANIngressFilterModeType aIfilter);

/** @brief Get Switch VLAN ingress filter mode

    This API retrieves switch VLAN ingress filter mode.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[out]     aMode       Pointer to retrieve VLAN ingress filter state

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved switch
                                        VLAN ingress filter
    @retval     #BCM_ERR_INVAL_PARAMS   (Invalid aMode) or
                                        (Invalid aConnHdl)
    @retval     #BCM_ERR_UNKNOWN        Unknown Error

    @post None

    @trace  #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_CoreGetIfilter(BCM_HandleType aConnHdl,
                                        ETHSWT_VLANIngressFilterModeType *const aIfilter);
#endif /* ETHERNET_SWT_CORE_H */
/** @} */
