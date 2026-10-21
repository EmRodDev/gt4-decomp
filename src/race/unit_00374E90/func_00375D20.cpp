struct Entry { short delta, index; char *(*fn)(void *, int); };
struct Entry4 { short delta, index; void (*fn)(void *, char *, int, int, float); };
struct Obj { char *vtbl; char pad[0x9C0 - 4]; float f9C0; char pad2[0x9D4 - 0x9C4]; float f9D4; };
struct Tg { char *vtbl; };
extern "C" void func_00378F28(char *, void *, char *, char *, float *);
extern "C" int func_003FFA20(char *);
extern "C" int func_00400408(char *, int);
extern "C" void func_00375D20(Obj *self, char *arg1, int a2, int idx, int a4, int *out) {
    char *base = (char *)self + idx * 0x19C;
    char *s4 = base + 0x10;
    char *s7 = base + 0xE0;
    char *c04 = (char *)self + 0xC04;
    int *outp = out;
    if (func_00400408(c04, (signed char)s7[0x4D])) {
        float *p9C0 = &self->f9C0;
        char *cc = c04;
        Tg *s0 = *(Tg **)(s4 + 0x168);
        int s1 = *(int *)(arg1 + 0x80);
        int h = func_003FFA20(cc);
        Entry4 *e = (Entry4 *)(s0->vtbl + 0x138);
        int v = 1;
        e->fn((char *)s0 + e->delta, s4, s1, h, self->f9D4 / *p9C0);
        *(Tg **)(s4 + 0x12C) = s0;
        *outp = v;
    }
    float *tailp = &self->f9C0;
    Entry *e0 = (Entry *)(self->vtbl + 0xD8);
    func_00378F28(e0->fn((char *)self + e0->delta, idx), arg1, s7, s4, tailp);
}
