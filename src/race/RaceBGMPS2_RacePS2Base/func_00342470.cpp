/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Draws a frame record onto the screen with a fixed render state (inferred from the many state calls followed by a
 * single rectangle copy). The record has a width at +8 (the height comes from func_00105818, the same getter used
 * for the 0x3C-byte records of D_0061850C elsewhere) and a placement x, y, dx, dy at +0x10..+0x1C. func_00105728
 * prepares the record, a series of state setters follows (func_004A4550 with 3 and 2, func_004A1638 with 5 and 4,
 * func_004A26F0, func_004A2750 with 7, func_004A6F10 with 0xFF), and func_004A6788 receives eight floats: the
 * source rectangle 0, 0, width, height and the destination rectangle x, y, x + dx, y + dy (inferred from the
 * arithmetic). Afterwards func_004AB040(4) and the colour value is reset to 0xFFFFFF. The setters' meaning is
 * unknown. */
typedef int s32;

struct R { char pad0[8]; s32 w; char pad1[4]; s32 x; s32 y; s32 dx; s32 dy; };

extern "C" void func_00105728(void *);
extern "C" s32 func_00105818(void *);
extern "C" void func_004A1638(s32);
extern "C" void func_004A26F0(s32);
extern "C" void func_004A2750(s32, float);
extern "C" void func_004A2980(s32);
extern "C" void func_004A3230(s32);
extern "C" void func_004A4550(s32, s32);
extern "C" void func_004A6788(float, float, float, float, float, float, float, float);
extern "C" void func_004A6F10(s32, s32);
extern "C" void func_004AB040(s32);

extern "C" void func_00342470(R *frame) {
    func_004A3230(2);
    float zero = 0.0f;
    func_00105728(frame);
    func_004A4550(3, 0);
    func_004A4550(2, 0);
    func_004A1638(5);
    func_004A1638(4);
    func_004A26F0(1);
    func_004A2750(7, zero);
    func_004A2980(0);
    func_004A6F10(1, 0xFF);
    float w = (float)frame->w;
    func_004A6788(zero, zero, w, (float)func_00105818(frame), (float)frame->x, (float)frame->y, (float)(frame->x + frame->dx), (float)(frame->y + frame->dy));
    func_004AB040(4);
    func_004A26F0(3);
    func_004A2980(0xFFFFFF);
}
