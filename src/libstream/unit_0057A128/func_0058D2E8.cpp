/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
struct Tbl { u8 d[12]; };
extern Tbl D_006CF2D8;
extern "C" void func_0058D2E8(u8 *o) {
    Tbl days;
    int y;
    days = D_006CF2D8;
    o[5] = o[5] - 1;
    if ((o[7] & 3) == 0) days.d[1] = 0x1D;
    if (o[5] == 0) {
        int m = o[6] - 1;
        o[6] = m;
        if ((m & 0xFF) == 0) {
            y = o[7];
            if (y != 0) o[7] = y - 1; else o[7] = 99;
            o[6] = 12;
        }
        o[5] = days.d[o[6] - 1];
    }
}

