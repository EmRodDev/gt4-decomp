struct VEntry { short delta; short index; int (*fn)(void *); };
struct ReadEntry { short delta; short index; bool (*fn)(void *, void *, int); };
struct Obj { int field0; VEntry *vtbl; };

/* Layout backed by include/gt4/hIO.h:
 *   vtable slot 52 (0x1a0 / 8): is_eof()
 *   vtable slot 50 (0x190 / 8): read(buf, len)
 */
extern "C" int hIO__cget(Obj *self) {
    unsigned char c;
    VEntry *e = &self->vtbl[52];
    if (e->fn((char *)self + e->delta) != 0) return -1;
    ReadEntry *r = (ReadEntry *)&self->vtbl[50];
    c = 0;
    bool success = r->fn((char *)self + r->delta, &c, 1);
    if (success == false) return -1;
    return c;
}
