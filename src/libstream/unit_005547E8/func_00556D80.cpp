/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { int key; char pad4[0x280]; int missing; };
extern "C" int func_00566EA8(void *, int, void *);
extern char D_00655290[];
extern "C" int func_00556D80(Self *self) {
    char buf[16];
    return self->missing = (func_00566EA8(D_00655290, self->key, buf) == 0);
}
