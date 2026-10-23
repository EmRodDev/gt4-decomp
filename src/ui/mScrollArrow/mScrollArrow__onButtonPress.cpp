/* mScrollArrow::onButtonPress(mRenderContext *, mButtonEvent *) (GT HD name, vtable slot 73).
 * Runs the base mWidget handler; for button 1 it activates the arrow and forwards the press to the
 * owning scroll window (+0xB0): +0xB4 set picks onHDec/onVDec, clear picks onVInc/onHInc, and +0xB8
 * chooses between the two. Without a window it returns 0, otherwise the base handler's result.
 * The window test must wrap the four calls (if (window) { ... } return 0;): an early
 * `if (!window) return 0;` gives one block less, the function then fits sched1's interblock region
 * limit (10 blocks) and the setActive arguments are hoisted above the button test. */
#include "types.h"

struct mButtonEvent {
    char pad0[0x20];
    u16 button;
};

struct mScrollArrow {
    char pad0[0xB0];
    void *window;
    s32 unkB4;
    s32 unkB8;
};

extern "C" s32 mWidget__onButtonPress(mScrollArrow *self, s32 ctx, mButtonEvent *ev);
extern "C" void mWidget__setActive(mScrollArrow *self, s32 active);
extern "C" s32 mScrollWindow__onHDecButtonPress(void *window, s32 ctx, mButtonEvent *ev);
extern "C" s32 mScrollWindow__onVDecButtonPress(void *window, s32 ctx, mButtonEvent *ev);
extern "C" s32 mScrollWindow__onVIncButtonPress(void *window, s32 ctx, mButtonEvent *ev);
extern "C" s32 mScrollWindow__onHIncButtonPress(void *window, s32 ctx, mButtonEvent *ev);

extern "C" s32 mScrollArrow__onButtonPress(mScrollArrow *self, s32 ctx, mButtonEvent *ev) {
    s32 r = mWidget__onButtonPress(self, ctx, ev);
    if (ev->button != 1)
        return r;
    mWidget__setActive(self, 1);
    if (self->window) {
        if (self->unkB4) {
            if (self->unkB8)
                return mScrollWindow__onHDecButtonPress(self->window, ctx, ev);
            else
                return mScrollWindow__onVDecButtonPress(self->window, ctx, ev);
        } else {
            if (self->unkB8)
                return mScrollWindow__onVIncButtonPress(self->window, ctx, ev);
            else
                return mScrollWindow__onHIncButtonPress(self->window, ctx, ev);
        }
    }
    return 0;
}
