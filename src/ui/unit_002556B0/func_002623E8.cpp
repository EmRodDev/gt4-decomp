#include "types.h"

struct Obj002676A8;

struct Widget {
    char pad[0x34];
    s32 window_geometry;
};

extern "C" void func_00261FB8(s32 arg0, s32 arg1);
extern "C" void func_002676A8(struct Obj002676A8 *arg0, s32 arg1);

extern "C" void func_002623E8(Widget *arg0, s32 arg1) {
    func_00261FB8(arg1, (s32)&arg0->window_geometry);
    func_002676A8((struct Obj002676A8 *)arg0, 2);
}
