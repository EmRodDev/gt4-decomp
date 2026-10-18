/* compiler: ee-gcc2.9-991111 */
/* Replace the caller-owned 16-byte entry table under interrupt exclusion.
 * The previous table is returned to its owner; the replacement is cleared.
 * Callback register types and the final word remain provisional. */
struct Entry {
    void (*callback)(int, void *);
    void *argument;
    void *global_pointer;
    unsigned unknownC;
};
extern struct Entry *D_00659310;
extern unsigned int D_00659314;
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern void *func_005A48D8(void *, int, unsigned int);
struct Entry *func_005B9310(struct Entry *table, unsigned int count) {
    int interrupts = func_005B72A8();
    struct Entry *previous = D_00659310;
    D_00659310 = table;
    D_00659314 = count;
    func_005A48D8(table, 0, count * sizeof(struct Entry));
    if (interrupts) func_005B72F8();
    return previous;
}
