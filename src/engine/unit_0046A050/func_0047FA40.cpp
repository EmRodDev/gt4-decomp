/* Rebases a pointer after its target moved: if the pointer stored at +0x10 is non-null it is advanced by 'delta'
 * (inferred from the null test plus add; sibling of func_0047EEC8, which does the same at +0xC). */
typedef int s32;
extern "C" void func_0047FA40(int *self, s32 delta)
{
    int pointer;
    self = (int *)((char *)self + 0x10);
    pointer = *self;
    if (pointer != 0) {
        *self = pointer + delta;
    }
}
