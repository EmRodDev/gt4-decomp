/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xC]; int count; };
extern "C" int func_005B72A8(void);
extern "C" void func_001C4D90(void *);
extern "C" void func_001C5980(void *);
extern "C" void func_001C5128(void *);
extern "C" void func_001C5918(void);
extern "C" void func_001C4C68(Obj *self) {
    int irq = func_005B72A8();
    int last = --self->count == 0;
    if (irq) __asm__ volatile("ei");
    if (last) {
        func_001C4D90(self);
        func_001C5980(self);
        func_001C5128(self);
        func_001C5918();
    }
}
