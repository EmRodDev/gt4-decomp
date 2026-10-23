/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; int (*fn)(void *); };
struct Table { char pad0[0x110]; unsigned int cell[1][16]; };
struct Board { char pad0[8]; Table table; };
struct BoardHdr { char pad0[0x10]; char *race; char pad14[0xDC - 0x14]; unsigned char lap[1]; };
extern "C" int func_003FA3D0(char *base, int i, unsigned char j, unsigned short *out1, int *out2);
extern "C" short func_003FA320(char *base, int i, unsigned char *out);

extern "C" void func_003DC7B0(char *self) {
    unsigned short pos;
    int flag;
    char *race = ((BoardHdr *)self)->race;
    int n = *(int *)(race + 0xF8A0);
    Entry *e = (Entry *)(*(char **)(race + 0x10140) + 0x150);
    int rows = e->fn(race + e->delta);
    for (int row = 0; row < rows; row++) {
        Table *t = &((Board *)self)->table;
        for (int car = 0; car < n; car++) {
            unsigned int color = (row & 1) ? 0x80181818 : 0x80282828;
            unsigned int time = func_003FA3D0(((BoardHdr *)self)->race, car, row, &pos, &flag);
            if (time != 0x157529FF) {
                int rank = 0;
                for (int i = 0; i < n; i++)
                    rank += (unsigned int)func_003FA3D0(((BoardHdr *)self)->race, i, row, &pos, &flag) < time;
                float k = (float)rank / (float)(n - 1);
                float inv = 1.0f - k;
                float r = k * 0.0f;
                float g = k * 0.0f;
                k = k * 0.4f;
                r += inv * 1.0f;
                g += inv * 0.2f;
                k += inv * 0.2f;
                color = ((int)(k * 255.0f) << 16) | (int)(r * 255.0f) | ((int)(g * 255.0f) << 8) | 0x80000000;
            }
            t->cell[car][row] = color;
        }
    }
    for (int i = 0; i < n; i++)
        func_003FA320(((BoardHdr *)self)->race, i, &((BoardHdr *)self)->lap[i]);
}
