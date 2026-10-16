typedef struct Node {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    struct Node *next;
} Node;

extern "C" int object_mutex;
extern "C" Node *objects;
extern "C" int func_005ADCE0(int sema);
extern "C" int func_005ADCC0(int sema);

extern "C" void func_005BEC48(int value, Node *n)
{
    n->m8 = value;
    n->m4 = 0;
    n->m0 = 0;
    n->mC = 0;
    n->m10 = 0;
    func_005ADCE0(object_mutex);
    n->next = objects;
    objects = n;
    func_005ADCC0(object_mutex);
}
