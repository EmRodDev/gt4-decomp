/* compiler: ee-gcc2.96-g-as2004g */
typedef unsigned long U64;
typedef U64 Key8 __attribute__((aligned(4)));

typedef struct Address {
    Key8 value;
} Address;

typedef struct Input {
    Address local;
    Address remote;
    int localId;
    int remoteId;
} Input;

typedef struct State {
    int flag;
    void *localHandle;
    void *remoteHandle;
    char padC[0x20];
    unsigned short seq;
    char pad2E[0x16];
} State;

typedef struct Obj {
    void *ctx;
    char pad4[0x80];
    State *state;
    char pad88[0x30];
    unsigned short port;
    char padBA[0xA];
    unsigned short seq;
    char padC6[0xA];
    int value;
} Obj;

typedef struct Request {
    Address key;
    int id;
    int index;
    unsigned short port;
    unsigned short pad;
    void (*cb1)();
    void (*cb2)();
    Obj *owner;
} Request;

typedef struct Api {
    char pad[0x6c];
    void (*reset)(Input *);
    int (*isNull)(Key8);
    int (*same)(Key8, Key8);
} Api;

extern Api *D_0064B4B0;
void func_00526040(Obj *, int *, unsigned short *);
int func_00525EC0(Obj *, Input *, unsigned short *);
int func_005260A8(Obj *);
int func_0052A3B0(void *, const void *, void **);
void func_005256A8();
void func_005257B0();

int func_005243B0(Obj *self, Input *in)
{
    Request req;
    int status = 0;
    unsigned short pos = 0xFFFE;
    State *s;
    int error;
    int i;

    if (!self) return 2;
    func_00526040(self, &status, &pos);
    if (status == 7) {
        pos = 0xFFFE;
        error = func_00525EC0(self, in, &pos);
        if (error) return error;
        if (pos == 0xFFFE) {
            i = func_005260A8(self);
            pos = i;
            if (i == 0xFFFE) return 0xD4E8;
            s = &self->state[pos];
            req.index = pos;
            s->seq = ++self->seq;
            if (D_0064B4B0->same(in->local.value, in->remote.value) && in->localId == in->remoteId) {
                D_0064B4B0->reset(in);
                in->localId = 0;
            }
            req.index = pos;
            req.port = self->port;
            req.cb2 = func_005257B0;
            req.cb1 = func_005256A8;
            req.owner = self;
            if (!D_0064B4B0->isNull(in->local.value) && in->localId != 0) {
                req.key = in->local;
                req.id = in->localId;
                error = func_0052A3B0(self->ctx, &req, &s->localHandle);
                if (error) return error;
                s->flag = 2;
            }
            if (!D_0064B4B0->isNull(in->remote.value) && in->remoteId != 0) {
                req.key = in->remote;
                req.id = in->remoteId;
                error = func_0052A3B0(self->ctx, &req, &s->remoteHandle);
                if (error) return error;
                s->flag = 2;
            }
            return 0;
        }
        return 0xD4E7;
    }
    return 0;
}
