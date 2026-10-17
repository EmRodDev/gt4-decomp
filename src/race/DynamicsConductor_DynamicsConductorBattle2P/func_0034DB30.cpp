/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Course {
    char pad0[0xCC8];
    int xCC8;
};

struct Race {
    char pad0[0x84];
    Course *course;
};

struct CarState {
    char pad0[0x32];
    u8 type;
};

struct Info {
    char pad0[0x440];
    u8 player;
    u8 enabled;
    char pad442[0x450 - 0x442];
    f32 wait;
    char pad454[0x466 - 0x454];
    s8 state;
    char pad467[0x4A4 - 0x467];
    f32 x4A4;
    char pad4A8[0x4AF - 0x4A8];
    s8 rank;
    char pad4B0[0x4BC - 0x4B0];
    s8 active;
    char pad4BD[0x630 - 0x4BD];
    u8 flags;
    u8 timer;
};

struct Entrant {
    char pad0[0x10];
    CarState *state;
    char pad14[0x104 - 0x14];
    Info info;
};

struct Conductor {
    Race *race;
    char pad4[0xCBDC - 4];
    u8 mode;
    char padCBDD[0xCBF8 - 0xCBDD];
    f32 dt;
    int countdown[8];
    char padCC1C[0xCD7C - 0xCC1C];
    char grid[0xF8A0 - 0xCD7C];
    int count;
    int order[8];
    char padF8C4[0x10140 - 0xF8C4];
    char *vtbl;
};

extern "C" {
void func_00343ED0(Entrant *) throw();
void func_00344420(Entrant *) throw();
void func_00344458(Entrant *) throw();
void func_00344530(Entrant *) throw();
void func_00349FD0(Entrant *) throw();
void func_0034C0E0(Conductor *) throw();
Entrant *func_0034C190(Conductor *, int) throw();
int func_0034C210(Conductor *) throw();
void DynamicsConductor__processCollision_Solitaire(Conductor *, int) throw();
void func_00350308(Entrant *);
void func_00351778(Entrant *);
void func_00352EA0(Entrant *);
void func_00353218(Entrant *);
void func_003535B0(Entrant *);
void func_00354A78(Entrant *);
void func_00355868(Entrant *);
void func_00355E10(Entrant *);
void func_00357700(Entrant *);
void func_00359008(Conductor *, int);
void func_0035A678(Entrant *);
void func_0035BE60(Entrant *);
void func_0035CA60(Entrant *);
void func_0035D1D0(Entrant *);
void func_0035DF80(Race *, int, int, int);
void func_0035F658(Conductor *);
int DynamicsConductor__GetStandings(Conductor *, int);
void func_00365E80(Conductor *);
void func_00366588(Conductor *);
void func_00369888(Entrant *);
int func_003C0E78(Race *);
void func_003F1148(Conductor *);
void func_003F12B0(Conductor *);
void func_003F1368(Conductor *);
void func_003F28B8(Entrant *);
void func_003F3368(Entrant *);
void func_003F38D8(Entrant *);
void func_003F4638(Conductor *);
void func_003F71C8(Entrant *);
void func_003F79A0(Entrant *);
void func_003F7EA8(Entrant *);
void func_004146E8(char *);
}

static inline VEntry *ventry(Conductor *self, int off) {
    return (VEntry *)(self->vtbl + off);
}

static inline void vcall(Conductor *self, int off) {
    VEntry *e = ventry(self, off);
    ((void (*)(char *))e->fn)((char *)self + e->delta);
}

static inline f32 pair(Conductor *self, Info *a, Info *b, f32 f) {
    VEntry *e = ventry(self, 0x20);
    return ((f32 (*)(char *, Info *, Info *, f32))e->fn)((char *)self + e->delta, a, b, f);
}

