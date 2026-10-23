/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reset per-car state. Layout offsets remain provisional; +0x68 is the
 * RNG seed (confirmed by func_00463960), +0x78 holds 64 invalidated entries,
 * and +0xE8/+0xEC are borrowed links to the car and its selection data. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
extern "C" unsigned int func_00463960(char *) throw();
extern "C" int func_004639B0(char *) throw();
extern "C" int func_0046BB48(void *, unsigned);
extern "C" int func_00463C00(char *, int);
extern "C" void func_004694A0(char *);
extern "C" void func_00469E48(char *);
extern "C" void *func_005A48D8(void *, int, unsigned short) throw();
extern "C" void func_004639E0(char *self, int index) {
    char *data = FIELD(self,char *,0xe8) + 0x104;
    short seed;
    if (FIELD(data,signed char,0x466) == 2) {
        seed = FIELD(data,unsigned char,0x440) + 1;
        FIELD(self,short,0x68) = seed;
    } else {
        seed = 1;
        FIELD(self,short,0x68) = seed;
    }
    // Advance the seed before invalidating the entry buffer.
    func_00463960(self);
    func_005A48D8(self + 0x78, 0xff, 0x40);
    FIELD(self,char,0x1b) = 0;
    FIELD(self,char,0x6b) = 0;
    float value = FIELD(FIELD(FIELD(self,char *,0xe8),char *,0x10),float,0xfd8);
    FIELD(self,float,0x24) = value;
    FIELD(self,float,0x28) = value;
    int selection;
    if (index == -1) selection = func_004639B0(self);
    else selection = func_0046BB48(FIELD(self,void *,0xec), index);
    func_00463C00(self, func_0046BB48(FIELD(self,void *,0xec), selection));
    FIELD(self,char,0x20) = 0;
    FIELD(self,short,0x22) = 0;
    FIELD(self,char,0x3f) = 0;
    FIELD(self,char,0x52) = 0;
    func_004694A0(self);
    FIELD(self,short,0x18) = 0;
    FIELD(self,char,0x6a) = 0;
    FIELD(self,char,0x51) = -1;
    FIELD(self,char,0x50) = 0;
    func_00469E48(self);
    FIELD(self,char,0x1a) = 0;
}
