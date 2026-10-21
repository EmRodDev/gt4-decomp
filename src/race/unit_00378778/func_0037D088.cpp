typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef long long s64;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };

struct Obj {
    char *vt;
    char pad0[0x168 - 4];
    s64 m168;
    char pad1[0x268 - 0x170];
    s64 m268;
    char pad2[0x2C0 - 0x270];
    s8 a;
    s8 b;
    u8 c;
    s8 d;
    s32 e;
};

struct In {
    char pad0[0x19];
    s8 f19;
    char pad1[0x21 - 0x1A];
    u8 f21;
    s8 f22;
    s8 f23;
};

extern "C" void func_0037BC20(Obj *, s32) throw();
extern "C" void func_0037CFC8(Obj *) throw();

static inline s32 get(Obj *self) {
 VEntry *ent = (VEntry *)(self->vt + 0xB8);
 return ent->fn((char *)self + ent->delta);
}
extern "C" s32 func_0037D088(Obj *self, In *in) {
    s32 changed = 0;
    s8 a2 = in->f19;
    s8 nd = in->f23;
    u8 a3 = in->f21;
    s8 nb = in->f22;
    if (self->e >= 0) {
        s32 r = get(self);
        if (self->e != r) {
            changed = 1;
            func_0037BC20(self, self->e);
            s64 lo = self->m168;
            s64 temp = (((-1LL << 0x10) | 0xFF) << 0x10) | 0xFFFF;
            s64 hi = self->m268;
            self->m168 = lo & temp;
            self->m268 = hi & temp & 0xFFFFFFFFFFFF00FFLL;
        }
        self->e = get(self);
    } else {
        s32 r;
        if (self->b == 0) {
            s8 od = self->d;
            s32 h = 1;
            if (od != 0) {
                h = 0;
                if (nd != 0) {
                    self->d = nd;
                    if (nd == od)
                        self->d = 0;
                    h = 1;
                } else if (a2 != 0 || a3 != 0) {
                    self->d = 0;
                    h = 1;
                }
                if (h) {
                    goto update;
                }
            } else {
                r = 0;
                if (nd != 0) {
                    self->d = nd;
                    r = 1;
                    h = 0;
                }
                if (h) {
                    s32 t = self->a;
                    if (a2 != 0) {
                        t++;
                        r = 1;
                        h = 0;
                        if (t >= 5)
                            t = 0;
                        self->a = t;
                    }
                    if (h && a3 != 0) {
                        r = 1;
                        *(s64 *)((char *)self + 0x2C0) = (*(s64 *)((char *)self + 0x2C0) & ~(0xFFLL << 16)) | ((s64)(self->c ^ 1) << 16);
                    }
                }
                if (r) {
update:
                    func_0037CFC8(self);
                    changed = 1;
                }
            }
        }
        if (nb != self->b) {
            self->b = nb;
            changed = 1;
            func_0037CFC8(self);
        }
    }
    return changed;
}
