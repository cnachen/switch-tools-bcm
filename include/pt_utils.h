/*****************************************************************************
 Copyright 2016-2023 Broadcom Limited.  All rights reserved.

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
    @defgroup grp_ptu_ifc Interface
    @ingroup grp_ptu

    @addtogroup grp_ptu_ifc
    @{

    @subsection subsec_pt_ptable Partition Table
    There are upto sixteen copies of Partition Table located at the beginning of Flash. Partition Table contains one Partition
    Table Header (#PTBL_HdrType) followed by a maximum of Eleven Partition Table Entries (#PTBL_EntryType). Each PT copy is
    256 bytes (36 bytes of PT Header and 11 x 20 bytes of PT Entry). All four copies fit into first four pages of the
    Flash.
    <BR>Content of all PT Entries together can be validated with a CRC field in PT Header. However, PT Header is not
    validated with any CRC (only magic in PT Header is validated). The “magicNumber” field in PT Header is validated
    before using it. The “errDetCode” in PT Header is validated with PT Entries before using PT Entries. Each valid PT
    Entry points to a unique partition in flash.
    @subsection subsec_pt_ptable Image Partition
    Each Partition pointed by PT Entry contains Image Header, ‘N’ Image Entries and ‘N’ Images. Images can be left blank
    if it needs to be updated by Bootloader/Firmware. For BootROM to load and execute Bootloader/Firmware, Executable
    binary (bin extracted from ELF) shall be placed in the first Image Entry.
    Image Header must be located (in Flash) at the address specified in “addr” field (Flash offset) in #PTBL_EntryType.
    Image Entries must immediately follow Image Header. Images need not be located immediately after last Image Entry.
    <BR>Each Image can be validated with a CRC field present in Image Entry. All Image Entries together can be validated
    with CRC field present in Image Header. However, Image Header cannot be validated with CRC (Only magic is checked in
    Image Header). BootROM validates Image Header, Image Entries and executable image before using it.
    <BR>For Flash Sector/Subsector alignment requirements, refer to Service Update Process.
    @subsection subsec_pt_blpart Bootloader Partition
    Bootloader (Code+Data) binary shall be the only entry in the Bootloader partitions.
    @subsection subsec_fw_part Firmware Partition
    This partion contains executable images related to firmware and transceiver configuration images for quick usage.
    Refer to Service Update Process for safely updating this partition.
    @subsection subsec_syscfg_part System Config Partition
    All configuration images needed for a safe execution of application/usecase must be placed in this Partition.
    This partition is used only by Firmware. Refer to Service Update Process for safely updating this partition.
    @subsection subsec_ud_part Userdata Partition
    Design limits Firmware to write only to this partition. User profile information, auxiliary information, and other
    miscellaneous information that is not critical for basic application/usecase can be placed here. For example,
    changes in Propagation delay on BroadR-Reach can be preserved here. This partition is not marked for read-only
    access in PT Entry.
    @subsection subsec_crash_part Crash Partition
    This partition is used by Bootloader to preserve critical memory regions and CPU status for debugging later.
    Bootloader shall look for an empty image entry (actualSize = 0 in Image Entry), update the partition with crash
    logs/dumps for debugging.

    @limitation All these structure are supposed to be 4-byte aligned

    @file pt_utils.h
    @brief Partition table interface
    This file defines interface for Partition table
    @version 1.0 Import from SADS
*/

#ifndef PT_UTILS_H
#define PT_UTILS_H

#include <stdint.h>
#include <compiler.h>
#include <bcm_comp.h>    /* ITBL_MAX_NUM_ENTRIES defined in makefile */

