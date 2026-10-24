/* compiler: ee-gcc2.96-nogcse */
typedef long long Key8;
struct Key16 { volatile Key8 id; int extra[2]; };
struct API { char pad[0x38]; int (*poll)(int, int *, Key16 *, int *); };
extern API *D_0064B4B0;
struct Pump { int active; int handle; void (*cb)(Key8, int); };
extern Pump D_00863798;

extern "C" int func_0051D798(void) {
    Key16 key;
    int more;
    int arg;
    arg = 0;
    more = 0;
    if (D_00863798.active == 0)
        return 5;
    Pump *p = &D_00863798;
    int r;
    int m;
    do {
        r = D_0064B4B0->poll(p->handle, &more, &key, &arg);
        if (r != 0)
            return r;
        m = more;
        if (m == 0)
            break;
        if (p->cb) {
            p->cb(key.id, arg);
            m = more;
        }
    } while (m != 0);
    return 0;
}
