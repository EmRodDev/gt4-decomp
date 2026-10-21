/* Script engine: calls a native function looked up by name (inferred from func_00606DD8 searching D_00624800 with the string). When found
 * it runs it with the argument and returns; otherwise it prints an error naming the missing function (func_0057D9C0) and stores 1
 * in result. */
#include "types.h"

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};

extern "C" void *func_00606DD8(void *result, char *argument, int name);
extern "C" s32 func_0057D9C0(const char *fmt, ...);
extern char D_006ADC80[];
extern char D_006ADCD0[];
extern char D_00624800[];

struct Callee {
    s32 pad0;
    s32 pad1;
    void (*fn)(s32 *, s32);
};

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006ADC80;
    s.terminate();
    return s.data();
}

extern "C" s32 *func_0047CA38(s32 *result, s32 *argument, String *name) {
    void *entry = func_00606DD8((void *)c_str(*name), D_00624800, 1);
    if (entry) {
        Callee *callee = (Callee *)entry;
        callee->fn(result, *argument);
        return result;
    }
    func_0057D9C0(D_006ADCD0, c_str(*name));
    *result = 1;
    return result;
}
