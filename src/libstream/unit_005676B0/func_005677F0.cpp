struct Self { char p0[0x554]; int f554; int f558; };
extern char D_00689D10[];
extern char D_006C9658[];

extern "C" {
void func_005679C8(void *p, int v);
int func_00567C98(void *p);
int func_00567D80(void *s, int request, void *value);
}

extern "C" void func_005677F0(struct Self *self, int a1) {
    int arr[2];
    int t;
    self->f558 = (int)D_00689D10;
    arr[0] = 0;
    arr[1] = 0;
    func_005679C8((char *)self + 0x530, a1);
    arr[1] = 1;
    t = func_00567C98(D_006C9658);
    self->f554 = t;
    func_00567D80((void *)t, 3, arr);
    func_00567D80((void *)self->f554, 0, &arr[1]);
}
