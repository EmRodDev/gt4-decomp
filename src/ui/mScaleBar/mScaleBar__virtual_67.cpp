struct Rep { int len, cap, ref, flag; };
struct String { char *p; char pad[12]; };
struct ID { int value; char pad[12]; };
struct Handle { void *p; char pad[12]; };
struct Obj { char pad[0xC4]; float value; char pad2[0x28]; void *popup; void *pinch; char pad3[8]; int active; };
extern Rep D_00659FA8;
extern char D_00698B58[], D_00698BA8[];
extern "C" int mTextFace__virtual_67(Obj *);
extern "C" int func_002556B0(Handle *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" String *func_005C2630(String *, unsigned, unsigned, const char *, unsigned);
extern "C" int HSymID__GetID(String *);
extern "C" void func_003069F8(void *, Handle *, ID *);
extern "C" char **func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_00265E50(void *, int);
extern "C" void func_002550B8(Handle *, int);
extern "C" void func_00238FC0(Obj *, float);
extern "C" void func_00238FF0(Obj *, float);
static inline void init(String *s, const char *name) {
    char *p;
    Rep *r = &D_00659FA8;
    if (r->flag) p = func_005C2560(r);
    else { p = (char *)(r + 1); r->ref = r->ref + 1; }
    s->p = p;
    func_005C2630(s, 0, -1, name, func_0057F260(name));
}
static inline void freeRep(Rep *r, int size) {
    func_00326798(r, size, 4, *func_005C11A8());
}
static inline void destroy(String *s) {
    Rep *rep = (Rep *)(s->p - 16);
    if (--rep->ref == 0) {
        int cap = rep->cap;
        freeRep(rep, cap + 16);
    }
}
static inline void lookup(ID *id, String *s, const char *name) {
    init(s, name);
    id->value = HSymID__GetID(s);
}
extern "C" void mScaleBar__virtual_67(Obj *self) {
    Handle h;
    ID first;
    String a;
    ID second;
    mTextFace__virtual_67(self);
    String b;
    void *target = self;
    func_002556B0(&h);
    lookup(&first, &a, D_00698B58);
    func_003069F8(self, &h, &first);
    destroy(&a);
    if (h.p) { target = h.p; self->popup = target; func_00265E50(target, 0); }
    self->active = 0;
    func_002550B8(&h, 2);
    func_002556B0(&h);
    lookup(&second, &b, D_00698BA8);
    func_003069F8(target, &h, &second);
    destroy(&b);
    if (h.p) self->pinch = h.p;
    func_002550B8(&h, 2);
    func_00238FC0(self, self->value);
    func_00238FF0(self, self->value);
}
