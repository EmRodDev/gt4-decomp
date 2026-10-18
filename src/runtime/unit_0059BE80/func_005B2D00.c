/* compiler: ee-gcc2.9-991111 */
/* Submit operation 253 after a backend compatibility check and empty-table check.
 * Shared response RAM is read through its uncached alias before unlocking.
 * Operation semantics and the unused packet word remain provisional. */
struct Request { int argument; int unknown4; };
extern struct Request D_008882C0;
extern char D_008899C0;
extern int D_00888F00, D_0065833C;
extern int func_005B27C8(int);
extern void func_005B27F8(void);
extern int func_005B28F0(void);
extern int func_005B2AF8(void);
extern int func_005B2150(void);
extern unsigned int func_005B2258(void *, int, int, void *, int, void *, int,
    void (*)(void *), void *, int);
int func_005B2D00(int argument) {
    int result;
    func_005B27C8(253);
    if (!D_0065833C) func_005B28F0();
    if (func_005B2AF8()) {
        func_005B27F8();
        return 0xFFFEFFFC;
    }
    if (func_005B2150()) {
        func_005B27F8();
        return -16;
    }
    D_008882C0.argument = argument;
    if ((int)func_005B2258(&D_008899C0, 253, 0, &D_008882C0, 8,
                         &D_00888F00, 4, 0, 0, 0) < 0) {
        func_005B27F8();
        return -11;
    }
    result = *(int *)((unsigned)&D_00888F00 | 0x20000000);
    func_005B27F8();
    return result;
}
