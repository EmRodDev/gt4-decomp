/* compiler: ee-gcc2.96-as2004g */
struct Pair { int lo, hi; };
struct Raw4 { char b[4]; };
union Key { struct Raw4 raw; struct Pair pair; };
int func_00536CF8(void);
int func_00536D38(void);
int func_00535780(int);
int func_00531F40(int, struct Pair, int, int, int, int);

int func_0052EA40(signed char type, struct Raw4 *addr, int a2, int a3, int a4, int a5) {
    union Key key;
    int r;
    int res;
    r = func_00535780(func_00536CF8());
    if (r != 0)
        return r;
    key.raw = *addr;
    res = func_00531F40(type, key.pair, a2, a3, a4, a5);
    r = func_00535780(func_00536D38());
    return r == 0 ? res : r;
}
