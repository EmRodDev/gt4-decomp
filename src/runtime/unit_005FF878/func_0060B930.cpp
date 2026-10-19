#include "types.h"

struct Obj {
    char pad[4];
    u8 *unk4;
};

extern "C" s32 func_0060B930(struct Obj *arg0) {
    u8 *p = arg0->unk4 + 0xC;
    return (p[0] | (p[1] << 8) | (p[2] << 16)) | (p[3] << 24);
}
