#include "types.h"

extern "C" void *func_00326750(s32, s32, const char *);
extern "C" void *hObject__structor_0(void *);
extern "C" void func_00309348(void *, void *);
extern "C" const char D_00690F00[];
extern "C" u32 mMemoryCardFile__vtable;

struct CallbackRecordPrefix_00178A98 {
    u32 pad0;
};

struct CallbackRecordVtable_00178A98 {
    u32 vtable;
    u8 pad8[8];
};

struct CallbackRecord_00178A98 : CallbackRecordPrefix_00178A98, CallbackRecordVtable_00178A98 {
    void *callback;
    u32 pad14;
};

extern "C" void mMemoryCardFile__structor_0(void *owner, void *callback) {
    struct CallbackRecord_00178A98 *record = (struct CallbackRecord_00178A98 *)func_00326750(0x18, 4, D_00690F00);
    hObject__structor_0(record);
    u32 vtable = (u32)&mMemoryCardFile__vtable;
    record->callback = callback;
    record->vtable = vtable;
    record->pad14 = 0;
    void *local = record;
    func_00309348(owner, &local);
}
