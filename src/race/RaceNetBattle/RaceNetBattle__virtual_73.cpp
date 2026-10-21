/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-frame play update of a network battle (virtual 73): runs RaceBasic::updatePlay, then drives the RaceDisplay block at +0x1ED1C from
 * object number 0 returned by the virtual at vtable +0xD0 (display state taken from that object: the short at +0x1C of its 0x19C-byte entry
 * number idx, its virtual +0x120 as view mode, 00373DA0 as dive-replay mode and its virtual +0x1B0 as replay enable), updates the
 * display with the time step, notifies the optional callback object at +0xE41C through its virtual +0x20 with the race display and the result of
 * the virtual at +0x230, and finishes with 0039DA80. The meaning of those display values is taken from the callee names only. */
struct Ent { char pad[0x1C]; short callbackArg; char pad2[0x19C - 0x1E]; };
struct Race {
    struct VE0 *vtbl;
    char pad[0x9BC - 4];
    int idx;
};
struct VE0 { char pad[0]; };
struct VEi { short delta, index; int (*fn)(void *); };
struct VEp { short delta, index; Race *(*fn)(void *, int); };
struct VEc { short delta, index; void (*fn)(void *, void *, int); };
struct Cb { char pad[0xC]; char *vt; };
struct Obj {
    char pad0[0x64]; char *vtbl;
    char pad1[4]; void *f6C;
};
extern "C" int func_00373DA0(void *, int);
extern "C" void RaceBasic__updatePlay(Obj *, float);
extern "C" void RaceDisplay__virtual_10(void *, int);
extern "C" void RaceDisplay__setViewMode(void *, int);
extern "C" void RaceDisplay__setDiveReplayMode(void *, int);
extern "C" void RaceDisplay__commonPreUpdate(void *);
extern "C" void func_0039DA80(void *);
extern "C" void RaceDisplay__update(void *, float);
extern "C" void RaceDisplay__setDisplayEnableInReplay(void *, int);

extern "C" void RaceNetBattle__virtual_73(Obj *self, float timeStep) {
    char *display = (char *)self + 0x1ED1C;
    RaceBasic__updatePlay(self, timeStep);
    RaceDisplay__commonPreUpdate(self->f6C);
    VEp *objectEntry = (VEp *)(self->vtbl + 0xD0);
    Race *object0 = objectEntry->fn((char *)self + objectEntry->delta, 0);
    RaceDisplay__virtual_10(display, ((Ent *)object0)[object0->idx].callbackArg);
    VEi *viewModeEntry = (VEi *)((char *)object0->vtbl + 0x120);
    RaceDisplay__setViewMode(display, viewModeEntry->fn((char *)object0 + viewModeEntry->delta));
    RaceDisplay__setDiveReplayMode(display, func_00373DA0(object0, 0));
    VEi *replayEnableEntry = (VEi *)((char *)object0->vtbl + 0x1B0);
    RaceDisplay__setDisplayEnableInReplay(display, replayEnableEntry->fn((char *)object0 + replayEnableEntry->delta));
    RaceDisplay__update(display, timeStep);
    if (*(Cb **)((char *)self + 0xE41C)) {
        VEi *callbackArgEntry = (VEi *)(self->vtbl + 0x230);
        void *raceDisplay = self->f6C;
        int callbackArg = callbackArgEntry->fn((char *)self + callbackArgEntry->delta);
        Cb *callback = *(Cb **)((char *)self + 0xE41C);
        VEc *callbackEntry = (VEc *)(callback->vt + 0x20);
        callbackEntry->fn((char *)callback + callbackEntry->delta, raceDisplay, callbackArg);
    }
    func_0039DA80(self->f6C);
}
