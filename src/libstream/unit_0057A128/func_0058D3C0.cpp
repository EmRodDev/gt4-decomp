/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
extern "C" void func_0058D2E8(void *);
extern "C" void func_0058D3C0(u8 *p) {
    if (p[3] == 0) {
        p[3] = 0x17;
        func_0058D2E8(p);
        return;
    }
    p[3]--;
}
