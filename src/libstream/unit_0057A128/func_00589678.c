/* compiler: ee-gcc2.9-991111 */
struct Ops { int x0; int (*close)(int, int); };
struct S { unsigned char mode; char p1[0xb]; const unsigned char *path; int x10; int data; unsigned flags; char p1c[0x14]; struct Ops *ops; int ctx; };
struct Mod { char pad[10]; unsigned short flags; };
struct Stat { unsigned mode; char pad4[0x24]; int x28, x2c; char pad30[0x10]; };
int func_00588960(struct S *);
int func_00588B10(struct Ops *, int, const unsigned char *, int *);
struct Mod *func_00588F20(struct S *, int, int, void *, unsigned short *, int *);
struct Mod *func_00589128(struct S *, int, void *, unsigned short *, int *);
void func_0058B1C8(struct Mod *);
int func_005B49D8(const unsigned char *, struct Stat *);
int func_005B72A8(void);
int func_005B72F8(void);
int func_005B9548(void *, int);
struct Mod * __attribute__((register_precision ($16, 128))) func_00589678(struct S *s, int *err) {
    char header[0x40];
    struct Stat st;
    struct { int length; unsigned short flags; } load;
    int fd = 1;
    struct Mod *m;
    *err = 0x8105902c;
    switch (s->mode) {
    case 3:
    case 1:
        fd = -1;
        load.length = s->data;
        break;
    default: {
        int kind;
        if (!s->path) return 0;
        kind = func_00588960(s);
        if (kind < 0) { *err = kind; return 0; }
        if (kind == 1) {
            unsigned permissions;
            if (!(s->flags & 0x2000)) { *err = 0x81050001; return 0; }
            kind = func_005B49D8(s->path, &st);
            if (kind < 0) { *err = func_005B9548(0, kind); return 0; }
            permissions = st.mode;
            if (st.x28 == 0xffff) permissions >>= 6;
            else if (st.x2c == 0xffff) permissions >>= 3;
            if ((permissions & 5) != 5) { *err = 0x8105000d; return 0; }
        } else if (kind == 2 && !(s->flags & 0x4000)) {
            *err = 0x81050001; return 0;
        }
        fd = func_00588B10(s->ops, s->ctx, s->path, &load.length);
        if (fd < 0) { *err = fd; return 0; }
        break;
    }
    }
    m = 0;
    switch (s->flags & 0xf00) {
    case 0:
        m = func_00588F20(s, fd, load.length, header, &load.flags, err);
        break;
    case 0x100:
    case 0x200:
        m = func_00589128(s, fd, header, &load.flags, err);
        break;
    }
    if (fd != -1) s->ops->close(s->ctx, fd);
    if (!m) return 0;
    *err = 0;
    {
        int intr = func_005B72A8();
        m->flags = load.flags;
        func_0058B1C8(m);
        if (intr) func_005B72F8();
    }
    return m;
}
