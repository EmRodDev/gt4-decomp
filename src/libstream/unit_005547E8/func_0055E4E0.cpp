/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { char d[0x80]; };
struct Obj { char pad[0x3F8]; int dirty; };
extern Blk D_00873DC0;
extern Blk D_00873E40;
extern "C" void func_00576B28(Blk *, int);
extern "C" void func_0055E4E0(Obj *o) {
    if (o->dirty != 0) {
        o->dirty = 0;
        func_00576B28(&D_00873DC0, 0x80);
        D_00873E40 = D_00873DC0;
    }
}