/**
    @name Partition Table & Image Table Architecture IDs
    @{
    @brief Architecture IDs for Partition & Image Tables

*/
#define BRCM_SWARCH_PTBL_ID_TYPE                 (0x8101U)    /**< @brief #PTBL_IdType                     */
#define BRCM_SWARCH_PTBL_MACRO                   (0x8102U)    /**< @brief #PTBL_MAGIC                      */
#define BRCM_SWARCH_PTBL_ERR_DET_MACRO           (0x8103U)    /**< @brief #PTBL_ERR_DET_NOCODE             */
#define BRCM_SWARCH_PTBL_HDR_TYPE                (0x8104U)    /**< @brief #PTBL_HdrType                    */
#define BRCM_SWARCH_PTBL_ENTRY_TYPE              (0x8105U)    /**< @brief #PTBL_EntryType                  */
#define BRCM_SWARCH_PTBL_TYPE                    (0x8106U)    /**< @brief #PTBL_Type                       */
#define BRCM_SWARCH_ITBL_MACRO                   (0x8107U)    /**< @brief #ITBL_MAGIC                      */
#define BRCM_SWARCH_ITBL_ERR_DET_MACRO           (0x8108U)    /**< @brief #ITBL_ERR_DET_HDR_MASK           */
#define BRCM_SWARCH_ITBL_HDR_TYPE                (0x8109U)    /**< @brief #ITBL_HdrType                    */
#define BRCM_SWARCH_ITBL_ENTRY_TYPE              (0x810AU)    /**< @brief #ITBL_EntryType                  */
#define BRCM_SWARCH_ITBL_TYPE                    (0x810BU)    /**< @brief #ITBL_Type                       */
#define BRCM_SWARCH_ITBL_BL_TYPE                 (0x810CU)    /**< @brief #ITBL_BLType                     */
#define BRCM_SWARCH_PTU_IMG_INFO_TYPE            (0x810DU)    /**< @brief #PTU_ImgInfoType                 */
#define BRCM_SWARCH_PTU_CONSTRUCT_PTBL_PROC      (0x810EU)    /**< @brief #PTU_ConstructPTBL               */
#define BRCM_SWARCH_PTU_GET_PT_ADDR_PROC         (0x810FU)    /**< @brief #PTU_GetPartitionAddr            */
#define BRCM_SWARCH_PTU_GET_IMG_IDS_PROC         (0x8110U)    /**< @brief #PTU_GetImgIDs                   */
#define BRCM_SWARCH_PTU_GET_IMG_INFO_PROC        (0x8111U)    /**< @brief #PTU_GetImgInfo                  */
#define BRCM_SWARCH_PTU_GET_BL_INFO_PROC         (0x8112U)    /**< @brief #PTU_GetBootloaderInfo           */
#define BRCM_SWARCH_PTU_CREATE_PTBL_PROC         (0x8113U)    /**< @brief #PTU_CreatePTBL                  */
#define BRCM_SWARCH_PTU_CREATE_ITBL_PROC         (0x8114U)    /**< @brief #PTU_CreateITBL                  */
#define BRCM_SWARCH_PTU_GET_LOAD_ADDR_PROC       (0x8115U)    /**< @brief #PTU_GetLoadAddress              */
#define BRCM_SWARCH_PTU_TAR_MAGIC_MACRO          (0x8116U)    /**< @brief #PTU_TAR_MAGIC                   */
#define BRCM_SWARCH_PTU_TAR_HDRSIZE_MACRO        (0x8117U)    /**< @brief #PTU_TAR_HDR_SIZE                */
#define BRCM_SWARCH_PTU_TAR_MAX_IMG_COUNT_MACRO  (0x8119U)    /**< @brief #PTU_TAR_MAX_IMG_COUNT           */
#define BRCM_SWARCH_PTU_TAR_FILE_MACRO           (0x811AU)    /**< @brief #PTU_TAR_FILE_HEADER_TOTAL_SIZE  */
#define BRCM_SWARCH_PTU_TAR_IMAGE_INFO_TYPE      (0x811BU)    /**< @brief #PTU_TarImageInfoType            */
#define BRCM_SWARCH_PTU_TAR_DOWNLOADHDR_TYPE     (0x811CU)    /**< @brief #PTU_TarDownloadHdrType          */
#define BRCM_SWARCH_PTU_TAR_VAL_DWNLD_HDR_PROC   (0x811DU)    /**< @brief #PTU_TarValidateDownloadHeader   */
#define BRCM_SWARCH_PTU_TAR_GET_IMAGE_INFO_PROC  (0x811EU)    /**< @brief #PTU_TarGetImageInfo             */
#define BRCM_SWARCH_PTU_CONSTRUCT_ITBL_PROC      (0x811FU)    /**< @brief #PTU_ConstructITBL               */
#define BRCM_SWARCH_PTU_GET_PT_MAX_SIZE_PROC     (0x8120U)    /**< @brief #PTU_GetPartitionMaxSize         */
#define BRCM_SWARCH_PTU_PARSEIMAGE_PROC          (0x8121U)    /**< @brief #PTU_ParseImage                  */
#define BRCM_SWARCH_PTU_GETIMGOFFSET_PROC        (0x8122U)    /**< @brief #PTU_GetImgOffset                */
#define BRCM_SWARCH_PTU_ADD_PID_PROC             (0x8123U)    /**< @brief #PTU_AddPid                      */
#define BRCM_SWARCH_PTBL_HDR_SIZE_MACRO          (0x8124U)    /**< @brief #PTBL_HDR_SIZE                   */
#define BRCM_SWARCH_PTBL_ENTRY_SIZE_MACRO        (0x8125U)    /**< @brief #PTBL_ENTRY_SIZE                 */
#define BRCM_SWARCH_PTBL_SIZE_MACRO              (0x8126U)    /**< @brief #PTBL_SIZE                       */
#define BRCM_SWARCH_ITBL_HDR_SIZE_MACRO          (0x8127U)    /**< @brief #ITBL_HDR_SIZE                   */
#define BRCM_SWARCH_ITBL_ENTRY_SIZE_MACRO        (0x8128U)    /**< @brief #ITBL_ENTRY_SIZE                 */
/** @} */

