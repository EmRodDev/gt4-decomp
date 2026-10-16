typedef unsigned int u32;
struct Obj { char *a, *b, *c, *d; };
extern "C" int func_005385E0(Obj *p, int *out) {
    int ret = 2;
    if (p && out) {
        char *c = p->c;
        if (p->d == c) *out = 0;
        else {
            char *b = p->b;
            char *a = p->a;
            if (b >= a) *out = c - b;
            else *out = a - b;
        }
        ret = 0;
    }
    return ret;
}
