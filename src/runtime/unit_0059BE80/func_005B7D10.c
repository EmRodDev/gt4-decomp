/* compiler: ee-gcc2.9-991111 */
/* Shut down the timer service only when no timer records remain allocated.
 * Preserve the original interrupt-handler removal and hardware-reset paths.
 * State names and the unexposed tail of the layout remain provisional. */
struct TimerState {
    unsigned long long ticks;
    int interrupt_handler;
    unsigned generation;
    volatile int allocated;
};
extern struct TimerState D_006592F0;
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern int func_005AD9A0(int, int);
extern int func_005AE780(int);
extern void func_005B7B98(unsigned);
extern void func_005B7B88(unsigned);
int func_005B7D10(void) {
    int interrupts;
    if (D_006592F0.interrupt_handler < 0) return 0x80008001;
    if (D_006592F0.allocated) return 0x80000010;
    interrupts = func_005B72A8();
    if (!func_005AD9A0(11, D_006592F0.interrupt_handler)) {
        func_005AE780(11);
        func_005B7B98(0xC00);
        func_005B7B88(0);
    }
    D_006592F0.ticks = 0;
    D_006592F0.interrupt_handler = -1;
    if (interrupts) func_005B72F8();
    return 0;
}
