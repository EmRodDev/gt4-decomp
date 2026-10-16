typedef int I128 __attribute__((mode(TI)));
struct Section { char p0[0x10]; I128 *e10; char p14[4]; I128 *entries; char p1c[4];
  I128 &get(int i) { return entries[i]; } };
struct Runway { char p0[0x5C]; I128 *entries; char p60[0x3C]; Section *sections;
  I128 &get(int i) { return entries[i]; }
  Section &section(int i) { return sections[i]; } };
struct Obj { int p0; int course; char p8[0xA8]; int section; };
extern "C" Runway *CourseData__getRunway(int);
extern "C" I128 func_003952C0(Obj *self, int idx) {
    if (self->section < 0) {
        return CourseData__getRunway(self->course)->get(idx);
    }
    return CourseData__getRunway(self->course)->section(self->section).get(idx);
}
