/* compiler: ee-gcc2.96-nogcse */
/* Late adjustment of one simulated item after a step of length dt (shape inferred from the caller func_0045BB60). It acts only when
 * func_003451B8 accepts the object at +0x450, when |f3C4| and |f3C8| are below 1.0, dt < 0.1 and the item is 'busy': any of the
 * words at +0x3F4, +0x3F8, +0x43C is set, or one of 8 per-slot records (stride 0x44 / 0x2C) has a flag. Then f3D0 gains
 * func_00344680(obj, 0) * 20 * f4DC and func_0045C5A8 is called. The inline abs.s is how the original takes the absolute values.
 * The meaning of the fields is unknown. */
struct Elem {
    char pad1[0x3C4];
    float f3C4, f3C8, pad3CC, f3D0;
    char pad2[0x3F4 - 0x3D4];
    int f3F4, f3F8;
    char pad3[0x43C - 0x3FC];
    int f43C;
    char pad4[0x450 - 0x440];
    char *f450;
    char pad5[0x4DC - 0x454];
    float f4DC;
};
extern "C" int func_003451B8(char *);
extern "C" float func_00344680(char *, unsigned char *);
extern "C" void func_0045C5A8(Elem *) throw();
static inline float abs_(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" void func_0045CA60(Elem *item, float dt)
{
    if (func_003451B8(item->f450)) {
        int busy = ((item->f3F8 != 0) | (item->f3F4 != 0) | item->f43C) != 0;
        if (!busy) {
            int slot = 0;
            char *flagsBase = (char *)item + 8;
            char *wordBase = (char *)item + 0xC;
            int *wordB = (int *)((char *)item + 0x248);
            int *wordA = (int *)((char *)item + 0x244);
            int slotOffset = 0x20;
            do {
                if ((*(int *)(flagsBase + slotOffset) & 1) || *(int *)(wordBase + slotOffset) || *wordA || *wordB) { busy = 1; break; }
                slotOffset += 0x44;
                wordA = (int *)((char *)wordA + 0x2C);
                wordB = (int *)((char *)wordB + 0x2C);
                slot++;
            } while (slot < 8);
        }
        float one = 1.0f;
        if (abs_(item->f3C4) < one && abs_(item->f3C8) < one && dt < 0.1f && busy) {
            item->f3D0 += func_00344680(item->f450, 0) * 20.0f * item->f4DC;
            func_0045C5A8(item);
        }
    }
}
