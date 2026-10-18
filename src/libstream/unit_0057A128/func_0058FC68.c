/* compiler: ee-gcc2.9-991111 */
/* Synchronous shared-buffer RPC: serialize request/result access and report
 * a diagnostic on transport failure. Names are provisional layout views. */
struct Client { char unknown0[0x28]; };
struct Packet { int argument, result; char unknown8[0x88]; };
extern int D_00657B50, D_00885280;
extern struct Client D_00882DC0;
extern struct Packet D_00882EC0;
extern const char D_006CF4D8[];
extern int func_005ADCE0(int);
extern int func_005ADCC0(int);
extern int func_00590950(const char *);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_0058FC68(int argument) {
    int result;
    if(!D_00657B50) return 0;
    func_005ADCE0(D_00885280);
    D_00882EC0.argument=argument;
    if(func_005B19B0(&D_00882DC0,0x80001302,0,&D_00882EC0,0x90,
        &D_00882EC0,0x90,0,0)<0) {
        func_00590950(D_006CF4D8);
        func_005ADCC0(D_00885280);
        return 0;
    }
    result=D_00882EC0.result;
    func_005ADCC0(D_00885280);
    return result;
}
