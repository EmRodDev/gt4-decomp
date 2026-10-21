/* Finishes the automobile control recorder: if the pointer at +0x148 is set, calls
 * AutomobileControlRecord::Recorder::finish on the Recorder part, which sits at +8 of the pointed object (name from the symbol table). */
#include "types.h"

struct Struct_00426C50 {
    char pad[0x148];
    s32 *unk148;
};

extern void AutomobileControlRecord__Recorder__finish(s32 *);

extern "C" void func_00426C78(Struct_00426C50 *self) {
    s32 *recorderOwner;

    recorderOwner = self->unk148;
    if (recorderOwner != 0) {
        AutomobileControlRecord__Recorder__finish((s32 *)((char *)recorderOwner + 8));
    }
}
