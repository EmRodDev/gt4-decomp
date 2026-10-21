/* Indexed lookup: reads the signed byte stored at self + index + 0xC and passes it, with the handle at +4, to
 * func_00344D48. Same shape as func_003D7648, func_003D7360 and func_003D7670, which differ only in the callee. */
typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_00344D48(s32 handle, s8 entry);

extern "C" s32 func_003D7380(Obj *self, s32 index) {
    char *entryBase = (char *)self + index;
    return func_00344D48(self->unk4, *(s8 *)(entryBase + 0xC));
}
