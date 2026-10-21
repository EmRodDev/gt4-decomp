/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int PDISTD__UNIT_MANAGER[];
extern char D_006A37E0[];
extern "C" float func_00472C28(int *);
extern "C" char *func_00472898(int *);
extern "C" double fptodp(float);
extern "C" int func_0057DA20(char *, const char *, ...);
struct Obj { int first; char text[0xB0]; void update() __asm__("func_003E02C8"); };
void Obj::update() {
 int *p=PDISTD__UNIT_MANAGER;
 float x=func_00472C28(p);
 char *buf=text;
 char *s=func_00472898(p);
 const char *fmt=D_006A37E0;
 func_0057DA20(buf,fmt,fptodp(x),s);
}
