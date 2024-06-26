
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
    @defgroup grp_ethernet_nif_ifc  Ethernet abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_nif_ifc
    @{

    @file ethernet_nif.h

    @brief Ethernet Interface
    This file contains the interfaces for the abstract for Ethernet

    @version 1.0 Initial version
*/

#ifndef ETHER_NIF_H
#define ETHER_NIF_H

#include <ethernet_common.h>

/**
    @name Ethernet API IDs
    @{
    @brief API IDs for Ethernet
*/
#define BRCM_SWARCH_ETHER_CMDID_TYPE               (0x8E01U) /**< @brief #ETHER_CmdIdType                */
#define BRCM_SWARCH_ETHER_MDIOACCESS_TYPE          (0x8E02U) /**< @brief #ETHER_MDIOAccessType           */
#define BRCM_SWARCH_ETHER_MSGUNION_TYPE            (0x8E03U) /**< @brief #ETHER_MsgUnionType             */
#define BRCM_SWARCH_ETHER_ID_OF_MACRO              (0x8E04U) /**< @brief #ETHER_ID_OF                    */
#define BRCM_SWARCH_ETHER_READCL22_PROC            (0x8E05U) /**< @brief #ETHER_ReadCl22                 */
#define BRCM_SWARCH_ETHER_WRITECL22_PROC           (0x8E06U) /**< @brief #ETHER_WriteCl22                */
#define BRCM_SWARCH_ETHER_READCL45_PROC            (0x8E07U) /**< @brief #ETHER_ReadCl45                 */
#define BRCM_SWARCH_ETHER_WRITECL45_PROC           (0x8E08U) /**< @brief #ETHER_WriteCl45                */
#define BRCM_SWARCH_ETHER_SEND_DBG_PKT_PROC        (0x8E09U) /**< @brief #ETHER_SendDbgPkt               */
#define BRCM_SWARCH_ETHER_MAX_MSG_SIZE_MACRO       (0x8E0AU) /**< @brief #ETHER_MAX_MSG_SIZE             */
#define BRCM_SWARCH_ETHER_DBGPKTL2PAYLOADLEN_MACRO (0x8E0BU) /**< @brief #ETHER_DBGPKT_L2PAYLOADBUFF_LEN */
#define BRCM_SWARCH_ETHER_DBGPKT_TYPE              (0x8E0CU) /**< @brief #ETHER_DbgPktType               */
/** @} */

/**
    @brief Macro to Construct Ethernet CmdID

    @trace #BRCM_SWREQ_ETHER
*/
#define ETHER_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_ETH_ID, aId)

/**
    @brief Maximum size of ETHERNET messages

    @trace #BRCM_SWREQ_ETHER
*/
#define ETHER_MAX_MSG_SIZE             (440UL)

/**
    @brief Maximum size of Ethernet IP header

    ETHER_MAX_MSG_SIZE - sizeof other structure members in ETHER_DbgPktType

    @trace #BRCM_SWREQ_ETHER
*/
#define ETHER_DBGPKT_L2PAYLOADBUFF_LEN    (394UL)

/**
    @brief Message structure for sending ethernet debug packet

    If 'l2PayloadLen' is more than #ETHER_DBGPKT_L2PAYLOADBUFF_LEN, last byte of 'l2Payload' is
    used for padding. This is applicable when user needs to send larger packets.

    @trace #BRCM_SWREQ_ETHER
*/
typedef struct sETHER_DbgPktType {
    ETHER_PortIDType portId;                                    /**< @brief port index in BRCM Header     */
    uint32_t         tSec;                                      /**< @brief Time alignment in sec         */
    uint32_t         tNanoSec;                                  /**< @brief Time alignment in n-sec       */
    uint16_t         l2PayloadLen;                              /**< @brief Actual L2 payload length      */
    ETHER_VLANIDType vlanId;                                    /**< @brief VLAN ID                       */
    uint16_t         ethType;                                   /**< @brief Ether type                    */
    uint8_t          dMac[6];                                   /**< @brief Destination MAC Address       */
    uint8_t          sMac[6];                                   /**< @brief Source MAC Address            */
    uint8_t          l2Payload[ETHER_DBGPKT_L2PAYLOADBUFF_LEN]; /**< @brief L2 payload buffer             */
    uint8_t          pcp;                                       /**< @brief PCP in VLAN tag               */
    uint8_t          dei;                                       /**< @brief DEI in VLAN tag               */
    uint8_t          tc;                                        /**< @brief Traffic class in tx mgmt info */
    uint8_t          reserved[13];
} ETHER_DbgPktType;
BCM_STATIC_SIZE_ASSERT(ETHER_DbgPktType, 440U, ETHER_MAX_MSG_SIZE);

/**
    @name Ethernet command IDs
    @{
    @brief Ethernet command IDs group

    @trace #BRCM_SWREQ_ETHER
*/
typedef uint8_t ETHER_CmdIdType;                            /**< @brief Ethernet command message Type  */
#define ETHER_CMDID_MDIO_READ     ETHER_ID_OF(0x05U)        /**< @brief MDIO read command              */
#define ETHER_CMDID_MDIO_WRITE    ETHER_ID_OF(0x06U)        /**< @brief MDIO write command             */
#define ETHER_CMDID_SEND_DBG_PKT  ETHER_ID_OF(0x07U)        /**< @brief Send debug pkt command         */
/** @} */

/**
    @brief Structure to perform MDIO read/write accesses

    @trace #BRCM_SWREQ_ETHER
*/
/* Just to support legacy */
typedef struct sETHER_MDIOAccessType {
    uint32_t deviceID;            /**< @brief Device ID   */
    ETHER_MDIOHwIDType mdioHwID;  /**< @brief MDIO Controller ID which is driving the PHY's */
    ETHER_MDIOPktType pkt;        /**< @brief Packet type      */
} ETHER_MDIOAccessType;
BCM_STATIC_SIZE_ASSERT(ETHER_MDIOAccessType, 16UL, ETHER_MAX_MSG_SIZE)

/**
    @brief Union encapsulating all ethernet messages

    @trace #BRCM_SWREQ_ETHER
*/
typedef union uETHER_MsgUnionType {
    uint32_t             data[ETHER_MAX_MSG_SIZE/4UL]; /**< @brief Max Payload size    */
    ETHER_MDIOAccessType mdioAccess;                       /**< @brief MDIO access Payload */
    ETHER_DbgPktType     pkt;                              /**< @brief Ethernet packet     */
} ETHER_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHER_MsgUnionType, 440U, ETHER_MAX_MSG_SIZE)

