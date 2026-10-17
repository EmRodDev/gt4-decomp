/* compiler: ee-gcc2.96-as2004g */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long T __attribute__((aligned(4)));
struct Entry { int type; char pad4[4]; T key; int kind; char pad14[0x5a]; u16 id; int code; char rest[0x428]; };
struct Obj { int pad0; Entry *base; char pad8[0x48]; u32 count; };
struct Key { unsigned int a,b; };
struct Ops { char pad[0x74]; int (*compare)(unsigned long long,T); };
extern Ops *D_0064B4B0;
extern "C" Entry *func_0052CAE0(Obj *o, u16 *id, Key key, int kind) {
    Entry *fallback=0;
    if (!o) return 0;
    if (!(*id&0x3ff)) return 0;
    Entry *p=o->base;
    for (u32 i=0; i<o->count; i++,p++) {
        if (p->type) {
            T value=p->key;
            if (D_0064B4B0->compare(*(volatile unsigned long long *)&key,value) && kind == p->kind) {
                int n=*id&0x3ff;
                u16 old=p->id;
                if (n == old) return p;
                if (n == p->code) return p;
                if ((u32)(p->type-9)<2 && (!n || !old)) fallback=p;
            }
        }
    }
    return fallback;
}
