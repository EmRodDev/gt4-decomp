/* compiler: ee-gcc2.9-991111 */
/* Stop a running timer, accumulating its elapsed ticks and removing any
 * pending callback from the scheduler. Caller supplies IRQ exclusion.
 * Partial record/state layouts remain provisional. */
struct Timer {
    struct Timer *next;
    unsigned unknown4, id, flags;
    unsigned long long started, elapsed;
};
struct TimerState { char unknown0[0x1C]; int current; };
extern volatile struct TimerState D_006592F0;
extern unsigned long long func_005B8400(void);
extern struct Timer *func_005B8120(struct Timer *);
extern void func_005B7F08(unsigned long long);
int func_005B8828(int handle) {
    struct Timer *timer = (struct Timer *)(((unsigned)handle >> 10) << 6);
    unsigned flags;
    unsigned long long now;
    if (handle < 0 || (handle & 0x3FF) != timer->id) return 0x80008002;
    if (D_006592F0.current == handle) return 0x80000010;
    if (!(timer->flags & 1)) return 0;
    now = func_005B8400();
    flags = timer->flags;
    timer->elapsed += now - timer->started;
    timer->flags = flags & ~1U;
    if (flags & 2) {
        func_005B8120(timer);
        func_005B7F08(now);
    }
    return 1;
}
