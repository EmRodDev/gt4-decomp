typedef unsigned int u32;
extern "C" void func_00544A18(u32 *p, u32 n) {
    u32 i;
    for (i = 0; i < 32; i++, p++) {
        if (i != 0) {
            u32 v = *p;
            if (v != 0) { *p = v - 1; return; }
            *p = 0xFFFFFFFF;
        } else {
            u32 v = *p;
            if (v < n) {
                *p = v - n;
            } else {
                *p = v - n;
                break;
            }
        }
    }
}
