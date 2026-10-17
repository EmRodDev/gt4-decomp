/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Request {
    int status;
    int field4;
    int pad8;
    char pad[0x10 - 0xC];
    int pad10;
    int pad14;
    unsigned int limit;
    int buffer;
    Request *self;
    int pad24;
    char pad28[0x34 - 0x28];
    int mode;
};

extern "C" int func_00590FD8(int, int, int, Request *, int, Request *, int, int, int);
extern "C" int func_00571850(int buffer, int limit);

extern "C" int func_005716D8(int unit, Request *r)
{
    r->status = 0;
    r->self = r;
    r->pad24 = 0;
    r->field4 = 0;
    if (func_00590FD8(unit, 0x65, 0, r, 0x50, r, 0x50, 0, 0) < 0)
        return 1;
    if (r->mode == 0 || r->mode == 3) {
        unsigned int limit = r->limit;
        if (limit < (unsigned int)r->pad8 + 0x40)
            return 1;
        {
            int result = func_00571850(r->buffer, limit);
            if (result)
                return result;
        }
    }
    return 0;
}
