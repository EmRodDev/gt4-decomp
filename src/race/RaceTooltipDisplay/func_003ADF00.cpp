/* Resets a RaceTooltipDisplay: zeroes the floats at +0x18/+0x1C, resets the AutomaticFader at +0x20, and sets up its two text parts the same way:
 * the RaceMessageDisplay at +0x3C (cleared, shown with 0/0, low byte of its first word set to 1, font D_006A1860, alignment 2/1), then the event
 * display at +0x18C (cleared, 003A5268 given the same font, alignment 2/1). `cursor` starts as the object and is moved to +0x18C. What the
 * alignment values 2 and 1 mean is taken from RaceDisplayObjectBase::setAlignment and is purpose unknown. */
#include "types.h"

extern char D_006A1860[];

extern "C" void RaceMessageDisplay__setFont(void *cursor, s32 arg1, s32 arg2);
extern "C" void RaceMessageDisplay__clear(void *self);
extern "C" void RaceMessageDisplay__show(void *cursor, f32 fparg0, f32 fparg1);
extern "C" void RaceEventDisplay__clear(void *cursor, f32 fparg0);
extern "C" void func_003A5268(void *cursor, s32 arg1, s32 arg2);
extern "C" void AutomaticFader__reset(void *cursor);
extern "C" void RaceDisplayObjectBase__setAlignment(void *cursor, s8 arg1, s8 arg2);

extern "C" void func_003ADF00(char *cursor) {
    f32 zero = 0.0f;
    char *messageDisplay = cursor + 0x3C;
    s32 fontName = (s32)D_006A1860;

    *(f32 *)(cursor + 0x18) = zero;
    *(f32 *)(cursor + 0x1C) = zero;
    AutomaticFader__reset(cursor + 0x20);
    cursor += 0x18C;
    RaceMessageDisplay__clear(messageDisplay);
    RaceMessageDisplay__show(messageDisplay, zero, zero);
    *(s32 *)messageDisplay = (*(s32 *)messageDisplay & -0x100) | 1;
    RaceMessageDisplay__setFont(messageDisplay, fontName, 0);
    RaceDisplayObjectBase__setAlignment(messageDisplay, 2, 1);
    RaceEventDisplay__clear(cursor, zero);
    func_003A5268(cursor, fontName, 0);
    RaceDisplayObjectBase__setAlignment(cursor, 2, 1);
}
