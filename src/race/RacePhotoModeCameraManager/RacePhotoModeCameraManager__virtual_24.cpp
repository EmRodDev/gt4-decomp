#include "types.h"

struct RacePhotoModeCameraManagerLayout {
    char pad0[0x9C0];
    f32 unk9C0;
    char pad9C4[0x9D4 - 0x9C4];
    f32 unk9D4;
    char pad9D8[0xE28 - 0x9D8];
    char unkE28[0x108];
};

extern "C" void DevelopCamera__virtual_24(void *arg0);
extern "C" void func_0036FD88(void *arg0, f32 fparg0, f32 fparg1);

extern "C" void RacePhotoModeCameraManager__virtual_24(RacePhotoModeCameraManagerLayout *arg0) {
    DevelopCamera__virtual_24(arg0);
    func_0036FD88(arg0->unkE28, arg0->unk9C0, arg0->unk9D4);
}
