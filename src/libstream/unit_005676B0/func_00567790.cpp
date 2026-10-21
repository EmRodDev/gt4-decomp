/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; };
struct Queue { Node *head; Node **tail; Node *pendingHead; Node **pendingTail; };
extern "C" int func_005B72A8(void);
extern "C" int func_005B72F8(void);
extern "C" void func_00567790(Queue *q, Node *p) {
    func_005B72A8();
    Node *n = p - 1;
    n->next = 0;
    *q->tail = n;
    q->tail = &n->next;
    if ((q->pendingHead = n->next) == 0) q->pendingTail = &q->pendingHead;
    func_005B72F8();
}
