/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct M3 { u128 rows[3]; };
struct Basis { u128 pos; M3 mat; };
struct Src { u128 pos; char mat[0x40]; u128 vector; };
extern "C" void *func_00421C58(M3 *, void *);
extern "C" int func_004187A0(void *, Basis *, void *);
extern "C" void *func_005FFD18(void *out, Src *src) {
    Basis tmp;
    tmp.pos = src->pos;
    func_00421C58(&tmp.mat, src->mat);
    func_004187A0(out, &tmp, &src->vector);
    return out;
}
