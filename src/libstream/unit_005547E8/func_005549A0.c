/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef struct Node { int id; struct Node *next; } Node;
typedef struct Queue { Node *head; Node *tail; } Queue;
typedef struct Pool { int handle; char pad[0x10]; int owner; int flags; } Pool;
Node *func_00567718(int);
int func_005ADB90(void);
void func_005ADBC0(void);
void func_005ADBD0(int);
int func_005B72A8(void);
int func_005B72F8(void);
int func_005549A0(Pool *pool, Queue *q) {
    int f;
    Node *n = func_00567718(pool->handle);
    n->id = func_005ADB90();
    n->next = 0;
    *(Node **)q->tail = n;
    q->tail = (Node *)&n->next;
    f = pool->flags;
    if (!(f & 1)) return f;
    func_005B72F8();
    func_005ADBC0();
    func_005B72A8();
    if (!(pool->flags & 1)) {
        func_005B72F8();
        func_005ADBD0(pool->owner);
        func_005B72A8();
    }
    f = pool->flags;
    return f;
}
