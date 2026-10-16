/* compiler: ee-gcc2.96-no-strict-aliasing */
struct M { char pad[0x7A]; char f7A; char pad7B; short f7C; short f7E; short f80; short pad82; int f84; };
struct O { char pad[0x5A8]; M *f5A8; };
extern "C" int func_004F0C88(void *);
extern "C" int func_004F0CD0(void *, int);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_004F74A0(O *o, int a1, int a2) {
    if (func_004F0C88(o) != 0) {
        M *m;
        func_005A48D8(o->f5A8, 0, 0x8C);
        m = o->f5A8;
        m->f7A = 0;
        m->f7C = 0x64;
        m->f7E = a1;
        m->f80 = a2;
        m->f84 = 4;
        return func_004F0CD0(o, 0x54);
    }
}
