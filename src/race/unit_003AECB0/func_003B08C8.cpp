#include "types.h"

struct Obj {
    u8 pad[0x690];
    s32 unk690;
};

extern "C" void func_003B04D0(char *arg0);
extern "C" int func_00419068(Obj *arg0);

extern "C" void func_003B08C8(Obj *arg0) {
    func_00419068(arg0);
    func_003B04D0((char *)arg0 + 0x680);
    arg0->unk690 = 0;
}
