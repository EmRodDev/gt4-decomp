/* Runs func_003F9D00 on the block at +0x1098 of the object linked at +0x10, then func_003F9870 on the same block with a
 * flag that is 1 when the float at +0x104+0x490 is below 0.1 and 0 otherwise. Returns that result. Meaning unknown. */
struct Obj { char p0[0x10]; char *f10; char p14[0x104 - 0x14]; };
struct Sub { char p0[0x490]; float f490; };
extern "C" int func_003F9870(Obj *self, char *p, int flag);
extern "C" void func_003F9D00(Obj *self, char *p);

extern "C" int func_003F77B8(Obj *self) {
    char *block = self->f10 + 0x1098;
    Sub *state = (Sub *)((char *)self + 0x104);
    func_003F9D00(self, block);
    int belowLimit = 1;
    if (!(state->f490 < 0.1f)) {
        belowLimit = 0;
    }
    return func_003F9870(self, block, belowLimit);
}
