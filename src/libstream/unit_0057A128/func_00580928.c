/* compiler: ee-gcc2.9-991111 */

extern int D_00655EE8;
extern int D_00655F40;
extern char D_00657090[];
extern int func_005807D0(int);
extern void func_005ADCC0(int);
extern int func_005B19B0(void *, int, int, void *, int, void *, int,
                       void *, void *);

/* Command gate 2 submits RPC 14 without a payload and returns its DMA reply.
 * The gate retains the shared semaphore, so both RPC outcomes release it. */
int func_00580928(void)
{
    int result;
    if (!func_005807D0(2))
        return 0;
    if (func_005B19B0(D_00657090, 14, 0, 0, 0, &D_00655F40, 4, 0, 0) < 0) {
        func_005ADCC0(D_00655EE8);
        return 0;
    }
    result = *(int *)((unsigned int)&D_00655F40 | 0x20000000);
    func_005ADCC0(D_00655EE8);
    return result;
}
