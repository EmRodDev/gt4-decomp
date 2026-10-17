/* compiler: ee-gcc2.96-nsa-g */
struct Token { double value; } __attribute__((packed));
struct Packet { unsigned char pad0, type; char pad2[2]; Token id; char payload[1]; };
struct Obj { char pad[0x104]; int type; char pad108[0x50]; int mode; char pad15c[4]; int handle; };
struct Ops { char pad[0x74]; int (*compare)(double, double); };
struct Callback { char pad[0x18]; int (*send)(int, int, void *); };
struct Config { char pad[0x68]; int first, second; };
extern "C" Ops *D_0064B4B0;
extern "C" Callback *D_0064B710;
extern "C" Config *D_0064B47C;
extern "C" int func_00531040(Token *) throw();
static inline int compare(double a, double b) { return D_0064B4B0->compare(a, b); }
extern "C" void func_005319A8(Obj *, int, double, int) throw();
extern "C" int func_00537058(Obj *obj, int unused1, int unused2, Packet *packet) {
    if (!obj) return -1;
    Token id = packet->id;
    Token other;
    func_00531040(&other);
    if (!compare(id.value, other.value) || packet->type != obj->type) {
        Callback *cb = D_0064B710;
        if (cb) {
            if (obj->mode == 2) cb->send(-1, packet->type, packet->payload);
            else cb->send(obj->handle & 0x7fffffff, packet->type, packet->payload);
        }
    }
    int mode = D_0064B47C->first;
    if (!mode) mode = D_0064B47C->second;
    func_005319A8(obj, packet->type, id.value, mode);
    return 0x4c;
}
