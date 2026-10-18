/* compiler: ee-gcc2.9-991111 */
/* SDK parameter layouts inferred from the fields passed to CreateSema and
 * CreateThread. Fields not initialized by the original are left untouched. */
typedef struct {
    int count, max_count, initial_count, waiting_threads;
    unsigned int attributes;
    const char *option;
} SemaParameters;
typedef struct {
    int status;
    void (*entry)(void);
    void *stack;
    int stack_size;
    void *global_pointer;
    int priority, initial_priority;
    unsigned int attributes;
    const char *option;
} ThreadParameters;
extern int D_006582A8, D_00885EE0;
extern int D_00885EE8[2];
extern char D_00885AE0[], D_006DDDF0[];
extern const char D_006D2360[];
extern void func_005AE9A0(void);
extern int func_005ADCA0(SemaParameters *);
extern int func_005ADCB0(int);
extern int func_005ADAA0(ThreadParameters *);
extern int func_005AEDE0(int, void *);
extern int func_005ADB90(void);
extern int func_005ADB30(int, int);

/* Start the kernel's top worker once, releasing its semaphore if thread
 * creation fails. The two-word start message is zero-initialized. */
int func_005AEA78(void)
{
    ThreadParameters thread;
    SemaParameters semaphore;
    if (D_006582A8 > 0)
        return -1;
    semaphore.max_count = 255;
    semaphore.initial_count = 0;
    semaphore.option = D_006D2360;
    D_00885EE0 = func_005ADCA0(&semaphore);
    if (D_00885EE0 < 0)
        return -1;
    thread.entry = func_005AE9A0;
    thread.stack = D_00885AE0;
    thread.stack_size = 0x400;
    thread.global_pointer = D_006DDDF0;
    thread.option = D_006D2360;
    thread.priority = 0;
    D_006582A8 = func_005ADAA0(&thread);
    if (D_006582A8 < 0) {
        func_005ADCB0(D_00885EE0);
        return -1;
    }
    D_00885EE8[0] = 0;
    D_00885EE8[1] = 0;
    func_005AEDE0(D_006582A8, D_00885EE8);
    func_005ADB30(func_005ADB90(), 1);
    return D_006582A8;
}
