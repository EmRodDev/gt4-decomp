/* compiler: ee-gcc2.9-991111 */
/* Stop both channels before clearing the library's initialized flag.
 * Layout and state value 3 are provisional views of the channel records. */
struct Channel { int unknown0, state; char unknown8[0x20]; };
extern struct Channel D_0087E3F8[2];
extern int D_00657AAC;
extern int func_0058C740(int);
extern int func_0058C518(int);
extern int func_0058C690(int);
int func_0058C088(void) {
    int i;
    for(i=0; i<2; ++i) {
        if(func_0058C740(i)==3) func_0058C518(i);
        if(D_0087E3F8[i].state==3) func_0058C690(i);
    }
    D_00657AAC=0;
    return 0;
}