/**
    @name Partition IDs

    @anchor PTBL_ID_CONSTRUCT

    @{
    @brief Partition ID

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
typedef uint16_t PTBL_IdType;               /**< @brief 16-bit Partition ID     */
#define PTBL_ID_BL              (1U)        /**< @brief Bootloader Partition ID */
#define PTBL_ID_FW              (3U)        /**< @brief Firmware Partition ID   */
#define PTBL_ID_SYSCFG          (5U)        /**< @brief SysCfg Partition ID     */
#define PTBL_ID_CRASH_DUMP      (7U)        /**< @brief Crash Partition ID      */
#define PTBL_ID_SECURE_KEY      (8U)        /**< @brief Secure Key Partition ID */
#define PTBL_ID_USER_DATA       (9U)        /**< @brief User Data Partition ID  */
#define PTBL_ID_TYPE_MASK       (0xFFU)     /**< @brief Partition ID mask       */
#define PTBL_ID_TYPE_SHIFT      (0U)        /**< @brief Partition ID shift      */
#define PTBL_ID_COPY_MASK       (0xF00U)    /**< @brief Partition ID Copy mask  */
#define PTBL_ID_COPY_SHIFT      (8U)        /**< @brief Partition ID Copy shift */
#define PTBL_ID_SKIP_MASK       (0x01U)     /**< @brief Partition ID skip mask  */
#define PTBL_ID_SKIP_SHIFT      (0U)        /**< @brief Partition ID skip shift */
#define PTBL_ID_CONSTRUCT(aPid, aCopyNum)  \
    (((((PTBL_IdType) (aPid)) << (PTBL_ID_TYPE_SHIFT)) & (PTBL_ID_TYPE_MASK)) \
     | ((((PTBL_IdType) (aCopyNum)) << (PTBL_ID_COPY_SHIFT)) & (PTBL_ID_COPY_MASK)))
/** @} */


/**
    @name Partition Table related Macros
    @{
    @brief Partition Table related Macros

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
#define PTBL_MAGIC            (0x5054424CUL)        /**< @brief PT magic number 'P''T''B''L' */
#define PTBL_VERSION          (0x00000001UL)        /**< @brief PT format version */
#define PTBL_MAX_NUM_ENTRIES  (11UL)                /**< @brief Max Number of entries in Parition Table */
#define PTBL_NUM_COPIES       (4UL)                 /**< @brief Number of PT copies in RAM */
#define PTBL_MAX_NUM_COPIES   (3U)                  /**< @brief Max Number of PT entries for same partition copy */
#define PTBL_CRC32_POLY       (0x04C11DB7UL)        /**< @brief CRC polynomial used for generating
                                                        partition table related CRCs */
/** @} */

/**
    @name Partition Table Error Detection Code types
    @{
    @brief Partition Table Error Detection Code Macros

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
#define PTBL_ERR_DET_NOCODE         (0UL)   /**< @brief No error detection code         */
#define PTBL_ERR_DET_CRC            (1UL)   /**< @brief Error detection code CRC        */
#define PTBL_ERR_DET_CHECKSUM       (2UL)   /**< @brief Error detection code Checksum   */
#define PTBL_ERR_DET_MASK        (0x07UL)   /**< @brief PT header flag error detection code mask */
#define PTBL_ERR_DET_SHIFT          (0UL)   /**< @brief PT header flag error detection code shift */
/** @} */

/**
    @name Image Table related macros
    @{
    @brief Image Table related macros

    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
#define ITBL_MAGIC           (0x494D4748UL)         /**< @brief Image magic number 'I''M''G''H' */
#define ITBL_MAGIC_V2        (0x4954424CUL)         /**< @brief Image magic number 'I''T''B''L' */
#define ITBL_VERSION         (0x00000001UL)         /**< @brief Image Table format verison      */
#define ITBL_CRC32_POLY      (0x04C11DB7UL)         /**< @brief CRC polynomial used for generating
                                                        partition table related CRCs */
#define ITBL_ID_EXE_MAX      (0xFU)                 /**< @brief Image ID for the executable image
                                                        ranging from 0 - 0xF */
#define ITBL_SIGNATURE_SIZE   (256UL)               /**< @brief Signature size */
/** @} */

/**
    @name Image Table Error Detection Code types
    @{
    @brief Image Table Error Detection Code Macros

    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
#define ITBL_ERR_DET_HDR_MASK      (0x07UL)     /**< @brief Image header flag error detection code mask */
#define ITBL_ERR_DET_HDR_SHIFT     (0UL)        /**< @brief Image header flag error detection code shift */
#define ITBL_ERR_DET_ENTRY_MASK    (0x1CUL)     /**< @brief Image entry flag error detection code mask */
#define ITBL_ERR_DET_ENTRY_SHIFT   (2UL)        /**< @brief Image entry flag error detection code shift */
/** @} */