/**
    @brief NIF MDIO CL22 Register Read

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aHwId           MDIO Controller ID which is driving the PHY's
    @param[in]      aSlaveAddr      Address where the PHY is connected as SLAVE
    @param[in]      aRegAddr        PHY Register address (from the data sheet)
    @param[in]      aDeviceID       Master Or Slave Device ID (0: Master 1: Slave (only on MCM))
    @param[out]     aData           Data to be read from the PHY

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Register Read Success
    @retval         #BCM_ERR_INVAL_PARAMS    aData is NULL or
                                             aHwId is invalid
    @retval         #BCM_ERR_NOMEM           MDIO Channel is Busy

    @post None

    @trace #BRCM_SWREQ_ETHER

    @limitations None
*/
extern int32_t ETHER_ReadCl22(BCM_HandleType aHdl,
                               ETHER_MDIOHwIDType aHwId,
                               ETHER_MDIOSlaveAddrType aSlaveAddr,
                               ETHER_MDIORegAddrType aRegAddr,
                               uint32_t aDeviceID,
                               uint16_t *aData);

/**
    @brief NIF MDIO CL22 Register Write

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aHwId           MDIO Controller ID which is driving the PHY's
    @param[in]      aSlaveAddr      Address where the PHY is connected as SLAVE
    @param[in]      aRegAddr        PHY Register address (from the data sheet)
    @param[in]      aDeviceID       Master Or Slave Device ID (0: Master 1: Slave (only on MCM))
    @param[in]      aData           Data to be written to the PHY

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Register Write Success
    @retval     #BCM_ERR_INVAL_PARAMS   aHwId is invalid
    @retval     #BCM_ERR_NOMEM          MDIO Channel is Busy

    @post None

    @trace #BRCM_SWREQ_ETHER

    @limitations None
*/
extern int32_t ETHER_WriteCl22(BCM_HandleType aHdl,
                                 ETHER_MDIOHwIDType aHwId,
                                 ETHER_MDIOSlaveAddrType aSlaveAddr,
                                 ETHER_MDIORegAddrType aRegAddr,
                                 uint32_t aDeviceID,
                                 uint16_t aData);

