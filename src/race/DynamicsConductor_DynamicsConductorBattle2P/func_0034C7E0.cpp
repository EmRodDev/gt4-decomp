/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned long long u64;

struct Course {
    char pad[0x78];
    u64 id;
};

struct Rec {
    char pad[0x10];
    u8 type;
    u8 f11;
    u8 f12;
    u8 f13;
    u8 f14;
    char tail[3];
};

struct Self {
    Course *course;
    char pad[0xCBDD - 4];
    u8 courseType;
    u8 fCBDE;
    u8 fCBDF;
    u8 fCBE0;
    u8 fCBE1;
    char padCBE2[4];
    u8 code[8];
};

extern "C" bool func_00447F48(u64 id, Rec *out);
extern "C" const char *func_00447F08(u64 key);
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" void func_0034C7E0(Self *self) {
    Rec rec;
    Course *course = self->course;
    const u8 *s;
    unsigned int i;

    func_00447F48(course->id, &rec);
    self->courseType = rec.type;
    self->fCBDE = rec.f12;
    self->fCBDF = rec.f13;
    self->fCBE0 = rec.f14 != 0;
    self->fCBE1 = rec.f13 >= 2;
    s = (const u8 *)func_00447F08(course->id);
    func_005A48D8(self->code, 0, 8);
    for (i = 0; i < 8; i++) {
        u8 c = s[i];
        if (c == 0)
            break;
        switch (i) {
        case 0:
        case 3:
            if ((u8)(c - '0') < 10)
                c = c - '0';
            break;
        case 1:
        case 2:
            if ((u8)(c - '0') < 10)
                c = c - '0';
            else if ((u8)(c - 'a') < 6)
                c = c - 'a' + 10;
            else if ((u8)(c - 'A') < 6)
                c = c - 'A' + 10;
            break;
        }
        self->code[i] = c;
    }
}
