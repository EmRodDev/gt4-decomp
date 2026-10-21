/* compiler: ee-gcc2.9-991111 */
struct Packet { int socket; int result; char pad[0x88]; };
extern struct Packet D_00882EC0;
extern char D_00882DC0[];
extern int D_00885280;
void func_00590950(char *, ...);
void func_005ADCC0(int);
int func_005ADCE0(int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);
int func_0058FF90(int socket) {
    struct Packet *p;
    int r;
    func_005ADCE0(D_00885280);
    p = &D_00882EC0;
    p->socket = socket;
    if (func_005B19B0(D_00882DC0, 0x80001315, 0, p, 0x90, p, 0x90, 0, 0) < 0) {
        func_00590950("sceDbcInitSocket: rpc error\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    r = p->result;
    func_005ADCC0(D_00885280);
    return r;
}
