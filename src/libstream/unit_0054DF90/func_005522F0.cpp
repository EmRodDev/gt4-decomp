/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { virtual ~Base(); };
struct Item : Base { char pad[0xA4]; virtual ~Item(); };
struct Items { Item array[2]; ~Items() {} };
struct Handle { int a, b; };
struct Handles { Handle array[2]; };
struct Node { Node *next; Handle *value; };
struct Nodes { Node array[2]; };
struct Ids { int array[2]; };
extern Items D_0064C728;
extern Handles D_0086FD60;
extern Nodes D_0086FD70;
extern Ids D_0064C720;
extern Node *D_00654A44;
extern "C" void func_00551DD8(Item *, int) throw();
extern "C" void *func_0055F3A8(Handle *, int, Item *);
extern "C" void func_0055F3B8(Handle *, int);
static inline void link(Node *p, Handle *value) {
    p->next = D_00654A44;
    p->value = value;
    D_00654A44 = p;
}
extern "C" void func_005522F0(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        func_00551DD8(&D_0064C728.array[0], 0);
        func_00551DD8(&D_0064C728.array[1], 1);
    }
    if (prio == 0xFFFF && init == 1) {
        func_0055F3A8(&D_0086FD60.array[0], D_0064C720.array[0], &D_0064C728.array[0]);
        func_0055F3A8(&D_0086FD60.array[1], D_0064C720.array[1], &D_0064C728.array[1]);
    }
    if (prio == 0xFFFF && init == 1) {
        Node *nodes = D_0086FD70.array;
        Node *n = nodes;
        link(n, &D_0086FD60.array[0]);
        n++;
        link(n, &D_0086FD60.array[1]);
    }
    if (prio == 0xFFFF && init == 0) {
        if (D_0086FD60.array) {
            Handle *q = D_0086FD60.array + 2;
            while (q != D_0086FD60.array) {
                --q;
                func_0055F3B8(q, 2);
            }
        }
    }
    if (prio == 0xFFFF && init == 0)
        D_0064C728.~Items();
}
