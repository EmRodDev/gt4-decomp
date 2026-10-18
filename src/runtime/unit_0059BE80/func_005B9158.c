/* compiler: ee-gcc2.9-991111 */
/* Validate the alarm handle's generation, release its timer and return the
 * record to the shared pool under interrupt exclusion. Layout provisional. */
typedef unsigned long long (*TimerCallback)(int, unsigned long long,
    unsigned long long, void *);
struct Alarm {
    struct Alarm *next;
    volatile int timer;
    TimerCallback callback;
    void *argument;
};
extern struct Alarm *volatile D_0088C340;
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern int func_005B8628(int);
int func_005B9158(int handle) {
    struct Alarm *alarm = (struct Alarm *)(((unsigned)handle >> 8) << 4);
    int interrupts = func_005B72A8();
    if (handle < 0 || ((handle ^ alarm->timer) & 255)) {
        if (interrupts) func_005B72F8();
        return 0x80008002;
    }
    func_005B8628(alarm->timer);
    {
        struct Alarm *previous = D_0088C340;
        D_0088C340 = alarm;
        alarm->next = previous;
        alarm->timer = 0;
    }
    if (interrupts) func_005B72F8();
    return 0;
}
