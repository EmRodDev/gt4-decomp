/* If the member at +0x2A4 is set, forwards it to func_00154208. Sibling of func_0013A548 (same guard, func_00154040). Purpose unknown. */
typedef int s32;

struct Struct_0013A548 {
    char pad0[0x2A4];
    s32 unk2A4;
};

extern void func_00154208(s32);

extern "C" void func_0013A650(Struct_0013A548 *self) {
    s32 member = self->unk2A4;
    if (member != 0) {
        func_00154208(member);
    }
}
