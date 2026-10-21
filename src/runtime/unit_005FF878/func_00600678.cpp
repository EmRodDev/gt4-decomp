/* Deleting destructor shape: stores the class's vtable pointer (D_006872E0) at +0x4, calls no base-class destructor, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
struct S {
    char pad[0x4];
    int unk4;
};

extern void func_005C1628(S *);
extern int D_006872E0;

void func_00600678(S *self, int deleteFlag)
{
    deleteFlag = deleteFlag & 1;
    self->unk4 = (int)&D_006872E0;
    if (deleteFlag)
    {
        func_005C1628(self);
        return;
    }
}
