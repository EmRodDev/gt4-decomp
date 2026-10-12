struct Obj {
    char pad0[0x75F];
    unsigned char flag;
};

extern "C" short func_00343B48(Obj *arg0);
extern "C" unsigned func_00357800(char *a, char *b);

extern "C" int func_00357830(int arg0, Obj *arg1) {
    if (!func_00343B48(arg1))
        return 0;
    if (arg1->flag == 1)
        return 0;
    return func_00357800((char *)arg0, (char *)arg1);
}
