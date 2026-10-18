typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
struct Obj { u8 *base; s32 pad4, pad8; u8 *table; };
extern "C" s32 func_0057A2B8(s32 key, u8 *entry);
static inline s32 rd16(const u8 *p) { return p[0] | (p[1] << 8); }
static inline s32 rd32(const u8 *p) { return (p[0] | (p[1] << 8) | (p[2] << 16)) | (p[3] << 24); }
extern "C" s32 func_0057A468(struct Obj *o, s32 key, u32 value) {
    u8 *t = o->table;
    if (!t) return 0;
    const u8 *hdr = t + 8;
    const u8 *first = hdr + 2;
    s32 count = rd16(hdr);
    s32 i = 0;
    if (count) {
        const u8 *e = first;
        do {
            s32 off = rd32(e);
            e += 4;
            if (func_0057A2B8(key, o->base + off) == 0) {
                u8 *r = o->base + off - 5;
                r[0] = value;
                r[1] = value >> 8;
                r[2] = value >> 16;
                r[3] = value >> 24;
                return 1;
            }
            i++;
        } while (i < count);
    }
    return 0;
}
