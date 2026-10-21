/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned int u32; typedef long s64; typedef short s16; typedef unsigned short u16; typedef unsigned char u8;
#define F(p,t,o) (*(t*)((char*)(p)+(o)))
struct Request { char p0[0x14]; int m14; char p18[12]; int m24; char p28[8]; int flags; char p34[12]; };
struct Tone { u8 a,b,c,d,flags; char p5[8]; u8 v; char pE[2]; };
struct Owner { char p0[8]; s64 id; int key; s16 x,y; char p18[12]; int f24; char p28[8]; void *p30; };
extern s64 D_006C8BD0;
extern "C" void *func_00559AC0(void*,u32);
extern "C" void func_0055A8B0(Owner*,void*,int,int,int,void*,Tone*);
extern "C" int func_0055CFE8(Request*,s64);
extern "C" void *func_0055D0B0(Request*,int);
extern "C" void *func_0055D1C0(Request*);
extern "C" void func_0055D5F0(void*,int);
extern "C" void func_0055D630(void*,int);
extern "C" void func_0055DD88(void*,int);
extern "C" void func_00611AA0(Owner *self,int index,int note,int arg3) {
    Request req;
    void *prog=func_00559AC0(self->p30,index);
    if(!prog) return;
    Tone *tone=(Tone*)((char*)prog+8);
    if(!tone) return;
    int delta=note-F(prog,u8,6);
    if(delta<0) return;
    int key=self->key;
    tone+=delta;
    void *voice=0;
    int value,selector;
    if(key!=-1) {
        selector=key;
        func_0055CFE8(&req,self->id);
        voice=func_0055D0B0(&req,selector);
        if(voice) { value=0; goto setup; }
        goto done;
    } else {
        value=tone->a;
        selector=tone->b;
        if(value) {
            func_0055CFE8(&req,D_006C8BD0);
            req.flags|=32;
            req.m24=value;
            voice=func_0055D1C0(&req);
        }
        if(!voice) {
            func_0055CFE8(&req,self->id);
            req.flags|=2;
            req.m14=4;
            voice=func_0055D1C0(&req);
            if(!voice) goto done;
        }
    }
setup:
    {
    F(voice,int,0x30)=2;
    F(voice,int,0x40)=value;
    F(voice,int,0x34)=selector;
    int field=F(self->p30,int,0x10);
    F(voice,u8,0x1f)=1;
    F(voice,int,0x50)=field;
    int x=self->x,y=self->y;
    F(voice,s16,0x64)=x;
    F(voice,s16,0x66)=y;
    F(voice,int,0x70)=tone->v;
    if((tone->flags&128) || self->f24) F(voice,u8,0x25)=1;
    if(tone->flags&32) {func_0055D630(voice,10); func_0055D5F0(voice,127);}
    if(tone->flags&2) {func_0055DD88(voice,tone->c); F(voice,u8,0x26)=1;}
    if(self->key!=-1) { if((u8)(tone->flags&1)) F(voice,u16,0x1a)|=4; }
    func_0055A8B0(self,voice,index,note,arg3,prog,tone);
    }
done:;
}
