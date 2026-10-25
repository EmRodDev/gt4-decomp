struct Event { int x0, x4, x8, xc; void *user; };
typedef void (*EventCb)(struct Event *);
typedef int (*DataCb)(void *, int);
/* What func_00535CB0 reports for a node; 0 means none (the values are not known yet). */
enum NodeKind { NODE_KIND_NONE };
struct Node {
    char p0[0x100]; enum NodeKind kind; int x104; char p108[0x1c];
    EventCb cb; void *user; EventCb cb2; void *user2; DataCb rx; void *rx_user; DataCb tx; void *tx_user; int state, x148, x14c, x150, x154, x158, x15c, x160;
    void *handle;
};
struct Info { int x0; int mode; int x8; int xc; int x10; int x14; };
struct In { int valid; EventCb cb; void *user; EventCb cb2; void *user2; DataCb rx; void *rx_user; DataCb tx; void *tx_user; int x24; struct Info info; char p40[0x50]; int x90, x94; };
struct Out { int x0; int err; struct Node *node; };
struct Api { int x0; int (*start)(struct Node *, int, const struct Info *); void (*stop)(struct Node *); char pc[0x50]; int x5c; };
struct Api2 { char p0[0x44]; void (*setup)(struct Node *, int); };
struct Api3 { char p0[0x2c]; int (*query)(void *, int *); };
extern struct Api *D_0064B4AC;
extern struct Api2 *D_0064B4B4;
extern struct Api3 *D_0064B4B8;
extern int func_00535B50(int, struct Node **);
extern int func_00535CB0(struct Node *, int, enum NodeKind *);
extern int func_00532EA0(struct Node *, int, int, int, int, int, int);
extern void func_00533188(struct Node *, int, int, int, int);
extern void *func_005A48D8(void *, int, unsigned);

int func_005341C0(const struct In *a, struct Out *out) {
    struct Event ev;
    struct Node *p = 0;
    enum NodeKind n = NODE_KIND_NONE;
    int err = 0;
    int r;
    const struct Info *info;
    if (!out) return 0x17;
    out->err = 0x1d;
    out->x0 = 1;
    if (!a) {
        out->err = 0x17;
        return 0x17;
    }
    if (!a->valid) {
        out->err = 0x26;
        return 0x26;
    }
    if (!a->x24) {
        out->err = 0x17;
        return 0x17;
    }
    r = func_00535B50(0, &p);
    out->err = r;
    if (r || !p) return r;
    info = &a->info;
    if (D_0064B4AC)
        out->err = func_00532EA0(p, a->x94, a->x24, info->mode, info->x8, info->x14, D_0064B4AC->x5c);
    else
        out->err = func_00532EA0(p, a->x94, a->x24, 0, 0, 0, 0);
    r = out->err;
    if (r || !p->handle) return r;
    r = func_00535CB0(p, 0, &n);
    out->err = r;
    if (r || !n) return r;
    if (D_0064B4B4) D_0064B4B4->setup(p, 0x100);
    p->x148 = 1;
    p->x150 = a->x24;
    p->x154 = a->x90;
    p->x158 = 2;
    p->cb = a->cb;
    p->user = a->user;
    p->cb2 = a->cb2;
    p->user2 = a->user2;
    p->rx = a->rx;
    p->rx_user = a->rx_user;
    p->tx = a->tx;
    p->tx_user = a->tx_user;
    out->node = p;
    p->state = 2;
    p->x104 = 0x100;
    p->kind = NODE_KIND_NONE;
    if (a->info.mode == 1) err = D_0064B4AC->start(p, a->x24, info);
    if (err) {
        if (D_0064B4AC) D_0064B4AC->stop(p);
        p->state = 3;
        if (p->cb) {
            func_005A48D8(&ev, 0, sizeof(ev));
            ev.x4 = 3;
            ev.x8 = 1;
            ev.user = p->user;
            ev.x0 = 0;
            ev.xc = err;
            p->cb(&ev);
        }
        out->err = err;
        return err;
    }
    if (D_0064B4B8->query(p->handle, &p->x104) == 0) {
        p->kind = n;
        func_00533188(p, p->x104, 1, 1, 0);
        out->err = 0;
    } else {
        func_00533188(p, 0x100, 0, 0, 1);
        out->err = 3;
    }
    return out->err;
}
