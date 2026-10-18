/* Look a name up in a table of { value, name } pairs; store the value through `out` when given. */
struct Entry { int value; const char *name; };
struct Table { Entry *entries; unsigned count; };
extern "C" int func_0057F238(const char *, const char *); /* strcmp-like */
extern "C" int func_0057B210(Table *t, const char *name, int *out) {
    for (unsigned i = 0; i < t->count; i++) {
        if (func_0057F238(t->entries[i].name, name) == 0) {
            if (out) *out = t->entries[i].value;
            return 1;
        }
    }
    return 0;
}
