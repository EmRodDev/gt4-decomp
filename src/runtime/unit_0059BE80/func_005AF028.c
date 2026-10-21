/* compiler: ee-gcc2.9-991111 */
struct Queue { char pad[12]; unsigned char *write; };
struct Tty { int socket; volatile int wlen,rlen; volatile int busy; unsigned char *wbuf,*rbuf; struct Queue *queue; };
extern void func_005AEFA8(struct Queue *);
extern void func_005B07D0(const char *,...);
extern int func_005B96C0(int,void *,int);
extern int func_005B96F8(int,void *,int);
extern char D_006D2390[],D_006D23B8[],D_006D23D0[],D_006D23E8[];
void func_005AF028(int event,int count,struct Tty *t) {
 unsigned short *packet;
 switch(event) {
 case 1: case 2:
  if(count!=0) {
   int offset;
   if((unsigned)(t->rlen+count)>0x140) func_005B07D0(D_006D2390);
   offset=t->rlen;
   count=func_005B96C0(t->socket,t->rbuf+offset,count & 0xffff);
   if(count<0) func_005B07D0(D_006D23B8);
   t->rlen+=count;
  } else {
   packet=(unsigned short *)t->rbuf;
   for(count=12;count<*packet;count++) {
    *t->queue->write=t->rbuf[count];
    func_005AEFA8(t->queue);
   }
   t->rlen=0;

  }
  return;
 case 3: {
  int n=func_005B96F8(t->socket,t->wbuf,t->wlen & 0xffff);
  if(n<0) {func_005B07D0(D_006D23D0,n); t->busy=0;}
  else {t->wbuf+=n; t->wlen-=n;}
  return;
 }
 case 4:
  if(t->wlen!=0) func_005B07D0(D_006D23E8,t->wlen);
  t->busy=0;
  return;
 default: break;
 }
}
