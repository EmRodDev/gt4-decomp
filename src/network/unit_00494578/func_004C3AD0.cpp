/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Entry { u16 index, size, prev; short next; };
struct Table { char pad[0x10]; Entry *entries; u16 *count; char pad18[4]; u16 *max; };
extern "C" int func_004C3AD0(Table *t, u16 prev, u16 index) {
    if ((u16)(index - 1) >= 0x1fff) return -1;
    Entry *e = t->entries + index;
    Entry *p = t->entries + prev;
    e->prev = prev;
    if (((u16) p->next) != 0xffff) {
        Entry *next = t->entries + ((u16) p->next);
        next->prev = index;
    }
    e->next = p->next;
    p->next = index;
    *t->count = *t->count - e->size - 1;
    int used = 0x2000 - *t->count;
    if (*t->max < used) *t->max = used;
    return 0;
}
