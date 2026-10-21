/* compiler: ee-gcc2.9-991111 */
#include "ee_kernel.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef void (*sceSifCmdHandler)(void *, void *);

typedef struct {
    sceSifCmdHandler func;
    void *data;
    void *gp;
} sceSifCmdData;

typedef struct {
    unsigned int psize:8;
    unsigned int dsize:24;
    unsigned int dest;
    unsigned int fcode;
    unsigned int opt;
} sceSifCmdHdr;

struct CmdData {
    void *pktbuf;
    void *unused;
    void *iopbuf;
    sceSifCmdData *sys;
    int nsys;
    sceSifCmdData *usr;
    int nusr;
};

extern struct CmdData D_00886818;
extern int func_005AE090(void);

/* eekernel.h's SetGp carries a "memory" clobber: the handler table is reloaded after it. */

/* _sceSifCmdIntrHdlr */
int func_005B0E30(void)
{
    u_long128 pkt[7];
    struct CmdData *cd = &D_00886818;
    volatile sceSifCmdHdr *h = (volatile sceSifCmdHdr *)cd->pktbuf;
    sceSifCmdHandler func;
    u_long128 *src;
    int size, i;

    size = h->psize;
    if (size == 0)
        return 0;
    size = (size + 15) / 16;
    h->psize = 0;
    src = (u_long128 *)h;
    for (i = 0; i < size; i++)
        pkt[i] = *src++;
    func_005AE090();
    h = (volatile sceSifCmdHdr *)pkt;
    if (h->fcode & 0x80000000) {
        size = h->fcode & 0x7FFFFFFF;
        if (size < cd->nsys) {
            func = cd->sys[size].func;
            if (func) {
                void *gp = SetGp(cd->sys[size].gp);
                func(pkt, cd->sys[size].data);
                SetGp(gp);
            }
        }
    } else {
        size = h->fcode;
        if (size < cd->nusr) {
            func = cd->usr[size].func;
            if (func) {
                void *gp = SetGp(cd->usr[size].gp);
                func(pkt, cd->usr[size].data);
                SetGp(gp);
            }
        }
    }
    ExitHandler();
    return 0;
}
