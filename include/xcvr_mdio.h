/*****************************************************************************
 Copyright 2019-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_xcvr_mdio Ethernet MDIO abstract Interface
    @ingroup grp_transceiver_abstract

    @addtogroup grp_xcvr_mdio
    @{

    @file xcvr_mdio.h

    @brief Ethernet Service: MDIO interface
    This file defines the interface for ethernet MDIO

    @version 1.0 Initial version
*/

#ifndef XCVR_MDIO_H
#define XCVR_MDIO_H

#include <stddef.h>
#include <inttypes.h>
#include <bcm_err.h>
#include <xcvr_common.h>

/**
    @name MDIO driver API IDs
    @{
    @brief API IDs for MDIO driver
 */
#define BRCM_SWARCH_MDIO_MSG_MAX_SIZE_MACRO                     (0x8000U) /**< @brief #MDIO_MSG_MAX_SIZE    */
#define BRCM_SWARCH_MDIO_HW_IDTYPE_TYPE                         (0x8001U) /**< @brief #MDIO_HwIDType        */
#define BRCM_SWARCH_MDIO_CTRLMODE_TYPE                          (0x8002U) /**< @brief #MDIO_CtrlModeType    */
#define BRCM_SWARCH_MDIO_ACC_CLAUSE_TYPE                        (0x8003U) /**< @brief #MDIO_AccClauseType   */
#define BRCM_SWARCH_MDIO_SLAVEADDR_TYPE                         (0x8004U) /**< @brief #MDIO_SlaveAddrType   */
#define BRCM_SWARCH_MDIO_DEVICE_TYPE                            (0x8005U) /**< @brief #MDIO_DeviceType      */
#define BRCM_SWARCH_MDIO_REGADDR_TYPE                           (0x8006U) /**< @brief #MDIO_RegAddrType     */
#define BRCM_SWARCH_MDIO_PKT_TYPE                               (0x8007U) /**< @brief #MDIO_PktType         */
#define BRCM_SWARCH_MDIO_ACCESS_TYPE                            (0x8008U) /**< @brief #MDIO_AccessType      */
#define BRCM_SWARCH_MDIO_BUS_CFG_TYPE                           (0x8009U) /**< @brief #MDIO_BusCfgType      */
#define BRCM_SWARCH_MDIO_INIT_PROC                              (0x800AU) /**< @brief #MDIO_Init            */
#define BRCM_SWARCH_MDIO_OPEN_PROC                              (0x800BU) /**< @brief #MDIO_Open            */
#define BRCM_SWARCH_MDIO_READ_PROC                              (0x800CU) /**< @brief #MDIO_Read            */
#define BRCM_SWARCH_MDIO_WRITE_PROC                             (0x800DU) /**< @brief #MDIO_Write           */
#define BRCM_SWARCH_MDIO_CLOSE_PROC                             (0x800EU) /**< @brief #MDIO_Close           */
#define BRCM_SWARCH_MDIO_DE_INIT_PROC                           (0x800FU) /**< @brief #MDIO_DeInit          */
#define BRCM_SWARCH_MDIO_CUSTOM_DATA_TYPE                       (0x8010U) /**< @brief #MDIO_CustomDataType  */
#define BRCM_SWARCH_MDIO_HANDLE_TYPE                            (0x8011U) /**< @brief #MDIO_HandleType      */
/** @} */

/**
    @brief Maximum size of command payload in bytes

    @trace #BRCM_SWREQ_MDIO
*/
#define MDIO_MSG_MAX_SIZE    (32UL)

/**
    @brief MDIO hardware index

    Each MDIO bus in the system is represented by this unique number.

    @trace #BRCM_SWREQ_MDIO
*/
typedef uint32_t MDIO_HwIDType;

/**
    @name MDIO_CtrlModeType
    @{
    @brief MDIO controller mode type

    @trace #BRCM_SWREQ_MDIO
*/
typedef uint32_t MDIO_CtrlModeType;
#define MDIO_CTRLMODE_MASTER        (1UL)   /**< @brief MDIO controller master mode */
#define MDIO_CTRLMODE_SLAVE         (2UL)   /**< @brief MDIO controller slave mode */
/** @} */

/**
    @name MDIO_AccClauseType
    @{
    @brief MDIO register access clause

    @trace #BRCM_SWREQ_MDIO
 */
typedef uint8_t MDIO_AccClauseType;
#define MDIO_ACC_CLAUSE_CL22       (0x1U)    /**< @brief MDIO CL22 register access */
#define MDIO_ACC_CLAUSE_CL45       (0x2U)    /**< @brief MDIO CL45 register access */
/** @} */

