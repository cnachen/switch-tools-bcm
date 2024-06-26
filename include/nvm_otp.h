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
    @defgroup grp_nvm_abstract_otp OTP
    @ingroup grp_nvm_abstract

    @addtogroup grp_nvm_abstract_otp
    @{

    @file nvm_opt.h

    @brief NVM OTP Interface
    This file contains the interfaces for the NVM OTP

    @version 0.1 Initial version
*/

#ifndef NVM_OTP_H
#define NVM_OTP_H

#include <crypto_secotp.h>

/**
    @name OTP Module IDs
    @{
    @brief Architecture API IDs for OTP module
*/
#define BRCM_SWARCH_OTPM_GET_PRODMODE_PROC        (0x8300U)    /**< @brief #OTPM_GetProdMode         */
#define BRCM_SWARCH_OTPM_SET_PRODMODE_PROC        (0x8301U)    /**< @brief #OTPM_SetProdMode         */
#define BRCM_SWARCH_OTPM_READ_MAC_PROC            (0x8302U)    /**< @brief #OTPM_ReadMac             */
#define BRCM_SWARCH_OTPM_WRITE_MAC_PROC           (0x8303U)    /**< @brief #OTPM_WriteMac            */
#define BRCM_SWARCH_OTPM_READ_IPCFG_PROC          (0x8304U)    /**< @brief #OTPM_ReadIPCfg           */
#define BRCM_SWARCH_OTPM_WRITE_IPCFG_PROC         (0x8305U)    /**< @brief #OTPM_WriteIPCfg          */
#define BRCM_SWARCH_OTPM_GET_ACCESS_LOCK_PROC     (0x8306U)    /**< @brief #OTPM_GetAccessLock       */
#define BRCM_SWARCH_OTPM_SET_ACCESS_LOCK_PROC     (0x8307U)    /**< @brief #OTPM_SetAccessLock       */
#define BRCM_SWARCH_OTPM_SET_BOOTMODE_PROC        (0x8308U)    /**< @brief #OTPM_DisableBootModes    */
#define BRCM_SWARCH_OTPM_GET_PATCH_VER_PROC       (0x8309U)    /**< @brief #OTPM_GetPatchVersion     */
#define BRCM_SWARCH_OTPM_COMMIT_PATCH_VER_PROC    (0x830AU)    /**< @brief #OTPM_CommitPatchVersion  */
#define BRCM_SWARCH_OTPM_READ_CUST_DATA_PROC      (0x830BU)    /**< @brief #OTPM_ReadCustData        */
#define BRCM_SWARCH_OTPM_WRITE_CUST_DATA_PROC     (0x830CU)    /**< @brief #OTPM_WriteCustData       */
#define BRCM_SWARCH_OTPM_DUK_MSG_TYPE             (0x830DU)    /**< @brief #OTPM_DukMsgType          */
#define BRCM_SWARCH_OTPM_STACKING_INFO_TYPE       (0x830EU)    /**< @brief #OTPM_StackingInfoType    */
#define BRCM_SWARCH_OTPM_READ_STACKING_INFO_PROC  (0x830FU)    /**< @brief #OTPM_ReadStackingInfo    */
#define BRCM_SWARCH_OTPM_WRITE_STACKING_INFO_PROC (0x8310U)    /**< @brief #OTPM_WriteStackingInfo   */

#define BRCM_SWARCH_OTPM_BOOTMODE_TYPE            (0x8341U)    /**< @brief #OTPM_BootModeType        */
#define BRCM_SWARCH_OTPM_ALTMEM_GLOBAL            (0x8342U)    /**< @brief #OTPM_AltMem              */
#define BRCM_SWARCH_OTPM_READ_PUBKEY_PROC         (0x8343U)    /**< @brief #OTPM_ReadPubKey          */
#define BRCM_SWARCH_OTPM_READ_DEVUNIQKEY_PROC     (0x8345U)    /**< @brief #OTPM_ReadDevUniqKey      */
#define BRCM_SWARCH_OTPM_READ_TC10_CONFIG_PROC    (0x8346U)    /**< @brief #OTPM_ReadTC10Config      */
#define BRCM_SWARCH_OTPM_GET_BOOTMODE_PROC        (0x8347U)    /**< @brief #OTPM_GetEnabledBootModes */
#define BRCM_SWARCH_OTPM_PTPUBKEY_GLOBAL          (0x8348U)    /**< @brief #OTPM_PTPubKey            */
#define BRCM_SWARCH_OTPM_PTRSA256_GLOBAL          (0x8349U)    /**< @brief #OTPM_PTRsa256            */
#define BRCM_SWARCH_OTPM_CMD_TYPE                 (0x834AU)    /**< @brief #OTPM_CmdIDType           */
#define BRCM_SWARCH_OTPM_MACRO                    (0x834BU)    /**< @brief #OTPM_ID                  */
#define BRCM_SWARCH_OTPM_READ_MSG_TYPE            (0x834CU)    /**< @brief #OTPM_ReadMsgType         */
#define BRCM_SWARCH_OTPM_WRITE_MSG_TYPE           (0x834DU)    /**< @brief #OTPM_WriteMsgType        */
#define BRCM_SWARCH_OTPM_IPCFG_MSG_TYPE           (0x834EU)    /**< @brief #OTPM_IPCfgMsgType        */
#define BRCM_SWARCH_OTPM_PROD_MSG_TYPE            (0x834FU)    /**< @brief #OTPM_ProdMsgType         */
#define BRCM_SWARCH_OTPM_MSG_UNION_TYPE           (0x8350U)    /**< @brief #OTPM_MsgUnionType        */
#define BRCM_SWARCH_OTPM_MSG_TYPE                 (0x8351U)    /**< @brief #OTPM_MsgType             */
#define BRCM_SWARCH_OTPM_ACCESS_LOCK_MSG_TYPE     (0x8352U)    /**< @brief #OTPM_AccessLockMsgType   */
#define BRCM_SWARCH_OTPM_ACCESS_MODE_TYPE         (0x8353U)    /**< @brief #OTPM_AccessModeType      */
#define BRCM_SWARCH_OTPM_ACCESS_STATUS_TYPE       (0x8354U)    /**< @brief #OTPM_AccessStatusType    */
#define BRCM_SWARCH_OTPM_BOOT_MODE_MSG_TYPE       (0x8355U)    /**< @brief #OTPM_BootModeMsgType     */
#define BRCM_SWARCH_OTPM_PATCH_VER_TYPE           (0x8356U)    /**< @brief #OTPM_PatchVerType        */
#define BRCM_SWARCH_OTPM_PATCH_VER_MSG_TYPE       (0x8357U)    /**< @brief #OTPM_PatchVerMsgType     */
#define BRCM_SWARCH_OTPM_DUK_MAX_SIZE_MACRO       (0x8358U)    /**< @brief #OTPM_DUK_MAX_SIZE        */
#define BRCM_SWARCH_OTPM_WRITE_TC10_CONFIG_PROC   (0x8359U)    /**< @brief #OTPM_WriteTC10Config     */
#define BRCM_SWARCH_OTPM_INT_GET_PATCH_VER_PROC   (0x835AU)    /**< @brief #OTPM_IntGetPatchVersion  */

/** @} */

/**
    @brief DUK size

    @trace #BRCM_SWREQ_OTPM
 */
#define OTPM_DUK_MAX_SIZE (32UL)

/**
    @brief OTP Module Macro

    @trace #BRCM_SWREQ_OTPM
 */
#define OTPM_ID(x)                         BCM_MSG(BCM_GROUPID_NVM, BCM_OTM_ID, (x)) /**< @brief OTPM ID construction macro */
#define OTPM_RPC_MAX_DATA_SIZE             (256UL)
#define OTPM_RPC_MAX_PAYLOAD_SIZE          (OTPM_RPC_MAX_DATA_SIZE + 32UL)
#define OTPM_MAGIC                         (0x4F54504DUL)                              /**< @brief ASCII "UPDT" */

/**
    @brief OTP Module Command ID Type

    @trace #BRCM_SWREQ_OTPM
 */
typedef uint32_t OTPM_CmdIDType;            /**< @brief typedef for otpm cmdID */
#define OTPM_CMD_READ                       OTPM_ID(0x1UL) /**< @brief #OTPM_ReadMsgType  */
#define OTPM_CMD_WRITE                      OTPM_ID(0x2UL) /**< @brief #OTPM_WriteMsgType */
#define OTPM_CMD_MAC_READ                   OTPM_ID(0x3UL) /**< @brief #OTPM_ReadMsgType  */
#define OTPM_CMD_MAC_WRITE                  OTPM_ID(0x4UL) /**< @brief #OTPM_WriteMsgType */
#define OTPM_CMD_IPCFG_READ                 OTPM_ID(0x5UL) /**< @brief #OTPM_IPCfgMsgType */
#define OTPM_CMD_IPCFG_WRITE                OTPM_ID(0x6UL) /**< @brief #OTPM_IPCfgMsgType */
#define OTPM_CMD_ST_INFO_READ               OTPM_ID(0x7UL) /**< @brief #OTPM_StackingInfoType */
#define OTPM_CMD_ST_INFO_WRITE              OTPM_ID(0x8UL) /**< @brief #OTPM_StackingInfoType */

#define OTPM_CMD_CUST_READ                  OTPM_ID(0x10UL) /**< @brief #OTPM_ReadMsgType */
#define OTPM_CMD_CUST_WRITE                 OTPM_ID(0x11UL) /**< @brief #OTPM_WriteMsgType */

#define OTPM_CMD_PROD_MODE_GET              OTPM_ID(0x81UL) /**< @brief #OTPM_ProdMsgType  */
#define OTPM_CMD_PROD_MODE_SET              OTPM_ID(0x82UL) /**< @brief #OTPM_ProdMsgType  */
#define OTPM_CMD_ACCESS_LOCK_GET            OTPM_ID(0x83UL) /**< @brief #OTPM_AccessLockMsgType  */
#define OTPM_CMD_ACCESS_LOCK_SET            OTPM_ID(0x84UL) /**< @brief #OTPM_AccessLockMsgType  */

#define OTPM_CMD_BOOT_MODE_GET              OTPM_ID(0x90UL) /**< @brief #OTPM_BootModeMsgType  */
#define OTPM_CMD_BOOT_MODE_SET              OTPM_ID(0x91UL) /**< @brief #OTPM_BootModeMsgType  */

#define OTPM_CMD_PATCH_VERSION_GET          OTPM_ID(0xA0UL) /**< @brief #OTPM_PatchVerMsgType  */
#define OTPM_CMD_PATCH_VERSION_COMMIT       OTPM_ID(0xA1UL) /**< @brief #OTPM_PatchVerMsgType  */

#define OTPM_CMD_DUK_READ                   OTPM_ID(0xB0UL) /**< @brief #OTPM_DukMsgType  */
#define OTPM_CMD_DUK_WRITE                  OTPM_ID(0xB1UL) /**< @brief #OTPM_DukMsgType */

/**
    @brief OTP Module Interface ID Type
    @{

    @trace #BRCM_SWREQ_OTPM
 */
typedef uint16_t OTPM_AccessModeType;            /**< @brief typedef for otpm interface ID */
#define OTPM_ACCESS_MODE_SPI                     (0x01U)
#define OTPM_ACCESS_MODE_MDIO                    (0x02U)
#define OTPM_ACCESS_MODE_PCIE                    (0x04U)
#define OTPM_ACCESS_MODE_ALL                     (0xFFU)
#define OTPM_ACCESS_MODE_MAX_COUNT               (0x8U)
_Static_assert(8U >= OTPM_ACCESS_MODE_MAX_COUNT,
    "Maximum access mode count should be less or equal to 8U");
/** @} */

/**
    @brief OTP Module Access status Type
    @{

    @trace #BRCM_SWREQ_OTPM
 */
typedef uint32_t OTPM_AccessStatusType;          /**< @brief typedef for otpm interface ID */
#define OTPM_ACCESS_STATUS_UNKNOWN               (0x00UL) /**< @brief  Group Mode Access Status is unknown(Query individually) */
#define OTPM_ACCESS_STATUS_UNLOCK                (0x01UL) /**< @brief  Group/Individual Access Status is Unlocked */
#define OTPM_ACCESS_STATUS_LOCK                  (0x02UL) /**< @brief  Group/Individual Access Status is Locked */
/** @} */

/**
    @name Boot Mode flags
    @{
    @brief Boot Mode flags

    @trace #BRCM_SWREQ_OTPM
 */
typedef uint32_t OTPM_BootModeType;                     /**< @brief Bootmode bit flags  */
#define OTPM_BOOTMODE_FLASH         (1UL)               /**< @brief Flash Boot          */
#define OTPM_BOOTMODE_TFTP          (2UL)               /**< @brief TFTP Boot           */
#define OTPM_BOOTMODE_IPC           (4UL)               /**< @brief IPC Boot            */
/** @} */

/**
    @brief OTP Patch Version Type
    @{

    @trace #BRCM_SWREQ_OTPM
 */
typedef uint32_t OTPM_PatchVerType;              /**< @brief typedef for patch version */
#define OTPM_PATCH_VER_NOT_FOUND                 (0x00UL)       /**< @brief  No version found*/
#define OTPM_PATCH_VER_UNDETERMINE               (0xFFFFFFFFUL) /**< @brief  OTP Patch is out of sync with Sw Patch*/
/** @} */

/**
    @brief OTP Module RPC Read Msg structure

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_ReadMsgType {
    uint32_t            rsvd0;                              /**< @brief rsvd0  */
    uint32_t            rsvd1;                              /**< @brief rsvd1  */
    uint32_t            rsvd2;                              /**< @brief rsvd2  */
    uint32_t            len;                                /**< @brief Read data length */
    uint8_t             bufOut[OTPM_RPC_MAX_DATA_SIZE];     /**< @brief Input data buffer */
} OTPM_ReadMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_ReadMsgType, 272UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP Module RPC Write Msg structure

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_WriteMsgType {
    uint32_t            rsvd0;                              /**< @brief rsvd0  */
    uint32_t            rsvd1;                              /**< @brief rsvd1  */
    uint32_t            rsvd2;                              /**< @brief rsvd2  */
    uint32_t            len;                                /**< @brief write data length */
    uint8_t             bufIn[OTPM_RPC_MAX_DATA_SIZE];      /**< @brief  Input data buffer */
} OTPM_WriteMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_WriteMsgType, 272UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP Module RPC IP Addr Msg structure

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_IPCfgMsgType {
    uint32_t            mstSlvSel;                        /**< @brief 0: Master, 1: Slave-1  */
    uint32_t            ipAddr;                           /**< @brief IP address to be used for private communication */
    uint32_t            gwIPAddr;                         /**< @brief Gateway IP address to be used for private communication */
    uint32_t            bootInfo;                         /**< @brief 24 bits of application specific information*/
    uint8_t             netmask;                          /**< @brief Netmask to be used for private communication */
    uint32_t            tftpServerAddr;                   /**< @brief TFTP server IP address */
} OTPM_IPCfgMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_IPCfgMsgType, 24UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Production Mode Set/Get

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_ProdMsgType {
    uint32_t           prodStatus;                       /**< @brief Production mode status*/
} OTPM_ProdMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_ProdMsgType, 4UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Access Lock Status

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_AccessLockMsgType {
    OTPM_AccessModeType     accessMode;                      /**< @brief Input: Access Mode */
    OTPM_AccessStatusType   status;                          /**< @brief OutPut: Access Lock status */
} OTPM_AccessLockMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_AccessLockMsgType, 8UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Boot Mode

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_BootModeMsgType {
    OTPM_BootModeType     bootMode;                      /**< @brief Input/Output: Boot Mode */
} OTPM_BootModeMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_BootModeMsgType, 4UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Patching based on SW Version

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_PatchVerMsgType {
    uint32_t     swVersion;                           /**< @brief Output: Available Patch Version
                                                           <Arch(24:31), Major(16:23), Minor(8:15), Custom(0:7)> */
    uint32_t     otpVersion;                          /**< @brief OutPut: Current OTP Patch Version
                                                           <Arch(24:31), Major(16:23), Minor(8:15), Custom(0:7)> */
} OTPM_PatchVerMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_PatchVerMsgType, 8UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Message to program a DUK into the OTP

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_DukMsgType {
    uint32_t keyType;
    uint8_t  key[OTPM_DUK_MAX_SIZE];
} OTPM_DukMsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_DukMsgType, 36UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Stacking info structure for OTP command

    @trace #BRCM_SWREQ_OTPM
 */
