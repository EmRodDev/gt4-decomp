/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct Info { int data[0x2C / 4]; };
struct Item { char pad[0x20]; Info info; char pad2[0x114 - 0x4C]; };
struct Owner { Item items[1]; };
extern "C" void func_00555228(Owner *);
extern "C" void func_00555268(Owner *);
extern "C" int func_00556210(Owner *, int);
extern "C" int func_005554E0(Owner *o, int idx, Info *out) {
    int ret = 0;
    func_00555228(o);
    if (func_00556210(o, idx) == 0) {
        ret = 2;
        *out = o->items[idx].info;
    }
    func_00555268(o);
    return ret;
}
