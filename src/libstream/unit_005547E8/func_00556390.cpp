struct ServiceState;
extern int D_0064D20C;
extern ServiceState *D_008A1A50[];
// This canonical symbol at 0x005C1498 is the allocation routine (size in bytes).
extern "C" void *exception__structor_0(unsigned int size);
extern "C" void func_005563F0(ServiceState *state);

extern "C" ServiceState *func_00556390() {
    ServiceState *selected = D_008A1A50[D_0064D20C];
    if (selected != 0)
        return selected;
    // Initialization publishes the shared fallback in slot zero.
    if (D_008A1A50[0] == 0)
        func_005563F0((ServiceState *)exception__structor_0(0x64));
    return D_008A1A50[0];
}
