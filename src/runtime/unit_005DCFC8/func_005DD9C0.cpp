/* Empties a circular doubly linked list in place; this is the shape of a list<T>::clear instance (inferred from the 0xC-byte
 * nodes {next, prev, payload at +8} and from the sentinel being reset to point at itself). Each payload is destroyed with
 * func_001FEF50(payload, 2) (2 = delete flag, as in other destructor calls), each node is returned with the sized free func_00326798(node, 0xC, 4,
 * tag from func_005DEA88()), and finally the sentinel's next and prev point to itself. Sibling instances: func_005DD168, func_005DD278,
 * func_005DD9C0, func_005EB3D0, func_005F1AE0; they differ only in the payload destructor and the tag getter. */
struct Node {
    Node *next;
    void *prev;
};
struct Obj {
    char pad0[4];
    Node *sentinel;
};

extern "C" void func_00326798(void *, int, int, int);
extern "C" int *func_005DEA88(void);
extern "C" void func_001FEF50(void *, int);

extern "C" void func_005DD9C0(Obj *list) {
    Node *head = list->sentinel;
    Node *nextNode = head->next;
    if (nextNode != head) {
        do {
            Node *node = nextNode;
            nextNode = nextNode->next;
            func_001FEF50((char *)node + 8, 2);
            func_00326798(node, 0xC, 4, *func_005DEA88());
            head = list->sentinel;
            node = nextNode;
        } while (nextNode != head);
    }
    head->next = head;
    head = list->sentinel;
    head->prev = head;
}
