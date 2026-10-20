#include "types.h"
extern char D_006CC598[];
extern "C" s32 func_0057F260(const char *s);
extern "C" s32 func_00594470(const char *a, const char *b, s32 n);

extern "C" void func_00577AF0(char *arg0) {
    char *s;
    char *end;
    char c;

    if (func_00594470(arg0, D_006CC598, 5) != 0) {
        return;
    }
    s = arg0 + 5;
    if (s[1] == ':') {
        s = arg0 + 6;
    }
    if (*s != ':') {
        return;
    }
    end = s + func_0057F260(s);
    if (end[-2] != ';') {
        return;
    }
    if (end[-1] != '1') {
        return;
    }
    end -= 2;
    while (s < end) {
        c = *s;
        if ((unsigned char)(c - 'a') < 26) {
            *s = c - 0x20;
        } else if (c == '/') {
            *s = '\\';
        }
        s++;
    }
}
