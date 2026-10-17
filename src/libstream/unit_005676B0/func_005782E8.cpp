/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Req { int w0; int a1; int a0; int rest[3]; };
extern int D_00874550[];
extern "C" void func_00577F80();
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_005ADCA0(Req *);
extern "C" int func_005782E8(int a0, int a1) {
    Req req;
    int gen;
    int idx;
    int none = -1;
    func_005A48D8(&req, 0, 0x18);
    Req *rp = &req;
    rp->a0 = a0;
    rp->a1 = a1;
    while ((idx = func_005ADCA0(rp)) == none) func_00577F80();
    gen = D_00874550[idx];
    gen = (gen + 1) & 0x7FFFFF;
    if (gen == 0) gen = 1;
    D_00874550[idx] = gen;
    return idx | (gen << 8);
}
