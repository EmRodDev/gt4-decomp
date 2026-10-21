/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Blk {
    u32 prev;
    u32 end;
    s32 w8;
    s32 wC;
};

struct Heap {
    char pad0[0xC];
    Blk *bucket[16];
    s32 lock;
};

extern "C" Blk *func_005721B8(Heap *, Blk *, u32) throw();
extern "C" void *func_005722A8(Heap *, Blk *, s32) throw();
extern "C" void func_005722F8(Heap *, void *) throw();
extern "C" void func_005723D8(Heap *, Blk *) throw();
extern "C" s32 func_00572438(Heap *, s32) throw();
extern "C" void func_005769F0(void *, u32 size);
extern "C" void func_00576A28(void *);

static inline u32 rounded(u32 value, u32 align) {
    u32 mask = align - 1;
    return (value + mask) & ~mask;
}

extern "C" void *func_005725A8(Heap *h, u32 size, u32 align) {
    u32 al = align < 0x10 ? 0x10 : align;
    u32 need = rounded(size != 0 ? size : 1, al) + 0x10;
    void *lk = &h->lock;
    Blk *found = 0;
    func_005769F0(lk, size);
    s32 i = func_00572438(h, need);
    if (i < 16) {
        Blk **buckets = h->bucket;
        Blk **p = (Blk **)(i * 4 + (u32)buckets);
        do {
            Blk *b = *p;
            if (b != 0) {
                do {
                    u32 base = (u32)b + 0x10;
                    u32 pad = rounded(base, al) - base;
                    if (b->end - (u32)b >= need + pad) {
                        found = b;
                        break;
                    }
                    b = (Blk *)b->wC;
                } while (b != 0);
            }
            p++;
            i++;
        } while (!found && i < 16);
    }
    if (found) {
        func_005723D8(h, found);
        found = func_005721B8(h, found, al);
        if (found->end - (u32)found >= need + 0x20) {
            func_005722F8(h, func_005722A8(h, found, need));
        }
        found->w8 = -1;
        found->wC = -1;
    }
    func_00576A28(lk);
    return found ? (void *)((char *)found + 0x10) : 0;
}
