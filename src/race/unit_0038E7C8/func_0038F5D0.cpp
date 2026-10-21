/* compiler: ee-gcc2.96-no-strict-aliasing */
/* One GS draw pass over a list of up to six 40-byte records (count at +0x1D0 region, array at +0x140): pushes
 * render state, sets an orthographic-looking frustum (+-0.9, +-1), then in the first loop transforms each record's
 * vector a with func_004A7AA8, normalises it (the rsqrt.s inline asm gives 1/sqrt(x*x+y*y+z*z), the same instruction
 * the original used) and stores the scale g/|a| in w; the second loop hands each record's second vector b and its
 * float f to func_0038F408. Finally restores the state. What is being drawn is purpose unknown (inferred: a
 * per-light or per-marker screen overlay, from the six-entry vector list only). */
struct Vec { float x,y,z,w; };
struct Rec { Vec a; Vec b; float f, g; };
struct Self { char pad[0x140]; Rec arr[6]; char p[4]; int count; };
struct VE { short delta; short pad; void (*fn)(void *,float); };
struct Obj { VE *vt; };
extern "C" void func_00105670(void *);
extern "C" void func_001056A0(void *);
extern "C" void func_0038F408(void *,void *,float) throw();
extern "C" void func_0049BBB0(int,int,int,int,int);
extern "C" int func_0049BBF0();
extern "C" void func_0049FE28();
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int,float);
extern "C" void func_004A2980(int);
extern "C" void func_004A3998(int,float);
extern "C" void func_004A4910();
extern "C" void RaceEntryCar__update(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688();
extern "C" void func_004A5A90(float,float,float,float,float,float);
extern "C" void func_004A7454();
extern "C" void func_004A7890(float,float,float);
extern "C" void func_004A7AA8(void *,void *);
extern "C" void func_004AB040(int);
extern "C" void func_0038F5D0(Self *self,void *arg1,void *arg2,Obj *obj) {
    Vec transformed[6];
    int entryIndex=0;
    pglPushAttrib(0x8c7);
    RaceEntryCar__update(1); func_004A53F8(); func_004A7454();
    func_004A5A90(-0.9f,0.9f,-0.9f,0.9f,-1.0f,1.0f);
    RaceEntryCar__update(0); func_004A53F8(); func_004A7454();
    func_004A7890(-1.0f,1.0f,-1.0f);
    VE *e=obj->vt+3;
    e->fn((char *)obj+e->delta,0.0f);
    func_00105670(arg2); func_001056A0(arg1);
    func_004A3998(4,1.0f);func_0049FE28();func_004A2980(0xffffff);
    func_004AB040(5);func_004AB040(4);func_004AB040(8);func_004AB040(2);
    func_004A1638(6);func_004A2808(0x44,0.0f);func_004AB040(15);func_004A1638(17);
    if(entryIndex<self->count) {
    float *fieldG=&self->arr[0].g;
    Vec *sourceVec=&self->arr[0].a;
    Vec *destVec=transformed;
    for (;entryIndex<self->count;entryIndex++,fieldG=(float *)((char *)fieldG+40),sourceVec=(Vec *)((char *)sourceVec+40),destVec++) {
        func_004A7AA8(destVec,sourceVec);
        float x=destVec->x,y=destVec->y,z=destVec->z;
        float lengthSq=x*x+y*y+z*z;
        float fieldG2=*fieldG;
        float invLength;
        __asm__("rsqrt.s %0, %1, %2" : "=f"(invLength) : "f"(1.0f),"f"(lengthSq));
        destVec->x=x*invLength;destVec->y=y*invLength;destVec->z=z*invLength;
        destVec->w=fieldG2*invLength;
    }
    }
    entryIndex=0;
    func_004A7454();func_0049BBB0(4,0x32,0x31,0x27,0x32);
    if(entryIndex<self->count) {
    float *fieldG=&self->arr[0].f;Vec *sourceVec=&self->arr[0].b;Vec *destVec=transformed;
    for(;entryIndex<self->count;entryIndex++,destVec++,sourceVec=(Vec *)((char *)sourceVec+40),fieldG=(float *)((char *)fieldG+40))
        func_0038F408(destVec,sourceVec,*fieldG);
    }
    func_0049BBF0();func_004A2980(-1);func_004AB040(6);func_004A1638(15);
    RaceEntryCar__update(1);func_004A5400();RaceEntryCar__update(0);func_004A5400();
    func_004A5688();func_0049FE28();func_004A4910();
}
