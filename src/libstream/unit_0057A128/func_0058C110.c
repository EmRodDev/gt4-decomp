/* compiler: ee-gcc2.9-991111 */
typedef struct { int state; int f4; int f8; int fC; int f10; int width; int height; int rate; int mode; int f24; } Ent;
extern Ent D_0087E3F8[];
extern int D_00657AA0;
extern char *D_0087E3C8[], *D_0087E3C0[];
extern int func_0058BD78(int, int, int, int, int, int *, int);
extern int func_0058BE20(int);
extern int func_0058C740(int);
int func_0058C110(int port, unsigned int mode, int rate, char *buffer) {
    Ent *e = &D_0087E3F8[port];
    int w,h,r;
    if (!func_0058BE20(rate)) return -12;
    switch (rate) {
    case 25: case 30: case 50: case 60:
        e->rate = rate; break;
    default: return -22;
    }
    switch (mode) {
    case 0: e->width=320; e->height=240; break;
    case 1: e->width=160; e->height=112; break;
    case 2:
        if (rate > 30) return -22;
        e->width=640; e->height=480; break;
    default: return -22;
    }
    e->mode=mode;
    e->state=0;
    e->f8=0;
    if (!func_0058C740(port)) return 0xFFFF6FC4;
    if (func_0058BD78(port,2,(int)buffer,(int)(buffer+D_00657AA0*3),1,&r,1)<0) return 0xFFFF7FF6;
    D_0087E3C0[port]=buffer;
    D_0087E3C8[port]=buffer+D_00657AA0*3;
    if (func_0058BD78(port,1,e->width,e->height,1,&r,1)<0) return 0xFFFF7FF6;
    if (r<0) return r;
    if (func_0058BD78(port,7,e->rate,0,1,0,0)<0) return 0xFFFF7FF6;
    if (r<0) return r;
    if (func_0058C740(port)) e->state=2;
    return 0;
}
