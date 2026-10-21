/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Waiter {
    Waiter *next;
    int thread;
};

struct WaitQueue {
    char pad0[8];
    Waiter *head;
    Waiter *tail;
    Waiter *pendHead;
    Waiter *pendTail;
    char pad18[8];
    int deferred;
};

extern "C" int func_005AEB68(int thread);

/* From an interrupt handler: wakes every waiter of q, or moves them to its pending list. */
extern "C" void func_00576A48(WaitQueue *q) {
    unsigned int status;
    Waiter *w;
    Waiter *last;
    int thread;

    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    if (!(status & 1)) {
        w = q->head;
        last = q->tail;
        q->head = 0;
        q->tail = 0;
        if (q->deferred == 0) {
            while (w != 0) {
                thread = w->thread;
                w = w->next;
                func_005AEB68(thread);
            }
        } else if (w != 0) {
            if (q->pendTail != 0)
                q->pendTail->next = w;
            else
                q->pendHead = w;
            q->pendTail = last;
        }
    }
}
