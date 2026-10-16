/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned long long Key __attribute__((aligned(4)));
struct Self;
struct P8 { int a, b; };
struct Args { Self *self; unsigned int id; P8 *p; int num; int pad; int data; };
struct State { char pad0[12]; int mode; char pad10[16]; int enabled; };
struct Self { char pad0[256]; State *state; char pad104[56]; void (*cb)(Args *); int data; char pad144[8]; int count; };
struct Rec { Key key; int pad8; int num; char pad10[16]; int valid; };
struct A { char pad0[0x7c]; void (*fn)(P8 *, Key); };
struct B { char pad0[8]; void (*start)(Self *, unsigned int); char padC[0x8c]; void (*end)(Self *, int, int, int); };
extern A *D_0064B4B0;
extern B *D_0064B4B4;
extern "C" Rec *func_00535C88(Self *, unsigned int);
extern "C" void func_00531C40(Self *, unsigned int);
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" int func_00532628(Self *self, unsigned int id) {
    Rec *r;
    State *s;
    if (id >= 0x40) return 23;
    if (self == 0) return 23;
    r = func_00535C88(self, id);
    s = self->state;
    if (r != 0 && r->valid) {
        if (D_0064B4B4) D_0064B4B4->start(self, id);
        if (s->enabled && self->cb) {
            P8 tmp;
            Args args;
            D_0064B4B0->fn(&tmp, r->key);
            func_005A48D8(&args, 0, sizeof(args));
            args.num = r->num;
            args.data = self->data;
            args.self = self;
            args.id = id;
            args.p = &tmp;
            self->cb(&args);
        }
        func_00531C40(self, id);
        if (s->mode == 3) {
            D_0064B4B4->end(self, 0, 0, 0);
            return 0;
        }
        return 0;
    }
    if (self->count) self->count--;
    if (s->mode == 3) D_0064B4B4->end(self, 0, 0, 0);
    return 0;
}
