/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;
struct Str {
    char *p;
    u32 size() const { return *(u32 *)(p - 0x10); }
    s32 at0() const { return size() ? p[0] : 0; }
};
extern "C" s32 func_004E7408(Str *s) {
    u32 n = s->size();
    int r = 0;
    if (!(n < 0x10)) return r;
    if (s->at0() >= 0x30) {
        if (s->at0() < 0x3A) return 1;
    }
    return r;
}
