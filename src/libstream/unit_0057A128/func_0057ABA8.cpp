/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned D_00874D54;
extern unsigned D_00874D58;
extern "C" int func_0057A058(int) throw();

/* A four-character tag built from translated characters, stored inverted. */
static inline void initTag(unsigned *self, int c0, int c1, int c2, int c3)
{
    unsigned a = func_0057A058(c0);
    unsigned b = func_0057A058(c1);
    unsigned c = func_0057A058(c2);
    unsigned d = func_0057A058(c3);
    *self = ~((a | (c << 16)) | ((b << 24) | (d << 8)));
}

/* Static initialisation of this unit's two tag words (__static_initialization_and_destruction_0). */
extern "C" void func_0057ABA8(int init, int prio)
{
    if (prio == 0xFFFF && init == 1)
        initTag(&D_00874D54, 'R', 'c', 'O', 'L');
    if (prio == 0xFFFF && init == 1)
        initTag(&D_00874D58, 'S', 'B', 'M', 'Y');
}