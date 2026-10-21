/* compiler: ee-gcc2.96-exceptions-as2004 */
typedef unsigned long long T __attribute__((aligned(4)));
struct Blob { T value; };
struct Vt { char p0[0x40]; int (*get)(Blob *); char p44[0x70-0x44]; int (*test)(T); };
extern char D_00868698[];
extern Vt *D_0064B4B0;
extern "C" int func_00535780(unsigned int);
extern "C" int func_00530F98(Blob *out) {
    char *v = D_00868698;
    Blob *src = (Blob *)(v + 0x14);
    *out = *src;
    if (D_0064B4B0->test(out->value) != 0) {
        int r = func_00535780(D_0064B4B0->get(out));
        if (r != 0) return r;
        *src = *out;
    }
    return 0;
}
