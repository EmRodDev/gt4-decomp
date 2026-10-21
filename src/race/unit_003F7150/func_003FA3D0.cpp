/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Car { char p[0x5B2]; unsigned char f5B2; };
extern "C" Car *func_0034C190(int, int);
extern "C" int Automobile__GetExplicitCurrentLap(Car *);

extern "C" int func_003FA3D0(char *base, int i, unsigned char j, unsigned short *out1, int *out2)
{
    Car *c = func_0034C190((int)base, i);
    int n = Automobile__GetExplicitCurrentLap(c) - (j >= c->f5B2);
    int k = i * 16 + j;
    base += 4;
    unsigned short v = *(unsigned short *)(base + k * 2 + 0xD920);
    *out1 = v;
    *out2 = (short)v == n;
    return *(int *)(base + k * 4 + 0xD7A0);
}
