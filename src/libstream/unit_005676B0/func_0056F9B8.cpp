struct Cl { char pad[0x24]; int ready; };
extern "C" int func_00590CC8(Cl *, int, int, unsigned, int, int);
extern "C" void func_005B0750(const char *, ...);
extern "C" int func_0056F9B8(Cl *cl, unsigned size, int a, int b) {
    if (size < 128) return -543;
    if (size != ((size + 63) & ~63u)) {
        func_005B0750("sceLibnetInitialize() buffersize\n");
        return -543;
    }
    goto call;
    do {
        for (unsigned n = 0x10000; n--; ) { }
call:
        if (func_00590CC8(cl, 0x80001201, 0, size, a, b) < 0) return -540;
    } while (cl->ready == 0);
    return 0;
}
