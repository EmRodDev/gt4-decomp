/* Moves the current gear (byte at +0x104+0x520, same field func_0036C160 reads as 'gear') one step per call toward the target
 * gear returned by func_0036C8E8, through func_0035A5F8(self, 0, +1/-1); when the target is neutral or the gear is 0 it sets the
 * state byte (0x522) to 2, and to 3 if the owner's sub-block rejects it. Returns early when there is no target (-1). */
struct Obj {
    char pad0[0x10];
    char *unk10;
};

struct Sub {
    char pad0[0x520];
    unsigned char unk520;
    char pad1;
    unsigned char unk522;
};

extern "C" int func_0036C8E8(Obj *self);
extern "C" int func_003F1F88(char *self);
extern "C" void func_0035A5F8(char *self, int arg1, signed char arg2);
extern "C" void func_0036BEB8(Obj *self, int arg1);

extern "C" void func_00351DC8(Obj *self) {
    int targetGear;
    int currentGear;
    Sub *gearState;

    targetGear = func_0036C8E8(self);
    gearState = (Sub *)((char *)self + 0x104);
    if (targetGear == -1) {
        return;
    }
    if (gearState->unk522 != 0) {
        if (targetGear == 0 || gearState->unk520 == 0) {
            gearState->unk522 = 2;
        } else {
            if (func_003F1F88(self->unk10 + 0x234) == 0) {
                gearState->unk522 = 3;
            }
            currentGear = gearState->unk520;
            if (currentGear < targetGear) {
                func_0035A5F8((char *)self, 0, 1);
            } else if (targetGear < currentGear) {
                func_0035A5F8((char *)self, 0, -1);
            }
        }
    }
    return func_0036BEB8(self, targetGear);
}
