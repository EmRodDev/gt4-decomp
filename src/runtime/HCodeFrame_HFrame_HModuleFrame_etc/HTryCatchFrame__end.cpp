typedef int s32;
#define NULL 0

struct Temp24 {
    char pad0[0x30];
    s32 unk30;
};

struct Temp2C {
    char pad0[0x20];
    s32 unk20;
};

struct HTryCatchFrame {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

struct HContext {
    char pad0[0x24];
    Temp24 *unk24;
    s32 unk28;
    Temp2C *unk2C;
};

extern "C" void HTryCatchFrame__end(HTryCatchFrame *arg0, HContext *arg1) {
    s32 offset = arg0->unk4;
    Temp24 *code = arg1->unk24;
    s32 pc;
    if (code != NULL) {
        pc = code->unk30 + offset * 4;
    } else {
        pc = 0;
    }
    arg1->unk28 = pc;
    arg1->unk2C->unk20 = arg0->unk8;
}
