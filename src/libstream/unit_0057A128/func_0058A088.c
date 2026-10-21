/* compiler: ee-gcc2.9-991111 */
struct State { int a,b,c,d; char pad[0x20]; int x30,x34,x38; int (*create)(void *,void *); int x40; int (*open)(int,int); int (*stat)(int,int,void *); char pad4c[0x34]; char buf[1]; };
extern struct State D_0087E1C0;
int __attribute__((register_precision ($16, 128))) func_0058A088(void) {
    int info[16];
    int args[8];
    int r = D_0087E1C0.open(D_0087E1C0.a + 2, D_0087E1C0.b);
    D_0087E1C0.x38 = 0;
    if (r < 0) {
        if ((r & 0xffff) != 0x8002) return r;
        args[0]=2;
        args[1]=D_0087E1C0.a+2;
        args[2]=D_0087E1C0.b;
        r=D_0087E1C0.create(args,D_0087E1C0.buf);
        if (r < 0) return r;
        D_0087E1C0.x38=1;
    }
    D_0087E1C0.x34=r;
    r=D_0087E1C0.stat(r,D_0087E1C0.c,info);
    if (r < 0) return r;
    D_0087E1C0.x30=0;
    D_0087E1C0.d=info[4];
    return 0;
}
