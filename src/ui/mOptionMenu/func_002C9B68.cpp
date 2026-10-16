/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Sel { s32 cur; s32 first; s32 last; };
struct S { char pad[0xC4]; void *c4; char pad2[0x10]; Sel sel; };
extern "C" void *func_00206868(void *);
extern "C" void *func_0025C300(void *);
extern "C" s32 func_00265D98(void *);
extern "C" void func_00266200(void *, s32);
extern "C" void func_002C9898(S *, s32, s32) throw();
extern "C" s32 func_0057CE60(Sel *);
#define MIN(a, b) ((a) < (b) ? (a) : (b))
extern "C" void func_002C9B68(S *self, s32 arg1, s32 *values, s32 n) {
    if (self->c4 == 0) return;
    Sel *sel = &self->sel;
    s32 cur = sel->cur;
    s32 changed = 0;
    s32 cnt = MIN(n, func_0057CE60(sel));
    s32 i = 0;
    for (void *o = func_00206868(self->c4); i < cnt && o != 0; o = func_0025C300(o)) {
        if (func_00265D98(o) == 0) {
            if (cur == i && values[i] != 0) changed = 1;
            func_00266200(o, values[i]);
            i++;
        }
    }
    if (changed)
        func_002C9898(self, arg1, 0);
}
