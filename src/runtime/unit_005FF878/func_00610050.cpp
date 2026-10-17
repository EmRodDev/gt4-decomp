/* compiler: ee-gcc2.96-nsa-nosib */
extern "C" void func_00578500(int);
extern "C" int func_00578168(void *, int, int, void *, int);
struct Self { int lock; };
extern "C" int func_00610050(Self *self) {
    int result;
    {
        int size = 0x7F;
        char raw[size];
        int *buf = (int *)(((unsigned)raw + 0x3F) & ~0x3F);
        func_00578500(self->lock);
        func_00578168(self, 4, 0, buf, 0x40);
        result = -1;
        if (buf[0] != 0) result = buf[1];
    }
    return result;
}
