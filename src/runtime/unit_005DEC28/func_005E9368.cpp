#include "types.h"

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

struct Heap {
    const char *name;
};

extern "C" Heap *func_005C11A8(void) throw();
extern "C" char *func_005C2560(Rep *src) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    Str &operator=(const Str &o) {
        if (&o != this) {
            Rep *q = rep();
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
            p = o.rep()->grab();
        }
        return *this;
    }
};

struct Item {
    s32 id;
    Str s[4];
    s32 v[4];
};

extern "C" void func_005E9368(Item *first, Item *last, const Item *val) {
    for (; first != last; ++first)
        *first = *val;
}
