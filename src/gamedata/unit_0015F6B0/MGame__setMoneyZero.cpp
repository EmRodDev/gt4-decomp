struct Owner { char pad[0x10]; char *p; };
extern "C" void func_0015F3E0(void *, void *);
extern "C" void func_0015F388(void *, int);
extern "C" void func_0043AF88(void *, int);
extern "C" void MGame__setMoneyZero(void *, void *arg1, int, void *) {
    Owner *buf[4];
    func_0015F3E0(buf, arg1);
    func_0043AF88(buf[0]->p + 0x348, 0);
    func_0015F388(buf, 2);
}
