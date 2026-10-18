/* compiler: ee-gcc2.9-991111 */
/* SDK parameter layouts inferred from matching callers. Unspecified fields
 * retain the original uninitialized state. The worker signals done or idle. */
struct Semaphore {
    int current_count, maximum_count, initial_count, waiters;
    unsigned attributes;
    void *tag;
};
struct Thread {
    int status;
    void (*entry)(void *);
    void *stack;
    int stack_size, global_pointer, priority, current_priority;
    unsigned attributes;
    void *tag;
};
struct Driver { int thread, priority, done_semaphore, idle_semaphore, request; };
extern struct Driver D_0087E180;
extern char D_006CE760, D_006CE778, D_006CE790, D_00876180;
extern void func_00587BB0(void *);
extern void func_00589BF8(int);
extern int func_005ADCA0(struct Semaphore *);
extern int func_005ADCB0(int);
extern int func_005ADAA0(struct Thread *);
extern int func_005AEDE0(int, void *);
int func_00586DA0(int priority) {
    struct Thread thread;
    struct Semaphore semaphore;
    D_0087E180.priority=priority;
    D_0087E180.request=0;
    func_00589BF8(2);
    semaphore.initial_count=1;
    semaphore.tag=&D_006CE760;
    semaphore.maximum_count=1;
    D_0087E180.done_semaphore=func_005ADCA0(&semaphore);
    if(D_0087E180.done_semaphore<0) return 0x81058003;
    semaphore.maximum_count=1;
    semaphore.tag=&D_006CE778;
    semaphore.initial_count=0;
    D_0087E180.idle_semaphore=func_005ADCA0(&semaphore);
    if(D_0087E180.idle_semaphore<0) {
        func_005ADCB0(D_0087E180.done_semaphore);
        D_0087E180.done_semaphore=-1;
        return 0x81058003;
    }
    thread.entry=func_00587BB0;
    thread.stack=&D_00876180;
    thread.stack_size=0x8000;
    thread.priority=priority;
    thread.tag=&D_006CE790;
    thread.global_pointer=0;
    D_0087E180.thread=func_005ADAA0(&thread);
    if(D_0087E180.thread<0) {
        func_005ADCB0(D_0087E180.done_semaphore);
        func_005ADCB0(D_0087E180.idle_semaphore);
        D_0087E180.done_semaphore=-1;
        D_0087E180.idle_semaphore=-1;
        return 0x81058004;
    }
    func_005AEDE0(D_0087E180.thread,0);
    return 0;
}
