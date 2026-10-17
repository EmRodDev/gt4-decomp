/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0054D5C8(void);
extern "C" void func_00563258(unsigned int);

extern "C" void func_00562D20(void)
{
    func_0054D5C8();
    unsigned int low = *(volatile unsigned int *)0x10002020 & 0x7F;
    return func_00563258(((low + 7) & 0xF8) - low);
}
