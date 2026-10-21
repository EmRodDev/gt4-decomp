/* compiler: ee-gcc2.9-991111 */
struct Library {
    char pad[0x10];
    const char *name;
    unsigned short version;
};
extern int func_0057F238(const char *, const char *);

int func_005868F0(struct Library *a, struct Library *b)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));

int func_005868F0(struct Library *a, struct Library *b) {
    if (func_0057F238(a->name, b->name))
        return 0;
    return (a->version >> 8) == (b->version >> 8);
}
