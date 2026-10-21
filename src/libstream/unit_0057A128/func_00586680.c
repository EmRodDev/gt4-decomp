/* compiler: ee-gcc2.9-991111 */
struct Entry { int a, b, c; struct Entry *next; char *name; unsigned short version, flags; int x18, x1c; };
struct Lib { int a, b; struct Lib *next; struct Entry *clients; };
struct G { struct Lib *libs; int f4; struct Entry anchor; };
extern struct G D_00875898;
void func_005869A8(struct Entry *);
int func_00586D40(struct Lib *, struct Entry *);
void func_005ADF20(int);
int func_005B72A8(void);
int func_005B72F8(void);

/* _sceErxUnLinkLibraryClients */
int func_00586680(int *start, unsigned int size)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_00586680(int *start, unsigned int size) {
    int *end = start + (size >> 2);
    struct Lib *lib, *next;
    struct Entry *c, *e, *prev, *t, *n;
    int intr;

    intr = func_005B72A8();
    for (lib = D_00875898.libs; lib != 0; lib = next) {
        next = lib->next;
        for (c = lib->clients; c != 0; c = c->next) {
            if ((int *)c < start || (int *)c >= end)
                continue;
            if (func_00586D40(lib, c) == 0) {
                if (intr) func_005B72F8();
                func_005ADF20(2);
                return 0x81050053;
            }
            func_005869A8(c);
        }
    }
    prev = &D_00875898.anchor;
    while (prev->next != 0) {
        e = prev->next;
        if ((int *)e >= start && (int *)e < end) {
            e->flags &= ~4;
            func_005869A8(e);
            t = prev->next;
            n = t->next;
            t->next = 0;
            prev->next = n;
        } else {
            prev = e;
        }
    }
    if (intr) func_005B72F8();
    func_005ADF20(2);
    return 0;
}
