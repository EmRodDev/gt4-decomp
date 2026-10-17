/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short pad; void (*fn)(void *, int); };
struct Self { char pad[0x64]; char *vt; };
extern char D_00655340[];
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0055BF18(Self *self, int arg) {
    int *state = (int *)((char *)self + 0x234);
    func_00576100(D_00655340);
    *state = 0;
    VEntry *e = (VEntry *)(*(char **)((char *)self + 0x64) + 0x18);
    e->fn((char *)self + e->delta, arg);
    func_00576140(D_00655340);
}
