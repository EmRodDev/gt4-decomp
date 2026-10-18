/* compiler: ee-gcc2.9-991111 */
/* Submit operation 14 with flag 16 and two string fields; completion is tagged
 * as pending operation 19. The metadata prefix is deliberately left intact. */
struct Client { char unknown0[0x24]; void *server; };
struct Metadata { char unknown0[32]; char text[32]; };
struct Command { int argument0, argument1, flags, unknownC; struct Metadata *metadata; char text[1024]; };
extern struct Client D_0087E480;
extern struct Metadata D_0087E4C0;
extern struct Command D_0087E530;
extern int D_00657AF4, D_00657AF0, D_0087FA40;
extern int func_005ADCF0(int);
extern int func_005ADCC0(int);
extern void func_005ADF20(int);
extern void func_0058D748(void *);
extern char *func_005A6AB0(char *, const char *, unsigned);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_0058E9C8(int argument0, int argument1, const char *text, const char *metadata_text) {
    if(!D_0087E480.server) return -100;
    if(func_005ADCF0(D_00657AF4)<0) return -200;
    if(!text || !*text || !metadata_text) {func_005ADCC0(D_00657AF4);return -210;}
    D_0087E530.argument0=argument0;
    D_0087E530.argument1=argument1;
    D_0087E530.flags=16;
    func_005A6AB0(D_0087E530.text,text,1023);
    D_0087E530.text[1023]=0;
    func_005A6AB0(D_0087E4C0.text,metadata_text,32);
    D_0087E530.metadata=&D_0087E4C0;
    func_005ADF20(0);
    if(func_005B19B0(&D_0087E480,14,1,&D_0087E530,0x414,&D_0087FA40,4,
        func_0058D748,0)) {func_005ADCC0(D_00657AF4);return -91;}
    D_00657AF0=19;
    return 0;
}
