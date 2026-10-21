/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct Heap { const char *name; };
struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern "C" struct Heap *func_005C11A8(struct String *self) throw();
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" char *func_005C2560(struct StringRep *src) throw();
extern "C" struct String *func_005C2630(struct String *str, u32 pos, u32 n1, const char *s, u32 n2) throw();

static inline struct StringRep *rep(const struct String *str) { return (struct StringRep *)str->dat - 1; }

extern "C" struct String *func_005CE388(struct String *self, u32 pos1, u32 n1, const struct String *str, u32 pos2, u32 n2) {
    u32 len2 = rep(str)->len;
    if (pos1 == 0 && n1 >= rep(self)->len && pos2 == 0 && n2 >= len2) {
        if (str != self) {
            struct StringRep *r = rep(self);
            if (--r->ref == 0) {
                int size = r->res + 0x10;
                func_00326798(r, size, 4, func_005C11A8(self)->name);
            }
            {
                struct StringRep *g = rep(str);
                char *d;
                if (g->selfish != 0) {
                    d = func_005C2560(g);
                } else {
                    d = (char *)(g + 1);
                    g->ref++;
                }
                self->dat = d;
            }
        }
        return self;
    }
    if (n2 > len2 - pos2)
        n2 = len2 - pos2;
    return func_005C2630(self, pos1, n1, str->dat + pos2, n2);
}
