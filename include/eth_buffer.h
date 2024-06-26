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
    @defgroup grp_eth_cntlrdrv_cntlr_buf_ifc Ethernet Controller Buffer
    @ingroup grp_eth_cntlrdrv

    @addtogroup grp_eth_cntlrdrv_cntlr_buf_ifc
    @{

    @file ethernet/drivers/controller/inc/eth_buffer.h
*/

#ifndef ETH_BUFFER_H
#define ETH_BUFFER_H

/**
    @name Ethernet controller buffer manager interfce IDs
    @{
    @brief Interface IDs for Ethernet controller driver buffer manager
*/
#define BRCM_SWARCH_ETHER_RXDMAPKTSIZE_MACRO            (0x8101U)    /**< @brief #ETHER_RXDMAPKTSIZE          */
#define BRCM_SWARCH_ETHER_TXDMAPKTSIZE_MACRO            (0x8102U)    /**< @brief #ETHER_TXDMAPKTSIZE          */
#define BRCM_SWARCH_ETHER_TXBUFFIDXQSIZE_MACRO          (0x8103U)    /**< @brief #ETHER_TXBUFFIDXQSIZE        */
#define BRCM_SWARCH_ETHER_RXBUFFIDXQSIZE_MACRO          (0x8104U)    /**< @brief #ETHER_RXBUFFIDXQSIZE        */
#define BRCM_SWARCH_ETHER_RXPKT_TYPE                    (0x8105U)    /**< @brief #ETHER_RxPktType             */
#define BRCM_SWARCH_ETHER_TXPKT_TYPE                    (0x8106U)    /**< @brief #ETHER_TxPktType             */
#define BRCM_SWARCH_ETHER_INVAL_BUFF_IDX_MACRO          (0x8107U)    /**< @brief #ETHER_INVAL_BUFF_IDX        */
#define BRCM_SWARCH_ETHER_PKTBUFFSTATE_TYPE             (0x8108U)    /**< @brief #ETHER_PktBuffStateType      */
#define BRCM_SWARCH_ETHER_RXPKTBUFFINFO_TYPE            (0x8109U)    /**< @brief #ETHER_RxPktBuffInfoType     */
#define BRCM_SWARCH_ETHER_TXPKTBUFFINFO_TYPE            (0x810AU)    /**< @brief #ETHER_TxPktBuffInfoType     */
#define BRCM_SWARCH_ETHER_PKTFLAGS_TYPE                 (0x810BU)    /**< @brief #ETHER_PktFlagsType          */
#define BRCM_SWARCH_ETHER_TXBUFMGRINFO_TYPE             (0x810CU)    /**< @brief #ETHER_TxBufMgrInfoType      */
#define BRCM_SWARCH_ETHER_RXBUFMGRINFO_TYPE             (0x810DU)    /**< @brief #ETHER_RxBufMgrInfoType      */
#define BRCM_SWARCH_ETHER_INITTXBUFMGRINFO_MACRO        (0x810EU)    /**< @brief #ETHER_INITTXBUFMGRINFO      */
#define BRCM_SWARCH_ETHER_INITRXBUFMGRINFO_MACRO        (0x810FU)    /**< @brief #ETHER_INITRXBUFMGRINFO      */
#define BRCM_SWARCH_ETHER_CNTLRDEINITTXBUF_PROC         (0x8110U)    /**< @brief #ETHER_CntlrDeInitTxBuf      */
#define BRCM_SWARCH_ETHER_CNTLRINITTXBUF_PROC           (0x8111U)    /**< @brief #ETHER_CntlrInitTxBuf        */
#define BRCM_SWARCH_ETHER_CNTLRPEEKTXDEQUEUEBUF_PROC    (0x8112U)    /**< @brief #ETHER_CntlrPeekTxDequeueBuf */
#define BRCM_SWARCH_ETHER_CNTLRDEQUEUETXBUF_PROC        (0x8113U)    /**< @brief #ETHER_CntlrDequeueTxBuf     */
#define BRCM_SWARCH_ETHER_CNTLRDEALLOCTXBUF_PROC        (0x8114U)    /**< @brief #ETHER_CntlrDeallocTxBuf     */
#define BRCM_SWARCH_ETHER_CNTLRGETDEQUEUEDTXBUF_PROC    (0x8115U)    /**< @brief #ETHER_CntlrGetDequeuedTxBuf */
#define BRCM_SWARCH_ETHER_CNTLRALLOCTXBUF_PROC          (0x8116U)    /**< @brief #ETHER_CntlrAllocTxBuf       */
#define BRCM_SWARCH_ETHER_CNTLRFREETXBUF_PROC           (0x8117U)    /**< @brief #ETHER_CntlrFreeTxBuf        */
#define BRCM_SWARCH_ETHER_CNTLRQUEUETXBUF_PROC          (0x8118U)    /**< @brief #ETHER_CntlrQueueTxBuf       */
#define BRCM_SWARCH_ETHER_CNTLRDEINITRXBUF_PROC         (0x8119U)    /**< @brief #ETHER_CntlrDeInitRxBuf      */
#define BRCM_SWARCH_ETHER_CNTLRINITRXBUF_PROC           (0x811AU)    /**< @brief #ETHER_CntlrInitRxBuf        */
#define BRCM_SWARCH_ETHER_CNTLRPEEKRXDEQUEUEBUF_PROC    (0x811BU)    /**< @brief #ETHER_CntlrPeekRxDequeueBuf */
#define BRCM_SWARCH_ETHER_CNTLRDEQUEUERXBUF_PROC        (0x811CU)    /**< @brief #ETHER_CntlrDequeueRxBuf     */
#define BRCM_SWARCH_ETHER_CNTLRDEALLOCRXBUF_PROC        (0x811DU)    /**< @brief #ETHER_CntlrDeallocRxBuf     */
#define BRCM_SWARCH_ETHER_CNTLRQUEUERXBUF_PROC          (0x811EU)    /**< @brief #ETHER_CntlrQueueRxBuf       */
#define BRCM_SWARCH_ETHER_CNTLRGETDEQUEUEDRXBUF_PROC    (0x811FU)    /**< @brief #ETHER_CntlrGetDequeuedRxBuf */
#define BRCM_SWARCH_ETHER_DMA_DESC_TBL_ALIGN_MACRO      (0x8120U)    /**< @brief #ETHER_DMA_DESC_TBL_ALIGN    */
#define BRCM_SWARCH_ETHER_DESCTABLEDESCCNT_MACRO        (0x8121U)    /**< @brief #ETHER_DESCTABLEDESCCNT      */
#define BRCM_SWARCH_ETHER_BUF_ALIGN_MACRO               (0x8122U)    /**< @brief #ETHER_BUF_ALIGN             */
#define BRCM_SWARCH_ETHER_RXPKTTYPESIZE_MACRO           (0x8123U)    /**< @brief #ETHER_RXPKTTYPESIZE         */
#define BRCM_SWARCH_ETHER_INITRXDESC_MACRO              (0x8124U)    /**< @brief #ETHER_INITRXDESC            */
#define BRCM_SWARCH_ETHER_DMA_DESC_TYPE                 (0x8125U)    /**< @brief #ETHER_DmaDescType           */
#define BRCM_SWARCH_ETHER_ALIGN_MACRO                   (0x8126U)    /**< @brief #ETHER_ALIGN                 */
#define BRCM_SWARCH_ETHER_MINFRMSIZENOCRC_MACRO         (0x8127U)    /**< @brief #ETHER_MINFRMSIZENOCRC       */
#define BRCM_SWARCH_ETHER_MINFRMSIZE_MACRO              (0x8128U)    /**< @brief #ETHER_MINFRMSIZE            */
#define BRCM_SWARCH_ETHER_CRCSIZE_MACRO                 (0x8129U)    /**< @brief #ETHER_CRCSIZE               */
#define BRCM_SWARCH_ETHER_VLANTAGSIZE_MACRO             (0x812AU)    /**< @brief #ETHER_VLANTAGSIZE           */
#define BRCM_SWARCH_ETHER_FRMSIZENOCRC_MACRO            (0x812BU)    /**< @brief #ETHER_FRMSIZENOCRC          */
#define BRCM_SWARCH_ETHER_FRAMESIZE_MACRO               (0x812CU)    /**< @brief #ETHER_FRAMESIZE             */
#define BRCM_SWARCH_ETHER_CLIENTBUFINFO_TYPE            (0x812DU)    /**< @brief #ETHER_ClientBufInfoType     */
/** @} */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_ALIGN(x, y)   ((((uint32_t)(x)) + (((uint32_t)(y)) - 1)) \
                            & (~(uint32_t)((y) - 1))) /**< @brief Ethernet buffer alignment macro */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_MINFRMSIZENOCRC   (60UL)  /**< @brief Ethernet minimum size frame without CRC */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_MINFRMSIZE        (64UL)  /**< @brief Ethernet minimum size frame with CRC */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_CRCSIZE           (4UL)   /**< @brief CRC byte-length */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_VLANTAGSIZE       (4UL)   /**< @brief VLAN tag byte-length */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_FRMSIZENOCRC      (ETHER_MTU + ETHER_HDR_SIZE + ETHER_VLANTAGSIZE) /**< @brief Ethernet maximum size frame without CRC */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_FRAMESIZE         (ETHER_MTU + ETHER_HDR_SIZE \
                                + ETHER_VLANTAGSIZE \
                                + ETHER_CRCSIZE) /**< @brief Ethernet maximum size frame with CRC */

/**
    @{
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_RXDMAPKTSIZE       ETHER_ALIGN((ETHER_FRAMESIZE + 4UL), ETHER_RXPKTSTARTALIGN) /**< @brief Rx DMA packet size */
/** @} */

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_TXDMAPKTSIZE       ETHER_ALIGN(ETHER_FRAMESIZE, 32) /**< @brief Tx DMA packet size */

/**
    @trace #BRCM_SWREQ_ETHER_CONFIGURATION
TODO: add a check to in controller driver to  modify this according to increase
decrease of the driver buffers
*/
#define ETHER_TXBUFFIDXQSIZE          (16UL)    /**< @brief Tx buffer index queue size */

/**
    @trace #BRCM_SWREQ_ETHER_CONFIGURATION
*/
#define ETHER_RXBUFFIDXQSIZE          (16UL)    /**< @brief Rx buffer index queue size */

/**
    @brief Ethernet Rx packet type

    @Note Align pktBuff to 32Bytes boundary

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef struct sETHER_RxPktType {
    uint8_t     rsvd[ETHER_RXPKTSTARTALIGN - 4UL];  /**< @brief reserved */
    uint32_t    rxPktInfo;                          /**< @brief rx packet info */
    uint8_t     pktBuff[ETHER_RXDMAPKTSIZE];        /**< @brief packet buffer */
} ETHER_RxPktType;

