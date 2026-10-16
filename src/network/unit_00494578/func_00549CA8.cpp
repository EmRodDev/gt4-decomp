/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Request {
    int a, b;
    char name[0x40];
    int c, d, e, f, g;
};
struct State { char pad[0x3E4]; Request request; char pad440[0x5C]; int ready; };
extern State *D_0064C3E4;
extern "C" int func_005B72A8(void);
extern "C" char *func_005A609C(char *, const char *);
extern "C" void func_00574EE8(void *);
extern "C" void func_00549CA8(int a, int b, const char *name, int c, int d, int e, int f, int g) {
    State *s = D_0064C3E4;
    Request *r = &s->request;
    int enabled = func_005B72A8();
    r->a = a;
    r->b = b;
    if (name) func_005A609C(r->name, name);
    else r->name[0] = 0;
    r->c = c;
    r->d = d;
    r->e = e;
    r->f = f;
    r->g = g;
    s->ready = 1;
    if (enabled) __asm__ volatile("ei");
    func_00574EE8((char *)s + 4);
}
