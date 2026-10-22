/* Shared startup strings are declared at their verified original addresses;
 * the standalone function pools do not follow the executable's pool order. */
extern const char sio2manModuleName[] __asm__("D_0068BC90");
extern const char mcmanModuleName[] __asm__("D_0068BCA0");
extern const char mcservModuleName[] __asm__("D_0068BCB0");
extern const char sio2dModuleName[] __asm__("D_0068BCC0");
extern const char dbcmanModuleName[] __asm__("D_0068BCD0");
extern const char libsdModuleName[] __asm__("D_0068BCE0");
extern const char usbdModuleName[] __asm__("D_0068BCF0");
extern const char inetModuleName[] __asm__("D_0068BD00");
extern const char netcnfModuleName[] __asm__("D_0068BD10");
extern const char networkIconArguments[] __asm__("D_0068BAA8");
extern const char inetctlModuleName[] __asm__("D_0068BD20");
extern const char inetctlArguments[] __asm__("D_0068BD30");
extern const char dev9ModuleName[] __asm__("D_0068BD48");
extern const char smapModuleName[] __asm__("D_0068BD58");
extern const char msifrpcModuleName[] __asm__("D_0068BD68");
extern const char libpdiModuleName[] __asm__("D_0068BD78");
extern const char pdicdvdModuleName[] __asm__("D_0068BD88");
extern const char pdispu2ModuleName[] __asm__("D_0068BD98");
extern const char pdistrModuleName[] __asm__("D_0068BDA8");
extern const char pdiusbModuleName[] __asm__("D_0068BDB8");
extern const char ustorageModuleName[] __asm__("D_0068BDC8");
extern const char lgdevModuleName[] __asm__("D_0068BDD8");
extern const char powoffModuleName[] __asm__("D_0068BDE8");

/* Provisional ABI views: module objects occupy 0x28 bytes; the two
 * 8-byte callback/value representations are passed by address. */
struct ModuleValue { char b[8]; };
struct ModuleCallback { int f, v; };
extern "C" ModuleCallback *func_00577170(ModuleCallback *callback, const int &f, int v);
extern "C" ModuleCallback *func_00577188(ModuleCallback *callback, const int &f, int v);
struct IopModule { char data[0x28]; };

extern "C" IopModule *func_00577198(IopModule *modules);
extern "C" IopModule *func_00577240(IopModule *modules, const char *name, const ModuleCallback *f);
extern "C" IopModule *func_00577290(IopModule *modules, const ModuleCallback *f);
extern "C" IopModule *func_005772E8(IopModule *modules, const char *name, const ModuleCallback *f);
extern "C" IopModule *func_00577340(IopModule *modules, const char *name, const char *args, const ModuleValue *a, const ModuleValue *b);

extern "C" void func_00101A70(void);
extern "C" void func_00101858(void);
extern "C" void func_00101970(void);
extern "C" void func_00102788(void);
extern "C" void func_00101930(void);
extern "C" void func_00101A10(void);
extern "C" void func_001026D0(void);
extern "C" void func_00102738(void);
extern "C" void func_00101AF0(void);
extern "C" void func_001027B0(void);
extern "C" void func_00101B18(void);

extern ModuleValue D_00655880;
extern char *D_00617D90;
extern int D_006182A0;
extern char *D_006182BC;
extern char *D_006182C0;
extern IopModule D_00617D98[18];
extern IopModule D_00618068[9];
extern IopModule D_006181D0[3];
extern IopModule D_00618248[2];

extern "C" void func_00101E28(int init, int prio) {
    ModuleCallback callback;
    if (prio == 0xFFFF && init == 1) {
        IopModule *module;
        IopModule *modules = D_00617D98;
        {
            func_00577188(&callback, (int)func_00101A70, 0);
            func_00577290(&modules[0], &callback);
        }
        {
            module = &modules[1];
            func_00577188(&callback, (int)func_00101858, 0);
            func_00577290(module, &callback);
        }
        func_00577340(&modules[2], sio2manModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[3], mcmanModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[4], mcservModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[5], sio2dModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[6], dbcmanModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[7], D_006182A0 ? D_00617D90 + 5 : D_00617D90, 0, &D_00655880, &D_00655880);
        {
            module = &modules[8];
            func_00577188(&callback, (int)func_00101970, 0);
            func_00577290(module, &callback);
        }
        func_00577340(&modules[9], libsdModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[10], usbdModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[11], inetModuleName, 0, &D_00655880, &D_00655880);
        func_00577340(&modules[12], netcnfModuleName, networkIconArguments, &D_00655880, &D_00655880);
        func_00577340(&modules[13], inetctlModuleName, inetctlArguments, &D_00655880, &D_00655880);
        func_00577340(&modules[14], dev9ModuleName, 0, &D_00655880, &D_00655880);
        {
            module = &modules[15];
            func_00577170(&callback, (int)func_00102788, 0);
            func_00577240(module, smapModuleName, &callback);
        }
        func_00577340(&modules[16], msifrpcModuleName, 0, &D_00655880, &D_00655880);
        func_00577198(&modules[17]);
    }
    if (prio == 0xFFFF && init == 1) {
        IopModule *module;
        IopModule *modules = D_00618068;
        func_00577340(&modules[0], libpdiModuleName, 0, &D_00655880, &D_00655880);
        {
            module = &modules[1];
            func_00577188(&callback, (int)func_00101930, 0);
            func_005772E8(module, pdicdvdModuleName, &callback);
        }
        func_00577340(&modules[2], pdispu2ModuleName, 0, &D_00655880, &D_00655880);
        {
            module = &modules[3];
            func_00577188(&callback, (int)func_00101A10, 0);
            func_005772E8(module, pdistrModuleName, &callback);
        }
        {
            module = &modules[4];
            func_00577188(&callback, (int)func_001026D0, 0);
            func_005772E8(module, pdiusbModuleName, &callback);
        }
        {
            module = &modules[5];
            func_00577188(&callback, (int)func_00102738, 0);
            func_005772E8(module, ustorageModuleName, &callback);
        }
        {
            module = &modules[6];
            func_00577188(&callback, (int)func_00101AF0, 0);
            func_005772E8(module, lgdevModuleName, &callback);
        }
        func_00577340(&modules[7], powoffModuleName, 0, &D_00655880, &D_00655880);
        func_00577198(&modules[8]);
    }
    if (prio == 0xFFFF && init == 1) {
        IopModule *module;
        IopModule *modules = D_006181D0;
        func_00577340(&modules[0], D_006182BC, D_006182C0, &D_00655880, &D_00655880);
        {
            module = &modules[1];
            func_00577188(&callback, (int)func_001027B0, 0);
            func_00577290(module, &callback);
        }
        func_00577198(&modules[2]);
    }
    if (prio == 0xFFFF && init == 1) {
        IopModule *module;
        IopModule *modules = D_00618248;
        {
            func_00577188(&callback, (int)func_00101B18, 0);
            func_00577290(&modules[0], &callback);
        }
        func_00577198(&modules[1]);
    }
}
