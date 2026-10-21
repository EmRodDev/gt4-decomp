/* Start-up registration of the menu callbacks (shape inferred from the calls): builds a frame object (func_002ECDE0), then registers
 * init_menu and func_0012C9D0 under two names with func_002EAA50, passing the frame's handle at +0 each time (the names are string
 * constants D_0068CFA0 / D_0068CFA8, built with the library string class: grab() copies the shared empty string, assign() fills it,
 * destroy() releases it, so each name object lives and dies around its call). A third name D_0068CFB0 goes to func_00305CF8.
 * The frame is torn down with func_002EA590 at the end. What the strings contain is unknown. */
#include "types.h"

struct Rep { u32 len; u32 res; u32 ref; u32 selfish; };
struct Str { char *dat; char pad[0xC]; };
struct Heap { const char *name; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *r);
extern "C" u32 func_0057F260(const char *s);
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern "C" Str *func_005C2630(Str *self, u32 pos, u32 n1, const char *s, u32 n2);

static inline char *grab(Rep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}
static inline Str &assign(Str *str, const char *s, u32 n) { return *func_005C2630(str, 0, (u32)-1, s, n); }
static inline Str &assign(Str *str, const char *s) { return assign(str, s, func_0057F260(s)); }
static inline void construct(Str *str, const char *s) { str->dat = grab(&D_00659FA8); assign(str, s); }
static inline Rep *rep(const Str *str) { return (Rep *)str->dat - 1; }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(Rep) + ((Rep *)ptr)->res); }
static inline void release(Rep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(Str *str) { release(rep(str)); }

struct Frame {
    s32 h0;
    s32 pad0[3];
    char o10[0x10];
    Str s20;
    Str s30;
};

extern char D_0068CFA0[];
extern char D_0068CFA8[];
extern char D_0068CFB0[];

extern "C" void func_001051D8(void);
extern "C" void func_001DC5F8(void *, s32);
extern "C" s32 func_001DC8F0(void *);
extern "C" void func_002EA590(void *, s32);
typedef void (*FnPtr)(void);
extern "C" void func_002EAA50(s32, Str *, FnPtr);
extern "C" void init_menu(void);
extern "C" void func_0012C9D0(void);
extern "C" void func_002EC3A0(void *, s32);
extern "C" void func_002ECDE0(void *);
extern "C" void func_003041B8(void *, s32);
extern "C" void func_00305CF8(s32, Str *);
extern "C" void func_004361D0(void);
extern "C" void func_0043A490(void);

extern "C" void func_0010AFC8(void) {
    Frame frame;
    Str *nameString;
    func_002ECDE0(&frame);
    func_001DC8F0(frame.o10);
    nameString = &frame.s20;
    {
        s32 h = frame.h0;
        construct(nameString, D_0068CFA0);
        func_002EAA50(h, nameString, init_menu);
        destroy(nameString);
    }
    {
        s32 h = frame.h0;
        construct(nameString, D_0068CFA8);
        func_002EAA50(h, nameString, func_0012C9D0);
        destroy(nameString);
    }
    func_0043A490();
    func_004361D0();
    func_002EC3A0(nameString, frame.h0);
    {
        s32 nameChars = (s32)nameString->dat;
        construct(&frame.s30, D_0068CFB0);
        func_00305CF8(nameChars, &frame.s30);
        destroy(&frame.s30);
    }
    func_003041B8(nameString, 2);
    func_001051D8();
    func_001DC5F8(frame.o10, 2);
    func_002EA590(&frame, 2);
}
