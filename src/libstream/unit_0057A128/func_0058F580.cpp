/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
extern const char *D_00657B20[];
extern u8 D_006CF3F0;
extern "C" char *func_005A609C(char *, const char *);
extern "C" void func_0058F580(unsigned idx, u8 *out) {
    if (idx < 4) {
        func_005A609C((char *)out, D_00657B20[idx]);
        return;
    }
    *out = D_006CF3F0;
}
