/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int active; char pad[0x90]; int value; unsigned ready; };
extern "C" int func_004EF6D0(void *, void *, int, void *, int);
extern "C" void func_004EF9F0(void *, int);
extern "C" int func_005B72A8();
struct Guard {
 int state;
 Guard() { state = func_005B72A8(); }
 ~Guard() { if(state) __asm__ volatile("ei"); }
};
extern "C" unsigned func_004EEF48(Obj *p) {
 if (!p->active) return 0;
 if (p->ready) return 1;
 func_004EF9F0(p, 1);
 int out[4], aux[4];
 int result = func_004EF6D0(p, out, 2, aux, 2);
 unsigned ready;
 { Guard guard; ready = result >= 0; p->ready = ready; }
 p->value = ready ? out[0] : 0;
 return ready;
}
