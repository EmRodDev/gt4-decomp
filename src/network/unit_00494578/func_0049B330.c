/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct V { unsigned x, y, z; } V;
int func_0049B2C8(unsigned long, unsigned long, unsigned long);
void func_0049E3E0(void);
#define CLIP(p, q, r) do { bits &= func_0049B2C8((p)->x, (q)->y, (r)->z); if (!bits) return 1; } while (0)
int func_0049B330(V *a, V *b) {
    int bits = 0x3f;
    func_0049E3E0();
    CLIP(a, a, a);
    CLIP(b, b, b);
    CLIP(a, a, b);
    CLIP(b, b, a);
    CLIP(a, b, a);
    CLIP(b, a, b);
    CLIP(a, b, b);
    bits &= func_0049B2C8(b->x, a->y, a->z);
    return bits == 0;
}