/**
    @brief Ethernet Tx packet type

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef struct sETHER_TxPktType {
    uint8_t     pktBuff[ETHER_TXDMAPKTSIZE];    /**< @brief Packet buffer */
} ETHER_TxPktType;

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
#define ETHER_INVAL_BUFF_IDX            (0xFFFFFFFFUL)  /**< @brief Invalid buffer index */

/**
    @name ETHER_PktBuffStateType
    @{
    @brief Ethernet packet buffer state

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef uint32_t ETHER_PktBuffStateType;      /**< @brief State of Packet buffer */
#define ETHER_PKTBUFFSTATE_FREE         (0UL) /**< @brief Buffer in Free state */
#define ETHER_PKTBUFFSTATE_ALLOC        (1UL) /**< @brief Buffer With client */
#define ETHER_PKTBUFFSTATE_QUEUED       (2UL) /**< @brief Buffer Queued to DMA */
#define ETHER_PKTBUFFSTATE_DEQUEUED     (3UL) /**< @brief Buffer Dequeued after DMA completion */
/** @} */

/**
    @brief Structure for Rx packet buffer info

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef volatile struct sETHER_RxPktBuffInfoType {
    uint32_t    state;          /**< @brief State of the packet buffer */
    ETHER_RxPktType * pktBuff;  /**< @brief Pointer to packet buffer */
} ETHER_RxPktBuffInfoType;

