/* compiler: ee-gcc2.9-991111 */
extern void func_005AE0D0(int, void *);
void func_005B9668(int a, int b, int c) {
    int buf[8];
    buf[1] = b;
    buf[0] = a & 0xff;
    buf[2] = c;
    func_005AE0D0(0x20, buf);
}
