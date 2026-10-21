/* compiler: ee-gcc2.9-991111 */
struct Entry { char pad[8]; struct Entry *next; int unkC; char *name; unsigned short version; };
extern int D_00657A80;
extern struct Entry *D_00875898;
extern int func_0057F238(const char *, const char *);
extern int func_005B72A8(void);
extern int func_005B72F8(void);
struct Entry *func_00586030(const char *name, unsigned short version) {
    int intr;
    struct Entry *p;
    if (D_00657A80) {
        intr = func_005B72A8();
        p = D_00875898;
        for (; p; p = p->next) {
            if (func_0057F238(p->name, name) == 0) {
                if ((p->version >> 8) == (version >> 8)) {
                    if (intr) func_005B72F8();
                    return p;
                }
            }
        }
        if (intr) func_005B72F8();
    }
    return 0;
}
