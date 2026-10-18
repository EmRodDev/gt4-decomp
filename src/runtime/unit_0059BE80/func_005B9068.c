/* compiler: ee-gcc2.9-991111 */
/* Allocate an alarm record using the timer primitives without IRQ wrapping.
 * Roll back the record on timer-allocation failure. Handle encoding combines
 * the record address with the timer generation bits; names are provisional. */
/* The dispatcher forwards four registers, including two 64-bit timer values.
 * Their precise meaning and the original callback typedef remain provisional. */
typedef unsigned long long (*TimerCallback)(int, unsigned long long,
    unsigned long long, void *);
struct Alarm {
    struct Alarm *next;
    volatile int timer;
    TimerCallback callback;
    void *argument;
};
extern struct Alarm *volatile D_0088C340;
static inline struct Alarm *take_record(void) {
    struct Alarm *record=D_0088C340;
    if(record) D_0088C340=record->next;
    return record;
}
extern int func_005B84D0(void);
extern int func_005B8B68(int, unsigned long long, TimerCallback, void *);
extern unsigned long long func_005B8ED8(int, unsigned long long, unsigned long long, void *);
extern int func_005B8728(int);
int func_005B9068(unsigned long long delay, TimerCallback callback, void *argument) {
    struct Alarm *alarm;
    int timer;
    if(!callback) return 0x80000016;
    alarm=take_record();
    if(!alarm) {
        return 0x80008005;
    }
    timer=func_005B84D0();
    if(timer<0) {
        struct Alarm *previous=D_0088C340;
        D_0088C340=alarm;
        alarm->next=previous;
        alarm->timer=0;
        return timer;
    }
    alarm->callback=callback;
    alarm->argument=argument;
    alarm->timer=timer;
    func_005B8B68(timer,delay,func_005B8ED8,alarm);
    func_005B8728(timer);
    return ((unsigned)alarm<<4)|(timer&0xFE)|1;
}
