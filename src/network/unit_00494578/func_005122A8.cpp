/* A fixed-size pool handing out untyped blocks: each block starts with its payload pointer and
   carries the free-list link at +8; the payload follows the 16-byte header when the pool has one. */
struct Block { void *data; unsigned pad4; void *next; unsigned padC; };
struct Pool { unsigned pad0, size; int count; unsigned padC, pad10; void *freelist; };

extern "C" int func_00538B08(void **out, unsigned long size);
extern "C" void *func_005A4724(void *dst, const void *src, unsigned n);

extern "C" void *func_005122A8(Pool *p, void *src) {
    void *blk = 0;
    int sz;
    if (p->freelist) {
        blk = p->freelist;
        p->freelist = ((Block *)blk)->next;
        ((Block *)blk)->next = 0;
        sz = p->count;
    } else {
        if (func_00538B08(&blk, p->size)) return 0;
        sz = p->count;
        if (sz) ((Block *)blk)->data = (Block *)blk + 1;
    }
    if (sz) func_005A4724(((Block *)blk)->data, src, sz);
    else ((Block *)blk)->data = src;
    return blk;
}
