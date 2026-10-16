struct Obj {
    char p0[0xC];
    int c;
    char p10[4];
    int v14;
    char p18[4];
    int v1c;
    int v20;
    int v24;
};
extern "C" int func_00538C68(void *p);
extern "C" int func_00538D50(void *p, int a, int b);
extern "C" int func_00571530(Obj *arg0) {
    if (arg0 == 0) {
        return 2;
    }
    if (arg0->c + 0x40 >= 0x2001) {
        return 1;
    }
    void *s1 = &arg0->p10;
    if (func_00538D50(s1, 0x2040, 0x40) != 0) {
        return 3;
    }
    arg0->v20 = arg0->v14;
    int r = func_00538D50(&arg0->p18, 0x2040, 0x40);
    if (r != 0) {
        func_00538C68(s1);
        return 3;
    }
    arg0->v24 = arg0->v1c;
    return r;
}
