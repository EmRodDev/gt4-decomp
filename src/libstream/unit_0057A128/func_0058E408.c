/* compiler: ee-gcc2.9-991111 */
/* Operation 12 sends a bounded string and receives text through a separate
 * DMA buffer. The callback copies it to the caller's output, then signals
 * completion. Partial packet fields and operation meanings are provisional. */
struct Client { char unknown0[0x24]; void *server; };
struct Command {
    int argument0, argument1;
    char unknown8[8];
    char *response;
    char text[1024];
};
extern struct Client D_0087E480;
extern struct Command D_0087E530;
extern char D_0087EA40[1024], D_0087FA40;
extern int D_00657AF4, D_00657AF0;
extern int func_005ADCF0(int);
extern int func_005ADCC0(int);
extern char *func_005A6AB0(char *, const char *, unsigned int);
extern void func_005B0F78(void *, int);
extern void func_0058E378(char *);
extern int func_005B19B0(struct Client *, int, int, void *, int, void *, int,
    void (*)(char *), char *);
int func_0058E408(int argument0, int argument1, const char *text, char *output) {
    if (!D_0087E480.server) return -100;
    if (func_005ADCF0(D_00657AF4) < 0) return -200;
    if (!text || !*text) {
        func_005ADCC0(D_00657AF4);
        return -210;
    }
    D_0087E530.argument0 = argument0;
    D_0087E530.argument1 = argument1;
    D_0087E530.response = D_0087EA40;
    func_005A6AB0(D_0087E530.text, text, 1023);
    D_0087E530.text[1023] = 0;
    func_005B0F78(D_0087EA40, 1024);
    if (func_005B19B0(&D_0087E480, 12, 1, &D_0087E530, 1044,
                     &D_0087FA40, 4, func_0058E378, output)) {
        func_005ADCC0(D_00657AF4);
        return -91;
    }
    D_00657AF0 = 12;
    return 0;
}
