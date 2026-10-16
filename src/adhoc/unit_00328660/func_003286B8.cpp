/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void *fn; };
struct Obj { int pad; VEntry *vt; };
extern "C" int func_005B72A8(void);
extern "C" void func_003286B8(Obj *self) {
    int enabled = func_005B72A8();
    VEntry *e = self->vt + 7;
    int result = ((int (*)(void *))e->fn)((char *)self + e->delta);
    if (enabled) __asm__ volatile("ei");
    if (result && self) {
        VEntry *d = self->vt + 1;
        ((void (*)(void *, int))d->fn)((char *)self + d->delta, 3);
    }
}
