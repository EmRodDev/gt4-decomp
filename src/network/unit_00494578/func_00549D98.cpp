/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Req { int cmd,id; int data[16]; int a,b,c; void (*cb)(int,int); int arg; };
struct Node { Node *next; int id,result; };
struct Obj { char pad[0x64]; int stop; char pad2[0x3e4-0x68]; Req src,dst; int busy,result; Node *head; };
extern "C" Obj *D_0064C3E4;
extern "C" {
int func_005B72A8();
void func_00574EB0(void *);
void func_00576788(void *);
void func_005767C0(void *);
void func_00549C40(void *) throw();
int func_005ADBD0(int);
int func_0054AE70(int,void *,int,int);
int func_0054AEF8(int,void *);
int func_0054B020(int,void *);
int func_0054B088(int);
int func_0054B1A8(int,void *,int,int,int);
int func_0054B4F8(int,void *,int);
int func_0054B630(int,void *);
int func_0054B698(int,void *,int,int,int);
int func_0054B8C0(int,void *,int);
int func_0054B9F0(int,void *,int,int);
int func_0054BB30(int);
int func_0054BC50(int,void *,int,int,int);
}
extern "C" void func_00549D98(Obj *p) {
void (*cb)(int,int); int arg,r;
for (;;) {
void *event=(char *)p+4;
int *stop=&p->stop;
func_00574EB0(event);
if(*stop) break;
Req *q=&p->dst;
int enabled=func_005B72A8();
*q=p->src;
p->src.cmd=0;
if(enabled) __asm__ volatile("ei");
switch(q->cmd) {
case 1:
func_00576788((char *)D_0064C3E4+0x34);
func_00549C40((char *)p+0x68);
func_005767C0((char *)D_0064C3E4+0x34);
break;
case 2:
cb=q->cb; arg=q->arg; r=func_0054AE70(q->id,q->data,q->a,q->c);
p->result=r;
if(cb) cb(arg,r);
break;
case 3:
cb=q->cb; arg=q->arg; r=func_0054AEF8(q->id,q->data);
p->result=r;
if(cb) cb(arg,r);
break;
case 4:
cb=q->cb; arg=q->arg; r=func_0054B020(q->id,q->data);
p->result=r;
if(cb) cb(arg,r);
break;
case 5:
cb=q->cb; arg=q->arg; r=func_0054B088(q->id);
p->result=r;
if(cb) cb(arg,r);
break;
case 6:
cb=q->cb; arg=q->arg; r=func_0054B1A8(q->id,q->data,q->a,q->b,q->c);
p->result=r;
if(cb) cb(arg,r);
break;
case 7:
cb=q->cb; arg=q->arg; r=func_0054B4F8(q->id,q->data,q->a);
p->result=r;
if(cb) cb(arg,r);
break;
case 8:
cb=q->cb; arg=q->arg; r=func_0054B630(q->id,q->data);
p->result=r;
if(cb) cb(arg,r);
break;
case 9: {
int result=func_0054B698(q->id,q->data,q->a,q->b,q->c);
void (*callback)(int,int)=q->cb;
int value=0;
int context=q->arg;
if(result<0) value=-result;
p->result=value;
if(callback) callback(context,value);
break;
}
case 10:
cb=q->cb; arg=q->arg; r=func_0054B8C0(q->id,q->data,q->a);
p->result=r;
if(cb) cb(arg,r);
break;
case 11:
cb=q->cb; arg=q->arg; r=func_0054B9F0(q->id,q->data,q->a,q->b);
p->result=r;
if(cb) cb(arg,r);
break;
case 13:
cb=q->cb; arg=q->arg; r=func_0054BB30(q->id);
p->result=r;
if(cb) cb(arg,r);
break;
case 12:
cb=q->cb; arg=q->arg; r=func_0054BC50(q->id,q->data,q->a,q->b,q->c);
p->result=r;
if(cb) cb(arg,r);
break;
case 0: default: break;
}
enabled=func_005B72A8();
Node *n=p->head;
p->busy=0; p->head=0;
if(enabled) __asm__ volatile("ei");
while(n) {
n->result=p->result;
int id=n->id;
n=n->next;
func_005ADBD0(id);
}
}
}
