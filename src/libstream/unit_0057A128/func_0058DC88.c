/* compiler: ee-gcc2.9-991111 */
/* Operation 5 submits a caller buffer plus a cache-visible scratch area.
 * Pointer and size fields follow the packet; their original names are unknown. */
struct Client { char unknown0[0x24]; void *server; };
struct Command {
    int argument;
    char unknown4[8];
    int size;
    char unknown10[8];
    void *buffer, *scratch;
    char unknown20[16];
};
extern struct Client D_0087E480;
extern struct Command D_0087E500;
extern char D_0087E980[0xC0];
extern int D_00657AF4, D_00657AF0, D_0087FA40;
extern void func_0058DBD8(void *);
extern int func_005ADCF0(int);
extern int func_005ADCC0(int);
extern void func_005B0F78(void *, int);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_0058DC88(int argument, void *buffer, int size) {
    if(!D_0087E480.server) return -100;
    if(func_005ADCF0(D_00657AF4)<0) return -200;
    D_0087E500.argument=argument;
    D_0087E500.buffer=buffer;
    D_0087E500.size=size;
    D_0087E500.scratch=D_0087E980;
    func_005B0F78(buffer,size);
    func_005B0F78(D_0087E980,0xC0);
    if(func_005B19B0(&D_0087E480,5,1,&D_0087E500,48,&D_0087FA40,4,
        func_0058DBD8,D_0087E980)) {
        func_005ADCC0(D_00657AF4);
        return -91;
    }
    D_00657AF0=5;
    return 0;
}
