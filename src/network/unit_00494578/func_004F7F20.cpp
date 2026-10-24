/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Msg { char pad0[0x18]; int x18; char pad1c[0x20]; int x3C; signed char x40; char pad41[0x3F]; };
struct Queue { char pad0[0x5318]; Msg entries[16]; char pad5b18[0x20]; int write; int read; int count; };
struct Request { char x0; char pad1[0x14]; char name[0x13]; int x28; int x2C; char x30; char x31; char pad32[0x3E]; };
struct Session { char pad0[0x5A8]; Queue *queue; char pad5ac[0x54C]; char name[0x11]; };
extern "C" void *func_005A6AB0(void *, const void *, int);
extern "C" int func_0050CB00(Request *);
extern "C" void func_004F87B0(Session *, int);
extern "C" void func_004F0BF0(Session *, int);

extern "C" void func_004F7F20(Session *self, Msg *msg) {
    if (self->queue == 0) {
        int type = msg->x3C;
        if (type == 1 && msg->x40 != 0x32) {
            Request req;
            req.x0 = 0;
            func_005A6AB0(req.name, self->name, 0x11);
            req.x28 = type;
            req.x2C = msg->x18;
            req.x30 = 0x32;
            req.x31 = 0;
            int r = func_0050CB00(&req);
            if (r != 0)
                func_004F87B0(self, r);
        }
        return;
    }
    if (msg->x3C == 1 && msg->x40 == 0x32) {
        func_004F0BF0(self, 2);
        return;
    }
    Queue *q = self->queue;
    q->count++;
    int *w = &self->queue->write;
    int i = *w;
    self->queue->entries[i] = *msg;
    *w = ++i;
    if (self->queue->write >= 16)
        self->queue->write = 0;
    if (self->queue->count >= 16) {
        self->queue->count = 16;
        if (++self->queue->read >= 16)
            self->queue->read = 0;
    }
}
