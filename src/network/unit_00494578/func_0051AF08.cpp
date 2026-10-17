/* compiler: ee-gcc2.96-as2004g */
struct Obj { char pad[8]; signed char data[0x10000]; };
extern Obj *D_0064B4B4;
static inline int allocate(unsigned int n) {
        for (int i = 0; i < (int)(0x1000 - n); i++) {
            if (D_0064B4B4->data[i + 0xE630] == 0) {
                int end = i + n;
                int ok = 1;
                for (int j = i + 1; j < end; j++) {
                    if (D_0064B4B4->data[j + 0xE630] != 0) { ok = 0; break; }
                }
                if (ok) {
                    for (int j = i; j < end; j++) D_0064B4B4->data[j + 0xE630] = 1;
                    return i;
                }
            }
        }
    return -1;
}
extern "C" int func_0051AF08(unsigned int n) {
    if (n >= 0x1000U) return 0x100;
    return allocate(n);
}
