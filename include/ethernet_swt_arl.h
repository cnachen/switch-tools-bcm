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
    @defgroup grp_ethernet_swt_arl_ifc Switch ARL abstract Interface
    @ingroup grp_ethernet_abstract

    @addtogroup grp_ethernet_swt_arl_ifc
    @{

    @file ethernet_swt_arl.h

    @brief Abstract ARL Interface
    This file contains the abstract interfaces for ARL

    @version 1.0 Initial version
*/

#ifndef ETHSWT_ABSTRACT_ARL_H
#define ETHSWT_ABSTRACT_ARL_H

#include <ethernet_common.h>
#include <ethernet_swt_common.h>
#include <bcm_utils.h>

/**
    @name ARL API IDs
    @{
    @brief API IDs for ARL
*/
#define BRCM_SWARCH_ETHSWT_ARL_HOST_MAX_ENTRIES_MACRO       (0x8501U) /**< @brief #ETHSWT_ARL_HOST_MAX_ENTRIES     */
#define BRCM_SWARCH_ETHSWT_ARL_MAX_ENTRIES_MACRO            (0x8502U) /**< @brief #ETHSWT_ARL_MAX_ENTRIES          */
#define BRCM_SWARCH_ETHSWT_ARL_RPC_MAX_ENTRIES_MACRO        (0x8503U) /**< @brief #ETHSWT_ARL_RPC_MAX_ENTRIES      */
#define BRCM_SWARCH_ETHSWT_ARLCMDID_TYPE                    (0x8504U) /**< @brief #ETHSWT_ARLCmdIdType             */
#define BRCM_SWARCH_ETHSWT_ARLENTRY_TYPE                    (0x8505U) /**< @brief #ETHSWT_ARLEntryType             */
#define BRCM_SWARCH_ETHSWT_ARLLIST_TYPE                     (0x8506U) /**< @brief #ETHSWT_ARLListType              */
#define BRCM_SWARCH_ETHSWT_ARLMSGUNIONTYPE_                 (0x8507U) /**< @brief #ETHSWT_ARLMsgUnionType          */
#define BRCM_SWARCH_ETHSWT_ARL_MAX_PAYLOAD_SIZE_MACRO       (0x8508U) /**< @brief #ETHSWT_ARL_MAX_PAYLOAD_SIZE     */
#define BRCM_SWARCH_ETHSWT_ARL_ID_OF_MACRO                  (0x8509U) /**< @brief #ETHSWT_ARL_ID_OF                */
#define BRCM_SWARCH_ETHSWT_ARL_V2_RPC_MAX_ENTRIES_MACRO     (0x850AU) /**< @brief #ETHSWT_ARL_V2_RPC_MAX_ENTRIES   */
#define BRCM_SWARCH_ETHSWT_ARLENTRYV2_TYPE                  (0x850BU) /**< @brief #ETHSWT_ARLEntryV2Type           */
#define BRCM_SWARCH_ETHSWT_ARLLISTV2_TYPE                   (0x850CU) /**< @brief #ETHSWT_ARLListV2Type            */
#define BRCM_SWARCH_ETHSWT_ARLADD_PROC                      (0x850DU) /**< @brief #ETHSWT_ARLAdd                   */
#define BRCM_SWARCH_ETHSWT_ARLREMOVE_PROC                   (0x850EU) /**< @brief #ETHSWT_ARLRemove                */
#define BRCM_SWARCH_ETHSWT_ARLDUMP_PROC                     (0x850FU) /**< @brief #ETHSWT_ARLDump                  */
#define BRCM_SWARCH_ETHSWT_ARLENTRYV1_TYPE                  (0x8581U) /**< @brief #ETHSWT_ARLEntryV1Type           */
#define BRCM_SWARCH_ETHSWT_ARLCONFIGV1_TYPE                 (0x8582U) /**< @brief #ETHSWT_ARLConfigV1Type          */
#define BRCM_SWARCH_ETHSWT_ARLCONFIGV2_TYPE                 (0x8583U) /**< @brief #ETHSWT_ARLConfigV2Type          */
#define BRCM_SWARCH_ETHSWT_ARL_REMOVE_BY_PORT_PROC          (0x8584U) /**< @brief #ETHSWT_ARLRemoveByPort          */
#define BRCM_SWARCH_ETHSWT_ARL_FIND_PROC                    (0x8585U) /**< @brief #ETHSWT_ARLFind                  */
#define BRCM_SWARCH_ETHSWT_ARL_GET_PORT_ARL_ENTRIES_MACRO   (0x8586U) /**< @brief #ETHSWT_ARL_GET_PORT_ARL_ENTRIES */
#define BRCM_SWARCH_ETHSWT_ARL_TYPE                         (0x8587U) /**< @brief #ETHSWT_ARLType                  */
#define BRCM_SWARCH_ETHSWT_ARL_PERPORTLIST_TYPE             (0x8588U) /**< @brief #ETHSWT_ARLPerPortListType       */
#define BRCM_SWARCH_ETHSWT_ARL_LISTMSG_TYPE                 (0x8589U) /**< @brief #ETHSWT_ARLListMsgType           */
#define BRCM_SWARCH_ETHSWT_ARL_GETPERPORT_PROC              (0x858AU) /**< @brief #ETHSWT_ARLGetPerPort            */
/** @} */

/** @brief Maximum ARL Entries that host can capture

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_ARL_HOST_MAX_ENTRIES       (1000UL)

/**
    @brief Maximum number of ARL entries supported
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_ARL_MAX_ENTRIES            (512UL)

/**
    @brief Maximum number of ARL entries
           Maximum number of ARL entries can be retrieved for port in one message
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_ARL_GET_PORT_ARL_ENTRIES     (34U)

/**
    @brief Maximum size of ARL payload
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_ARL_MAX_PAYLOAD_SIZE       (448UL)

/**
    @brief Macro to Construct ARL CmdID

    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_ARL_ID_OF(aId)     \
    BCM_MSG(BCM_GROUPID_ETHSRV, BCM_ARL_ID, aId)

/**
    @name Switch ARL command IDs
    @{
    @brief Group of Switch ARL command IDs

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef uint8_t ETHSWT_ARLCmdIdType;         /**< @brief ARL command message Type                                         */
#define ETHSWT_ARLCMDID_ADD                 ETHSWT_ARL_ID_OF(0x80U)  /**< @brief #ETHSWT_ARLEntryType       #ETHSWT_AddARLEntry           */
#define ETHSWT_ARLCMDID_DELETE              ETHSWT_ARL_ID_OF(0x81U)  /**< @brief #ETHSWT_ARLEntryType       #ETHSWTM_ARLDelEntry          */
#define ETHSWT_ARLCMDID_SNAPSHOT            ETHSWT_ARL_ID_OF(0x82U)  /**< @brief #ETHSWT_ARLListType        #ETHSWT_GetARLTable           */
#define ETHSWT_ARLCMDID_GET                 ETHSWT_ARL_ID_OF(0x83U)  /**< @brief #ETHSWT_ARLListType        #ETHSWT_GetARLTable           */
#define ETHSWT_ARLCMDID_ADD_V2              ETHSWT_ARL_ID_OF(0x84U)  /**< @brief #ETHSWT_ARLEntryV2Type     #ETHSWT_AddARLEntry           */
#define ETHSWT_ARLCMDID_DELETE_V2           ETHSWT_ARL_ID_OF(0x85U)  /**< @brief #ETHSWT_ARLEntryV2Type     #ETHSWTM_ARLDelEntry          */
#define ETHSWT_ARLCMDID_SNAPSHOT_V2         ETHSWT_ARL_ID_OF(0x86U)  /**< @brief #ETHSWT_ARLListV2Type      #ETHSWT_GetARLTable           */
#define ETHSWT_ARLCMDID_GET_V2              ETHSWT_ARL_ID_OF(0x87U)  /**< @brief #ETHSWT_ARLListV2Type      #ETHSWT_GetARLTable           */
#define ETHSWT_ARLCMDID_FIND                ETHSWT_ARL_ID_OF(0x88U)  /**< @brief #ETHSWT_ARLEntryV2Type     #ETHSWT_Find                  */
#define ETHSWT_ARLCMDID_UPDATE_PORTMASK     ETHSWT_ARL_ID_OF(0x89U)  /**< @brief #ETHSWT_ARLEntryV2Type     #ETHSWT_ARLRemoveByPort       */
#define ETHSWT_ARLCMDID_GET_PORT_ARL        ETHSWT_ARL_ID_OF(0x8AU)  /**< @brief #ETHSWT_ARLListMsgType  #ETHSWT_GetARLTable           */
/** @} */

/**
    @brief ARL table entry

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ARLEntryType {
    uint8_t             macAddr[6];     /**< @brief MAC address */
    ETHER_VLANIDType      vlanID;         /**< @brief VLAN ID */
    ETHSWT_PortIDType   portMask;       /**< @brief Switch port mask */
    uint16_t            reserved;       /**< @brief Reserved */
} ETHSWT_ARLEntryType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLEntryType, 16UL, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief Maximum number of ARL entries in a RPC message
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_ARL_RPC_MAX_ENTRIES        ((ETHSWT_ARL_MAX_PAYLOAD_SIZE-4UL)/sizeof(ETHSWT_ARLEntryType))

