/* Thin wrapper: returns func_0054A530(the field at +4 of the object). One of a run of such wrappers (func_001D1708..func_001D1868), each around a different callee; purpose unknown. */
typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_0054A530(s32 self);

extern "C" s32 func_001D1760(Obj *self)
{
    return func_0054A530(self->unk4);
}
