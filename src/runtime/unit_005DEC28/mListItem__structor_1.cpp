/* compiler: ee-gcc2.96-no-strict-aliasing */
struct RefCounter { int count; void *vtable; };
extern char mListItem__vtable[];
extern "C" int RefCounter__structor_0(RefCounter *);
struct ListItem : RefCounter {
    int f[5];
    union {
        unsigned short half;
        struct { unsigned lo : 16; unsigned a : 1; unsigned b : 1; unsigned c : 1; } bits;
    } u;
};
extern "C" void mListItem__structor_1(ListItem *self) {
    RefCounter__structor_0(self);
    self->u.half = 0;
    self->vtable = mListItem__vtable;
    self->u.bits.a = 0;
    self->u.bits.b = 0;
    self->u.bits.c = 0;
    self->f[0] = 0;
    self->f[1] = 0;
    do { self->f[2] = 0; } while (0);
    self->f[3] = 0;
    self->f[4] = 0;
}
