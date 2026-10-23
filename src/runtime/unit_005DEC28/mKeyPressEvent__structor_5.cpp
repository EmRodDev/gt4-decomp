/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int x; void *vt; char pad[24]; void *p20; void *p24; float f28, f2c; int x30; };
extern char mKeyPressEvent__vtable[];
extern "C" void *mWindowEvent__structor_0(void *, int a1, int a2);
extern "C" void *mKeyPressEvent__structor_5(Obj *p, int a1, int a2, int a3, int a4, float f0, float f1, int a5) {
 void *r = mWindowEvent__structor_0(p, a1, a2);
 p->p20 = (void *)a3;
 p->x30 = a5;
 p->p24 = (void *)a4;
 p->f28 = f0;
 p->f2c = f1;
 p->vt = mKeyPressEvent__vtable;
 return r;
}