/**
    @name MDIO_CustomDataType
    @{
    @brief MDIO Custom Data

    This element is used only in the implementation of the functions in this layer/file
    to distinquish between different Phy connections.

    It may be set to zero if not needed in the underlying implementation

    @trace #BRCM_SWREQ_MDIO
 */
typedef uint32_t MDIO_CustomDataType;
#define MDIO_CUSTOM_DATA_DIRECT             (0x0UL)         /**< @brief Direct MDIO access                      */
#define MDIO_CUSTOM_DATA_DENALI_8P_MC       (0x4D440800UL)  /**< @brief MD80 MDIO Denali 8-port Media Converter */
#define MDIO_CUSTOM_DATA_EIGER_EVK          (0x45494700UL)  /**< @brief EIG0 MDIO Eiger EVK                     */
#define MDIO_CUSTOM_DATA_SHORTFIN_MC        (0x45494701UL)  /**< @brief SF80 MDIO Shortfin 8-port media Converter */
/** @} */

/**
    @brief MDIO Bus configuration type

    @trace #BRCM_SWREQ_MDIO
 */
typedef struct sMDIO_BusCfgType {
    MDIO_HwIDType       hwID;           /**< MDIO hardware index          */
    MDIO_CtrlModeType   cntrlMode;      /**< @brief MDIO controller mode  */
    uint32_t            speed;          /**< @brief MDIO speed            */
    MDIO_CustomDataType custom0;        /**< @brief Phy Connection type   */
    uint32_t            custom1;        /**< @brief Data specific to custom0 */
} MDIO_BusCfgType;
BCM_STATIC_SIZE_ASSERT(MDIO_BusCfgType, 20UL, MDIO_MSG_MAX_SIZE)

/**
    @name MDIO_SlaveAddrType
    @{
    @brief MDIO Slave Address Type

    @trace #BRCM_SWREQ_MDIO
*/
typedef uint8_t MDIO_SlaveAddrType;
#define MDIO_SLAVEADDR_MASK         (0x1FU) /**< @brief MDIO slave address field mask */
#define MDIO_SLAVEADDR_MAX          (31U)   /**< @brief MDIO slave address max value */
/** @} */

/**
    @name MDIO_DeviceType
    @{
    @brief MDIO Device Type

    @trace #BRCM_SWREQ_MDIO
*/
typedef uint8_t MDIO_DeviceType;
#define MDIO_DEVICETYPE_MASK        (0x1FU) /**< @brief MDIO device type field mask */
#define MDIO_DEVICETYPE_MAX         (31U)   /**< @brief MDIO device type max value */
/** @} */

/**
    @name MDIO_RegAddrType
    @{
    @brief MDIO register addres type

    @trace #BRCM_SWREQ_MDIO
 */
typedef uint16_t MDIO_RegAddrType;
#define MDIO_REGADDR_CL22_MASK     (0x1FU)   /**< @brief MDIO register address mask for CL22 register access */
#define MDIO_REGADDR_CL22_MAX      (0x1FU)   /**< @brief MDIO register address max for CL22 register access */
#define MDIO_REGADDR_CL45_MASK     (0xFFFFU) /**< @brief MDIO register address mask for CL45 register access */
#define MDIO_REGADDR_CL45_MAX      (0xFFFFU) /**< @brief MDIO register address max for CL45 register access */
/** @} */

/**
    @brief MDIO handle details
    @{
    @brief MDIO handle type

    @trace #BRCM_SWREQ_MDIO
 */
typedef BCM_HandleType MDIO_HandleType;
#define MDIO_HANDLE_CTX_SHIFT       (0ULL)
#define MDIO_HANDLE_CTX_MASK        (0xFFULL)
#define MDIO_HANDLE_SESSION_SHIFT   (8ULL)
#define MDIO_HANDLE_SESSION_MASK    (0xFFULL)
#define MDIO_HANDLE_SEED_SHIFT      (16ULL)
#define MDIO_HANDLE_SEED_MASK       (0xFFFFULL)
#define MDIO_HANDLE_MAGIC_SHIFT     (32ULL)
#define MDIO_HANDLE_MAGIC_MASK      (0xFFFFFFFFULL)
/** @} */

