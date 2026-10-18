/* compiler: ee-gcc2.9-991111 */
/* Bind an RPC client until its server pointer becomes available. The delay
 * counter is volatile because this is a polling delay with observable loads. */
struct Client { char unknown0[0x24]; void *server; };
extern struct Client D_0087E3D0;
extern int func_005B17D0(struct Client *, int, int);
int func_0058BCE8(int server_id) {
    volatile int delay;
    D_0087E3D0.server=0;
    while (func_005B17D0(&D_0087E3D0,server_id,0), !D_0087E3D0.server) {
        delay=100000;
        while(--delay>0) {}
    }
    return 0;
}
