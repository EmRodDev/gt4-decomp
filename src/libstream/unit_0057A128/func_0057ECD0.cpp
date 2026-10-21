extern double D_006CCBD8[];
extern double D_00655D90;
extern "C" int *func_005A3130();
#define SPACE(c) (((unsigned char *)0x006D0E79)[c] & 8)
#define DIGIT(c) (((unsigned char *)0x006D0E79)[c] & 4)
extern "C" double func_0057ECD0(char *str, char **endptr) {
    char *s = str;
    double *powers = D_006CCBD8;
    int negative;
    char *ip, *fp, *ep, *p;
    int ni, nf, exponent, eneg, count;
    unsigned long value;
    double result;
    while (SPACE(*s)) s++;
    negative = 0;
    switch (*s) {
    case 0: goto invalid;
    case '-': negative = 1;
    case '+': s++;
    }
    ip = s;
    while (DIGIT(*s)) s++;
    ni = s - ip;
    if (*s == '.') s++;
    fp = s;
    while (DIGIT(*s)) s++;
    nf = s - fp;
    if (ip == s || (ni == 0 && nf == 0)) goto invalid;
    exponent = 0;
    if (*s == 'E' || *s == 'e') {
        s++;
        eneg = 0;
        switch (*s) {
        case '-': eneg = 1;
        case '+': s++;
        }
        ep = s;
        while (DIGIT(*s)) s++;
        if (ep == s) goto invalid;
        while (*ep == '0') ep++;
        if (s - ep >= 10) goto overflow;
        while (ep != s) exponent = exponent * 10 + *ep++ - '0';
        if (eneg) exponent = -exponent;
    }
    p = ip;
    while (*ip == '0') ip++;
    ni -= ip - p;
    exponent += ni - 1;
    if (!ni) {
        p = fp;
        while (*fp == '0') fp++;
        count = fp - p;
        nf -= count;
        exponent -= count;
        if (!nf) goto zero;
    }
    if (ni >= 20) ni = 19;
    p = ip + ni;
    value = 0;
    while (ip != p) value = value * 10 + (*ip++ - '0');
    count = 19 - ni;
    if (nf > count) nf = count;
    p = fp + nf;
    while (fp != p) value = value * 10 + (*fp++ - '0');
    count = exponent - (ni + nf) + 325;
    if (count < 0) goto underflow;
    if (count >= 633) goto overflow;
    result = powers[count] * (double)value;
    if (result == 0.0) goto underflow;
    if (result == D_00655D90) goto overflow;
    if (endptr) *endptr = s;
    return negative ? -result : result;
invalid:
    if (endptr) *endptr = str;
    return 0.0;
underflow:
    *func_005A3130() = 34;
zero:
    if (endptr) *endptr = s;
    return 0.0;
overflow:
    *func_005A3130() = 34;
    if (endptr) *endptr = s;
    return negative ? -D_00655D90 : D_00655D90;
}
