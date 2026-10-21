/* compiler: ee-gcc2.9-991111 */
struct Entry { int a, b, c; struct Entry *next; char *name; unsigned short version, flags; int x18, x1c; };
struct G { char pad[0x14]; struct Entry *head; };
extern int D_00657A80;
extern struct G D_00875898;
void func_005869A8(struct Entry *);
int func_00586AE0(struct Entry *);
int func_00586B80(struct Entry *);
void func_0058B2B0(struct Entry *, unsigned);
void func_005ADF20(int);
void func_005B0750(const char *, ...);
int func_005B72A8(void);
int func_005B72F8(void);
/* Preserve the full SDK callee-saved registers. Repeat s0 to work around
   the 991111 attribute-list overwrite, as in adjacent SDK functions. */
int func_005864E0(struct Entry *start, unsigned bytes, int mode)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_005864E0(struct Entry *start, unsigned bytes, int mode) {
    int n = bytes >> 2;
    struct Entry *p;
    int intr, result;
    if (!D_00657A80) return 0x81058001;
    p = start;
    intr = func_005B72A8();
    result = 0;
    for (; n > 0; p++, n -= 8) {
        if (func_00586AE0(p) < 0) { result = 0x81059039; break; }
        if ((p->flags & 2) && ((*(unsigned *)&p->version & 0x30000) != 0x20000)) continue;
        if (func_00586B80(p) == 1) {
            if (mode) p->flags |= 8;
        } else if (mode) {
            func_005869A8(p);
            p->flags |= 0xC;
            p->next = D_00875898.head;
            D_00875898.head = p;
        } else {
            unsigned v = p->version;
            func_005B0750("link failed: \"%s\" (%d.%d)\n", p->name, v >> 8, v & 255);
            func_0058B2B0(start, bytes);
            if (intr) func_005B72F8();
            return 0x81059037;
        }
    }
    func_005ADF20(2);
    if (intr) func_005B72F8();
    return result;
}
