/* compiler: ee-gcc2.96-as2004g */
typedef unsigned long U64;
typedef U64 Unaligned64 __attribute__((aligned(4)));
typedef struct Obj { char pad[0x9c]; unsigned short count; } Obj;
typedef struct Key { volatile Unaligned64 a, b; int pad10, value; } Key;
typedef struct Ops { char pad[0x74]; int (*compare)(U64,U64); } Ops;
extern Ops *D_0064B4B0;
void func_00523C20(Obj *,unsigned short,int,U64 *,int *);
int func_00525EC0(Obj *obj, Key *key, unsigned short *out) {
    volatile U64 value[2];
    int tag;
    unsigned short i;
    *out = -2;
    if (!obj) return 2;
    for (i = 0; i < obj->count; i++) {
        int found = 0;
        func_00523C20(obj,i,0,value,&tag);
        D_0064B4B0->compare(value[0],key->a);
        func_00523C20(obj,i,1,value,&tag);
        if (D_0064B4B0->compare(value[0],key->b)) found = tag == key->value;
        if (found) { *out = i; break; }
    }
    return 0;
}
