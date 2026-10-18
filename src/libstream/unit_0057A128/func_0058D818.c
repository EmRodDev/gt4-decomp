/* compiler: ee-gcc2.9-991111 */
/* Synchronous operation 21: serialize the shared packet, submit the RPC,
 * release the semaphore, then return the server's result word. */
struct Client { char unknown0[0x24]; void *server; };
struct Command { int argument0, argument1; char unknown8[40]; };
extern struct Client D_0087E480;
extern struct Command D_0087E500;
extern int D_00657AF4, D_0087FA40;
extern int func_005ADCF0(int);
extern int func_005ADCC0(int);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_0058D818(int argument) {
    if(!D_0087E480.server) return -100;
    if(func_005ADCF0(D_00657AF4)<0) return -200;
    D_0087E500.argument1=argument;
    if(func_005B19B0(&D_0087E480,21,0,&D_0087E500,48,&D_0087FA40,4,0,0)) {
        func_005ADCC0(D_00657AF4);
        return -91;
    }
    func_005ADCC0(D_00657AF4);
    return D_0087FA40;
}
