/* Builds a request from the object and the given value (func_0025A7E0, func_0026AC20 with constants 1, 0, 1), and if it produced a result, passes the result to func_00154290 together with the member at +0x2A4.
 * Both temporaries are released (mode 2). Purpose unknown. */
typedef int s32;

extern "C" void func_0025A7E0(void *buf, void *value);
extern "C" void func_0026AC20(void *self, s32 value, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern "C" void func_0026A118(void *buf, s32 value);
extern "C" void func_0021B328(void *buf, void *value);
extern "C" void func_00154290(s32 self, void *buf);
extern "C" void func_0021B340(void *self, s32 value);

struct ObjA {
    char pad[0x2A4];
    s32 unk2A4;
};

extern "C" void func_0013A678(ObjA *self, s32 value) {
    s32 result[4];
    s32 request[4];
    s32 *requestPtr = request;

    func_0025A7E0(requestPtr, self);
    func_0026AC20(result, *requestPtr, value, 1, 0, 1);
    func_0026A118(requestPtr, 2);
    if (result[0] != 0) {
        func_0021B328(requestPtr, result);
        func_00154290(self->unk2A4, requestPtr);
    }
    func_0021B340(result, 2);
}
