/* Under the lock on the member at +0x10 it queues item arg1 on the list heads at +0x40 and +0x4C (func_0057CC80 / func_0057CB00, both given the item's list node at +0x3C), takes the item's own lock to set its field +0x80 to 1, and finally notifies the member at +0x64 (func_00574EE8). func_00576788 / func_005767C0 are the lock begin/end pair (inferred from the matching call order); what the lists are is not determined. */
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

extern "C" void func_00576788(void *);
extern "C" void func_0057CC80(void *, void *);
extern "C" void func_0057CB00(void *, void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00574EE8(void *);

struct func_004AD648_arg1 {
    char pad0[0x80];
    s32 unk80;
};

extern "C" void func_004AD648(s32 *owner, void *item) {
    char *ownerLock;
    char *itemNode;
    ownerLock = (char *)owner + 0x10;
    itemNode = (char *)item + 0x3c;
    func_00576788(ownerLock);
    func_0057CC80((char *)owner + 0x40, itemNode);
    func_00576788(item);
    ((struct func_004AD648_arg1 *)item)->unk80 = 0x1;
    func_0057CB00((char *)owner + 0x4c, itemNode);
    func_005767C0(item);
    func_00574EE8((char *)owner + 0x64);
    func_005767C0(ownerLock);
}