/**
    @brief ARL table v2 entry

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ARLEntryV2Type {
    uint8_t             macAddr[6];     /**< @brief MAC address */
    ETHER_VLANIDType    vlanID;         /**< @brief VLAN ID */
    ETHSWT_PortMaskType portMask;       /**< @brief Switch port mask */
} ETHSWT_ARLEntryV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLEntryV2Type, 16UL, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief Maximum number of ARL V2 entries in a RPC message
    @trace #BRCM_SWREQ_ETHSWT
*/
#define ETHSWT_ARL_V2_RPC_MAX_ENTRIES     ((ETHSWT_ARL_MAX_PAYLOAD_SIZE-4UL)/sizeof(ETHSWT_ARLEntryV2Type))

/**
    @brief Structure to manage the ARL commands.

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ARLListType {
    uint32_t            num;                                  /**< @brief NUmber of entries */
    ETHSWT_ARLEntryType entries[ETHSWT_ARL_RPC_MAX_ENTRIES];  /**< @brief ARL entries */
} ETHSWT_ARLListType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLListType, 436UL, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief List of ARL V2 entries

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ARLListV2Type {
    uint32_t            num;                                       /**< @brief Number of entries */
    ETHSWT_ARLEntryV2Type entries[ETHSWT_ARL_V2_RPC_MAX_ENTRIES];  /**< @brief ARL V2 entries */
} ETHSWT_ARLListV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLListV2Type, 440UL, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief List of ARL entries for a port

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ARLType {
    uint8_t macAddr[6U];    /**< @brief output : MAC address */
    ETHSWT_VLANIDType vlan; /**< @brief output : VLAN ID     */
    uint32_t rsvd;
}ETHSWT_ARLType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLType, 12UL, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief ARL information for get port ARL list request

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ARLPerPortListType  {
    uint32_t            lastEntryNum;          /**< @brief output: Last searched ARL entry number */
    uint16_t            isSearchComplete;      /**< @brief output: Set to 1 to indicate the ARL fetching is compleated */
    uint16_t            count;                 /**< @brief output: count of valid ARL's in the arlList */
    uint32_t            rsvd[2UL];
    ETHSWT_ARLType      entry[ETHSWT_ARL_GET_PORT_ARL_ENTRIES];  /**< @brief output: List of ARL entries
                                                                            associated with port
                                                                            (And VLAN in case vlan is not '0') */
}ETHSWT_ARLPerPortListType ;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLPerPortListType , 424UL, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief Port ARL list message

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct sETHSWT_ARLListMsgType {
    ETHSWT_PortIDType       port;            /**< @brief input: Switch Port Index of which the ARL to be fetched */
    ETHSWT_VLANIDType       vlan;            /**< @brief input: VLAN ID. Use '0' to ignore the VLAN match*/
    uint16_t                nextEntryNum;    /**< @brief input: Next ARL entry number to start search */
    uint32_t                rsvd[4UL];
    ETHSWT_ARLPerPortListType   arl;
}ETHSWT_ARLListMsgType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLListMsgType, ETHSWT_ARL_MAX_PAYLOAD_SIZE, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief ARL Union encapsulating all messages

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef union uETHSWT_ARLMsgUnionType {
    uint32_t               data[ETHSWT_ARL_MAX_PAYLOAD_SIZE/4UL]; /**< @brief byte array */
    ETHSWT_ARLEntryType    arlEntry;    /**< @brief ARL entry */
    ETHSWT_ARLListType     arlList;     /**< @brief ARL list */
    ETHSWT_ARLEntryV2Type  arlEntryV2;  /**< @brief ARL entry */
    ETHSWT_ARLListV2Type   arlListV2;   /**< @brief ARL list */
    ETHSWT_ARLListMsgType  getPortArl; /**< @brief Get port ARL entries */
} ETHSWT_ARLMsgUnionType;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLMsgUnionType, ETHSWT_ARL_MAX_PAYLOAD_SIZE, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief ARL Entry type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_ARLEntryV1Type {
    uint8_t  macAddress[6U]; /**< @brief MAC address */
    uint16_t vlan;           /**< @brief VLAN Identifier */
    uint16_t portMask;       /**< @brief Bitmap of destination ports */
} ETHSWT_ARLEntryV1Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLEntryV1Type, 10UL, ETHSWT_ARL_MAX_PAYLOAD_SIZE)

