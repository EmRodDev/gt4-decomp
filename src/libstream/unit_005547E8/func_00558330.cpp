/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Worker {
    char pad0[0xD0]; char subA[0x560]; char subB[1];   /* 0xD0 / 0x630 regions passed to func_005678E8 */
};
struct Lock { int word; };
extern Lock D_00873558;
extern "C" void func_005512C0(int);
extern "C" void func_00557F88(void *);
extern "C" int func_00557F90(void *);
extern "C" void func_00558018(void *);
extern "C" void func_00558038(void *, int);
extern "C" void func_00558100(void *);
extern "C" int func_005678E8(void *, void *);
extern "C" void func_00576100(Lock *);
extern "C" void func_00576140(Lock *);
extern "C" void func_005783A0(int);
extern "C" void func_00578500(int);
/* scope guard: locks on construction, unlocks on destruction */
struct Guard {
    Lock *lock;
    Guard(Lock *l) { lock = l; func_00576100(l); }
    ~Guard() { func_00576140(lock); }
};
#define F(T, off) (*(T *)((char *)w + (off)))
extern "C" void func_00558330(char *w) {
    while (F(int, 0x76C) != 0) {
        func_00578500(F(int, 0x788));
        if (F(int, 0x76C) == 0) break;
        if (func_00557F90(w) != 0) {
            func_00558038(w, 1);
            F(int, 0x77C) = func_005678E8(w + 0xD0, w + 0x630);
            while (F(int, 0x774) == 0) {
                if (F(int, 0x778) != 0) func_00578500(F(int, 0x788));
                func_00558100(w);
                if (F(int, 0x77C) <= 0) break;
                func_00558038(w, 0);
            }
            func_00558018(w);
        }
        {
            Guard guard(&D_00873558);
            F(int, 0x774) = 0;
            F(int, 0x770) = 0;
            F(int, 0x778) = 0;
        }
        func_00557F88(w);
    }
    func_005512C0(F(int, 0x768));
    func_005783A0(F(int, 0x788));
}
