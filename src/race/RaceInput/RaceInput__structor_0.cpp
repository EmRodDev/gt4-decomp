/* Constructor of RaceInput: runs the base constructor 0055F620, installs the RaceInput vtable at +0xD0, constructs the embedded parts at +0xD4,
 * +0x170 (given +0x150) and +0x1A0, and zeroes thirteen fields with +0x1CC set to 1 (the only nonzero start value). The fields keep their
 * unkNN names from include/gt4/RaceInput.h; their meaning is purpose unknown here. */
#include "gt4/RaceInput.h"
typedef int s32;

extern void *RaceInput__vtable;
extern "C" void *func_0055F620(void *);
extern "C" void *func_00346758(void *);
extern "C" void *func_0043A0C0(void *, void *);
extern "C" void *func_0043A078(void *);

extern "C" void RaceInput__structor_0(void *self) {
    func_0055F620(self);
    ((struct RaceInput *)self)->unkD0 = &RaceInput__vtable;
    func_00346758((char *)self + 0xd4);
    func_0043A0C0((char *)self + 0x170, (char *)self + 0x150);
    func_0043A078((char *)self + 0x1a0);
    ((struct RaceInput *)self)->unk1C4 = 0x0;
    ((struct RaceInput *)self)->unk1CC = (void *)(0x1);
    ((struct RaceInput *)self)->unk1C8 = 0x0;
    ((struct RaceInput *)self)->unk1D0 = 0x0;
    ((struct RaceInput *)self)->unk1D4 = 0x0;
    ((struct RaceInput *)self)->unk144 = 0x0;
    ((struct RaceInput *)self)->unk148 = 0x0;
    ((struct RaceInput *)self)->unk14C = 0x0;
    ((struct RaceInput *)self)->unk194 = 0x0;
    ((struct RaceInput *)self)->unk19C = 0x0;
    ((struct RaceInput *)self)->unk1D8 = 0x0;
    ((struct RaceInput *)self)->unk1DC = 0x0;
}
