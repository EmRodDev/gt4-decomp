/* compiler: ee-gcc2.96-nsa-nosib */
extern "C" void func_00578500(int);
extern "C" int func_00578168(void *, int, int, void *, int);
struct Self { int lock; };
extern "C" int func_006104B8(Self *self) {
    int *buf;
    {
        /* 64-byte aligned scratch block carved out of the stack */
        int size = 0x7F;
        char raw[size];
        buf = (int *)(((unsigned)raw + 0x3F) & ~0x3F);
        func_00578500(self->lock);
        func_00578168(self, 0, 0, buf, 0x40);
    }
    return buf[0];
}