/**
    @brief Partition Table Header

    @note hdrErrDetCode member is not used by BootROM of all the chipsets (Refer table below).
    Where as hdrErrDetCode is always used by Bootloader and Firmware.
    |  Chipset          | Description                                       |
    |:-----------------:|:-------------------------------------------------:|
    | BCM8908x          |   Not used by BootROM                             |
    | BCM8910x          |   Not used by BootROM                             |
    | BCM89531          |   Not used by BootROM                             |
    | BCM89541          |   Not used by BootROM                             |
    | BCM89551          |   Not used by BootROM                             |
    | BCM89559          |   Used by BootROM                                 |
    | BCM89559G         |   Used by BootROM                                 |

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
typedef struct COMP_PACKED sPTBL_HdrType {
    uint32_t magicNumber;           /**< @brief Must be set to 0x5054424C (ASCII representation of ‘PTBL’) */
    uint32_t version;               /**< @brief Table format version */
    uint32_t crc;                   /**< @brief 32-bit CRC */
    uint32_t reserved;              /**< @brief Reserved for future use */
    uint32_t flags;                 /**< @brief Bit[0-2] – Type of Error detection mechanism. Must be set to 0x1 */
    uint32_t totalSize;             /**< @brief Must be set to sizeof(PTBL_HdrType) + numEntries * sizeof(PTBL_EntryType) */
    uint32_t loadAddr;              /**< @brief Address in RAM where PT (Hdr + Entries) has to be loaded to.
                                        Must be set to a valid address for BootROM to load it. */
    uint32_t numEntries;            /**< @brief Number of partition entries in PT */
    uint32_t hdrErrDetCode;         /**< @brief PT header error detection code */
} PTBL_HdrType;

/**
    @brief Partition Table Header Structure Size Macro

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
#define PTBL_HDR_SIZE    (sizeof(PTBL_HdrType))     /**< @brief PT header struct size */

/**
    @brief PT entry structure type

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
typedef struct COMP_PACKED sPTBL_EntryType {
    uint32_t flags;                 /**< @brief Bit[0] – BootRom will skip this PT Entry if set to 1
                                            <BR>Bit[1] – If set, Partition Shall be treated as Read only
                                            [Can be used to notify Factory image, never update]
                                            <BR>Bit[2] – QSPI Dual Lane mode [Used by BootROM)
                                            <BR>    0- Single Lane mode
                                            <BR>    1- Dual Lane mode
                                            <BR> Bootloader shall ignore this bit.
                                            <BR>Other bits are reserved */
    uint32_t addr;                  /**< @brief Absolute Flash Address/Offset where the Partition is located */
    uint32_t maxSize;               /**< @brief Set to Zero. Ignored by BootRom */
    PTBL_IdType pid;                 /**< @brief Partition ID
                                            <BR>Bit[0-7] – Partition Type
                                            <BR>Bit[8-15] – Partition Index
                                                [Valid values: 1,2.. numEntries in PT Header] */
    uint16_t resvd1;                /**< @brief Reserved fields */
    uint32_t resvd2;                /**< @brief Reserved fields */
} PTBL_EntryType;

/**
    @brief Partition Table Entry Structure Size Macro

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
#define PTBL_ENTRY_SIZE  (sizeof(PTBL_EntryType))   /**< @brief PT entry struct size */

/**
    @brief Partition Table structure type

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
typedef struct COMP_PACKED sPTBL_Type {
    PTBL_HdrType    hdr;                        /**< @brief Partition Table Header  */
    PTBL_EntryType  entry[PTBL_MAX_NUM_ENTRIES];/**< @brief Partition Table Entries */
} PTBL_Type;

/**
    @brief Partition Table Structure Size Macro

    @trace #BRCM_SWREQ_PTBL_LAYOUT
*/
#define PTBL_SIZE        (sizeof(PTBL_Type))        /**< @brief Parition Table (PT) size (equal to 256,
                                                        same as FLASH_PAGE_SIZE for most of the flashes */

/**
    @brief Image Header

    @note hdrErrDetCode member is not used by BootROM of all the chipsets (Refer table below).
    Where as hdrErrDetCode is always used by Bootloader and Firmware.
    |  Chipset          | Description                                       |
    |:-----------------:|:-------------------------------------------------:|
    | BCM8910x          |   Not used by BootROM                             |
    | BCM89531          |   Not used by BootROM                             |
    | BCM89541          |   Not used by BootROM                             |
    | BCM89551          |   Not used by BootROM                             |
    | BCM89559          |   Used by BootROM                                 |
    | BCM89559G         |   Used by BootROM                                 |


    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
typedef struct COMP_PACKED sITBL_HdrType {
    uint32_t magicNumber;           /**< @brief Must be set to ITBL_MAGIC or ITBL_MAGIC_V2 */
    uint32_t version;               /**< @brief Table version */
    uint64_t timeStamp;             /**< @brief Build time information */
    uint32_t imgVersion;            /**< @brief Image version */
    uint32_t crc;                   /**< @brief 32-bit CRC */
    uint32_t reserved;              /**< @brief Reserved for future use */
    uint32_t flags;                 /**< @brief Must be set to 0x1 */
    uint32_t entryPoint;            /**< @brief Address to which BootROM/Bootloader shall execute “Branch to” to execute
                                        Firmware/Bootloader Must be set appropriately. Refer to Image Entry to know
                                        where the executable is loaded to. */
    uint32_t numImgs;               /**< @brief Number of valid Image Entries (or Images, each Image Entry can point to
                                        only one Image) */
    uint32_t hdrErrDetCode;         /**< @brief Image header error detection code */
} ITBL_HdrType;

