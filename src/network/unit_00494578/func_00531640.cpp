struct Conn { char pad[0x158]; int state; char pad15C[8]; void *handle; };
struct NetOps { char pad[0x18]; int (*query)(void *handle, unsigned short *id); };
extern NetOps *D_0064B4B8;

extern "C" long func_00531640(Conn *c, int *out) {
    int none = 0xFFFE;
    unsigned short id = none;
    if (c == 0) return 0x17;
    if (c->state != 2) return 0x17;
    if (out == 0) return 0x17;
    *out = 0x100;
    if (D_0064B4B8->query(c->handle, &id) != 0) return 0x25;
    if (id != none) {
        *out = id;
        return 0;
    }
    return 1;
}
