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
void func_00580120(int a);
void func_005ADCC0(int);
void func_005B0750(const char *, ...);
void func_005B0F78(void *, int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

/* sceCdRead */
int func_00581980(unsigned int lbn, unsigned int sectors, void *buf, u8 *mode)
{
    Cmd *cmd = &D_00655FC0;
    int len;
    char *data;

    if (!(D_00655EF8 & 1)) {
        if (func_00580928() == 6) return 0;
    }
    if (!func_005807D0(4)) return 0;
    cmd->a = lbn;
    cmd->b = sectors;
    cmd->c = (int)buf;
    cmd->s0 = mode[0];
    cmd->s1 = mode[1];
    cmd->s2 = mode[2];
    cmd->buf = D_00656FC0;
    cmd->res = &D_00657080;
    switch (mode[2]) {
    case 0: len = sectors << 11; break;
    case 1: len = sectors * 0x918; break;
    case 2: len = sectors * 0x924; break;
    default: len = sectors << 11; break;
    }
    D_00657080 = 0;
    if (!(D_00655EF8 & 2)) func_005B0F78(buf, len);
    data = D_00656FC0;
    func_005B0F78(data, 0x90);
    func_005B0F78(cmd, 0x18);
    func_005B0F78(&D_00657080, 4);
    if (D_00655ED0 > 0) func_005B0750("call cdread cmd\n");
    D_00655F20 = 1;
    D_00655EF4 = 1;
    if (func_005B19B0(D_00657090, 1, 1, cmd, 0x18, 0, 0, (void *)func_00580120, data) < 0) {
        D_00655F20 = 0;
        D_00655EF4 = 0;
        func_005ADCC0(D_00655EE8);
        return 0;
    }
    if (D_00655ED0 > 0) func_005B0750("cdread end\n");
    return 1;
}
