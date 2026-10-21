/* License-mode override of getDataLoggerSection. When the virtual at vtable +0x40 reports 0 the base DynamicsConductor version answers. Otherwise
 * the section number is (implicit current lap - 1) * (number of logger sections) + the byte at +0x5B8 of the car (the car's current section,
 * inferred from the formula), minus 1 when flag is nonzero. The meaning of flag and of the +0x40 test is purpose unknown. */
#include "types.h"

struct Obj_3F6140 {
    char pad0[0x10140];
    char *vtbl;
};

struct VEntry_3F6140 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32);
};

extern "C" s16 Automobile__GetImplicitCurrentLap(void *);
extern "C" s32 DynamicsConductor__getNumberOfLoggerSections(void *);
extern "C" s32 DynamicsConductor__getDataLoggerSection(void *, void *, s32);

extern "C" s32 DynamicsConductorLicense__getDataLoggerSection(char *conductor, char *car, s32 flag) {
    Obj_3F6140 *conductorObject = (Obj_3F6140 *)conductor;
    VEntry_3F6140 *entry = (VEntry_3F6140 *)(conductorObject->vtbl + 0x40);
    if (entry->fn((char *)conductorObject + entry->delta, car, flag) == 0) {
        return DynamicsConductor__getDataLoggerSection(conductor, car, flag);
    } else {
        s32 lap = Automobile__GetImplicitCurrentLap(car);
        s32 sectionCount = DynamicsConductor__getNumberOfLoggerSections(conductor);
        s32 sectionNumber = (lap - 1) * sectionCount + *(u8 *)(car + 0x5B8);
        s32 result = sectionNumber - 1;
        if (flag == 0) {
            result = sectionNumber;
        }
        return result;
    }
}
