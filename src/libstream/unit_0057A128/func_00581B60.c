/* compiler: ee-gcc2.9-as296 */
typedef unsigned char u8;
typedef struct { int a; int b; int c; u8 s0; u8 s1; u8 s2; u8 pad; void *buf; int *res; } Cmd;
extern Cmd D_00655FC0;
extern volatile int D_00655EF8;
extern volatile int D_00655EF4;
extern volatile int D_00655F20;
extern int D_00655ED0;
extern volatile int D_00655EE8;
extern char D_00656FC0[];
extern int D_00657080;
extern char D_00657090[];
int func_00580928(void);
int func_005807D0(int);
void func_0057FF10(int a);
void func_005ADCC0(int);
void func_005B0750(const char *, ...);
void func_005B0F78(void *, int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

/* sceCdReadIOPm */
int func_00581B60(unsigned int lbn, unsigned int sectors, void *buf, u8 *mode)
{
    Cmd *cmd = &D_00655FC0;

    if (!(D_00655EF8 & 1)) {
        if (func_00580928() == 6) return 0;
    }
    if (!func_005807D0(5)) return 0;
    cmd->a = lbn;
    cmd->b = sectors;
    cmd->c = (int)buf;
    cmd->s0 = mode[0];
    cmd->s1 = mode[1];
    cmd->s2 = mode[2];
    cmd->buf = D_00656FC0;
    cmd->res = &D_00657080;
    func_005B0F78(cmd, 0x18);
    D_00655F20 = 1;
    D_00655EF4 = 1;
    if (func_005B19B0(D_00657090, 0xD, 1, cmd, 0x18, 0, 0, (void *)func_0057FF10, (void *)&D_00655F20) < 0) {
        D_00655F20 = 0;
        D_00655EF4 = 0;
        func_005ADCC0(D_00655EE8);
        return 0;
    }
    if (D_00655ED0 > 0) func_005B0750("cdread end\n");
    return 1;
}
