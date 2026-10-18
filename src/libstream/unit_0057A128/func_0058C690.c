/* compiler: ee-gcc2.9-991111 */
/* Close one channel through operation 6. Preserve the server's distinguished
 * failure results and update the local channel state only after success. */
struct Channel { int unknown0, state; char unknown8[0x20]; };
extern struct Channel D_0087E3F8[2];
extern int func_0058C740(int);
extern int func_0058BD78(int, int, int, int, int, int *, int);
int func_0058C690(int channel) {
    int result;
    struct Channel *entry=&D_0087E3F8[channel];
    if(!func_0058C740(channel)) return -36924;
    if(func_0058BD78(channel,6,0,0,1,&result,1)<0) return -32778;
    if(result==-2) return -32779;
    if(result==-1) return -36924;
    entry->state=2;
    return 0;
}
