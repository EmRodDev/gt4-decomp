/* Sets a colour through func_004AA1D8 (the four floats are read as red, green, blue and alpha; inferred from the
 * 1/128 scaling and the 0..1 check on the last one) after adjusting the alpha from the state object. If state+0x14
 * is zero, func_00473638 initializes the state first. When state+0xC is non-zero the alpha is replaced by the int
 * at +0x24 times 0.0078125 (1/128) and id 9 is switched off with func_004AB040. Otherwise, when state+0 is non-
 * zero and state+4 is zero, an alpha that is exactly 1.0 after scaling by 128 turns id 9 on with func_004A1638(9,
 * red) (the first colour value is passed along, purpose unknown), any other alpha turns it off. The 128 comparison
 * is done on the integer value of alpha * 128. */
extern "C" void func_00473638(void *state);
extern "C" void func_004A1638(int state, float arg1);
extern "C" void func_004AA1D8(float state, float arg1, float arg2, float arg3);
extern "C" void func_004AB040(int state);

struct func_00473438_arg0 {
    int unk0;
    int unk4;
    char pad8[0x4];
    int unkC;
    char pad10[0x4];
    int unk14;
    char pad18[0xC];
    int unk24;
};

extern "C" void func_00473438(void *state, float red, float green, float blue, float alphaIn) {
    float alpha;

    alpha = alphaIn;
    if (((struct func_00473438_arg0 *)state)->unk14 == 0) {
        func_00473638(state);
    }
    if (((struct func_00473438_arg0 *)state)->unkC != 0) {
        alpha = (float)((struct func_00473438_arg0 *)state)->unk24 * 0.0078125f;
        func_004AB040(9);
    } else if (((struct func_00473438_arg0 *)state)->unk0 != 0) {
        if (((struct func_00473438_arg0 *)state)->unk4 == 0) {
            if ((int)(alpha * 128.0f) == 0x80) {
                alpha = 1.0f;
                func_004A1638(9, red);
            } else {
                func_004AB040(9);
            }
        }
    }
    func_004AA1D8(red, green, blue, alpha);
}