/**
    @brief Image Header Structure Size Macro

    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
#define ITBL_HDR_SIZE   (sizeof(ITBL_HdrType))      /**< @brief Image header struct size        */

/**
    @brief Image Entry

    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
typedef struct COMP_PACKED sITBL_EntryType {
    uint32_t flags;                 /**< @brief Bit[0] – Reserved. Must be zero
                                        <BR>Bit[1] – Reserved. Must be zero
                                        <BR>Bit[2-4] – Type of Error detection mechanism. Must be set 0x1.
                                        <BR>Other bits are reserved. Must be set to Zero. */
    uint32_t crc;                   /**< @brief 32-bit CRC */
    uint32_t reserved;              /**< @brief Reserved for future use */
    uint32_t flashOffset;           /**< @brief Offset within Partition to the beginning of Image.
                                        <BR>For flash offset, add this offset to “addr” field in PT Entry. */
    uint32_t actualSize;            /**< @brief Actual size of image to be loaded.
                                        <BR>(Must be less than or equal to maxSize) */
    uint16_t imgType;               /**< @brief Unique Image ID in the partition.
                                        <BR>Each image is uniquely identified with (pid, imgID) pair */
    uint16_t compType;              /**< @brief Compression type (Unused) */
    uint32_t loadAddr;              /**< @brief Address to which the image needs to be loaded to.
                                        <BR>Used by BootROM to load bootloader/firmware to appropriate address.
                                        <BR>Used by Bootloader to load firmware to appropriate address.
                                        <BR>Ignored by Firmware.
                                        <BR>BootROM needs this address (for Bootloader Partition) to be outside BootROM’s
                                        <BR>memory usage. Refer to TRM [15] for details on BootROM memory usage/map. */
    uint32_t maxSize;               /**< @brief Maximum allowed image size.
                                        <BR>Flash memory shall be reserved for maxSize for this image */
    uint32_t resvd2;                /**< @brief Reserved fields. Used for CRC validation on Image Header by Bootloader */
} ITBL_EntryType;

/**
    @brief Image Entry Structure Size Macro

    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
#define ITBL_ENTRY_SIZE (sizeof(ITBL_EntryType))    /**< @brief Image entry struct size         */

/**
    @brief Image Table structure type

    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
typedef struct COMP_PACKED sITBL_Type {
    ITBL_HdrType    hdr;                                /**< @brief Image Table Header  */
    ITBL_EntryType  entry[ITBL_MAX_NUM_ENTRIES];        /**< @brief Image Table Entries */
} ITBL_Type;

/**
    @brief BL Image Table structure type

    @trace #BRCM_SWREQ_ITBL_LAYOUT
*/
typedef struct COMP_PACKED sITBL_BLType {
    ITBL_HdrType    hdr;                                /**< @brief Image Table Header  */
    ITBL_EntryType  entry;                              /**< @brief Image Table Entry */
    uint8_t         signature[ITBL_SIGNATURE_SIZE];     /**< @brief Partition signature */
} ITBL_BLType;

/**
    @brief partition table(PT) Image Information structure type

    @trace #BRCM_SWREQ_PTU
*/
typedef struct sPTU_ImgInfoType {
    uint32_t crc;                   /**< @brief 32-bit CRC */
    uint32_t flashAddr;             /**< @brief Flash address where image is residing */
    uint32_t actualSize;            /**< @brief Actual size of image to be loaded.
                                        <BR>(Must be less than or equal to maxSize) */
    uint32_t loadAddr;              /**< @brief Address to which the image needs to be loaded to.*/
    uint32_t maxSize;               /**< @brief Maximum allowed image size.
                                        <BR>Flash memory shall be reserved for maxSize for this image */
} PTU_ImgInfoType;

/**
    @brief TAR Magic

    TAR Magic definition.

    @trace #BRCM_SWREQ_PTU
*/
#define PTU_TAR_MAGIC                   (0x54415248UL)      /**< @brief Image magic number 'H''R''A''T'  */

/**
    @brief Maximum images in TAR file

    Maximum number of images in TAR file

    @trace #BRCM_SWREQ_PTU
*/
#define PTU_TAR_MAX_IMG_COUNT           (64UL)

