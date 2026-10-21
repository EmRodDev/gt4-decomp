/* compiler: ee-gcc2.9-991111 */
struct Lib { int a, b; struct Lib *next; void *clients; char *name; };
struct Module { struct Module *next; int f4, f8, fC; unsigned int text_start; unsigned int text_size; };
struct G { struct Lib *libs; int f4; char pad[0x10]; struct Module *modules; int count; };
extern struct G D_00875898;
extern void func_005B0750(const char *, ...);
extern int func_005B72A8(void);
extern int func_005B72F8(void);

/* _sceErxReleaseModule */
void func_00585408(struct Module *mod)
{
    struct Lib *lib;
    struct Module *prev, *m;
    int intr;

    if (mod == 0)
        return;
    intr = func_005B72A8();
    for (lib = D_00875898.libs; lib != 0; lib = lib->next) {
        if ((unsigned int)lib >= mod->text_start && (unsigned int)lib < mod->text_start + mod->text_size) {
            func_005B72F8();
            func_005B0750("liberx: PANIC!! a library still remained in unloading module(%08x,%s)\n", lib, lib->name);
            while (1)
                ;
        }
    }
    prev = (struct Module *)&D_00875898.modules;
    while (prev->next != 0) {
        m = prev->next;
        if (m == mod) {
            prev->next = m->next;
            D_00875898.count--;
            if (intr)
                func_005B72F8();
            return;
        }
        prev = m;
    }
    if (!intr)
        return;
    func_005B72F8();
}
