/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Static initialization of this unit's stream objects, written like func_005522F0 (same template): two items
   constructed by func_00560198, two stream handles opened on them through func_0055F3A8
   and linked into the global handle list (D_00654A44); destruction closes the handles in reverse
   order (func_0055F3B8) and runs the items' virtual destructors. */
struct Base { virtual ~Base(); };
struct Item : Base { char pad[0x8]; virtual ~Item(); };
struct Items { Item array[2]; ~Items() {} };
struct Handle { int a, b; };
struct Handles { Handle array[2]; };
struct Node { Node *next; Handle *value; };
struct Nodes { Node array[2]; };
struct Ids { int array[2]; };
extern Items D_0064D3E0;
extern Handles D_00873568;
extern Nodes D_00873578;
extern Ids D_0064D3D8;
extern Node *D_00654A44;
struct Src { char b[0x14]; };
struct Srcs { Src array[2]; };
extern Srcs D_00654DF8;
extern char D_006C8968[];
extern "C" void func_00560198(Item *, Src *, void *) throw();
extern "C" void *func_0055F3A8(Handle *, int, Item *);
extern "C" void func_0055F3B8(Handle *, int);
static inline void link(Node *p, Handle *value) {
    p->next = D_00654A44;
    p->value = value;
    D_00654A44 = p;
}
extern "C" void func_00558BC8(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        func_00560198(&D_0064D3E0.array[0], &D_00654DF8.array[0], D_006C8968);
        func_00560198(&D_0064D3E0.array[1], &D_00654DF8.array[1], D_006C8968);
    }
    if (prio == 0xFFFF && init == 1) {
        func_0055F3A8(&D_00873568.array[0], D_0064D3D8.array[0], &D_0064D3E0.array[0]);
        func_0055F3A8(&D_00873568.array[1], D_0064D3D8.array[1], &D_0064D3E0.array[1]);
    }
    if (prio == 0xFFFF && init == 1) {
        Node *nodes = D_00873578.array;
        Node *n = nodes;
        link(n, &D_00873568.array[0]);
        n++;
        link(n, &D_00873568.array[1]);
    }
    if (prio == 0xFFFF && init == 0) {
        if (D_00873568.array) {
            Handle *q = D_00873568.array + 2;
            while (q != D_00873568.array) {
                --q;
                func_0055F3B8(q, 2);
            }
        }
    }
    if (prio == 0xFFFF && init == 0)
        D_0064D3E0.~Items();
}
