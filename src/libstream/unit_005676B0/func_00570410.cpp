struct Dst {
    int w0;
    int w4;
};
struct Src {
    char pad[8];
    int w8;
};
extern "C" int func_00538C68(void **p);
extern "C" int func_005715D8(void *p);
extern "C" int func_00590FD8(void *self, int id, int a, void *mode, int b, void *mode2, int c, int d, int e);
extern "C" int func_00570410(void *arg0, Dst *dst, Src *src, int value) {
    if (src == 0) {
        return -0x200;
    }
    dst->w0 = src->w8;
    dst->w4 = value;
    void *sp = src;
    int s0 = func_00590FD8(arg0, 0x66, 0, dst, 0x10, dst, 0x10, 0, 0);
    if (func_005715D8(sp) != 0 || func_00538C68(&sp) != 0) {
        return -0x1F5;
    }
    return s0 < 0 ? -0x1F5 : 0;
}
