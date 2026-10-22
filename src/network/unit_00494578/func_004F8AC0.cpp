/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef int s32;
struct E { s32 f0, f4, f8, fC; };
struct Obj { E entries[32]; s32 n; s32 key; E *func_004F8AC0(s32) __asm__("func_004F8AC0"); };
E *Obj::func_004F8AC0(s32 key) {
    Obj *obj = this;
    E *e;
    s32 k = obj->key;
    if (key != -1) {
        e = obj->entries;
        if (k != -1) {
            E *end = obj->entries + obj->n;
                for (; e != end; e++) {
                if (e->f4 == key && e->f8 == k) return e;
            }
        }
    }
    return 0;
}
