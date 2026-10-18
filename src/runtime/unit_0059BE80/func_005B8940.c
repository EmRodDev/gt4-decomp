/* compiler: ee-gcc2.9-991111 */
/* Replace a timer's accumulated ticks and return its previous running total.
 * Handle validation and all updates occur under interrupt exclusion.
 * Record/state layouts and names remain provisional. */
struct Timer {
    struct Timer *next;
    unsigned unknown4, id, flags;
    unsigned long long started, elapsed;
};
struct TimerState { char unknown0[0x1C]; int current; };
extern volatile struct TimerState D_006592F0;
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern unsigned long long func_005B8400(void);
unsigned long long func_005B8940(int handle, unsigned long long replacement) {
    struct Timer *timer = (struct Timer *)(((unsigned)handle >> 10) << 6);
    int interrupts = func_005B72A8();
    unsigned long long previous;
    if (handle < 0 || (handle & 0x3FF) != timer->id ||
        D_006592F0.current == handle) {
        if (interrupts) func_005B72F8();
        return -1;
    }
    previous = timer->elapsed;
    if (timer->flags & 1) {
        unsigned long long now = func_005B8400();
        previous += now - timer->started;
        timer->started = now;
        timer->elapsed = replacement;
    } else {
        timer->elapsed = replacement;
    }
    if (interrupts) func_005B72F8();
    return previous;
}
