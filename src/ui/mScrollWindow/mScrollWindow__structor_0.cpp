/* Constructor of mScrollWindow: runs the mComposite constructor, sets the vtable at +4 and its own members, then builds the two scroll bars it owns.
 * Members: +0xB4 gets 0.3 (the literal 0.299999989569f), +0xB0 gets 1, +0xB8, +0xBC and +0xC0 get 0 (the +0xBC and +0xC0 slots are the view and content widgets
 * that mScrollWindow virtual 92 reads later). func_002D1B38(bar, orientation, partner) constructs the bar at +0xC4 with orientation 1 and partner +0xFC, then the bar at +0xFC with
 * orientation 0 and partner +0xC4; the orientation is the field func_002D2068 tests as isHorizontal, so +0xC4 is the horizontal bar (inferred). */
#include "gt4/mScrollWindow.h"
typedef int s32;

extern void *mScrollWindow__vtable;
extern "C" void *mComposite__structor_0(void *);
extern "C" void *func_002D1B38(void *, s32, void *);

extern "C" void mScrollWindow__structor_0(void *self) {
    mComposite__structor_0(self);
    ((struct mScrollWindow *)self)->unk4 = &mScrollWindow__vtable;
    ((struct mScrollWindow *)self)->unkB4 = 0.299999989569f;
    ((struct mScrollWindow *)self)->unkB0 = (void *)(0x1);
    ((struct mScrollWindow *)self)->unkB8 = 0x0;
    ((struct mScrollWindow *)self)->unkBC = 0x0;
    ((struct mScrollWindow *)self)->unkC0 = 0x0;
    func_002D1B38((char *)self + 0xc4, 0x1, (char *)self + 0xfc);
    func_002D1B38((char *)self + 0xfc, 0x0, (char *)self + 0xc4); return;
}
