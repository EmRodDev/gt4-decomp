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
extern void *D_00875864;
extern int D_00875868, D_0087586C, D_00875870;
extern const char D_006CE670[], D_006CE680[];
extern void *func_0058B138(int, unsigned int, unsigned int);
extern int func_005ADCA0(SemaParameters *);
extern int func_005ADAA0(ThreadParameters *);
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern int func_005AD990(int, void (*)(void), int, int);
extern int func_005AE7E8(int);
extern void func_00583B98(void);
extern void func_00583B88(void);
void func_00583BA0(void)
{
    ThreadParameters thread;
    SemaParameters semaphore;
    int interrupts_enabled;
    D_00875864 = func_0058B138(4, 0xA000, 0x100);
    if (!D_00875864)
        return;
    semaphore.max_count = 1;
    semaphore.option = D_006CE670;
    semaphore.initial_count = 0;
    D_00875868 = func_005ADCA0(&semaphore);
    thread.entry = func_00583B98;
    thread.stack = D_00875864;
    thread.stack_size = 0x400;
    thread.priority = 0x7E;
    thread.option = D_006CE680;
    thread.global_pointer = 0;
    D_0087586C = func_005ADAA0(&thread);
    interrupts_enabled = func_005B72A8();
    D_00875870 = func_005AD990(3, func_00583B88, 0, 0);
    func_005AE7E8(3);
    if (interrupts_enabled)
        func_005B72F8();
}
