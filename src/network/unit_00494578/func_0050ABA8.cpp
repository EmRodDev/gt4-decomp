/* compiler: ee-gcc2.96-nosib */
extern "C" void func_0050A9C0(int) throw();
extern "C" int func_0050A9D0(void) throw();
extern "C" int func_0050AA68(void *) throw();
extern "C" void func_0050AB40(int *) throw();
extern "C" void func_0050AB50(void *) throw();
extern "C" int func_0050B460(int, int, int, void *);

struct L {
    char a[0x94];
    char c1[0x3C];
    char b[0xBC];
    char c2[0x34];
    int code;
    char pad[0xC];
};

extern "C" int func_0050ABA8(void) {
    L l;
    char *pb;
    int r = 0;
    if (func_0050A9D0() == 2) {
        func_0050A9C0(0);
        return -0xA;
    }
    if (func_0050A9D0() == 1) {
        func_0050A9C0(0);
        func_0050AB40(&l.code);
        pb = l.b;
        if (l.code != 0x12) {
            if (l.code == 0x2C) {
                func_0050AB50(l.a);
                func_0050AA68(l.c1);
                r = func_0050B460(1, 0xF3, 0xC4, l.a);
            }
        } else {
            func_0050AB50(pb);
            func_0050AA68(l.c2);
            r = func_0050B460(1, 0x1F, 0xEC, pb);
        }
    }
    return r == 0 ? 0 : -0xA;
}
