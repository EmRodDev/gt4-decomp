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
    u32 lo;
    u32 hi;
    char pad8[0x44];
    s32 lock;
};

extern "C" void *func_005722A8(void *, void *, s32) throw();
extern "C" void func_005722D8(void *, void *, void *) throw();
extern "C" void func_005722F8(void *, void *) throw();
extern "C" void func_005723D8(void *, void *) throw();
extern "C" void *func_005725A8(void *, s32, s32) throw();
extern "C" void func_00572930(void *, void *);
extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
extern "C" void *func_005A4724(void *, const void *, unsigned);

static inline s32 equal(s32 a, s32 b) { return a == b; }

static inline u32 expand(Heap *h, Blk *b, u32 p, u32 need, s32 rounded) {
    u32 d = b->end - (u32)b;
    if (d >= (u32)(rounded + 0x30)) {
        func_005722F8(h, func_005722A8(h, b, need));
    }
    return p;
}

extern "C" u32 func_00572738(Heap *h, u32 p, s32 size, s32 a3) {
    if (p == 0) {
        return (u32)func_005725A8(h, size, a3);
    }
    Blk *b = (Blk *)(p - 0x10);
    s32 ok = 0;
    if (!((u32)b & 0xF) && (u32)b >= h->lo && (u32)b < h->hi) {
        if (equal(-1, b->w8)) ok = equal(-1, b->wC);
    }
    if (ok == 0) return 0;
    void *lk = &h->lock;
    u32 r = p;
    func_005769F0(lk);
    s32 s6 = (size + 0xF) & ~0xF;
    Blk *nx = (Blk *)b->end;
    size = s6 + 0x10;
    if ((u32)nx - (u32)b < (u32)size) {
        r = 0;
        if ((u32)nx < h->hi && ~nx->w8 != 0) {
            func_005723D8(h, nx);
            func_005722D8(h, b, nx);
            u32 d = b->end - (u32)b;
            if (d >= (u32)size) r = expand(h, b, p, (u32)size, s6);
        }
    }
    func_00576A28(lk);
    if (r == 0) {
    r = (u32)func_005725A8(h, (u32)size, a3);
    if (r != 0) {
        func_005A4724((void *)r, (void *)p, b->end - (u32)b - 0x10);
    }
    func_00572930(h, (void *)p);
    }
    return r;
}
