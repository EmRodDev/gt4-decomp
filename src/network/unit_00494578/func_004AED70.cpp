/* compiler: ee-gcc2.96-stl */
struct VE { short adj; short pad; void (*fn)(char *); };
struct VT { char pad[0x48]; VE e48; };
struct A { char pad[0x60]; int f60; char pad64[0x44]; int fA8; int fAC; };
struct A2 { char pad[0x60]; void *f60; char pad64[0x44]; VT *vt; int fAC; };
struct B { char pad[0x50]; A2 *f50; int f54; };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_004AF568(void *);
extern "C" int func_0057CAB8(void *, void *);
extern "C" void func_0057CB80(void *, void *);
extern "C" void func_004AED70(A2 *a, B *b) {
    void *r;
    func_00576788(a);
    r = 0;
    if (a == b->f50 && func_0057CAB8(&a->fAC, ((char *)b + 0x54)) != 0) {
        func_0057CB80(&a->fAC, ((char *)b + 0x54));
        if (a->fAC == 0) {
            VE *e = &a->vt->e48;
            r = a->f60;
            a->f60 = 0;
            e->fn((char *)a + e->adj);
        }
    }
    func_005767C0(a);
    if (r != 0) func_004AF568(a);
}
