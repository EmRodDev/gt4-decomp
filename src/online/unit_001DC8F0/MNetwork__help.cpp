typedef int s32;

struct Str {
    char *p;
    char pad[0xC];
};

struct Cmd {
    const char *name;
    const char *usage;
    const char *help;
};

extern char D_006959D8[];
extern char D_006959E0[];
extern char D_00695F58[];
extern char D_00695F60[];
extern char D_00695F68[];
extern Cmd D_00695E68[];

extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" void func_0023B1D8(void *, int) throw();
extern "C" void func_0023B478(void *) throw();
extern "C" void func_0023CA78(void *, const char *, const char *) throw();
extern "C" void func_00312318(void *, int) throw();
extern "C" void func_00312370(void *, void *) throw();
extern "C" Str *func_00314920(void *) throw();
extern "C" void func_0057DA20(void *, const char *, ...) throw();
extern "C" s32 func_0057F238(const char *, const char *) throw();
extern "C" void func_005A609C(void *, const char *) throw();
extern "C" void func_005D4AD8(const char *, ...) throw();

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

extern "C" void MNetwork__help(void *arg0, void *arg1, s32 arg2, void *arg3) {
    Str sp0;
    Str h;
    char buf[0x80];
    const char *cmd = 0;
    int i;
    Cmd *e;
    func_001DC650(&sp0, arg1);
    if (arg2 > 0) {
        Str *ph = &h;
        func_00312370(ph, arg3);
        cmd = c_str(func_00314920(ph->p));
        func_00312318(ph, 2);
    }
    i = 0;
    if (cmd == 0) {
        for (;;) {
            Cmd *c = &D_00695E68[i];
            if (c->name == 0) break;
            i++;
            func_005A609C(buf, c->name);
            func_005D4AD8(D_00695F58, buf);
            Str *ph = &h;
            func_0023B478(ph);
            func_0023CA78(ph->p, buf, D_006959E0);
            func_0023B1D8(ph, 2);
        }
    } else {
    search:
        e = &D_00695E68[i++];
        if (e->name != 0 && func_0057F238(cmd, e->name) != 0) goto search;
        const char *name = e->name;
        if (name != 0) {
            func_0057DA20(buf, D_00695F60, name, e->usage);
            func_005D4AD8(D_00695F58, buf);
            Str *ph = &h;
            func_0023B478(ph);
            func_0023CA78(ph->p, buf, D_006959E0);
            func_0023B1D8(ph, 2);
            func_005A609C(buf, e->help);
            func_005D4AD8(D_00695F58, buf);
            func_0023B478(ph);
            func_0023CA78(ph->p, buf, D_006959E0);
            func_0023B1D8(ph, 2);
        } else {
            func_0057DA20(buf, D_00695F68, cmd);
            func_005D4AD8(D_00695F58, buf);
            Str *ph = &h;
            func_0023B478(ph);
            func_0023CA78(ph->p, buf, D_006959E0);
            func_0023B1D8(ph, 2);
        }
    }
    func_001DC5F8(&sp0, 2);
}
