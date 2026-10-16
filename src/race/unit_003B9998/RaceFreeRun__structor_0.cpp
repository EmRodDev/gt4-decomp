/* compiler: ee-gcc2.96-no-strict-aliasing */
struct InputMode {
    int pad0;
    int mode;
};

struct RaceFreeRun {
    char pad0[0x64];
    char *vt;
    char pad68[0x70 - 0x68];
    void *m70;
    char pad74[0xD68 - 0x74];
    int unkD68;
    char padD6C[0xE350 - 0xD6C];
    char mE350[0xE408 - 0xE350];
    void *mE408;
    char padE40C[4];
    void *mE410;
    char padE414[0xE740 - 0xE414];
    InputMode input1;
    char padE748[0xE920 - 0xE748];
    InputMode input2;
    char padE928[0xEB00 - 0xE928];
    InputMode input3;
    char padEB08[0xF140 - 0xEB08];
    char mF140[0x1F2A0 - 0xF140];
    char m1F2A0[0x1F2D0 - 0x1F2A0];
    char m1F2D0[0x1F308 - 0x1F2D0];
    char m1F308[0x23238 - 0x1F308];
    char m23238[0x24578 - 0x23238];
    char m24578[0x24680 - 0x24578];
    char m24680[0x24698 - 0x24680];
    int unk24698;
    int unk2469C;
    int unk246A0;
    int unk246A4;
};

inline void *operator new(unsigned int, void *p) { return p; }

struct Dynamics {
    char x[0x1F2A0 - 0xF140];
    Dynamics() __asm__("func_003F54E0");
};

struct Elem {
    char x[8];
    Elem() __asm__("func_00393700");
};

struct Region {
    Dynamics dynamics;
    Elem elems[6];
};

extern char RaceFreeRun__vtable[];

extern "C" {
int func_0033CF48(void);
void func_0038BB50(RaceFreeRun *self, void *p);
void RaceDisplay__structor_0(void *p);
void func_003BAB90(void *p);
void RacePause__structor_0(void *p);
void func_003C31C8(void *p, void *q);
void func_003D7700(void *p);
void func_003D8490(void *p, void *q);
void func_003DCA28(void *p);
void func_003DD4B8(void *p, void *q);
RaceFreeRun *RaceSolitaire__structor_0(RaceFreeRun *self);
}

extern "C" void RaceFreeRun__structor_0(RaceFreeRun *self)
{
    RaceSolitaire__structor_0(self);
    self->vt = RaceFreeRun__vtable;
    new (self->mF140) Region;
    RacePause__structor_0(self->m1F2D0);
    RaceDisplay__structor_0(self->m1F308);
    func_003D7700(self->m23238);
    func_003DCA28(self->m24578);
    func_003BAB90(self->m24680);

    self->mE408 = self->m24578;
    self->mE410 = self->m24680;
    func_0038BB50(self, self->m1F308);
    self->m70 = self->mF140;
    if (func_0033CF48() == 0) {
        func_003C31C8(self->m1F2D0, self->mE350);
        func_003D8490(self->m23238, self->mE350);
        func_003DD4B8(self->m24578, self->mE350);
    }
    self->input1.mode = 2;
    self->input2.mode = 2;
    self->input3.mode = 2;
    self->unk24698 = 0;
    self->unk246A4 = 0;
    self->unk246A0 = 0;
    self->unk2469C = 0;
    self->unkD68 = 0xB;
}
