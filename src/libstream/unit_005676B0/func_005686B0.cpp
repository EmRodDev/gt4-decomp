struct S { char pad0[8]; int mode; char pad1[0x24]; int first[2][2], second[2][2]; int timing[2][2]; };
extern "C" int func_00563158(int);
extern "C" void func_005687A0(S *, int *, int, int);
extern "C" int func_005686B0(S *self, int i, int a, int b) {
    if (self->mode == 1) {
        func_005687A0(self, self->first[i], a, b);
        self->second[i][0] = self->first[i][0];
        self->second[i][1] = self->first[i][1];
    } else {
        self->timing[0][i] = func_00563158(1);
        func_005687A0(self, self->first[i], a, b);
        self->timing[1][i] = func_00563158(1);
        func_005687A0(self, self->second[i], a, b);
    }
    return 0;
}
