/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Two-phase update of an on-screen job, run once per frame while game->f1E634 is set (otherwise it only calls func_00109BA8): phase 1 (self+0x218 == 0) sets the display up (func_00106A68, both buffers of D_006184D0 are cleared and flipped), copies the viewport values of the game config into the sub-object (aspect ratio inverted when below 1.0) and starts it (func_00333560); phase 2 keeps calling func_00333A00 with a frame counter at +0x21C until it returns 0, then restores the display, clears f1E634 and shuts the sub-object (func_003355F0). What the job renders is not determined. */
typedef int s32;
typedef float f32;

struct Item { char pad[0x30]; s32 f30; char pad34[0x3C - 0x34]; };
struct Tbl {
    Item items[2];
    s32 cur;
};
struct Disp {
    char hdr[0x3C];
    Tbl t;
};
struct Cfg { s32 f0; s32 f4; s32 f8; s32 fC; f32 f10; s32 f14; };
struct Game {
    char pad[0x1E634];
    volatile s32 f1E634;
    Cfg cfg;
    void *f1E650;
    char pad1E654[0x1E668 - 0x1E654];
    s32 f1E668;
    f32 f1E66C;
    f32 f1E670;
    f32 f1E674;
    f32 f1E678;
    f32 f1E67C;
};
struct Sub {
    char pad[0x118];
    s32 f118;
    char pad11C[8];
    s32 f124;
    s32 f128;
    f32 f12C;
    f32 f130;
    f32 f134;
    f32 f138;
    f32 f13C;
};
struct Self {
    char pad[0xA8];
    Game *game;
    Sub sub;
    char pad140[0x218 - 0xAC - sizeof(Sub)];
    s32 f218;
    s32 f21C;
};

extern Disp D_006184D0;
extern "C" void func_001056A0(void *);
extern "C" void func_00106A68(void *, s32, s32, s32);
extern "C" void func_001074D0(void *, s32, s32, s32, s32);
extern "C" void func_00109BA8(void);
extern "C" s32 func_00333560(void *, void *, s32, s32, s32, s32, f32, s32);
extern "C" s32 func_00333A00(void *, s32);
extern "C" void func_003355F0(void *);
extern "C" void func_003C7D60(void *, s32);
extern "C" void func_004A2980(s32);
extern "C" void func_004A3078(s32);
extern "C" void func_004A3230(s32);

extern "C" void func_001C89F0(Self *job) {
    if (job->game->f1E634 != 0) {
        if (job->f218 == 0) {
            func_00106A68(&D_006184D0, 2, 0x100, 0x180);
            func_004A3078(0);
            func_004A2980(-1);
            Tbl *displayTable = &D_006184D0.t;
            func_001056A0(&displayTable->items[displayTable->cur]);
            func_004A3230(1);
            func_001056A0(&displayTable->items[1 - displayTable->cur]);
            func_004A3230(1);
            job->f218 = 1;
            Game *game = job->game;
            Cfg *config = &game->cfg;
            f32 aspect = config->f10;
            s32 aspectBelowOne = 1;
            if (!(aspect < 1.0f)) aspectBelowOne = 0;
            Sub *subObject = &job->sub;
            s32 cfg0 = config->f0, cfg4 = config->f4, cfg8 = config->f8, cfgC = config->fC;
            f32 scale;
            if (aspectBelowOne) scale = 1.0f / aspect;
            else scale = aspect;
            func_00333560(subObject, game, cfg0, cfg4, cfg8, cfgC, scale, aspectBelowOne);
            s32 cfg14 = config->f14;
            subObject->f124 = 0;
            subObject->f118 = cfg14;
            subObject->f128 = job->game->f1E668;
            subObject->f134 = job->game->f1E674;
            subObject->f130 = job->game->f1E670;
            subObject->f138 = job->game->f1E678;
            subObject->f13C = job->game->f1E67C;
            subObject->f12C = job->game->f1E66C;
            func_003C7D60(job->game, 1);
            job->f21C = 0;
        
        } else {
            Sub *subObject = &job->sub;
            if (func_00333A00(subObject, job->f21C++) != 0) return;
            {
                func_001074D0(&D_006184D0, 1, 2, 0x280, 0x1C0);
                Tbl *displayTable = &D_006184D0.t;
                displayTable->items[displayTable->cur].f30 = 0;
                displayTable->items[1 - displayTable->cur].f30 = 0;
                job->game->f1E650 = (char *)job + 0xC8;
                Game *game = job->game;
                game->f1E634 = 0;
                (void)game->f1E634;
                func_003C7D60(job->game, 0);
                func_003355F0(subObject);
                job->f218 = 0;
            }
        }
    } else {
        func_00109BA8();
    }
}
