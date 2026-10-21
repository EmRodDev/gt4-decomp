/* Looks up the object at +0x14 (func_00441248), converts it with func_00445F70 and forwards it as the last argument of func_00146198 with the two given values.
 * Same shape as func_001460C8 (func_00445EE8 and func_00145FE8). */
typedef int s32;

struct Struct_001460C8 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" s32 func_00441248(s32 self);
extern "C" s32 func_00445F70(s32 self);
extern "C" void func_00146198(void *self, s32 first, s32 second, s32 arg3);

extern "C" void func_00146278(Struct_001460C8 *self, s32 first, s32 second) {
    s32 resolved = func_00441248(self->unk14);
    resolved = func_00445F70(resolved);
    func_00146198(self, first, second, resolved);
}
