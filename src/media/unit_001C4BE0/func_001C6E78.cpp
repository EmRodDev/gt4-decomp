/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int w[0xa1]; };
struct Pair { int a, b; char pad[8]; };
struct Rec {
    int key;            /* 0x000 */
    char obj[0x28];     /* 0x004 */
    Block blk;          /* 0x02C */
    int id;             /* 0x2B0 */
    unsigned flags;     /* 0x2B4: low byte = state */
};
struct Op { char pad[0xafc]; Block blk; char pad2[0x54]; int a; int b; };
struct Self {
    char pad0[0xc];
    int ids[0x190];     /* 0x00C */
    Rec recs[2];        /* 0x64C */
    int cur;            /* 0xBBC */
    int busy;           /* 0xBC0 */
    int id;             /* 0xBC4 */
    char pad1[8];
    int q;              /* 0xBD0 */
    int p;              /* 0xBD4 */
    Op op;              /* 0xBD8 */
    char pad2[0x3f8];
    char ctx[4];        /* 0x1DAC */
};
extern "C" int func_001C65B8(void *, int, int) throw();
extern "C" void func_001C7960(void *, Pair *, Pair *);
extern "C" int func_0046D960(void *);
extern "C" int func_0046D100(void *);
extern "C" void func_001C5D80(void *) throw();
extern "C" void func_001C5DA0(void *, int, int, void *) throw();
static inline void copy(Block *dst, Block *src) { dst->w[0xa0] = 0; if (src) *dst = *src; }
extern "C" int func_001C6E78(Self *self, int id) {
    Pair out, in;
    int result = -2;
    int idx = self->cur;
    int r;
    Op *op;
    if (id < 0) return result;
    result = 0;
    if (self->busy == 0) {
        if ((self->recs[idx].flags & 0xff) == 0) {
            self->id = id;
            self->busy = 1;
            r = func_001C65B8(self, self->ids[id], self->p);
            if (r <= 0) goto error;
            out.b = self->q; out.a = r; in.b = self->recs[idx].key; in.a = 0x384000;
            op = &self->op;
            func_001C7960(op, &in, &out);
            if (!func_0046D960(op)) { self->busy = 0; return -1; }
            if (!func_0046D100(op)) {
            error:
                self->busy = 0; return -1;
            }
            Rec *rec = &self->recs[idx];
            int a = op->a; int b = op->b;
            func_001C5D80(rec->obj); func_001C5DA0(rec->obj, a, b, self->ctx);
            rec->id = self->id;
            copy(&rec->blk, &self->op.blk);
            rec->flags = (rec->flags & ~0xffu) | 1;
            idx++; if (idx >= 2) idx = 0;
            self->cur = idx; self->busy = 0;
            return 1;
        }
    }
    return result;
}
