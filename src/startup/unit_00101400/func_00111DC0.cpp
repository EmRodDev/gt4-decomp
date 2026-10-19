#include "types.h"
struct Car { char pad[0x3448]; int flag; };
struct Wheel { char pad[8]; Car *car; };
struct Parent { char pad[0x60]; Wheel *wheel; };
struct Owner { char pad[0x6C - 0x0]; };
struct Child { char pad[0x60]; Wheel *wheel; };
struct Self {
    char pad0[0x3AC]; u8 b3AC; char p3AD[3]; u8 b3B0; char p3B1[3]; u8 b3B4; char p3B5[3]; u8 b3B8; char p3B9[3]; u8 b3BC; char p3BD[3];
    int s3C0; int s3C4; char p3C8[0xC0]; int pending;
};
struct Model { char pad[0x60]; Wheel *wheel; };
struct Target { char pad[0x6C]; };
extern "C" void func_00110B90(int sel, int *a, int *b);
extern "C" void func_003C0D78(void *, int, int);
extern "C" void func_003C0D98(void *, int, int);
extern "C" int func_00443240(void *);
extern "C" void func_00111DC0(Self *self, char *arg) {
    int out[2];
    void *obj = *(void **)(arg + 0x6C);
    Car *car = **(Car ***)(*(char **)((char *)obj + 0x60) + 8);
    car->flag = self->s3C0 != 0;
    char *e;
    func_00110B90(self->s3C4, &out[0], &out[1]);
    func_003C0D78(obj, out[0], 0);
    func_003C0D98(obj, out[1], 0);
    if (self->pending) {
        e = (char *)car + 0x20;
        e[0x163] = self->b3B0 + 100;
        e[0x162] = self->b3AC + 100;
        e[0x160] = self->b3B8;
        e[0x161] = self->b3BC;
        if (self->b3B4) {
            e[0x12A] = self->b3B4;
            func_00443240(e);
        }
        e[0x165] = 1;
        self->pending = 0;
    }
}
