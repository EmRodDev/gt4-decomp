typedef unsigned long long u64;

struct Obj {
    char pad[0x260];
    u64 flags;
};

extern "C" void func_005F5BC0(Obj *arg0, int arg1) {
    arg0->flags = (arg0->flags & 0xFF00FFFFFFFFFFFFULL) | ((u64)(arg1 & 0xFF) << 48);
}
