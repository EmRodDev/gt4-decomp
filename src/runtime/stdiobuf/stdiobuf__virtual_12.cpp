struct FILE { unsigned char *p; int r; };
struct Buf { char pad[0x58]; FILE *fp; };
extern "C" int func_005A5820(FILE *fp) throw();
extern "C" unsigned int func_005A3998(char *buf, unsigned int size, unsigned int n, FILE *fp) throw();

extern "C" unsigned long stdiobuf__virtual_12(Buf *self, char *buf, long n) {
    if (n == 1) {
        FILE *fp = self->fp;
        int c;
        if (--fp->r < 0)
            c = func_005A5820(fp);
        else
            c = *fp->p++;
        if (c == -1)
            return 0;
        *buf = c;
        return 1;
    }
    return func_005A3998(buf, 1, n, self->fp);
}
