/* Resolves the object at +0x14 with func_00441248 and returns what func_00445350 reads from it. Purpose unknown. */
typedef int s32;

extern s32 func_00441248(s32 a);
extern s32 func_00445350(s32 a);

struct func_00145AB8_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00145AB8(void *self) {
    return func_00445350(func_00441248(((struct func_00145AB8_arg0 *)self)->unk14));
}
