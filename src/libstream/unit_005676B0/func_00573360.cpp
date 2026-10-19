/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Inflate's code decoder (Info-ZIP inflate_codes) for a stream object that
   reads its input in 32-bit words and keeps a 32 KB history window. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

/* A Huffman table entry: e > 16 links a sub-table of e - 16 bits, e == 16 is a
   literal, e == 15 ends the block, other values are the number of extra bits. */
struct Huft {
    Huft *next;
    u16 n;
    u8 b;
    u8 e;
};


struct InflateStream {
    u64 bitbuf;          /* 0x00 */
    int bitcnt;          /* 0x08: bits left in bitbuf */
    u32 *in;             /* 0x0C */
    u32 *in_end;         /* 0x10 */
    u8 *window;          /* 0x14: history, or none */
    int wpos;            /* 0x18 */
    int pad1c;
    u8 *out;             /* 0x20 */
    u8 *out_end;         /* 0x24 */
    int pad28[2];
    Huft *tl;            /* 0x30 */
    Huft *td;            /* 0x34 */
    int bl;              /* 0x38: literal/length table bits, then its mask */
    int bd;              /* 0x3C: distance table bits, then its mask */
    int pad40;
    /* the vtable pointer follows at 0x44 */
    virtual void unknown0();
    virtual void refill();
    virtual void flush();
};

#define WMASK 0x7FFF

#define SAVE()                     \
    s->bitbuf = b;                 \
    s->bitcnt = k;                 \
    s->in = in;                    \
    s->in_end = in_end;            \
    s->wpos = w;                   \
    s->out = out;                  \
    s->out_end = out_end

#define LOAD()                     \
    b = s->bitbuf;                 \
    k = s->bitcnt;                 \
    in = s->in;                    \
    in_end = s->in_end;            \
    window = s->window;            \
    w = s->wpos;                   \
    out = s->out;                  \
    out_end = s->out_end

/* drop n bits, then refill a word when the buffer ran dry */
#define DUMPBITS(n)                \
    k -= (n);                      \
    b >>= (n);                     \
    if (k < 0) {                   \
        k += 32;                   \
        if (in == in_end) {        \
            SAVE();                \
            s->refill();               \
            LOAD();                \
        }                          \
        b |= (u64)*in++ << k;      \
    }

#define PUTBYTE(c)                 \
    *out++ = (c);                  \
    if (out == out_end) {          \
        SAVE();                    \
        s->flush();                   \
        LOAD();                    \
    }

extern "C" void func_00573360(InflateStream *s)
{
    u64 b;
    int k;
    u32 *in;
    u32 *in_end;
    u8 *window;
    int w;
    u8 *out;
    u8 *out_end;
    Huft *t;
    Huft *td;
    u32 e;
    u32 n;
    int ml;
    int md;
    int idx;

    /* the table bit counts are replaced by their masks */
    ml = s->bl;
    md = s->bd;
    ml = (1 << ml) - 1;
    md = (1 << md) - 1;
    s->bl = ml;
    s->bd = md;
    LOAD();
    Huft *tl = s->tl;
    td = s->td;

    for (;;) {
        t = tl;
        idx = ml & (int)b;
        for (;;) {
            t += idx;
            e = t->e;
            DUMPBITS(t->b);
            /* idx goes from the sub-table's bit count to its mask to the index */
            idx = e - 16;
            if (e <= 16)
                break;
            idx = 1 << idx;
            idx -= 1;
            idx &= (int)b;
            t = t->next;
        }
        n = t->n;
        /* the mask of the e extra bits, built ahead of the literal and end tests */
        u32 top = 1 << e;
        if (e == 16) {
            *out++ = n;
            if (window != 0) {
                window[w] = n;
                w = (w + 1) & WMASK;
            }
            if (out == out_end) {
                SAVE();
                s->flush();
                LOAD();
            }
            continue;
        }
        u32 mask = top - 1;
        if (e == 15)
            break;
        n += mask & (int)b;
        DUMPBITS(e);

        t = td;
        idx = md & (int)b;
        for (;;) {
            t += idx;
            e = t->e;
            DUMPBITS(t->b);
            /* idx goes from the sub-table's bit count to its mask to the index */
            idx = e - 16;
            if (e <= 16)
                break;
            idx = 1 << idx;
            idx -= 1;
            idx &= (int)b;
            t = t->next;
        }
        u32 d = t->n + ((int)b & ((1 << e) - 1));
        DUMPBITS(e);

        if (window != 0) {
            do {
                u8 c = window[(w - d) & WMASK];
                u8 *dst = &window[w];
                w = (w + 1) & WMASK;
                *out++ = c;
                *dst = c;
                if (out == out_end) {
                    SAVE();
                    s->flush();
                    LOAD();
                }
            } while (--n);
        } else {
            u8 *src = out - d;
            u8 *end = src + n;
            do {
                PUTBYTE(*src++);
            } while (src != end);
        }
    }
    SAVE();
}
