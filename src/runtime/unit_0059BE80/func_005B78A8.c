/* compiler: ee-gcc2.9-991111 */
extern char D_006D2910[];
extern char *D_00659690;
extern char *func_005B7788(const char *, int, const char **);
extern void func_005B78A0(void);
extern int func_005AD8F0(int, int, int, void *);
int func_005B78A8(int a, int b, int n, const char **v) {
    func_005B7788(D_006D2910, n, v);
    func_005B78A0();
    return func_005AD8F0(a, b, n, D_00659690 + 4);
}
