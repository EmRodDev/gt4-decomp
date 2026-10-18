/* compiler: ee-gcc2.9-991111 */
/* Provisional views of the SIF transaction and the caller's completion record. */
struct Completion;
struct Request {
    int unknown0[5];
    struct Request *self;
    int token;
    struct Completion *completion;
    int argument0, argument1, argument2;
};
struct Completion { struct Request *request; int token; int semaphore; };
struct Semaphore { int current_count, maximum_count, initial_count, waiters; unsigned attributes; const char *tag; };
extern char D_00888240;
extern const char D_006D25C8;
extern struct Request *func_005B11F0(void *);
extern void func_005B1298(struct Request *);
extern int func_005ADCA0(struct Semaphore *);
extern int func_005ADCB0(int);
extern int func_005ADCE0(int);
extern int func_005B0DB0(int, struct Request *, int, int, int, int);
int func_005B1508(struct Completion *completion, int arg0, int arg1, int arg2, int flags) {
    struct Semaphore semaphore;
    struct Request *request=func_005B11F0(&D_00888240);
    if(!request) return -1;
    completion->request=request;
    completion->token=request->token;
    request->argument0=arg0;
    request->argument1=arg1;
    request->argument2=arg2;
    request->self=request;
    request->completion=completion;
    if(!(flags&1)) {
        semaphore.maximum_count=1;
        semaphore.tag=&D_006D25C8;
        semaphore.initial_count=0;
        completion->semaphore=func_005ADCA0(&semaphore);
        if(completion->semaphore<0) {func_005B1298(request); return -3;}
        if(!func_005B0DB0(0x8000000C,request,64,0,0,0)) {
            func_005B1298(request);
            func_005ADCB0(completion->semaphore);
            return -2;
        }
        func_005ADCE0(completion->semaphore);
        func_005ADCB0(completion->semaphore);
        return 0;
    } else {
        completion->semaphore=-1;
        if(!func_005B0DB0(0x8000000C,request,64,0,0,0)) {
            func_005B1298(request);return -2;
        }
        return 0;
    }
}
