/* compiler: ee-gcc2.9-991111 */
/* Count live descriptors while owning the table semaphore. The table has
 * 32 sixteen-byte records; the backend handle is distinct from occupancy. */
struct Entry { int handle, occupied, unknown8, unknownC; };
extern struct Entry D_008897C0[32];
extern int D_00658348;
extern void func_005B20E0(void);
extern int func_005ADCE0(int);
extern int func_005ADCC0(int);
int func_005B2150(void) {
    struct Entry *entry;
    int count = 0;
    func_005B20E0();
    func_005ADCE0(D_00658348);
    for (entry = D_008897C0; entry < D_008897C0 + 32; ++entry)
        if (entry->occupied) ++count;
    func_005ADCC0(D_00658348);
    return count;
}
