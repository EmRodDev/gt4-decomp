/* compiler: ee-gcc2.9-991111 */
/* SIF reboot command. Layout follows the packet fields and DMA descriptor in
 * the executable; names are provisional pending SDK header identification. */
typedef unsigned int u32;
struct Packet {
    unsigned long long size:8;
    unsigned long long data_size:24;
    unsigned long long destination:32;
    u32 command, option;
    int argument_length, mode;
    char arguments[80];
};
struct Dma { void *source; u32 destination; int size, attributes; };
extern struct Packet D_00889EC0;
extern void func_005B94A0(int, int);
extern void func_005ADF70(void);
extern u32 func_005AE0B0(int);
extern void func_005AE0A0(u32, u32);
extern int func_005AE060(struct Dma *, int);
extern void func_005B0F78(void *, int);
int func_005B6FC8(char *arguments, int mode) {
    struct Dma transfer;
    u32 destination;
    int length;
    func_005B94A0(0,0);
    func_005B94A0(1,0);
    func_005ADF70();
    destination=func_005AE0B0(0x80000000);
    D_00889EC0.mode=mode;
    for(length=0; arguments[length]; ++length)
        D_00889EC0.arguments[length]=arguments[length];
    D_00889EC0.destination=0;
    D_00889EC0.argument_length=length;
    D_00889EC0.command=0x80000003;
    D_00889EC0.data_size=0;
    D_00889EC0.size=104;
    transfer.source=&D_00889EC0;
    transfer.destination=destination;
    transfer.size=104;
    transfer.attributes=0x44;
    func_005B0F78(&D_00889EC0,104);
    func_005AE0A0(4,0x40000);
    if(func_005AE060(&transfer,1)) {
        func_005AE0A0(4,0x10000);
        func_005AE0A0(4,0x20000);
        func_005AE0A0(0x80000002,0);
        func_005AE0A0(0x80000000,0);
        return 1;
    }
    return 0;
}
