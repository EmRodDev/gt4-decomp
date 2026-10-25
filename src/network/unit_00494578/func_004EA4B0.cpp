/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" char *strobe__toUpper(struct Rep *);
extern "C" void func_00575DA0(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
struct Rep {
    u32 len, res, ref, selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    char *grab() { if (selfish) return strobe__toUpper(this); ++ref; return data(); }
    void release() { if (--ref == 0) func_00575DA0(this); }
};
extern Rep D_00659E20;
struct Str;
extern "C" Str *strobe__Any__setMember(Str *, u32, u32, const char *, u32);
extern "C" Str *func_0060DC18(Str *, u32, u32, const Str *, u32, u32);
extern "C" Str *func_00605888(Str *, u32, u32, u32, char);
extern "C" void func_00605A98(Str *, u32, int);
extern "C" u32 func_0060DEE0(const Str *, const char *, u32, u32);
extern "C" int func_005FBDD0(const Str *, const char *, u32, u32);
extern "C" int func_00608D98(const Str *, const Str *, u32, u32);
struct Str {
    char *dat;
    Rep *rep() const { return ((Rep *)dat) - 1; }
    Str() : dat(D_00659E20.grab()) {}
    Str(const Str &s) : dat(s.rep()->grab()) {}
    Str(const Str &s, u32 pos, u32 n) : dat(D_00659E20.grab()) { assign(s, pos, n); }
    Str(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    ~Str() { rep()->release(); }
    Str &assign(const Str &s, u32 pos, u32 n) { return *func_0060DC18(this, 0, (u32)-1, &s, pos, n); }
    Str &assign(const char *s, u32 n) { return *strobe__Any__setMember(this, 0, (u32)-1, s, n); }
    Str &assign(const char *s) { return assign(s, func_0057F260(s)); }
    Str &operator=(const Str &s) {
        if (&s != this) { rep()->release(); dat = s.rep()->grab(); }
        return *this;
    }
    u32 length() const { return rep()->len; }
    void alloc(u32 size, int save) { func_00605A98(this, size, save); }
    void unique() { if (rep()->ref > 1) alloc(length(), 1); }
    void selfish() { unique(); rep()->selfish = 1; }
    char &operator[](u32 pos) { selfish(); return (*rep())[pos]; }
    char *begin() { selfish(); return &(*this)[0]; }
    char *end() { selfish(); return &(*this)[length()]; }
    Str &replace(u32 pos, u32 n1, u32 n2, char c) { return *func_00605888(this, pos, n1, n2, c); }
    Str &erase(u32 pos, u32 n) { return replace(pos, n, 0, 0); }
    u32 find(const char *s, u32 pos = 0) const { return func_0060DEE0(this, s, pos, func_0057F260(s)); }
    int compare(const char *s, u32 pos = 0) const { return func_005FBDD0(this, s, pos, func_0057F260(s)); }
    int compare(const Str &s, u32 pos = 0, u32 n = (u32)-1) const { return func_00608D98(this, &s, pos, n); }
};
static inline bool operator<(const Str &a, const Str &b) { return a.compare(b) < 0; }
static inline bool operator!=(const Str &a, const Str &b) { return a.compare(b) != 0; }

struct Pair {
    Str first, second;
    Pair(const Str &a, const Str &b) : first(a), second(b) {}
};
struct Node { int color; Node *parent, *left, *right; Pair value; };
struct Iter {
    Node *node;
    Iter() {}
    Iter(Node *x) { node = x; }
    Iter(const Iter &it) { node = it.node; }
    Pair &operator*() const { return node->value; }
    bool operator==(const Iter &x) const { return node == x.node; }
};
struct InsRes { Iter first; bool second; };
struct Tree;
extern "C" Iter func_0060DF98(Tree *, const Str &);
extern "C" Iter func_0060E018(Tree *, Iter, const Pair &);
extern "C" InsRes func_0060DA68(Tree *, const Pair &);
struct Tree {
    int alloc;
    Node *header;
    int count;
    Iter end() { return header; }
};
struct Map {
    Tree t;
    Iter end() { return t.end(); }
    Iter lower_bound(const Str &k) { return func_0060DF98(&t, k); }
    Iter insert(Iter pos, const Pair &x) { return func_0060E018(&t, pos, x); }
    InsRes insert(const Pair &x) { return func_0060DA68(&t, x); }
    Str &operator[](const Str &k) {
        Iter i = lower_bound(k);
        if (i == end() || k < (*i).first)
            i = insert(i, Pair(k, Str()));
        return (*i).second;
    }
};
struct Obj { char pad[0x80]; Map cookies; };
extern char D_006BFF38[], D_006C0128[], D_006C0130[];  /* "=", "secure", "noname" */
extern "C" char func_004EBA18(char);
extern "C" char *func_0060DE78(char *, char *, char *, char (*)(char));

extern "C" void func_004EA4B0(Obj *self, Str &input) {
    const char *sep = "; ";
    int done = 0;
    do {
        Str line;
        u32 pos = input.find(sep);
        if (pos != (u32)-1) {
            line = Str(input, 0, pos);
            input.erase(0, pos + 2);
        } else {
            line = input;
            done = 1;
        }
        u32 eq = line.find(D_006BFF38);
        if (eq != (u32)-1) {
            Str key(line, 0, eq);
            Str value(line, eq + 1, line.length() - eq + 1);
            Str lower(key);
            func_0060DE78(key.begin(), key.end(), lower.begin(), func_004EBA18);
            if (lower.compare("expires") != 0 && lower.compare("domain") != 0 && lower.compare("path") != 0)
                self->cookies[key] = value;
        } else if (line != Str(D_006C0128)) {
            self->cookies.insert(Pair(Str(D_006C0130), line));
        }
    } while (!done);
}