/**
    @name ETHER_PktFlagsType
    @{
    @brief Ethernet flags type

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef uint32_t ETHER_PktFlagsType;
#define ETHER_PKTFLAGS_CBEN             (0x00000001UL) /**< @brief Flags callback enable */
#define ETHER_PKTFLAGS_1588TXCONF       (0x00000002UL) /**< @brief Flags 1588 transmission confirmation */
/** @} */

/**
    @brief Structure for Tx packet buffer info

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
typedef struct sETHER_TxPktBuffInfoType {
    uint32_t    state;      /**< @brief State of the packet buffer */
    uint32_t    flags;      /**< @brief Callback Enable */
    uint8_t *   pktBuff;    /**< @brief Pointer to packet buffer */
    uint32_t    len;
    uint64_t    ctrlId;
} ETHER_TxPktBuffInfoType;

/**
    @brief Structure for Tx buffer management info

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef struct sETHER_TxBufMgrInfoType {
    ETHER_TxPktBuffInfoType     pktBuffInfo[ETHER_TXBUFFIDXQSIZE]; /**< @brief Transmit  buffer info array */
    uint32_t                    pktBuffCnt;  /**< @brief Count of pktBuffers */
    uint32_t                    descCnt;     /**< @brief DMA desc count */
    uint32_t                    allocIdx;    /**< @brief allocIdx */
    uint32_t                    deallocIdx;  /**< @brief deallocIdx */
    uint32_t                    queueIdx;    /**< @brief queueIdx */
    uint32_t                    dequeueIdx;  /**< @brief dequeueIdx */
    uint16_t                    seedVal;     /**< @brief Seed Value*/
    uint64_t                    buffIdxQ[ETHER_TXBUFFIDXQSIZE]; /**< @brief buffer index queue */
} ETHER_TxBufMgrInfoType;

