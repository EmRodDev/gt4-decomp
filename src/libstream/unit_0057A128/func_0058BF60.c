/* compiler: ee-gcc2.9-991111 */
typedef struct { char b[0x28]; } Ent;
extern Ent D_0087E3F8[2];
extern int D_00657AAC;
extern char D_00657A98;
extern char D_00657A99;
extern char D_00657A9A;
extern int D_00657A9C;
extern int D_00657AA0;
extern int D_00657AA4;
extern int D_00657AB0;
void func_005B1028(int);
void *func_005A48D8(void *, int, unsigned int);
int func_0058BCE8(int);
int func_0058BD78(int, int, int, int, int, unsigned *, int);

int func_0058BF60(void) {
    unsigned v;
    int t;
    int p;
    int end;
    if (D_00657AAC == 0) {
        func_005B1028(0);
        p = (int)D_0087E3F8;
        end = p + 0x50;
        do {
            func_005A48D8((void *)p, 0, 0x28);
            p += 0x28;
        } while (p < end);
        func_0058BCE8(0x80001400);
        if (func_0058BD78(0, 8, 0, 0, 1, &v, 1) < 0)
            return 0xFFFF7FF6;
        t = (v & 0xFF) << 10;
        D_00657AA0 = t;
        D_00657AA4 = v & 0xFF00;
        D_00657A98 = (v >> 16) & 1;
        D_00657A9A = (v >> 17) & 3;
        D_00657A9C = ((v >> 19) & 3) * 8000;
        D_00657A99 = (v >> 24) & 1;
        D_00657AB0 = t;
        D_00657AAC = 1;
    }
    return 0;
}
