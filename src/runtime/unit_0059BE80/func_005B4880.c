/* compiler: ee-gcc2.9-991111 */
/* Submit operation 11 for a live descriptor and wait for its completion word.
 * Partial packet/descriptor layouts are provisional. The original submission
 * error path waits and unlocks without deleting the semaphore. */
struct Entry { int handle, occupied, unknown8, unknownC; };
struct Semaphore { int current, maximum, initial, waiters; unsigned attributes; const char *tag; };
struct Request { int semaphore; int *result; int result_size, handle; void *output; char unknown14[12]; };
extern struct Request D_008882C0;
extern int D_0065833C, D_00888F00;
extern char D_008899C0;
extern const char D_006D27C0[];
extern struct Entry *func_005B2348(unsigned);
extern int func_005B27C8(int);
extern void func_005B27F8(void);
extern int func_005ADCA0(struct Semaphore *);
extern int func_005ADCB0(int);
extern int func_005ADCE0(int);
extern unsigned func_005B2258(void *, int, int, void *, int, void *, int,
    void (*)(void *), void *, int);
int func_005B4880(unsigned descriptor, void *output) {
    struct Semaphore parameters;
    int result, semaphore, accepted, handle;
    struct Request *request=&D_008882C0;
    struct Entry *entry=func_005B2348(descriptor);
    func_005B27C8(11);
    if(!D_0065833C || !entry || !entry->occupied) {
        func_005B27F8();return -9;
    }
    handle=entry->handle;
    request->handle=handle;
    request->output=output;
    parameters.maximum=1;
    parameters.tag=D_006D27C0;
    parameters.initial=0;
    semaphore=func_005ADCA0(&parameters);
    request->semaphore=semaphore;
    request->result=&result;
    request->result_size=4;
    if((int)func_005B2258(&D_008899C0,11,0,request,32,&D_00888F00,4,0,0,0)<0) {
        func_005ADCE0(semaphore);
        func_005B27F8();return -11;
    }
    accepted=*(int *)((unsigned)&D_00888F00|0x20000000);
    func_005B27F8();
    if(!accepted) {func_005ADCB0(semaphore);return -11;}
    func_005ADCE0(semaphore);
    func_005ADCB0(semaphore);
    return result;
}
