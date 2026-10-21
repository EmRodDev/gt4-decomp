/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int x; Node *next; int a, b; };
struct Heap { Node *lo, *hi, *cur; char pad[0x4c-12]; char lock; };
extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
extern "C" int func_00572B98(Heap *s) {
    void *lock = &s->lock;
    func_005769F0(lock);
    Node *cur = s->cur;
    int count = 0;
    while (cur >= s->lo && cur < s->hi) {
        if (cur->a != -1 && cur->b != -1) count++;
        cur = cur->next;
    }
    func_00576A28(lock);
    return count;
}
