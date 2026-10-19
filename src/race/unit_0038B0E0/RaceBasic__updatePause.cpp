/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VE { s16 delta; s16 idx; void *fn; };
struct PauseControl { char pad[8]; VE *vt; };
struct Sub { char pad[0x7C]; s32 f7C; };

struct RaceBasicLayout {
    char pad0[0x64];
    VE *vt;
    char pad68[4];
    void *u6C;
    char pad70[0xE418 - 0x70];
    PauseControl *unkE418;
    char padE41C[8];
    Sub *unkE424;
};

extern "C" void RaceBasic__handle_command_in_pause(void *);

extern "C" void RaceBasic__updatePause(RaceBasicLayout *self) {
    if (self->unkE418 != 0) {
        VE *e = &self->vt[71];
        s32 r = ((s32 (*)(void *))e->fn)((char *)self + e->delta);
        VE *e2 = &self->unkE418->vt[4];
        s32 k = ((s32 (*)(void *, s32, void *))e2->fn)((char *)self->unkE418 + e2->delta, r, self->u6C);
        switch (k) {
        case 2: {
            VE *e3 = &self->vt[87];
            ((void (*)(void *, s32, float, float))e3->fn)((char *)self + e3->delta, 3, 0.0f, 0.0f);
            break;
        }
        case 4: {
            VE *e3 = &self->vt[87];
            ((void (*)(void *, s32, float, float))e3->fn)((char *)self + e3->delta, 2, 0.0f, 0.0f);
            break;
        }
        case 3: {
            VE *e3 = &self->vt[151];
            ((void (*)(void *))e3->fn)((char *)self + e3->delta);
            break;
        }
        case 5: {
            VE *e3 = &self->vt[87];
            ((void (*)(void *, s32, float, float))e3->fn)((char *)self + e3->delta, 4, 0.0f, 0.0f);
            break;
        }
        }
        Sub *p = self->unkE424;
        if (p) {
            p->f7C = 1;
            VE *e3 = &self->vt[142];
            ((void (*)(void *, s32))e3->fn)((char *)self + e3->delta, 1);
        }
        RaceBasic__handle_command_in_pause(self);
    }
}
