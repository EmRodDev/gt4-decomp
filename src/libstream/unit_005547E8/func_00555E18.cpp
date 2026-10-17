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
Node *func_005560C8(Owner *, int);
int func_00556210(Owner *, int);
}
extern "C" void func_00555E18(Owner *o, int idx, int a, int b, int val, int enable) {
    func_00555228(o);
    if (func_00556210(o, idx) == 0) {
        Node *n = func_005560C8(o, idx == 0 ? 3 : 4);
        Item *it = &o->items[idx];
        Data *src = &it->b;
        Vol *vb = &it->b.vol;
        if (enable != 0) {
            vb->w10 = a;
            vb->w14 = b;
            vb->w8 = val;
            vb->wC = val;
        }
        n->data = *src;
        n->flag = enable;
    }
    func_00555268(o);
}
