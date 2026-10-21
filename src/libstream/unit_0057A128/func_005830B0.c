/* compiler: ee-gcc2.9-991111 */

/* Shared CD streaming RPC request. Field roles are inferred from its callers;
 * the trailing byte belongs to the 20-byte wire layout and is left unchanged. */
typedef struct {
    unsigned char retry_count;
    unsigned char spindle_control;
    unsigned char data_pattern;
    unsigned char reserved;
} ReadMode;

typedef struct {
    unsigned int sector;
    unsigned int sector_count;
    void *buffer;
    int command;
    ReadMode mode;
} StreamRequest;

extern int D_00655ED0;
extern int D_00655EE8;
extern int D_00655F40;
extern StreamRequest D_00655FC0;
extern char D_00657090[];
extern const char D_006CE3C0[], D_006CE3D8[], D_006CE3F0[];

extern int func_005807D0(int);
extern void func_005ADCC0(int);
extern void func_005B0750(const char *, ...);
extern void func_005B0F78(void *, int);
extern int func_005B19B0(void *, int, int, void *, int, void *, int,
                       void *, void *);

int func_005830B0(unsigned int sector, unsigned int sector_count,
                  void *buffer, int command, const ReadMode *mode)
{
    int result;
    StreamRequest *request = &D_00655FC0;
    if (!func_005807D0(15))
        return 0;
    if (D_00655ED0 > 0)
        func_005B0750(D_006CE3C0);

    D_00655FC0.sector = sector;
    request->sector_count = sector_count;
    request->buffer = buffer;
    request->command = command;
    if (mode) {
        request->mode.retry_count = mode->retry_count;
        request->mode.spindle_control = mode->spindle_control;
        request->mode.data_pattern = mode->data_pattern;
    }
    if (D_00655ED0 > 0)
        func_005B0750(D_006CE3D8);
    func_005B0F78(request, 20);
    if (func_005B19B0(D_00657090, 9, 0, request, 20,
                      &D_00655F40, 4, 0, 0) < 0) {
        func_005ADCC0(D_00655EE8);
        return 0;
    }
    if (D_00655ED0 > 0)
        func_005B0750(D_006CE3F0);

    /* RPC writes the result through DMA: read the uncached EE alias. */
    result = *(int *)((unsigned int)&D_00655F40 | 0x20000000);
    func_005ADCC0(D_00655EE8);
    return result;
}
