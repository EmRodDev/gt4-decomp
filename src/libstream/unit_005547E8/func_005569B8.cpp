/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Out {
    int mode;
    int state;
    int mode2;
    int pad0C;
    int a, b, c;
    short s1C, s1E;
    short s20, s22, s24, s26, s28, s2A, s2C;
};
extern "C" int func_005B72A8();
extern "C" int func_005B72F8();
#define DEC(p, i) (((p)[i] << 2) | ((p)[(i) + 1] << 9))
extern "C" void func_005569B8(Out *o, const u8 *in) {
    func_005B72A8();
    int mode = o->mode;
    o->state = 2;
    o->a = (short)DEC(in, 0);
    o->b = (short)DEC(in, 2);
    o->c = (short)DEC(in, 4);
    switch (mode) {
    case 0:
        o->mode2 = 0;
        *(int *)&o->s24 = (short)DEC(in, 6);
        *(int *)&o->s20 = (short)DEC(in, 8);
        *(int *)&o->s1C = (short)DEC(in, 10);
        break;
    case 1:
        o->mode2 = mode;
        o->s1C = DEC(in, 6);
        o->s22 = DEC(in, 8);
        o->s28 = DEC(in, 10);
        o->s1E = DEC(in, 12);
        o->s24 = DEC(in, 14);
        o->s2A = DEC(in, 16);
        o->s20 = DEC(in, 18);
        o->s26 = DEC(in, 20);
        o->s2C = DEC(in, 22);
        break;
    }
    func_005B72F8();
}
