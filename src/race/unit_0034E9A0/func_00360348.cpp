struct Info {
    char pad0[0x94];
    unsigned mask;
    unsigned flags98;
};

struct Hold {
    int pad0;
    void *h;
};

struct Obj {
    char pad0[0xCBD8];
    Hold *hold;
    char padCBDC[0xCBF0 - 0xCBDC];
    unsigned out;
};

extern "C" Info *CourseData__getRunway(void *);

static inline bool is_clear(int masked) { return !__builtin_expect(masked, 0); }
extern "C" void func_00360348(Obj *o) {
    unsigned flags = 0;
    int i;
    unsigned t3 = CourseData__getRunway(o->hold->h)->flags98 & 2;
    bool s3 = t3 != 0;
    for (i = 0; i < 24; i++) {
        Info *info = CourseData__getRunway(o->hold->h);
        int bit = 1 << i;
        int masked = info->mask & bit;
        if (is_clear(masked)) continue;
        if (!((unsigned)i < 15)) continue;
        {
            {
                switch (i) {
                case 0:
                case 7:
                case 8:
                case 9:
                case 12:
                    flags |= 3;
                    if (!s3) break;
                case 6:
                    flags |= 4;
                    break;
                case 1:
                    flags |= 0x10;
                    break;
                case 2:
                case 3:
                case 4:
                    flags |= 0x20;
                    break;
                case 5:
                    flags |= 8;
                    break;
                case 10:
                    flags |= 0x40;
                    break;
                case 11:
                    flags |= 0x81;
                    break;
                case 13:
                    flags |= 0x200;
                    break;
                case 14:
                    flags |= 0x400;
                    break;
                }
            }
        }
    }
    o->out = flags;
}
