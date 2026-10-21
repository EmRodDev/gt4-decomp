/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_006879A0[];
extern char D_00688280[];
extern "C" void func_0043A408(void *, int);
extern "C" void func_005C1628(void *) throw();
struct Elem { char pad[0x178]; ~Elem() __asm__("func_00444210"); };
struct Base { void *vptr; int pad; ~Base() __asm__("func_0043A408"); };
struct Sub : Base { Elem e[3]; ~Sub() { vptr = D_00688280; } };
static inline void destroy_sub(char *p) {
    ((Sub *)p)->~Sub();
}
extern "C" void func_00600CC0(char *self, int flags) {
    *(void **)self = D_006879A0;
    destroy_sub(self + 0x598);
    destroy_sub(self + 0xD8);
    func_0043A408(self, 0);
    if (flags & 1) return func_005C1628(self);
}
