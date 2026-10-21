/* Ramp step: while flag 0x100 is set, raises 'cur' by step * k (step defaults to D_00620E25 * 0.1 when zero) up to the limit; on
 * reaching it clears the flag and, when neither 0x40 nor 0x80 is set, starts a 90-frame timer (0x5A). Purpose unknown (could be a
 * fade or gauge). */
struct Sub {
    char pad0[0x4B8];
    union {
        struct {
            unsigned short flags;
            unsigned short timer;
        } h;
        float fl;
    } u;
    char pad1[0x4CC - 0x4BC];
    float lim;
};

struct Obj {
    char pad0[0x54C];
    float k;
    char pad1[0x5D4 - 0x550];
    float cur;
};

extern unsigned char D_00620E25;

extern "C" void func_00354D60(Obj *self, float step) {
    Sub *state = (Sub *)((char *)self + 0x104);
    if (state->u.h.flags & 0x100) {
        float lim = state->lim;
        float *current = &self->cur;
        if (step == 0.0f)
            step = (float)D_00620E25 * 0x1.999998p-4f;
        float newValue = *current + step * self->k;
        *current = newValue;
        if (lim <= newValue) {
            *current = lim;
            int flagsAfter = state->u.h.flags ^ 0x100;
            state->u.h.flags = (unsigned short)flagsAfter;
            if (!(flagsAfter & 0xC0))
                state->u.h.timer = 0x5A;
        }
    }
}
