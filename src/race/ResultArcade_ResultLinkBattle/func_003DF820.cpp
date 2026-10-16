typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

struct Obj { void *tex[2]; };

struct IconEntry { char pad[0x68]; int value; char pad6c[0x54]; };

union ResultArcade {
    IconEntry entries[2];
    struct { char pad0[0x60]; Obj *icons; } head;
};

extern "C" void func_00393790(Obj *self, int mode, float x0, float y0, float x1, float y1, float scale);

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline u32 length(const String *str) { return rep(str)->len; }
static inline char *data(const String *str) { return str->dat; }
static inline char eos() { return 0; }
static inline char at(const String *str, u32 pos) {
    if (pos == length(str))
        return eos();
    return data(str)[pos];
}

extern "C" void func_003DF820(ResultArcade *self, const String *name, float *rect) {
    int n = at(name, length(name) - 1) - '1';
    func_00393790(self->head.icons + self->entries[n].value, 1, rect[0], rect[1], rect[2], rect[3], 1.0f);
}
