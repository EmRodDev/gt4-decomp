struct Obj { char pad[0x164]; int h; };
struct API { char pad[0x14]; int (*getB)(int, unsigned short *); int (*getA)(int, unsigned short *); };
extern API *D_0064B4B8;
extern "C" Obj *func_00535A18(unsigned int) throw();
extern "C" int func_00535F28(Obj *obj, int *out) {
    int invalid = 0xFFFE;
    unsigned short a = invalid, b = invalid;
    if (!out) return 23;
    *out = 0;
    if (!obj) {
        for (int i = 0; i < 4; i++) {
            obj = func_00535A18(i);
            if (obj) {
                if (D_0064B4B8->getA(obj->h, &a)) return 37;
                if (D_0064B4B8->getB(obj->h, &b)) return 37;
                if (b != 0xFFFE && a == b) { *out = 1; break; }
            }
        }
        return 0;
    }
    if (D_0064B4B8->getA(obj->h, &a)) return 37;
    if (D_0064B4B8->getB(obj->h, &b)) return 37;
    if (b != invalid && a == b) *out = 1;
    return 0;
}
