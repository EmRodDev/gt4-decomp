/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00689BB0[];
extern "C" int func_00612480(void *, void *);
extern "C" void func_0055F250(void *, int, int, int, int);
extern "C" void *func_0055F1E0(void *);
extern "C" void func_0055FAB0(void *, void *);
extern "C" void func_0055F6A0(char *self, int a, void *owner) {
    *(int *)self = a;
    *(void **)(self + 4) = owner;
    char *hdr = self + 0x14;
    *(void * volatile *)(self + 0xD0) = D_00689BB0;
    func_00612480(self + 8, self);
    *(int *)(self + 0xCC) = 0;
    func_0055F250(hdr, 0, 0, 0, 0);
    *(char **)(self + 0xC4) = self + 0x18;
    *(void **)(self + 0xC8) = func_0055F1E0(hdr);
    void *p = *(void **)(self + 4);
    if (p) func_0055FAB0(p, self);
}
