/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __mulsf3 (config/fp-bit.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef float FLO_type;
typedef unsigned int fractype;
typedef unsigned long long UDItype;

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union {
        fractype ll;
    } fraction;
} fp_number_type;

typedef union {
    FLO_type value;
    fractype value_raw;
} FLO_union_type;

extern void func_005BD9B8(FLO_union_type *src, fp_number_type *dst); /* unpack_d */
extern FLO_type func_005BD900(fp_number_type *src); /* pack_d */

#define IMPLICIT_1 0x40000000
#define IMPLICIT_2 0x80000000
#define FRACHIGH 0x80000000
#define FRACHIGH2 0x80000000
static inline int iszero(fp_number_type *x) { return x->class == CLASS_ZERO; }

static inline fp_number_type *
_fpmul_parts(fp_number_type *a, fp_number_type *b, fp_number_type *tmp)
{
    fractype low = 0;
    fractype high = 0;

    if (iszero(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (iszero(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }
    {
        UDItype answer = (UDItype)a->fraction.ll * (UDItype)b->fraction.ll;
        high = answer >> 32;
        low = answer;
    }
    tmp->normal_exp = a->normal_exp + b->normal_exp + 2;
    tmp->sign = a->sign != b->sign;
    while (high >= IMPLICIT_2) {
        tmp->normal_exp++;
        if (high & 1) {
            low >>= 1;
            low |= FRACHIGH2;
        }
        high >>= 1;
    }
    while (high < IMPLICIT_1) {
        tmp->normal_exp--;
        high <<= 1;
        if (low & FRACHIGH)
            high |= 1;
        low <<= 1;
    }
    tmp->fraction.ll = high;
    tmp->class = CLASS_NUMBER;
    return tmp;
}

FLO_type func_005BDCD8(FLO_type arg_a, FLO_type arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type *res;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;

    func_005BD9B8(&au, &a);
    func_005BD9B8(&bu, &b);

    res = _fpmul_parts(&a, &b, &tmp);

    return func_005BD900(res);
}
