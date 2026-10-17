/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Reader {
    char pad0[0x5C];
    int source;
    int pad60;
    int chunkSize;
    unsigned char input[0x128 - 0x68];
    char output[0x140 - 0x128];
    char *writePos;
};

extern "C" {
extern char D_00655290[];
int func_00566FF8(void *, int, void *, int);
void func_005569B8(Reader *, char *);

void func_005568C0(Reader *r)
{
    int bytes;
    unsigned char *buffer = r->input;
    unsigned char *in = buffer;
    while ((bytes = func_00566FF8(D_00655290, r->source, buffer, r->chunkSize << 3)) != 0) {
        if (bytes > 0) {
            int count = bytes;
            char *output = r->output;
            char **writePos = &r->writePos;
            do {
                unsigned char c = *in;
                if ((c & 0x80) || r->chunkSize < (r->writePos - (char *)r) - 0x128) {
                    func_005569B8(r, output);
                    r->writePos = output;
                    c = *in;
                }
                *(*writePos)++ = c & 0x7F;
                in++;
            } while (--count);
        }
    }
}
}