/**
    @name ETHER_INITTXBUFMGRINFO
    @{
    @brief Tx buffer manager info initialisation

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_INITTXBUFMGRINFO(aPktBuffCnt, aDescCnt,     \
                 aAllocIdx, aDeallocIdx, aQueueIdx, aDequeueIdx)        \
{                                                                       \
    .pktBuffCnt = (aPktBuffCnt),                                        \
    .descCnt = (aDescCnt),                                              \
    .allocIdx = (aAllocIdx),                                            \
    .deallocIdx = (aDeallocIdx),                                        \
    .queueIdx = (aQueueIdx),                                            \
    .dequeueIdx = (aDequeueIdx),                                        \
}
/** @} */

/**
    @brief Structure for Rx buffer management info

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
typedef struct sETHER_RxBufMgrInfoType {
    ETHER_RxPktBuffInfoType     pktBuffInfo[ETHER_RXBUFFCOUNT];  /**< @brief Receive buffer info array */
    uint32_t                    pktBuffCnt;   /**< @brief Count of pktBuffers */
    uint32_t                    allocIdx;     /**< @brief allocIdx */
    uint32_t                    queueIdx;     /**< @brief queueIdx */
    uint32_t                    dequeueIdx;   /**< @brief dequeueIdx */
    uint32_t                    buffIdxQ[ETHER_RXBUFFIDXQSIZE]; /**< @brief buffer index queue */
} ETHER_RxBufMgrInfoType;

/**
    @name ETHER_INITRXBUFMGRINFO
    @{
    @brief Rx buffer manager info initialisation

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
#define ETHER_INITRXBUFMGRINFO(aPktBuffCnt,               \
                            aAllocIdx, aQueueIdx, aDequeueIdx)          \
{                                                                       \
    .pktBuffCnt = (aPktBuffCnt),                                        \
    .allocIdx = (aAllocIdx),                                            \
    .queueIdx = (aQueueIdx),                                            \
    .dequeueIdx = (aDequeueIdx),                                        \
}
/** @} */

/**
 * @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
#define ETHER_DMA_DESC_TBL_ALIGN  (16UL)

/* Descriptor table for all the channels are allocated for 16 entries making
   total descriptor table size to 256Bytes */
