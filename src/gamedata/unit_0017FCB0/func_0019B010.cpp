typedef int s32;
typedef unsigned int u32;
struct V { char pad0[4]; char *b4; char *e8; char padC[4]; s32 f10,f14,f18,f1C,f20; float f24; };
struct Obj { char pad[0xC4]; V v; V *out; s32 fF0; };
struct It { u32 p; char pad[12]; };
struct Pair { s32 a,b; char pad[8]; };
struct Decoder { char pad[0xDD4]; s32 w,h; char tail[0x11e0-0xDDC]; };
extern "C" s32 func_00575D00(void);
extern "C" void *func_005A47D4(void *,const void *,u32) throw();
extern "C" void func_005CD968(void *);
extern "C" void func_005CD9E8(void *,char *,u32,char *);
extern "C" int func_0046CC38(void *);
extern "C" int func_0046CD48(void *,int);
extern "C" void func_0046CEE8(void *,Pair *,Pair *);
extern "C" void func_0046CFA0(void *,int);
extern "C" int func_0046D960(void *);
extern "C" int func_0046D100(void *);
extern "C" void func_00331520(void *,int,int);
static inline void resize(V *v, u32 n, char *fill, It *iter) {
            char *e = v->e8;
            char *b = v->b4;
            u32 used = e - b;
            if (used > n) {
                char *mid = v->b4 + n;
                func_005A47D4(mid,e,0);
                char *last = v->e8;
                iter->p = (u32)mid;
                v->e8 = last - (e - mid);
            } else {
                func_005CD9E8(v,e,n-used,fill);
            }
}
static inline s32 set_dimensions(V *v, int width, int height, int channels) {
    v->f24 = (float)width / (float)height;
    s32 oldheight = v->f14;
    s32 total = v->f10 * v->f20;
    total = total * oldheight;
    s32 t2 = v->f18 * v->f1C;
    total = total * t2;
    v->f10 = width;
    v->f14 = height;
    v->f18 = 1;
    v->f1C = 1;
    v->f20 = channels;
    return total;
}
extern "C" void func_0019B010(Obj *self,int arg1,int arg2,int arg3) {
    It iter;
    Pair input;
    Pair data;
    Decoder dec;
    char fill0,fill1,fill2;
    V *v = &self->v;
    self->out = 0;
    self->fF0 = 0;
    if (arg3) {

    u32 n = 0x384000;
    v->f24 = 0.75f;
    s32 oldheight = v->f14;
    s32 total = v->f10 * v->f20;
    total = total * oldheight;
    s32 t2 = v->f18 * v->f1C;
    total = total * t2;
    v->f10 = 960;
    v->f14 = 1280;
    v->f18 = 1;
    v->f1C = 1;
    v->f20 = 3;
    u32 avail = func_00575D00();
    if (total != n) {
        func_005CD968(v);
        if (!(avail < n)) {
            fill0 = 0;
            resize(v,n,&fill0,&iter);
        }
    }

    } else {

    u32 n = 0x384000;
    v->f24 = 0x1.555554p+0f;
    s32 oldheight = v->f14;
    s32 total = v->f10 * v->f20;
    total = total * oldheight;
    s32 t2 = v->f18 * v->f1C;
    total = total * t2;
    v->f10 = 1280;
    v->f14 = 960;
    v->f18 = 1;
    v->f1C = 1;
    v->f20 = 3;
    u32 avail = func_00575D00();
    if (total != n) {
        func_005CD968(v);
        if (!(avail < n)) {
            fill1 = 0;
            resize(v,n,&fill1,&iter);
        }
    }

    }
    input.b = arg1;
    input.a = arg2;
    data.a = v->f10 * v->f20 * v->f14;
    data.b = (s32)v->b4;
    Decoder *d = &dec;
    func_0046CC38(d);
    func_0046CEE8(d,&data,&input);
    func_0046CFA0(d,0);
    if (!func_0046D960(d) || !func_0046D100(d)) {
        func_0046CD48(d,2);
        return;
    }
    {
{

    int width = d->w;
    int height = d->h;
    int channels = 3;
    s32 total = set_dimensions(v,width,height,channels);
    u32 n = width * channels * height;
    u32 avail = func_00575D00();
    if (n != total) {
        func_005CD968(v);
        if (!(avail < n)) {
            fill2 = 0;
            resize(v,n,&fill2,&iter);
        }
    }

}
        func_00331520(v,2,2);
        self->out = v;
        func_0046CD48(d,2);
        return;
    }
}
