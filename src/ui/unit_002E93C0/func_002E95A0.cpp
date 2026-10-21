/* Dispatches to func_002663C8 when the field at +0xC4 is nonzero, otherwise to func_002663F8, passing the argument through and returning the result.
 * Same shape as func_002E9540. */
extern int func_002663C8(int);
extern int func_002663F8(int);

struct func_002E95A0_arg0 {
    char pad0[0xC4];
    int unkC4;
};

int func_002E95A0(void *obj, int value)
{
    if (((struct func_002E95A0_arg0 *)obj)->unkC4 != 0) {
        return func_002663C8(value);
    }
    return func_002663F8(value);
}
