/* compiler: ee-gcc2.96-nsa-nosib */
struct Block64 { char d[0x40]; } __attribute__((packed));
struct Self { int lock; char pad4[0x3C]; char name[1]; };
extern "C" void func_00578500(int);
extern "C" char *func_005A609C(char *, const char *);
extern "C" int func_00578168(void *, int, int, void *, int);
extern "C" Block64 func_00610608(Self *self, const char *name) {
    {
        int size = 0x7F;
        char raw[size];
        Block64 *buf = (Block64 *)(((unsigned)raw + 0x3F) & ~0x3F);
        func_00578500(self->lock);
        func_005A609C(self->name, name);
        func_00578168(self, 1, 0, buf, 0x40);
        return *buf;
    }
}
