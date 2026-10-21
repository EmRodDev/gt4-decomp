/* Sets up and runs one transfer through a 64-byte-aligned work block carved out of the local 0xD0-byte scratch buffer (the '& ~0x3F' on buf+0x8F aligns it; alignment suggests DMA-style hardware, inferred): func_001CE460/001CE4F0 prepare it and a non-zero status is returned as is; then the block is programmed from three words stored in the state object arg2 (offsets -0x7E34, -0x7E20, -0x7E10 relative to +0x10000), the two flags optionally add steps, and finally virtual slot arg1->vptr+0x88 is called with the block and 0x40. Returns 4 on setup failure, 1 when the slot call fails, 0 on success (the saved word is written back only on success). Real purpose not determined. */
typedef long s64;
struct Obj { char p[0x3C]; int f3c; };
struct Cls { char p[0x81CC]; };
struct Big { char p0[0x1000 * 0]; };
struct Ctx { char p[0x10000 + 0x81CC - 0x10000]; };
struct Vt { short off; short pad; int (*fn)(void *, char *, Obj *, int, int); };
struct Inst { char p[0x88]; Vt vt; };
struct Hdr { Inst *vptr; };

extern "C" void func_001CB8D8(void *, s64) throw();
extern "C" void func_001CB900(void *) throw();
extern "C" void func_001CB9B8(void *, int) throw();
extern "C" int func_001CBA80(void *, int, int, int) throw();
extern "C" int func_001CBAD0(void *, int) throw();
extern "C" void func_001CBB48(void *, int, int) throw();
extern "C" char *func_001CE460(void *, char *) throw();
struct Result { int value; };
extern "C" Result func_001CE4F0(void *, void *, int) throw();
static inline int status(const Result *const x) { return x->value; }
extern "C" unsigned long func_004359E0(char *);

#define F(p, o) (*(int *)((char *)(p) + 0x10000 + (o)))

static inline bool is_set(int v) { return v != 0; }
extern "C" int func_001CE868(void *context, Hdr *channel, char *state, int flagA, int flagB) {
    char scratch[0xD0];
    func_001CE460(context, scratch);
    Obj *block = (Obj *)(((int)&scratch[0x8F]) & ~0x3F);
    Result result = func_001CE4F0(context, channel, (int)block);
    int code = result.value;
    if (status(&result))
        return code;
    int wordA = F(state, -0x7E34);
    func_001CB9B8(block, wordA);
    if (func_001CBA80(block, wordA, F(state, -0x7E20), F(state, -0x7E10)) == 0)
        return 4;
    if (is_set(flagB))
        func_001CB8D8(block, func_004359E0(state));
    if (is_set(flagA))
        func_001CBB48(block, F(state, -0x7E20), flagA);
    func_001CBAD0(block, F(state, -0x7E10));
    int savedWord = block->f3c;
    func_001CB900(block);
    Vt *sendSlot = &channel->vptr->vt;
    int sendResult = sendSlot->fn((char *)channel + sendSlot->off, scratch, block, 0x40, 0);
    if (is_set(sendResult))
        return 1;
    F(state, -0x7E10) = savedWord;
    return 0;
}
