/* compiler: ee-gcc2.96-nsa-as2004 */
struct Request {
    void *buffer;
    int size;
};

struct Callback {
    void *function;
    void *context;
};

extern "C" char D_008722C0[];
extern "C" void func_00557AD0(void);
extern "C" int func_00578B50(unsigned int, int);
extern "C" unsigned char *func_00578610(unsigned char *);
extern "C" unsigned char *func_005750C0(Request *, unsigned char *);
extern "C" int func_005788B8(void *);

extern "C" void func_005579F0(void *context)
{
    Request request;
    request.buffer = D_008722C0;
    request.size = 0x1000;
    unsigned char *slot = func_005750C0(&request, func_00578610((unsigned char *)func_00578B50(3, 0)));
    Callback callback;
    Callback *cb = &callback;
    cb->function = (void *)func_00557AD0;
    callback.context = context;
    *(Callback *)(slot + 0x38) = callback;
    func_005788B8(slot);
}
