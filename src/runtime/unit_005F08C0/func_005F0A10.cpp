/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta,index; int (*fn)(void *); };
struct Obj { int word; VEntry *vt; };
struct Vec { int alloc; char *begin, *end, *cap; };
struct Data { int alloc; Obj **begin; char pad[12]; Obj **list; char pad18[8]; int count; };
struct Owner { char pad[0x24]; char *p24; char pad28[4]; Data *data; };
struct Arg { char pad[8]; Vec vec; int index; };
extern "C" void func_002F3478(void *, void *, void *);
extern "C" void func_00301228(void *, int);
extern "C" void *func_00301828(void *, void *, void *);
extern "C" void func_00307728(void *, int);
extern "C" int func_00307D90(void *, void *, void *, void *);
extern "C" void func_00309378(void *, int);
extern "C" void func_0030BB18(void *);
extern "C" void *func_0030F628(void *, void *, int);
extern "C" int func_0030F648(void *);
extern "C" void func_00321E38(void *, void *, void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_00323D08(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline int call98(Obj *o) { VEntry *e=(VEntry *)((char *)o->vt+0x98); return e->fn((char *)o+e->delta); }
static inline int call58(Obj *o) { VEntry *e=(VEntry *)((char *)o->vt+0x58); return e->fn((char *)o+e->delta); }
static inline int call50(Obj *o) { VEntry *e=(VEntry *)((char *)o->vt+0x50); return e->fn((char *)o+e->delta); }
#define ASSIGN(dst,src) if ((void *)(dst)!=(void *)(src)) { value=(int)*(Obj **)(src); if(value) func_003285A8((void *)value); scratch=(int)*(Obj **)(dst); if(scratch) func_003285F8((void *)scratch); *(Obj **)(dst)=(Obj *)value; }
extern "C" void func_005F0A10(Owner *self, Arg *arg) {
    Obj *buf[12], *h30[4], *h40[4], *h50[4], *h60[4], *h70[4];
    int value;
    int scratch;
    void *work;
    Obj **dest;
    Obj **p40, **p50, **p60;
    value=(int)(self->data->begin+arg->index);
    if(*(Obj **)value && call98(*(Obj **)value)) {
        work=self->data;
        scratch=((Data *)work)->count; dest=((Data *)work)->list+scratch;
        ASSIGN(dest,(void *)value);
        scratch=((Data *)work)->count; ((Data *)work)->count=scratch+1;
        return;
    }
    work=&arg->vec;
    if((unsigned)((((Vec *)work)->end-((Vec *)work)->begin)>>2) < 2) {
        dest=h30;
        void *v=work;
        work=self->data; value=arg->index;
        func_0030F628(dest,v,0);
        p40=h40;
        value=value*4;
        func_0030BB18(p40);
        func_00301828(buf,dest,p40);
        work=(char *)((Data *)work)->begin+value;
        ASSIGN(work,buf);
        self=(Owner *)self->data;
        scratch=((Data *)self)->count; dest=((Data *)self)->list+scratch;
        ASSIGN(dest,work);
        scratch=((Data *)self)->count; ((Data *)self)->count=scratch+1;
        func_00301228(buf,2);
        func_00309378(p40,2);
        return;
    }
    func_00323D08(buf);
    func_00321E38(self,buf,work);
    p50=h50;
    func_0030BB18(p50);
    if(call58(buf[0])) {
        Vec *v=(Vec *)(self->p24+0x10);
        scratch=(int)((char *)self->data->begin+(((int)(v->end-v->begin)>>2)*4));
        ASSIGN(p50,scratch);
        if(func_0030F648(work)==1) {
            value=call50(p50[0]);
            p60=h60;
            func_0030F628(p60,work,0);
            func_002F3478((void *)value,buf,p60);
        }
    }
    dest=h70;
    void *v=work;
    work=self->data; value=arg->index;
    func_0030F628(dest,v,0);
    p60=h60;
    func_00307D90(p60,dest,p50,buf);
    value=value*4;
    work=(char *)((Data *)work)->begin+value;
    ASSIGN(work,p60);
    self=(Owner *)self->data;
    scratch=((Data *)self)->count; dest=((Data *)self)->list+scratch;
    ASSIGN(dest,work);
    scratch=((Data *)self)->count; ((Data *)self)->count=scratch+1;
    func_00307728(p60,2);
    func_00309378(p50,2);
    func_00323B60(buf,2);
}
