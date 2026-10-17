/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Wrap { unsigned limit; unsigned offset; };
extern "C" float func_00579548(void *);
extern "C" void func_005D2370(void *data, unsigned n, void *rng, void (*swap)(void *, unsigned, unsigned), Wrap *w) {
    unsigned i;
    unsigned limit = w->limit;
    if (!(n < limit)) n -= w->offset;
    i = n - 1;
    while (i != 0) {
        unsigned idx = i;
        unsigned j;
        if (!(i < w->limit)) idx = i + w->offset;
        {
            float r = func_00579548(rng);
            unsigned u = i + 1;
            float fu = (float)u;
            j = (unsigned)(r * fu);
        }
        i--;
        if (!(j < w->limit)) j += w->offset;
        swap(data, idx, j);
    }
}
