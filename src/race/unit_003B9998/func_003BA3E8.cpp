/* compiler: ee-gcc2.96-no-strict-aliasing */
/* One-shot handler in the free-run race unit (inferred from the neighbouring RaceFreeRun methods). Unless it already ran (+0x24694), the
 * state at +0xCC8 is below 2 and the car's explicit current lap is at least 2, it sets +0x24694 to 1, runs 003B76F0 and 00343D78 (with 4),
 * finishes the control-record Recorder of the RaceSolitaire input (+0xDC) and calls 00426C78 on that input. Either way it ends with the virtual
 * method at vtable +0x2B8 called with (2, 0.0, 0.0). The first-lap-complete reading is a guess from the lap test; what the calls
 * stop or save is purpose unknown. */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Ent { char pad[0x18]; void *f18; };
struct Info { u32 n; s32 pad; Ent **tbl; };
struct Mid { char pad[0x60]; Info *info; };
struct Obj {
    char pad0[0x64]; char *vt; char pad68[4]; Mid *mid;
    char padCC8[0xCC8 - 0x70]; u32 cc8;
    char pad2[0x24694 - 0xCCC]; s32 f24694;
};
extern "C" {
int Automobile__GetExplicitCurrentLap(void *);
void func_00343D78(void *, s32);
void AutomobileControlRecord__Recorder__finish(void *);
void func_003B76F0(void *, int, int, int);
char *RaceSolitaire__getInput(void *);
void func_00426C78(void *);
void func_003BA3E8(Obj *self) {
    Mid *middle = self->mid;
    void *car = middle->info->tbl[0]->f18;
    if (self->f24694 != 0 || self->cc8 >= 2 || Automobile__GetExplicitCurrentLap(car) < 2) {
        VE *slotEntry = (VE *)(self->vt + 0x2B8);
        ((void (*)(void *, s32, float, float))slotEntry->fn)((char *)self + slotEntry->delta, 2, 0.0f, 0.0f);
        return;
    }
    self->f24694 = 1;
    func_003B76F0((char *)middle + 0xF4, 5, 0, 2);
    func_00343D78(car, 4);
    AutomobileControlRecord__Recorder__finish(RaceSolitaire__getInput(self) + 0xDC);
    func_00426C78(RaceSolitaire__getInput(self));
    VE *slotEntry = (VE *)(self->vt + 0x2B8);
    ((void (*)(void *, s32, float, float))slotEntry->fn)((char *)self + slotEntry->delta, 2, 0.0f, 0.0f);
}
}
