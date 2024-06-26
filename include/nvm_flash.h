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

/** @defgroup grp_nvm_flash_ifc FLASH Interface
    @ingroup grp_nvm_abstract

    @addtogroup grp_nvm_flash_ifc
    @{

    @file nvm_flash.h
    @brief Interface for FLASH Abstract

    @version 0.1 Initial version
*/

#ifndef NVM_FLASH_H
#define NVM_FLASH_H

#include <bcm_comp.h>
#include <bcm_utils.h>
#include <nvm_flash_types.h>

/**
    @name NVM FLASH Abstract Interface IDs
    @{
    @brief Interface IDs for NVM FLASH Abstract

*/
#define BRCM_SWARCH_FLASH_ERASESECTOR_CMD_PROC         (0x8200U)    /**< @brief #FLASH_EraseSector         */
#define BRCM_SWARCH_FLASH_WRITEPAGE_CMD_PROC           (0x8201U)    /**< @brief #FLASH_WritePage           */
#define BRCM_SWARCH_FLASH_READPAGE_CMD_PROC            (0x8202U)    /**< @brief #FLASH_ReadPage            */

#define BRCM_SWARCH_FLASH_RPC_MAX_MACRO                (0x8210U)    /**< @brief #FLASH_RPC_MAX_DATA_SIZE   */
#define BRCM_SWARCH_FLASH_CMD_TYPE                     (0x8211U)    /**< @brief #FLASH_CmdIDType           */
#define BRCM_SWARCH_FLASH_RPC_READ_INFO_TYPE           (0x8212U)    /**< @brief #FLASH_RpcReadInfoType     */
#define BRCM_SWARCH_FLASH_RPC_WRITE_INFO_TYPE          (0x8213U)    /**< @brief #FLASH_RpcWriteInfoType    */
#define BRCM_SWARCH_FLASH_RPC_ERASE_INFO_TYPE          (0x8214U)    /**< @brief #FLASH_RpcEraseInfoType    */
#define BRCM_SWARCH_FLASH_HANDLE_TYPE                  (0x8215U)    /**< @brief #FLASH_HandleType          */
#define BRCM_SWARCH_FLASH_IMGL_CMD_INFO_TYPE           (0x8216U)    /**< @brief #FLASH_ImglCmdInfoType     */
#define BRCM_SWARCH_FLASH_MAX_PAGE_SIZE_MACRO          (0x8217U)    /**< @brief #FLASH_MAX_PAGE_SIZE       */
#define BRCM_SWARCH_FLASH_MAX_FILESIZE_MACRO           (0x8218U)    /**< @brief #FLASH_MAX_FILESIZE        */
#define BRCM_SWARCH_FLASH_MAX_SECTOR_MACRO             (0x8219U)    /**< @brief #FLASH_MAX_SECTOR          */
#define BRCM_SWARCH_FLASH_MAX_PT_COUNT_MACRO           (0x821AU)    /**< @brief #FLASH_MAX_PT_COUNT        */
#define BRCM_SWARCH_FLASH_ID_OF_MACRO                  (0x821BU)    /**< @brief #FLASH_ID_OF               */
#define BRCM_SWARCH_FLASH_MAX_SFDP_PARAMETERS_MACRO    (0x821CU)    /**< @brief #FLASH_MAX_SFDP_PARAMETERS */
#define BRCM_SWARCH_FLASH_SFDP_DWORD_TYPE              (0x821DU)    /**< @brief #FLASH_SFDPDWordType       */
#define BRCM_SWARCH_FLASH_BASIC_INFO_TYPE              (0x821EU)    /**< @brief #FLASH_BasicInfoType       */
#define BRCM_SWARCH_FLASH_MEM_DENSITY_TYPE             (0x821FU)    /**< @brief #FLASH_MemDensityType      */
#define BRCM_SWARCH_FLASH_FAST_READ0_TYPE              (0x8220U)    /**< @brief #FLASH_FastRead0Type       */
#define BRCM_SWARCH_FLASH_FAST_READ1_TYPE              (0x8221U)    /**< @brief #FLASH_FastRead1Type       */
#define BRCM_SWARCH_FLASH_FAST_READ2_TYPE              (0x8222U)    /**< @brief #FLASH_FastRead2Type       */
#define BRCM_SWARCH_FLASH_FAST_READ3_TYPE              (0x8223U)    /**< @brief #FLASH_FastRead3Type       */
#define BRCM_SWARCH_FLASH_FAST_READ4_TYPE              (0x8224U)    /**< @brief #FLASH_FastRead4Type       */
#define BRCM_SWARCH_FLASH_ERASE_INFO0_TYPE             (0x8225U)    /**< @brief #FLASH_EraseInfo0Type      */
#define BRCM_SWARCH_FLASH_ERASE_INFO1_TYPE             (0x8226U)    /**< @brief #FLASH_EraseInfo1Type      */
#define BRCM_SWARCH_FLASH_TIME_INFO0_TYPE              (0x8227U)    /**< @brief #FLASH_TimeInfo0Type       */
#define BRCM_SWARCH_FLASH_TIME_INFO1_TYPE              (0x8228U)    /**< @brief #FLASH_TimeInfo1Type       */
#define BRCM_SWARCH_FLASH_SUSP_RESUME0_TYPE            (0x8229U)    /**< @brief #FLASH_SuspResume0Type     */
#define BRCM_SWARCH_FLASH_SUSP_RESUME1_TYPE            (0x822AU)    /**< @brief #FLASH_SuspResume1Type     */
#define BRCM_SWARCH_FLASH_POWER_DOWN_TYPE              (0x822BU)    /**< @brief #FLASH_PowerDownType       */
#define BRCM_SWARCH_FLASH_QUAD_INFO_TYPE               (0x822CU)    /**< @brief #FLASH_QuadInfoType        */
#define BRCM_SWARCH_FLASH_ADDR_MODE_TYPE               (0x822DU)    /**< @brief #FLASH_AddrModeType        */
#define BRCM_SWARCH_FLASH_FAST_READ5_TYPE              (0x822EU)    /**< @brief #FLASH_FastRead5Type       */
#define BRCM_SWARCH_FLASH_OCTAL_INFO0_TYPE             (0x822FU)    /**< @brief #FLASH_OctalInfo0Type      */
#define BRCM_SWARCH_FLASH_OCTAL_INFO1_TYPE             (0x8230U)    /**< @brief #FLASH_OctalInfo1Type      */
#define BRCM_SWARCH_FLASH_MAX_SPEED_TYPE               (0x8231U)    /**< @brief #FLASH_MaxSpeedType        */
#define BRCM_SWARCH_FLASH_FAST_READ6_TYPE              (0x8232U)    /**< @brief #FLASH_FastRead6Type       */
#define BRCM_SWARCH_FLASH_FAST_READ7_TYPE              (0x8233U)    /**< @brief #FLASH_FastRead7Type       */
#define BRCM_SWARCH_FLASH_FAST_READ8_TYPE              (0x8234U)    /**< @brief #FLASH_FastRead8Type       */
#define BRCM_SWARCH_FLASH_DEVICE_PARAM_TYPE            (0x8235U)    /**< @brief #FLASH_DevCapabiltiesType    */
#define BRCM_SWARCH_FLASH_GET_DEV_CAPABILTIES_PROC     (0x8236U)    /**< @brief #FLASH_GetDevCapabilties     */
#define BRCM_SWARCH_FLASH_SFDP_PARAM_ID_TYPE           (0x8237U)    /**< @brief #FLASH_SFDPParamIDType          */
#define BRCM_SWARCH_FLASH_MANUFACTURER_ID_TYPE         (0x8238U)    /**< @brief #FLASH_ManufacturerIDType       */
#define BRCM_SWARCH_FLASH_MEMORY_TYPE                  (0x8239U)    /**< @brief #FLASH_MemoryType               */
#define BRCM_SWARCH_FLASH_MEMORY_DENSITY_TYPE          (0x823AU)    /**< @brief #FLASH_MemoryDensityType        */
#define BRCM_SWARCH_FLASH_DEVICE_ID_TYPE               (0x823BU)    /**< @brief #FLASH_DeviceIDType             */
#define BRCM_SWARCH_FLASH_MAX_PARAMETERS_ID_LIST_MACRO (0x823CU)    /**< @brief #FLASH_MAX_PARAMETERS_ID_LIST   */
#define BRCM_SWARCH_FLASH_ID_TYPE                      (0x823DU)    /**< @brief #FLASH_IDType                   */
#define BRCM_SWARCH_FLASH_FLASHID_MSG_TYPE             (0x823EU)    /**< @brief #FLASH_FlashIDMsgType           */
#define BRCM_SWARCH_FLASH_PARAMETERS_INFO_TYPE         (0x823FU)    /**< @brief #FLASH_ParametersInfoType       */
#define BRCM_SWARCH_FLASH_PARAMETERS_INFO_MSG_TYPE     (0x8240U)    /**< @brief #FLASH_ParametersInfoMsgType    */
#define BRCM_SWARCH_FLASH_READ_PARAMETER_DATA_TYPE     (0x8241U)    /**< @brief #FLASH_ReadParameterDataType    */
#define BRCM_SWARCH_FLASH_READ_PARAMETER_DATA_MSG_TYPE (0x8242U)    /**< @brief #FLASH_ReadParameterDataMsgType */
#define BRCM_SWARCH_FLASH_GET_FLS_ID_PROC              (0x8243U)    /**< @brief #FLASH_GetFlsID                 */
#define BRCM_SWARCH_FLASH_GET_PARAM_INFO_PROC          (0x8244U)    /**< @brief #FLASH_GetParamInfo             */
#define BRCM_SWARCH_FLASH_READ_PARAM_DATA_PROC         (0x8245U)    /**< @brief #FLASH_ReadParamData            */
/** @} */

/**
    @brief NVM Integer parse status

    @trace #BRCM_SWREQ_FLASH
*/
#define  FLASH_MAX_PAGE_SIZE    (256UL)

/**
    @brief NVM Integer parse status

    @trace #BRCM_SWREQ_FLASH
*/
#define FLASH_MAX_FILESIZE    (2UL*1024UL*1024UL)

/**
    @brief NVM Integer parse status

    @trace #BRCM_SWREQ_FLASH
*/
#define FLASH_MAX_SECTOR           (32UL)
#define FLASH_MAX_SECTOR_SIZE      (0x10000UL)

/**
    @brief NVM maximum count of PT images

    @trace #BRCM_SWREQ_FLASH
*/
#define FLASH_MAX_PT_COUNT         (16UL)

/**
    @brief Maximum SFDP parameters count in the message packets

    @trace #BRCM_SWREQ_FLASH
*/
#define FLASH_MAX_SFDP_PARAMETERS     (50UL)

/**
    @brief Maximum SFDP parameters ID list in the message packets

    @trace #BRCM_SWREQ_FLASH
*/
#define FLASH_MAX_PARAMETERS_ID_LIST  (30UL)

/**
    @brief Flash RPC operation max data size

    @trace #BRCM_SWREQ_FLASH
 */
#define FLASH_RPC_MAX_DATA_SIZE             (256UL)
#define FLASH_RPC_MAX_PAYLOAD_SIZE          (FLASH_RPC_MAX_DATA_SIZE + 32UL)

/**
    @brief Macro to Construct Flash CmdID

    @trace #BRCM_SWREQ_FLASH
*/
#define FLASH_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_NVM, BCM_FLM_ID, aId)

