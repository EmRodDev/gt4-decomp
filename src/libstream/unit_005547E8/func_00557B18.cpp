/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Thread {
    char pad[0x288];
    int handle;
    int stop;
    void (*hook)(int);
    int hookArg;
};
extern "C" int func_005782E8(int, int);
extern "C" int func_005AD990(int, void (*)(), int, int);
extern "C" void func_005AD9A0(int, int);
extern "C" void func_00557AF0();
extern "C" void func_00578500(int);
extern "C" void func_005783A0(int);
extern "C" void func_00576788(int);
extern "C" void func_005767C0(int);
extern char D_00872280[];
extern "C" void func_00557B18(Thread *t) {
    t->handle = func_005782E8(0, 0xFF);
    int saved = func_005AD990(2, func_00557AF0, 0, t->handle);
    if (t->stop == 0) {
        do {
            func_00578500(t->handle);
            func_00576788((int)D_00872280);
            void (*hook)(int) = t->hook;
            int arg = t->hookArg;
            if (hook != 0) hook(arg);
            func_005767C0((int)D_00872280);
        } while (t->stop == 0);
    }
    t->stop = 0;
    func_005AD9A0(2, saved);
    func_005783A0(t->handle);
}
