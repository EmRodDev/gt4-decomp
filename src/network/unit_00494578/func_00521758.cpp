/* compiler: ee-gcc2.96-as2004g */
struct Id { long v; } __attribute__((packed));
struct Param { int x0, x1, x2; };
struct Request { char kind; char pad[0xFF]; Id id; int pad108; };
struct Session {
    int handle;
    char pad4[0x8];
    Id id;
    char pad14[0x200];
    int c214;
    char pad218[4];
    int c21C;
    int owner;
};
extern Session D_00863C08;
extern "C" int func_005224D0(long);
extern "C" int func_00522070(int);
extern "C" void func_005224B0(long *);
extern "C" int func_00520D88(Session *, long, int, Param *);
extern "C" void func_005218E0(Session *, Request *);
extern "C" int func_00520F90(int, long, int, void *, int, int *);
extern "C" void func_00520E60(int);
extern "C" void func_0053A860(void *);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_00521758(Request *req) {
    Param param;
    long handle[2];
    int out = 0;
    if (!req) return 2;
    if (!req->pad108) return 2;
    if (!req->kind) return 2;
    if (func_005224D0(req->id.v) != 0) return 2;
    Session *s = &D_00863C08;
    if (s->owner == 0) {
        s->owner = req->pad108;
        if (func_00522070(req->kind) != 0 || func_005224D0(req->id.v) != 0) {
            func_005A48D8(s, 0, 0x224);
            return 2;
        }
        s->id = req->id;
        func_005A48D8(&param, 0, 12);
        param.x0 = 1;
        param.x1 = 0x200;
        func_005224B0(handle);
        int r = func_00520D88(s, handle[0], 0, &param);
        if (r == 0) {
            func_005218E0(s, req);
            r = func_00520F90(s->handle, s->id.v, 0x35, (char *)s + 0x14, s->c214, &out);
            if (r == 0) goto done;
            func_00520E60(s->handle);
        }
        func_005A48D8(s, 0, 0x224);
        return r;
    }
    return 0xC357;
done:
    func_0053A860((char *)s + 4);
    s->c21C = 0;
    return 0;
}
