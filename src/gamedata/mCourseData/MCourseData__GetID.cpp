/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script native for MCourseData.GetID (inferred from the symbol name): turns a course name string into an integer id.
 * args[0] is read as a string through vtable slot 0x18 (the union u holds the string, then is reused as an int handle buffer),
 * c_str() is taken (empty string falls back to D_00693270), the std::string is released, and func_00447C78(name) gives the id,
 * masked with 0xFFFFFFFF as the compiler wants a long truncated to 32 bits. func_002FE278 boxes the id into an int handle that is
 * stored into ret with retain-new / release-old. Skipped when argc <= 0. */
typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; s32 pad[3]; };
union U { Str s; s32 h[4]; };
struct VEntry { short delta; short index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

extern char D_00693270[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" long func_00447C78(const char *s);
extern "C" void func_002FE278(void *ret, s32 argc);
extern "C" void func_002FC870(void *ret, int argc);
extern "C" void func_003285A8(s32 ret);
extern "C" void func_003285F8(s32 ret);

static inline void vcall(void *ret, VObj *o) {
    VEntry *e = &o->vtbl[3];
    e->fn(ret, (char *)o + e->delta);
}

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_00693270;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { s32 size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}

extern "C" void MCourseData__GetID(s32 *ret, s32 argc, VObj **args) {
    if (argc > 0) {
        const char *nameText;
        U tmp;
        s32 courseId;
        s32 newVal;
        s32 oldVal;

        vcall(&tmp, *args);
        nameText = c_str(&tmp.s);
        release(&tmp.s);
        courseId = func_00447C78(nameText) & 0xFFFFFFFFL;
        func_002FE278(&tmp, courseId);
        if (ret != tmp.h) {
            newVal = tmp.h[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *ret;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *ret = newVal;
        }
        func_002FC870(&tmp, 2);
    }
}
