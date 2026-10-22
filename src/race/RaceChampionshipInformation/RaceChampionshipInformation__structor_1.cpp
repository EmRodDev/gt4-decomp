/**
 * Constructor / initializer for RaceChampionshipInformation.
 * Sets the class vtable, iterates over the array of car equipment entries to reset
 * variation order flags, and initializes base race information.
 */
#include "gt4/RaceChampionshipInformation.h"
typedef int s32;

extern void *RaceChampionshipInformation__vtable;
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" void RaceInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceChampionshipInformation__structor_1(void *championshipInfo, s32 deleteFlag) {
    ((struct RaceChampionshipInformation *)championshipInfo)->unk12C = &RaceChampionshipInformation__vtable;
    if ((char *)championshipInfo + 0x180 != 0) {
        char *entryPtr = (char *)championshipInfo + 0xab0;
        while ((char *)championshipInfo + 0x180 != entryPtr) {
            entryPtr -= 0x188;
            SPEC_DATABASE__CarEquipments__setVariationOrder(entryPtr, 0x2);
        }
    }
    RaceInformation__structor_1(championshipInfo, 0x0);
    if ((deleteFlag & 0x1) != 0) {
        return func_005C1628(championshipInfo);
    }
}
