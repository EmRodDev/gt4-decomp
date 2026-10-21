/* compiler: ee-gcc2.96-stl */
typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

extern char D_00645440[];
extern char D_00696BF0[];
extern char D_00696C08[];
extern char D_00696C10[];
extern char D_00696C28[];
extern char D_00696C40[];
extern char D_00696C48[];
extern char D_006959E0[];

extern "C" s32 func_001F1578(s32);
extern "C" void func_0023B1D8(void *, int);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(void *, const char *, const char *);
extern "C" s32 func_004EEAB0(void *, char *);
extern "C" s32 func_004EF410(void *, char *, char *, s32);
extern "C" int func_0057DA20(char *, const char *, ...);

struct ScopedHandle {
    void *p; char pad[12];
    ScopedHandle() { func_0023B478(this); }
    ~ScopedHandle() { func_0023B1D8(this, 2); }
    void show(const char *a, const char *b) { func_0023CA78(p, a, b); }
};
extern "C" s32 func_001F11E8(s32 arg0) {
    char key[16];
    if (func_004EEAB0(D_00645440, key)) {
        char buf[128]; char text[128];
        func_004EF410(D_00645440, key, buf, 128);
        func_0057DA20(text, D_00696BF0, buf);
        ScopedHandle h;
        h.show(text, D_00696C08);
    } else {
        ScopedHandle h;
        h.show(D_00696C10, D_00696C08);
    }
    char text[128];
    func_0057DA20(text, D_00696C28, func_001F1578(arg0) ? D_00696C40 : D_00696C48);
    ScopedHandle h;
    h.show(text, D_006959E0);
    return 1;
}
