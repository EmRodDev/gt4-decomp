/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(VObj_58 *o) {
    VEntry_58 *e = &o->vtbl[11];
    return e->fn((char *)o + e->delta);
}

struct MoveActorLayout {
    char pad0[0x60];
    s32 flip;
};

struct Handle {
    MoveActorLayout *p;
    char pad[0xC];
};

extern "C" void func_002C03E0(void *arg0, void *arg1);
extern "C" void func_002C0388(void *arg0, s32 arg1);

extern "C" void MMoveActor__set_flip(s32 *arg0, void *arg1, s32 arg2, VObj_58 **arg3) {
    Handle buf0;
    MoveActorLayout *v_s0;
    if (arg2 > 0) {
        func_002C03E0(&buf0, arg1);
        v_s0 = buf0.p;
        v_s0->flip = vcall_58(*arg3) != 0;
        func_002C0388(&buf0, 0x2);
    }
}
