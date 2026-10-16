/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Out { unsigned short value; unsigned short zero; };
extern char *D_00634EF0[];
extern unsigned short *D_00634F10[];
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_004B9098(Out *out, int ch, int mode) {
    char **cursor = D_00634EF0;
    for (int i = 0; i < 7; i++, cursor++) {
        char *s = *cursor;
        int n = func_0057F260(s);
        if (ch >= s[0] && ch <= s[n - 1]) {
            int j = 0;
            if (n > 0) {
                do {
                if (s[j] == ch) {
                    int index = i;
                    if (mode) index = i + 7;
                    unsigned short v = D_00634F10[index][j];
                    out->zero = 0;
                    out->value = v;
                    return 1;
                }
                j++;
                } while (j < n);
            }
        }
    }
    return 0;
}
