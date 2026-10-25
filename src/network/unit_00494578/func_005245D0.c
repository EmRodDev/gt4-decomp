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
    char pad[0x38];
} State;

typedef struct Obj {
    void *ctx;
    char pad4[0x80];
    State *state;
    char pad88[0x30];
    unsigned short port;
    char padBA[0x16];
    int value;
} Obj;

typedef struct Request {
    Address key;
    int id;
    int zero;
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
int func_005293D0(void *, const void *, void **);
void *func_005A48D8(void *, int, unsigned int);
void func_005256A8();
void func_005257B0();

int func_005245D0(Obj *self, Input *in, int value)
{
    Request lreq;
    Request rreq;
    unsigned short pos = 0xFFFE;
    int status = 0;
    State *s;
    int error;

    if (!self) return 2;
    func_00526040(self, &status, &pos);
    if (status == 0) {
        s = self->state;
        func_005A48D8(s, 0, sizeof(State));
        if (D_0064B4B0->same(in->local.value, in->remote.value) && in->localId == in->remoteId) {
            D_0064B4B0->reset(in);
            in->localId = 0;
        }
        if (!D_0064B4B0->isNull(in->remote.value) && in->remoteId != 0) {
            func_005A48D8(&rreq, 0, sizeof(Request));
            rreq.key = in->remote;
            rreq.id = in->remoteId;
            rreq.port = self->port;
            rreq.cb1 = func_005256A8;
            rreq.cb2 = func_005257B0;
            rreq.zero = 0;
            rreq.owner = self;
            if (s->remoteHandle) return 0xD2F3;
            error = func_005293D0(self->ctx, &rreq, &s->remoteHandle);
            if (error) return error;
            s->flag = 1;
        }
        if (!D_0064B4B0->isNull(in->local.value) && in->localId != 0) {
            func_005A48D8(&lreq, 0, sizeof(Request));
            lreq.key = in->local;
            lreq.id = in->localId;
            lreq.port = self->port;
            lreq.cb1 = func_005256A8;
            lreq.cb2 = func_005257B0;
            lreq.zero = 0;
            lreq.owner = self;
            if (s->localHandle) return 0xD2F3;
            error = func_005293D0(self->ctx, &lreq, &s->localHandle);
            if (error) return error;
            s->flag = 1;
        }
        if (s->flag != 1) return 0xD4ED;
        self->value = value;
        return 0;
    }
    return 0xD4E7;
}
