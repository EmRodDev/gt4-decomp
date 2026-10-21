/* compiler: ee-gcc2.96-nsa-nosib */
/* Returns 0 when func_004B3E40 reports 0; otherwise 1 if the mode value at +0x164 is one of 0, 2, 6 or 7, else 0.
 * What the mode values and func_004B3E40 mean is unknown. */
extern "C" int func_004B3E40(void);

struct func_002A64D8_arg0 {
    char pad0[0x164];
    int unk164;
};

extern "C" int func_002A64D8(void *obj) {
    struct func_002A64D8_arg0 *self = (struct func_002A64D8_arg0 *)obj;
    int precondition = func_004B3E40();
    if (precondition == 0) {
        return precondition;
    }
    int flag = 0;
    int mode = self->unk164;
    if (mode == 0 || mode == 6 || mode == 2 || mode == 7) {
        flag = 1;
    }
    return flag;
}
