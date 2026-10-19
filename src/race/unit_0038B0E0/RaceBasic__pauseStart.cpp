/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub_428 {
    char pad0[4];
    void *p4;
};

struct Mid_428 {
    char pad0[0x80];
    Sub_428 *p80;
    char pad1[0xD0 - 0x84];
    s32 fD0;
};

struct RaceBasicLayout {
    char pad0[0x64];
    VEntry *vt;
    char pad1[4];
    Mid_428 *f6C;
    char pad2[0xE400 - 0x70];
    void *unkE400;
    char pad3[0xE418 - 0xE404];
    void *unkE418;
};

extern "C" void RaceBasic__setPause(void *arg0, s32 arg1);
extern "C" void CourseData__setPause(void *self, s32 on);
extern "C" void PauseBase__setTimeLimit(void *arg0, s32 arg1);

extern "C" void RaceBasic__pauseStart(RaceBasicLayout *self, void *arg1) {
    void *v = arg1;
    if (v == 0) {
        v = self->unkE400;
    }
    self->unkE418 = v;
    if (v != 0) {
        PauseBase__setTimeLimit(v, self->f6C->fD0);
        RaceBasic__setPause(self, 1);
        VEntry *e = &self->vt[90];
        e->fn((char *)self + e->delta);
        CourseData__setPause(self->f6C->p80->p4, 1);
    }
}
