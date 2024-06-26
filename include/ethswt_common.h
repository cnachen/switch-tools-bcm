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
    @defgroup grp_ethswt_common_ifc Common Interface
    @ingroup grp_ethswt

    @addtogroup grp_ethswt_common_ifc
    @{

    @file ethswt_common.h
    @brief Application programmer interface for Ethernet Switch Driver (Common)

    @version 0.51 Imported from docx
 */

#ifndef ETHSWT_COMMON_H
#define ETHSWT_COMMON_H

#include <compiler.h>
#include <ethernet.h>
#include <ethernet_swt_common.h>

/**
    @name Ethernet Switch driver API IDs
    @{
    @brief API IDs for  Ethernet Switch driver
*/
#define BRCM_SWARCH_ETHSWT_MGMT_INFO_TYPE                  (0x8808U)    /**< @brief #ETHSWT_MgmtInfoType       */
#define BRCM_SWARCH_ETHSWT_SET_MGMT_INFO_PROC              (0x880BU)    /**< @brief #ETHSWT_SetMgmtInfo        */
#define BRCM_SWARCH_ETHSWT_GET_DUMBFWDMODE_PROC            (0x880DU)    /**< @brief #ETHSWT_GetDumbFwdMode     */
#define BRCM_SWARCH_ETHSWT_SET_DUMBFWDMODE_PROC            (0x880EU)    /**< @brief #ETHSWT_SetDumbFwdMode     */
#define BRCM_SWARCH_ETHSWT_SET_PORT_ROLE_PROC              (0x880FU)    /**< @brief #ETHSWT_SetPortRole        */
#define BRCM_SWARCH_ETHSWT_SET_SWITCH_TYPE_PROC            (0x8810U)    /**< @brief #ETHSWT_SetSwitchType      */
#define BRCM_SWARCH_ETHSWT_READ_REG_PROC                   (0x8811U)    /**< @brief #ETHSWT_ReadReg            */
#define BRCM_SWARCH_ETHSWT_WRITE_REG_PROC                  (0x8812U)    /**< @brief #ETHSWT_WriteReg           */
#define BRCM_SWARCH_ETHSWT_INIT_PROC                       (0x8813U)    /**< @brief #ETHSWT_Init               */
#define BRCM_SWARCH_ETHSWT_ENABLE_TX_TIMESTAMP_PROC        (0x8814U)    /**< @brief #ETHSWT_EnableTxTimestamp  */
#define BRCM_SWARCH_ETHSWT_GET_MGMTMODE_PROC               (0x8815U)    /**< @brief #ETHSWT_GetMgmtMode        */
#define BRCM_SWARCH_ETHSWT_SET_MGMTMODE_PROC               (0x8816U)    /**< @brief #ETHSWT_SetMgmtMode        */
#define BRCM_SWARCH_ETHSWT_GET_BRCMHDRMODE_PROC            (0x8817U)    /**< @brief #ETHSWT_GetBrcmHdrMode     */
#define BRCM_SWARCH_ETHSWT_SET_BRCMHDRMODE_PROC            (0x8818U)    /**< @brief #ETHSWT_SetBrcmHdrMode     */
#define BRCM_SWARCH_ETHSWT_ENABLEBHSHIFT_PROC              (0x8819U)    /**< @brief #ETHSWT_EnableBHShift      */
#define BRCM_SWARCH_ETHSWT_ENABLERX_PROC                   (0x881AU)    /**< @brief #ETHSWT_EnableRx           */
#define BRCM_SWARCH_ETHSWT_DISABLERX_PROC                  (0x881BU)    /**< @brief #ETHSWT_DisableRx          */
#define BRCM_SWARCH_ETHSWT_GET_DLF_PORT_MAP_PROC           (0x881CU)    /**< @brief #ETHSWT_GetDLFPortMap      */
#define BRCM_SWARCH_ETHSWT_ADD_DLF_UCAST_PORT_PROC         (0x881DU)    /**< @brief #ETHSWT_AddPortToDLFUcastMap */
#define BRCM_SWARCH_ETHSWT_ADD_DLF_MCAST_PORT_PROC         (0x881EU)    /**< @brief #ETHSWT_AddPortToDLFMcastMap  */
#define BRCM_SWARCH_ETHSWT_REMOVE_DLF_UCAST_PORT_PROC      (0x881FU)    /**< @brief #ETHSWT_RemovePortFromDLFUcastMap */
#define BRCM_SWARCH_ETHSWT_REMOVE_DLF_MCAST_PORT_PROC      (0x8820U)    /**< @brief #ETHSWT_RemovePortFromDLFMcastMap */
#define BRCM_SWARCH_ETHSWT_FRAME_FORWARDING_PROC           (0x8821U)    /**< @brief #ETHSWT_FrameForwarding    */
#define BRCM_SWARCH_ETHSWT_PARSE_MGMTINFO_PROC             (0x8822U)    /**< @brief #ETHSWT_ParseMgmtInfo      */
#define BRCM_SWARCH_ETHSWT_CFP_CID_TYPE                    (0x8823U)    /**< @brief #ETHSWT_CIDType            */
/** @} */

/**
    @brief Maximum number of ports supported by Ethernet switch driver.

    @trace #BRCM_SWREQ_ETHSWT_KERNEL_INTERFACE
*/

/**
    @name CFP Classification ID type
    @{
    @brief Switch CFP Classification ID.

    @trace #BRCM_SWREQ_ETHSWT_KERNEL_INTERFACE
*/
typedef uint8_t ETHSWT_CIDType;         /**< @brief Switch CFP Classification ID type */
/** @} */

/**
    @brief Switch management information

    @trace #BRCM_SWREQ_ETHSWT_KERNEL_INTERFACE
*/
typedef struct sETHSWT_MgmtInfoType {
    ETHSWT_HwIDType   switchIdx;    /**< @brief Switch index            */
    ETHSWT_PortIDType portIdx;      /**< @brief Port index              */
    ETHSWT_TCType     tc;           /**< @brief Traffic class           */
    ETHSWT_CIDType    cid;          /**< @brief CFP classification ID   */
} ETHSWT_MgmtInfoType;


/** @brief Retrieve dumb forward mode for switch

    This API retrieves dumb forward mode of switch.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[out]     aMode       Pointer to retrieve switch dumb forward mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port dumb forward mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_QUERY

    @limitations None
*/
int32_t ETHSWT_GetDumbFwdMode(ETHSWT_HwIDType aSwtID,
        ETHSWT_DumbFwdModeType *const aMode);

/** @brief Set switch dumb forward mode

    This API set dumb forward mode for switch.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aMode       Port dumb forward mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved port dumb forward mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
int32_t ETHSWT_SetDumbFwdMode(ETHSWT_HwIDType aSwtID,
        ETHSWT_DumbFwdModeType aMode);

/** @brief Retrieve Broadcom header mode for IMP

    This API retrieves Broadcom header mode of IMP

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[out]     aMode       Pointer to retrieve IMP Broadcom header mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved IMP Broadcom header mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_QUERY

    @limitations None
*/
int32_t ETHSWT_GetBrcmHdrMode(ETHSWT_HwIDType aSwtID,
        ETHSWT_BrcmHdrModeType *const aMode);

/** @brief Set IMP Broadcom header mode

    This API set Broadcom header mode for IMP

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aMode       IMP Broadcom header mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved Broadcom header mode
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is not within allowed range or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
int32_t ETHSWT_SetBrcmHdrMode(ETHSWT_HwIDType aSwtID,
        ETHSWT_BrcmHdrModeType aMode);

/** @brief Retrieve management mode for switch

    This API retrieves management mode of switch.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[out]     aMode       Pointer to retrieve switch management mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved management mode
    @retval     #BCM_ERR_INVAL_PARAMS   (aMode is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_QUERY

    @limitations None
*/
int32_t ETHSWT_GetMgmtMode(ETHSWT_HwIDType aSwtID, ETHSWT_MgmtModeType *const aMode);

/** @brief Set switch management mode

    This API set management mode for switch.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aMode       Management mode

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved management mode
    @retval     #BCM_ERR_INVAL_PARAMS   aMode is not within allowed range or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
int32_t ETHSWT_SetMgmtMode(ETHSWT_HwIDType aSwtID, ETHSWT_MgmtModeType aMode);

/** @brief Set management information

    This API inserts the management information into the indexed Ethernet buffer
    which was previously adapted for the transmission by calling
    #ETHSWT_TxAdaptBuffer() to achieve the transmission on specific ports of
    the switch.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aCntrlID    Index of Ethernet controller
    @param[in]      aBufIdx     Ethernet buffer index
    @param[in]      aMgmtInfo   Pointer to management information to be set

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Successfully set Management
                                            information
    @retval     #BCM_ERR_INVAL_BUF_STATE    Invalid packet buffer state
    @retval     #BCM_ERR_INVAL_PARAMS       (aMgmtInfo is NULL) or
                                            (Invalid ethernet buffer index)
    @retval     #BCM_ERR_UNINIT             Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_MANAGEMENT

    @limitations None
*/
int32_t ETHSWT_SetMgmtInfo(ETHER_HwIDType aCntrlID,
                            uint32_t aBufIdx,
                            ETHSWT_MgmtInfoType * const aMgmtInfo);

/** @brief Parse management information

    This API parses management info from 32-bit info to structure

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aMgmtInfoPtrIn   Pointer to 32 bit mgmt info
    @param[out]     aMgmtInfoOut     Pointer to mgmt info structure to be set

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Successfully set Management
                                            information
    @retval     #BCM_ERR_INVAL_PARAMS       aMgmtInfo is NULL

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_MANAGEMENT

    @limitations None
*/
int32_t ETHSWT_ParseMgmtInfo(const uint32_t *const aMgmtInfoPtrIn,
                             ETHSWT_MgmtInfoType *const aMgmtInfoOut);

/** @brief Set RxDIS for the Port

    Enables the receive function of the port at the MAC level.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aSwtID      Switch index
    @param[in]      aPortID     Port ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully enabled RxDIS
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized
    @retval     #BCM_ERR_INVAL_PARAMS   (aSwtID is invalid) or
                                        (aPortID is invalid)

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_MANAGEMENT

    @limitations None
*/
int32_t ETHSWT_EnableRx(ETHSWT_HwIDType aSwtID,
                          ETHSWT_PortIDType aPortID);

/** @brief Clear RxDIS for the Port

    Disables the receive function of the port at the MAC level.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aSwtID      Switch index
    @param[in]      aPortID     Port ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully enabled RxDIS
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized
    @retval     #BCM_ERR_INVAL_PARAMS   (aSwtID is invalid) or
                                        (aPortID is invalid)

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_MANAGEMENT

    @limitations None
*/
int32_t ETHSWT_DisableRx(ETHSWT_HwIDType aSwtID,
                           ETHSWT_PortIDType aPortID);

/**
    @brief Set port role

    This API sets the port role

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aSwtID      Switch Index
    @param[in]      aSwiType    Switch type
    @param[in]      aPortID     Port ID
    @param[in]      aRole       Role

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             On Success
    @retval         #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                            switch register
    @retval         #BCM_ERR_INVAL_PARAMS   (aSwtType is invalid) or
                                            (aPortID is invalid) or
                                            (aRole is invalid)

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
 */
int32_t ETHSWT_SetPortRole(ETHSWT_HwIDType aSwtID,
                           ETHSWT_SwitchType aSwtType,
                           ETHSWT_PortIDType aPortID,
                           ETHSWT_PortType aRole);

/**
    @brief Set switch type

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aSwtID          Switch Index
    @param[in]      aSwitchType     Switch type
    @param[in]      aUplinkPortCnt  Number of uplink ports
    @param[in]      aUplinkPortMap  Array containing the uplink port numbers

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK            On Success
    @retval     #BCM_ERR_TIME_OUT      Timeout occurred while reading/writing
                                       switch register
    @retval     #BCM_ERR_INVAL_PARAMS  aSwitch is invalid or
                                       aUplinkPortMap is NULL when aUplinkPortCnt is non-zero

    @post None

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
 */
int32_t ETHSWT_SetSwitchType(ETHSWT_HwIDType aSwtID,
                             ETHSWT_SwitchType aSwitchType,
                             uint32_t aUplinkPortCnt,
                             uint32_t *const aUplinkPortMap);

/** @brief Read switch register

    This API read the switch register and returns eth value in aVal.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aAddr       Register Address
    @param[out]     aVal        Value read from the switch register

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully read register value
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading the
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPage is out of range) or
                                        (aOffset is out of range) or
                                        (Invalid switch index) or
                                        (aVal is NULL)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_QUERY

    @limitations None
*/
int32_t ETHSWT_ReadReg(ETHSWT_HwIDType aSwtID,
    uint32_t aAddr,
    uint64_t *const aVal);

/** @brief Write to Switch register

    This API writes the switch register.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aAddr       Register Address
    @param[in]      aVal        Value to write to the switch register

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully written register value
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while writing the
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   (aPage is out of range) or
                                        (aOffset is out of range) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
int32_t ETHSWT_WriteReg(ETHSWT_HwIDType aSwtID,
                        uint32_t aAddr,
                        uint64_t aVal);

/** @brief Initliaze Ethernet switch driver

    This API initializes Ethernet switch driver

    @behavior Sync, Re-entrant (for different switch index)

    @pre TBD

    @param[in]      aSwtID      Switch index

    @return     void

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_INITIALISATION

    @limitations This API doesn’t perform reset of switch. Switch port are
    enabled by system before initialization of switch driver.
*/
void ETHSWT_Init(ETHSWT_HwIDType aSwtID);

/** @brief Enable TX timestamp

    This API adapts a transmit buffer to add the management information and
    prepare for transmission.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aCntrlID    Controller index
    @param[in]      aBufIdx     Ethernet buffer index
    @param[inout]   aMgmtInfo   Pointer to management information
                                - In: Pointer to the position of the EthType in
                                  common Ethernet frame
                                - Out: Pointer to the position of the EthType in
                                  management frame

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK                 Successfully enabled timestamp for
                                            the given buffer index
    @retval     #BCM_ERR_INVAL_BUF_STATE    Invalid packet buffer state
    @retval     #BCM_ERR_INVAL_PARAMS       (Given TX channel is not allocated for gPTP) or
                                            (aMgmtInfo is NULL) or
                                            (Invalid ethernet buffer index) or
                                            (Invalid switch index)
    @retval     #BCM_ERR_UNINIT             Switch driver not initialized
    @retval     #BCM_ERR_NOSUPPORT          Switch driver does not have timestamp related
                                            functionality (#ENABLE_ETHSWT_TIME) enabled
    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_MANAGEMENT

    @limitations None
*/
int32_t ETHSWT_EnableTxTimestamp(ETHER_HwIDType aCntrlID,
                                   uint32_t aBufIdx,
                                   ETHSWT_MgmtInfoType *const aMgmtInfo);


/** @brief Enable Broadcom Header Shift

    This API enables/disables broadcom header shift in software

    @behavior Sync, Re-entrant

    @pre    None

    @param[in]      aSwtID      Switch index
    @param[in]      aCntrlID    Controller index
    @param[in]      aEnable     TRUE: Enable, FALSE: Disable

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Enabled/disabled successfully
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized
    @retval     #BCM_ERR_INVAL_PARAMS   aSwtID is invalid OR
                                        aCntrlID is invalid OR
                                        aEnable is invalid
    @retval     #BCM_ERR_NOSUPPORT      Unsupported

    @post   None

    @trace  #BRCM_SWREQ_ETHSWT_INITIALISATION

    @limitations None
*/
extern int32_t ETHSWT_EnableBHShift(ETHSWT_HwIDType aSwtID,
                                 ETHER_HwIDType aCntrlID, uint32_t aEnable);


/** @brief Add a port to the DLF unicast port map

    This API will add a  port to the DLF unicast port map

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID       Switch index
    @param[in]      aPortID      Switch Port Number

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully added Port to
                                        the DLF unicast port map

    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is INVALID) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
extern int32_t ETHSWT_AddPortToDLFUcastMap(ETHSWT_HwIDType aSwtID,
                                           ETHSWT_PortIDType aPortID);


/** @brief Add a port to the DLF Multicast port map

    This API will add a  port to the DLF Multicast port map

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID       Switch index
    @param[in]      aPortID      Switch Port Number

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully added the Port to DLF Multicast Map
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is INVALID) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
extern int32_t ETHSWT_AddPortToDLFMcastMap (ETHSWT_HwIDType aSwtID,
                                            ETHSWT_PortIDType aPortID);


/** @brief Get the  DLF Port Map for Unicast and Multicast

    This API will return the DLF Port Map for Unicast and Multicast.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID               Switch index
    @param[out]     aDlfMcastPortMap     Dlf Multicast Port Map
    @param[out]     aDlfUcastPortMap     Dlf Unicast Port Map

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully retrieved the DLF Port Map for
                                        Unicast and Multicast
    @retval     #BCM_ERR_INVAL_PARAMS   (aDlfMcastPortMap is NULL) or (aDlfUcastPortMap is NULL) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_QUERY

    @limitations None
*/
extern int32_t ETHSWT_GetDLFPortMap(ETHSWT_HwIDType aSwtID, ETHSWT_PortMaskType *const aDlfMcastMap, ETHSWT_PortMaskType *const aDlfUcastMap);


/** @brief Remove a port in  Dlf Port Map for Unicast

    This API will remove a  port in DLF Port map for Unicast

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aPortID      Switch Port Number

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully removed the Port from DLF Unicast Map
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is Invalid) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
extern int32_t ETHSWT_RemovePortFromDLFUcastMap (ETHSWT_HwIDType aSwtID,ETHSWT_PortIDType aPortID);

/** @brief Remove a port in Dlf Port Map for Multicast

    This API will add a  port in DLF Port map for Multicast

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aSwtID      Switch index
    @param[in]      aPortID     Switch Port Number

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully removed the Port from DLF Multicast Map
    @retval     #BCM_ERR_INVAL_PARAMS   (aPortID is Invalid) or
                                        (Invalid switch index)
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post TBD

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION

    @limitations None
*/
extern int32_t ETHSWT_RemovePortFromDLFMcastMap(ETHSWT_HwIDType aSwtID,ETHSWT_PortIDType aPortID);

/** @brief Control frame forwarding

    This API enable or disable frame forwarding

    @behavior Sync, Re-entrant (for different switch index)

    @pre Switch driver is initialized

    @param[in]      aSwtID      Switch index
    @param[in]      aEnable     TRUE: Enable, FALSE: Disable

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully removed the Port from DLF Multicast Map
    @retval     #BCM_ERR_INVAL_PARAMS   aSwtID is Invalid or
                                        invalid aEnable option
    @retval     #BCM_ERR_UNINIT         Switch driver not initialized

    @post Switch is ready to handle/pass traffic

    @trace  #BRCM_SWREQ_ETHSWT_DYNAMIC_CONFIGURATION
*/
extern int32_t ETHSWT_FrameForwarding(ETHSWT_HwIDType aSwtID, BCM_BoolType aEnable);

#endif /* ETHSWT_COMMON_H */

/** @} */
