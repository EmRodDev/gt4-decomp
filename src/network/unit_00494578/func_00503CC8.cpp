/* Detaches/cleans up item arg1 from owner arg0: if arg1 is non-null it calls func_00576788 (a lock-style begin, name inferred from the matching func_005767C0 at the end), releases the pair at +0xC/+0x10 through func_00529650, clears +0x14/+0x18, resets the sub-object at +0x40, runs three cleanup calls on the members at +0x38 and +0x1C, and finally removes arg1 from the three lists of the owner at +0x30, +0x3C and +0x48. All names are descriptive guesses from the call shapes; field purposes stay unknown. */
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

extern "C" void func_00576788(void);
extern "C" void func_00529650(s32, s32);
extern "C" void func_00538C68(void *);
extern "C" void func_00576100(void *);
extern "C" void func_0057B368(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0057CC80(void *, void *);
extern "C" void func_0057CB00(void *, void *);
extern "C" void func_005767C0(s32);

struct func_00503CC8_arg1 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" void func_00503CC8(s32 *owner, void *item) {
    s32 lockState[4];
    char *member38;
    char *member1C;
    member38 = (char *)item + 0x38;
    member1C = (char *)item + 0x1c;
    if (item != 0) {
        lockState[0] = (s32)owner;
        func_00576788();
        func_00529650(((struct func_00503CC8_arg1 *)item)->unkC, ((struct func_00503CC8_arg1 *)item)->unk10);
        ((struct func_00503CC8_arg1 *)item)->unk14 = 0;
        ((struct func_00503CC8_arg1 *)item)->unk18 = 0;
        func_00538C68((char *)item + 0x40);
        lockState[1] = (s32)member38;
        func_00576100(member38);
        func_0057B368(member1C);
        func_00576140(member38);
        func_0057CC80((char *)owner + 0x3c, item);
        func_0057CC80((char *)owner + 0x48, item);
        func_0057CB00((char *)owner + 0x30, item);
        func_005767C0(lockState[0]);
    }
}
