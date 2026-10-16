/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { float f0,f4,f8,fc,f10,f14,f18,f1c,f20; int i24,i28; char tex[0x3c]; };
struct View { int x,y,w,h; };
extern "C" {
void *func_00105378(void*,void*);
void func_001056A0(void*);
void func_00105708(void*);
void func_00399E70(void*,void*);
void func_00399F00(void*,void*);
void func_0039A2F0(void*,void*,int,float,float,float,float);
void func_004A1638(int);
int func_004A26F0(int);
void func_004A2808(int,float);
void func_004A29A8(int);
void func_004A6E20(float);
void func_004A6F10(int,int);
void func_004AB040(int);
float func_0057D488(float);
}
extern "C" void func_00399550(Obj *o,void *tex,View *view,void *state,void *copy,float r,float g,float b) {
 int i=0;
 func_00105378(o->tex,copy);
 func_004A29A8(0);
 func_00399F00(o,view);
 func_001056A0(tex);
 func_00105708(state);
 func_004A1638(5);
 func_004A26F0(3);
 func_004AB040(8);
 func_004A1638(6);
 func_004A2808(0x44,1.0f);
 float near=o->f14, far=o->f18;
 float range=near-far;
 float ratio=o->f4/(float)view->h;
 float delta=o->f10-o->fc;
 float scale=(near+far)/range;
 float bias=near*far*-2.0f/range;
 float square=o->fc*o->fc;
 for(;;i++) {
  float e=func_0057D488((float)i*0x1.62e42ep-1f/(float)o->i24);
  if(o->f1c<e) break;
  int n=o->i24;
  int rem=(i+1)%n;
  float fraction=1.0f;
  if(rem) fraction=(float)rem/(float)n;
  float depth=(square*o->f10)/(square-delta*e*ratio*o->f8);
  if(o->f14<depth || depth<0.0f) break;
  func_004A6E20(depth);
  func_0039A2F0(o,tex,i/o->i24,fraction,r,g,b);
 }
 func_00399E70(o,state);
 func_001056A0(tex);
 func_00105708(state);
 func_004A1638(5);
 func_004A1638(6);
 func_004A2808(0x44,1.0f);
 for(i=0;;i++) {
  float e=func_0057D488((float)i*0x1.62e42ep-1f/(float)o->i28);
  if(o->f20<e) break;
  int n=o->i28;
  int rem=(i+1)%n;
  float fraction=1.0f;
  if(rem) fraction=(float)rem/(float)n;
  float depth=(square*o->f10)/(square+delta*e*ratio*o->f8);
  if(depth<o->f18) break;
  func_004A6F10(0xffffff-(int)((1.0f-(scale*depth+bias)/depth)*8388608.0f),255);
  func_0039A2F0(o,tex,i/o->i28,fraction,r,g,b);
 }
 func_00399E70(o,state);
 func_004A29A8(1);
 func_004A1638(5);
 func_004AB040(6);
}
