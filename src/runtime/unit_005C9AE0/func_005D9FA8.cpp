struct Obj { int refs; char *vtbl; };
struct Entry { short delta; short index; int (*fn)(void *); };
extern Obj *D_00619018;
extern char D_00697970[];
extern "C" void mManager__structor_0(void *) throw();
extern "C" void func_002EA590(void *, int);
extern "C" int func_002EAB90(int, int, void *);
extern "C" void func_002ECDE0(void *);
extern "C" void *func_00326750(unsigned, int, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" Obj *func_005D9FA8(int flag) {
    if (flag) {
        if (D_00619018) {
            func_003285F8(D_00619018);
        }
        D_00619018 = 0;
    } else if (!D_00619018) {
        Obj *p = (Obj *)func_00326750(0x30, 4, D_00697970);
        mManager__structor_0(p);
        D_00619018 = p;
        func_003285A8(p);

        Obj *o = D_00619018;
        Entry *e = (Entry *)(o->vtbl + 0x20);
        int value = e->fn((char *)o + e->delta);

        int h[4];
        func_002ECDE0(h);
        func_002EAB90(h[0], value, (void *)func_005D9FA8);
        func_002EA590(h, 2);
    }
    return D_00619018;
}
