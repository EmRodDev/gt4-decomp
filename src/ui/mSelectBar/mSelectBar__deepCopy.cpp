/* compiler: ee-gcc2.96-no-strict-aliasing */
#define NULL 0

typedef int s32;
typedef short s16;
typedef float f32;

#define FLD(p, t, o) (*(t)((char *)(p) + (o)))

void func_002D4C88(void *arg0, void *arg1);                                   /* extern */
void *func_005C0FC8(s32, s32, s32, void *, s32, void *);                      /* extern */

extern char D_005EA2B0[];
extern char D_005EFF90[];

void func_002D78E0(void *arg0, void *arg1) {
    void *temp_v0;
    void *var_v1;

    func_002D4C88(arg0, arg1);
    var_v1 = NULL;
    if (arg1 != NULL) {
        temp_v0 = FLD(arg1, void **, 4);
        var_v1 = func_005C0FC8(FLD(temp_v0, s32 *, 4), (s32)D_005EA2B0, 0,
                               (char *)arg1 + FLD(temp_v0, s16 *, 0), (s32)D_005EFF90, arg1);
    }
    if (var_v1 != NULL) {
        FLD(arg0, f32 *, 0xE4) = FLD(var_v1, f32 *, 0xE4);
        FLD(arg0, f32 *, 0xE8) = FLD(var_v1, f32 *, 0xE8);
        FLD(arg0, f32 *, 0xD4) = FLD(var_v1, f32 *, 0xD4);
        FLD(arg0, s32 *, 0xD8) = FLD(var_v1, s32 *, 0xD8);
        FLD(arg0, s32 *, 0xDC) = FLD(var_v1, s32 *, 0xDC);
    }
}
