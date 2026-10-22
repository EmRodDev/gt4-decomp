/* compiler: ee-gcc2.96-stl */
typedef short s16;
extern "C" void func_003FB4C0(void *, int);
static inline void *get(void *o) {
    char *e = *(char **)o + 0x1F0;
    void *fn = *(void **)(e + 4);
    return ((void *(*)(void *))fn)((char *)o + *(s16 *)e);
}
static inline void copy(void *o, void *x) {
    char *e = *(char **)o + 0x68;
    void *fn = *(void **)(e + 4);
    ((void (*)(void *, void *))fn)((char *)o + *(s16 *)e, x);
}
extern "C" void RacePhotoModeCameraManager__virtual_63(void *self) {
    void *obj = get(self);
    void *dst;
    if (obj == 0) {
        dst = (char *)self + 0x9C0;
        return func_003FB4C0(dst, 0);
    } else { dst = (char *)self + 0x9C0;
    copy(obj, dst); }
}