extern "C" void func_0034DB30(Conductor *self, int solitary) {
    int i;
    int n;
    int tick;
    int steps = 1;

    if (func_003C0E78(self->race))
        func_003F1148(self);
    {
        int mode = self->mode;
        bool all = mode == 2;
        for (i = 0; i < self->count; i++) {
            if (all || func_0034C190(self, i)->info.enabled)
                func_0035BE60(func_0034C190(self, i));
        }
    }

    for (tick = 0; tick < steps; tick++) {
        int changed = 0;
        if (self->mode) {
            for (i = 0; i < self->count; i++) {
                f32 t = func_0034C190(self, i)->info.wait;
                f32 dt = self->dt;
                t -= dt;
                if (t < -dt * 0.5f) {
                    t = 1.0f - dt;
                    changed = 1;
                }
                func_0034C190(self, i)->info.wait = t;
            }
            if (!changed)
                goto next;
        }
        n = self->count;
        {
            int total = n;
            int first = solitary != 0;
            bool counting;

            for (i = first; i < n; i++)
                func_00343ED0(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00355E10(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_0035CA60(func_0034C190(self, i));
            counting = func_0034C210(self) != 0;
            for (i = first; i < n; i++) {
                Info *info = &func_0034C190(self, i)->info;
                if (counting) {
                    info->active = 1;
                } else if (self->countdown[i] != 0) {
                    if (--self->countdown[i] == 0)
                        func_0035DF80(self->race, 4, info->player, 0);
                    else
                        info->active = 1;
                } else {
                    info->active = 0;
                }
            }
            for (i = first; i < n; i++)
                func_00357700(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00349FD0(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_0035D1D0(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_003F7EA8(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00351778(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_003F79A0(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_003535B0(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_003F38D8(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00350308(func_0034C190(self, i));
            if (func_003C0E78(self->race))
                func_003F12B0(self);
            if (func_003C0E78(self->race))
                func_003F1368(self);
            for (i = first; i < n; i++) {
                Info *info = &func_0034C190(self, i)->info;
                if (info->timer != 0) {
                    if (--info->timer == 0)
                        info->flags ^= 2;
                }
            }
            if (!solitary)
                vcall(self, 0x68);
            else
                DynamicsConductor__processCollision_Solitaire(self, 1);
            if (!solitary)
                func_003F4638(self);
            for (i = first; i < n; i++)
                func_003F28B8(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00344420(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00344458(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00369888(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00344530(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00352EA0(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_00353218(func_0034C190(self, i));
            for (i = first; i < n; i++)
                func_0035A678(func_0034C190(self, i));
            if (!solitary) {
                func_00366588(self);
                vcall(self, 0x70);
            }
            for (i = first; i < n; i++) {
                Entrant *car = func_0034C190(self, i);
                VEntry *e = ventry(self, 0x108);
                f32 r = ((f32 (*)(char *, Entrant *))e->fn)((char *)self + e->delta, car);
                func_0034C190(self, i)->info.x4A4 = r;
            }
            if (!solitary) {
                for (i = first; i < n; i++)
                    func_00359008(self, DynamicsConductor__GetStandings(self, i));
            } else {
                func_00359008(self, first);
            }
            if (!solitary) {
                VEntry *e;
                vcall(self, 0x8);
                vcall(self, 0x78);
                func_00365E80(self);
                vcall(self, 0x18);
                e = ventry(self, 0xC0);
                ((void (*)(char *, int, int))e->fn)((char *)self + e->delta, first, n);
            }
            {
                int last = -1;
                int leader = -1;
                for (i = 0; i < self->count; i++) {
                    int idx = self->order[i];
                    if (func_0034C190(self, idx)->info.state != 2) {
                        if (leader == -1)
                            leader = idx;
                        last = idx;
                    }
                }
                if (last == -1)
                    leader = last = 0;
                VEntry *e = ventry(self, 0x140);
                switch (((int (*)(char *))e->fn)((char *)self + e->delta)) {
                case 1:
                    for (i = 0; i < self->count; i++) {
                        if (i != leader)
                            pair(self, &func_0034C190(self, leader)->info, &func_0034C190(self, i)->info, 1.0f);
                    }
                    break;
                case 2: {
                    int rank = func_0034C190(self, leader)->info.rank;
                    for (i = 0; i < rank - 1; i++)
                        pair(self, &func_0034C190(self, self->order[i + 1])->info,
                             &func_0034C190(self, self->order[i])->info, 1.0f);
                    for (i = rank; i < self->count; i++)
                        pair(self, &func_0034C190(self, self->order[i - 1])->info,
                             &func_0034C190(self, self->order[i])->info, 1.0f);
                    break;
                }
                case 0: {
                    int base = func_0034C190(self, leader)->info.rank - 1;
                    f32 f = 1.0f;
                    for (i = base; i > 0; i--)
                        f = pair(self, &func_0034C190(self, self->order[i])->info,
                                 &func_0034C190(self, self->order[i - 1])->info, f);
                    f = 1.0f;
                    for (i = base; i < self->count - 1; i++)
                        f = pair(self, &func_0034C190(self, self->order[i])->info,
                                 &func_0034C190(self, self->order[i + 1])->info, f);
                    break;
                }
                }
            }
            for (i = first; i < total; i++)
                func_00354A78(func_0034C190(self, i));
            for (i = first; i < total; i++)
                func_003F3368(func_0034C190(self, i));
            if (self->race->course->xCC8 == 0 && steps == 1)
                func_0035F658(self);
            for (i = first; i < total; i++)
                func_003F71C8(func_0034C190(self, i));
            for (i = first; i < total; i++) {
                Entrant *car = func_0034C190(self, i);
                if (car->state->type == 3)
                    func_00355868(car);
            }
        }
    next:
        func_0034C0E0(self);
        func_004146E8(self->grid);
    }
}
