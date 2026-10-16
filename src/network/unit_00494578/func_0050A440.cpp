struct Blk { char pad[0x124]; int *p124; int x128; int *p12c; int x130; };
extern "C" int func_00538BF8(void *, int);
extern "C" int func_00538C68(void *);
extern "C" long func_0050A440(Blk **out, int n, int m) {
    if (func_00538BF8(out, 0x134) != 0) return -4;
    if (func_00538BF8(&(*out)->p124, n) != 0) {
        func_00538C68(out);
        return -4;
    }
    if (m) {
        if (func_00538BF8(&(*out)->p12c, m) != 0) {
            func_00538C68((*out)->p124);
            func_00538C68(out);
            return -4;
        }
        return 0;
    }
    return 0;
}
