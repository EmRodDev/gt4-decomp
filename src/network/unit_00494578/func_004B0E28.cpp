/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block {
    int a;
    int b;
    int value;
    int c;
    int d;
};

struct Res {
    Block info;
    int extra[3];
};

struct Item {
    char pad[0x48];
    int lock;
    char pad4c[0x28];
    int state;
    char pad78[0xC];
    Block block;
};

struct Conn {
    int handle;
    int a;
    int b;
    void *p;
};

struct Param {
    int state;
    Item *item;
    int f8;
    Conn *conn;
};

struct Base {
    char pad[0xA4];
};

class Owner : public Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Res lookup(Item *item);
    virtual int open(int ctx, int x, int y);
};

extern char D_0084D5C0[], D_0084D5E0[];
extern "C" int func_004AC798(int lock);
extern "C" void func_004AC7B8(int lock);
extern "C" void func_004ADD70(Owner *, Param *);
extern "C" int func_00550D58(int, int, int, int);
extern "C" void *func_00575C00(void *, int);

static inline void attach(Owner *self, Param *prm, int r) {
    if (r == 0) {
        prm->state = 9;
    } else {
        func_004ADD70(self, prm);
        Conn *c = (Conn *)func_00575C00(D_0084D5C0, 0);
        c->handle = r;
        c->a = 0;
        c->b = 0;
        c->p = func_00575C00(D_0084D5E0, 0);
        prm->conn = c;
    }
}

extern "C" int func_004B0E28(Owner *self, Param *prm) {
    int r = -1;
    Item *item = prm->item;
    int lock = item->lock;
    int state = item->state;
    int ctx = func_004AC798(lock);

    if (state == 3) {
        r = 0;
    } else if (state == 0) {
        Res res = self->lookup(item);
        Block *dst = &item->block;
        *dst = res.info;
        if (dst->a == 0) {
            r = self->open(ctx, res.extra[0], dst->c);
            attach(self, prm, r);
        }
    } else {
        r = func_00550D58(0, -1, 0x8000, ctx);
        attach(self, prm, r);
    }
    func_004AC7B8(lock);
    return r;
}
