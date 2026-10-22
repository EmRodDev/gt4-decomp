/* Maps a rectangle given in some source space to 640x480 coordinates and passes it to the font manager call
 * func_00490700 (the four ints after the manager look like x, y, width, height, inferred from how they are built).
 * The corner (x0, y0) and the opposite corner (x0+dx, y0+dy) are transformed by func_004732F0 on view into start
 * and end; the width and height are their differences. The scale factors are 640 / frame width and 480 /
 * func_00105818(frame), where frame is the 0x3C-byte record chosen by the index at D_0061850C + 0x78 (the same
 * table used by func_003C8808), width read at +8. The locals c and d are declared but never used. */
#include "types.h"

struct Elem {
    char pad0[8];
    s32 k8;
    char pad1[0x3C - 0xC];
};

extern char D_0061850C[];
extern char PDISTD__global_font_manager[];

extern "C" void func_004732F0(void *a0, float *a1, float *a2);
extern "C" s32 func_00105818(void *p);
extern "C" void func_00490700(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

extern "C" void func_00473900(void *view, float x0, float y0, float dx, float dy) {
    float point[3];
    float start[3];
    float end[3];
    float endX;
    float endY;
    float c;
    float d;
    float scaleX;
    float scaleY;
    s32 frameIndex;
    char *frames;
    Elem *frame;
    s32 frameHeight;
    float widthOut;
    float heightOut;
    point[0] = x0;
    point[1] = y0;
    point[2] = 0.0f;
    func_004732F0(view, start, point);
    endX = x0 + dx;
    endY = y0 + dy;
    point[0] = endX;
    point[1] = endY;
    point[2] = 0.0f;
    func_004732F0(view, end, point);
    frames = D_0061850C;
    frameIndex = *(s32 *)(frames + 0x78);
    frame = (Elem *)(frames + frameIndex * 0x3C);
    scaleX = 640.0f / (float)frame->k8;
    frameHeight = func_00105818(frame);
    scaleY = 480.0f / (float)frameHeight;
    widthOut = end[0] - start[0];
    heightOut = end[1] - start[1];
    func_00490700(*(s32 *)PDISTD__global_font_manager, (s32)(start[0] * scaleX), (s32)(start[1] * scaleY), (s32)(widthOut * scaleX), (s32)(heightOut * scaleY));
}
