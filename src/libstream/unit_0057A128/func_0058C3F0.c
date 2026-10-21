/* compiler: ee-gcc2.9-991111 */
typedef struct { int state; char pad[0x24]; } Ent;
extern Ent D_0087E3F8[];
extern char *D_0087E3C0[];
extern int D_00657AB0;
extern int D_00657AA0;
int func_0058BD78(int, int, int, int, int, int *, int);
int func_0058C740(int);

int func_0058C3F0(int arg0) {
    Ent *e = &D_0087E3F8[arg0];
    int r;
    int v;
    char *base;
    r = func_0058C740(arg0);
    if (r == 2) {
        base = D_0087E3C0[arg0];
        *(int *)(base + D_00657AB0 - 4) = -1;
        *(int *)(base + D_00657AA0 + D_00657AB0 - 4) = -1;
        { char *q = base + D_00657AA0 * 2; *(int *)(q + D_00657AB0 - 4) = -1; }
        if (func_0058BD78(arg0, 3, 0, 0, 1, &v, 1) < 0) return 0xFFFF7FF6;
        if (v == -2) return 0xFFFF7FF5;
        if (v == -1) return 0xFFFF6FC4;
        e->state = 3;
    } else if (r == 0) {
        return 0xFFFF6FC4;
    }
    return 0;
}
