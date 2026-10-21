/* Deleting destructor shape: stores the class's vtable pointer (D_0065CE00) at +0, runs the base-class destructor none; no base destructor is called, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int D_0065CE00;

void func_005CB748(S *self, int deleteFlag)
{
    deleteFlag = deleteFlag & 1;
    self->unk0 = (int)&D_0065CE00;
    if (deleteFlag)
    {
        func_005C1628(self);
        return;
    }
}
