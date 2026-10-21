/* compiler: ee-gcc2.9-991111 */
typedef struct { int state; int f4; char pad[0x20]; } Ent;
extern Ent D_0087E3F8[];
int func_0058BD78(int, int, int, int, int, int *, int);
int func_0058C740(int);
int func_0058C5E0(int arg0) {
    Ent *e = &D_0087E3F8[arg0];
    int v;
    if (func_0058C740(arg0) == 0) return 0xFFFF6FC4;
    if (func_0058BD78(arg0, 5, 0, 0, 1, &v, 1) < 0) return 0xFFFF7FF6;
    if (v == -2) return 0xFFFF7FF5;
    if (v == -1) return 0xFFFF6FC4;
    e->f4 = 3;
    return 0;
}
