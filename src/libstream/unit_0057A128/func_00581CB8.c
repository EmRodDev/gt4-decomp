/* compiler: ee-gcc2.9-as296 */
typedef unsigned char u8;
typedef struct { int a; int b; int c; u8 s0; u8 s1; u8 s2; u8 pad; void *buf; } Cmd;
extern Cmd D_00655FC0;
extern char D_006CE2C0[];
extern volatile int D_00655EF8;
extern volatile int D_00655EF4;
extern volatile int D_00655F20;
extern int D_00655ED0;
extern volatile int D_00655EE8;
extern Cmd D_00655FC0;
extern char D_00656FC0[];
extern char D_00657090[];
int func_00580928(void);
int func_005807D0(int);
void func_00580120(int a);
void func_005ADCC0(int);
void func_005B0750(const char *, ...);
void func_005B0F78(void *, int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

int func_00581CB8(int a, int b, void *c, u8 *p, int flag) {
    Cmd *cmd = &D_00655FC0;
    int result;
    int m;
    int len;
    char *buf;
    if (!(D_00655EF8 & 1)) {
        if (func_00580928() == 6) return 0;
    }
    result = func_005807D0(7);
    if (!result) return 0;
    cmd->a = a;
    cmd->b = b;
    cmd->c = (int)c;
    cmd->s0 = p[0];
    cmd->s1 = p[1];
    cmd->s2 = p[2];
    cmd->buf = D_00656FC0;
    m = p[2];
    switch (m) {
    case 0: len = b * 0x930; break;
    case 1: len = b * 0x940; break;
    case 2: len = b * 0x990; break;
    default: len = b * 0x930; break;
    }
    if (!(D_00655EF8 & 2)) func_005B0F78(c, len);
    buf = D_00656FC0;
    func_005B0F78(buf, 0x90);
    func_005B0F78(cmd, 0x18);
    D_00655EF4 = 1;
    if (flag == 0) {
        D_00655F20 = 2;
        if (func_005B19B0(D_00657090, 2, 1, cmd, 0x18, 0, 0, (void *)func_00580120, buf) < 0) {
            D_00655F20 = 0;
            D_00655EF4 = 0;
            func_005ADCC0(D_00655EE8);
            return 0;
        }
    } else {
        D_00655F20 = 12;
        if (func_005B19B0(D_00657090, 16, 1, cmd, 0x18, 0, 0, (void *)func_00580120, buf) < 0) {
            D_00655F20 = 0;
            D_00655EF4 = 0;
            func_005ADCC0(D_00655EE8);
            return 0;
        }
    }
    if (D_00655ED0 > 0) func_005B0750(D_006CE2C0);
    return 1;
}
