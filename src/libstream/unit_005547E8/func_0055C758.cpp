/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned long u64;

struct InterruptSection {
    s32 depth;
    s32 previouslyEnabled;
};
extern InterruptSection D_00655340;
extern "C" void func_00576100(InterruptSection *);
extern "C" void func_00576140(InterruptSection *);

struct RequestQueueOwner;
struct PendingRequestNode {
    u64 flags;
    RequestQueueOwner *owner;
    PendingRequestNode *next;
    char unknown10[0x20];
    s32 field30;
    char unknown34[0x14];
    s32 id;
};
struct RequestQueueOwner {
    char unknown00[0xA0];
    s32 counter;
};
struct PendingRequestList {
    char unknown00[0x2AA8];
    PendingRequestNode *head;
};
extern "C" s32 func_0055C520(RequestQueueOwner *);

extern "C" PendingRequestNode *func_0055C758(PendingRequestList *self, u64 mask) {
    func_00576100(&D_00655340);
    PendingRequestNode *previous = 0;
    PendingRequestNode *node = self->head;
    while (node != 0 && !(node->flags & mask)) {
        previous = node;
        node = node->next;
    }
    if (node != 0) {
        PendingRequestNode *next = node->next;
        if (previous == 0)
            self->head = next;
        else
            previous->next = next;
        node->next = 0;
        node->field30 = 6;
        node->id = func_0055C520(node->owner);
    }
    func_00576140(&D_00655340);
    return node;
}
