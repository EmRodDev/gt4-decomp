/* Camera reset (same object as func_0036FAE8): sets the mode pair to (0, 0x18), re-derives the view with func_00370548 and keeps a
 * backup copy of the current vector and value pair (the same backup func_0036FAE8 makes after initialising; func_00370C68 restores it). */
struct Pair {
    unsigned char a;
    unsigned char b;
    void set(int x, int y) { a = x; b = y; }
};

struct Obj {
    char pad0[0x44];
    Pair mode;
    char pad46[0x3A];
    int arg80;
    char pad84[0x54];
    char mat[0xC];
    float fe4;
    int ie8;
    char vec[0xC];
    float ff8;
    int ifc;
};

extern "C" void func_00370548(Obj *self, void *mat, int arg);
extern "C" void func_005F5040(void *mat, void *vec);

extern "C" void func_00370BE0(Obj *self)
{
    self->mode.set(0, 0x18);
    func_00370548(self, self->mat, self->arg80);
    func_005F5040(self->mat, self->vec);
    self->ff8 = self->fe4;
    self->ifc = self->ie8;
}
