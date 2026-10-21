/* Sets a value on the camera sub-object at +0xE28 of the photo-mode object and returns the value read back through func_00370D70.
 * The object comes from func_00192E20 and its accessor is vtable +0x4B0 (the same camera at +0xE28 is used in func_00194DB0). Meaning of the value is unknown. */
#include "types.h"

struct Obj00370D70;

struct VEnt00195270 {
    s16 delta;
    s16 pad;
    void *(*fn)(void *);
};

struct ObjA00195270 {
    char pad0[0x64];
    VEnt00195270 *vtbl;
};

extern "C" int func_00192E20(s32);
extern "C" void func_00370DB0(void *camera, s32 v);
extern "C" f32 func_00370D70(Obj00370D70 *camera);

extern "C" f32 func_00195270(s32 arg0, s32 modeArg, s32 value)
{
    ObjA00195270 *photoMode;
    VEnt00195270 *entry;
    char *camera;

    photoMode = (ObjA00195270 *)func_00192E20(modeArg);
    entry = (VEnt00195270 *)((char *)photoMode->vtbl + 0x4B0);
    camera = (char *)entry->fn((char *)photoMode + entry->delta) + 0xE28;
    func_00370DB0(camera, value);
    return func_00370D70((Obj00370D70 *)camera);
}