/**
    @name TAR File header and name related macros
    @{
    @brief TAR File header and name related macros

    File name syntax is as below.
        'bcm-' + manuf + '-' + model + '-' + rev + '-' + isTbl + pid + imgId + '-' + offset + '-' + maxSz

    @trace #BRCM_SWREQ_PTU
*/
#define PTU_TAR_FILE_HEADER_TOTAL_SIZE           (512UL) /**< @brief File header size            */
#define PTU_TAR_FILE_SIZE_ALIGN                  (512UL) /**< @brief File size alignment         */
#define PTU_TAR_FILE_NAME_PREFIX_LENGTH          (4UL)   /**< @brief File name prefix Length     */
#define PTU_TAR_FILE_NAME_MANUFACTURER_LENGTH    (8UL)   /**< @brief Manufacturer info Length    */
#define PTU_TAR_FILE_NAME_MODEL_LENGTH           (8UL)   /**< @brief Model info Length           */
#define PTU_TAR_FILE_NAME_REV_LENGTH             (8UL)   /**< @brief Revision info Length        */
#define PTU_TAR_FILE_NAME_TBL_LENGTH             (2UL)   /**< @brief TBL info Length             */
#define PTU_TAR_FILE_NAME_PID_LENGTH             (2UL)   /**< @brief PID info Length             */
#define PTU_TAR_FILE_NAME_IMG_ID_LENGTH          (4UL)   /**< @brief IMG ID info Length          */
#define PTU_TAR_FILE_NAME_OFFSET_LENGTH          (8UL)   /**< @brief Offset info Length          */
#define PTU_TAR_FILE_NAME_MAX_SIZE_LENGTH        (8UL)   /**< @brief Max size info Length        */
/** @} */

/**
    @brief TAR image inforamtion structure type

    @trace #BRCM_SWREQ_PTU
*/
typedef struct sPTU_TarImageInfoType {
    uint32_t manuf;                                        /**< @brief Manufacturer       */
    uint32_t model;                                        /**< @brief Model              */
    uint32_t rev;                                          /**< @brief Revision           */
    uint8_t isTbl;                                         /**< @brief Tbl status         */
    uint8_t pid;                                           /**< @brief PID                */
    uint16_t imgID;                                        /**< @brief IMG ID             */
    uint32_t offset;                                       /**< @brief Offset             */
    uint32_t maxSize;                                      /**< @brief Max Size           */
    uint32_t actualSize;                                   /**< @brief Actual Size        */
} PTU_TarImageInfoType;

/**
    @brief TAR download header structure type

    @trace #BRCM_SWREQ_PTU
*/
typedef struct COMP_PACKED sPTU_TarDownloadHdrType {
    uint32_t magicNumber;           /**< @brief Must be set to #PTU_TAR_MAGIC     */
    uint32_t imgSize;               /**< @brief Size of the TAR file              */
    uint32_t flags;                 /**< @brief Configuration flags of Image      */
    uint32_t hdrErrDetCode;         /**< @brief Image header error detection code */
    uint32_t reserved;              /**< @brief Reserved                          */
} PTU_TarDownloadHdrType;

/**
    @brief TAR header size

    This value is size of PTU_TarDownloadHdrType

    @trace #BRCM_SWREQ_PTU
*/
#define PTU_TAR_HDR_SIZE                   (sizeof(PTU_TarDownloadHdrType))

/** @brief Construct partition table(PT)

    Construct the partition table. This validates the given data and
    accepts if correct. API assumes that, the given data is continuous
    chunks of partition tables. It validates till the end of the data
    or a valid partition table is found.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aData     Pointer to the input data
    @param[in]      aSize     Size of the input data in bytes
    @param[out]     aPTBL     Pointer to Partition Table to be populated

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Given data is validated as PT and
                                        aPTBL is updated.
    @retval     #BCM_ERR_DATA_INTEG     Error detection check failed
    @retval     #BCM_ERR_INVAL_PARAMS   @c aSize is less than #PTBL_SIZE
                                        or Given data is not a valid PT

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_ConstructPTBL(const uint8_t* const aData,
                                const uint32_t aSize,
                                PTBL_Type *aPTBL);

/** @brief Get partition address

    Get the partition address to load from flash.

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aPTBL     Pointer to Partition Table
    @param[in]      aPid      Partition ID and copy index as #PTBL_IdType
                              #PTBL_ID_CONSTRUCT can be used to construct.
    @param[out]     aAddr     Pointer to store the address.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
                                        Address is stored in @c aAddr.
    @retval     #BCM_ERR_NOT_FOUND      Given aPid is not found.
    @retval     #BCM_ERR_DATA_INTEG     Image Table integrity check failed
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPTBL is NULL
                                        or @c aAddr is NULL.

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_GetPartitionAddr(const PTBL_Type *aPTBL,
                                    const PTBL_IdType aPid,
                                    uint32_t *const aAddr);

/** @brief Get image IDs

    Get the list of  image IDs in given partition

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aPTBL     Partition Table pointer
    @param[in]      aITBL     Image Table Pointer
    @param[in]      aPid      Partition ID only as #PTBL_IdType.
    @param[out]     aImgID    Pointer to store the image IDs.
    @param[inout]   aSize     Pointer to the size of image ID array.
                              This is used to identify the maximum
                              size of the array @c aImgID.
                              On Success, this would be overwritten
                              with actual number of images present.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
                                        Image information is stored in @c aImgInfo.
    @retval     #BCM_ERR_DATA_INTEG     Image Table integrity check failed
    @retval     #BCM_ERR_DATA_INTEG     Partition Table integrity check failed
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPTBL is NULL
                                        or @c aITBL is NULL
                                        or @c aImgID is NULL
                                        or @c aSize is NULL
                                        or @c *aSize is Zero

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations The image entries order should follow the order of apperance in flash
*/
extern int32_t PTU_GetImgIDs(const PTBL_Type* const aPTBL,
                            const ITBL_Type *aITBL,
                            const PTBL_IdType aPid,
                            uint16_t *const aImgID,
                            uint32_t *const aSize);

