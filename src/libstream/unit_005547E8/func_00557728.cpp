/* compiler: ee-gcc2.96-nogcse */
/* Checks six ids (a value outside -0x63..0xC7C sets that bit of the returned mask); if any is bad it
   returns the mask. Otherwise it shifts the 64-bit entries at arg0+0x1D8 (entry i+6 to i-6, i+12 to i),
   formats the six ids into the buffer at arg0+0x48 with the format D_006C8800, and passes the string
   with its length plus one to func_00567018. The two loops must share one counter or the register
   allocation differs (found by free model B). The meaning of the table is unknown. */

typedef unsigned int u32;
typedef signed int s32;
typedef long long s64;
typedef unsigned long long u64;

extern char D_006C8800[];
extern char D_00655290[];

struct func_00567018_a0;
extern "C" u32 func_00567018(struct func_00567018_a0 *obj, s32 key, s32 a2, u32 len, s32 a4);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" int func_0057F260(char *);

extern "C" unsigned func_00557728(char *arg0, int *ids) {
    unsigned mask = 0;
    int i;
    for (i = 0; i < 6; i++) {
        if ((unsigned)(ids[i] + 0x63) >= 0xC7F) mask |= 1u << i;
    }
    if (mask != 0) return mask;

    s64 *p = (s64 *)(arg0 + 0x1D8);
    for (i = 0; i < 6; i++) {
        p[i - 6] = p[i + 6];
        p[i] = p[i + 12];
    }

    char *buf = arg0 + 0x48;
    func_0057DA20(buf, D_006C8800, ids[0], ids[1], ids[2], ids[3], ids[4], ids[5]);
    int n = func_0057F260(buf);
    func_00567018((struct func_00567018_a0 *)D_00655290, *(int *)arg0, (int)buf, n + 1, 0);
    return mask;
}
