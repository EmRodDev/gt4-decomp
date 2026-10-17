/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Service {
    char data[0x10];
};

extern "C" Service D_008732C0;
extern "C" Service *D_0064D210;
extern "C" char D_00655290[];

extern "C" void func_00556D30(Service *);
extern "C" void func_005579F0(Service *);
extern "C" int func_00556D80(Service *);
extern "C" void func_00557818(void);
extern "C" void func_00565B88(void *, void (*)(void), Service *);
extern "C" void func_00556EA0(Service *);

extern "C" Service *func_00556CA0(void)
{
    if (!D_0064D210) {
        Service *service = &D_008732C0;
        if (service)
            func_00556D30(service);
        D_0064D210 = service;
        func_005579F0(service);
        if (func_00556D80(D_0064D210)) {
            func_00565B88(D_00655290, func_00557818, D_0064D210);
            func_00556EA0(D_0064D210);
        }
    }
    return D_0064D210;
}
