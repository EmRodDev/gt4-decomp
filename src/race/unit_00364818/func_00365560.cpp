/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef float f32;
typedef unsigned char u8;
struct Obj { char pad0[0xC]; f32 c,d,e; };
struct Arg2 { char pad0[0x444]; f32 unk444; char pad448[0x4B1-0x448]; u8 unk4B1; };
extern "C" void func_00365560(Obj *arg0, void *arg1, Arg2 *arg2, s32 arg3, f32 fparg0) {
    f32 result;
    if (arg2->unk4B1 & 0x10) {
        result = 1.0f;
    } else if (arg3 < 0) {
        result = 1.0f;
    } else if (arg3 > 0 || arg0->e <= fparg0) {
        result = arg0->c + 1.0f;
    } else if (arg0->d < fparg0) {
        result = arg0->c * ((fparg0 - arg0->d) / (arg0->e - arg0->d)) + 1.0f;
    } else {
        result = 1.0f;
    }
    arg2->unk444 = result;
}
