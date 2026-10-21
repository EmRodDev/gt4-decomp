/* Calls a named handler: looks the string up with func_006066C8 (a table at D_00624570, third argument 0xF) and, when an entry is
 * found, calls the function pointer stored at +8 of the entry with the result slot and the second argument. Otherwise the result
 * slot is set to 1. An empty name is replaced by the shared empty string D_006AD838 and a non-empty one is NUL-terminated in
 * place, which is what the inline c_str() does (shape of the library string class). Reads like a script-native dispatcher
 * (inferred); the table's contents are unknown. */
#include "types.h"

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};

extern "C" void *func_006066C8(void *table, char *name, int flags);
extern char D_00624570[];
extern char D_006AD838[];

struct Callee {
    s32 pad0;
    s32 pad1;
    void (*fn)(s32 *, s32);
};

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006AD838;
    s.terminate();
    return s.data();
}

extern "C" s32 *func_0047B728(s32 *result, s32 argument, String *name) {
    void *found = func_006066C8((void *)c_str(*name), D_00624570, 0xF);
    if (found) {
        Callee *entry = (Callee *)found;
        entry->fn(result, argument);
        return result;
    }
    *result = 1;
    return result;
}
