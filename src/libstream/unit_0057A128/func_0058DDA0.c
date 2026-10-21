/* compiler: ee-gcc2.9-991111 */
struct G480 { char pad[0x24]; int v24; };
struct G500 { int v0; int v4; int v8; int vc; int v10; unsigned v14; int v18; int v1c; unsigned char data[0x10]; };
extern struct G480 D_0087E480;
extern struct G500 D_0087E500;
extern char D_0087FA40[];
extern int D_00657AF4, D_00657AF0;
extern char func_0058D748[];
extern void func_005ADCC0(int);
extern int func_005ADCF0(int);
extern void func_005ADF20(int);
extern int func_005B19B0(void *, int, int, void *, int, void *, int, void *, int);

int func_0058DDA0(int a0, unsigned p, int len) {
    unsigned i;
    struct G500 *r;
    unsigned char *p2 = (unsigned char *)p;
    if (D_0087E480.v24 == 0) return -100;
    if (func_005ADCF0(D_00657AF4) < 0) return -200;
    D_0087E500.v0 = a0;
    r = &D_0087E500;
    if (len < 0x11) {
        r->v14 = len;
        r->vc = 0;
        r->v18 = 0;
    } else {
        unsigned t = p - 0x10;
        unsigned d = ((p - 1) & 0xFFFFFFF0) - t;
        r->vc = len - d;
        r->v14 = d;
        r->v18 = p + d;
    }
    for (i = 0; i < D_0087E500.v14; i++) {
        unsigned char c = p2[i];
        D_0087E500.data[i] = c;
    }
    func_005ADF20(0);
    if (func_005B19B0(&D_0087E480, 6, 1, &D_0087E500, 0x30, D_0087FA40, 4, func_0058D748, 0)) {
        func_005ADCC0(D_00657AF4);
        return -91;
    }
    D_00657AF0 = 6;
    return 0;
}
