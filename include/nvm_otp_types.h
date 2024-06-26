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
    @defgroup grp_nvm_abstract_otp_types Types
    @ingroup grp_nvm_abstract_otp

    @addtogroup grp_nvm_abstract_otp_types
    @{

    @file nvm_opt_types.h

    @brief OTP type definitions

    @version 0.1 Initial version
*/

#ifndef NVM_OTP_TYPES_H
#define NVM_OTP_TYPES_H

#include <bcm_comp.h>
#include <crypto_common.h>

/**
    @name OTP types Architecture IDs
    @{
    @brief Architecture IDs for OTP types
*/
#define BRCM_SWARCH_OTP_MACRO                   (0x8800U)   /**< @brief #OTP_MAGIC              */
#define BRCM_SWARCH_OTP_CFG_VER_TYPE            (0x8801U)   /**< @brief #OTP_CfgVerType         */
#define BRCM_SWARCH_OTP_CMD_TYPE                (0x8802U)   /**< @brief #OTP_CmdIDType          */
#define BRCM_SWARCH_OTP_STACKING_INFO_TYPE      (0x8803U)   /**< @brief #OTP_StackingInfoType   */
#define BRCM_SWARCH_OTP_BOOTMODE_TYPE           (0x8804U)   /**< @brief #OTP_BootModeType       */
#define BRCM_SWARCH_OTP_ACCESS_MODE_TYPE        (0x8805U)   /**< @brief #OTP_AccessModeType     */
#define BRCM_SWARCH_OTP_ACCESS_STATUS_TYPE      (0x8806U)   /**< @brief #OTP_AccessStatusType   */
#define BRCM_SWARCH_OTP_PATCH_VER_TYPE          (0x8807U)   /**< @brief #OTP_PatchVerType       */

#define BRCM_SWARCH_OTP_RW_MSG_TYPE             (0x8810U)   /**< @brief #OTP_RawMsgType         */
#define BRCM_SWARCH_OTP_IP_CFG_TYPE             (0x8811U)   /**< @brief #OTP_IpCfgType          */
#define BRCM_SWARCH_OTP_IP_CFG_MSG_TYPE         (0x8812U)   /**< @brief #OTP_IpCfgMsgType       */
#define BRCM_SWARCH_OTP_PROD_MSG_TYPE           (0x8813U)   /**< @brief #OTP_ProdMsgType        */
#define BRCM_SWARCH_OTP_ACCESS_LOCK_MSG_TYPE    (0x8814U)   /**< @brief #OTP_AccessLockMsgType  */
#define BRCM_SWARCH_OTP_BOOT_MODE_MSG_TYPE      (0x8815U)   /**< @brief #OTP_BootModeMsgType    */
#define BRCM_SWARCH_OTP_PATCH_VER_MSG_TYPE      (0x8816U)   /**< @brief #OTP_PatchVerMsgType    */
#define BRCM_SWARCH_OTP_DUK_MSG_TYPE            (0x8817U)   /**< @brief #OTP_DukMsgType         */
#define BRCM_SWARCH_OTP_MVK_MSG_TYPE            (0x8818U)   /**< @brief #OTP_MvkMsgType         */

#define BRCM_SWARCH_OTP_CFG_TYPE                (0x8820U)   /**< @brief #OTP_CfgType            */
#define BRCM_SWARCH_OTP_AUTO_WRITE_TYPE         (0x8821U)   /**< @brief #OTP_AutoWriteType      */

/** @} */

/**
    @brief OTP Module Macro

    @trace #BRCM_SWREQ_OTP
*/
#define OTP_MAGIC                   (0x4F54504DUL)                              /**< @brief ASCII "OTPM"                            */
#define OTP_ID(x)                   BCM_MSG(BCM_GROUPID_NVM, BCM_OTM_ID, (x))   /**< @brief OTPM ID construction macro              */
#define OTP_RAW_MAX_DATA_SIZE       (256UL)                                     /**< @brief max data size for Read/Write messages   */
#define OTP_RPC_MAX_PAYLOAD_SIZE    (288UL)                                     /**< @brief max data size for RPC                   */
#define OTP_DUK_MAX_SIZE            (32UL)                                      /**< @brief Device unique key max size              */

/**
    @brief OTP config version

    @trace #BRCM_SWREQ_OTP
*/
typedef uint32_t OTP_CfgVerType;
#define OTP_CFG_VER_1_0     (0x00010000UL)      /**< @breif Version 1.0         */

/**
    @brief OTP Command ID Type

    @trace #BRCM_SWREQ_OTP
*/
typedef BCM_MsgType OTP_CmdIDType;      /**< @brief typedef for otpm cmdID */
#define OTP_CMD_READ                    OTP_ID(0x01UL) /**< @brief #OTP_RawMsgType   */
#define OTP_CMD_WRITE                   OTP_ID(0x02UL) /**< @brief #OTP_RawMsgType   */
#define OTP_CMD_MAC_READ                OTP_ID(0x03UL) /**< @brief #OTP_RawMsgType   */
#define OTP_CMD_MAC_WRITE               OTP_ID(0x04UL) /**< @brief #OTP_RawMsgType   */
#define OTP_CMD_IPCFG_READ              OTP_ID(0x05UL) /**< @brief #OTP_IpCfgMsgType */
#define OTP_CMD_IPCFG_WRITE             OTP_ID(0x06UL) /**< @brief #OTP_IpCfgMsgType */
#define OTP_CMD_ST_INFO_READ            OTP_ID(0x07UL) /**< @brief #OTP_StackingInfoType */
#define OTP_CMD_ST_INFO_WRITE           OTP_ID(0x08UL) /**< @brief #OTP_StackingInfoType */

#define OTP_CMD_CUST_READ               OTP_ID(0x10UL) /**< @brief #OTP_RawMsgType   */
#define OTP_CMD_CUST_WRITE              OTP_ID(0x11UL) /**< @brief #OTP_RawMsgType   */

#define OTP_CMD_PROD_MODE_GET           OTP_ID(0x81UL) /**< @brief #OTP_ProdMsgType  */
#define OTP_CMD_PROD_MODE_SET           OTP_ID(0x82UL) /**< @brief #OTP_ProdMsgType  */
#define OTP_CMD_ACCESS_LOCK_GET         OTP_ID(0x83UL) /**< @brief #OTP_AccessLockMsgType  */
#define OTP_CMD_ACCESS_LOCK_SET         OTP_ID(0x84UL) /**< @brief #OTP_AccessLockMsgType  */

#define OTP_CMD_BOOT_MODE_GET           OTP_ID(0x90UL) /**< @brief #OTP_BootModeMsgType  */
#define OTP_CMD_BOOT_MODE_SET           OTP_ID(0x91UL) /**< @brief #OTP_BootModeMsgType  */

#define OTP_CMD_PATCH_VERSION_GET       OTP_ID(0xA0UL) /**< @brief #OTP_PatchVerMsgType  */
#define OTP_CMD_PATCH_VERSION_COMMIT    OTP_ID(0xA1UL) /**< @brief #OTP_PatchVerMsgType  */

#define OTP_CMD_DUK_READ                OTP_ID(0xB0UL) /**< @brief #OTP_DukMsgType  */
#define OTP_CMD_DUK_WRITE               OTP_ID(0xB1UL) /**< @brief #OTP_DukMsgType */

/**
    @brief OTP Module Interface ID Type
    @{

    @trace #BRCM_SWREQ_OTP
*/
typedef uint16_t OTP_AccessModeType;            /**< @brief typedef for otpm interface ID */
#define OTP_ACCESS_MODE_SPI_MASK                (0x01U)
#define OTP_ACCESS_MODE_SPI_SHIFT               (0U)
#define OTP_ACCESS_MODE_MDIO_MASK               (0x02U)
#define OTP_ACCESS_MODE_MDIO_SHIFT              (1U)
#define OTP_ACCESS_MODE_PCIE_MASK               (0x04U)
#define OTP_ACCESS_MODE_PCIE_SHIFT              (2U)
/** @} */

/**
    @brief OTP Module Access status Type
    @{

    @trace #BRCM_SWREQ_OTP
*/
typedef uint32_t OTP_AccessStatusType;          /**< @brief typedef for otpm interface ID */
#define OTP_ACCESS_STATUS_UNKNOWN               (0x00UL) /**< @brief  Group Mode Access Status is unknown(Query individually) */
#define OTP_ACCESS_STATUS_UNLOCK                (0x01UL) /**< @brief  Group/Individual Access Status is Unlocked */
#define OTP_ACCESS_STATUS_LOCK                  (0x02UL) /**< @brief  Group/Individual Access Status is Locked */
/** @} */

/**
    @name Boot Mode flags
    @{
    @brief Boot Mode flags

    @trace #BRCM_SWREQ_OTP
*/
typedef uint32_t OTP_BootModeType;              /**< @brief Bootmode bit flags  */
#define OTP_BOOTMODE_FLASH_MASK     (0x01UL)    /**< @brief Flash Boot mask     */
#define OTP_BOOTMODE_FLASH_SHIFT    (0UL)       /**< @brief Flash Boot shift    */
#define OTP_BOOTMODE_TFTP_MASK      (0x02UL)    /**< @brief TFTP Boot mask      */
#define OTP_BOOTMODE_TFTP_SHIFT     (1UL)       /**< @brief TFTP Boot shift     */
#define OTP_BOOTMODE_IPC_MASK       (0x04UL)    /**< @brief IPC Boot mask       */
#define OTP_BOOTMODE_IPC_SHIFT      (2UL)       /**< @brief IPC Boot shift      */
/** @} */

/**
    @brief OTP Patch Version Type
    @{

    @trace #BRCM_SWREQ_OTP
*/
typedef uint32_t OTP_PatchVerType;              /**< @brief typedef for patch version */
#define OTP_PATCH_VER_NOT_FOUND                 (0x00UL)       /**< @brief  No version found*/
#define OTP_PATCH_VER_UNDETERMINE               (0xFFFFFFFFUL) /**< @brief  OTP Patch is out of sync with Sw Patch*/
/** @} */

/**
    @brief OTP Module RPC Read Msg structure

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_RawMsgType {
    uint32_t            rsvd0;  /**< @brief rsvd0  @xsd rsvd */
    uint32_t            rsvd1;  /**< @brief rsvd1  @xsd rsvd */
    uint32_t            rsvd2;  /**< @brief rsvd2  @xsd rsvd */
    uint32_t            len;    /**< @brief length of data @xsd count:buffer*/
    uint8_t             buffer[OTP_RAW_MAX_DATA_SIZE];
                                /**< @brief data buffer.
                                    Input for #OTP_CMD_READ, #OTP_CMD_MAC_READ, and #OTP_CMD_CUST_READ.
                                    Output for #OTP_CMD_WRITE, #OTP_CMD_MAC_WRITE, and #OTP_CMD_CUST_WRITE*/
} OTP_RawMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_RawMsgType, 272UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP IP config structure

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_IpCfgType {
    uint32_t    ipv6;           /**< IP version
                        @xsd ipver:ipAddr;ipver:gwIPAddr;ipver:netmask;ipver:tftpServer     */
    uint8_t     ipAddr[16UL];   /**< @brief IP address @xsd type:ip;default:0.0.0.0         */
    uint8_t     gwIPAddr[16UL]; /**< @brief Gateway IP address @xsd type:ip;default:0.0.0.0 */
    uint8_t     tftpServer[16UL];/**< @brief TFTP server IP address @xsd type:ip;default:0.0.0.0*/
    uint8_t     netmask[16UL];  /**< @brief Netmask to be used @xsd type:ip;default:0.0.0.0 */
    uint32_t    bootInfo;       /**< @brief 24 bits of application specific data
                                    @xsd hex;maxValue:0xFFFFFF;default:0x0                  */
} OTP_IpCfgType;
BCM_STATIC_SIZE_ASSERT(OTP_IpCfgType, 72UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP IP message structure

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_IpCfgMsgType {
    uint32_t            mstSlvSel;                        /**< @brief 0: Master, 1: Slave-1  */
    uint32_t            ipAddr;                           /**< @brief IP address to be used for private communication */
    uint32_t            gwIPAddr;                         /**< @brief Gateway IP address to be used for private communication */
    uint32_t            bootInfo;                         /**< @brief 24 bits of application specific information*/
    uint8_t             netmask;                          /**< @brief Netmask to be used for private communication */
    uint32_t            tftpServerAddr;                   /**< @brief TFTP server IP address */
} OTP_IpCfgMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_IpCfgMsgType, 24UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Production Mode Set/Get

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_ProdMsgType {
    uint32_t           prodStatus;                       /**< @brief Production mode status*/
} OTP_ProdMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_ProdMsgType, 4UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Access Lock Status

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_AccessLockMsgType {
    OTP_AccessModeType     accessMode;                      /**< @brief Input: Access Mode */
    OTP_AccessStatusType   status;                          /**< @brief OutPut: Access Lock status */
} OTP_AccessLockMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_AccessLockMsgType, 8UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Boot Mode

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_BootModeMsgType {
    OTP_BootModeType     bootMode;                      /**< @brief Input/Output: Boot Mode */
} OTP_BootModeMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_BootModeMsgType, 4UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Patching based on SW Version

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_PatchVerMsgType {
    uint32_t     swVersion;                           /**< @brief Output: Available Patch Version
                                                           <Arch(24:31), Major(16:23), Minor(8:15), Custom(0:7)> */
    uint32_t     otpVersion;                          /**< @brief OutPut: Current OTP Patch Version
                                                           <Arch(24:31), Major(16:23), Minor(8:15), Custom(0:7)> */
} OTP_PatchVerMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_PatchVerMsgType, 8UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP Module MVK Read Write data

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_MvkMsgType {
    CRYPTO_KeyType  keyType;         /**< @brief Key type RSA/ECDSA      @xsd pubkey_type:keyValue   */
    uint32_t        keyLength;       /**< @brief Key length in bytes     @xsd pubkey_len:keyValue    */
    uint8_t         keyValue[256UL]; /**< @brief Buffer to store the MKV @xsd pubkey                 */
} OTP_MvkMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_MvkMsgType, 264UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Message to program a DUK into the OTP

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_DukMsgType {
    uint32_t keyType;
    uint8_t  key[OTP_DUK_MAX_SIZE];
} OTP_DukMsgType;
BCM_STATIC_SIZE_ASSERT(OTP_DukMsgType, 36UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Stacking info structure for OTP command

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_StackingInfoType {
    uint8_t            stackingEn; /**< @brief Stacking Enable, @xsd bool;default:false */
    uint8_t            stackPort0; /**< @brief Stacking Port 0 info @xsd default:0      */
    uint8_t            stackPort1; /**< @brief Stacking Port 1 info @xsd default:0      */
    uint8_t            impPort;    /**< @brief Port number enabled in IMP mode (port8)
                                            @xsd default:0                              */
    uint16_t           vlan;       /**< @brief VLAN Id to be used for private communication
                                            @xsd default:0;maxValue:4094                */
    uint16_t           rsvd;       /**< @brief Reserved @xsd rsvd   */
} OTP_StackingInfoType;
BCM_STATIC_SIZE_ASSERT(OTP_StackingInfoType, 8UL, OTP_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP auto write type

    @trace #BRCM_SWREQ_OTP
*/
typedef uint32_t OTP_AutoWriteType;
#define OTP_AUTO_WRITE_MVK_MASK         (0x00000001UL)  /**< @brief MVK mask                */
#define OTP_AUTO_WRITE_MVK_SHIFT        (0UL)           /**< @brief MVK shift               */
#define OTP_AUTO_WRITE_DUK_MASK         (0x00000002UL)  /**< @brief DUK mask                */
#define OTP_AUTO_WRITE_DUK_SHIFT        (1UL)           /**< @brief DUK shift               */
#define OTP_AUTO_WRITE_MAC_MASK         (0x00000100UL)  /**< @brief MAC mask                */
#define OTP_AUTO_WRITE_MAC_SHIFT        (8UL)           /**< @brief MAC shift               */
#define OTP_AUTO_WRITE_IP_MASK          (0x00000200UL)  /**< @brief IP mask                 */
#define OTP_AUTO_WRITE_IP_SHIFT         (9UL)           /**< @brief IP shift                */
#define OTP_AUTO_WRITE_PROD_MASK        (0x00010000UL)  /**< @brief Production mode mask    */
#define OTP_AUTO_WRITE_PROD_SHIFT       (16UL)          /**< @brief Production mode shift   */
#define OTP_AUTO_WRITE_ACCESS_MASK      (0x00020000UL)  /**< @brief Access lock mask        */
#define OTP_AUTO_WRITE_ACCESS_SHIFT     (17UL)          /**< @brief Access lock shift       */
#define OTP_AUTO_WRITE_BOOTMODE_MASK    (0x00040000UL)  /**< @brief Boot mode mask          */
#define OTP_AUTO_WRITE_BOOTMODE_SHIFT   (18UL)          /**< @brief Boot mode shift         */
#define OTP_AUTO_WRITE_PATCH_MASK       (0x00080000UL)  /**< @brief patch mask              */
#define OTP_AUTO_WRITE_PATCH_SHIFT      (19UL)          /**< @brief patch shift             */
#define OTP_AUTO_WRITE_CUST_MASK        (0x00100000UL)  /**< @brief customer data mask      */
#define OTP_AUTO_WRITE_CUST_SHIFT       (20UL)          /**< @brief customer data shift     */

/**
    @brief OTP configuration

    @note This configuration is loaded and handled by Device monitor module
    so that it may redirect the request to HSM or non-HSM OTP appropriately

    @trace #BRCM_SWREQ_OTP
*/
typedef struct sOTP_CfgType {
    uint32_t                magic;          /**< @brief magic @xsd constant:OTP_MAGIC           */
    OTP_CfgVerType          version;        /**< @brief version @xsd constant:OTP_CFG_VER_1_0   */
    OTP_AutoWriteType       autoWrite;      /**< @brief Automatic write configuration           */
    uint32_t                reserved0;      /**< @brief reserved @xsd rsvd                      */
    OTP_MvkMsgType          mvk;            /**< @brief Manufacturer verification key           */
    uint32_t                reserved1[2UL]; /**< @brief reserved @xsd rsvd                      */
    uint8_t                 mac[6UL];       /**< @brief MAC address
                                                    @xsd type:mac;default:00:00:00:00:00:00     */
    uint16_t                reserved2;      /**< @brief reserved @xsd rsvd                      */
    OTP_IpCfgType           ip;             /**< @brief IP configuration                        */
    uint32_t                reserved3[3UL]; /**< @brief reserved @xsd rsvd                      */
    OTP_AccessModeType      access;         /**< @brief Disabled access types                   */
    uint16_t                reserved4;      /**< @brief reserved @xsd rsvd                      */
    OTP_BootModeType        bootMode;       /**< @brief Disabled boot modes                     */
    uint8_t                 customerData[OTP_RAW_MAX_DATA_SIZE];/**< @brief customer data
                                                @xsd hexdec;default:0x00                        */
    uint8_t                 reserved5[380UL];/**< @brief reserved @xsd rsvd                     */
} OTP_CfgType;
BCM_STATIC_SIZE_ASSERT(OTP_CfgType, 1024UL, 1024UL)


#endif /* NVM_OTP_TYPES_H */

/** @} */
