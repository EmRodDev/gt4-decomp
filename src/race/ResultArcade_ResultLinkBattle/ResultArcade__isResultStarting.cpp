/* ResultArcade__isResultStarting: returns 1 when the base check passes or arg1 matches the field at +0x64. */
struct Obj3DF1B8 {
    char pad[0x64];
    int unk64;
};

extern "C" int func_003E06F8(struct Obj3DF1B8 *arg0, int arg1);

extern "C" int func_003DF1B8(struct Obj3DF1B8 *arg0, int arg1) {
    int var = 0;

    if (func_003E06F8(arg0, arg1) != 0 || arg1 == arg0->unk64) {
        var = 1;
    }
    return var;
}
