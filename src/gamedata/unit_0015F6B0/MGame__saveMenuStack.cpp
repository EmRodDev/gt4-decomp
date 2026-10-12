struct Owner { char pad[0x10]; char *p; };
extern "C" void *func_0015F3E0(void *, void *);
extern "C" void func_0015F388(void *, int);
extern "C" void func_0042FE88(void *);
extern "C" void MGame__saveMenuStack(void *, void *arg1, int, void *) {
    Owner *buf[4];
    func_0015F3E0(buf, arg1);
    func_0042FE88(buf[0]->p + 0x3A368);
    func_0015F388(buf, 2);
}
