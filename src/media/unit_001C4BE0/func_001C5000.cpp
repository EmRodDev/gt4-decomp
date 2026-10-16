/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001C4A90(void *, int, int) throw();
extern "C" int func_005B72A8(void);
struct Entry { int a,b,c,d; };
struct Obj { char pad[0xc]; Entry entries[38]; char extra[0x10]; int count; };
extern "C" void func_001C5000(Obj *p) {
    int enabled = func_005B72A8();
    for (int i=0; i<18; ++i) {
        func_001C4A90(&p->entries[i+1], p->entries[i+19].c, p->entries[i+19].d);
    }
    *(int *)((char *)p + 0x27c) = 0;
    if (enabled) __asm__ volatile("ei");
}
