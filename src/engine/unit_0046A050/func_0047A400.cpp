/* Runs an action (strobe::ActionInstance::doAction) with a temporary ordered container (a tree with a heap-allocated header node
 * of 0x1C bytes, the shape of an STL set/map; inferred from the header's self links). The container is keyed by the action's key at
 * +0x10 and filled by func_0047A2A8. If the target object has the same id at +0x10 as the action's owner id at +0x1C it is passed
 * directly; otherwise a temporary Vec built by func_00485368 from that owner id is passed (and freed afterwards). The container
 * is emptied (func_00606258) and its header freed in both arms; the duplicate cleanup is kept as written. Returns the incoming
 * result pointer. The volatile locals reproduce the original's stack spills. */
#include "types.h"
struct Node { Node *a; Node *b; Node *c; Node *d; };
struct Tree { char pad0[4]; Node *head; Node *size; u8 flag; Node *key; char padz[0x1c]; };
struct Obj { char pad0[4]; s32 f4; u16 f8; char padA[6]; s32 f10; char pad14[8]; s32 f1C; };
struct Ctx { char pad[0x164]; s32 f164; };
struct Vec { s32 a; void *p; s32 b; s32 c; s32 d; char padv[0xc]; };
extern "C" void free(void *);
extern "C" void *func_00575E60(int, int);
extern "C" void func_00606258(void *, void *);
extern "C" void func_0047A2A8(Obj *, Tree *, s32, s32);
extern "C" void strobe__ActionInstance__doAction(s32, s32, s32, u16, void *, Tree *, Ctx *);
extern "C" void func_00485368(Vec *, s32);

extern "C" s32 func_0047A400(s32 result, Obj *action, s32 extra2, s32 extra3, Obj *target, Ctx *ctx) {
    Node *key = (Node *)action->f10;
    Tree tree;
    Vec temp;
    void *volatile keep;
    volatile u8 fl = 0;
    volatile u8 *pf = &fl;
    tree.head = 0;
    Node *header = (Node *)func_00575E60(0x10, 0x1C);
    tree.head = header;
    tree.size = 0;
    tree.flag = *pf;
    header->a = 0;
    tree.head->b = 0;
    tree.head->c = tree.head;
    tree.head->d = tree.head;
    *(Node *volatile *)&tree.key = key;
    func_0047A2A8(action, &tree, *(volatile s32 *)&ctx->f164, extra3);
    s32 ownerId = action->f1C;
    if (target->f10 == ownerId) {
        strobe__ActionInstance__doAction(result, extra2, action->f4, action->f8, target, &tree, ctx);
        if (tree.size != 0) {
            func_00606258(&tree, tree.head->b);
            tree.head->c = tree.head;
            tree.head->b = 0;
            tree.head->d = tree.head;
            tree.size = 0;
        }
        free(tree.head);
    } else {
        temp.p = 0; temp.b = 0; temp.c = 0; temp.d = 0;
        func_00485368(&temp, ownerId);
        strobe__ActionInstance__doAction(result, extra2, action->f4, action->f8, &temp, &tree, ctx);
        void *buffer = temp.p;
        keep = buffer;
        if (buffer) free(buffer);
        if (tree.size != 0) {
            func_00606258(&tree, tree.head->b);
            tree.head->c = tree.head;
            tree.head->b = 0;
            tree.head->d = tree.head;
            tree.size = 0;
        }
        free(tree.head);
    }
    return result;
}
