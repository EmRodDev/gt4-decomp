typedef int s32;
typedef float f32;

/* Returns a float table entry; the first argument is a pointer to the owner pointer. */
extern "C" f32 func_00364D78(void *arg0, s32 arg1);

struct Obj00459CC8 {
    char pad0[4];
    void *unk4;
};

extern "C" f32 func_00459CC8(char *arg0, s32 arg1) {
    s32 t1 = *(s32 *)(arg0 + arg1 * 0x10 + 0x1C);
    void *t0 = ((struct Obj00459CC8 *)arg0)->unk4;
    return func_00364D78(t0, t1);
}
