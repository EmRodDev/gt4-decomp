/* Re-inserts the buffer chain of a queue object: after validating the object (returns 2 if any of its fields +8/+0x10/+0x14 is empty), the 0x18-byte header is saved, cleared and re-initialised through func_0052D448; the node list that the header used to hold (nodes of {len, next} followed by their data) is then walked and each node is pushed back with func_0052D5A8 as a one-element gather list. If the caller's cursor *arg1 points at a node that was moved, it is updated to the node's new address. The saved header is restored when the re-init fails. The names are descriptive of the pattern; the owning subsystem is not determined. */
struct Node { int len; Node *next; };
struct Hdr { char c[0x18]; };
struct Obj { char pad0[8]; int f8; char padc[4]; int f10; int f14; };
struct IOV { char *p; int len; };
struct IOVec {
    IOV v[8]; int total; int count;
    IOVec() { count = 0; total = 0; }
};
extern "C" int func_0052D448(Obj *, int) throw();
extern "C" void func_0052D4E0(void *) throw();
extern "C" void func_0052D5A8(Obj *, void *, IOVec *) throw();
extern "C" void *func_0052DD98(Obj *) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" int func_0052DE00(Obj *queue, void **cursor) {
    Hdr oldHeader;
    if (queue == 0 || queue->f10 == 0 || queue->f14 == 0 || queue->f8 == 0) return 2;
    oldHeader = *(Hdr *)queue;
    func_005A48D8(queue, 0, 0x18);
    int status = func_0052D448(queue, *(int *)(oldHeader.c + 8));
    Node *node = *(Node **)(oldHeader.c + 0x14);
    if (status != 0) {
        *(Hdr *)queue = oldHeader;
        return status;
    }
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
            if (cursor != 0 && node == *cursor) *cursor = func_0052DD98(queue);
            node = node->next;
        } while (node != 0);
    }
    func_0052D4E0(&oldHeader);
    return 0;
}
