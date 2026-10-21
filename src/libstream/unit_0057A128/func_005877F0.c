/* compiler: ee-gcc2.9-991111 */
struct LoadReq { char pad[0x2C]; int result; };
struct ModLoad { int tid; int f4; int done_sema; int sema; struct LoadReq *req; };
extern struct ModLoad D_0087E180;
extern int func_005ADB90(void);
extern void func_005ADCC0(int);
extern int func_005ADCE0(int);
extern int func_005ADCF0(int);

/* _sceErxSync */
int func_005877F0(unsigned int mode, int *result)
{
    struct LoadReq *req;

    if (D_0087E180.tid < 0)
        return 0x81058001;
    if (func_005ADB90() == D_0087E180.tid)
        return 0x8105002D;
    if (mode >= 2)
        return 0x81050016;
    if (result == 0)
        return 0x8105000E;
    if (D_0087E180.req == 0)
        return 0x81050003;
    if (mode == 0) {
        func_005ADCE0(D_0087E180.sema);
    } else if (mode == 1) {
        if (func_005ADCF0(D_0087E180.sema) < 0)
            return 1;
    }
    req = D_0087E180.req;
    D_0087E180.req = 0;
    *result = req->result;
    func_005ADCC0(D_0087E180.done_sema);
    return 0;
}
