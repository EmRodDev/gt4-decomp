/* compiler: ee-gcc2.9-991111 */
/* Operation 1 requests up to three optional result words. Keep their output
 * pointers for the completion callback and pass presence flags in the packet. */
struct Client { char unknown0[0x24]; void *server; };
struct Command {
    int unknown0, argument0, argument1, want2, want1, want0;
    int unknown18;
    void *scratch;
    char unknown20[16];
};
extern struct Client D_0087E480;
extern struct Command D_0087E500;
extern char D_0087E980[0xC0];
extern int *D_0087E4A8, *D_0087E4AC, *D_0087E4B0;
extern int D_00657AF4, D_00657AF0, D_0087FA40;
extern int func_005ADCF0(int);
extern int func_005ADCC0(int);
extern void func_005B0F78(void *, int);
extern void func_0058DFE0(void *);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_0058E038(int argument0, int argument1, int *output0, int *output1, int *output2) {
    if(!D_0087E480.server) return -100;
    if(func_005ADCF0(D_00657AF4)<0) return -200;
    D_0087E500.argument0=argument0;
    D_0087E500.argument1=argument1;
    D_0087E500.scratch=D_0087E980;
    if(output0) D_0087E500.want0=1; else D_0087E500.want0=0;
    if(output1) D_0087E500.want1=1; else D_0087E500.want1=0;
    if(output2) D_0087E500.want2=1; else D_0087E500.want2=0;
    D_0087E4A8=output0;
    D_0087E4AC=output1;
    D_0087E4B0=output2;
    func_005B0F78(D_0087E980,0xC0);
    if(func_005B19B0(&D_0087E480,1,1,&D_0087E500,48,&D_0087FA40,4,
        func_0058DFE0,D_0087E980)) {
        func_005ADCC0(D_00657AF4);return -91;
    }
    D_00657AF0=1;
    return 0;
}
