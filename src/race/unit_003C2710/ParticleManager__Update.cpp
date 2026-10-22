/**
 * Updates all active particle emitters in the particle manager linked list.
 * Calls each particle's virtual update method (slot 0x10); if it returns zero,
 * removes the particle node from the active list.
 */
typedef int s32;
typedef short s16;
typedef float f32;

struct Node {
    Node *next;
    void **vtbl;
};

struct Obj {
    char pad0[4];
    Node *head;
};

struct VEntry_003C2780 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self, s32 arg1, f32 f);
};

extern "C" void ParticleManager__remove(Obj *managerObj, Node *targetNode, void **prevNodePtr);

extern "C" void ParticleManager__Update(Obj *managerObj, s32 updateFlags, f32 deltaTime) {
    Node *prevNode = 0;
    Node *currentNode = managerObj->head;
    while (currentNode != 0) {
        Node *nextNode = currentNode->next;
        VEntry_003C2780 *vtableEntry = (VEntry_003C2780 *)((char *)currentNode->vtbl + 0x10);
        if (vtableEntry->fn((char *)currentNode + vtableEntry->delta, updateFlags, deltaTime) == 0) {
            ParticleManager__remove(managerObj, currentNode, (void **)prevNode);
        } else {
            prevNode = currentNode;
        }
        currentNode = nextNode;
    }
}
