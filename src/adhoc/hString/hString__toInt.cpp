#include "types.h"

extern "C" void func_005A2F88(void *arg0);
extern "C" char D_0069E1B0[];

/* Layout backed by include/gt4/hString.h, config/class_layout.json and bastring.h:
 *   0x00..0x0F: hObject base fields (0x04 vtable)
 *   0x10: str (string buffer pointer at 0x10)
 *   Rep header precedes buffer: p - sizeof(Rep) has len at offset 0
 */
struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
};

struct hStringLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    Str str;
};

extern "C" void func_005A2F88(void *arg0);
extern "C" char D_0069E1B0[];

extern "C" void hString__toInt(hStringLayout *self) {
    Str *s = &self->str;
    char *obj = s->p;
    Rep *rep = (Rep *)obj - 1;
    s32 off = rep->len;
    void *a0v;
    if (off == 0) {
        a0v = D_0069E1B0;
    } else {
        obj[off] = 0;
        a0v = s->p;
    }
    func_005A2F88(a0v);
}

