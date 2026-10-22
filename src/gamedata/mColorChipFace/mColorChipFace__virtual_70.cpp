/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Virtual slot 70 of mColorChipFace (inferred from the symbol name): draws the colour chip after the mWidget slot 70 has run.
 * Only when flag is non-zero and the member-function pointer at +0xD4 (pmf, a C++ pointer to member taking the context) is set: the context's vtable slot 0x1C0
 * is called with 0, the pointer-to-member is invoked on this object with the context, slot 0x1C8 of the context is called, and func_001598B8(self, context, item) draws,
 * where item is the pointer at +0xA8 when the word at +0xB8 is non-zero and the pointer at +0xAC otherwise. The tail call form (return func_...) is why the first branch returns.
 * The meaning of slots 0x1C0/0x1C8 (probably a begin/end pair around the callback) is not established. */
typedef int s32;
struct VEntry {
    short delta;
    short index;
    void *fn;
};
#define VCALL0(R, o, off) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *))e_->fn)((char *)(o) + e_->delta); })
#define VCALL1(R, o, off, a) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *, ...))e_->fn)((char *)(o) + e_->delta, a); })

struct Obj;
typedef void (Obj::*PM)(void *);
struct Obj {
    char pad0[0xA8];
    void *unkA8;
    void *unkAC;
    char padB0[8];
    s32 unkB8;
    char padBC[0x18];
    PM pmf;
};
extern "C" void func_001598B8(Obj *self, void *context, void *arg2) throw();
extern "C" void mWidget__virtual_70(Obj *self, void *context, s32 arg2);

extern "C" void mColorChipFace__virtual_70(Obj *self, void *context, s32 flag) {
    mWidget__virtual_70(self, context, 0);
    if (flag != 0) {
        if (self->pmf != 0) {
            VCALL1(void, context, 0x1C0, 0);
            (self->*(self->pmf))(context);
            VCALL0(void, context, 0x1C8);
            if (self->unkB8 != 0) {
                return func_001598B8(self, context, self->unkA8);
            }
            func_001598B8(self, context, self->unkAC);
        }
    }
}
