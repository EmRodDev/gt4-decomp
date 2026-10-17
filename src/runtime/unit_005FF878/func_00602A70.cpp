/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Destructor of a large aggregate: each member gets its vtable pointer set back before its own destructor runs, in reverse construction order. */
extern char D_006878C8[];
extern char D_00687908[];
extern char D_00687960[];
extern char D_006879E0[];
extern char D_00687A20[];
extern char D_00687A60[];
extern char D_00687AA0[];
extern char D_00687DD0[];
extern char D_00687E90[];
extern char D_00687F50[];
extern "C" void func_0043A408(void *, int);
extern "C" void func_00435268(void *, int);
extern "C" void func_00600A40(void *, int);
extern "C" int func_005C1628(void *);
#define AT(base, off) ((char *)(base) + (off))
#define SETVT(p, vt) (*(void **)(p) = (vt))
extern "C" int func_00602A70(char *self, unsigned flags) {
    char *tail = AT(self, 0x220);
    SETVT(self, D_00687E90);
    { char *m = AT(self, 0x38940); SETVT(m, D_00687F50); func_0043A408(m, 0); }
    { char *m = AT(self, 0x388B0); SETVT(m, D_00687960); func_0043A408(m, 0); }
    { char *m = AT(self, 0x38838); SETVT(m, D_00687DD0); func_0043A408(m, 0); }
    { char *m = AT(self, 0x38728); SETVT(m, D_006879E0); func_0043A408(m, 0); }
    { char *m = AT(self, 0x38618); SETVT(m, D_006879E0); func_0043A408(m, 0); }
    { char *m = AT(self, 0x36208); SETVT(m, D_006878C8); func_0043A408(m, 0); }
    { char *m = AT(self, 0x26BE8); SETVT(m, D_00687A60); func_0043A408(m, 0); }
    { char *m = AT(self, 0x262F8); SETVT(m, D_00687AA0); func_0043A408(m, 0); }
    { char *m = AT(self, 0x146E8); SETVT(m, D_00687AA0); func_0043A408(m, 0); }
    { char *m = AT(self, 0x13AE0); SETVT(m, D_00687A20); func_0043A408(m, 0); }
    func_00435268(AT(self, 0xB8E8), 2);
    SETVT(tail, D_00687908);
    func_00600A40(AT(self, 0x228), 2);
    func_0043A408(tail, 0);
    func_0043A408(self, 0);
    if (flags & 1) return func_005C1628(self);
}
