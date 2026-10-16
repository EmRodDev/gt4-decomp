struct Node {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Node *next;
};

extern int object_mutex;
extern Node *objects;

extern "C" int func_005ADCE0(int sema);
extern "C" void func_005ADCC0(int sema);

extern "C" void func_005BECE0(int v, Node *n) {
    int *sema = &object_mutex;
    n->m8 = v;
    n->m4 = 0;
    n->m0 = 0;
    n->mC = v;
    n->m10 = 0;
    func_005ADCE0(*sema);
    n->next = objects;
    objects = n;
    func_005ADCC0(*sema);
}
