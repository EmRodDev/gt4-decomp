/* Reports a speed value for car carIndex: records it on the car entry and raises a speed display event. carState
 * is the state block at car+0x104 (the same block layout used by func_0035BFE8); nothing happens unless the bytes
 * at +0x441 and +0x632 of it are zero. func_0035E3F8 is asked about the car; when it returns 0 the speed is stored
 * at carEntry+0x3464, where the entry is found through the pointer array at (race+0x60)->+8 indexed by carIndex.
 * If the int at race+0xDC is zero, a RaceDisplaySpeedEvent is built on the stack, given the car index at +0 and
 * the speed converted by func_00472940 with PDISTD__UNIT_MANAGER (a unit conversion, inferred from the name) at
 * +8, and put into the race through the event base put method. The meaning of the first check on bytes
 * +0x441/+0x632 is unknown. */
#include "types.h"

extern "C" s32 func_0034C190(void *owner, s32 carIndex);
extern "C" s32 func_0035E3F8(void *owner, void *carIndex, s32 arg2);
extern "C" void RaceDisplayEventBase__put(void *o, void *t);
extern "C" void RaceDisplaySpeedEvent__structor_0(void *owner);
extern "C" f32 func_00472940(void *p, f32 x);
extern char PDISTD__UNIT_MANAGER[];

extern "C" void func_0035E7C0(void *owner, s32 carIndex, f32 speed) {
    s32 event[4];
    char *race;
    s32 byteOffset;
    s32 result;
    unsigned char *carState;

    carState = (unsigned char *)((char *)func_0034C190(owner, carIndex) + 0x104);
    if (carState[0x441] == 0 && carState[0x632] == 0) {
        race = *(char **)owner;
        result = func_0035E3F8(race, owner, func_0034C190(owner, carIndex));
        byteOffset = carIndex * 4;
        if (result == 0) {
            char *listHolder = *(char **)(race + 0x60);
            s32 listBase = *(s32 *)(listHolder + 8);
            char *carEntry = *(char **)(byteOffset + listBase);
            *(f32 *)(carEntry + 0x3464) = speed;
        }
        if (*(s32 *)(race + 0xDC) == 0) {
            RaceDisplaySpeedEvent__structor_0(event);
            event[0] = carIndex;
            *(f32 *)&event[2] = func_00472940(PDISTD__UNIT_MANAGER, speed);
            RaceDisplayEventBase__put(event, race);
        }
    }
}
