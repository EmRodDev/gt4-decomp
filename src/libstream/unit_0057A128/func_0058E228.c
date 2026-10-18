/* compiler: ee-gcc2.9-991111 */
/* Operation 13 carries a string and a buffer of 64-byte records. A negative
 * record count skips cache writeback, preserving the original request mode. */
struct Client { char unknown0[0x24]; void *server; };
struct Metadata { int words[16]; };
struct Command {
    int argument0, argument1, argument2, record_count;
    struct Metadata *records;
    char text[1024];
};
extern struct Client D_0087E480;
extern struct Command D_0087E530;
extern int D_00657AF4, D_00657AF0, D_0087FA40;
extern int func_005ADCF0(int);
extern int func_005ADCC0(int);
extern char *func_005A6AB0(char *, const char *, unsigned);
extern void func_005B0F78(void *, int);
extern void func_0058D748(void *);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(void *), void *);
int func_0058E228(int argument0, int argument1, const char *text,
                 int argument2, int record_count, struct Metadata *records) {
    if(!D_0087E480.server) return -100;
    if(func_005ADCF0(D_00657AF4)<0) return -200;
    if(!text || !*text) {func_005ADCC0(D_00657AF4);return -210;}
    D_0087E530.argument0=argument0;
    D_0087E530.argument1=argument1;
    D_0087E530.argument2=argument2;
    D_0087E530.record_count=record_count;
    D_0087E530.records=records;
    func_005A6AB0(D_0087E530.text,text,1023);
    D_0087E530.text[1023]=0;
    if(record_count>=0) func_005B0F78(records,record_count*sizeof(*records));
    if(func_005B19B0(&D_0087E480,13,1,&D_0087E530,0x414,&D_0087FA40,4,
        func_0058D748,0)) {func_005ADCC0(D_00657AF4);return -91;}
    D_00657AF0=13;
    return 0;
}
