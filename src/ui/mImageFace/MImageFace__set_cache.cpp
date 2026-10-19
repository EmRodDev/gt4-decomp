/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(VObj_58 *o) {
    VEntry_58 *e = &o->vtbl[11];
    return e->fn((char *)o + e->delta);
}

struct ImageFaceLayout {
    char pad0[0xC8];
    s32 cache_flags;
};

struct Handle {
    ImageFaceLayout *p;
    char pad[0xC];
};

extern "C" void func_002A0D78(void *arg0, void *arg1);
extern "C" void func_002A0D20(void *arg0, s32 arg1);

extern "C" void MImageFace__set_cache(s32 *arg0, void *arg1, s32 arg2, VObj_58 **arg3) {
    Handle buf0;
    ImageFaceLayout *v_s0;
    s32 flag;
    if (arg2 > 0) {
        func_002A0D78(&buf0, arg1);
        v_s0 = buf0.p;
        flag = vcall_58(*arg3) != 0;
        v_s0->cache_flags = (v_s0->cache_flags & ~1) | flag;
        func_002A0D20(&buf0, 2);
    }
}