/**
    @brief MDIO transfer packet

    MDIO transfer packet structure.

    @trace #BRCM_SWREQ_MDIO
*/
typedef struct sMDIO_PktType {
    MDIO_SlaveAddrType slaveAddr;   /**< @brief Device address of the MDIO slave.
                                        This slaveAddr is 5bit address */
    MDIO_DeviceType    deviceType;  /**< @brief Device type */
    MDIO_AccClauseType regAccMode;  /**< @brief Slave register access mode type */
    MDIO_RegAddrType   regAddr;     /**< @brief Slave register address */
    uint16_t           regData;     /**< @brief Data read from slave register
                                          or data to write to slave register */
} MDIO_PktType;
BCM_STATIC_SIZE_ASSERT(MDIO_PktType, 8UL, MDIO_MSG_MAX_SIZE)

/**
    @brief Structure to perform MDIO read/write accesses

    @trace #BRCM_SWREQ_MDIO
*/
typedef struct sMDIO_AccessType {
    uint32_t deviceID;            /**< @brief MDIO device ID   */
    MDIO_HwIDType mdioHwID;       /**< @brief MDIO hardware ID */
    MDIO_PktType pkt;             /**< @brief Packet type      */
} MDIO_AccessType;
BCM_STATIC_SIZE_ASSERT(MDIO_AccessType, 16UL, MDIO_MSG_MAX_SIZE)

/**
    @brief Initialize MDIO

    This API initializes MDIO bus.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aUsrData        64-bit user data (to be used internally by MDIO driver)
    @param[in]      aConfig         Pointer to bus configuration structure

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aConfig in NULL
    @retval         #BCM_ERR_INVAL_PARAMS   Some configuration in aConfig is not correct
    @retval         #BCM_ERR_INVAL_STATE    Bus already initialized.
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_MDIO

    @limitations None
*/
extern int32_t MDIO_Init(uint64_t aUsrData, const MDIO_BusCfgType *const aConfig);

/**
    @brief Open MDIO connection with device

    This API opens a virtual connection with given slave and returns
    64-bit handle in aHdl.

    On single MDIO bus (same aID), multiple devices could be connected
    and user need to call #MDIO_Open for each slave device and obtain
    a handle. This handle can be used for #MDIO_Read and #MDIO_Write
    APIs.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aUsrData        64-bit user data
    @param[in]      aHwID           MDIO hardware index
    @param[in]      aSlaveAddr      5-bit slave address
    @param[in]      aRegAccMode     Register access mode
    @param[out]     aHdl            MDIO handle

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             success
    @retval         #BCM_ERR_INVAL_PARAMS   aHwID is invalid
    @retval         #BCM_ERR_INVAL_PARAMS   aSlaveAddr > 31
    @retval         #BCM_ERR_INVAL_PARAMS   aRegAccMode is invalid
    @retval         #BCM_ERR_INVAL_PARAMS   aHdl is NULL
    @retval         #BCM_ERR_INVAL_STATE    MDIO is already in opened state
    @retval         #BCM_ERR_UNINIT         Bus not initialized
    @retval         #BCM_ERR_UNKNOWN        integration error

    @post None

    @trace #BRCM_SWREQ_MDIO

    @limitations None
*/
extern int32_t MDIO_Open(uint64_t aUsrData, MDIO_HwIDType aHwID, uint32_t aSlaveAddr,
                            MDIO_AccClauseType aRegAccMode, BCM_HandleType *const aHdl);

/** @brief MDIO read

    API to do MDIO read operation.

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

    @trace #BRCM_SWREQ_MDIO

    @limitations None
*/
extern int32_t MDIO_Read(BCM_HandleType aHdl, uint16_t aRegAddr, uint8_t aDevType,
                            uint16_t *const aData);

/** @brief MDIO write

    API to do MDIO write operation.

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

    @trace #BRCM_SWREQ_MDIO

    @limitations None
*/
extern int32_t MDIO_Write(BCM_HandleType aHdl, uint16_t aRegAddr, uint8_t aDevType,
                            uint16_t aData);

/** @brief Close MDIO driver

    This API closes MDIO handle which was previously opened using #MDIO_Open call.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aHdl        MDIO handle

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_INVAL_PARAMS   aHdl is invalid

    @post None

    @trace #BRCM_SWREQ_MDIO

    @limitations None
*/
extern int32_t MDIO_Close(BCM_HandleType aHdl);

/** @brief De-Initialize MDIO bus

    API to de-initialize MDIO bus.

    @behavior Sync, Re-entrant

    @pre TBD

    @param[in]      aHdl          MDIO handle

    Return values are documented in reverse-chronological order
    @return         void

    @post None

    @trace #BRCM_SWREQ_MDIO

    @limitations None
*/
extern void MDIO_DeInit(MDIO_HwIDType aID);

#endif /* XCVR_MDIO_H */
/** @} */
