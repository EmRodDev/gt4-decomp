/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_00874550[];
extern "C" void func_00577F80();
extern "C" int func_00578290(int v) {
    int gen = (v >> 8) & 0x7FFFFF;
    int idx = v & 0xFF;
    if (gen == 0 || gen != D_00874550[idx]) {
        func_00577F80();
        idx = -1;
    }
    return idx;
}
