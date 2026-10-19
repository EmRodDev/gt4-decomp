typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x28];
    f32 unk28;
};

extern "C" f32 func_0036FFC0(void *cam, f32 x);

extern "C" f32 func_003700F8(Obj *arg0) {
    return func_0036FFC0(arg0, arg0->unk28);
}
