/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub_B4B8 {
    char pad0[4];
    void *p4;
};

struct Mid_B4B8 {
    char pad0[0x80];
    Sub_B4B8 *p80;
};

struct RaceBasicLayout {
    char pad0[0x64];
    VEntry *vt;
    char pad1[4];
    Mid_B4B8 *f6C;
    char pad2[0xD30 - 0x70];
    s32 fD30;
    char pad3[0xE418 - 0xD34];
    void *unkE418;
};

extern "C" void RaceBasic__setPause(void *arg0, s32 arg1);
extern "C" void CourseData__setPause(void *self, s32 on);

extern "C" void RaceBasic__pauseEnd(RaceBasicLayout *self) {
    self->fD30 = 0;
    RaceBasic__setPause(self, 0);
    VEntry *e = &self->vt[89];
    e->fn((char *)self + e->delta);
    CourseData__setPause(self->f6C->p80->p4, 0);
    self->unkE418 = 0;
}
