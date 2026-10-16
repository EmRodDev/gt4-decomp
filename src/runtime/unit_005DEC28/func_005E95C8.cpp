typedef int s32;

struct Rep;
extern "C" char *func_005C2560(Rep *src) throw();
struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
    char *data() { return (char *)(this + 1); }
    char *grab() {
        if (sel)
            return func_005C2560(this);
        ++ref;
        return data();
    }
};

struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    Str(const Str &o) : p(o.rep()->grab()) {}
};

struct Item {
    s32 id;
    Str s[4];
    s32 v[4];
};

inline void *operator new(unsigned int, void *p) { return p; }

extern "C" Item *func_005E95C8(Item *first, s32 n, const Item &x) {
    for (; n != 0; --n, ++first)
        if (first)
            new (first) Item(x);
    return first;
}
