/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;

struct IopBufReq {
    unsigned int size;
    unsigned int count;
};

extern struct IopBufReq D_008882C0;
extern int D_0065833C;
extern char D_008899C0[];
extern char D_00888F00[];
extern int func_005B2150(void);
extern u32 func_005B2258(int, int, int, int, int, int, int, int, int, int);
extern int func_005B27C8(int);
extern void func_005B27F8(void);
extern void func_005B28F0(void);
extern int func_005B2AF8(void);

/* sceFsSetIopBuf */
int func_005B2BC0(unsigned int buffsize, unsigned int buffcnt)
{
    struct IopBufReq *req;
    int ret;

    func_005B27C8(0xFE);
    if (D_0065833C == 0)
        func_005B28F0();
    if (func_005B2AF8() != 0) {
        func_005B27F8();
        return 0xFFFEFFFC;
    }
    if (func_005B2150() != 0) {
        func_005B27F8();
        return -0x10;
    }
    if ((buffsize & 0x3FFF) != 0 || buffsize == 0 || buffsize > 0xFFFFF || buffcnt == 0 || buffcnt > 0x20) {
        func_005B27F8();
        return -0x16;
    }
    D_008882C0.size = buffsize;
    req = &D_008882C0;
    req->count = buffcnt;
    if ((int)func_005B2258((int)D_008899C0, 0xFE, 0, (int)req, 8, (int)D_00888F00, 4, 0, 0, 0) < 0) {
        func_005B27F8();
        return -0xB;
    }
    ret = *(int *)((u32)D_00888F00 | 0x20000000);
    func_005B27F8();
    return ret;
}
