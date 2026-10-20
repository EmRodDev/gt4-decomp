#include "types.h"

/* the record SPEC_DATABASE__DatabaseStorage__getRow fills for an id */
struct Info {
    u16 f0;
    char pad2[0x2E];
};

struct Global;

struct Obj {
    char pad0[0x30];
    s64 id;
};

extern Global D_006235A8;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_00445D90(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info);
    return info.f0;
}
