/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
struct Ent { u8 *data; int size; u16 x, a, b, c; };
#define ENT(tbl, id, off) ((Ent *)((char *)((tbl) + ((id) & 0xff) * 16) + (off)))
extern "C" void func_004BC818(u16 *, u8 *, int) throw();
extern "C" u16 func_004C07F8(char *tbl, u16 id, int index, int off) {
    u16 v;
    u8 *base;
    int pos = index * 6;
    if ((id & 0xff00) == 0x200) base = ENT(tbl, id, 0x40)->data + pos;
    else base = ENT(tbl, id, 0x50)->data + pos;
    func_004BC818(&v, base + off, 2);
    return v;
}
