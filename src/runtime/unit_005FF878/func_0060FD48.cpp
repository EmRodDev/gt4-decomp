/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { long data[8]; };
extern Block D_0086CB00, D_0086CB40;
extern "C" void func_00578500(int);
extern "C" int func_00578168(void *, int, int, void *, int);
extern "C" int func_005B72A8();
extern "C" void func_0060FD48(int *self) {
    func_00578500(self[0]);
    func_00578168(self, 8, 0, &D_0086CB00, 0x40);
    int intr = func_005B72A8();
    D_0086CB40 = D_0086CB00;
    if (intr) __asm__ volatile("ei");
}
