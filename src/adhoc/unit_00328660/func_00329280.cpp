typedef int s32;
typedef short s16;
struct R { char pad[0x44]; s32 f44; };
struct VEntry { s16 delta; s16 index; R *(*fn)(char *, s32); };
struct Obj { VEntry *vtbl; };

/* Layout backed by ADHOC::Pool:
 *   vtable slot 2 (0x10 / 8): get_record(s32)
 */
extern "C" void func_00329280(Obj *o, s32 b, s32 c) {
    VEntry *e = &o->vtbl[2];
    R *r = e->fn((char *)o + e->delta, b);
    r->f44 = c;
}