typedef struct sOTPM_StackingInfoType {
    uint8_t            stackingEn; /**< @brief Stacking Enable, 0: Disable, 1: Enable */
    uint8_t            stackPort0; /**< @brief Stacking Port 0 info                   */
    uint8_t            stackPort1; /**< @brief Stacking Port 1 info                   */
    uint8_t            impPort;    /**< @brief Port number enabled in IMP mode (port8) */
    uint16_t           vlan;       /**< @brief VLAN Id to be used for private communication */
    uint16_t           rsvd;       /**< @brief Reserved */
} OTPM_StackingInfoType;
BCM_STATIC_SIZE_ASSERT(OTPM_StackingInfoType, 8UL, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTP Module Command Handle

    @trace #BRCM_SWREQ_OTPM
*/
typedef union uOTPM_MsgUnionType {
    OTPM_ReadMsgType       readMsg;
    OTPM_WriteMsgType      writeMsg;
    SECOTP_MvkMsgType      mvkMsg;                         /**< @brief Public key message */
    OTPM_IPCfgMsgType      ipCfgMsg;
    OTPM_ProdMsgType       prodModeMsg;
    OTPM_AccessLockMsgType accessLockMsg;
    OTPM_BootModeMsgType   bootModeMsg;
    OTPM_PatchVerMsgType   patchVerMsg;
    OTPM_DukMsgType        dukMsg;
    OTPM_StackingInfoType  stackingInfo;
    uint32_t               data[OTPM_RPC_MAX_PAYLOAD_SIZE/4];
} OTPM_MsgUnionType;
BCM_STATIC_SIZE_ASSERT(OTPM_MsgUnionType, OTPM_RPC_MAX_PAYLOAD_SIZE, OTPM_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief OTPM Msg Type

    @trace #BRCM_SWREQ_OTPM
*/
typedef struct sOTPM_MsgType {
    uint32_t             magic;
    OTPM_CmdIDType       cmd;
    uint32_t             cmdLen;
    int32_t              status;
    OTPM_MsgUnionType    u;
} OTPM_MsgType;
BCM_STATIC_SIZE_ASSERT(OTPM_MsgType, 304UL, 304UL)


/**
    @brief OTP Alternet Memory

    @trace #BRCM_SWREQ_OTPM
 */
#ifdef OTPM_ALT_MEM_ROWS_COUNT
extern uint32_t OTPM_AltMem[OTPM_ALT_MEM_ROWS_COUNT];
#endif

/**
    @brief Read OTP PubKey from Flash PT

    @trace #BRCM_SWREQ_OTPM
 */
extern uint8_t OTPM_PTPubKey[256UL];

/**
    @brief Hold RSA256 data of #OTPM_PTPubKey

    @trace #BRCM_SWREQ_OTPM
 */
extern uint8_t OTPM_PTRsa256[32UL];

/** @brief Read Public Key

  Interface to read public key from OTP rows

  @behavior Sync, None re-entrant

  @pre TBD

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[out]   aKey       Pointer to the memory where public key will be copied
  @param[in]    aBufSize   Size of the input key buffer
  @param[out]   aKeyType   Actual key type read.
  @param[out]   aKeySize   Actual key size read.

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              OTP public key read was successful
  @retval      #BCM_ERR_DATA_INTEG      Public key is Invalid
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOT_FOUND       Not a secure variant
  @retval      #BCM_ERR_NOMEM           aBufSize is less than Public key size
  @retval      #BCM_ERR_NOSUPPORT       Requested operation not supported.
  @retval      #BCM_ERR_INVAL_PARAMS    aKey is not valid
                                        aKeyType is NULL
                                        aKeySize is NULL

  @post TBD

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_ReadPubKey(uint8_t *const aKey, uint32_t aBufSize, uint32_t * const aKeyType, uint32_t * const aKeySize);

/** @brief Read the device unique Key

  Interface to read the DUK from OTP rows

  @behavior Sync, None re-entrant

  @pre TBD

  @param[in]    aBufSize   Size of the input key buffer
  @param[out]   aKey       Pointer to the memory where the DUK will be copied
  @param[out]   aKeyType   Actual key type read.

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              DUK read complete
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOSUPPORT       DUK not supported on this platform
  @retval      #BCM_ERR_NOT_FOUND       No DUK programmed
  @retval      #BCM_ERR_INVAL_PARAMS    aKey is not valid
                                        aKeyType is NULL
                                        aBufSize is not big enough

  @post TBD

  @trace #BRCM_SWREQ_OTPM

  @limitations
*/
int32_t OTPM_ReadDevUniqKey(const uint32_t aBufSize, uint8_t *const aKey, uint32_t *const aKeyType);

/** @brief Read TC10 Configuration data

  Interface to read TC10 Configuration from OTP rows

  @behavior Sync, None re-entrant

  @pre TBD

  @param[out]   aMemAddr    Buffer where the data will be copied
  @param[in]    aBufSize    Size of the input buffer
  @param[out]   aFilledSize Actual TC10 config size read

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              OTP switch config data read was successful
  @retval      #BCM_ERR_DATA_INTEG      TC10 configuration is Invalid
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOMEM           aBufSize is less than the TC10 Config size
  @retval      #BCM_ERR_NOSUPPORT       Not supported
  @retval      #BCM_ERR_INVAL_PARAMS    aMemAddr is NULL
  @post TBD

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_ReadTC10Config(uint32_t *const aMemAddr,
                            uint32_t aBufSize,
                            uint32_t *const aFilledSize);

/** @brief Write TC10 Config data to OTP

    @behavior Sync, None re-entrant

    @pre None

    @param[in]     aCfgData    TC10 Config data
    @param[in]     aCfgSize    Number of bytes in the config data

    Return values are documented in reverse-chronological order

    @retval      #BCM_ERR_OK              TC10 config written to the OTP
    @retval      #BCM_ERR_UNKNOWN         Error while writing the OTP
    @retval      #BCM_ERR_NOSUPPORT       Not supported in this platform

    @post TC10 Config written to the OTP

  @trace #BRCM_SWREQ_OTPM
*/
int32_t OTPM_WriteTC10Config(uint32_t const * const aCfgData,
                             uint32_t aCfgSize);

/** @brief Get Enabled boot-modes

  Interface to get all the enabled boot modes

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[out]   aBootModes    Bit flags for each enabled boot modes

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Boot modes read successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS aBootModes is NULL
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_GetEnabledBootModes(BCM_HandleType aHdl, OTPM_BootModeType *const aBootModes);

/** @brief Set Disable boot-modes

  Interface to set boot modes disable

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[out]   aBootModes    Bit flags to Disable boot modes

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Boot modes read successfully
  @retval      #BCM_ERR_INVAL_PARAMS aBootModes is Invalid
  @retval      #BCM_ERR_NOSUPPORT    aBootModes is not supported
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_DisableBootModes(BCM_HandleType aHdl, OTPM_BootModeType aBootModes);

/** @brief Get Production Mode

  Reads the production mode bits from the OTP and returns status.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[out]   aEnabled    Pointer to hold the status of Production mode(TRUE/FALSE)

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Production modes read successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl or aEnable is NULL
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_GetProdMode(BCM_HandleType aHdl, uint32_t *const aEnabled);

/** @brief Set Production Mode

  Write the production mode bits in the OTP.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - 0ULL for Internal Consumption

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Production modes set successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl

  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_SetProdMode(BCM_HandleType aHdl);

/** @brief Read MAC Address

  Read MAC Address from the OTP.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - 0ULL for Internal Consumption
  @param[out]   aMACBuf     Pointer to hold the MAC Address in LE format
  @param[out]   aIdx        Pointer to hold the Current Valid MAC Index

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           MAC read successfully
  @retval      #BCM_ERR_DATA_INTEG   OTP MAC row is corrupted
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOT_FOUND    MAC address is not programmed
  @retval      #BCM_ERR_INVAL_PARAMS aHdl or aMACBuf is Invalid

  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_ReadMac(BCM_HandleType aHdl, uint8_t * const aMACBuf, uint32_t *const aIdx);

/** @brief Write MAC Address

  Write the MAC Address in the available OTP Index.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - 0ULL for Internal Consumption
  @param[in]   aMACBuf     Pointer to hold the MAC Address in LE format

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              OTP MAC data write is successful
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS    aHdl or aMACBuf is Invalid


  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_WriteMac(BCM_HandleType aHdl, const uint8_t *const aMACBuf);

/** @brief Read IP Configuration

  Reads IP Configuration from the OTP.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - 0ULL for Internal Consumption
  @param[out]   aIPCfg      Structure Pointer to hold the IP Address Config

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              IP config data read is successful
  @retval      #BCM_ERR_DATA_INTEG      IP OTP row is corrupted
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOSUPPORT       Requested operation not supported
  @retval      #BCM_ERR_INVAL_PARAMS    Invalid aHdl or aIPCfg is NULL


  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_ReadIPCfg(BCM_HandleType aHdl, OTPM_IPCfgMsgType *const aIPCfg);

/** @brief Write IP Configuration

  Write the IP Configuration in the available OTP Index.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - 0ULL for Internal Consumption
  @param[in]   aIPCfg      Structure Pointer to hold the IP Address Config

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK              IP config data write is successful
  @retval      #BCM_ERR_DATA_INTEG      IP OTP row is corrupted
  @retval      #BCM_ERR_UNKNOWN         Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOSUPPORT       Requested operation not supported
  @retval      #BCM_ERR_INVAL_PARAMS    Invalid aHdl or aIPCfg is NULL


  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_WriteIPCfg(BCM_HandleType aHdl, const OTPM_IPCfgMsgType* const aIPCfg);

/** @brief Get Access Lock Status

  Reads the Access mode bits from the OTP and returns status.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]     aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[in/out] aAccessLock Pointor of Access Lock Info

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Access status read successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl or aAccessLock is NULL
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_GetAccessLock(BCM_HandleType aHdl, OTPM_AccessLockMsgType* const aAccessLock);

/** @brief Set Access Lock

  Write the Access mode bits in the OTP.

  @behavior Sync, None re-entrant

  @pre None

  @param[in]    aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
                                - NULL for Internal Consumption
  @param[in]    aAccessLock Pointor of Access Lock Info

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Access status Locked successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl or aAccessLock is NULL
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_SetAccessLock(BCM_HandleType aHdl, OTPM_AccessLockMsgType* const aAccessLock);

/** @brief Get OTP Patch Version

  Reads Programmed OTP patch version
  and Available patch version to program

  @behavior Sync, None re-entrant

  @pre None

  @param[in]     aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
  @param[out] aPatchVer      Pointor of #OTPM_PatchVerMsgType

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Patch version read successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl or OTPM_PatchVerMsgType is NULL
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_GetPatchVersion(BCM_HandleType aHdl, OTPM_PatchVerMsgType* const aPatchVer);

/** @brief Commit OTP Patch Version

  Program the latest Patch Version

  @behavior Sync, None re-entrant

  @pre None

  @param[in]     aHdl        Connection handle
  - RPC Handle for Host
  - Msg Handle for Module

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Patch version commit successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_NOT_FOUND    No Valid OTP version found to commit
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_CommitPatchVersion(BCM_HandleType aHdl);

/** @brief Read Customer Data

  Reads Customer Data from OTP

  @behavior Sync, None re-entrant

  @pre None

  @param[in]     aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
  @param[out]    aCustData   Pointor of #OTPM_ReadMsgType

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Custom Data read successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl or OTPM_ReadMsgType is NULL
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_ReadCustData(BCM_HandleType aHdl, OTPM_ReadMsgType* const aCustData);

/** @brief Write Customer Data

  Write Customer Data from OTP

  @behavior Sync, None re-entrant

  @pre None

  @param[in]     aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
  @param[in]    aCustData   Pointor of #OTPM_WriteMsgType

  Return values are documented in reverse-chronological order

  @retval      #BCM_ERR_OK           Custom Data read successfully
  @retval      #BCM_ERR_UNKNOWN      Integration error or OTP Controller failure
  @retval      #BCM_ERR_INVAL_PARAMS Invalid length of Custom Data
  @retval      #BCM_ERR_INVAL_PARAMS Invalid aHdl or OTPM_ReadMsgType is NULL
  @post None

  @trace #BRCM_SWREQ_OTPM

  @limitations

*/
int32_t OTPM_WriteCustData(BCM_HandleType aHdl, OTPM_WriteMsgType* const aCustData);

/** @brief Get Patch Version commited in OTP and latest available Patch Version to commit

    @behavior Sync, None re-entrant

    @pre OTP Module is initialized

    @param[out]    aOtpPatchVer   OTP Patch version
    @param[out]    aSwPatchVer    Software Patch Version

    Return values are documented in reverse-chronological order

    @retval      #BCM_ERR_OK          Patch Version fetched successfully
    @retval      #BCM_ERR_UNKNOWN     Invalid OTP patch configuration

    @post None

    @trace #BRCM_SWREQ_OTPM
*/
int32_t OTPM_IntGetPatchVersion(uint32_t* aOtpPatchVer, uint32_t* aSwPatchVer);

/** @brief Read Valid Stacking Data

    Interface to read the valid stacking info stored in the OTP
    If multiple stacking info are stored. It retrieves the
    currently active one (last written)

    @behavior Sync, None re-entrant

    @pre OTP Module is initialized

    @param[in]     aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
    @param[out]   aStackinInfo  Parsed stacking info

    Return values are documented in reverse-chronological order

    @retval      #BCM_ERR_OK              Valid stacking data returned
    @retval      #BCM_ERR_NOT_FOUND       All stacking row is corrupted or zero

    @post None

    @trace #BRCM_SWREQ_OTPM
*/
int32_t OTPM_ReadStackingInfo(BCM_HandleType aHdl,
                              OTPM_StackingInfoType * const aStackingInfo);

/** @brief Write Stacking Data to the OTP row

    This API searches for a free Stacking Info slot
    and writes the data

    @behavior Sync, None re-entrant

    @pre OTP Module is initialized

    @param[in]     aHdl        Connection handle
                                - RPC Handle for Host
                                - Msg Handle for Module
    @param[in]   aStackinInfo  Stacking info to be written

    Return values are documented in reverse-chronological order

    @retval      #BCM_ERR_OK              Stacking info written successfully
    @retval      #BCM_ERR_INVAL_PARAMS    aStackingInfo is NULL or
                                          one of the parameter is out of range
    @retval      #BCM_ERR_NOMEM           No free slots available

    @post Stacking info written to the OTP

    @trace #BRCM_SWREQ_OTPM
*/
int32_t OTPM_WriteStackingInfo(BCM_HandleType aHdl,
                               OTPM_StackingInfoType const * const aStackingInfo);

#endif /* NVM_OTP_H */

/** @} */
