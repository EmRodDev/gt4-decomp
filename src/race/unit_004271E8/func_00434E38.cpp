/* compiler: ee-gcc2.96-no-strict-aliasing */
struct W { unsigned long b0 : 1; unsigned long b1 : 1; unsigned long b2 : 7; unsigned long b9 : 18; unsigned long b27 : 5; unsigned long b32 : 13; unsigned long b45 : 19; };
struct O { long f0; W w; union { long f10; struct { int lo, f14; } q; }; };
extern "C" void func_00434D80(O *) throw();
extern "C" void func_00434FD0(void *, void *);
extern "C" void func_0043A408(void *, int);
extern "C" void *func_0043DC20(void *);
extern "C" void func_00440EC8(void *, long);
extern "C" void func_00440F78(void *);
extern "C" void func_00441298(void *, int);
extern "C" void func_003434A8(void *, int);
extern char D_00688280[];

struct Base { char header[8]; ~Base() __asm__("func_0043A408"); };
struct Elem { char data[0x178]; ~Elem() __asm__("func_00444210"); };
struct Temp : Base { Elem elems[3]; char tail[0x50]; ~Temp() { *(void **)this = D_00688280; } };
extern "C" void func_00434E38(O *o, long a1, int a2, int a3) {
    Temp obj;
    char *sp = (char *)&obj;
    func_00434D80(o);
    o->f0 = a1;
    o->q.f14 = a3;
    o->w.b2 = a2;
    o->w.b0 = 1;
    o->w.b1 = 0;
    o->w.b9 = 0;
    o->w.b32 = 0;
    o->f10 = o->f10 & (int)0xFF000000;
    func_0043DC20(sp);
    func_00440EC8(sp, a1);
    func_00441298(sp, a2);
    func_003434A8(sp + 0x4A0, o->q.f14);
    func_00440F78(sp);
    func_00434FD0(o, sp);
}
