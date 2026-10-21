/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Stores three values into entry 'index' (0..3 only) of the 0x38-byte records starting at +0x94: valueA at +0x18, valueB at +0x20 and
 * valueB - valueC at +0x1C, then forwards all of them to func_00458A30 on the owner object. Meaning of the entries unknown. */
struct Obj;

struct func_00450F50_elem {
    char pad0[0x18];
    float unk18;
    float unk1C;
    float unk20;
};

extern "C" void func_00458A30(Obj *o, int flags, float a, float b, float c);

extern "C" void func_00450F50(int *self, unsigned int index, float valueA, float valueB, float valueC)
{
    char *entryBytes;

    entryBytes = (char *)self + index * 0x38 + 0x94;
    if (index < 4U) {
        struct func_00450F50_elem *e = (struct func_00450F50_elem *)entryBytes;
        float difference = valueB - valueC;
        e->unk18 = valueA;
        e->unk20 = valueB;
        e->unk1C = difference;
        func_00458A30((Obj *)*self, index, valueA, valueB, valueC);
    }
}
