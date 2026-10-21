/* compiler: ee-gcc2.96-exceptions */
struct Raw8 { unsigned char b[8]; };
struct Data { Raw8 id; int value; };
union Word { unsigned char b[2]; unsigned short h; };
struct Header { Word low, high; unsigned short extra; };
struct Entry { void *ptr; int len; };
struct Table { Entry e[8]; int total, count; };
struct Node; struct S;
extern "C" Node *func_0052DD98(S *);
extern "C" int func_0052D5A8(S *, Node *, Table *) throw();
static inline void add(Table *t, void *p, int len) {
    if (t->count < 8) {
        t->e[t->count].ptr = p;
        t->e[t->count].len = len;
        t->total = t->total + len;
        t->count = t->count + 1;
    }
}
extern "C" int func_0052C9B0(char *self, unsigned char *p, long id, int value) {
    Data d;
    Table t;
    Header h;
        d.id = *(Raw8 *)&id;
    d.value = value;
    h.high.b[0] = p[0]; h.high.b[1] = p[1];
    h.low.b[0] = p[0]; h.low.b[1] = p[1];
    h.low.h &= 0x7ff;
    h.high.h &= 0xf800;
    if (h.high.h & 0x6000) h.extra = 4; else h.extra = 2;
    t.count = 0; t.total = 0;
    add(&t, p, h.extra + h.low.h);
    if (t.count < 8) {
        t.e[t.count].ptr = &d;
        t.e[t.count].len = 12;
        t.total += 12;
        t.count++;
    }
    Node *n = func_0052DD98((S *)(self + 12));
    if (!n) return 3;
    func_0052D5A8((S *)(self + 12),n,&t);
}
