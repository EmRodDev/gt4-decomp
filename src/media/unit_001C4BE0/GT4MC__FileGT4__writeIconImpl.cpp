/* compiler: ee-gcc2.96-no-strict-aliasing */

struct Entry { short delta, index; int (*fn)(void*,...); };

struct Self {
    char pad[0x24];
    char name[0x28];
    Entry *vt;
};

struct File {
    Entry *vt;
};

struct sceMcIconSys {
    int header[0x104 / 4];
    char icon_file[64];    /* 0x104: main 3D icon name */
    char icon_copy[64];    /* 0x144: copy animation icon */
    char icon_del[64];     /* 0x184: delete animation icon */
};

extern "C" void func_0057DA20(char*, const char*, ...) throw();
extern "C" void *func_005A48D8(void*, int, unsigned);
extern "C" char *func_005A609C(char*, const char*);
extern char D_00694E00[];  /* "icon%d.ico" */
extern char D_00694DA8[];  /* "/%s/%s" */
extern char D_00694E10[];  /* "/%s/icon.sys" */

extern "C" int GT4MC__FileGT4__writeIconImpl(Self *self, File *file, sceMcIconSys *icon, int arg3) {
    char path[0x50];
    char raw[0x410];
    int i = 0;
    Entry *e = self->vt + 28;
    int n = e->fn((char*)self + e->delta);

    if (n > 0) {
        char *p = icon->icon_file;
        char *first = p;
        for (; i < n; i++) {
            func_0057DA20(p, D_00694E00, i);
            if (i == 0) {
                func_005A609C(icon->icon_copy, first);
                func_005A609C(icon->icon_del, first);
            }
            char *old = p;
            p += 0x40;
            func_0057DA20(path, D_00694DA8, self->name, old);
            Entry *v = self->vt + 30;
            int r = v->fn((char*)self + v->delta, file, path, i, arg3);
            if (r == 0) return r;
        }
    }
    func_0057DA20(path, D_00694E10, self->name);
    char *aligned = (char*)((unsigned)(raw + 0x3f) & ~0x3f);
    func_005A48D8(aligned, 0, 0x3c4);
    *(sceMcIconSys*)aligned = *icon;
    Entry *v = file->vt + 16;
    return v->fn((char*)file + v->delta, path, aligned, 0x3c4) == 0;
}
