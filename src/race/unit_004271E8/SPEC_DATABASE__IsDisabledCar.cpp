/* compiler: ee-gcc2.96-nsa-nosib */
struct Global { char unknown[0x39E7C]; int zone; };
extern Global *D_00622F4C;
extern void *D_00623790;
extern "C" int SPEC_DATABASE__GameZoneToDisableCondition(int);
extern "C" unsigned long SPEC_DATABASE__DisabledInfo__searchInfo(unsigned long, int);
extern "C" int func_0044A5A8(void *, int, int);
static inline unsigned long converted(unsigned long code,int kind) { if((int)(code>>32)==kind)code=SPEC_DATABASE__DisabledInfo__searchInfo(code,kind);return code; }
extern "C" int SPEC_DATABASE__IsDisabledCar(unsigned long identifier) {
    int condition = SPEC_DATABASE__GameZoneToDisableCondition(D_00622F4C->zone);
    if (condition == 0) return condition;
    unsigned long normalized=converted(identifier,0x26);
    int number=(int)(normalized & 0xFFFFFFFF);
    return func_0044A5A8(D_00623790, number, condition);
}
