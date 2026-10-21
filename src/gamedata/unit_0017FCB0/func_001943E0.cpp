/* If the member at +0xE4 is set: wraps (arg2 != 0) in a script value (func_002FE278), builds a call record from the member, 2 and arg1 (func_0020D738),
 * passes it to func_002319A0 together with arg1 and then releases both temporaries. Purpose unknown; looks like firing a script event (inferred from the shape). */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_002FE278(void *, s32);
extern "C" void func_0020D738(void *, void *, s32, void *, s32);
extern "C" void func_002319A0(void *, void *);
extern "C" void func_0020D1B8(void *, s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void func_001943E0(s32 *self, void *target, s32 flag) {
    s32 boolValue[4];
    s32 record[4];
    char *member;
    s32 *recordPtr;
    member = (char *)self + 0xe4;
    if (*(s32 *)(char *)member != 0) {
        func_002FE278(boolValue, flag != 0);
        recordPtr = record;
        func_0020D738(recordPtr, member, 0x2, target, boolValue[0]);
        func_002319A0(target, recordPtr);
        func_0020D1B8(recordPtr, 0x2);
        func_002FC870(boolValue, 0x2);
    }
}
