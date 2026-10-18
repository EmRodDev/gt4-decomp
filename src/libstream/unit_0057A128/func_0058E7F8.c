/* compiler: ee-gcc2.9-991111 */
/* Operation 14 carries a string, three flag bits and a copied 64-byte record.
 * Original record and argument names remain unknown. */
struct Client { char unknown0[0x24]; void *server; };
struct Metadata { int words[16]; };
struct Command {
    int argument0, argument1, flags, unknownC;
    struct Metadata *metadata;
    char text[1024];
};
extern struct Client D_0087E480;
extern struct Metadata D_0087E4C0;
extern struct Command D_0087E530;
extern int D_00657AF4, D_00657AF0, D_0087FA40;
extern int func_005ADCF0(int);
extern int func_005ADCC0(int);
extern void func_0058D748(void *);
extern void func_005ADF20(int);
extern char *func_005A6AB0(char *, const char *, unsigned);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_0058E7F8(int argument0, int argument1, const char *text,
                 const struct Metadata *metadata, unsigned flags) {
    if(!D_0087E480.server) return -100;
    if(func_005ADCF0(D_00657AF4)<0) return -200;
    if(!text || !*text) {func_005ADCC0(D_00657AF4);return -210;}
    flags&=7;
    D_0087E530.argument0=argument0;
    D_0087E530.argument1=argument1;
    D_0087E530.flags=flags;
    D_0087E4C0=*metadata;
    D_0087E530.metadata=&D_0087E4C0;
    func_005A6AB0(D_0087E530.text,text,1023);
    D_0087E530.text[1023]=0;
    func_005ADF20(0);
    if(func_005B19B0(&D_0087E480,14,1,&D_0087E530,0x414,&D_0087FA40,4,
        func_0058D748,0)) {func_005ADCC0(D_00657AF4);return -91;}
    D_00657AF0=14;
    return 0;
}
