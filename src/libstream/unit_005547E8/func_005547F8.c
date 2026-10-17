/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef struct Node { int id; struct Node *next; } Node;
typedef struct Queue { Node *head; Node *tail; } Queue;
typedef struct Pool {
    int handle;
    Queue a;
    Queue b;
    int f14;
    int flags;
    int f1C;
    int f20;
    int pad24;
    int f28, f2C, f30, f34;
} Pool;
int func_005B72A8(void);
int func_005B72F8(void);
int func_005ADB90(void);
void func_005ADBC0(void);
void func_00554910(Pool *pool, Queue *q);
void func_005676B0(int);
void func_005547F8(Pool *p) {
    int n = 0;
    Node *node;
    func_005B72A8();
    p->flags &= ~1;
    for (node = p->b.head; node != 0; node = node->next) n++;
    for (node = p->a.head; node != 0; node = node->next) n++;
    n--;
    func_005B72F8();
    func_00554910(p, &p->a);
    func_00554910(p, &p->b);
    func_005B72A8();
    p->f14 = func_005ADB90();
    while (n != -1) {
        n--;
        func_005B72F8();
        func_005ADBC0();
        func_005B72A8();
    }
    func_005676B0(p->handle);
    p->f28 = 0;
    p->f2C = 0;
    p->f30 = p->f20;
    p->f34 = 0;
    func_005B72F8();
}
