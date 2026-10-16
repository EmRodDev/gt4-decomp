struct Obj { char pad[0x40]; int n; };
extern "C" int func_00571210(void *, Obj *, int, int, int, int *, int *);
extern "C" int func_00570AB8(void *a0, void *a1, void *a2, Obj *a3, int *a4, int a5, int a6, int a7) {
    int sp0 = 0;
    int sp4 = -501;
    if (a0 != 0) {
        if (a7 < -1) return -501;
        if (a1 != 0) goto valid;
    }
    return -501;
valid:
    if (a3->n == 0) return 0;
    if (func_00571210(a2, a3, *a4, a5, a6, &sp0, &sp4) == 0) return sp0;
    return sp4 == 0 ? -501 : sp4;
}
