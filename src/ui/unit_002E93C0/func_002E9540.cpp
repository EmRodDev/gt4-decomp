/* Dispatches to func_00266368 when the field at +0xC4 is nonzero, otherwise to func_00266398, passing the argument through and returning the result.
 * What the two callees do is unknown. */
extern int func_00266368(int);
extern int func_00266398(int);

struct func_002E9540_arg0 {
    char pad0[0xC4];
    int unkC4;
};

int func_002E9540(void *obj, int value)
{
    if (((struct func_002E9540_arg0 *)obj)->unkC4 != 0) {
        return func_00266368(value);
    }
    return func_00266398(value);
}
