struct B30 { char b[0x30]; };
struct B40 { char b[0x40]; };
struct Src { char pad0[0x18]; int state; struct B30 a; char pad4c[4]; struct B40 b; };
struct Req { int x0; struct B30 a; struct B40 b; char pad74[0xC]; };
extern void (*D_008A0168)(struct Src *, int);
extern int D_008A0130;
void func_005346E0(struct Req *);
void func_0052F070(struct Req *, int *);

int func_00504D48(int a0, int a1, int a2, struct Src *src) {
    struct Req req;
    int out;
    if (D_008A0168)
        D_008A0168(src, D_008A0130);
    if (src->state == 2) {
        func_005346E0(&req);
        req.a = src->a;
        req.b = src->b;
        func_0052F070(&req, &out);
    }
    return 0xB4;
}
