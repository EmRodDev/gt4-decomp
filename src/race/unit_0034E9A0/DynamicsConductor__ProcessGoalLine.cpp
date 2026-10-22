/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Handles a car reaching the goal line, but only when the byte at +0xCBDE is 1 or the byte at +0xF81A is 2
 * (otherwise returns 0). It looks the car up with func_0034C190, raises a RaceDisplayGeneralTimeEvent (the car
 * index, arg2, arg4, arg5 and a byte from carSlot+0x5B7; what each argument means is unknown), tells the race
 * object stored in the first field with func_0035DF80(5, carIndex, 2), calls func_00343D78(carSlot, 3), and for
 * car 0 also func_0034C0A0(conductor, 3). After func_00363528(carSlot) the argument arg4 is stored at
 * carState+0x614 (carState is the block at carSlot+0x104) and the function returns 1. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Slot { char pad[0x5B7]; u8 b5B7; };
struct DC {
    void *f0;
    char pad4[0xCBDE - 4];
    u8 fCBDE;
    char padCBDF[0xF81A - 0xCBDF];
    u8 fF81A;
};

extern "C" Slot *func_0034C190(void *conductor, s32 carIndex);
extern "C" void func_00343D78(void *p, s32 n);
extern "C" void func_0034C0A0(void *p, s32 n);
extern "C" void func_00363528(void *p);
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(void *self, s32 v, s32 w, s32 x, s32 t, s32 f);
extern "C" void func_0035DF80(void *p, s32 a, s32 b, s32 c);

extern "C" s32 DynamicsConductor__ProcessGoalLine(DC *conductor, s32 carIndex, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    if (conductor->fCBDE != 1 && conductor->fF81A != 2) {
        return 0;
    }
    Slot *carSlot = func_0034C190(conductor, carIndex);
    char *carState = (char *)carSlot + 0x104;
    RaceDisplayGeneralTimeEvent__structor_1(conductor, carIndex, arg2, arg4, arg5, carSlot->b5B7);
    func_0035DF80(conductor->f0, 5, carIndex, 2);
    func_00343D78(carSlot, 3);
    if (carIndex == 0) {
        func_0034C0A0(conductor, 3);
    }
    func_00363528(carSlot);
    *(s32 *)(carState + 0x614) = arg4;
    return 1;
}
