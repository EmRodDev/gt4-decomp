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

extern "C" s32 func_0055C6E0(PendingRequestList *self, u64 mask) {
    func_00576100(&D_00655340);
    s32 count = 0;
    for (PendingRequestNode *node = self->head; node != 0; node = node->next) {
        if (node->flags & mask)
            count++;
    }
    func_00576140(&D_00655340);
    return count;
}
