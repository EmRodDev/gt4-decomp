typedef int s32;

struct S_Vec {
    char pad0[4];
    char *unk4;
    char *unk8;
    s32 size() { return (s32)(unk8 - unk4) >> 4; }
};

struct mColorFace {
    char pad0[0xA0];
    S_Vec vec;
};

extern "C" s32 func_00286060(mColorFace *arg0) {
    return arg0->vec.size();
}
