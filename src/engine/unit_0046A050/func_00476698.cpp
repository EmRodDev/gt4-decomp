/* Looks up a name in the 16-entry table D_006244F0 (pairs of name pointer and type number, searched by
 * func_006061E0) and returns the hit as a script value (inferred from the Val type/payload pair and the copy
 * helper func_00476768). A temporary value starts with type 1; on a hit its type becomes the entry's type, and for
 * type 9 the payload is set to owner + 0x40 (the address of something inside the owner; what it is is unknown). On
 * a miss the temporary stays as an empty value. The temporary is copied into the result and released. The name is
 * a counted string whose c_str helper returns the shared empty string D_006AD5A8 for length 0 and otherwise writes
 * the terminator byte, which is why the string layout is written out in this file. The result pointer is also the
 * return value. */
#include "types.h"

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);
extern "C" void func_00476768(Val *, const Val *);

struct Entry { const char *name; s32 type; };
extern "C" Entry *func_006061E0(const char *key, Entry *table, s32 count);
extern Entry D_006244F0[];
extern char D_006AD5A8[];

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
    const char *c_str() const { if (length() == 0) return D_006AD5A8; terminate(); return data(); }
};

extern "C" Val *func_00476698(Val *result, const String &name, char *owner) {
    Val temp;
    Entry *entry;
    temp.type = 1;
    entry = func_006061E0(name.c_str(), D_006244F0, 16);
    if (entry) {
        s32 type = entry->type;
        func_004768C0(&temp);
        temp.type = type;
        if (entry->type == 9)
            temp.v = (s32)(owner + 0x40);
    } else {
        func_004768C0(&temp);
    }
    func_00476768(result, &temp);
    func_004768C0(&temp);
    return result;
}
