/* Variant of func_0052DE00 that rebuilds the queue object arg0 with a new size arg1: returns 2 for an invalid object, 300 when arg1 is smaller than the current size field (+0xC), otherwise saves and clears the 0x18-byte header, re-initialises it for arg1 (func_0052D448; restores the old header on error) and pushes every node of the old chain back as a one-element gather list. Unlike func_0052DE00 it has no cursor to fix up. Meaning of the object (some buffer queue) is not determined. */
struct Node { int len; Node *next; };
struct Hdr { char c[0x18]; };
struct Obj { char pad0[8]; int f8; unsigned fc; int f10; int f14; };
struct IOV { char *p; int len; };
struct IOVec {
    IOV v[8]; int total; int count;
    IOVec() { count = 0; total = 0; }
};
extern "C" int func_0052D448(Obj *, int) throw();
extern "C" void func_0052D4E0(void *) throw();
extern "C" void func_0052D5A8(Obj *, void *, IOVec *) throw();
extern "C" void *func_0052DD98(Obj *) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int) throw();

extern "C" int func_0052DFA0(Obj *queue, unsigned newSize) {
    Hdr oldHeader;
    if (queue == 0 || queue->f10 == 0 || queue->f14 == 0 || queue->f8 == 0) return 2;
    if (newSize < queue->fc) return 300;
    oldHeader = *(Hdr *)queue;
    func_005A48D8(queue, 0, 0x18);
    int status = func_0052D448(queue, newSize);
    if (status != 0) {
        *(Hdr *)queue = oldHeader;
        return status;
    }
    Node *node = *(Node **)(oldHeader.c + 0x14);
    if (node != 0) {
        do {
            void *newNode = func_0052DD98(queue);
            IOVec gather;
            int slot = gather.count;
            gather.v[slot].p = node ? (char *)node + 8 : 0;
            gather.v[slot].len = node ? node->len : 0;
            int total = gather.total;
            if (node) total += node->len;
            gather.total = total;
            gather.count = gather.count + 1;
            func_0052D5A8(queue, newNode, &gather);
            node = node->next;
        } while (node != 0);
    }
    func_0052D4E0(&oldHeader);
    return 0;
}
