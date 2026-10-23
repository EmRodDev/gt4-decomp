/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void AutomaticFader__fadeout(void *, float);
extern "C" void func_003B76F0(void *, int, int, int);
extern "C" void RaceLicenseDisplay__virtual_35(char *self, char *race) {
    int type = *(int *)(self + 0x20);
    switch (type) {
    case 0: break;
    case 2: func_003B76F0((race + 0xF4), 0x18, 0x14, 0); break;
    default: break;
    }
    func_003B76F0((race + 0xF4), 8, 0, 0);
    AutomaticFader__fadeout(self + 0xBC, 0.25f);
}
