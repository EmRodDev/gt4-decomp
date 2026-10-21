/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Thread {
    char pad[0x30];
    int id;
};

extern char D_006CC660[]; /* "EE xChangeThreadPriority failed." */

extern "C" void func_00574C30(const char *fmt, ...);
extern "C" int func_00578618(int arg) throw();
extern "C" int func_005785F0(int arg0) throw() __attribute__((const));
extern "C" int func_005ADB30(int thread, int prio);
extern "C" int func_005ADB40(int thread, int prio);

extern "C" void func_00578828(Thread *t, int prio) {
    int id;
    int eePrio;
    unsigned int status;
    int (*change)(int, int);

    id = func_00578618(t->id);
    eePrio = func_005785F0(prio);
    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    if (!(status & 1))
        change = func_005ADB40;
    else
        change = func_005ADB30;
    if (change(id, eePrio) == -1)
        func_00574C30(D_006CC660);
}
