/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Obj {
    int state;
    char pad4[0x1C - 4];
    char *base;
    char pad20[0x3C - 0x20];
    int off;
};
struct Cell { int state; char pad[0x3C - 4]; int mark; };
extern "C" int func_00571B20(Obj *, Cell **, u8 *);
extern "C" int func_00571798(Obj *o, u8 mode, u8 flag, u8 *out) {
    if (out == 0) return 2;
    *out = 0;
    if (o == 0) return 2;
    if (mode == 1) {
        u8 r;
        Cell *cell = 0;
        if (flag == 0) {
            r = 0;
            int ret = func_00571B20(o, &cell, &r);
            if (ret == 0) *out = r;
            return ret;
        } else {
            cell = (Cell *)(o->base + o->off);
            if (cell->state == 1 && cell->mark == 1) *out = 1;
            else *out = 0;
        }
    } else {
        if (o->state > 0) *out = 1;
        else *out = 0;
    }
    return 0;
}