/**
    @brief NIF MDIO CL45 Register Read

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aHwId           MDIO Controller ID which is driving the PHY's
    @param[in]      aSlaveAddr      Address where the PHY is connected as SLAVE
    @param[in]      aDevType        DEVAD (from the PHY data sheet)
    @param[in]      aRegAddr        PHY Register address (from the data sheet)
    @param[in]      aDeviceID       Master Or Slave Device ID (0: Master 1: Slave (only on MCM))
    @param[out]     aData           Data read from the PHY

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK              Register Read Success
    @retval         #BCM_ERR_INVAL_PARAMS    aData is NULL or
                                             aHwId is invalid
    @retval         #BCM_ERR_NOMEM           MDIO Channel is Busy

    @post None

    @trace #BRCM_SWREQ_ETHER

    @limitations None
*/
extern int32_t ETHER_ReadCl45(BCM_HandleType aHdl,
                               ETHER_MDIOHwIDType aHwId,
                               ETHER_MDIOSlaveAddrType aSlaveAddr,
                               ETHER_MDIODeviceType aDevType,
                               ETHER_MDIORegAddrType aRegAddr,
                               uint32_t aDeviceID,
                               uint16_t *aData);

/**
    @brief NIF MDIO CL45 Register Write

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aHwId           MDIO Controller ID which is driving the PHY's
    @param[in]      aSlaveAddr      Address where the PHY is connected as SLAVE
    @param[in]      aDevType        DEVAD (from the PHY data sheet)
    @param[in]      aRegAddr        PHY Register address (from the data sheet)
    @param[in]      aDeviceID       Master Or Slave Device ID (0: Master 1: Slave (only on MCM))
    @param[in]      aData           Data to be written to the PHY

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Register Write Success
    @retval         #BCM_ERR_INVAL_PARAMS   aHwId is invalid
    @retval         #BCM_ERR_NOMEM          MDIO Channel is Busy

    @post None

    @trace #BRCM_SWREQ_ETHER

    @limitations None
*/
extern int32_t ETHER_WriteCl45(BCM_HandleType aHdl,
                                 ETHER_MDIOHwIDType aHwId,
                                 ETHER_MDIOSlaveAddrType aSlaveAddr,
                                 ETHER_MDIODeviceType aDevType,
                                 ETHER_MDIORegAddrType aRegAddr,
                                 uint32_t aDeviceID,
                                 uint16_t aData);

/**
    @brief NIF MDIO CL45 Register Write

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl       Connection handle (from RPC_Connect)
    @param[in]      aPkt       Ethernet debug packet to be sent

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Packet sent succesfully
    @retval         #BCM_ERR_INVAL_PARAMS   aHdl or aPkt is invalid
    @retval         #BCM_ERR_NOMEM          Tx Buffer not available

    @post None

    @trace #BRCM_SWREQ_ETHER

    @limitations None
*/
extern int32_t ETHER_SendDbgPkt(BCM_HandleType aHdl,
                                ETHER_DbgPktType *const aPkt);

#endif /* ETHER_NIF_H */
/** @} */
