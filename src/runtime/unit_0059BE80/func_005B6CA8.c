/* compiler: ee-gcc2.9-991111 */
struct RpcBuf { int result; int value; char name[0xFC]; char name2[0xFC]; };
struct Result { int result; int value; };
extern struct RpcBuf D_00889C80;
extern int D_00889E80;
extern int func_005B6268(void);
extern int func_005B6368(void);
extern char *func_005A6AB0(char *, const char *, unsigned int);
extern int func_005B19B0(void *, int, unsigned int, void *, int, void *, int, void *, void *);
int func_005B6CA8(const char *name, const char *name2, struct Result *out, int fno) {
    if (func_005B6268() < 0) return -0x10000;
    if (func_005B6368() != 0) return -0x10004;
    func_005A6AB0(D_00889C80.name, name, 0xFC);
    D_00889C80.name[0xFB] = 0;
    func_005A6AB0(D_00889C80.name2, name2, 0xFC);
    D_00889C80.name2[0xFB] = 0;
    if (func_005B19B0(&D_00889E80, fno, 0, &D_00889C80, 0x200, &D_00889C80, 0x10, 0, 0) < 0) return -0x10001;
    if (D_00889C80.result == 0) return -0x10003;
    out->result = D_00889C80.result;
    out->value = D_00889C80.value;
    return 0;
}
