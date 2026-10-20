typedef unsigned long long u64;

struct Obj {
    char pad0[0x188];
    float unk188;
    char pad18C[0x260 - 0x18C];
    u64 flags;
};

extern "C" void func_005F5C50(Obj *arg0, float f) {
    arg0->unk188 = f;
    arg0->flags = (arg0->flags & 0x00FFFFFFFFFFFFFFULL) | 0x0100000000000000ULL;
}
