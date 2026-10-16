/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

extern Rep D_00659FA8;
extern char D_00693270[];
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_00447C78(const char *);
extern "C" const char *func_00447F08(s32);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

struct String {
    char *p;
    String(const char *s);
    String(const String &);
    ~String();
    Rep *rep() { return (Rep *)p - 1; }
    s32 length() { return rep()->len; }
    const char *c_str();
};
extern "C" String *func_005C2630(String *, u32, u32, const char *, u32);
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
inline const char *String::c_str() {
    if (length() == 0) return D_00693270;
    rep_data(rep())[length()] = 0;
    return rep_data(rep());
}
static inline char *grab(Rep *r) {
    if (r->sel)
        return func_005C2560(r);
    ++r->ref;
    return rep_data(r);
}
inline String::String(const char *s) {
    p = grab(&D_00659FA8);
    func_005C2630(this, 0, (u32)-1, s, func_0057F260(s));
}
inline String::~String() {
    Rep *q = rep();
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}

struct HObject {
    s32 h;
    HObject(const HObject &);
    HObject() {}
    HObject &operator=(const HObject &o) {
        if (this != &o) {
            s32 v = o.h;
            if (v != 0) func_003285A8(v);
            if (h != 0) func_003285F8(h);
            h = v;
        }
        return *this;
    }
};
struct HString : HObject {
    HString(const String &s) __asm__("func_00314B20");
    ~HString() __asm__("func_00312318");
};

struct VEnt { s16 delta; s16 idx; String (*fn)(void *); };
struct VT { char pad[0x18]; VEnt e; };
struct Obj { char pad[4]; VT *vt; };

static inline String toString(Obj *o) {
    VEnt *e = &o->vt->e;
    return e->fn((char *)o + e->delta);
}

extern "C" void MCourseData__GetAttrString(HObject *ret, s32 argc, Obj **argv) {
    if (argc > 0) {
        const char *name = toString(*argv).c_str();
        s32 id = func_00447C78(name);
        *ret = HString(String(func_00447F08(id)));
    }
}
