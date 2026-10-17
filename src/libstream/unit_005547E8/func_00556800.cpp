/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Config {
    int mode;
    char pad[0x64 - 4];
    int size;
};

extern "C" void func_00556800(Config *c, int mode)
{
    c->mode = mode;
    switch (mode) {
    case 0:
        c->size = 0xC;
        break;
    case 1:
        c->size = 0x18;
        break;
    }
}
