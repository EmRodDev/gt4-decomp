/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Static initialization of this unit's stream objects, written like func_005522F0 (same template): two items
   constructed by func_00566388, two stream handles opened on them through func_0055F3A8
   and linked into the global handle list (D_00654A44); destruction closes the handles in reverse
   order (func_0055F3B8) and runs the items' virtual destructors. */
struct Base { virtual ~Base(); };
struct Item : Base { char pad[0x68]; virtual ~Item(); };
struct Items { Item array[2]; ~Items() {} };
struct Handle { int a, b; };
struct Handles { Handle array[2]; };
struct Node { Node *next; Handle *value; };
struct Nodes { Node array[2]; };
struct Ids { int array[2]; };
extern Items D_006551B8;
extern Handles D_008743F0;
extern Nodes D_00874400;
extern Ids D_006551B0;
extern Node *D_00654A44;
extern "C" void func_00566388(Item *, int) throw();
extern "C" void *func_0055F3A8(Handle *, int, Item *);
extern "C" void func_0055F3B8(Handle *, int);
static inline void link(Node *p, Handle *value) {
    p->next = D_00654A44;
    p->value = value;
    D_00654A44 = p;
}
extern "C" void func_00566BE0(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        func_00566388(&D_006551B8.array[0], 0);
        func_00566388(&D_006551B8.array[1], 1);
    }
    if (prio == 0xFFFF && init == 1) {
        func_0055F3A8(&D_008743F0.array[0], D_006551B0.array[0], &D_006551B8.array[0]);
        func_0055F3A8(&D_008743F0.array[1], D_006551B0.array[1], &D_006551B8.array[1]);
    }
    if (prio == 0xFFFF && init == 1) {
        Node *nodes = D_00874400.array;
        Node *n = nodes;
        link(n, &D_008743F0.array[0]);
        n++;
        link(n, &D_008743F0.array[1]);
    }
    if (prio == 0xFFFF && init == 0) {
        if (D_008743F0.array) {
            Handle *q = D_008743F0.array + 2;
            while (q != D_008743F0.array) {
                --q;
                func_0055F3B8(q, 2);
            }
        }
    }
    if (prio == 0xFFFF && init == 0)
        D_006551B8.~Items();
}
