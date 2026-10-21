typedef unsigned int u32;
typedef long long s64;
struct Entry { short delta,index; int (*fn)(); };
struct IO { Entry *vt; };
struct Cursor { int block, key; u32 index,offset; };
struct File { int a,b,handle,d; u32 position; Cursor cursor; };
struct Stream { IO *io; void *ctx; char pad[0x44]; int base; u32 blocksize; char p2[0x14]; u32 count,unit; int shift,pad74; Entry *vt; };
extern "C" s64 func_004CC260(Stream *,File *,int,u32,int) throw();
extern "C" int func_004CB9C8(Stream *,Cursor *,u32) throw();
extern "C" int func_004CB8E8(Stream *,int) throw();
extern "C" void func_004CB1A8(int,int) throw();
extern "C" void *func_004CA778(void *,int) throw();
extern "C" void func_004CA9F8(void *,void *) throw();
extern "C" void func_004CAA88(void *,int) throw();
static inline int test(Stream *s,int n) { Entry *e=s->vt+1; return ((int (*)(void *,int))e->fn)((char *)s+e->delta,n); }
static inline int alloc(Stream *s,int key,u32 n) { Entry *e=s->vt+7;return ((int (*)(void *,int,u32))e->fn)((char *)s+e->delta,key,n); }
extern "C" s64 func_004CC380(Stream *s,File *f,int pos,u32 remaining,int mode) {
 Cursor *c=&f->cursor;
 u32 original=remaining;
 int result;
 if(c->offset) {
  result=(s64)func_004CC260(s,f,pos,remaining,mode);
  pos+=result; remaining-=result;
  if(result<0) return result;
 }
 if(pos==((pos+63)&~63)) {
  while(remaining>=s->blocksize) {
   if(c->block==0 || test(s,c->block)) {
    if(mode) break;
    result=alloc(s,c->key,(remaining+s->unit-1)/s->unit);
    if(result<0) return result;
    if(c->block==0) func_004CB1A8(f->handle,result);
    c->block=result;
   }
   u32 i=0;
   int start=func_004CB8E8(s,c->block)+c->index;
   u32 n=remaining/s->blocksize;
   u32 avail=s->count-c->index;
   if(n>=avail) n=avail;
   for(;i<n;i++) {
    if(mode) {
     void *p=func_004CA778(s->ctx,start+i);
     if(p) func_004CA9F8(s->ctx,p);
    } else func_004CAA88(s->ctx,start+i);
   }
   i=n*s->blocksize;
   u32 size=i;
   IO *io=s->io;
   Entry *e=io->vt+3;
   result=(s64)((s64 (*)(void *,int,int,u32,int))e->fn)((char *)io+e->delta,s->base+start,pos,size,mode);
   if(result) return -5;
   pos+=size;
   result=func_004CB9C8(s,c,size);
   remaining-=size;
   if(result<0) return result;
   f->position+=size;
  }
 }
 while(remaining) {
  if(c->block==0 || test(s,c->block)) {
   if(mode) break;
   result=alloc(s,c->key,(remaining+s->unit-1)/s->unit);
   if(result<0) return result;
   if(c->block==0) func_004CB1A8(f->handle,result);
   c->block=result;
  }
  result=(s64)func_004CC260(s,f,pos,remaining,mode);
  if(result<0) return result;
  pos+=result;
  remaining-=result;
 }
 return (s64)(original-remaining);
}
