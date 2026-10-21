/* compiler: ee-gcc2.9-as296 */
extern int D_00655ED4;
extern volatile int D_00655F20;
extern volatile int D_00655EE0, D_00655EE8, D_00655EEC, D_00655EF0;
extern void func_005ADCC0(int);
extern int func_005ADCB0(int);
extern int func_005B72A8(void);
extern void func_005B0C28(int);
extern int func_005B72F8(void);

void func_005802C0(void)
{
    int state;

    if (D_00655ED4 != 0) {
        D_00655F20 = -1;
        func_005ADCC0(D_00655EE0);
    }
    func_005ADCB0(D_00655EE8);
    func_005ADCB0(D_00655EEC);
    func_005ADCB0(D_00655EF0);
    func_005ADCB0(D_00655EE0);
    state = func_005B72A8();
    func_005B0C28(0x80000012);
    if (state != 0)
        func_005B72F8();
}
