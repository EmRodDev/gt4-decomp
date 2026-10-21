/* compiler: ee-gcc2.9-991111 */
typedef struct {
    int sema;
    int cmd;
    void *dest;
    int size;
} RcvHdr;

typedef struct {
    int n1;
    int n2;
    unsigned char *d1;
    unsigned char *d2;
    unsigned char b1[64];
    unsigned char b2[64];
} RcvEdges;

extern int D_00658340;
extern int D_00658338;
extern volatile int D_006582B8[32];
extern char D_00888F40[][0x440];
extern void *func_005A4724(void *, const void *, unsigned);
extern void func_005ADCD0(int);

/* _sceFs_Rcv_Intr */
void func_005B23B8(int *data)
{
    int sema, cmd;
    void *dest;
    int size;
    void *addr;
    unsigned len;
    char *p;
    unsigned char *d, *u;
    int i;

    D_00658338 = D_00658340 ? data[3] : 0;
    p = (char *)((unsigned)D_00888F40[D_00658338] | 0x20000000);
    __builtin_memcpy(&sema, p, 4);
    __builtin_memcpy(&cmd, p + 4, 4);
    __builtin_memcpy(&dest, p + 8, 4);
    __builtin_memcpy(&size, p + 12, 4);
    if (sema >= 0)
        func_005A4724(dest, p + 0x10, size);
    switch (cmd) {
    case 2: {
        RcvEdges *e = (RcvEdges *)(p + 0x14);
        if (e->n1 > 0) {
            d = e->d1;
            u = (unsigned char *)((unsigned)d | 0x20000000);
            for (i = 0; i < e->n1; i++)
                d[i] = u[i] = e->b1[i];
        }
        if (e->n2 > 0) {
            d = e->d2;
            u = (unsigned char *)((unsigned)d | 0x20000000);
            for (i = 0; i < e->n2; i++)
                d[i] = u[i] = e->b2[i];
        }
        break;
    }
    case 11:
        if (*(int *)dest > 0) {
            __builtin_memcpy(&addr, p + 0x14, 4);
            __builtin_memcpy(addr, p + 0x18, 324);
        }
        break;
    case 12:
        __builtin_memcpy(&addr, p + 0x14, 4);
        __builtin_memcpy(addr, p + 0x18, 64);
        break;
    case 23:
    case 25:
    case 26:
        __builtin_memcpy(&addr, p + 0x14, 4);
        __builtin_memcpy(&len, p + 0x18, 4);
        if (len > 0x400)
            len = 0x400;
        func_005A4724(addr, p + 0x1C, len);
        break;
    }
    if (sema < 0) {
        sema = -sema;
        for (i = 0; i < 32; i++) {
            if (D_006582B8[i] == sema) {
                D_006582B8[i] = -1;
                break;
            }
        }
    } else {
        func_005ADCD0(sema);
    }
}
