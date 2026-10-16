/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
typedef struct Entry {u32 data,size;u16 x,a,b,c;} Entry;
typedef struct Obj {char pad[12];u32 *time;char pad2[20];char *table;} Obj;
typedef struct Desc {u16 index;char pad[14];u32 time;char pad2[12];} Desc;
int func_004BC978(char *,int,Desc *,int);
int func_004BE840(Obj *,int,u16,int *);
int func_004C0208(Obj *p,u16 id,int mode,u16 *exclude,int n) {
u16 ids[20];u32 ages[20];Desc d;int sum=0;
u32 minimum=0;int count;s16 minidx=-1;u16 first,last,index;int i;
if(mode==1) {
 char *table=p->table;
 first=1; last=((Entry *)(table+(id&255)*16+0x50))->a;
} else {
 u32 offset=(id&255)*16+0x50;
 Entry *e=(Entry *)(p->table+offset);
 first=e->a+1;last=first+e->b-1;
}
for(i=0;i<20;i++) {ids[i]=0;ages[i]=0;}
count=0;
for(index=first;index<=last;index++) {
 d.index=index;
 if(func_004BC978(p->table,id,&d,0)>0) {
 u32 now=*p->time;
 u32 age=now-d.time;
 if(now<d.time)age+=0x10000000;
 for(i=0;i<n;i++) if(exclude[i]==index) break;
 if(i<n)continue;
 if(minidx<0) {
  if(count<20) {
   ages[count]=age;ids[count]=d.index;count++;
  } else {
   int j;
   minimum=0x0fffffff;minidx=-1;
   for(j=0;j<20;j++) {
    if(ages[j]<age) {
     u32 tmp=ages[j];u16 old=ids[j];ages[j]=age;age=tmp;
     ids[j]=d.index;d.index=old;
    }
    if(ages[j]<minimum) {minimum=ages[j];minidx=(s16)j;}
   }
  }
 } else if(minimum<age) {
  ages[minidx]=age;ids[minidx]=d.index;minidx=-1;
 }
 }
}
if(!count)return -1;
for(i=0;i<count;i++) {
 int out;
 int r=func_004BE840(p,id,ids[i],&out);
 if(r<0)return r;
 sum+=out;
}
return sum;
}