/**
 * @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
#define ETHER_DESCTABLEDESCCNT     (16UL)

/**
 * @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
#define ETHER_BUF_ALIGN     (32UL)

/**
 * @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
#define ETHER_RXPKTTYPESIZE    (sizeof(ETHER_RxPktType))

/**
 * @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
#define ETHER_INITRXDESC(aEot, aRxPktPtr)                           \
{                                                                   \
    .flags = 0UL,                                                   \
    .eot = (aEot),                                                  \
    .intOnComp = AMAC_DMA_DESC_IOC_DIS,                             \
    .eof = AMAC_DMA_DESC_EOF_DIS,                                   \
    .sof = AMAC_DMA_DESC_SOF_DIS,                                   \
    .bufCount = ETHER_RXPKTTYPESIZE,                                \
    .addrExt = 0UL,                                                 \
    .dataPtrLow = (uint32_t)(aRxPktPtr) + AMAC_DMA_RX_MEM_VIEW_BASE,\
    .dataPtrHigh = AMAC_DMA_DESC_DATAPTRHIGH_ZERO                   \
}

/**
 * @brief Client Buffer Info
 *
 * @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
typedef struct sETHER_ClientBufInfoType {
    uint64_t bufIndex;
    uint64_t ctrlId;
} ETHER_ClientBufInfoType;


/**
 * @brief AMAC DMA descriptor
 *
 * @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
 */
typedef struct sETHER_DmaDescType {
    uint32_t rsvd1          :20;    /**< @brief reserved */
    uint32_t flags          :8;     /**< @brief used by core */
    uint32_t eot            :1;     /**< @brief End of table */
    uint32_t intOnComp      :1;     /**< @brief interrupt on completion */
    uint32_t eof            :1;     /**< @brief end of frame */
    uint32_t sof            :1;     /**< @brief start of frame */
    uint32_t bufCount       :15;    /**< @brief buffer count */
    uint32_t rsvd2          :1;     /**< @brief reserved */
    uint32_t addrExt        :2;     /**< @brief  address external (PCIE) */
    uint32_t rsvd3          :1;     /**< @brief reserved */
    uint32_t rsvd4          :13;    /**< @brief reserved */
    uint32_t dataPtrLow;            /**< @brief data buffer pointer low address */
    uint32_t dataPtrHigh;           /**< @brief data buffer pointer high address */
} ETHER_DmaDescType;

/**
    @brief ethernet controller driver initialise transmit buffer

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
extern void ETHER_CntlrInitTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo,
                                ETHER_TxPktType *const aTxChanPkt);

/**
    @brief ethernet controller driver de-initialise transmit buffer

    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
extern void ETHER_CntlrDeInitTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern uint32_t ETHER_CntlrPeekTxDequeueBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrDequeueTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrDeallocTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrGetDequeuedTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo,
                                          uint64_t *const aBufIdx,
                                          uint32_t *const aFlag,
                                          uint64_t *const aCtrlId);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrAllocTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo,
                                    uint64_t *const aBufIdx,
                                    uint8_t **const aBuf);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrFreeTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo,
                                    uint64_t aBufIdx);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrQueueTxBuf(ETHER_TxBufMgrInfoType *const aTxBufMgrInfo,
                                    uint64_t aBufIdx,
                                    uint8_t **const aBuf,
                                    BCM_BoolType aTxConfirmation);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
extern void ETHER_CntlrDeInitRxBuf(ETHER_RxBufMgrInfoType *const aRxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_INITIALISATION
*/
extern void ETHER_CntlrInitRxBuf(ETHER_RxBufMgrInfoType *const aRxBufMgrInfo,
                                ETHER_RxPktType *const aRxChanPkt,
                                uint32_t aQueueCnt);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern uint32_t ETHER_CntlrPeekRxDequeueBuf(ETHER_RxBufMgrInfoType *const aRxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrDequeueRxBuf(ETHER_RxBufMgrInfoType *const aRxBufMgrInfo,
                                    uint8_t **const aBuf,
                                    uint32_t *const aDequeueIdx);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern void ETHER_CntlrDeallocRxBuf(ETHER_RxBufMgrInfoType *const aRxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern void ETHER_CntlrQueueRxBuf(ETHER_RxBufMgrInfoType *const aRxBufMgrInfo);

/**
    @trace #BRCM_SWREQ_ETHER_CONTROLLER_COMMUNICATION
*/
extern int32_t ETHER_CntlrGetDequeuedRxBuf(ETHER_RxBufMgrInfoType *const aRxBufMgrInfo,
                                  ETHER_RxPktType **const aBuf,
                                  uint64_t *const aBufIdx);
#endif /* ETH_BUFFER_H */
/** @} */
