/* compiler: ee-gcc2.96-nosib */
/* Answers whether the selection can step down (name from GT HD): false when func_0057CE80 on the member at +0xBC returns true,
 * otherwise true exactly when the float at +0xEC is negative. The meaning of the two tests is unknown. */
typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xEC];
    f32 unkEC;
};

extern "C" bool func_0057CE80(Obj *member);

extern "C" s32 mSelectBox__canDecrement(Obj *box) {
    s32 result;

    if (func_0057CE80((Obj *)((char *)box + 0xBC)) != 0) {
        return 0;
    }
    result = 1;
    if (!(box->unkEC < 0.0f)) {
        result = 0;
    }
    return result;
}