/**
    @brief ARL Configuration Type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_ARLConfigV1Type {
    ETHSWT_ARLEntryV1Type arlTable[ETHSWT_ARL_MAX_ENTRIES]; /**< @brief ARL table */
    uint32_t arlTblSz;            /**< @brief Number of entries in ARL table */
} ETHSWT_ARLConfigV1Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLConfigV1Type, 5124UL, 5124UL)

/**
    @brief ARL Configuration V2 Type

    @trace #BRCM_SWREQ_ETHSWT
*/
typedef struct COMP_PACKED sETHSWT_ARLConfigV2Type {
    ETHSWT_ARLEntryV2Type arlTable[ETHSWT_ARL_MAX_ENTRIES]; /**< @brief ARL table */
    uint32_t arlTblSz;            /**< @brief Number of entries in ARL table */
} ETHSWT_ARLConfigV2Type;
BCM_STATIC_SIZE_ASSERT(ETHSWT_ARLConfigV2Type, 8196UL, 8196UL)

/**
    @brief Add a ARL Entry

    @behavior Sync, Non-Rentrant

    @pre The VLAN ID should already be created before adding ARL entry

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aMacAddress     MacAddress
    @param[in]      aVlanID         VLAN ID
    @param[in]      aPortMask       Switch port mask

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS     aMacAddress is NULL or
                                              Entry exists or
                                              Out of space
    @retval         #BCM_ERR_OK               Entry added successfully

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ARLAdd(BCM_HandleType aHdl,
                             const uint8_t *const aMacAddress,
                             ETHER_VLANIDType aVlanID,
                             ETHSWT_PortMaskType aPortMask);

/**
    @brief Remove a ARL Entry

    @behavior Sync, Non-Rentrant

    @note This API does not remove static entries created as part of SDK.

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aMacAddress     MacAddress
    @param[in]      aVlanID         VLAN ID

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_INVAL_PARAMS     aMacAddress is NULL
    @retval         #BCM_ERR_NOPERM           No permission to delete
    @retval         #BCM_ERR_OK               Entry Removed successfully

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ARLRemove(BCM_HandleType aHdl,
                                 const uint8_t *const aMacAddress,
                                 ETHER_VLANIDType aVlanID);

/**
    @brief Retrive ARL Entries

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]      aHdl                   Connection handle (from RPC_Connect)
    @param[in]      aArlListCount          Number of ARL entries that can be filled in aArlList
                                           This value should be aArlList buffer size.
                                           Setting this to '0' will return only aNumOfAvailEntries
    @param[out]     aArlList               Pointer to List of Entries
    @param[out]     aNumOfFilledEntries    Total number of entries filled into aArlList.
    @param[out]     aNumOfAvailEntries     Total number of ARL entries available in the hardware
                                           This is required when user want to know the total number of available ARL's
                                           otherwise it can be NULL

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_UNKNOWN        Failed to retrive ARL Entries
    @retval         #BCM_ERR_INVAL_PARAMS   aNumOfFilledEntries is NULL
    @retval         #BCM_ERR_INVAL_PARAMS   aArlList is NULL
    @retval         #BCM_ERR_OK             If the available entries in hardware is less than aArlListCount,
                                            this API would give out all entries in the hardware.
                                            If the available entries in the hardware is more than aArlListCount,
                                            this API give out the number of entries presented in aArlListCount only
                                            In this case to get all the entries this API needs to be invoked again using the
                                            returned aNumOfAvailEntries as aArlListCount.
                                            If aArlListCount is set to '0' and if aNumOfAvailEntries points to a valid address then
                                            this API returns aNumOfAvailEntries(Entries present in the hardware).
    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ARLDump(BCM_HandleType aHdl,
                                 uint32_t aArlListCount,
                                 ETHSWT_ARLEntryV2Type *const aArlList,
                                 uint32_t *const aNumOfFilledEntries,
                                 uint32_t *const aNumOfAvailEntries);

/**
    @brief Retrieve an ARL entry

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aHdl            Connection handle (from RPC_Connect)
    @param[in]     aMacAddress     MAC Address of ARL Entry
    @param[in]     aVlanID         Vlan Id of ARL Entry
    @param[out]    aPortMask       Ports which are part of the ARL Entry

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Retrieved Ports which are part of
                                            given MAC Address and Vlan Id
    @retval         #BCM_ERR_UNKNOWN        Failed to retrieve ARL entry
    @retval         #BCM_ERR_NOT_FOUND      If Vlan ID or MAC address does not
                                            exist
    @retval         #BCM_ERR_INVAL_PARAMS   If aMacAddress is NULL or
                                            aPortMask is NULL or
                                            aVlanID is greater than 4094

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/

extern int32_t ETHSWT_ARLFind(BCM_HandleType aHdl,
                             const uint8_t *const aMacAddress,
                             const ETHSWT_VLANIDType aVlanID,
                             ETHSWT_PortMaskType * const aPortMask);

/**
    @brief Remove specific Ports from a an ARL Entry

    @behavior Sync, Non-Rentrant

    @pre None

    @param[in]     aHdl            Connection handle (from RPC_Connect)
    @param[in]     aMacAddress     MAC Address of ARL Entry
    @param[in]     aVlanID         Vlan Id of ARL Entry
    @param[in]     aPortMask       Ports from which the ARL Entry needs
                                   to be removed

    Return values are documented in reverse-chronological order
    @retval         #BCM_ERR_OK             Removed Ports from ARL entry or
                                            ports are not part of ARL
    @retval         #BCM_ERR_UNKNOWN        Failed to removed Ports from ARL entry
    @retval         #BCM_ERR_NOT_FOUND      If Vlan ID or MAC address does not
                                            found
    @retval         #BCM_ERR_INVAL_PARAMS   If aMacAddress is NULL or
                                            aPortMask is zero or
                                            aVlanID is greater than 4094 or
                                            user has given multiple ports
                                            in aPortmask for an Unicast entry

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ARLRemoveByPort(BCM_HandleType aHdl,
                                      const uint8_t *const aMacAddress,
                                      const ETHSWT_VLANIDType aVlanID,
                                      const ETHSWT_PortMaskType aPortMask);

/** @brief Retrieve the list of ARL of a Port

    This API search and retrieves the list of all ARL of a given port.
    If VLAN ID is also provided then it matches both port and VLAN
    and retrieves the matching ARL.
    Multiple invocations of this API may be expected to search through full
    available list of arl till 'aArl.arl.isSearchComplete' is Set to 1.

    @behavior Sync, Re-entrant

    @pre None

    @param[in]      aHdl            Connection handle (from RPC_Connect)
    @param[in]      aPort           Port number for which the ARL to be fetched
    @param[in]      aVlanID         VLAN ID to match. if '0' then VLAN will not be matched.
    @param[in]      aNextEntryNum   Next ARL entry number to start search from.
                                    Entries are starts from 0. To search from entry 5 aNextEntryNum should set to 4
    @param[out]     aArlList        List of retrieved ARL. Maximum of ETHSWT_ARL_GET_PORT_ARL_ENTRIES

    Return values are documented in reverse-chronological order
    @retval     #BCM_ERR_OK             Successfully fetched list of ARL
    @retval     #BCM_ERR_TIME_OUT       Timeout occurred while reading/writing
                                        switch register
    @retval     #BCM_ERR_INVAL_PARAMS   aArl is NULL
                #BCM_ERR_INVAL_PARAMS   Invalid aPort
                #BCM_ERR_INVAL_PARAMS   Invalid aVlanID
    @retval     #BCM_ERR_NOSUPPORT      Operation is Not Supported

    @post None

    @trace #BRCM_SWREQ_ETHSWT

    @limitations None
*/
extern int32_t ETHSWT_ARLGetPerPort(BCM_HandleType aHdl,
                                           ETHSWT_PortIDType aPort,
                                           ETHSWT_VLANIDType aVlanID,
                                           uint16_t aNextEntryNum,
                                           ETHSWT_ARLPerPortListType *const aArl);
#endif /* ETHSWT_ABSTRACT_ARL_H */
/** @} */
