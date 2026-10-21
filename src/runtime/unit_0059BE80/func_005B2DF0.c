/* compiler: ee-gcc2.9-991111 */
struct Slot { int fd,flags,a,b; };
struct Req { int sema; int *result; int size,flags,mode; char name[1024]; int slot; };
struct Sema { int attr,max,init,a,b; char *name; };
extern struct Req D_008882C0;
extern struct Slot D_008897C0[32];
extern char D_008899C0[],D_00888F00[],D_006D26A0[];
extern int D_0065833C,D_00658348;
int func_005B27C8(int);
void func_005B27F8(void);
int func_005B28F0(void),func_005B2AF8(void);
struct Slot *func_005B21D0(void);
int func_005ADCA0(struct Sema *);
int func_005ADCB0(int);
int func_005ADCE0(int),func_005ADCC0(int);
int func_005B2258(void *,int,int,void *,int,void *,int,int,int,int);
int func_005B2DF0(const char *name,int flags,...) {
    struct Req *req=&D_008882C0;
    char *args;
    struct Sema sp;
    int result;
    struct Slot *slot;
    int i, idx, sema, reply, mode;
    func_005B27C8(0);
    if (!D_0065833C) func_005B28F0();
    if (func_005B2AF8()) { func_005B27F8(); return -0x10004; }
    slot=func_005B21D0();
    if (!slot) { func_005B27F8(); return -19; }
    args=(char *)__builtin_next_arg(flags) - (__builtin_args_info(2)>=8 ? 0 : (8-__builtin_args_info(2))*8);
    mode=*(int *)args;
    for (i=0; i<1024; i++) {
        char *dst=(char *)req+i;
        if ((*(dst+20)=name[i])==0) break;
    }
    if (i==1024) req->name[1023]=0;
    idx=slot-D_008897C0;
    req->flags=flags&0x7fffffff;
    req->mode=mode;
    sp.max=1;
    sp.name=D_006D26A0;
    req->slot=idx;
    sp.init=0;
    sema=func_005ADCA0(&sp);
    req->result=&result;
    req->sema=sema;
    req->size=4;
    if (func_005B2258(D_008899C0,0,0,&D_008882C0,0x418,D_00888F00,4,0,0,0)<0) {
        func_005ADCB0(sema); func_005B27F8(); return -11;
    }
    reply=*(int *)((unsigned int)D_00888F00|0x20000000);
    func_005B27F8();
    if (!reply) { func_005ADCB0(sema); return -11; }
    func_005ADCE0(sema);
    func_005ADCB0(sema);
    if (result<0) {
        func_005ADCE0(D_00658348);
        slot->flags=0;
        func_005ADCC0(D_00658348);
        return result;
    }
    reply=idx;
    func_005ADCE0(D_00658348);
    { int old=slot->flags; int fd=result;
    slot->fd=fd;
    slot->flags=old|flags; }
    func_005ADCC0(D_00658348);
    return reply;
}
