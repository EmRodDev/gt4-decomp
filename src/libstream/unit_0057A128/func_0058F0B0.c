/* compiler: ee-gcc2.9-991111 */
typedef struct Bits { unsigned long f0:14; unsigned long f1:2; unsigned long f2:8; unsigned long f3:8; } Bits;
typedef union HdrU { Bits b; unsigned long l; } HdrU;
struct Chan { int m0; int state; char pad[0x32C]; };
struct Buf { unsigned char value; char pad[3]; int state; };
extern struct Chan D_0087FA80[];
void func_0058F2D0(int);
int func_0058F348(int);
struct Buf *func_0058F408(int);
int func_0058F470(int);
int func_00590828(int, int, int *, unsigned char *);
unsigned char func_0058F0B0(int port) {
    unsigned char value;
    int len;
    HdrU h;
    if (D_0087FA80[port].state == 0) {
        if (func_0058F348(port) < 0) return 0;
    }
    if (func_0058F470(port) != 0) {
        struct Buf *buf = func_0058F408(port);
        if (buf->state == 0 && func_0058F348(port) < 0) goto fail;
        value = buf->value;
        goto done;
    } else {
        h.b.f0 = 12;
        h.b.f1 = 2;
        h.b.f2 = 1;
        h.b.f3 = 1;
        if (func_00590828(port, (int)h.l, &len, &value) >= 0) goto done;
    }
fail:
    D_0087FA80[port].state = 0;
    func_0058F2D0(port);
    return 0;
done:
    return value;
}
