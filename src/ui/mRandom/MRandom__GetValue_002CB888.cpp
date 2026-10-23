/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct RefCounter;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(char *);
};

struct Vobj {
    char pad0[4];
    char *vt;
};

struct Handle {
    void *p;
    char pad[0xC];
};

struct Arr {
    char pad0[8];
    Vobj *obj;
};

extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" s32 func_002FE250(void *arg0);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_005792E8(void *arg0, s32 arg1);
extern "C" f32 mBlockTransition__getBlock(void *arg0, f32 a, f32 b);
extern "C" f32 func_00579398(f32 a);

static inline void assign(Handle *dst, Handle *src) {
    if ((void *)dst != (void *)src) {
        RefCounter *n = (RefCounter *)src->p;
        if (n != 0) {
            func_003285A8(n);
        }
        if (dst->p != 0) {
            func_003285F8((RefCounter *)dst->p);
        }
        dst->p = n;
    }
}

extern "C" void MRandom__GetValue(Handle *arg0, s32 arg1, Arr *arg2) {
    Handle hh[2];
    s32 s1, s3;
    if (arg1 >= 2) {
        func_002FC8C8(hh, arg2);
        s1 = func_002FE250(hh[0].p);
        func_002FC870(hh, 2);
        func_002FC8C8(hh, (char *)arg2 + 4);
        s3 = func_002FE250(hh[0].p);
        func_002FC870(hh, 2);
        if (arg1 < 3) {
            func_002FE278(hh, (s32)(func_00579398((f32)(s3 - s1)) + (f32)s1));
            assign(arg0, hh);
            func_002FC870(hh, 2);
        } else {
            Vobj *o = arg2->obj;
            VEntry *e = (VEntry *)(o->vt + 0x58);
            int v = 1;
            func_005792E8((hh + v), e->fn((char *)o + e->delta));
            func_002FE278(hh, (s32)mBlockTransition__getBlock((hh + 1), (f32)s1, (f32)s3));
            assign(arg0, hh);
            func_002FC870(hh, 2);
        }
    }
}
