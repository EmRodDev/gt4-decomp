/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00578290(int arg) throw();
extern "C" int func_005ADCF0(int sema);
extern "C" int func_005ADD00(int sema);

extern "C" int func_00578400(int arg) {
    int sema;
    int ret;
    unsigned int status;
    int (*poll)(int);

    sema = func_00578290(arg);
    if (sema == -1)
        return sema;
    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    if (!(status & 1))
        poll = func_005ADD00;
    else
        poll = func_005ADCF0;
    ret = poll(sema);
    if (ret == sema)
        return arg;
    return ret;
}
