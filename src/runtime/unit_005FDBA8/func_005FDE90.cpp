/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00682F98[];
extern "C" int func_005792D8(int *);
struct Obj { void *vt; int value; int active; int pad; char rows[0x50]; char pad60[8]; int tail[1]; };
static inline void row(float *p, float a, float b) { p[0] = a; p[1] = b; p[2] = a; }
extern "C" void func_005FDE90(Obj *o, int arg1) {
    o->vt = D_00682F98;
    float *p = (float *)o->rows;
    o->active = 1;
    int i = 3;
    do {
        i -= 1;
        row(p, 0.0f, 1.0f);
        p = (float *)((char *)p + 0x14);
    } while (i != -1);
    func_005792D8(o->tail);
    o->value = arg1;
}
