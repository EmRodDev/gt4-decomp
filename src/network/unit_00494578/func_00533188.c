struct Node;
struct Event { struct Node *node; int x4, x8, xc; void *user; };
typedef void (*EventCb)(struct Event *);
enum EntryState { ENTRY_STATE_0 };
struct Entry { int x0, x4, x8; enum EntryState state; int x10, x14, x18, x1c, x20, x24, x28; };
enum NodeState { NODE_STATE_0 };
struct Node {
    char p0[0x100]; struct Entry *entry; unsigned int x104; char p108[0x1c];
    EventCb cb; void *user; char p12c[0x18]; enum NodeState state; int x148, x14c; char p150[0x14];
    void *handle;
};
struct Api { int x0, x4; void (*stop)(struct Node *); int xc, x10, x14; int (*active)(void); };
struct Api3 { char p0[0x10]; int (*open)(void *, int, struct Entry *, int *); };
extern struct Api *D_0064B4AC;
extern struct Api3 *D_0064B4B8;
extern int func_00535CB0(struct Node *, unsigned int, struct Entry **);
extern void *func_005A48D8(void *, int, unsigned);

void func_00533188(struct Node *node, unsigned int idx, int open, int n, int arg4)
{
    struct Event ev;
    struct Entry *e = 0;
    int status;

    if (!node) return;
    if (node->state == 1) return;
    if (open) {
        if (idx >= 0x40) return;
        status = func_00535CB0(node, idx, &e);
        if (status) return;
        if (!e) return;
        node->state = 1;
        node->entry = e;
        e->state = 2;
        node->x104 = idx;
        node->x14c = n - 1;
        e->x10 = 0;
        e->x14 = 0;
        e->x20 = 1;
        if (D_0064B4B8->open(node->handle, 1, e, &e->x8)) return;
    } else {
        status = 3;
        node->x104 = 0x100;
        node->entry = 0;
        node->state = 3;
        if (D_0064B4AC && D_0064B4AC->active()) D_0064B4AC->stop(node);
    }
    if (node->cb) {
        func_005A48D8(&ev, 0, sizeof(ev));
        ev.x4 = node->state;
        ev.user = node->user;
        ev.x8 = arg4;
        ev.xc = status;
        ev.node = node;
        node->cb(&ev);
        node->cb = 0;
        node->user = 0;
    }
}
