#include "gt4/mTextFace.h"
typedef int s32;

extern void *mTextFace__vtable;
extern "C" void *mWidget__structor_0(void *);
extern "C" void *func_00246F58(void *);
extern "C" void *func_002B70B8(void *);
extern "C" void *func_0025B4C8(void *, float, float);

struct mTextFaceInternal {
    void *vptr0;
    void *unk4;
    s32 unk8;
    s32 unkC;
    char pad10[0x90];
    char face_data[0x64];
    void *unk104;
    void *unk108;
    void *unk10C;
    void *unk110;
    void *unk114_pvoid;
    void *unk118_pvoid;
    void *unk11C_pvoid;
};

extern "C" void mTextFace__structor_0(mTextFaceInternal *arg0) {
    mWidget__structor_0(arg0);
    arg0->unk4 = &mTextFace__vtable;
    func_00246F58(arg0->face_data);
    func_002B70B8(&arg0->unk104);
    arg0->unk108 = 0;
    arg0->unk114_pvoid = 0;
    arg0->unk10C = (void *)(-0x1);
    arg0->unk110 = (void *)(-0x1);
    arg0->unk118_pvoid = 0;
    arg0->unk11C_pvoid = 0;
    return (void)func_0025B4C8(arg0, 256.000007629f, 24.0000004768f);
}
