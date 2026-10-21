/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; int id; int value; int zero; int result; };
struct Lock { Node *head; Node *tail; char pad[16]; int owner; int priority; int count; int level; };
extern "C" int func_005ADB90();
extern "C" int func_005ADB30(int,int);
extern "C" int func_005B72A8();
extern "C" int func_00576550(Lock *self, int flag) {
    int prior=-1;
    int id=func_005ADB90();
    if(flag) prior=func_005ADB30(id,1);
    int got=1;
    int irq=func_005B72A8();
    int old=self->count;
    if(old==0) {
        self->owner=id;
        self->count=1;
    } else if(id==self->owner) {
        self->count=old+1;
    } else {
        got=0;
    }
    if(flag && got && self->level<0) {
        self->level=old;
        self->priority=prior;
    }
    if(irq) __asm__ volatile("ei");
    if(flag) {
        if(!got) func_005ADB30(id,prior);
    }
    return got;
}
