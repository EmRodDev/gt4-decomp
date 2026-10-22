/* Constructor of mPlayerStats taking a pointer to a std::string: runs the hObject base constructor, sets the vtable at +4, and copies the string's bytes to +0x10
 * (the length comes from the rep header at -0x10 of the string data, so the copy has the string's own size and no bound check). Then it writes 0 to the bytes at
 * +0x4F, +0x6F, +0x8F, +0xCF and +0x10F; they look like the terminators of five fixed text buffers (inferred from their spacing), the first being the 0x40-byte buffer at +0x10. */
#include "gt4/mPlayerStats.h"
typedef int s32;

extern void *mPlayerStats__vtable;
extern "C" void *hObject__structor_0(void *);
extern "C" void *memcpy(void *, void *, void *);

extern "C" void mPlayerStats__structor_0(void *self, void *name) {
    hObject__structor_0(self);
    ((struct mPlayerStats *)self)->unk4 = &mPlayerStats__vtable;
    memcpy((char *)self + 0x10, *(void **)(name), *(void **)((char *)*(void **)(name) + -0x10));
    ((struct mPlayerStats *)self)->unk4F = 0x0;
    ((struct mPlayerStats *)self)->unk6F = 0x0;
    ((struct mPlayerStats *)self)->unk8F = 0x0;
    ((struct mPlayerStats *)self)->unkCF = 0x0;
    ((struct mPlayerStats *)self)->unk10F = 0x0;
}
