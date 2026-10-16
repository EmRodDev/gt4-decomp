/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" void func_00576AD8(void *, int);
extern "C" void func_00576B28(void *, int);
extern "C" void func_001C49A0(char *dst, char *src, int width, int height) {
    int size = width * height * 4;
    height >>= 4;
    func_00576B28(src, size);
    char *source = src;
    int stride = width * 4;
    int blockstride = width << 6;
    char *row = dst;
    if (height != 0) {
        do {
            int cols = width >> 4;
            char *block = row;
            char *p = source;
            if (cols != 0) {
                do {
                    char *s = p;
                    char *d = block;
                    char *end = s + 0x400;
                    do {
                        u128 a = ((u128 *)s)[0];
                        u128 b = ((u128 *)s)[1];
                        u128 c = ((u128 *)s)[2];
                        u128 e = ((u128 *)s)[3];
                        s += 0x40;
                        ((u128 *)d)[0] = a;
                        ((u128 *)d)[1] = b;
                        ((u128 *)d)[2] = c;
                        ((u128 *)d)[3] = e;
                        d += stride;
                    } while (s != end);
                    --cols;
                    p = end;
                    block += 0x40;
                } while (cols != 0);
            }
            --height;
            row += blockstride;
            source += blockstride;
        } while (height != 0);
    }
    func_00576AD8(dst, size);
}
