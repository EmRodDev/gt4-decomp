/* compiler: ee-gcc2.96-stl */
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef float f32;
struct Mat4 { float m[16]; };
struct VEntry { short delta,index; void (*fn)(void *); };
struct VEntryI { short delta,index; void (*fn)(void *,int); };
struct VEntryR { short delta,index; s32 (*fn)(void *); };
struct VEntryL { short delta,index; s64 (*fn)(void *); };
struct Car { char p[0x18]; void *f18; char p1[0x345c-0x1c]; int f345C; };
struct P8 { Car *p0; };
struct P60 { char p[8]; P8 *p8; };
struct Course {
 int f0; char p4[0x60-4]; P60 *p60;
 char p64[0x70-0x64]; void *p70;
 char p74[0x80-0x74]; void *p80;
 char p84[0xc4-0x84]; int fC4;
 char pc8[8]; int fD0;
 char pd4[0x974-0xd4]; char *vtbl;
};
struct Run { char p[0x64]; char *vtbl; int p68; Course *u6C; char p70[0xe3ac-0x70]; char fE3AC[4]; };
struct Info { char p[0x12c]; char *vtbl; };
struct Hud { int f0; char p[0x46c-4]; int f46C; char p470[0x480-0x470]; int f480; ~Hud() __asm__("func_00127F70"); };
struct Stats { char p[0x70]; s64 f70,f78; };
struct Game { char p[0x348]; Stats f348; char p3c8[8]; unsigned char f3D0; char p3d1[0x13938-0x3d1]; char f13938[0x38c20-0x13938]; signed char f38C20; char p38c21[0x3a368-0x38c21]; char f3A368[4]; };
struct Rec { char p[0x1c]; void *u1C; };
struct Championship : Run { Championship() __asm__("func_003EF498"); };
struct Practice : Run { Practice() __asm__("func_003B92D0"); };
inline void *operator new(unsigned int,void *p) throw() {return p;}
extern Game *D_00622F4C;
extern "C" {
void GranTurismo4__LoadingMode(const char *) throw();
void func_0010AF40(int) throw();
void func_001103C8(void *) throw();
void func_001103E0(void *,int) throw();
void func_00110460(void *) throw();
void func_0044CA98(int,int,int,int) throw();
void func_0044CB10() throw();
void *exception__structor_0(u32) throw();
extern "C" char *func_00575DC8(int) throw() __attribute__((malloc));
void func_00575DA0(void *) throw();
void RaceChampionshipInformation__structor_0(Info *) throw();
void func_001197B8(Info *) throw();
void func_00127E60(Hud *) throw();
void func_001242B8(Hud *) throw();
void func_00127F70(Hud *,int) throw();
Course *func_003B7850(Info *) throw();
int RaceChampionship__structor_0(Run *) throw();
void RaceFreePractice__structor_0(Run *) throw();
void func_00447378(s32) throw();
void func_003EE9F8(Info *,Course *);
void func_003EE808(Info *,Course *) throw();
void func_00387EF0(Run *,int,int) throw();
void func_00119918(Hud *,Info *,Run *) throw();
void func_00119CB8(Hud *,Info *,Run *) throw();
void func_00110D18(Course *) throw();
void func_00119890(Run *) throw();
void func_0010F948(Course *) throw();
void func_0010F770(Course *) throw();
void func_0010F848(Course *) throw();
int func_003EF330(Info *) throw();
void func_0011A4C0(Run *,int) throw();
float func_00110A80(char *) throw();
void *func_004472A0(void *) throw();
void func_00468710(Mat4 *,void *,float) throw();
void func_00110AE8(Course *,Mat4 *) throw();
int func_00468AF0(void *,void *,float) throw();
void func_0010FA58(Course *,u32 *,u32 *) throw();
short Automobile__GetImplicitCurrentLap(void *) throw();
void func_003C0008(Course *) throw();
void func_0010FE40(const char *) throw();
void func_003BFFE8(Course *) throw();
u32 func_0035E3F0(void *) throw();
void func_00119BD8(Info *,int) throw();
void func_003EF088(Info *) throw();
void RaceCourse__clearData(void *) throw();
void func_003C0108(Course *) throw();
void func_003BFD58(Course *,s64) throw();
void func_003C0C20(Course *,s64) throw();
void RaceCourse__setSectionNumber(void *,int) throw();
void func_00110C20(Course *) throw();
Rec *func_001D3A60() throw();
void func_0042FC98(char *,const char *) throw();
}
struct Guard { int x; u32 a,b; Guard() {func_001103C8(this);a=0;b=0;} ~Guard(){func_001103E0(this,2);} };
#define CAR(c) ((c)->p60->p8->p0)
#define VCALL(r,off) { VEntry *e=(VEntry *)((r)->vtbl+(off)); e->fn((char *)(r)+e->delta); }
#define VCALLI(r,off,arg) { VEntryI *e=(VEntryI *)((r)->vtbl+(off)); e->fn((char *)(r)+e->delta,arg); }
static inline s32 get(Info *r,int off) { VEntryR *e=(VEntryR *)(r->vtbl+off); return e->fn((char *)r+e->delta); }
static inline s64 getl(Info *r,int off) { VEntryL *e=(VEntryL *)(r->vtbl+off); return e->fn((char *)r+e->delta); }
extern "C" void func_00118EF0() {
 func_0010AF40(0);
 Guard guard;
 func_0044CA98(0x30000,2,6,0xbc8000);
 Info *info=(Info *)exception__structor_0(0xab0);
 RaceChampionshipInformation__structor_0(info);
 func_001197B8(info);
 Hud *hud=(Hud *)exception__structor_0(0x4f8);
 func_00127E60(hud);
 func_001242B8(hud);
 Hud *mode=hud;
 Course *course=func_003B7850(info);
 CAR(course)->f345C=D_00622F4C->f3D0;
 void *mem=func_00575DC8(0x24140);
 Championship *initial=new(mem) Championship;
 initial->u6C=course;
 Run *run=initial;
 func_00447378(get(info,0x98));
 if(D_00622F4C->f38C20)func_003EE9F8(info,course);
 func_00387EF0(initial,0,1);
 VCALL(initial,0x2c0)
 func_00119918(hud,info,initial);
 func_00110D18(course);
 Mat4 m;
 int running=1;
 int flag=0;
 do {
 func_00119890(run);
 switch(mode->f0) {
 case 1: {
 func_0010F948(course);func_0010F770(course);func_0010F848(course);
 func_0011A4C0(run,func_003EF330(info));
 float dt=func_00110A80(D_00622F4C->f13938);
 func_00468710(&m,func_004472A0(course->p70),dt);
 func_00110AE8(course,&m);
 if(flag) {flag=0;VCALL(run,0x168)}
 VCALLI(run,0x328,0)
 func_00119CB8(hud,info,run);
 void *car=CAR(course)->f18;
 func_00468AF0(car,func_004472A0(course->p70),dt);
 func_0010FA58(course,&guard.a,&guard.b);
 if(Automobile__GetImplicitCurrentLap(CAR(run->u6C)->f18)>=2) {VCALLI(run,0x328,2)}
 hud->f46C=1;hud->f480=1;break;
 }
 case 14: {
 func_0010F948(course);func_0010F770(course);func_0010F848(course);
 func_0011A4C0(run,func_003EF330(info));
 float dt=func_00110A80(D_00622F4C->f13938);
 func_00468710(&m,func_004472A0(course->p70),dt);
 func_00110AE8(course,&m);
 if(flag) {flag=0;VCALL(run,0x168)}
 VCALLI(run,0x328,1)
 func_00119CB8(hud,info,run);
 void *car=CAR(course)->f18;
 func_00468AF0(car,func_004472A0(course->p70),dt);
 func_0010FA58(course,&guard.a,&guard.b);
 hud->f46C=2;hud->f480=1;break;
 }
 case 15:
 flag=1;func_003C0008(course);func_0010FE40("setting");func_003BFFE8(course);break;
 case 20: {
 VCALLI(run,8,2)
 Run *practice=(Run *)mem;
 if(practice)RaceFreePractice__structor_0(practice);
 practice->u6C=course;
 func_0010F948(course);func_0010F770(course);func_0010F848(course);
 VCALLI(practice,0x328,0)
 func_0010FA58(course,&guard.a,&guard.b);
 u32 value=func_0035E3F0(CAR(course)->f18);
 VCALLI(practice,8,2)
 Championship *next=new(run) Championship;
 next->u6C=course;
 run=next;
 if(value!=0x157529ff) {
 func_003EE808(info,course);
 func_00387EF0(run,0,1);VCALL(run,0x2c0)
 func_00119918(hud,info,run);
 }
 break;
 }
 case 18:
 if(func_003EF330(info)) {func_00119BD8(info,0);running=0;}
 else {
 func_003EF088(info);
 RaceCourse__clearData(course->p80);
 func_003C0108(course);
 func_003BFD58(course,getl(info,0x10));
 func_003C0C20(course,getl(info,0x18));
 course->f0=get(info,0x38);
 course->fC4=get(info,0x40);
 course->fD0=get(info,0x48);
 void *track=course->p80;
 RaceCourse__setSectionNumber(track,get(info,0x90));
 func_00110C20(course);
 func_003EE9F8(info,course);
 func_00387EF0(run,0,1);VCALL(run,0x2c0)
 func_00119918(hud,info,run);
 }
 hud->f46C=0;hud->f480=0;break;
 case 3:
 if(hud->f46C==1) {VCALLI(run,0x328,2)} else {VCALLI(run,0x328,3)}
 break;
 case 9:
 func_001D3A60()->u1C=run->fE3AC;
 func_0042FC98(D_00622F4C->f3A368,"MODE_SAVE_FULL_REPLAY");
 func_003C0008(course);func_0010FE40("labomode");func_003BFFE8(course);break;
 case 2: {
 int end=1;
 if(hud->f480) {
 if(func_003EF330(info))end=0;
 else func_003EF088(info);
 }
 func_00119BD8(info,end);running=0;break;
 }
 case 19:func_00119BD8(info,0);running=0;break;
 case 22:func_003C0008(course);func_0010FE40("option");func_003BFFE8(course);func_00110460(&guard);break;
 default:running=0;break;
 }
 } while(running);
 if(course) {VCALLI(course,8,3)}
 GranTurismo4__LoadingMode("race-end");
 VCALLI(run,8,2)
 func_00575DA0(mem);
 func_001242B8(0);
 delete hud;
 func_0044CB10();
 if(info) {VCALLI(info,8,3)}
 {Stats *s=&D_00622F4C->f348;s->f70+=guard.a;}
 {Stats *s=&D_00622F4C->f348;s->f78+=guard.b;}
}
