/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vol { int w0, w4, w8, wC, w10, w14; };
struct Data { int hdr[3]; Vol vol; int rest[7]; };
struct Node { int flag; int pad; Data data; };
struct Item {
    char pad0[0x8C];
    Data b;
    Data a;
    char pad10C[0x114 - 0x10C];
};
struct Owner { Item items[1]; };
extern "C" {
void func_00555228(Owner *);
void func_00555268(Owner *);
void func_00555D10(Owner *, int, int, int, int);
Node *func_005560C8(Owner *, int);
int func_00556210(Owner *, int);
}
extern "C" void func_00555AA0(Owner *o, int idx, int enable) {
    func_00555228(o);
    if (func_00556210(o, idx) == 0) {
        Node *n = func_005560C8(o, 0);
        Item *it = &o->items[idx];
        Vol *va = &it->a.vol;
        Data *src = &it->a;
        if (enable != 0) {
            va->w0 = 0;
            va->w10 = 0x80;
            va->w14 = 0x80;
            va->w8 = 0x80;
            va->wC = 0x80;
        }
        n->data = *src;
        n->flag = enable;
        func_00555D10(o, idx, 0, 1, 1);
        if (enable == 0) {
            Node *m = func_005560C8(o, 0);
            Vol *vb = &it->b.vol;
            vb->w10 = 0;
            vb->w14 = 0;
            vb->w8 = 0;
            vb->wC = 0;
            m->data = it->b;
            m->flag = 0;
        }
    }
    func_00555268(o);
}
