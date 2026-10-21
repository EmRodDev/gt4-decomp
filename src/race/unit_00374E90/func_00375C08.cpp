/* Hands one 0x19C-byte slot of the object (array at +0x10, chosen by idx) to the handler object stored in that slot at +0x168: a virtual call
 * (vtable +0xD8, a part) supplies a placement that is turned into two 3-float vectors by 0036EF28 and 005F5040 plus the float at part+0xC;
 * 003FFD10 and 003FFA20 are run on the block at +0xC04 with them; the handler's virtual method at +0x138 then receives the slot, a value from
 * source+0x80, the 003FFA20 result and the quotient of the floats at +0x9D4 and +0x9C0; finally the handler is recorded in the slot at
 * +0x12C. What the slot represents is purpose unknown (the callees carry no recovered names). */
struct Entry { short delta, index; char *(*fn)(void *, int); };
struct Entry4 { short delta, index; void (*fn)(void *, char *, int, int, float); };
struct Obj { char *vtbl; char pad[0x9C0 - 4]; float f9C0; char pad2[0x9D4 - 0x9C4]; float f9D4; };
struct Tg { char *vtbl; };
struct Loc { float pad[8]; float a[3]; float b[3]; float c; };
extern "C" void func_0036EF28(char *, float *) throw();
extern "C" void func_005F5040(char *, float *);
extern "C" void func_003FFD10(char *, char *, char *, char *, float *);
extern "C" int func_003FFA20(char *);
extern "C" void func_00375C08(Obj *self, char *source, int idx) {
    Loc placement;
    float *posA = placement.a;
    float *posB = placement.b;
    char *block = (char *)self + 0xC04;
    char *slot = (char *)self + idx * 0x19C + 0x10;
    Entry *partEntry = (Entry *)(self->vtbl + 0xD8);
    char *part = partEntry->fn((char *)self + partEntry->delta, 0);
    Tg *handler;
    func_0036EF28(part + 0x100, posB);
    func_005F5040(part + 0x10, posA);
    placement.c = *(float *)(part + 0xC);
    func_003FFD10(block, source, slot, (char *)self + 4, posA);
    handler = *(Tg **)(slot + 0x168);
    int sourceValue = *(int *)(source + 0x80);
    int resultCode = func_003FFA20(block);
    float ratio = self->f9D4 / self->f9C0;
    Entry4 *handlerEntry = (Entry4 *)(handler->vtbl + 0x138);
    handlerEntry->fn((char *)handler + handlerEntry->delta, slot, sourceValue, resultCode, ratio);
    *(Tg **)(slot + 0x12C) = handler;
}
