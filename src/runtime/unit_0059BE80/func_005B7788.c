/* compiler: ee-gcc2.9-991111 */
extern char *D_00659690;
struct Args { int x; int y; };
extern struct Args D_00658B40;
extern int func_005B7778(int, int);
extern int func_005B7738(void *, const void *, int);
extern int func_0057F260(const char *);
char *func_005B7788(const char *name, int argc, const char **argv) {
    char *table = D_00659690;
    struct Args *config = &D_00658B40;
    char *out = table + 0x40;
    char *end = out;
    int len;
    const char **arg;
    func_005B7778(config->x, config->y);
    if (argc >= 16) argc = 15;
    func_005B7738(table, &out, 4);
    table += 4;
    len = func_0057F260(name) + 1;
    func_005B7738(out, name, len);
    out += len;
    if (argc > 0) {
        arg = argv;
        do {
            func_005B7738(table, &out, 4);
            table += 4;
            argc--;
            len = func_0057F260(*arg) + 1;
            func_005B7738(out, *arg, len);
            arg++;
            out += len;
        } while (argc != 0);
    }
    return end;
}
