/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x,y; };
struct Chain { Vec2 *items[48]; int count,side; };
extern "C" void func_004854F8(void *,const Vec2 *,const Vec2 *,const Vec2 *);
extern "C" void func_006089A0(Chain *,Vec2 **);
extern "C" void func_006089D0(Chain *,unsigned int,int);
static inline Vec2 *get(Vec2 *const &v) { return v; }
extern "C" void func_00608598(Chain *s,void *out,Vec2 *point,int side) {
 int n=s->count;
 if(n<2) { func_006089A0(s,&point); s->side=side; return; }
 if(side==s->side) {
  Vec2 **cursor=(Vec2 **)(n*4+(int)s-8);
  int used=2;
  int back=n-1;
  Vec2 *prev=s->items[back];
  int i=n-2;
  float dx=get(prev)->x-point->x;
  float dy=get(prev)->y-point->y;
  int last;
  while(1) {
   Vec2 *current=*cursor--;
   last=i;
   Vec2 **pcur=&current;
   float ex=get(*pcur)->x-point->x;
   float ey=get(*pcur)->y-point->y;
   float cross=dx*ey-dy*ex;
   if(side) cross=-cross;
   if(!(cross<0.0f)) break;
   ++used;
   func_004854F8(out,current,prev,point);
   i=last-1;dx=ex;dy=ey;prev=current;
   if(n<used) { last=n-used; break; }
  }
  func_006089D0(s,last+2,0);
  func_006089A0(s,&point);
 } else {
  --n;
  s->side=side;
  int i=0;
  while(i<n) {
   int next=i+1;
   func_004854F8(out,s->items[i],s->items[next],point);
   i=next;
  }
  s->items[0]=s->items[n]; s->items[1]=point;
  func_006089D0(s,2,0);
 }
}
