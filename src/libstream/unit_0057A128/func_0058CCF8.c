/* compiler: ee-gcc2.9-991111 */
struct Entry { int x; int state; int a[2]; int seq; int b[5]; };
extern struct Entry D_0087E3F8[];
extern unsigned int D_0087E3C8[];
extern int D_00657AA4;
int func_0058C740(int);
void *func_005A4724(void *,const void *,unsigned int);
int func_0058CCF8(int id,void *out,int len) {
 struct Entry *e=&D_0087E3F8[id];
 unsigned int h;
 int n;
 void *data;
 if((unsigned int)func_0058C740(id)<2 || e->state==2) return 0xffff6fc5;
 data=(void *)(D_0087E3C8[id]|0x20000000);
 h=*(unsigned int *)((char *)data+D_00657AA4-4);
 n=h>>16;
 if(e->seq==(h&0xffff)) n=0;
 else if(len) {
 e->seq=h&0xffff;
 n=len<n?len:n;
 func_005A4724(out,data,n);
 }
 return n;
}
