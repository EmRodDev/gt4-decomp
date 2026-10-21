/* Initializes a race object for the id `baseId` (what kind of object is unknown): stores the id at +0xD8, clears three
 * fields, registers id+0x20 with the sub-object at +0x10 (func_004076E0, plus func_004078D0 with the global D_00622F4C + 0x13938
 * when the flag is set), reads two values back from it (func_00407BC0 / func_00407C40) and falls back to the sub-object's +0x44 and
 * the object's +0xA0 when they come back negative. If a value is stored at +0x00 it also allocates a 0x19C-byte node
 * (allocator named exception__structor_0 in the symbol table), constructs it, hooks callback func_003DCC28 and marks it with flags
 * 1 / 0 / 1 at +0x10 / +0x14 / +0x18. The volatile accesses only keep the compiler's store order. */
#include "types.h"

struct Obj {
    s32 f00;
    void *f04;
    s32 f08;
    char pad0C[0x94];
    s32 fA0;
    char padA4[0x34];
    s32 fD8;
    s32 fDC;
    s32 fE0;
    s32 fE4;
    char padE8[0x8];
    s32 fF0;
    s32 fF4;
    s32 fF8;
};

struct Sub {
    char pad0[0x44];
    s32 f44;
};

struct Node {
    char pad0[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
};

extern s32 D_00622F4C;

extern "C" void func_004076E0(void *s, s32 a);
extern "C" void func_004078D0(void *s, s32 a, s32 b);
extern "C" s32 func_00407BC0(void *s, s32 a);
extern "C" s32 func_00407C40(void *s, s32 a);
extern "C" s32 func_004462E0(s32 a);
extern "C" s32 func_00446320(s32 a);
extern "C" void func_00474F38(void *p, s32 a, s32 b, s32 c);
extern "C" void func_00475D78(void *p, void (*fn)(void), Obj *o);
extern "C" void *exception__structor_0(s32 size);
extern "C" void func_003DCC28(void);

extern "C" void func_003DCC50(Obj *self, s32 baseId, s32 extraFlag) {
    Sub *subObject = (Sub *)((char *)self + 0x10);
    s32 adjustedId = baseId + 0x20;
    self->fD8 = baseId;
    self->fE0 = 0;
    self->fDC = 0;
    self->fE4 = 0;
    func_004076E0(subObject, adjustedId);
    if (extraFlag != 0) {
        func_004078D0(subObject, adjustedId, D_00622F4C + 0x13938);
    }
    self->fF0 = func_00407BC0(subObject, func_004462E0(adjustedId));
    self->fF4 = func_00407C40(subObject, func_00446320(adjustedId));
    if (self->fF0 < 0) {
        self->fF0 = subObject->f44;
    }
    if (self->fF4 < 0) {
        self->fF4 = self->fA0;
    }
    self->fF8 = 1;
    if (self->f00 != 0) {
        Node *node = (Node *)exception__structor_0(0x19C);
        func_00474F38(node, self->f00, 0, self->f08);
        self->f04 = node;
        func_00475D78(node, func_003DCC28, self);
        *(volatile s32 *)&((Node *)self->f04)->f10 = 1;
        {
            Node *nodeAgain = *(Node * volatile *)&self->f04;
            nodeAgain->f18 = 1;
            nodeAgain->f14 = 0;
        }
    }
}
