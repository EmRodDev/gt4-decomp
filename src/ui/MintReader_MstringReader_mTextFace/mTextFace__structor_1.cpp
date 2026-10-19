#include "gt4/mTextFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mTextFace__vtable;
extern "C" void func_002B6EA8(void *, s32);
extern "C" void func_00203118(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mWidget__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)s->p - 1;
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

struct MemberA0 {
    char pad0[0x10];
    Str str10;
    char pad14[0x2C];
};

static inline void member_dtor_0(MemberA0 *m) {
    str_release(&m->str10);
    func_00203118(m, 2);
}

struct mTextFaceInternal {
    void *vptr0;
    void *unk4;
    s32 unk8;
    s32 unkC;
    char pad10[0x90];
    MemberA0 memberA0;
    char memberE0[0x24];
    void *unk104;
};

extern "C" void mTextFace__structor_1(mTextFaceInternal *arg0, s32 arg1) {
    arg0->unk4 = &mTextFace__vtable;
    func_002B6EA8(&arg0->unk104, 0x2);
    func_00203118(arg0->memberE0, 0x2);
    member_dtor_0(&arg0->memberA0);
    mWidget__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x120, 0x4, "RefCounter");
    }
}
