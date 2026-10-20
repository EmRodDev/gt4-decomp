#include "types.h"
struct Data { int a,b,c,d; };
struct Header {
    int state, zero, len; u32 size;
    Data data;
    int arg4,arg2,pad28; Header *self;
    char pad30[12]; int flag;
};
struct Context {
    int error; char pad4[4]; u32 limit;
    char padC[12]; int end; char *buffer;
    char pad20[12]; char *dest;
    char pad30[12]; int cursor;
};
struct Owner { char pad0[0x24]; Context *ctx; };
struct Chunk { char *data; int len; };
struct Input { Chunk chunks[8]; u32 size; int count; };
extern "C" int func_00570EC0(void *, void *, int) throw();
extern "C" int func_005718F8(Context *,u32,int *,u8 *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_005ADF20(int);
extern "C" int func_00571210(Owner *owner, Input *in, int arg2, Data *data, int arg4, u32 *out, int *status) {
    int ret=2;
    u8 flag=0;
    int len;
    int next, payload;
    int copied=0;
    if (!out) return ret;
    *out=0;
    if (!in) return ret;
    u32 size=in->size;
    if (!size) return ret;
    if (!data) return ret;
    if (!status) return ret;
    if (!owner) return ret;
    Context *ctx=owner->ctx;
    if (!ctx) return ret;
    if (ctx->limit<size) return ret;
    if (size>=(u32)(ctx->end-0x40)) return ret;
    func_005ADF20(0);
    if (ctx->error<0) { *status=ctx->error; return 1; }
    ret=func_005718F8(ctx,in->size,&len,&flag);
    if (ret) return ret;
    int f=flag;
    if (f==1) {
        int cursor=ctx->cursor;
        next=cursor+0x40;
        payload=len-0x40;
        Header *h=(Header *)(ctx->buffer+cursor);
        *(int *)h=f;
        *((int *)h+1)=0;
        h->len=len-0x40;
        h->size=in->size;
        h->data=*data;
        h->arg4=arg4;
        h->arg2=arg2;
        h->self=h;
        h->flag=f;
        char *buf=(char *)h+0x40;
        int i=0;
        if (in->count > 0) do {
            func_005A4724(buf+copied,in->chunks[i].data,in->chunks[i].len);
            copied+=in->chunks[i].len;
            i++;
        } while (i<in->count);
        ret=func_00570EC0(buf,ctx->dest+next,payload);
        if (ret) return ret;
        ret=func_00570EC0(h,ctx->dest+cursor,0x40);
        if (ret) return ret;
        ctx->cursor+=len;
        if (ctx->cursor>=ctx->end) ctx->cursor=0;
        *out=in->size;
    } else *out=0;
    *status=*out;
    ret=0;
    return ret;
}
