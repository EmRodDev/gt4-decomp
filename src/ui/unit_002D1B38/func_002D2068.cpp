/* Lays out the parts of a scrollbar-like widget inside its parent window (inferred from the parts being placed at both ends and a resized middle).
 * The parent size comes from mWidget__getWindowSize. If isHorizontal (+4) is non-zero the X axis is used, otherwise Y: three fields at +0xC/+0x10/+0x14 are set from
 * the inputs (fparg0 or fparg1, arg1[2] or arg1[3], -arg1[0] or -arg1[1]; their meaning is unknown), the start part goes to (0,0), the end part is placed at
 * parentSize - endLength along the axis, the middle part is resized by func_0025B538 to parentSize - 2*endLength with crossSize on the other axis,
 * and the inner part is placed at endLength. Each part is optional (null checked). Does nothing without a parent widget at +0x20. */
#include "types.h"

struct C {
    char pad0[4];
    s32 isHorizontal;
    char pad8[4];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 crossSize;
    f32 endLength;
    void *parentWidget;
    void *startPart;
    void *endPart;
    void *middlePart;
    void *innerPart;
};

extern "C" void mWidget__setWindowPosition(void *c, f32 x, f32 y);
extern "C" void mWidget__getWindowSize(void *arg0, f32 *arg1, f32 *arg2);
extern "C" void func_0025B538(void *c, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void func_002D2068(C *self, f32 *arg1, f32 fparg0, f32 fparg1) {
    f32 parentSize[2];

    if (self->parentWidget != 0) {
        mWidget__getWindowSize(self->parentWidget, parentSize, parentSize + 1);
        if (self->isHorizontal != 0) {
            void *startPtr = self->startPart;
            self->unkC = fparg0;
            self->unk10 = arg1[2];
            self->unk14 = -arg1[0];
            if (startPtr != 0) {
                mWidget__setWindowPosition(startPtr, 0.0f, 0.0f);
            }
            void *endPtr = self->endPart;
            if (endPtr != 0) {
                mWidget__setWindowPosition(endPtr, parentSize[0] - self->endLength, 0.0f);
            }
            void *middlePtr = self->middlePart;
            if (middlePtr != 0) {
                func_0025B538(middlePtr, self->endLength, 0.0f, parentSize[0] - (self->endLength + self->endLength), self->crossSize);
            }
            void *innerPtr = self->innerPart;
            if (innerPtr != 0) {
                mWidget__setWindowPosition(innerPtr, self->endLength, 0.0f);
            }
        } else {
            void *startPtr = self->startPart;
            self->unkC = fparg1;
            self->unk10 = arg1[3];
            self->unk14 = -arg1[1];
            if (startPtr != 0) {
                mWidget__setWindowPosition(startPtr, 0.0f, 0.0f);
            }
            void *endPtr = self->endPart;
            if (endPtr != 0) {
                mWidget__setWindowPosition(endPtr, 0.0f, parentSize[1] - self->endLength);
            }
            void *middlePtr = self->middlePart;
            if (middlePtr != 0) {
                func_0025B538(middlePtr, 0.0f, self->endLength, self->crossSize, parentSize[1] - (self->endLength + self->endLength));
            }
            void *innerPtr = self->innerPart;
            if (innerPtr != 0) {
                mWidget__setWindowPosition(innerPtr, 0.0f, self->endLength);
            }
        }
    }
}
