/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct E { s32 a, b; u32 w8; };
struct S { E e[8]; s32 idx; };
extern "C" s32 func_00609DF8(S *s, u32 key) {
loop:
    s32 i = s->idx;
    if (i < 0) return 0;
    if (!(key < s->e[i].w8)) {
        s->idx = i - 1;
        goto loop;
    }
    return 1;
}
