/* compiler: ee-gcc2.96-no-strict-aliasing */
struct RaceRichCountDisplay {
    char pad[0x68];
    int count;
    int total;
    int limit;
    int dirty;
    char text[0x10];
};
extern "C" char D_006A1468[], D_006A1488[];
extern "C" void func_0057DA20(char *, const char *, ...);

extern "C" void RaceRichCountDisplay__make_string(RaceRichCountDisplay *s) {
    int limit = s->limit;
    int count = s->count;
    int total = s->total;
    if (limit < count) count = limit;
    if (total == 0) {
        func_0057DA20(s->text, D_006A1468, count);
    } else {
        if (limit >= total) limit = total;
        func_0057DA20(s->text, D_006A1488, count, limit);
    }
    s->dirty = 0;
}
