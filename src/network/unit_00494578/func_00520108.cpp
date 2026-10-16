/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long U64 __attribute__((aligned(4)));

/* Connection kind: an enum, so the state read does not alias the int result stores. */
enum ConnState { CONN_STREAM, CONN_DATAGRAM, CONN_CLOSED };

struct Conn {
    enum ConnState state;
    char pad[12];
    U64 addr;
    int mode;
    int handle;
};

struct NetOps {
    char pad[0x1c];
    int (*read)(int handle, void *data, unsigned size, int *out);
    int (*readFrom)(int handle, U64 addr, int mode, void *data, unsigned size, int *out);
};

extern NetOps *D_0064B4B0;

extern "C" unsigned func_00520058(void *data, unsigned n, int limit) throw();

extern "C" int func_00520108(Conn *p, void *data, unsigned n, int *out) {
    unsigned size;
    int r;
    *out = 0;
    if (p->state == 0) {
        size = n;
        if (size > 0x1000) size = 0x1000;
        r = D_0064B4B0->read(p->handle, data, size, out);
        if (r) return r;
    } else if (p->state == 1) {
        size = func_00520058(data, n, 0x248);
        if (size != 0) {
            r = D_0064B4B0->readFrom(p->handle, p->addr, p->mode, data, size, out);
            if (r) return r;
        }
    } else {
        return 4;
    }
    return 0;
}
