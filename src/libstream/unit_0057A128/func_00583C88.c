/* compiler: ee-gcc2.9-991111 */
/* ELOADP driver teardown: release synchronization, worker and stack resources,
 * then unregister its interrupt handler while CPU interrupts are disabled. */
extern int D_00875868, D_0087586C, D_00875870;
extern void *D_00875864;
extern void func_005ADCB0(int);
extern void func_005ADAB0(int);
extern void func_0058B140(void *);
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern int func_005AD9A0(int, int);
extern int func_005AE780(int);
void func_00583C88(void)
{
    int interrupts_enabled;
    int unregister_result;
    func_005ADCB0(D_00875868);
    D_00875868 = -1;
    func_005ADAB0(D_0087586C);
    D_0087586C = -1;
    if (D_00875864) {
        func_0058B140(D_00875864);
        D_00875864 = 0;
    }
    interrupts_enabled = func_005B72A8();
    unregister_result = func_005AD9A0(3, D_00875870);
    D_00875870 = -1;
    if (unregister_result == 0)
        func_005AE780(3);
    if (interrupts_enabled)
        func_005B72F8();
}
