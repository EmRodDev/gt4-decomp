/* Deleting destructor of mUpdateContext (object size 0x12C, freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * Order: vtable pointer reset at +4, member at 0x118 (func_00203118, 2), member at 0xE8 (func_00574DA8, 2), then three 0xC-byte nodes that are destroyed and freed with
 * their allocator names: the node at 0xCC (kill_a, callee func_005DD278), at 0x18 (kill_b, func_005DD1F8) and at 0x10 (kill_c, func_005DD168); each is a small list-like
 * container whose header node is freed with size 0xC, alignment 4 (inferred from that size). Last the hObject base destructor (hObject__structor_2). */
#include "gt4/mUpdateContext.h"
typedef int s32;

extern "C" void func_00203118(void *self, s32 flags);
extern "C" void func_00574DA8(void *self, s32 flags);
extern "C" void func_005DD278(void *self);
extern "C" void func_005DD1F8(void *self);
extern "C" void func_005DD168(void *self);
extern "C" const char **func_005DD870(void);
extern "C" const char **func_005DD830(void);
extern "C" const char **func_005DD7F0(void);
extern "C" void hObject__structor_2(void *self, s32 flags);
extern "C" void func_00326798(void *self, s32 flags, s32 arg2, const char *arg3);

extern void *mUpdateContext__vtable;

struct Node { void *a; void *p; };
static inline void kill_a(Node *q) { func_005DD278(q); void *p = q->p; func_00326798(p, 0xC, 4, *func_005DD870()); }
static inline void kill_b(Node *q) { func_005DD1F8(q); void *p = q->p; func_00326798(p, 0xC, 4, *func_005DD830()); }
static inline void kill_c(Node *q) { func_005DD168(q); void *p = q->p; func_00326798(p, 0xC, 4, *func_005DD7F0()); }

extern "C" void mUpdateContext__structor_1(void *self, s32 flags) {
    ((struct mUpdateContext *)self)->unk4 = &mUpdateContext__vtable;
    func_00203118((char *)self + 0x118, 2);
    func_00574DA8((char *)self + 0xE8, 2);
    kill_a((Node *)((char *)self + 0xCC));
    kill_b((Node *)((char *)self + 0x18));
    kill_c((Node *)((char *)self + 0x10));
    hObject__structor_2(self, 0);
    if (flags & 1) {
        return func_00326798(self, 0x12C, 4, "RefCounter");
    }
}
