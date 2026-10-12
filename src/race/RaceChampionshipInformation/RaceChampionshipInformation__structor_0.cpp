typedef int s32;
extern "C" void *func_003BB340(s32 *arg0);
extern "C" s32 func_00444190(s32 arg0);
extern "C" char D_006850C0[];

extern "C" void func_003EE590(void *arg0) {
    func_003BB340((s32 *)arg0);
    *(s32 *)((char *)arg0 + 0x12C) = (s32)D_006850C0;

    char *p = (char *)arg0 + 0x180;
    for (s32 i = 5; i != -1; i--) {
        func_00444190((s32)p);
        p += 0x188;
    }

    *(s32 *)((char *)arg0 + 0x118) = 6;

    char *q = (char *)arg0 + 0x2F0;
    for (s32 j = 0; j < 6; j++) {
        *(s32 *)(q + 0x8) = 0;
        *(s32 *)(q + 0xC) = 0;
        q += 0x188;
    }

    *(s32 *)((char *)arg0 + 0x170) = 0;
    *(s32 *)((char *)arg0 + 0x174) = 0;
    *(s32 *)((char *)arg0 + 0x178) = 0;
}
