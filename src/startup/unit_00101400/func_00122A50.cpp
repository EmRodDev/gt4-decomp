/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Draws one text line through the global font manager (PDISTD__global_font_manager): sets its scale fields (+0x24 / +0x28) to 2.0,
 * positions at x = 64 and y = self+0x2F4 minus (yOffset + 12.5), uses the four floats of table D_00618770[slot] with 0.4 as
 * colour (inferred) and prints the format D_0068DDC8 with the character D_0068DDD0[slot]. */
typedef int s32;
typedef float f32;
struct Mgr { char pad[0x24]; f32 f24; f32 f28; };
struct Ent { f32 x; f32 y; f32 z; f32 w; };
struct Self { char pad[0x2F4]; f32 f2F4; };
extern s32 PDISTD__global_font_manager;
extern Ent D_00618770[];
extern char D_0068DDC0[];
extern char D_0068DDC8[];
extern char D_0068DDD0[];
extern "C" void func_00490290(void *, void *);
extern "C" void func_00490518(void *, f32, f32, f32, f32);
extern "C" void func_00490890(void *, f32, f32);
extern "C" void func_00490950(void *, const char *, ...);

extern "C" void func_00122A50(Self *self, s32 slot, f32 yOffset) {
    yOffset += 12.5f;
    Ent *colour = &D_00618770[slot];
    f32 y = self->f2F4;
    y -= yOffset;
    func_00490290((void *)PDISTD__global_font_manager, D_0068DDC0);
    Mgr *font = (Mgr *)PDISTD__global_font_manager;
    font->f28 = 2.0f;
    font->f24 = 2.0f;
    func_00490890((void *)PDISTD__global_font_manager, 64.0f, y);
    func_00490518((void *)PDISTD__global_font_manager, colour->x, colour->y, colour->z, 0x1.999998p-2f);
    func_00490950((void *)PDISTD__global_font_manager, D_0068DDC8, D_0068DDD0[slot]);
}
