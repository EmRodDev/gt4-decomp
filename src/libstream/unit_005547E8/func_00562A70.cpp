/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void func_0054D900(void);
int func_0054D930(void);
void func_00562B20(char *dst, char *src, int bytes);

int func_00562A70(char *dst, char *src, int total)
{
    func_0054D900();
    int rest = total % 0x300;
    int chunks = total / 0x300;
    if (chunks > 0) do {
        chunks--;
        func_00562B20(dst, src, 0x300);
        dst += 0xC0000;
        src += 0x48000;
    } while (chunks != 0);
    if (rest)
        func_00562B20(dst, src, rest);
    return func_0054D930();
}
}
