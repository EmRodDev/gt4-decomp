/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Tbl { u8 *data; char p4[6]; u16 a,b; } Tbl;
typedef struct Head { char pad[0x50]; Tbl table; } Head;
typedef struct Obj { char pad[0x24]; Head *h; } Obj;
typedef struct Sub { u16 idx; u8 count,res,zero4,zero5; u16 flags; } Sub;
typedef struct Out { int tag; Sub v; short value; u8 zero, pad; } Out;
typedef struct Node { u8 k; char p1[3]; Out *entries; u16 n; char pA[2]; struct Node *next; } Node;
int func_004BF2D0(Obj *,int,u16 *,int,u16 *,int *);
short func_004C07F8(Head *,int,u16,int);
u8 *func_004C0740(short,Head *,int);
short func_004C37B0(Obj *,unsigned int);
int func_004C3918(Obj *,int,short);
void *func_004C8C20(Obj *,int);
void func_004C8C38(Obj *,void *);
int func_004C8ED0(u16 *);
int func_004C9368(u8 *,int);
int func_004C9580(unsigned int *,int);
int func_004C2B10(Obj *self,u16 *name,unsigned int *filter,Node **ret) {
 u16 index;
 int count;
 int k,i,len,total,last,match;
 Head *head=self->h;
 len=func_004C8ED0(name);
 total=0;
 last=-1;
 if(len>=64) len=63;
 match=0;
 for(k=1;k<=len;k++) {
  int result=func_004BF2D0(self,0x300,name,k,&index,&count);
  Out *out;
  Node *node;
  if(result<=0) return result;
  if(count<=0) continue;
  out=0;
  node=0;
  i=0;
  if(i<count) {
  Tbl *t=&head->table;
  do {
   short id=func_004C07F8(head,0x300,index,0);
   int off=id*20;
   int n=(t->a+t->b)*6;
   u8 *p=(u8*)(n+(int)(t->data+off));
   u8 *q=(u8*)(off+(int)(t->data+n));
   int tag=(q[0x10]<<8)|p[0x11];
   u8 *base;
   u8 *r;
   u8 *c;
   u8 cnt;
   u8 cur;
   int res;
   Sub *v;
   if(tag!=last) { match=func_004C9580(filter,tag); last=tag; }
   if(match==1) {
    base=func_004C0740(id,head,0x300);
    if(base) {
     r=(u8*)(off+(int)(t->data+(t->a+t->b)*6));
     c=r+0xc;
     cnt=*c+r[9];
     cur=*c;
     res=func_004C9368(base+r[0x12],r[0xd]+r[0xb]);
     if(res==0 || cnt!=cur) {
      if(!out) {
       out=(Out*)func_004C8C20(self,count*16);
       if(!out) return 0x80000334;
       node=(Node*)func_004C8C20(self,16);
       if(!node) { func_004C8C38(self,out); return 0x80000334; }
       node->entries=out;
       node->k=k;
       node->n=0;
       node->next=*ret;
       *ret=node;
      }
      out=&node->entries[node->n];
      v=&out->v;
      total++;
      v->idx=id;
      out->zero=0;
      v->count=cnt;
      v->res=res;
      if(v->res==0) {
       int off;
       u8 *data;
       int n;
       u8 *p;
       u8 *q;
       int mask;
       int hi;
       int lo;
       out->tag=id|0x800000;
       off=id*20;
       v->zero4=0;
       v->zero5=0;
       data=t->data;
       n=(t->a+t->b)*6;
       p=(u8*)(n+(int)(data+off));
       q=(u8*)(off+(int)(data+n));
       mask=p[0xf]&0x1f;
       hi=q[0x10]<<8;
       lo=p[0x11];
       v->flags=lo|hi|(mask<<11);
      } else {
       int off;
       u8 *r;
       u8 *data;
       int n;
       u8 *p;
       u8 *q;
       out->tag=id|0x400000;
       v->zero4=cur;
       off=id*20;
       r=(u8*)(off+(int)(t->data+(t->a+t->b)*6));
       v->zero5=func_004C9368(base+r[0x12],r[0xd]);
       data=t->data;
       n=(t->a+t->b)*6;
       p=(u8*)(n+(int)(data+off));
       q=(u8*)(off+(int)(data+n));
       v->flags=p[0xf]|(q[0xe]<<8);
      }
      out->value=func_004C37B0(self,func_004C3918(self,0x300,id));
      node->n++;
     }
    }
   }
   i++;
   index++;
  } while(i<count);
  }
 }
 return total;
}
