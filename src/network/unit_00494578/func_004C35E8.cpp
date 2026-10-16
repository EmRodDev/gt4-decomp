/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
struct E { char pad[0x1C]; unsigned *arr; char pad20[8]; u16 *cnt; };
struct Obj { E entries[256]; };
inline unsigned search(Obj *base, unsigned idx, unsigned key, unsigned lo, unsigned hi) {
    while (lo < hi) {
        u16 mid = (int)(lo + hi) / 2;
        if ((base->entries[idx].arr[mid] & 0xFFFFF) < key)
            lo = (u16)(mid + 1);
        else hi = mid;
    }
    return lo;
}
extern "C" unsigned func_004C35E8(Obj *base, u8 idx, unsigned key) {
    u16 hi = *base->entries[idx].cnt;
    return search(base, idx, key, 0, hi);
}
