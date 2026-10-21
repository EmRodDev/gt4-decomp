/* Advances rotation-like accumulators (inferred from the wrap at 80000000.0, which keeps the float precise): the rate at +0x5C4 times
 * the scale at +0x54C is added to the value kept by func_00343518 and to the counter at 0x5D0; with the mode byte at 0x466 == 1
 * the counter at 0x6AC advances too. Does nothing while the rate is negative (negative means disabled, inferred). */
struct func_0035DD00_sub {
    char pad0[0x466];
    signed char unk466;
    char pad1[0x5C4 - 0x467];
    float unk5C4;
    char pad2[0x5D0 - 0x5C8];
    float unk5D0;
    float unk5D4;
    char pad3[0x6AC - 0x5D8];
    float unk6AC;
};

struct func_0035DD00_arg0 {
    char pad0[0x54C];
    float unk54C;
};

extern "C" float func_00343518(unsigned int *total, float amount);

extern "C" void func_0035DD00(struct func_0035DD00_arg0 *self) {
    struct func_0035DD00_sub *state = (struct func_0035DD00_sub *)((char *)self + 0x104);
    float step = state->unk5C4;
    float wrapped;
    float counter;
    float wrapLimit;

    if (!(step < 0.0f)) {
        step = step * self->unk54C;
        wrapped = func_00343518((unsigned int *)((char *)self + 0x6DC), state->unk5D4 + step);
        counter = state->unk5D0 + step;
        wrapLimit = 0x1.312D00p+26f;
        state->unk5D4 = wrapped;
        state->unk5D0 = counter;
        if (counter >= wrapLimit) {
            state->unk5D0 = counter - wrapLimit;
        }
        if (state->unk466 == 1) {
            wrapped = state->unk6AC + step;
            state->unk6AC = wrapped;
            if (wrapped >= wrapLimit) {
                state->unk6AC = wrapped - wrapLimit;
            }
        }
    }
}
