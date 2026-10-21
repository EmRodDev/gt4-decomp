/* Thin wrapper: passes the 32-bit field at +8 to func_0046BC40 and returns its result (sibling of func_0046BC80, which does the
 * same with func_0046BC00). Purpose unknown. */
typedef int s32;
struct Obj {
    char pad0[8];
    s32 unk8;
};
extern "C" s32 func_0046BC40(s32 value);
extern "C" s32 func_0046BC98(Obj *self)
{
    return func_0046BC40(self->unk8);
}