/**
  @name Flash module supported command
  @{
  @brief Flash module supported command

  @trace #BRCM_SWREQ_FLASH
*/
typedef uint32_t FLASH_CmdIDType;            /**< @brief typedef for flash cmdID */
#define FLASH_CMD_RPC_READ                   FLASH_ID_OF(1UL)  /**< @brief #FLASH_RpcReadInfoType       */
#define FLASH_CMD_RPC_WRITE                  FLASH_ID_OF(2UL)  /**< @brief #FLASH_RpcWriteInfoType      */
#define FLASH_CMD_RPC_ERASE                  FLASH_ID_OF(3UL)  /**< @brief #FLASH_RpcEraseInfoType      */
#define FLASH_CMD_IMGL_READ                  FLASH_ID_OF(4UL)  /**< @brief #FLASH_ImglCmdInfoType       */
#define FLASH_CMD_IMGL_WRITE                 FLASH_ID_OF(5UL)  /**< @brief #FLASH_ImglCmdInfoType       */
#define FLASH_CMD_IMGL_ERASE                 FLASH_ID_OF(6UL)  /**< @brief #FLASH_ImglCmdInfoType       */
#define FLASH_CMD_IMGL_READ_V2               FLASH_ID_OF(7UL)  /**< @brief #FLASH_ImglCmdInfoType       */
#define FLASH_CMD_IMGL_COPY                  FLASH_ID_OF(8UL)  /**< @brief #FLASH_ImglCmdInfoType       */
#define FLASH_CMD_GET_DEV_CAPABLITIES        FLASH_ID_OF(9UL)  /**< @brief #FLASH_DevCapabiltiesType    */
#define FLASH_CMD_GET_FLASH_ID               FLASH_ID_OF(10UL) /**< @brief #FLASH_FlashIDMsgType        */
#define FLASH_CMD_GET_PARAMETERS_INFO        FLASH_ID_OF(11UL) /**< @brief #FLASH_ParametersInfoType    */
#define FLASH_CMD_READ_PARAMETERS_DATA       FLASH_ID_OF(12UL) /**< @brief #FLASH_ReadParameterDataType */
/** @} */

/**
    @brief Flash Module RPC Read Info structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_ImglCmdInfoType {
    uint32_t            hwID;                            /**< @brief  Flash ID */
    uint32_t            len;                             /**< @brief  Read/wrire/erase length */
    uint32_t            readAddr;                        /**< @brief  Flash Physical read address */
    uint32_t            writeAddr;                       /**< @brief  Flash Physical write/erase address */
    uint8_t             *buf;                            /**< @brief  Input/Output data buffer */
} FLASH_ImglCmdInfoType;

