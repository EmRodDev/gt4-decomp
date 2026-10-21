/* compiler: ee-gcc2.9-991111 */
struct Field { int enabled, bits, offset, shift; };
struct Block { char pad[0x14]; struct Field fields[50]; };
extern struct Block D_0087FA80[];
int func_0058F1F0(int idx, unsigned char *data, int field) {
    struct Field v = D_0087FA80[idx].fields[field];
    if (v.enabled != 0) {
        switch (v.bits) {
        case 1: {
            if ((((int)data[v.offset] >> v.shift) & 1) == 0) return v.bits;
            return 0;
        }
        case 8: {
            int r = ((int)data[v.offset] >> v.shift) & 0xff;
            if (v.shift != 0) {
                v.offset++;
                r = (r | (data[v.offset] << (v.bits - v.shift))) & 0xff;
            }
            return r;
        }
        default: return -1;
        }
    }
    return -1;
}
