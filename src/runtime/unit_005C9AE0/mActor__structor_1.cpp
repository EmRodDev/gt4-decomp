/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char mMCFileActor__vtable[], mActor__vtable[], D_00690CE0[];
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };


extern "C" void func_00105280(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void hObject__structor_2(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


extern "C" void mActor__structor_1(void *arg0, s32 arg1) {
    *(char **)((char *)arg0+4) = mMCFileActor__vtable;
    func_00105280((char *)arg0 + 0x40, 0x2);
    *(char **)((char *)arg0+4) = mActor__vtable;
    str_release((Str *)((char *)arg0 + 0x10));
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x80, 0x4, D_00690CE0);
    }
}