/** @brief Get image information

    Get the image information

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aPTBL     Partition Table pointer
    @param[in]      aPid      Partition ID only as #PTBL_IdType.
    @param[in]      aITBL     Image Table pointer
    @param[in]      aImgID    Image ID for which information is needed.
    @param[out]     aImgInfo  Pointer to #PTU_ImgInfoType structure to
                              store the image information.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
                                        Image information is stored in @c aImgInfo.
    @retval     #BCM_ERR_NOT_FOUND      Given aPid or aImgID is not found.
    @retval     #BCM_ERR_DATA_INTEG     Partition Table or Image Table integrity check failed
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPTBL is NULL
                                        or @c aITBL is NULL
                                        or @c aImgInfo is NULL.

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations The image entries order should follow the order of apperance in flash
*/
extern int32_t PTU_GetImgInfo(const PTBL_Type *aPTBL,
                            const PTBL_IdType aPid,
                            const ITBL_Type *aITBL,
                            const uint16_t aImgID,
                            PTU_ImgInfoType *const aImgInfo);

/** @brief Get Load address for bootloader/firmware binaries only

    Get the image load address

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aPTBL           Partition Table pointer
    @param[in]      aITBL           Image Table pointer
    @param[in]      aPid            Partition ID only as #PTBL_IdType.
    @param[in]      aImgID          Image ID for which information is needed.
    @param[out]     aLoadAddress    Image Load address

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
                                        Image Load address is updated
    @retval     #BCM_ERR_NOT_FOUND      Given aPid or aImgID is not found.
    @retval     #BCM_ERR_DATA_INTEG     Partition Table or Image Table integrity check failed
    @retval     #BCM_ERR_INVAL_PARAMS   @c aLoadAddr is NULL
                                        or @c aITBL is NULL
                                        or @c aPTBL is NULL

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations The image entries order should follow the order of apperance in flash
*/
extern int32_t PTU_GetLoadAddress(const PTBL_Type* const aPTBL,
                            const ITBL_Type *aITBL,
                            const PTBL_IdType aPid,
                            const uint16_t aImgID,
                            uint32_t *const aLoadAddr);

/** @brief Get bootloader information

    Get bootloader information

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aPTBL     Partition Table pointer
    @param[in]      aPid      Partition ID only as #PTBL_IdType.
    @param[in]      aITBL     Image Table pointer
    @param[out]     aImgInfo  Pointer to #PTU_ImgInfoType structure to
                              store the image information.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
                                        Image information is stored in @c aImgInfo.
    @retval     #BCM_ERR_NOT_FOUND      Given aPid is not found.
    @retval     #BCM_ERR_DATA_INTEG     Partition Table or Image Table integrity check failed
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPTBL is NULL
                                        or @c aITBL is NULL
                                        or @c aImgInfo is NULL.

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_GetBootloaderInfo(const PTBL_Type *aPTBL,
                                    const PTBL_IdType aPid,
                                    const ITBL_BLType *aITBL,
                                    PTU_ImgInfoType *const aImgInfo);

/** @brief Create PTBL

    Create default partition table

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aPid      Partition ID and copy index as #PTBL_IdType
                              #PTBL_ID_CONSTRUCT can be used to construct.
    @param[in]      aAddr     Image table address
    @param[out]     aPtbl     Pointer to update the table

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPtbl is NULL

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_CreatePTBL(const PTBL_IdType aPid,
                              const uint32_t aAddr,
                              PTBL_Type *const aPtbl);

/** @brief Add pid to PTBL

    Create default partition table if given ptbl is invalid
    Otherwise, add given pid

    @behavior Sync, Non-reentrant

    @pre None

    @param[inout]   aPtbl     Pointer to update the table

    @param[in]      aPid      Partition ID and copy index as #PTBL_IdType
                              #PTBL_ID_CONSTRUCT can be used to construct.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPtbl is NULL

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_AddPid(PTBL_Type *const aPtbl,
                          const PTBL_IdType aPid);

/** @brief Create ITBL

    Create default image table

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]   aImgID        Image ID
    @param[in]   aEntryPoint   Entry point
    @param[in]   aLoadAddress  Image load address
    @param[in]   aImgSize      Image size
    @param[in]   aImgMaxSize   Image maximum size
    @param[out]  aItbl         Pointer to update the table

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPtbl is NULL

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_CreateITBL(const uint16_t aImgID,
                              const uint32_t aEntryPoint,
                              const uint32_t aLoadAddress,
                              const uint32_t aImgSize,
                              const uint32_t aImgMaxSize,
                              ITBL_BLType *const aItbl,
                              const uint32_t aOffset);

/** @brief Vaidate & create ITBL

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aPTBL               Pointer to partition table
    @param[in]      aData               Data buffer
    @param[in]      aSize               Size of the buffer
    @param[in]      aPid                Partition ID only as #PTBL_IdType
    @param[out]     aITBL               Pointer to update the table

    Return values are documented in reverse-chronological order
    @retval     BCM_ERR_OK              If header is valid
    @retval     BCM_ERR_INVAL_PARAMS    If aPTBL or aITBL or aData is NULL or aSize is invalid
    @retval     BCM_ERR_DATA_INTEG      If aPTBL or magic or numImgs is invalid

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations The image entries order should follow the order of apperance in flash
*/
int32_t PTU_ConstructITBL(const PTBL_Type* const aPTBL,
                          const uint8_t* const aData,
                          const uint32_t aSize,
                          PTBL_IdType aPid,
                          ITBL_Type *aITBL);