/**
    @brief Flash Module RPC Read Info structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_RpcReadInfoType {
    uint32_t            hwID;                              /**< @brief  Flash ID */
    uint32_t            addr;                              /**< @brief  Flash Physical address */
    uint32_t            len;                               /**< @brief  Read length */
    uint8_t             bufOut[FLASH_RPC_MAX_DATA_SIZE];  /**< @brief  Input data buffer */
} FLASH_RpcReadInfoType;
BCM_STATIC_SIZE_ASSERT(FLASH_RpcReadInfoType, 268UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Flash Module RPC Write Info structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_RpcWriteInfoType {
    uint32_t            hwID;                              /**< @brief Flash ID */
    uint32_t            addr;                              /**< @brief operation Physical address */
    uint32_t            len;                               /**< @brief write length */
    uint8_t             bufIn[FLASH_RPC_MAX_DATA_SIZE];   /**< @brief Output data buffer */
} FLASH_RpcWriteInfoType;
BCM_STATIC_SIZE_ASSERT(FLASH_RpcWriteInfoType, 268UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Flash Module RPC Erase Info structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_RpcEraseInfoType {
    uint32_t            hwID;                             /**< @brief  Flash ID */
    uint32_t            addr;                             /**< @brief  operation Physical address */
    uint32_t            len;                             /**< @brief  Flash sector / sub-sector size */
} FLASH_RpcEraseInfoType;
BCM_STATIC_SIZE_ASSERT(FLASH_RpcEraseInfoType, 12UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
  @name Flash SFDP Parameter ID Type
  @{
  @brief Flash SFDP Parameter ID Type

  @trace #BRCM_SWREQ_FLASH
*/
typedef uint16_t FLASH_SFDPParamIDType;            /**< @brief typedef for flash SFDP parameter ID */
/** @} */

/**
  @name Flash Manufacturer ID Type
  @{
  @brief Flash Manufacturer ID Type

  @trace #BRCM_SWREQ_FLASH
*/
typedef uint8_t FLASH_ManufacturerIDType;             /**< @brief typedef for flash manufacturer ID */
#define FLASH_MANUFACTURER_ID_INVALID     (0xFFU)     /**< @brief Invalid flash manufacturer ID     */
/** @} */

/**
  @name Flash Memory Type
  @{
  @brief Flash Memory Type

  @trace #BRCM_SWREQ_FLASH
*/
typedef uint8_t FLASH_MemoryType;                    /**< @brief typedef for flash memory type */
#define FLASH_MEMORY_TYPE_INVALID         (0xFFU)    /**< @brief Invalid flash memory type     */
/** @} */

/**
  @name Flash Memory Density Type
  @{
  @brief Flash Memory Density Type

  @trace #BRCM_SWREQ_FLASH
*/
typedef uint8_t FLASH_MemoryDensityType;             /**< @brief typedef for flash memory density type */
#define FLASH_MEMORY_DENSITY_2GBIT        (0x22U)    /**< @brief 2 Giga-Bit                            */
#define FLASH_MEMORY_DENSITY_1GBIT        (0x21U)    /**< @brief 2 Giga-Bit                            */
#define FLASH_MEMORY_DENSITY_512MBIT      (0x20U)    /**< @brief 512 Mega-Bit                          */
#define FLASH_MEMORY_DENSITY_256MBIT      (0x19U)    /**< @brief 256 Mega-Bit                          */
#define FLASH_MEMORY_DENSITY_128MBIT      (0x18U)    /**< @brief 128 Mega-Bit                          */
#define FLASH_MEMORY_DENSITY_64MBIT       (0x17U)    /**< @brief 64 Mega-Bit                           */
#define FLASH_MEMORY_DENSITY_INVALID      (0xFFU)    /**< @brief Invalid flash memory density          */
/** @} */

/**
  @name Flash Device ID Type
  @{
  @brief Flash Device ID Type

  @trace #BRCM_SWREQ_FLASH
*/
typedef uint8_t FLASH_DeviceIDType;                  /**< @brief typedef for flash device ID type */
#define FLASH_DEVICE_ID_INVALID           (0xFFU)    /**< @brief Invalid flash device ID          */
/** @} */

/**
    @brief Flash ID structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_IDType {
    FLASH_ManufacturerIDType manufacturerID;                   /**< @brief Flash Manufacturer ID          */
    FLASH_MemoryType         memoryType;                       /**< @brief Flash Memory Type              */
    FLASH_MemoryDensityType  memoryDensity;                    /**< @brief Flash Memory Density           */
    FLASH_DeviceIDType       deviceID;                         /**< @brief Flash Device ID                */
    uint32_t                 resv[8];                          /**< @brief Reserved                       */
} FLASH_IDType;
BCM_STATIC_SIZE_ASSERT(FLASH_IDType, 36UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Get Flash ID message structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_FlashIDMsgType {
    uint32_t hwID;                                                    /**< @brief Flash Hardware ID              */
    FLASH_IDType flashID;                                             /**< @brief Flash Device ID                */
} FLASH_FlashIDMsgType;
BCM_STATIC_SIZE_ASSERT(FLASH_FlashIDMsgType, 40UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
  @name Flash SFDP DWord Type
  @{
  @brief Flash SFDP DWord Type & Parameter bit definitions

  Reference: JESD216 in JEDEC standard
  | JESD216 Revision | SFDP Version in Document | Release Date  | DWords Count in JEDEC parameter |
  |:----------------:|:------------------------:|:-------------:|:--------------------------------|
  | Base             | 1.00                     | April 2011    | 9                               |
  | A                | 1.05                     | July 2013     | 16                              |
  | F.02             | 1.10                     | June 2022     | 23                              |

  @trace #BRCM_SWREQ_FLASH
*/
typedef uint32_t FLASH_SFDPDWordType;            /**< @brief typedef for flash SFDP parameters */
/** @} */

/**
  @name Flash SFDP Basic info type (DWord 1)
  @{
  @brief Flash SFDP Basic info type

  This DWord contains the following informations:
      - Uniform 4 KB Sectors
      - Write Buffer Size,
      - Volatile Status Register,
      - Fast Read Support (1S-1S-2S) (1S-2S-2S) (1S-4S-4S)(1S-1S-4S)
      - Number of Address Bytes
      - DTR Support

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_BasicInfoType;            /**< @brief typedef for flash basic info parameters */
#define FLASH_BASIC_INFO_1_1_4_FAST_READ_SUPPORT_SHIFT      (22UL) /**< @brief Supports (1-1-4) Fast Read bit position */
#define FLASH_BASIC_INFO_1_1_4_FAST_READ_SUPPORT_MASK       (1UL << FLASH_BASIC_INFO_1_1_4_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (1-1-4) Fast Read bit mask */
#define FLASH_BASIC_INFO_1_4_4_FAST_READ_SUPPORT_SHIFT      (21UL) /**< @brief Supports (1-4-4) Fast Read bit position */
#define FLASH_BASIC_INFO_1_4_4_FAST_READ_SUPPORT_MASK       (1UL << FLASH_BASIC_INFO_1_4_4_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (1-4-4) Fast Read bit mask */
#define FLASH_BASIC_INFO_1_2_2_FAST_READ_SUPPORT_SHIFT      (20UL) /**< @brief Supports (1-2-2) Fast Read bit position */
#define FLASH_BASIC_INFO_1_2_2_FAST_READ_SUPPORT_MASK       (1UL << FLASH_BASIC_INFO_1_2_2_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (1-2-2) Fast Read bit mask */
#define FLASH_BASIC_INFO_DTR_CLOCKING_SUPPORT_SHIFT         (19UL) /**< @brief Supports Double Transfer Rate (DTR) Clocking bit position */
#define FLASH_BASIC_INFO_DTR_CLOCKING_SUPPORT_MASK          (1UL << FLASH_BASIC_INFO_DTR_CLOCKING_SUPPORT_SHIFT) /**< @brief Supports Double Transfer Rate (DTR) Clocking bit mask */
#define FLASH_BASIC_INFO_ADDRESS_BYTES_SHIFT                (17UL) /**< @brief Number of bytes used in addressing flash array read, write and erase bit position */
#define FLASH_BASIC_INFO_ADDRESS_BYTES_MASK                 (3UL << FLASH_BASIC_INFO_ADDRESS_BYTES_SHIFT) /**< @brief Number of bytes used in addressing flash array read, write and erase bit mask */
#define FLASH_BASIC_INFO_1_1_2_FAST_READ_SUPPORT_SHIFT      (16UL) /**< @brief Supports (1-1-2) Fast Read bit position */
#define FLASH_BASIC_INFO_1_1_2_FAST_READ_SUPPORT_MASK       (1UL << FLASH_BASIC_INFO_1_1_2_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (1-1-2) Fast Read bit mask */
#define FLASH_BASIC_INFO_4KB_ERASE_INSTRUCTION_SHIFT        (8UL) /**< @brief 4 Kilobyte Erase Instruction bit position */
#define FLASH_BASIC_INFO_4KB_ERASE_INSTRUCTION_MASK         (0xFFUL << FLASH_BASIC_INFO_4KB_ERASE_INSTRUCTION_SHIFT) /**< @brief 4 Kilobyte Erase Instruction bit mask */
#define FLASH_BASIC_INFO_WE_INSTRUCTION_SELECT_SHIFT        (4UL)  /**< @brief Write Enable Opcode Select for Writing to Volatile Status Register bit position */
#define FLASH_BASIC_INFO_WE_INSTRUCTION_SELECT_MASK         (1UL << FLASH_BASIC_INFO_WE_INSTRUCTION_SELECT_SHIFT) /**< @brief Write Enable Opcode Select for Writing to Volatile Status Register bit mask */
#define FLASH_BASIC_INFO_WE_FOR_STATUSREG_REQ_SHIFT         (3UL) /**< @brief Write Enable Instruction Required for Writing to Volatile Status Register bit position */
#define FLASH_BASIC_INFO_WE_FOR_STATUSREG_REQ_MASK          (1UL << FLASH_BASIC_INFO_WE_FOR_STATUSREG_REQ_SHIFT) /**< @brief Write Enable Instruction Required for Writing to Volatile Status Register bit mask */
#define FLASH_BASIC_INFO_WRITE_GRANULARITY_SHIFT            (2UL) /**< @brief Write Granularity bit position */
#define FLASH_BASIC_INFO_WRITE_GRANULARITY_MASK             (1UL << FLASH_BASIC_INFO_WRITE_GRANULARITY_SHIFT) /**< @brief Write Granularity bit mask */
#define FLASH_BASIC_INFO_SECTOR_ERASE_SIZE_SHIFT            (0UL) /**< @brief Block/Sector Erase Sizes bit position */
#define FLASH_BASIC_INFO_SECTOR_ERASE_SIZE_MASK             (3UL << FLASH_BASIC_INFO_SECTOR_ERASE_SIZE_SHIFT) /**< @brief Block/Sector Erase Sizes bit mask */
/** @} */

/**
  @name Flash memory desnity type (DWord 2)
  @{
  @brief Flash memory desnity type

  This DWord contains flash memory size information

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_MemDensityType;           /**< @brief typedef for flash memory density parameter */
#define FLASH_MEM_DENSITY_FLASH_SIZE_SHIFT            (0UL) /**< @brief Flash Memory Size bit position */
#define FLASH_MEM_DENSITY_FLASH_SIZE_MASK             (0xFFFFFFFFUL << FLASH_MEM_DENSITY_FLASH_SIZE_SHIFT) /**< @brief Flash Memory Size bit mask */
/** @} */

/**
  @name Flash SFDP fast read 0 type (DWord 3)
  @{
  @brief Flash SFDP fast read 0 type

  This DWord contains the following informations:
      Fast Read (1S-4S-4S) (1S-1S-4S)
          - Wait States
          - Mode Bit Clocks
          - Instruction for read

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead0Type;           /**< @brief typedef for SFDP fast read 0 parameter */
#define FLASH_FAST_READ0_1_1_4_FAST_READ_INSTRUCTION_SHIFT  (24UL) /**< @brief (1-1-4) Fast Read Instruction bit position */
#define FLASH_FAST_READ0_1_1_4_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ0_1_1_4_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1-1-4) Fast Read Instruction bit mask */
#define FLASH_FAST_READ0_1_1_4_FAST_READ_MODE_BITS_SHIFT    (21UL) /**< @brief (1-1-4) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ0_1_1_4_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ0_1_1_4_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1-1-4) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ0_1_1_4_FAST_READ_WAIT_STATES_SHIFT  (16UL) /**< @brief (1-1-4) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ0_1_1_4_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ0_1_1_4_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1-1-4) Fast Read Number of Wait states (dummy clocks) bit mask */
#define FLASH_FAST_READ0_1_4_4_FAST_READ_INSTRUCTION_SHIFT  (8UL)  /**< @brief (1-4-4) Fast Read Instruction bit position */
#define FLASH_FAST_READ0_1_4_4_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ0_1_4_4_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1-4-4) Fast Read Instruction bit mask */
#define FLASH_FAST_READ0_1_4_4_FAST_READ_MODE_BITS_SHIFT    (5UL)  /**< @brief (1-4-4) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ0_1_4_4_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ0_1_4_4_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1-4-4) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ0_1_4_4_FAST_READ_WAIT_STATES_SHIFT  (0UL)  /**< @brief (1-4-4) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ0_1_4_4_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ0_1_4_4_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1-4-4) Fast Read Number of Wait states (dummy clocks) bit mask */
/** @} */

/**
  @name Flash SFDP fast read 1 type (DWord 4)
  @{
  @brief Flash SFDP fast read 1 type

  This DWord contains the following informations:
      Fast Read (1S-1S-2S) (1S-2S-2S)
          - Wait States
          - Mode Bit Clocks
          - Instruction for read

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead1Type;           /**< @brief typedef for SFDP fast read 1 parameter */
#define FLASH_FAST_READ1_1_2_2_FAST_READ_INSTRUCTION_SHIFT  (24UL) /**< @brief (1-2-2) Fast Read Instruction bit position */
#define FLASH_FAST_READ1_1_2_2_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ1_1_2_2_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1-2-2) Fast Read Instruction bit mask */
#define FLASH_FAST_READ1_1_2_2_FAST_READ_MODE_BITS_SHIFT    (21UL) /**< @brief (1-2-2) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ1_1_2_2_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ1_1_2_2_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1-2-2) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ1_1_2_2_FAST_READ_WAIT_STATES_SHIFT  (16UL) /**< @brief (1-2-2) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ1_1_2_2_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ1_1_2_2_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1-2-2) Fast Read Number of Wait states (dummy clocks) bit mask */
#define FLASH_FAST_READ1_1_1_2_FAST_READ_INSTRUCTION_SHIFT  (8UL)  /**< @brief (1-1-2) Fast Read Instruction bit position */
#define FLASH_FAST_READ1_1_1_2_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ1_1_1_2_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1-1-2) Fast Read Instruction bit mask */
#define FLASH_FAST_READ1_1_1_2_FAST_READ_MODE_BITS_SHIFT    (5UL)  /**< @brief (1-1-2) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ1_1_1_2_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ1_1_1_2_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1-1-2) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ1_1_1_2_FAST_READ_WAIT_STATES_SHIFT  (0UL)  /**< @brief (1-1-2) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ1_1_1_2_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ1_1_1_2_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1-1-2) Fast Read Number of Wait states (dummy clocks) bit mask */
/** @} */

/**
  @name Flash SFDP fast read 2 type (DWord 5)
  @{
  @brief Flash SFDP fast read 2 type

  This DWord contains fast read support information of (2S-2S-2S) (4S-4S-4S) modes.

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead2Type;           /**< @brief typedef for SFDP fast read 2 parameter */
#define FLASH_FAST_READ2_4_4_4_FAST_READ_SUPPORT_SHIFT      (4UL) /**< @brief Supports (4-4-4) Fast Read bit position */
#define FLASH_FAST_READ2_4_4_4_FAST_READ_SUPPORT_MASK       (1UL << FLASH_FAST_READ2_4_4_4_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (4-4-4) Fast Read bit mask */
#define FLASH_FAST_READ2_2_2_2_FAST_READ_SUPPORT_SHIFT      (0UL) /**< @brief Supports (2-2-2) Fast Read bit position */
#define FLASH_FAST_READ2_2_2_2_FAST_READ_SUPPORT_MASK       (1UL << FLASH_FAST_READ2_2_2_2_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (2-2-2) Fast Read bit mask */
/** @} */

/**
  @name Flash SFDP fast read 3 type (DWord 6)
  @{
  @brief Flash SFDP fast read 3 type

  This DWord contains the following informations:
      Fast Read (2S-2S-2S)
          - Wait States
          - Mode Bit Clocks
          - Instruction for read

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead3Type;           /**< @brief typedef for SFDP fast read 3 parameter */
#define FLASH_FAST_READ3_2_2_2_FAST_READ_INSTRUCTION_SHIFT  (24UL) /**< @brief (2-2-2) Fast Read Instruction bit position */
#define FLASH_FAST_READ3_2_2_2_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ3_2_2_2_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (2-2-2) Fast Read Instruction bit mask */
#define FLASH_FAST_READ3_2_2_2_FAST_READ_MODE_BITS_SHIFT    (21UL) /**< @brief (2-2-2) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ3_2_2_2_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ3_2_2_2_FAST_READ_MODE_BITS_SHIFT) /**< @brief (2-2-2) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ3_2_2_2_FAST_READ_WAIT_STATES_SHIFT  (16UL) /**< @brief (2-2-2) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ3_2_2_2_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ3_2_2_2_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (2-2-2) Fast Read Number of Wait states (dummy clocks) bit mask */
/** @} */

/**
  @name Flash SFDP fast read 4 type (DWord 7)
  @{
  @brief Flash SFDP fast read 4 type

  This DWord contains the following informations:
      Fast Read (4S-4S-4S)
          - Wait States
          - Mode Bit Clocks
          - Instruction for read

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead4Type;           /**< @brief typedef for SFDP fast read 4 parameter */
#define FLASH_FAST_READ4_4_4_4_FAST_READ_INSTRUCTION_SHIFT  (24UL) /**< @brief (4-4-4) Fast Read Instruction bit position */
#define FLASH_FAST_READ4_4_4_4_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ4_4_4_4_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (4-4-4) Fast Read Instruction bit mask */
#define FLASH_FAST_READ4_4_4_4_FAST_READ_MODE_BITS_SHIFT    (21UL) /**< @brief (4-4-4) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ4_4_4_4_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ4_4_4_4_FAST_READ_MODE_BITS_SHIFT) /**< @brief (4-4-4) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ4_4_4_4_FAST_READ_WAIT_STATES_SHIFT  (16UL) /**< @brief (4-4-4) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ4_4_4_4_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ4_4_4_4_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (4-4-4) Fast Read Number of Wait states (dummy clocks) bit mask */
/** @} */

/**
  @name Flash SFDP Erase information 0 type (DWord 8)
  @{
  @brief Flash SFDP Erase information 0 type

  This DWord contains Erase Type 1 and 2 Size and Instruction for operation

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_EraseInfo0Type;           /**< @brief typedef for SFDP Erase information 0 parameter */
#define FLASH_ERASE_INFO0_ERASE_TYPE_2_INSTRUCTION_SHIFT     (24UL) /**< @brief Erase Type 2 Instruction bit position */
#define FLASH_ERASE_INFO0_ERASE_TYPE_2_INSTRUCTION_MASK      (0xFFUL << FLASH_ERASE_INFO0_ERASE_TYPE_2_INSTRUCTION_SHIFT) /**< @brief Erase Type 2 Instruction bit mask */
#define FLASH_ERASE_INFO0_ERASE_TYPE_2_SIZE_SHIFT            (16UL) /**< @brief Erase Type 2 Size bit position */
#define FLASH_ERASE_INFO0_ERASE_TYPE_2_SIZE_MASK             (0xFFUL << FLASH_ERASE_INFO0_ERASE_TYPE_2_SIZE_SHIFT) /**< @brief Erase Type 2 Size bit mask */
#define FLASH_ERASE_INFO0_ERASE_TYPE_1_INSTRUCTION_SHIFT     (8UL)  /**< @brief Erase Type 1 Instruction bit position */
#define FLASH_ERASE_INFO0_ERASE_TYPE_1_INSTRUCTION_MASK      (0xFFUL << FLASH_ERASE_INFO0_ERASE_TYPE_1_INSTRUCTION_SHIFT) /**< @brief Erase Type 1 Instruction bit mask */
#define FLASH_ERASE_INFO0_ERASE_TYPE_1_SIZE_SHIFT            (0UL)  /**< @brief Erase Type 1 Size bit position */
#define FLASH_ERASE_INFO0_ERASE_TYPE_1_SIZE_MASK             (0xFFUL << FLASH_ERASE_INFO0_ERASE_TYPE_1_SIZE_SHIFT) /**< @brief Erase Type 1 Size bit mask */
/** @} */

/**
  @name Flash SFDP Erase information 1 type (DWord 9)
  @{
  @brief Flash SFDP Erase information 1 type

  This DWord contains Erase Type 3 and 4 Size and Instruction for operation

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_EraseInfo1Type;           /**< @brief typedef for SFDP Erase information 1 parameter */
#define FLASH_ERASE_INFO1_ERASE_TYPE_4_INSTRUCTION_SHIFT     (24UL) /**< @brief Erase Type 4 Instruction bit position */
#define FLASH_ERASE_INFO1_ERASE_TYPE_4_INSTRUCTION_MASK      (0xFFUL << FLASH_ERASE_INFO1_ERASE_TYPE_4_INSTRUCTION_SHIFT) /**< @brief Erase Type 4 Instruction bit mask */
#define FLASH_ERASE_INFO1_ERASE_TYPE_4_SIZE_SHIFT            (16UL) /**< @brief Erase Type 4 Size bit position */
#define FLASH_ERASE_INFO1_ERASE_TYPE_4_SIZE_MASK             (0xFFUL << FLASH_ERASE_INFO1_ERASE_TYPE_4_SIZE_SHIFT) /**< @brief Erase Type 4 Size bit mask */
#define FLASH_ERASE_INFO1_ERASE_TYPE_3_INSTRUCTION_SHIFT     (8UL)  /**< @brief Erase Type 3 Instruction bit position */
#define FLASH_ERASE_INFO1_ERASE_TYPE_3_INSTRUCTION_MASK      (0xFFUL << FLASH_ERASE_INFO1_ERASE_TYPE_3_INSTRUCTION_SHIFT) /**< @brief Erase Type 3 Instruction bit mask */
#define FLASH_ERASE_INFO1_ERASE_TYPE_3_SIZE_SHIFT            (0UL)  /**< @brief Erase Type 3 Size bit position */
#define FLASH_ERASE_INFO1_ERASE_TYPE_3_SIZE_MASK             (0xFFUL << FLASH_ERASE_INFO1_ERASE_TYPE_3_SIZE_SHIFT) /**< @brief Erase Type 3 Size bit mask */
/** @} */

/**
  @name Flash SFDP Time information 0 type (DWord 10)
  @{
  @brief Flash SFDP Time information 0 type

  This DWord contains Erase Type (1:4) Typical Erase Times and
  Multiplier Used To Derive Max Erase Times

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_TimeInfo0Type;            /**< @brief typedef for SFDP Time information 0 parameter */
#define FLASH_TIME_INFO0_ERASE_TYPE_4_TIME_UNIT_SHIFT      (30UL) /**< @brief Erase Type 4 Typical time uint bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_4_TIME_UNIT_MASK       (0x3UL << FLASH_TIME_INFO0_ERASE_TYPE_4_TIME_UNIT_SHIFT) /**< @brief Erase Type 4 Typical time uint bit mask */
#define FLASH_TIME_INFO0_ERASE_TYPE_4_TIME_COUNT_SHIFT     (25UL) /**< @brief Erase Type 4 Typical time count bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_4_TIME_COUNT_MASK      (0x1FUL << FLASH_TIME_INFO0_ERASE_TYPE_4_TIME_COUNT_SHIFT) /**< @brief Erase Type 4 Typical time count bit mask */
#define FLASH_TIME_INFO0_ERASE_TYPE_3_TIME_UNIT_SHIFT      (23UL) /**< @brief Erase Type 3 Typical time uint bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_3_TIME_UNIT_MASK       (0x3UL << FLASH_TIME_INFO0_ERASE_TYPE_3_TIME_UNIT_SHIFT) /**< @brief Erase Type 3 Typical time uint bit mask */
#define FLASH_TIME_INFO0_ERASE_TYPE_3_TIME_COUNT_SHIFT     (18UL) /**< @brief Erase Type 3 Typical time count bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_3_TIME_COUNT_MASK      (0x1FUL << FLASH_TIME_INFO0_ERASE_TYPE_3_TIME_COUNT_SHIFT) /**< @brief Erase Type 3 Typical time count bit mask */
#define FLASH_TIME_INFO0_ERASE_TYPE_2_TIME_UNIT_SHIFT      (16UL) /**< @brief Erase Type 2 Typical time uint bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_2_TIME_UNIT_MASK       (0x3UL << FLASH_TIME_INFO0_ERASE_TYPE_2_TIME_UNIT_SHIFT) /**< @brief Erase Type 2 Typical time uint bit mask */
#define FLASH_TIME_INFO0_ERASE_TYPE_2_TIME_COUNT_SHIFT     (11UL) /**< @brief Erase Type 2 Typical time count bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_2_TIME_COUNT_MASK      (0x1FUL << FLASH_TIME_INFO0_ERASE_TYPE_2_TIME_COUNT_SHIFT) /**< @brief Erase Type 2 Typical time count bit mask */
#define FLASH_TIME_INFO0_ERASE_TYPE_1_TIME_UNIT_SHIFT      (9UL)  /**< @brief Erase Type 1 Typical time uint bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_1_TIME_UNIT_MASK       (0x3UL << FLASH_TIME_INFO0_ERASE_TYPE_1_TIME_UNIT_SHIFT) /**< @brief Erase Type 1 Typical time uint bit mask */
#define FLASH_TIME_INFO0_ERASE_TYPE_1_TIME_COUNT_SHIFT     (4UL)  /**< @brief Erase Type 1 Typical time count bit position */
#define FLASH_TIME_INFO0_ERASE_TYPE_1_TIME_COUNT_MASK      (0x1FUL << FLASH_TIME_INFO0_ERASE_TYPE_1_TIME_COUNT_SHIFT) /**< @brief Erase Type 1 Typical time count bit mask */
#define FLASH_TIME_INFO0_ERASE_TIME_MULTIPLIER_SHIFT       (0UL)  /**< @brief Multiplier from typical erase time to maximum erase time bit position */
#define FLASH_TIME_INFO0_ERASE_TIME_MULTIPLIER_MASK        (0xFUL << FLASH_TIME_INFO0_ERASE_TIME_MULTIPLIER_SHIFT) /**< @brief Multiplier from typical erase time to maximum erase time bit mask */
/** @} */

/**
  @name Flash SFDP Time information 1 type (DWord 11)
  @{
  @brief Flash SFDP Time information 1 type

  This DWord contains,
      - Chip Erase Typical Time
      - Byte Program and Typical Time
      - Page Program Typical Time
      - Page Size
      - Program Time Multiplier

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_TimeInfo1Type;            /**< @brief typedef for SFDP Time information 1 parameter */
#define FLASH_TIME_INFO1_CHIP_ERASE_TIME_UNIT_SHIFT        (29UL) /**< @brief Chip Erase Typical time uint bit position */
#define FLASH_TIME_INFO1_CHIP_ERASE_TIME_UNIT_MASK         (0x3UL << FLASH_TIME_INFO1_CHIP_ERASE_TIME_UNIT_SHIFT) /**< @brief Chip Erase Typical time uint bit mask */
#define FLASH_TIME_INFO1_CHIP_ERASE_TIME_COUNT_SHIFT       (24UL) /**< @brief Chip Erase Typical time count bit position */
#define FLASH_TIME_INFO1_CHIP_ERASE_TIME_COUNT_MASK        (0x1FUL << FLASH_TIME_INFO1_CHIP_ERASE_TIME_COUNT_SHIFT) /**< @brief Chip Erase Typical time count bit mask */
#define FLASH_TIME_INFO1_ADDITIONAL_PROG_TIME_UNIT_SHIFT   (23UL) /**< @brief Additional Byte Program Typical time uint bit position */
#define FLASH_TIME_INFO1_ADDITIONAL_PROG_TIME_UNIT_MASK    (0x1UL << FLASH_TIME_INFO1_ADDITIONAL_PROG_TIME_UNIT_SHIFT) /**< @brief Additional Byte Program Typical time uint bit mask */
#define FLASH_TIME_INFO1_ADDITIONAL_PROG_TIME_COUNT_SHIFT  (19UL) /**< @brief Additional Byte Program Typical time count bit position */
#define FLASH_TIME_INFO1_ADDITIONAL_PROG_TIME_COUNT_MASK   (0xFUL << FLASH_TIME_INFO1_ADDITIONAL_PROG_TIME_COUNT_SHIFT) /**< @brief Additional Byte Program Typical time count bit mask */
#define FLASH_TIME_INFO1_FIRST_BYTE_PROG_TIME_UNIT_SHIFT   (18UL) /**< @brief First Byte Program Typical time uint bit position */
#define FLASH_TIME_INFO1_FIRST_BYTE_PROG_TIME_UNIT_MASK    (0x1UL << FLASH_TIME_INFO1_FIRST_BYTE_PROG_TIME_UNIT_SHIFT) /**< @brief First Byte Program Typical time uint bit mask */
#define FLASH_TIME_INFO1_FIRST_BYTE_PROG_TIME_COUNT_SHIFT  (14UL) /**< @brief First Byte Program Typical time count bit position */
#define FLASH_TIME_INFO1_FIRST_BYTE_PROG_TIME_COUNT_MASK   (0xFUL << FLASH_TIME_INFO1_FIRST_BYTE_PROG_TIME_COUNT_SHIFT) /**< @brief First Byte Program Typical time count bit mask */
#define FLASH_TIME_INFO1_PAGE_PROG_TIME_UNIT_SHIFT         (13UL) /**< @brief Page Program Typical time uint bit position */
#define FLASH_TIME_INFO1_PAGE_PROG_TIME_UNIT_MASK          (0x1UL << FLASH_TIME_INFO1_PAGE_PROG_TIME_UNIT_SHIFT) /**< @brief Page Program Typical time uint bit mask */
#define FLASH_TIME_INFO1_PAGE_PROG_TIME_COUNT_SHIFT        (8UL)  /**< @brief Page Program Typical time count bit position */
#define FLASH_TIME_INFO1_PAGE_PROG_TIME_COUNT_MASK         (0x1FUL << FLASH_TIME_INFO1_PAGE_PROG_TIME_COUNT_SHIFT) /**< @brief Page Program Typical time count bit mask */
#define FLASH_TIME_INFO1_PAGE_SIZE_SHIFT                   (4UL)  /**< @brief Page Size bit position */
#define FLASH_TIME_INFO1_PAGE_SIZE_MASK                    (0xFUL << FLASH_TIME_INFO1_PAGE_SIZE_SHIFT) /**< @brief Page Size bit mask */
#define FLASH_TIME_INFO1_PROG_TIME_MULTIPLIER_SHIFT        (0UL)  /**< @brief Multiplier from typical time to max time for Page or byte program bit position */
#define FLASH_TIME_INFO1_PROG_TIME_MULTIPLIER_MASK         (0xFUL << FLASH_TIME_INFO1_PROG_TIME_MULTIPLIER_SHIFT) /**< @brief Multiplier from typical time to max time for Page or byte program bit mask */
/** @} */

/**
  @name Flash SFDP Suspend & Resume info 0 type (DWord 12)
  @{
  @brief Flash SFDP Suspend & Resume info 0 type

  This DWord contains,
      - Erase/Program Suspend/Resume Support
      - Intervals
      - Latency
      - Keep Out Area Size

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_SuspResume0Type;            /**< @brief typedef for SFDP Suspend & Resume info 0 parameter */
#define FLASH_SUSP_RESUME0_SUSPEND_RESUME_SUPPORT_SHIFT      (31UL) /**< @brief Suspend / Resume supported bit position */
#define FLASH_SUSP_RESUME0_SUSPEND_RESUME_SUPPORT_MASK       (0x1UL << FLASH_SUSP_RESUME0_SUSPEND_RESUME_SUPPORT_SHIFT) /**< @brief Suspend / Resume supported bit mask */
#define FLASH_SUSP_RESUME0_SIP_ERASE_LATENCY_UNIT_SHIFT      (29UL) /**< @brief Suspend in-progress erase max latency bit position */
#define FLASH_SUSP_RESUME0_SIP_ERASE_LATENCY_UNIT_MASK       (0x3UL << FLASH_SUSP_RESUME0_SIP_ERASE_LATENCY_UNIT_SHIFT) /**< @brief Suspend in-progress erase max latency uint bit mask */
#define FLASH_SUSP_RESUME0_SIP_ERASE_LATENCY_COUNT_SHIFT     (24UL) /**< @brief Suspend in-progress erase max latency bit position */
#define FLASH_SUSP_RESUME0_SIP_ERASE_LATENCY_COUNT_MASK      (0x1FUL << FLASH_SUSP_RESUME0_SIP_ERASE_LATENCY_COUNT_SHIFT) /**< @brief Suspend in-progress erase max latency count bit mask */
#define FLASH_SUSP_RESUME0_ERASE_RES_TO_SUSP_INTERVAL_SHIFT  (20UL) /**< @brief Erase Resume to Suspend Interval bit position */
#define FLASH_SUSP_RESUME0_ERASE_RES_TO_SUSP_INTERVAL_MASK   (0xFUL << FLASH_SUSP_RESUME0_ERASE_RES_TO_SUSP_INTERVAL_SHIFT) /**< @brief Erase Resume to Suspend Interval bit mask */
#define FLASH_SUSP_RESUME0_SIP_PROGRAM_LATENCY_UNIT_SHIFT    (18UL) /**< @brief Suspend in-progress program max latency bit position */
#define FLASH_SUSP_RESUME0_SIP_PROGRAM_LATENCY_UNIT_MASK     (0x3UL << FLASH_SUSP_RESUME0_SIP_PROGRAM_LATENCY_UNIT_SHIFT) /**< @brief Suspend in-progress program max latency uint bit mask */
#define FLASH_SUSP_RESUME0_SIP_PROGRAM_LATENCY_COUNT_SHIFT   (13UL) /**< @brief Suspend in-progress program max latency bit position */
#define FLASH_SUSP_RESUME0_SIP_PROGRAM_LATENCY_COUNT_MASK    (0x1FUL << FLASH_SUSP_RESUME0_SIP_PROGRAM_LATENCY_COUNT_SHIFT) /**< @brief Suspend in-progress program max latency count bit mask */
#define FLASH_SUSP_RESUME0_PROG_RES_TO_SUSP_INTERVAL_SHIFT   (9UL) /**< @brief Program Resume to Suspend Interval bit position */
#define FLASH_SUSP_RESUME0_PROG_RES_TO_SUSP_INTERVAL_MASK    (0xFUL << FLASH_SUSP_RESUME0_PROG_RES_TO_SUSP_INTERVAL_SHIFT) /**< @brief Program Resume to Suspend Interval bit mask */
#define FLASH_SUSP_RESUME0_PROHIBITED_IN_ERASE_SUSP_SHIFT    (4UL) /**< @brief Prohibited Operations During Erase Suspend bit position */
#define FLASH_SUSP_RESUME0_PROHIBITED_IN_ERASE_SUSP_MASK     (0xFUL << FLASH_SUSP_RESUME0_PROHIBITED_IN_ERASE_SUSP_SHIFT) /**< @brief Prohibited Operations During Erase Suspend bit mask */
#define FLASH_SUSP_RESUME0_PROHIBITED_IN_PROG_SUSP_SHIFT     (0UL) /**< @brief Prohibited Operations During Program Suspend bit position */
#define FLASH_SUSP_RESUME0_PROHIBITED_IN_PROG_SUSP_MASK      (0xFUL << FLASH_SUSP_RESUME0_PROHIBITED_IN_PROG_SUSP_SHIFT) /**< @brief Prohibited Operations During Program Suspend bit mask */
/** @} */

/**
  @name Flash SFDP Suspend & Resume info 1 type (DWord 13)
  @{
  @brief Flash SFDP Suspend & Resume info 0 type

  This DWord contains,
      - Program Suspend Instruction
      - Erase Suspend Instruction
      - Program Resume Instruction
      - Erase Resume Instruction

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_SuspResume1Type;            /**< @brief typedef for SFDP Suspend & Resume info 1 parameter */
#define FLASH_SUSP_RESUME1_SUSPEND_INSTRUCTION_SHIFT         (24UL) /**< @brief Suspend Instruction bit position */
#define FLASH_SUSP_RESUME1_SUSPEND_INSTRUCTION_MASK          (0xFFUL << FLASH_SUSP_RESUME1_SUSPEND_INSTRUCTION_SHIFT) /**< @brief Suspend Instruction bit mask */
#define FLASH_SUSP_RESUME1_RESUME_INSTRUCTION_SHIFT          (16UL) /**< @brief Resume Instruction bit position */
#define FLASH_SUSP_RESUME1_RESUME_INSTRUCTION_MASK           (0xFFUL << FLASH_SUSP_RESUME1_RESUME_INSTRUCTION_SHIFT) /**< @brief Resume Instruction bit mask */
#define FLASH_SUSP_RESUME1_PROG_SUSPEND_INSTRUCTION_SHIFT    (8UL)  /**< @brief Program Suspend Instruction bit position */
#define FLASH_SUSP_RESUME1_PROG_SUSPEND_INSTRUCTION_MASK     (0xFFUL << FLASH_SUSP_RESUME1_PROG_SUSPEND_INSTRUCTION_SHIFT) /**< @brief Program Suspend Instruction bit mask */
#define FLASH_SUSP_RESUME1_PROG_RESUME_INSTRUCTION_SHIFT     (0UL)  /**< @brief Program Resume Instruction bit position */
#define FLASH_SUSP_RESUME1_PROG_RESUME_INSTRUCTION_MASK      (0xFFUL << FLASH_SUSP_RESUME1_PROG_RESUME_INSTRUCTION_SHIFT) /**< @brief Program Resume Instruction bit mask */
/** @} */

/**
  @name Flash SFDP Power Down info type (DWord 14)
  @{
  @brief Flash SFDP Power Down info type

  This DWord contains the inforamtion about Deep Powerdown and
  Status Register Polling Device Busy

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_PowerDownType;            /**< @brief typedef for SFDP Power Down info parameter */
#define FLASH_POWER_DOWN_DEEP_POWER_DOWN_SUPPORT_SHIFT     (31UL) /**< @brief Deep Powerdown Supported bit position */
#define FLASH_POWER_DOWN_DEEP_POWER_DOWN_SUPPORT_MASK      (1UL << FLASH_POWER_DOWN_DEEP_POWER_DOWN_SUPPORT_SHIFT) /**< @brief Deep Powerdown Supported bit mask */
#define FLASH_POWER_DOWN_ENTER_DEEP_POWERDOWN_INSTR_SHIFT  (23UL) /**< @brief Enter Deep Powerdown Instruction bit position */
#define FLASH_POWER_DOWN_ENTER_DEEP_POWERDOWN_INSTR_MASK   (0xFFUL << FLASH_POWER_DOWN_ENTER_DEEP_POWERDOWN_INSTR_SHIFT) /**< @brief Enter Deep Powerdown Instruction bit mask */
#define FLASH_POWER_DOWN_EXIT_DEEP_POWERDOWN_INSTR_SHIFT   (15UL) /**< @brief Exit Deep Powerdown Instruction bit position */
#define FLASH_POWER_DOWN_EXIT_DEEP_POWERDOWN_INSTR_MASK    (0xFFUL << FLASH_POWER_DOWN_EXIT_DEEP_POWERDOWN_INSTR_SHIFT) /**< @brief Exit Deep Powerdown Instruction bit mask */
#define FLASH_POWER_DOWN_DLY_AFTER_EXIT_PWRDWN_UNIT_SHIFT  (13UL) /**< @brief Exit Deep Powerdown to next operation delay unit bit position */
#define FLASH_POWER_DOWN_DLY_AFTER_EXIT_PWRDWN_UNIT_MASK   (0x3UL << FLASH_POWER_DOWN_DLY_AFTER_EXIT_PWRDWN_UNIT_SHIFT) /**< @brief Exit Deep Powerdown to next operation delay unit bit mask */
#define FLASH_POWER_DOWN_DLY_AFTER_EXIT_PWRDWN_COUNT_SHIFT (8UL)  /**< @brief Exit Deep Powerdown to next operation delay count bit position */
#define FLASH_POWER_DOWN_DLY_AFTER_EXIT_PWRDWN_COUNT_MASK  (0x1FUL << FLASH_POWER_DOWN_DLY_AFTER_EXIT_PWRDWN_COUNT_SHIFT) /**< @brief Exit Deep Powerdown to next operation delay count bit mask */
#define FLASH_POWER_DOWN_STATUS_REG_POLLING_BUSY_SHIFT     (2UL)  /**< @brief Status Register Polling Device Busy bit position */
#define FLASH_POWER_DOWN_STATUS_REG_POLLING_BUSY_MASK      (0x3FUL << FLASH_POWER_DOWN_STATUS_REG_POLLING_BUSY_SHIFT) /**< @brief Status Register Polling Device Busy bit mask */
/** @} */

/**
  @name Flash SFDP Quad mode info type (DWord 15)
  @{
  @brief Flash SFDP Quad mode info type

  This DWord contains,
      - Hold and WP Disable Function
      - Quad Enable Requirements
      - 4S-4S-4S Mode Enable/Disable Sequences
      - 0-4-4 Entry/Exit Methods and Support

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_QuadInfoType;               /**< @brief typedef for Quad mode info parameter */
#define FLASH_QUAD_INFO_HOLD_WP_DISABLE_SHIFT             (23UL) /**< @brief HOLD and WP Disable bit position */
#define FLASH_QUAD_INFO_HOLD_WP_DISABLE_MASK              (1UL << FLASH_QUAD_INFO_HOLD_WP_DISABLE_SHIFT) /**< @brief HOLD and WP Disable bit mask */
#define FLASH_QUAD_INFO_QUAD_EN_REQ_SHIFT                 (20UL) /**< @brief Quad Enable Requirements bit position */
#define FLASH_QUAD_INFO_QUAD_EN_REQ_MASK                  (0x7UL << FLASH_QUAD_INFO_QUAD_EN_REQ_SHIFT) /**< @brief Quad Enable Requirements bit mask */
#define FLASH_QUAD_INFO_0_4_4_ENTRY_METHOD_SHIFT          (16UL) /**< @brief (0-4-4) Mode Entry Method bit position */
#define FLASH_QUAD_INFO_0_4_4_ENTRY_METHOD_MASK           (0xFUL << FLASH_QUAD_INFO_0_4_4_ENTRY_METHOD_SHIFT) /**< @brief (0-4-4) Mode Entry Method bit mask */
#define FLASH_QUAD_INFO_0_4_4_EXIT_METHOD_SHIFT           (10UL) /**< @brief (0-4-4) Mode Exit Method bit position */
#define FLASH_QUAD_INFO_0_4_4_EXIT_METHOD_MASK            (0x3FUL << FLASH_QUAD_INFO_0_4_4_EXIT_METHOD_SHIFT) /**< @brief (0-4-4) Mode Exit Method bit mask */
#define FLASH_QUAD_INFO_0_4_4_MODE_SUPPORTED_SHIFT        (9UL)  /**< @brief (0-4-4) Mode Supported bit position */
#define FLASH_QUAD_INFO_0_4_4_MODE_SUPPORTED_MASK         (0xFUL << FLASH_QUAD_INFO_0_4_4_MODE_SUPPORTED_SHIFT) /**< @brief (0-4-4) Mode Supported bit mask */
#define FLASH_QUAD_INFO_4_4_4_ENABLE_SEQUENCE_SHIFT       (4UL)  /**< @brief (4-4-4) Mode enable sequences bit position */
#define FLASH_QUAD_INFO_4_4_4_ENABLE_SEQUENCE_MASK        (0x1FUL << FLASH_QUAD_INFO_4_4_4_ENABLE_SEQUENCE_SHIFT) /**< @brief (0-4-4) Mode enable sequences bit mask */
#define FLASH_QUAD_INFO_4_4_4_DISABLE_SEQUENCE_SHIFT      (0UL)  /**< @brief (4-4-4) Mode disable sequences bit position */
#define FLASH_QUAD_INFO_4_4_4_DISABLE_SEQUENCE_MASK       (0xFUL << FLASH_QUAD_INFO_4_4_4_DISABLE_SEQUENCE_SHIFT) /**< @brief (0-4-4) Mode disable sequences bit mask */
/** @} */

/**
  @name Flash SFDP Address mode info type (DWord 16)
  @{
  @brief Flash SFDP Address mode info type

  This DWord contains,
      - 32-bit Address Entry/Exit Methods and Support
      - Soft Reset and Rescue Sequences
      - Volatile and Nonvolatile Status Register Support

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_AddrModeType;               /**< @brief typedef for Address mode info parameter */
#define FLASH_ADDR_MODE_ENTER_4_BYTE_ADDRESSING_SHIFT     (24UL) /**< @brief Enter 4-Byte Addressing bit position */
#define FLASH_ADDR_MODE_ENTER_4_BYTE_ADDRESSING_MASK      (0xFFUL << FLASH_ADDR_MODE_ENTER_4_BYTE_ADDRESSING_SHIFT) /**< @brief Enter 4-Byte Addressing bit mask */
#define FLASH_ADDR_MODE_EXIT_4_BYTE_ADDRESSING_SHIFT      (14UL) /**< @brief Exit 4-Byte Addressing bit position */
#define FLASH_ADDR_MODE_EXIT_4_BYTE_ADDRESSING_MASK       (0x3FFUL << FLASH_ADDR_MODE_EXIT_4_BYTE_ADDRESSING_SHIFT) /**< @brief Exit 4-Byte Addressing bit mask */
#define FLASH_ADDR_MODE_SOFT_RESET_RESCUE_SEQUENCE_SHIFT  (8UL)  /**< @brief Soft Reset and Rescue Sequence Support bit position */
#define FLASH_ADDR_MODE_SOFT_RESET_RESCUE_SEQUENCE_MASK   (0x3FUL << FLASH_ADDR_MODE_SOFT_RESET_RESCUE_SEQUENCE_SHIFT) /**< @brief Soft Reset and Rescue Sequence Support bit mask */
#define FLASH_ADDR_MODE_WE_INST_STATUS_REG1_SHIFT         (0UL)  /**< @brief Volatile or Non-Volatile Register and Write Enable Instruction for Status Register 1 bit position */
#define FLASH_ADDR_MODE_WE_INST_STATUS_REG1_MASK          (0x7FUL << FLASH_ADDR_MODE_WE_INST_STATUS_REG1_SHIFT) /**< @brief Volatile or Non-Volatile Register and Write Enable Instruction for Status Register 1 bit mask */
/** @} */

/**
  @name Flash SFDP fast read 5 type (DWord 17)
  @{
  @brief Flash SFDP fast read 5 type

  This DWord contains the following informations:
      Fast Read (1S-8S-8S) (1S-1S-8S)
          - Wait States
          - Mode Bit Clocks
          - Instruction for read

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead5Type;           /**< @brief typedef for SFDP fast read 5 parameter */
#define FLASH_FAST_READ5_1S_1S_8S_FAST_READ_INSTRUCTION_SHIFT  (24UL) /**< @brief (1S-1S-8S) Fast Read Instruction bit position */
#define FLASH_FAST_READ5_1S_1S_8S_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ5_1S_1S_8S_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1S-1S-8S) Fast Read Instruction bit mask */
#define FLASH_FAST_READ5_1S_1S_8S_FAST_READ_MODE_BITS_SHIFT    (21UL) /**< @brief (1S-1S-8S) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ5_1S_1S_8S_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ5_1S_1S_8S_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1S-1S-8S) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ5_1S_1S_8S_FAST_READ_WAIT_STATES_SHIFT  (16UL) /**< @brief (1S-1S-8S) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ5_1S_1S_8S_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ5_1S_1S_8S_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1S-1S-8S) Fast Read Number of Wait states (dummy clocks) bit mask */
#define FLASH_FAST_READ5_1S_8S_8S_FAST_READ_INSTRUCTION_SHIFT  (8UL)  /**< @brief (1S-8S-8S) Fast Read Instruction bit position */
#define FLASH_FAST_READ5_1S_8S_8S_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ5_1S_8S_8S_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1S-8S-8S) Fast Read Instruction bit mask */
#define FLASH_FAST_READ5_1S_8S_8S_FAST_READ_MODE_BITS_SHIFT    (5UL)  /**< @brief (1S-8S-8S) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ5_1S_8S_8S_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ5_1S_8S_8S_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1S-8S-8S) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ5_1S_8S_8S_FAST_READ_WAIT_STATES_SHIFT  (0UL)  /**< @brief (1S-8S-8S) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ5_1S_8S_8S_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ5_1S_8S_8S_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1S-8S-8S) Fast Read Number of Wait states (dummy clocks) bit mask */
/** @} */

/**
  @name Flash SFDP Octal mode info 0 type (DWord 18)
  @{
  @brief Flash SFDP Octal mode 0 info type

  This DWord contains,
      - Octal commands
      - Byte order
      - Data strobe
      - JEDEC SPI Protocol Reset

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_OctalInfo0Type;               /**< @brief typedef for Octal mode 0 info parameter */
#define FLASH_OCTAL_INFO0_BYTE_ORDER_8D_8D_8D_SHIFT             (31UL) /**< @brief Byte Order in (8D-8D-8D) mode bit position */
#define FLASH_OCTAL_INFO0_BYTE_ORDER_8D_8D_8D_MASK              (1UL << FLASH_OCTAL_INFO0_BYTE_ORDER_8D_8D_8D_SHIFT) /**< @brief Byte Order in (8D-8D-8D) mode bit mask */
#define FLASH_OCTAL_INFO0_COMMAND_8D_8D_8D_SHIFT                (29UL) /**< @brief Octal DTR (8D-8D-8D) Command and Command Extension bit position */
#define FLASH_OCTAL_INFO0_COMMAND_8D_8D_8D_MASK                 (0x3UL << FLASH_OCTAL_INFO0_COMMAND_8D_8D_8D_SHIFT) /**< @brief Octal DTR (8D-8D-8D) Command and Command Extension bit mask */
#define FLASH_OCTAL_INFO0_DATA_STROBE_SUPPORT_4S_4D_4D_SHIFT    (27UL) /**< @brief Data Strobe support for QPI DTR mode (4S-4D-4D) bit position */
#define FLASH_OCTAL_INFO0_DATA_STROBE_SUPPORT_4S_4D_4D_MASK     (1UL << FLASH_OCTAL_INFO0_DATA_STROBE_SUPPORT_4S_4D_4D_SHIFT) /**< @brief Data Strobe support for QPI DTR mode (4S-4D-4D) bit mask */
#define FLASH_OCTAL_INFO0_DATA_STROBE_SUPPORT_4S_4S_4S_SHIFT    (26UL) /**< @brief Data Strobe support for QPI DTR mode (4S-4S-4S) bit position */
#define FLASH_OCTAL_INFO0_DATA_STROBE_SUPPORT_4S_4S_4S_MASK     (1UL << FLASH_OCTAL_INFO0_DATA_STROBE_SUPPORT_4S_4S_4S_SHIFT) /**< @brief Data Strobe support for QPI DTR mode (4S-4S-4S) bit mask */
#define FLASH_OCTAL_INFO0_DATA_STROBE_WAVE_STR_MODE_SHIFT       (24UL) /**< @brief Data Strobe Waveforms in STR Mode bit position */
#define FLASH_OCTAL_INFO0_DATA_STROBE_WAVE_STR_MODE_MASK        (0x3UL << FLASH_OCTAL_INFO0_DATA_STROBE_WAVE_STR_MODE_SHIFT) /**< @brief Data Strobe Waveforms in STR Mode bit mask */
#define FLASH_OCTAL_INFO0_JEDEC_SPI_PROTOCOL_RESET_SHIFT        (23UL) /**< @brief JEDEC SPI Protocol Reset (In-Band Reset) bit position */
#define FLASH_OCTAL_INFO0_JEDEC_SPI_PROTOCOL_RESET_MASK         (1UL << FLASH_OCTAL_INFO0_JEDEC_SPI_PROTOCOL_RESET_SHIFT) /**< @brief JEDEC SPI Protocol Reset (In-Band Reset) bit mask */
#define FLASH_OCTAL_INFO0_OUTPUT_DRIVER_STRENGTH_SHIFT          (18UL) /**< @brief Variable Output Driver Strength bit position */
#define FLASH_OCTAL_INFO0_OUTPUT_DRIVER_STRENGTH_MASK           (0x1FUL << FLASH_OCTAL_INFO0_OUTPUT_DRIVER_STRENGTH_SHIFT) /**< @brief Variable Output Driver Strength bit mask */
/** @} */

/**
  @name Flash SFDP Octal mode info 1 type (DWord 19)
  @{
  @brief Flash SFDP Octal mode 1 info type

  This DWord contains,
      - Octal Enable Requirements
      - 8D-8D-8D Mode Enable/Disable Sequences
      - 0-8-8 Entry/Exit Methods and Support

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_OctalInfo1Type;               /**< @brief typedef for Octal mode 1 info parameter */
#define FLASH_OCTAL_INFO1_OCTAL_EN_REQ_SHIFT                    (20UL) /**< @brief Octal Enable Requirements bit position */
#define FLASH_OCTAL_INFO1_OCTAL_EN_REQ_MASK                     (0x7UL << FLASH_OCTAL_INFO1_OCTAL_EN_REQ_SHIFT) /**< @brief Octal Enable Requirements bit mask */
#define FLASH_OCTAL_INFO1_0_8_8_ENTRY_METHOD_SHIFT              (16UL) /**< @brief (0-8-8) Mode Entry Method bit position */
#define FLASH_OCTAL_INFO1_0_8_8_ENTRY_METHOD_MASK               (0xFUL << FLASH_OCTAL_INFO1_0_8_8_ENTRY_METHOD_SHIFT) /**< @brief (0-8-8) Mode Entry Method bit mask */
#define FLASH_OCTAL_INFO1_0_8_8_EXIT_METHOD_SHIFT               (10UL) /**< @brief (0-8-8) Mode Exit Method bit position */
#define FLASH_OCTAL_INFO1_0_8_8_EXIT_METHOD_MASK                (0x3FUL << FLASH_OCTAL_INFO1_0_8_8_EXIT_METHOD_SHIFT) /**< @brief (0-8-8) Mode Exit Method bit mask */
#define FLASH_OCTAL_INFO1_0_8_8_MODE_SUPPORTED_SHIFT            (9UL)  /**< @brief (0-8-8) Mode Supported bit position */
#define FLASH_OCTAL_INFO1_0_8_8_MODE_SUPPORTED_MASK             (0xFUL << FLASH_OCTAL_INFO1_0_8_8_MODE_SUPPORTED_SHIFT) /**< @brief (0-8-8) Mode Supported bit mask */
#define FLASH_OCTAL_INFO1_8S_8S_8S_ENABLE_SEQUENCE_SHIFT        (4UL)  /**< @brief (8s-8s-8s) Mode enable sequences bit position */
#define FLASH_OCTAL_INFO1_8S_8S_8S_ENABLE_SEQUENCE_MASK         (0x1FUL << FLASH_OCTAL_INFO1_8S_8S_8S_ENABLE_SEQUENCE_SHIFT) /**< @brief (8s-8s-8s) Mode enable sequences bit mask */
#define FLASH_OCTAL_INFO1_8S_8S_8S_DISABLE_SEQUENCE_SHIFT       (0UL)  /**< @brief (8s-8s-8s) Mode disable sequences bit position */
#define FLASH_OCTAL_INFO1_8S_8S_8S_DISABLE_SEQUENCE_MASK        (0xFUL << FLASH_OCTAL_INFO1_8S_8S_8S_DISABLE_SEQUENCE_SHIFT) /**< @brief (8s-8s-8s) Mode disable sequences bit mask */
/** @} */

/**
  @name Flash SFDP Maximum operating speeds type (DWord 20)
  @{
  @brief Flash SFDP Maximum operating speeds info type

  This DWord contains Maximum operating speeds with & without data strobe

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_MaxSpeedType;            /**< @brief typedef for Maximum operating speeds parameter */
#define FLASH_MAX_SPEED_8D_8D_8D_WITH_DS_SHIFT      (28UL) /**< @brief Maximum operation speed of device in 8D-8D-8D mode when utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_8D_8D_8D_WITH_DS_MASK       (0xFUL << FLASH_MAX_SPEED_8D_8D_8D_WITH_DS_SHIFT) /**< @brief Maximum operation speed of device in 8D-8D-8D mode when utilizing Data Strobe bit mask */
#define FLASH_MAX_SPEED_8D_8D_8D_WITHOUT_DS_SHIFT   (24UL) /**< @brief Maximum operation speed of device in 8D-8D-8D mode when not utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_8D_8D_8D_WITHOUT_DS_MASK    (0xFUL << FLASH_MAX_SPEED_8D_8D_8D_WITHOUT_DS_SHIFT) /**< @brief Maximum operation speed of device in 8D-8D-8D mode when not utilizing Data Strobe bit mask */
#define FLASH_MAX_SPEED_8S_8S_8S_WITH_DS_SHIFT      (20UL) /**< @brief Maximum operation speed of device in 8S-8S-8S mode when utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_8S_8S_8S_WITH_DS_MASK       (0xFUL << FLASH_MAX_SPEED_8S_8S_8S_WITH_DS_SHIFT) /**< @brief Maximum operation speed of device in 8S-8S-8S mode when utilizing Data Strobe bit mask */
#define FLASH_MAX_SPEED_8S_8S_8S_WITHOUT_DS_SHIFT   (16UL) /**< @brief Maximum operation speed of device in 8S-8S-8S mode when not utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_8S_8S_8S_WITHOUT_DS_MASK    (0xFUL << FLASH_MAX_SPEED_8S_8S_8S_WITHOUT_DS_SHIFT) /**< @brief Maximum operation speed of device in 8S-8S-8S mode when not utilizing Data Strobe bit mask */
#define FLASH_MAX_SPEED_4S_4D_4D_WITH_DS_SHIFT      (12UL) /**< @brief Maximum operation speed of device in 4S-4D-4D mode when utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_4S_4D_4D_WITH_DS_MASK       (0xFUL << FLASH_MAX_SPEED_4S_4D_4D_WITH_DS_SHIFT) /**< @brief Maximum operation speed of device in 4S-4D-4D mode when utilizing Data Strobe bit mask */
#define FLASH_MAX_SPEED_4S_4D_4D_WITHOUT_DS_SHIFT   (8UL)  /**< @brief Maximum operation speed of device in 4S-4D-4D mode when not utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_4S_4D_4D_WITHOUT_DS_MASK    (0xFUL << FLASH_MAX_SPEED_4S_4D_4D_WITHOUT_DS_SHIFT) /**< @brief Maximum operation speed of device in 4S-4D-4D mode when not utilizing Data Strobe bit mask */
#define FLASH_MAX_SPEED_4S_4S_4S_WITH_DS_SHIFT      (4UL)  /**< @brief Maximum operation speed of device in 4S-4S-4S mode when utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_4S_4S_4S_WITH_DS_MASK       (0xFUL << FLASH_MAX_SPEED_4S_4S_4S_WITH_DS_SHIFT) /**< @brief Maximum operation speed of device in 4S-4S-4S mode when utilizing Data Strobe bit mask */
#define FLASH_MAX_SPEED_4S_4S_4S_WITHOUT_DS_SHIFT   (0UL)  /**< @brief Maximum operation speed of device in 4S-4S-4S mode when not utilizing Data Strobe bit position */
#define FLASH_MAX_SPEED_4S_4S_4S_WITHOUT_DS_MASK    (0xFUL << FLASH_MAX_SPEED_4S_4S_4S_WITHOUT_DS_SHIFT) /**< @brief Maximum operation speed of device in 4S-4S-4S mode when not utilizing Data Strobe bit mask */
/** @} */

/**
  @name Flash SFDP fast read 6 type (DWord 21)
  @{
  @brief Flash SFDP fast read 6 type

  This DWord contains Fast Read (1S-1D-1D), (1S-2D-2D), (1S-4D-4D), and
  (4S-4D-4D) Support Information

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead6Type;           /**< @brief typedef for SFDP fast read 6 parameter */
#define FLASH_FAST_READ6_4S_4D_4D_FAST_READ_SUPPORT_SHIFT      (3UL) /**< @brief Supports (4S-4D-4D) Fast Read bit position */
#define FLASH_FAST_READ6_4S_4D_4D_FAST_READ_SUPPORT_MASK       (1UL << FLASH_FAST_READ6_4S_4D_4D_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (4S-4D-4D) Fast Read bit mask */
#define FLASH_FAST_READ6_1S_4D_4D_FAST_READ_SUPPORT_SHIFT      (2UL) /**< @brief Supports (1S-4D-4D) Fast Read bit position */
#define FLASH_FAST_READ6_1S_4D_4D_FAST_READ_SUPPORT_MASK       (1UL << FLASH_FAST_READ6_1S_4D_4D_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (1S-4D-4D) Fast Read bit mask */
#define FLASH_FAST_READ6_1S_2D_2D_FAST_READ_SUPPORT_SHIFT      (1UL) /**< @brief Supports (1S-2D-2D) Fast Read bit position */
#define FLASH_FAST_READ6_1S_2D_2D_FAST_READ_SUPPORT_MASK       (1UL << FLASH_FAST_READ6_1S_2D_2D_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (1S-2D-2D) Fast Read bit mask */
#define FLASH_FAST_READ6_1S_1D_1D_FAST_READ_SUPPORT_SHIFT      (0UL) /**< @brief Supports (1S-1D-1D) Fast Read bit position */
#define FLASH_FAST_READ6_1S_1D_1D_FAST_READ_SUPPORT_MASK       (1UL << FLASH_FAST_READ6_1S_1D_1D_FAST_READ_SUPPORT_SHIFT) /**< @brief Supports (1S-1D-1D) Fast Read bit mask */
/** @} */

/**
  @name Flash SFDP fast read 7 type (DWord 22)
  @{
  @brief Flash SFDP fast read 7 type

  This DWord contains the following informations:
      Fast Read (1S-1D-1D) and (1S-2D-2D)
          - Wait States
          - Mode Bit Clocks
          - Instruction for read

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead7Type;           /**< @brief typedef for SFDP fast read 7 parameter */
#define FLASH_FAST_READ7_1S_2D_2D_FAST_READ_INSTRUCTION_SHIFT  (24UL) /**< @brief (1S-2D-2D) Fast Read Instruction bit position */
#define FLASH_FAST_READ7_1S_2D_2D_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ7_1S_2D_2D_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1S-2D-2D) Fast Read Instruction bit mask */
#define FLASH_FAST_READ7_1S_2D_2D_FAST_READ_MODE_BITS_SHIFT    (21UL) /**< @brief (1S-2D-2D) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ7_1S_2D_2D_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ7_1S_2D_2D_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1S-2D-2D) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ7_1S_2D_2D_FAST_READ_WAIT_STATES_SHIFT  (16UL) /**< @brief (1S-2D-2D) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ7_1S_2D_2D_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ7_1S_2D_2D_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1S-2D-2D) Fast Read Number of Wait states (dummy clocks) bit mask */
#define FLASH_FAST_READ7_1S_1D_1D_FAST_READ_INSTRUCTION_SHIFT  (8UL)  /**< @brief (1S-1D-1D) Fast Read Instruction bit position */
#define FLASH_FAST_READ7_1S_1D_1D_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ7_1S_1D_1D_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1S-1D-1D) Fast Read Instruction bit mask */
#define FLASH_FAST_READ7_1S_1D_1D_FAST_READ_MODE_BITS_SHIFT    (5UL)  /**< @brief (1S-1D-1D) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ7_1S_1D_1D_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ7_1S_1D_1D_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1S-1D-1D) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ7_1S_1D_1D_FAST_READ_WAIT_STATES_SHIFT  (0UL)  /**< @brief (1S-1D-1D) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ7_1S_1D_1D_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ7_1S_1D_1D_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1S-1D-1D) Fast Read Number of Wait states (dummy clocks) bit mask */
/** @} */

/**
  @name Flash SFDP fast read 8 type (DWord 22)
  @{
  @brief Flash SFDP fast read 8 type

  This DWord contains the following informations:
      Fast Read (1S-4D-4D) and (4S-4D-4D)
          - Wait States
          - Mode Bit Clocks
          - Instruction for read

  @trace #BRCM_SWREQ_FLASH
*/
typedef FLASH_SFDPDWordType FLASH_FastRead8Type;           /**< @brief typedef for SFDP fast read 8 parameter */
#define FLASH_FAST_READ8_4S_4D_4D_FAST_READ_INSTRUCTION_SHIFT  (24UL) /**< @brief (4S-4D-4D) Fast Read Instruction bit position */
#define FLASH_FAST_READ8_4S_4D_4D_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ8_4S_4D_4D_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (4S-4D-4D) Fast Read Instruction bit mask */
#define FLASH_FAST_READ8_4S_4D_4D_FAST_READ_MODE_BITS_SHIFT    (21UL) /**< @brief (4S-4D-4D) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ8_4S_4D_4D_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ8_4S_4D_4D_FAST_READ_MODE_BITS_SHIFT) /**< @brief (4S-4D-4D) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ8_4S_4D_4D_FAST_READ_WAIT_STATES_SHIFT  (16UL) /**< @brief (4S-4D-4D) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ8_4S_4D_4D_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ8_4S_4D_4D_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (4S-4D-4D) Fast Read Number of Wait states (dummy clocks) bit mask */
#define FLASH_FAST_READ8_1S_4D_4D_FAST_READ_INSTRUCTION_SHIFT  (8UL)  /**< @brief (1S-4D-4D) Fast Read Instruction bit position */
#define FLASH_FAST_READ8_1S_4D_4D_FAST_READ_INSTRUCTION_MASK   (0xFFUL << FLASH_FAST_READ8_1S_4D_4D_FAST_READ_INSTRUCTION_SHIFT) /**< @brief (1S-4D-4D) Fast Read Instruction bit mask */
#define FLASH_FAST_READ8_1S_4D_4D_FAST_READ_MODE_BITS_SHIFT    (5UL)  /**< @brief (1S-4D-4D) Fast Read Number of Mode Bits bit position */
#define FLASH_FAST_READ8_1S_4D_4D_FAST_READ_MODE_BITS_MASK     (0x7UL << FLASH_FAST_READ8_1S_4D_4D_FAST_READ_MODE_BITS_SHIFT) /**< @brief (1S-4D-4D) Fast Read Number of Mode Bits bit mask */
#define FLASH_FAST_READ8_1S_4D_4D_FAST_READ_WAIT_STATES_SHIFT  (0UL)  /**< @brief (1S-4D-4D) Fast Read Number of Wait states (dummy clocks) bit position */
#define FLASH_FAST_READ8_1S_4D_4D_FAST_READ_WAIT_STATES_MASK   (0x1FUL << FLASH_FAST_READ8_1S_4D_4D_FAST_READ_WAIT_STATES_SHIFT) /**< @brief (1S-4D-4D) Fast Read Number of Wait states (dummy clocks) bit mask */
/** @} */

/**
    @brief Flash Get Device Capabilities(SFDP) structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_DevCapabiltiesType {
    uint32_t hwID;                                             /**< @brief Flash ID                      */
    uint8_t  versionMajor;                                     /**< @brief SFDP Version Major            */
    uint8_t  versionMinor;                                     /**< @brief SFDP Version Minor            */
    uint8_t  noOfParams;                                       /**< @brief SFDP No.of Valid Parameters   */
    uint8_t  resv1;                                            /**< @brief Reserved                      */
    uint32_t resv2[2];                                         /**< @brief Reserved                      */
    FLASH_SFDPDWordType paramList[FLASH_MAX_SFDP_PARAMETERS];  /**< @brief SFDP Parameters List (DWords) */
} FLASH_DevCapabiltiesType;
BCM_STATIC_SIZE_ASSERT(FLASH_DevCapabiltiesType, 216UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Flash parameters information structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_ParametersInfoType {
    uint8_t  versionMajorSFDP;                                        /**< @brief SFDP Version Major             */
    uint8_t  versionMinorSFDP;                                        /**< @brief SFDP Version Minor             */
    uint8_t  noOfParamID;                                             /**< @brief SFDP No.of Valid Parameters ID */
    uint8_t  accessProtocol;                                          /**< @brief SFDP Access Protocol           */
    FLASH_SFDPParamIDType paramIDList[FLASH_MAX_PARAMETERS_ID_LIST];  /**< @brief SFDP Parameters ID List        */
    uint32_t resv[10];                                                /**< @brief Reserved                       */
} FLASH_ParametersInfoType;
BCM_STATIC_SIZE_ASSERT(FLASH_ParametersInfoType, 104UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Flash parameters information message structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_ParametersInfoMsgType {
    uint32_t hwID;                                                    /**< @brief Flash Hardware ID              */
    FLASH_ParametersInfoType  paramsInfo;                             /**< @brief SFDP Parameters information    */
} FLASH_ParametersInfoMsgType;
BCM_STATIC_SIZE_ASSERT(FLASH_ParametersInfoMsgType, 108UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Flash read parameter data structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_ReadParameterDataType {
    uint8_t  versionMajor;                                     /**< @brief Parameter Data Version Major  */
    uint8_t  versionMinor;                                     /**< @brief Parameter Data Version Minor  */
    uint8_t  noOfParamData;                                    /**< @brief SFDP No.of Parameter Data     */
    FLASH_SFDPDWordType paramData[FLASH_MAX_SFDP_PARAMETERS];  /**< @brief SFDP Parameters Read (DWords) */
    uint32_t resv[10];                                         /**< @brief Reserved                      */
} FLASH_ReadParameterDataType;
BCM_STATIC_SIZE_ASSERT(FLASH_ReadParameterDataType, 244UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
    @brief Flash read parameter data message structure

    @trace #BRCM_SWREQ_FLASH
 */
typedef struct sFLASH_ReadParameterDataMsgType {
    uint32_t hwID;                                             /**< @brief Flash Hardware ID              */
    FLASH_SFDPParamIDType parameterID;                         /**< @brief Paramter ID to be read        */
    FLASH_ReadParameterDataType paramData;                     /**< @brief Parameter data structure      */
} FLASH_ReadParameterDataMsgType;
BCM_STATIC_SIZE_ASSERT(FLASH_ReadParameterDataMsgType, 252UL, FLASH_RPC_MAX_PAYLOAD_SIZE)

/**
  @brief Flash Module Command Handle

  @trace #BRCM_SWREQ_FLASH
*/
typedef union uFLASH_HandleType {
    FLASH_RpcReadInfoType          rpcReadInfo;
    FLASH_RpcWriteInfoType         rpcWriteInfo;
    FLASH_RpcEraseInfoType         rpcEraseInfo;
    FLASH_ImglCmdInfoType          imglCmdInfo;
    FLASH_DevCapabiltiesType       devCapablities;
    FLASH_FlashIDMsgType           flashIDMsg;
    FLASH_ParametersInfoMsgType    paramInfoMsg;
    FLASH_ReadParameterDataMsgType paramDataMsg;
    uint8_t                        data[FLASH_RPC_MAX_PAYLOAD_SIZE];
} FLASH_HandleType;
BCM_STATIC_SIZE_ASSERT(FLASH_HandleType, FLASH_RPC_MAX_PAYLOAD_SIZE, FLASH_RPC_MAX_PAYLOAD_SIZE)

/** @brief Erase flash

    API to erase flash sector.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash start address for operation. It shall be
                                a Flash sector/sub-sector size aligned address

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash erase
                                        operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aAddr is not aligned to sector boundary)
    @retval     #BCM_ERR_BUSY           API is called before completion of previous
                                        flash operation

    @post None

    @trace #BRCM_SWREQ_FLASH

    @limitations None
*/
extern int32_t FLASH_EraseSector(BCM_HandleType aConnHdl,
                                   uint32_t aID,
                                   uint32_t aAddr);

/** @brief Flash Page write

    API to write flash from aAddr  of a page size.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash start address for operation. It shall be
                                Flash page size aligned address.
    @param[in]      aBuf        Pointer to input data buffer

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash write operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aBuf is NULL) or
                                        (aAddr unaligned to flash page boundary) or
    @retval     #BCM_ERR_BUSY           API called before completion of previous
                                        flash operation

    @post None

    @trace #BRCM_SWREQ_FLASH

    @limitations None
*/
extern int32_t FLASH_WritePage(BCM_HandleType aConnHdl,
                                uint32_t aID,
                                uint32_t aAddr,
                                const uint8_t *const aBuf);

/** @brief Flash Page read

    API to read flash from aAddr of a page size.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Controller ID
    @param[in]      aAddr       Flash address
    @param[out]     aBuf        Pointer to output data buffer

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash read operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or
                                        (aBuf is NULL) or
                                        (aAddr unaligned to flash page boundary) or
    @retval     #BCM_ERR_BUSY           API called when previous operation in progress

    @post None

    @trace #BRCM_SWREQ_FLASH

    @limitations None
*/
extern int32_t FLASH_ReadPage(BCM_HandleType aConnHdl,
                                uint32_t aID,
                                uint32_t aAddr,
                                uint8_t *const aBuf);

/** @brief Flash Get Device Capabilities (SFDP)

    API to get the device capabilities (SFDP) from flash.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl    Connection handle (from RPC_Connect)
    @param[in]      aID         Controller ID
    @param[out]     aInfo       Pointer to SFDP data buffer

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully initiated flash read operation
    @retval     #BCM_ERR_INVAL_PARAMS   (aID is invalid) or (aInfo is NULL)
    @retval     #BCM_ERR_UNKNOWN        Flash does not support SFDP

    @post None

    @trace #BRCM_SWREQ_FLASH

    @limitations None
*/
extern int32_t FLASH_GetDevCapabilties(BCM_HandleType aConnHdl,
                                       uint32_t aID,
                                       FLASH_DevCapabiltiesType *const aInfo);

/** @brief Get Flash ID

    API to read the flash ID.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
    @param[in]      aID              Controller ID
    @param[out]     aFlashID         Pointer to flash ID

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully read parameter information
    @retval     #BCM_ERR_INVAL_PARAMS   aFlashID is NULL

    @post None

    @trace #BRCM_SWREQ_FLASH

    @limitations None
*/
extern int32_t FLASH_GetFlsID(BCM_HandleType aConnHdl, uint32_t aID,
                              FLASH_IDType *const aFlashID);

/** @brief Flash get parameters information (SFDP)

    API to read the parameters information (SFDP) from flash.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
    @param[in]      aID              Controller ID
    @param[out]     aParameterInfo   Pointer to SFDP parameters information

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully read parameter information
    @retval     #BCM_ERR_INVAL_PARAMS   aParameterInfo is NULL

    @post None

    @trace #BRCM_SWREQ_FLASH

    @limitations None
*/
extern int32_t FLASH_GetParamInfo(BCM_HandleType aConnHdl,
                                  uint32_t aID,
                                  FLASH_ParametersInfoType *const aParameterInfo);

/** @brief Flash get parameter data (SFDP)

    API to read the parameter data (SFDP) of the paramter ID from flash.

    @behavior Async, Re-entrant

    @pre None

    @param[in]      aConnHdl         Connection handle (from RPC_Connect)
    @param[in]      aID              Controller ID
    @param[in]      aParamID         Parameter ID to read
    @param[out]     aParameterData   Pointer to SFDP parameter data

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully read parameter data
    @retval     #BCM_ERR_INVAL_PARAMS   aParameterData is NULL

    @post None

    @trace #BRCM_SWREQ_FLASH

    @limitations None
*/
extern int32_t FLASH_ReadParamData(BCM_HandleType aConnHdl,
                                   uint32_t aID,
                                   FLASH_SFDPParamIDType aParamID,
                                   FLASH_ReadParameterDataType *const aParameterData);


#endif /* NVM_FLASH_H */
/** @} */
