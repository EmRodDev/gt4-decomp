/* compiler: ee-gcc2.9-991111 */
/* Same worker state as 00586DA0 and 00587BB0. */
struct Driver { int thread, priority, done_semaphore, idle_semaphore, request; };
extern struct Driver D_0087E180;
extern int func_005ADCE0(int);
extern int func_005ADAF0(int);
extern int func_005ADAB0(int);
extern int func_005ADCB0(int);
int func_00586EF0(void) {
    if(func_005ADCE0(D_0087E180.done_semaphore)<0) return 0x81058003;
    func_005ADAF0(D_0087E180.thread);
    func_005ADAB0(D_0087E180.thread);
    func_005ADCB0(D_0087E180.done_semaphore);
    func_005ADCB0(D_0087E180.idle_semaphore);
    D_0087E180.thread=-1;
    D_0087E180.done_semaphore=-1;
    D_0087E180.idle_semaphore=-1;
    return 0;
}