/** @brief Function to validate the download header

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aHdr    TAR header
    @param[in]      aSize   Size of the buffer

    Return values are documented in reverse-chronological order
    @retval     BCM_ERR_OK              If header is valid
    @retval     BCM_ERR_INVAL_PARAMS    If aHdr is NULL
    @retval     BCM_ERR_DATA_INTEG      If magic or size is invalid

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_TarValidateDownloadHeader(const uint8_t *const aHdr, uint32_t aSize);

/** @brief Function to get the image infor from file header

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aFileHdr    TAR file header buffer
    @param[in]      aSize       Size of the buffer
    @param[out]     aImageInfo  Address to store the image info

    Return values are documented in reverse-chronological order
    @retval     BCM_ERR_OK              If info is valid
    @retval     BCM_ERR_INVAL_PARAMS    If aFileHdr or aImageInfo is NULL

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_TarGetImageInfo(const uint8_t *const aFileHdr, uint32_t aSize, PTU_TarImageInfoType *const aImageInfo);

/** @brief Get partition maximum size

    Get the partition maximum size in flash

    @behavior Sync, Non-reentrant

    @pre None

    @param[in]      aPTBL     Pointer to Partition Table
    @param[in]      aPid      Partition ID only as #PTBL_IdType
    @param[out]     aMaxSize  Pointer to store the maximum size.

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Succesful.
                                        Address is stored in @c aAddr.
    @retval     #BCM_ERR_NOT_FOUND      Given aPid is not found.
    @retval     #BCM_ERR_DATA_INTEG     Image Table integrity check failed
    @retval     #BCM_ERR_INVAL_PARAMS   @c aPTBL is NULL
                                        or @c aAddr is NULL.

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_GetPartitionMaxSize(const PTBL_Type *aPTBL,
                                    const PTBL_IdType aPid,
                                    uint32_t *const aMaxSize);

/** @brief Parse the image information

    Parse the buffer and extract the images information

    @behavior Sync, Non-Reentrant

    @param[in]      aBuff                 Image data buffer
    @param[in]      aBuffSize             Extracted data buffer size
    @param[in]      aImagesInfoBuffCount  Total count of #aImagesInfoBuff array
    @param[out]     aImagesInfoBuff       Pointer to array of image information
    @param[out]     aNumImages            Total number of images in data buffer

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Success
    @retval     #BCM_ERR_UNKNOWN        Unknown error
    @retval     #BCM_ERR_INVAL_PARAMS   Could not open File
    @retval     #BCM_ERR_INVAL_PARAMS   aBuff is NULL or
                                        aBuffSize is 0 or
                                        aImagesInfoBuffCount is 0 or
                                        aImagesInfoBuff is NULL

    @trace  #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_ParseImage(const uint8_t *const aBuff,
                               uint32_t aBuffSize,
                               uint32_t aImagesInfoBuffCount,
                               PTU_TarImageInfoType *const aImagesInfoBuff,
                               uint32_t *const aNumImages);

/** @brief Get the image offset for an image

    Retrive the image offset and size of the image for the given pid and imgID.
    If aIsImgTbl is set to 1 then it returns the offset ans size of the image table.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]   aNumImages            Total number of available images
    @param[in]   aImagesInfoBuff       Parsed image information
    @param[in]   aIsImgTbl             Is Image Table
    @param[in]   aPid                  Partition ID
    @param[in]   aImgID                Image ID
    @param[out]  aImgOffset            Requested image Offset
    @param[out]  aImgSize              Requested image size

    @retval     #BCM_ERR_INVAL_PARAMS   aImagesInfoBuff is NULL or
                                        aImgOffset is NULL
                                        aNumberofImages is 0
    @retval     #BCM_ERR_OK             Success

    @post None

    @trace #BRCM_SWREQ_PTU

    @limitations None
*/
extern int32_t PTU_GetImgOffset(const uint32_t aNumImages,
                                  const PTU_TarImageInfoType *const aImagesInfoBuff,
                                  uint32_t aIsImgTbl,
                                  PTBL_IdType aPid,
                                  uint16_t aImgID,
                                  uint32_t *const aImgOffset,
                                  uint32_t *const aImgSize);
#endif /* PT_UTILS_H */
/** @} */
