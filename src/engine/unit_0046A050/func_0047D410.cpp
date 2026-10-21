/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Selects an entry of a list by index (inferred): the current record (9 ints) is saved in 'dst', then, when the list has at least two
 * entries, 'cur' becomes list[min(max(index - base, 0), count - 1)] where base is the short at +2 of the owner. The record's meaning is
 * unknown. */
struct Rec { int w[9]; };
struct Arr { Rec *data; int count; Rec &operator[](int i) { Rec *p = data+i; return *p; } };
struct Inner { char pad[2]; short h; char pad2[0x14]; Arr list; };
struct Obj {
    char pad[4];
    Inner *p;
    Rec dst;
    Rec cur;
};
static inline const int &mn(const int &a, const int &b) { return b < a ? b : a; }
extern "C" void func_0047D410(Obj *self, int unusedArg, int index) {
    Rec *cur = &self->cur;
    self->dst = *cur;
    if (self->p) {
        Arr *list = &self->p->list;
        index = index - self->p->h;
        index = index < 0 ? 0 : index;
        if (list->count >= 2) {
            *cur = (*list)[mn(index, list->count - 1)];
        }
    }
}
