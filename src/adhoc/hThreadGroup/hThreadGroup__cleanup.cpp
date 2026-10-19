typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void hObject__cleanup(void);
extern "C" void func_00318508(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00318538(void *, s32);
extern "C" void func_005F1AE0(void *);

struct hThreadGroupClean {
    s32 word0;
    void *vt;
    s32 word8;
    s32 wordC;
    s32 alloc;
    s32 list;
};

extern "C" void hThreadGroup__getClassID(hThreadGroupClean *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    p_s1 = &arg0->alloc;
    hObject__cleanup();
    buf1[0] = 0;
    func_00318508(buf0, buf1);
    if ((char *)p_s1 != (char *)buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *p_s1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *p_s1 = newVal;
    }
    func_00318538(buf0, 0x2);
    func_005F1AE0(&arg0->list);
}
