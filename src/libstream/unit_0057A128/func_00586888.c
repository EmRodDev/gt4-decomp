/* compiler: ee-gcc2.9-991111 */
struct Handler {
    char pad0[8];
    struct Handler *next;
    char padC[0x18];
    int (*fn)(int, struct Handler *);
};
extern struct Handler *D_00875898;

/* Repeat the first register attribute because this compiler overwrites its
   original entry while processing the next one. Both registers preserve all
   128 bits across this SDK callback dispatcher. */
void func_00586888(int arg)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));

void func_00586888(int arg) {
    struct Handler *h;
    for (h = D_00875898; h; h = h->next)
        h->fn(arg, h);
}
