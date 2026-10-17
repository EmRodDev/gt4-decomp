/* compiler: ee-gcc2.96-nsa-g */
/* exponent from newlib 1.9.0 libc/stdio/vfprintf.c (BSD licence, see THIRD_PARTY.md):
 * write the exponent suffix (e+NN) of a floating-point conversion; returns its length. */
#define MAXEXP 308
#define to_char(n) ((n) + '0')

int func_005A9BE8(char *p0, int exp, int fmtch)
{
	register char *p, *t;
	char expbuf[MAXEXP];

	p = p0;
	*p++ = fmtch;
	if (exp < 0) {
		exp = -exp;
		*p++ = '-';
	}
	else
		*p++ = '+';
	t = expbuf + MAXEXP;
	if (exp > 9) {
		do {
			*--t = to_char(exp % 10);
		} while ((exp /= 10) > 9);
		*--t = to_char(exp);
		for (; t < expbuf + MAXEXP; *p++ = *t++);
	}
	else {
		*p++ = '0';
		*p++ = to_char(exp);
	}
	return (p - p0);
}
