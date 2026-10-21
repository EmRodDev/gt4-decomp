/* compiler: ee-gcc2.9-991111 */
struct Ent { char pad[0x24]; int flag; };
extern char D_0087E3F8[];
int func_0058BD78(int, int, int, int, int, int *, int);
int func_0058C840(int a0, int a1, int a2, int a3) {
    int v;
    if (func_0058BD78(a0, a1 | 0x4000, a2, a3, 1, &v, 1) == -1)
        return 0xFFFF7FF6;
    if (v == -2) return 0xFFFF7FF5;
    if (v == -1) return 0xFFFF6FC4;
    if (a1 == 14) { char *e = D_0087E3F8 + a0 * 0x28; *(int *)(e + 0x24) = a2 != 0; }
    return 0;
}
