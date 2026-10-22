/* Virtual slot 23 of the race display: reacts to a message only outside play mode (RaceDisplay__is_play_mode
 * returns 0) and only when the message value at +8 differs from the value at display+0x50. It first calls
 * func_003A3AA8 on the widget at display+0x1170 with 11.0, then, when the float at display+0xBC is at least 1.0
 * and func_003A4A78 returns zero for both the widgets at display+0x23DC and display+0x291C (a busy test,
 * inferred), it stores the new value at display+0x50, copies the value and the message field at +0xC into the
 * panel at display+0x3EEC (+0x18 and +0x1C) and starts it with func_003AE538 using 10.0 and 0.5. What the value
 * stands for is unknown. */
#include "types.h"

struct Obj {
    char pad0[0x50];
    s32 unk50;
    char pad54[0xBC - 0x54];
    f32 unkBC;
};

struct Src {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

struct Sub {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

extern "C" s32 RaceDisplay__is_play_mode(Obj *display);
extern "C" void func_003A3AA8(s32 display, f32 fparg0);
extern "C" s32 func_003A4A78(void *display);
extern "C" void func_003AE538(char *display, f32 fparg0, f32 fparg1);

extern "C" void RaceDisplay__virtual_23(Obj *display, Src *message) {
    s32 newValue;
    Sub *panel;
    s32 secondActive;

    if (RaceDisplay__is_play_mode(display) == 0) {
        newValue = message->unk8;
        if (newValue != display->unk50) {
            func_003A3AA8((s32)((char *)display + 0x1170), 0x1.6p3f);
            if (!(display->unkBC < 0x1.0p0f) && (func_003A4A78((char *)display + 0x23DC) == 0)) {
                secondActive = func_003A4A78((char *)display + 0x291C);
                panel = (Sub *)((char *)display + 0x3EEC);
                if (secondActive == 0) {
                    display->unk50 = newValue;
                    panel->unk18 = newValue;
                    panel->unk1C = message->unkC;
                    func_003AE538((char *)panel, 0x1.4p3f, 0x1.0p-1f);
                }
            }
        }
    }
}
