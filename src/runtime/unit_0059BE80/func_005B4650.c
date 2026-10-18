/* compiler: ee-gcc2.9-991111 */
/* Allocate a file-descriptor table slot, open the backend handle, and publish
 * its index under the table semaphore. Field names are provisional. */
struct Entry { int handle, occupied, unknown8, unknownC; };
extern int D_0065833C, D_00658348;
extern struct Entry D_008897C0[];
extern int func_005B27C8(int);
extern void func_005B28F0(void);
extern void func_005B27F8(void);
extern struct Entry *func_005B21D0(void);
extern int func_005B3ED8(const char *, int);
extern int func_005ADCE0(int);
extern int func_005ADCC0(int);
int func_005B4650(const char *name) {
    int result;
    struct Entry *entry;
    func_005B27C8(9);
    if(!D_0065833C) func_005B28F0();
    func_005B27F8();
    entry=func_005B21D0();
    if(!entry) return -19;
    result=func_005B3ED8(name,9);
    if(result<0) {
        func_005ADCE0(D_00658348);
        entry->occupied=0;
        func_005ADCC0(D_00658348);
        return result;
    } else {
        func_005ADCE0(D_00658348);
        entry->handle=result;
        result=entry-D_008897C0;
        func_005ADCC0(D_00658348);
        return result;
    }
}
