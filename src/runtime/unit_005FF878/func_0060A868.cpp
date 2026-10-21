/* Setter: stores the two arguments at +0x30 and +0x34. Field purposes unknown. */
typedef int s32;

struct Obj {
    char pad[0x30];
    s32 unk30;
    s32 unk34;
};

extern "C" void func_0060A868(Obj *self, s32 first, s32 second) {
    self->unk30 = first;
    self->unk34 = second;
}
