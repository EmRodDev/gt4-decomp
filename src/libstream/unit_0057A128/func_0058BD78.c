/* compiler: ee-gcc2.9-991111 */
typedef struct { int f0; int f4; int f8; int fC; } S;
extern S D_0087E340;
extern char D_0087E380[];
extern char D_0087E3D0[];
void *func_005A4724(void *, const void *, unsigned);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

int func_0058BD78(int a0, int a1, int a2, int a3, int a4, void *a5, int a6) {
    S *s = &D_0087E340;
    int r;
    s->f8 = a3;
    s->f4 = a2;
    s->fC = a0;
    s->f0 = a1;
    r = func_005B19B0(D_0087E3D0, 0x80001400, a4 == 0, s, 0x10, D_0087E380, 0x10, 0, 0);
    if (r < 0) return -1;
    if (a5 != 0) func_005A4724(a5, D_0087E380, a6 << 2);
    return 0;
}
