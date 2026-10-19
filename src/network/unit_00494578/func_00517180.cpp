struct Req { void *owner; int key; int id; int type; int user; };
struct Context { char pad[0x104]; int key; char pad108[0x60]; int (*callback)(Req *); int user; };
struct Global { char pad[0x118]; Context *current; };
struct Entry { int pad; int link; int key; };
struct Reply { unsigned char r; char p; short s; };
extern Global D_00854038;
extern "C" Entry *func_00515DD8(void) throw();
extern "C" void func_00516030(int, int, unsigned) throw();
extern "C" int func_00536568(int);
extern "C" int func_00532588(Context *, int, int, int, void *);
extern "C" int func_005A48D8(void *, int, unsigned);
extern "C" int func_00517180(int id) {
    Reply m;
    Req req;
    short s;
    Context *ctx = D_00854038.current;
    if (!ctx) return 8;
    Entry *e = func_00515DD8();
    if (!e) return 8;
    int key = e->key;
    if (key != ctx->key) {
        if (e->link == -1) {
            s = id;
            func_00532588(D_00854038.current, key, 0xB, 2, &s);
        } else {
            return 0xB;
        }
    } else if (e->link == -1) {
        e->link = key;
        if (!ctx->callback) {
            func_00516030(key, id, -2);
        } else {
            func_005A48D8(&req, 0, 20);
            req.owner = D_00854038.current;
            int user = ctx->user;
            req.key = e->link;
            req.type = 1;
            req.id = id;
            req.user = user;
            ctx->callback(&req);
        }
        int link = e->link;
        m.s = id;
        m.r = func_00536568(link);
        func_00532588(D_00854038.current, -1, 0xC, 6, &m);
    } else {
        return 0xB;
    }
    return 0;
}
