struct Self { char p0[0x554]; int f554; };

extern "C" {
int func_00612A68(int a0, void *a1, int a2);
void func_00567A50(void *a0, void *a1, int a2);
void func_00567D30(int a0, void *a1, int a2);
}

extern "C" int func_00567920(struct Self *self, int arg1, int arg2) {
    char *s3;
    char *s1;
    char buf[2];
    int s0;
    s3 = (char *)self + 0x530;
    func_00612A68(arg1, buf, 2);
    s1 = (char *)self + 0x30;
    s0 = (buf[1] << 8) | buf[0];
    func_00612A68(arg1, s1, s0);
    func_00567A50(s3, s1, s0);
    func_00567D30(self->f554, s3, arg2);
    return s0 + 2;
}
