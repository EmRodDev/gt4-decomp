struct Obj { int refs; char *vtbl; };
struct Entry { short delta; short index; int (*fn)(void *); };
extern Obj *D_006191A8;
extern char D_00698C90[];
extern "C" void mShell__structor_0(void *) throw();
extern "C" void func_002EA590(void *, int);
extern "C" int func_002EAB90(int, int, void *);
extern "C" void func_002ECDE0(void *);
extern "C" void *func_00326750(unsigned, int, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" Obj *func_005DBF48(int flag) {
    if (flag) {
        if (D_006191A8) {
            func_003285F8(D_006191A8);
        }
        D_006191A8 = 0;
    } else if (!D_006191A8) {
        Obj *p = (Obj *)func_00326750(0x14, 4, D_00698C90);
        mShell__structor_0(p);
        D_006191A8 = p;
        func_003285A8(p);

        Obj *o = D_006191A8;
        Entry *e = (Entry *)(o->vtbl + 0x20);
        int value = e->fn((char *)o + e->delta);

        int h[4];
        func_002ECDE0(h);
        func_002EAB90(h[0], value, (void *)func_005DBF48);
        func_002EA590(h, 2);
    }
    return D_006191A8;
}
