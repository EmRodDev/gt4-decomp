typedef unsigned long long u64;

struct Obj {
    char pad[0x168];
    u64 flags;
};

extern "C" void func_005F5B10(Obj *arg0) {
    arg0->flags &= 0xFFFFFFFF00FFFFFFULL;
}
