/* compiler: ee-gcc2.96-nogcse */
/* Script engine glue (strobe::Any): turns a source value into a freshly allocated map value in 'result' (type 7). A type 13 source is
 * copied through func_0047A5D8; a type 15 source is expanded into 'count' entries keyed by a formatted index string; anything else
 * only notifies the owner. The shape (separate string copy register, no hoisted refcount) is what the original compiler produced. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};
struct Str {
    char *p;
};
struct Val {
    s32 type;
    s32 v;
};
struct Node {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s8 unkC;
    char padD[0x3];
    s32 unk10;
    char pad14[0x4];
    Val val;
};
struct Obj5 {
    char pad[0x164];
    void *unk164;
};
struct Obj3 {
    char pad[8];
    s32 unk8;
};

extern char D_00659E20[];
extern char D_006AD5B0[];

extern "C" void func_004768C0(Val *) throw();
extern "C" void func_00476768(Val *, Val *) throw();
extern "C" void *func_00476790(void *, void *) throw();
extern "C" void func_004767E8(Val *) throw();
extern "C" s32 func_00477298(Val *);
extern "C" s32 func_0047A858(s32);
extern "C" void func_00480F78(void *);
extern "C" void func_00480FA0(void *, s32);
extern "C" void *func_004812C8(void *, Str *);
extern "C" void free(void *) throw();
extern "C" s32 func_00575E60(s32, s32);
extern "C" s32 func_0057DA20(char *, const char *, ...);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" s32 exception__structor_0(s32);
extern "C" char *strobe__toUpper(void *);
extern "C" void *strobe__Any__setMember(void *, u32, u32, const char *, u32);

struct StrT {
    char *p;
    char pad[0xC];
};

extern "C" void func_0047A5D8(s32 *, s32, s32, Val *, u32, s32, void *);

extern "C" void func_00476D40(Val *result, Val *source, s32 extra2, u32 count, s32 extra4, Obj5 *owner) {
    char buf[16];
    s32 tmp[4];
    StrT str;
    struct ByteTag { s8 value; } b1;
    void *scriptCtx = owner->unk164;
    s32 type = 7;
    func_004768C0(result);
    result->type = type;
    s32 mapObject = exception__structor_0(0x20);
    Node *mapNode = (Node *)(mapObject + 4);
    *(s32 *)mapObject = 0;
    b1.value = 0;
    u8 *tagPtr = (u8 *)&b1;
    mapNode->unk4 = 0;
    s32 nodeHeader = func_00575E60(0x10, 0x1c);
    mapNode->unk8 = 0;
    mapNode->unk4 = nodeHeader;
    mapNode->unkC = *tagPtr;
    *(s32 *)nodeHeader = 0;
    *(s32 *)(mapNode->unk4 + 4) = 0;
    *(s32 *)(mapNode->unk4 + 8) = mapNode->unk4;
    *(s32 *)(mapNode->unk4 + 0xc) = mapNode->unk4;
    mapNode->unk10 = 0;
    Val *valueSlot = (Val *)(mapObject + 0x18);
    func_00476768(valueSlot, source);
    func_004767E8(valueSlot);
    if ((source->type ^ 13) == 0) {
        mapNode->unk10 = func_0047A858(func_00477298(valueSlot));
    }
    result->v = mapObject;
    switch (source->type) {
    case 13: {
        s32 *pt = tmp;
        s32 value = func_00477298(source);
        func_0047A5D8(pt, value, extra2, result, count, extra4, owner);
        func_004768C0((Val *)pt);
        break;
    }
    case 15: {
        u32 i = 0;
        if (count != 0) {
            StrT *pk = &str;
            do {
                func_0057DA20(buf, D_006AD5B0, i);
                void *m = (void *)(result->v + 4);
                StrT *ps = &str;
                char *src = buf;
                Rep *g = (Rep *)D_00659E20;
                char *r;
                if (g->sel != 0) {
                    r = strobe__toUpper(g);
                } else {
                    r = (char *)g + 0x10;
                    g->ref++;
                }
                ps->p = r;
                strobe__Any__setMember(ps, 0, (u32)-1, src, func_0057F260(src));
                void *v = func_004812C8(m, (Str *)pk);
                func_00476790(v, (void *)(((Obj3 *)scriptCtx)->unk8 - 8));
                Rep *q = (Rep *)(pk->p - 0x10);
                if (--q->ref == 0) free(q);
                func_00480F78(scriptCtx);
                i++;
            } while (i < count);
        }
        break;
    }
    default:
        func_00480FA0(scriptCtx, count);
        break;
    }
}
