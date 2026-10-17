/* compiler: ee-gcc2.96-as2004 */
/* Block headers can start at byte-aligned positions in the ring buffer. */
struct BlockHeader {
    unsigned int unknown00;
    unsigned int payloadBytes;
    BlockHeader *next;
    unsigned int unknown0C;
} __attribute__((packed));

struct PendingNode;
struct PendingQueue {
    PendingNode *head;
    PendingNode **tail;
};
struct StreamRing {
    int poolHandle;
    unsigned char unknown04[8];
    PendingQueue pending;
    unsigned int unknown14;
    unsigned int flags;
    unsigned char unknown1C[0x34 - 0x1C];
    unsigned int freeBytes;
};

extern "C" int func_005B72A8(void);
extern "C" int func_005B72F8(void);
extern "C" void func_00554910(StreamRing *, PendingQueue *);

extern "C" void func_00554C10(StreamRing *ring, const BlockHeader *blocks) {
    if (ring->flags & 1) {
        func_005B72A8();
        while (blocks) {
            ring->freeBytes += blocks->payloadBytes + sizeof(BlockHeader);
            blocks = blocks->next;
        }
        /* Retail enables interrupts unconditionally, then drains the pending queue. */
        func_005B72F8();
        func_00554910(ring, &ring->pending);
    }
}
