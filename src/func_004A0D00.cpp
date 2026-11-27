/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"

/* Resets one of the three DMA channels this unit drives (index 0..2, called by func_004A0D98 with
   the channels' CHCR values 0x40/0xC0/0x80): writes the mode to the channel's first register and
   clears five more of its registers through the channel table D_00629DC8, clears the channel's two
   state bytes in the scratchpad work area and creates the channel's semaphore (CreateSema, max 1,
   initial 1).

   Register layout of the channel block and the meaning of the two bytes are unknown. The channel
   state lives at scratchpad +0x50 (the Sub block func_004A0C10 and func_004A0BE0 also use),
   twelve bytes per channel from +0x1C. */

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

struct Chan {
    unsigned char b0, b1;
    char pad2[6];
    int sema;
};

struct Sub {
    char pad[0x1C];
    Chan ch[3];
};

struct Spr {
    char pad[0x50];
    Sub sub;
};

extern volatile unsigned int *D_00629DC8[];
extern "C" int func_005ADCA0(SemaParam *);

extern "C" void func_004A0D00(int ch, int mode) {
    Spr *s = (Spr *)spr_base();
    Sub *p = &s->sub;
    volatile unsigned int *r = D_00629DC8[ch];
    SemaParam sp;
    r[0] = mode;
    r[4] = 0;
    r[12] = 0;
    r[16] = 0;
    r[20] = 0;
    r[32] = 0;
    p->ch[ch].b0 = 0;
    p->ch[ch].b1 = 0;
    sp.initCount = 1;
    sp.maxCount = 1;
    p->ch[ch].sema = func_005ADCA0(&sp);
}
