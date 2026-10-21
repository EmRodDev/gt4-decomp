/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initialises an arcade race. Five setup helpers (0038B7C0, 0038B8D8, 0038BAB0, 0038B990, 0038BA90) are first called with null/zero
 * arguments, RaceSinglePlayer::initialize runs, and then the race type at +0xCC8 decides: types 2 and 3 repeat the null calls; the others
 * give the helpers their real blocks (+0x22C38, +0x22738, +0x22708, +0x22C70, the pointer at +0xE408 and the value at +0xE410), after
 * storing 1 in the first block's field +0x34 for type 1. Finally RaceDisplay::virtual_06 is called on the display at +0xE440 with 1 and
 * the display is pointed at the block at +0x22708. What each block is is purpose unknown. */
typedef int s32;
typedef unsigned int u32;

struct Pause {
    char pad0[0x34];
    s32 f34;
};

struct Disp {
    char pad0[8];
    char *f8;
};

struct Win {
    char pad0[0x14];
    char *f14;
};

struct Obj {
    char pad0[0xCC8];
    s32 type;
    char pad1[0xE408 - 0xCCC];
    char *eE408;
    char pad2[0xE410 - 0xE40C];
    s32 vE410;
    char pad3[0xE424 - 0xE414];
    Win *eE424;
};

extern "C" void func_0038B7C0(Obj *, void *);
extern "C" void func_0038B8D8(Obj *, void *);
extern "C" void func_0038B990(Obj *, void *);
extern "C" void func_0038BA90(Obj *, s32);
extern "C" void func_0038BAB0(Obj *, void *);
extern "C" void RaceDisplay__virtual_06(void *, s32);
extern "C" void RaceSinglePlayer__initialize(Obj *, s32);
extern "C" void func_003DF970(void *, void *);

extern "C" void RaceArcade__initialize(Obj *self, s32 initArg) {
    func_0038B7C0(self, 0);
    func_0038B8D8(self, 0);
    func_0038BAB0(self, 0);
    func_0038B990(self, 0);
    func_0038BA90(self, 0);
    Disp *display = (Disp *)((char *)self + 0xE440);
    RaceSinglePlayer__initialize(self, initArg);
    {
        s32 raceType = self->type;
        Pause *pauseBlock = (Pause *)((char *)self + 0x22C38);
        s32 flagValue = 0;
        if ((u32)(raceType - 2) < 2) {
            func_0038B7C0(self, 0);
            func_0038B8D8(self, 0);
            func_0038BAB0(self, 0);
            func_0038B990(self, 0);
            func_0038BA90(self, 0);
        } else {
            if (raceType == 1 || raceType == 3) flagValue = 1;
            pauseBlock->f34 = flagValue;
            func_0038B7C0(self, (char *)self + 0x22C38);
            func_0038B8D8(self, (char *)self + 0x22738);
            func_003DF970((char *)self + 0x22738, (char *)self + 0x22708);
            func_0038B990(self, self->eE408);
            func_0038BAB0(self, (char *)self + 0x22C70);
            self->eE424->f14 = (char *)self + 0x22708;
            func_0038BA90(self, self->vE410);
        }
    }
    RaceDisplay__virtual_06(display, 1);
    display->f8 = (char *)self + 0x22708;
}
