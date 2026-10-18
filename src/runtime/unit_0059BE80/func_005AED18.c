/* compiler: ee-gcc2.9-991111 */
typedef struct {
    int count, max_count, initial_count, waiting_threads;
    unsigned int attributes;
    const char *option;
} SemaParameters;
extern const char D_006D2378[];
extern int func_005ADCA0(SemaParameters *);
extern int func_005ADCB0(int);
extern int func_005ADCE0(int);
extern unsigned long func_005B8D88(unsigned int, unsigned int);
extern int func_005B8F38(unsigned long, int (*)(int, int, int, int), int);
extern int func_005AEF58(int, int, int, int);

/* Delay the current thread using an alarm that signals a temporary semaphore.
 * No alarm can wake the thread when CPU interrupts are disabled. */
int func_005AED18(unsigned int microseconds)
{
    unsigned int status;
    SemaParameters semaphore;
    int semaphore_id, alarm_id;
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    if (!(status & 0x10000))
        return (int)0x80008008U;
    semaphore.max_count = 1;
    semaphore.option = D_006D2378;
    semaphore.initial_count = 0;
    semaphore_id = func_005ADCA0(&semaphore);
    if (semaphore_id < 0)
        return (int)0x80008003U;
    alarm_id = func_005B8F38(func_005B8D88(0, microseconds),
                           func_005AEF58, semaphore_id);
    if (alarm_id < 0) {
        func_005ADCB0(semaphore_id);
        return alarm_id;
    }
    func_005ADCE0(semaphore_id);
    func_005ADCB0(semaphore_id);
    return 0;
}
