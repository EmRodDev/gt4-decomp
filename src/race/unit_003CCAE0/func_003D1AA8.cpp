/* Walks every car of the race (count at race+0xF8A0, per-car entries 0xA0 bytes apart in self) except the car at excludedCar and
 * asks the sub-object at +0x7C5C to process each (begin func_003D56A0, per car func_003D5728, end func_003D57D8). Purpose of the
 * sub-object unknown (a per-car overlay such as markers is plausible, not proven). */
#include "types.h"

extern "C" s32 func_003CC8E8(void);
extern "C" void RaceEntryCar__update(s32 arg0);
extern "C" s32 func_003D5660(void *s);
extern "C" void func_003D56A0(void *arg0);
extern "C" void func_003D5728(void *a0, s32 a1, s32 a2, f32 f12, f32 f13, f32 f14, f32 f15);
extern "C" void func_003D57D8(void *a0);

extern "C" void func_003D1AA8(void *arg0, void *race, s32 passArg, s32 excludedCar) {
    char *self = (char *)arg0;
    if (func_003CC8E8() == 0) {
        return;
    }
    RaceEntryCar__update(0);
    if (*(s32 *)(self + 0x9680) == 0) {
        return;
    }
    char *subObject = self + 0x7C5C;
    if (func_003D5660(subObject) == 0) {
        return;
    }
    func_003D56A0(subObject);
    s32 carIndex = 0;
    if (*(s32 *)((char *)race + 0xF8A0) > 0) {
        do {
            if (carIndex != excludedCar) {
                func_003D5728(subObject, carIndex, passArg, *(f32 *)(self + 0x78A8), *(f32 *)(self + 0x78AC),
                              *(f32 *)(self + 0x78B0), *(f32 *)(self + 0x78B8));
            }
            carIndex += 1;
            self += 0xA0;
        } while (carIndex < *(s32 *)((char *)race + 0xF8A0));
    }
    func_003D57D8(subObject);
}
