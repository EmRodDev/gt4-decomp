/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { Block *prev; Block *next; int f8, fc; };
struct Heap { Block *start; Block *end; char pad[0x44]; int lock; };
extern "C" void func_00572278(Heap *, Block *) throw();
extern "C" void func_005722D8(Heap *, Block *, Block *) throw();
extern "C" void func_005722F8(Heap *, Block *) throw();
extern "C" void func_005723D8(Heap *, Block *) throw();
extern "C" void func_005769F0(void *, char *ptr);
extern "C" void func_00576A28(void *);
static inline int is_free(Block *p) { return ~p->f8 != 0; }
static inline int equal(int a, int b) { return a == b; }
extern "C" void func_00572930(Heap *heap, char *ptr) {
    if (ptr) {
        Block *b = (Block *)(ptr - 16);
        int valid = 0;
        if (!((unsigned)b & 15) && b >= heap->start && b < heap->end && equal(-1, b->f8))
            valid = equal(-1, b->fc);
        int *lock = &heap->lock;
        if (valid) {
            func_005769F0(lock, ptr);
            Block *p = b->prev;
            if (p) {
              if (is_free(p)) {
                func_005723D8(heap, p);
                func_005722D8(heap, p, b);
                b = p;
              }
            } else {
                func_00572278(heap, b);
            }
            p = b->next;
            if (p < heap->end && ~p->f8) {
                func_005723D8(heap, p);
                func_005722D8(heap, b, p);
            }
            func_005722F8(heap, b);
            func_00576A28(lock);
        }
    }
}
