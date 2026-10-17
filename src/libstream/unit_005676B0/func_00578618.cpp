/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_00874950[];
extern "C" void func_00577F80();
extern "C" int func_00578618(int v) {
    int idx = v & 0xFF;
    int gen = (v >> 8) & 0xFFFF;
    if (gen != D_00874950[idx]) {
        func_00577F80();
        idx = -1;
    }
    return idx;
}
