/* Virtual slot 70 of mBlurFace (inferred from the symbol name): per-frame draw of the blur, with its strength fading in.
 * It first runs mWidget slot 70 with 0. When arg2 (a draw flag, purpose unknown) is non-zero and unkA0 is 0, the level at +0xA4 grows by 0x1.999998p-4 (about 0.1) per call
 * up to the limit at +0xA8, then, if it is positive, the context's vtable slot 0x218 is called with (5, level). When unkA0 is non-zero and the level is positive,
 * func_0025BAA0 fills a 4-float rectangle (cleared first) and the context's vtable slot 0x220 is called with (rect, 1.0 - level). Level and limit names are inferred from the ramp and clamp. */
#include "types.h"

struct C {
    char pad0[0xA0];
    s32 unkA0;
    f32 level;
    f32 levelLimit;
};

struct VE {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, f32);
};

static inline void vcall(char *o, s32 off, s32 a1, f32 remaining) {
    VE *slot = (VE *)(*(char **)(o + 4) + off);
    slot->fn(o + slot->delta, a1, remaining);
}

extern "C" void mWidget__virtual_70(void *, void *, s32);
extern "C" void func_0025BAA0(C *rawSelf, s32 a1, s32 a2, s32 a3, s32 cur);

extern "C" void mBlurFace__virtual_70(void *rawSelf, void *context, s32 drawFlag) {
    C *self = (C *)rawSelf;
    f32 rect[4];

    mWidget__virtual_70(rawSelf, context, 0);
    if (drawFlag != 0) {
        if (self->unkA0 != 0) {
            if (self->level > 0.0f) {
                rect[0] = 0.0f;
                rect[1] = 0.0f;
                rect[2] = 0.0f;
                rect[3] = 0.0f;
                func_0025BAA0(self, (s32)&rect[0], (s32)&rect[1], (s32)&rect[2], (s32)&rect[3]);
                {
                    VE *slot = (VE *)(*(char **)((char *)context + 4) + 0x220);
                    f32 remaining = 1.0f - self->level;
                    slot->fn((char *)context + slot->delta, (s32)&rect[0], remaining);
                }
            }
        } else {
            f32 cur = self->level;
            f32 limit = self->levelLimit;
            if (cur < limit) {
                self->level = cur + 0x1.999998p-4f;
            } else {
                self->level = limit;
            }
            if (self->level > 0.0f) {
                vcall((char *)context, 0x218, 5, self->level);
            }
        }
    }
}
