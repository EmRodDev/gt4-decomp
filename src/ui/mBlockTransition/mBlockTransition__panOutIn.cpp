/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
/* Layout backed by include/gt4/mWidget.h: slot 69 (0x228 / 8) */
struct Obj { int f0; VEntry *vtbl; };
extern "C" void mTransition__panOutIn(Obj *, Obj *);
extern "C" void mUpdateContext__Sync(int);
extern "C" int mBlockTransition__initialize_blocks(Obj *) throw();
extern "C" void mBlockTransition__panOutIn(Obj *self, Obj *other) {
    mTransition__panOutIn(self, other);
    VEntry *e = &other->vtbl[69];
    e->fn((char *)other + e->delta);
    mUpdateContext__Sync(1);
    mBlockTransition__initialize_blocks(self);
}
