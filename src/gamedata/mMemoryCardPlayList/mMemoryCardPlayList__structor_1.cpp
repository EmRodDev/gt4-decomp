#include "types.h"

struct hObjectNative {
    u32 unk0;
    u32 vtable;
    u32 unk8;
    u32 unkC;
    hObjectNative() __asm__("func_0030A678");
};

struct CopyBlock_0017D490 {
    u64 words[0x190];
    s32 count;
    s32 pad;
};

struct mMemoryCardPlayListNative : hObjectNative {
    void *data;
    s32 initialized;
    u32 unk18;
    mMemoryCardPlayListNative(const CopyBlock_0017D490 *source) __asm__("func_0017D490");
};

extern "C" void *exception__structor_0(s32);
extern "C" u32 mMemoryCardPlayList__vtable;

mMemoryCardPlayListNative::mMemoryCardPlayListNative(const CopyBlock_0017D490 *source)
    : hObjectNative() {
    vtable = (u32)&mMemoryCardPlayList__vtable;
    CopyBlock_0017D490 *allocation;
    if (source != 0) {
        allocation = (CopyBlock_0017D490 *)exception__structor_0(0xC88);
        *allocation = *source;
    } else {
        allocation = (CopyBlock_0017D490 *)exception__structor_0(0xC88);
        allocation->count = 0;
    }
    data = allocation;
    initialized = 1;
}
