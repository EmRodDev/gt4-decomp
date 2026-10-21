/* Forwards the sub-object at +4 and the field at +0x7C, with the second argument, to func_0056F868. Sibling of func_004EF768 and func_004EF6B0 (same +4/+0x7C pattern); purpose unknown. */
extern void func_0056F868(void *, int, int);

struct func_004EF9A0_arg0 {
    char pad0[0x7C];
    int unk7C;
};

void func_004EF9A0(void *self, int value)
{
    func_0056F868((char *)self + 4, ((struct func_004EF9A0_arg0 *)self)->unk7C, value);
}
