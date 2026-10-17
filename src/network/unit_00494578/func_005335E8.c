/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct Request { struct Obj *self; int type; int active; int zero; void *user; };
struct Obj { char pad[0x12C]; void (*callback)(struct Request *); void *user; char pad134[0x10]; int state; };
void *func_005A48D8(void *, int, unsigned int);
void func_005335E8(struct Obj *self) {
    if (self->callback) {
        struct Request req;
        struct Request *r = &req;
        func_005A48D8(r, 0, sizeof(req));
        r->self = self;
        self->state = 4;
        r->type = 4;
        r->active = 1;
        r->zero = 0;
        r->user = self->user;
        self->callback(r);
    }
}
