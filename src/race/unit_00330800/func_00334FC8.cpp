/* Serializes a film/effect object into a PMDI+FILM chunk stream in the caller's buffer and returns the number of bytes written. */
struct W { int a; int b; int c; };
struct Ck { int x[4]; };
struct Obj { int f0; int f4; int f8; int fC; int f10; float f14; int f18; char pad[0xFC]; int f118; int pad2; float f120; int f124; char b128[4]; char b12C[4]; char b130[4]; char b134[4]; char b138[4]; char b13C[4]; int f140; char b144[0x20]; };
extern "C" {
void func_0045B4D8(Ck *, W *, const char *);
void func_0045B548(Ck *, W *);
void func_0045AF58(W *, int);
void GT4Model__BinStreamWriter__write8u(W *, int);
void func_0045AFA0(W *, int);
void GT4Model__BinStreamWriter__write8(W *, int);
void GT4Model__BinStreamWriter__writeFloat(W *, float);
void GT4Model__BinStreamWriter__writeArray(W *, char *, int);
void func_0033A2A0(W *, int, int, int);
void func_0033A018(W *, int, int, int, float, int);
}
int func_00334FC8(Obj *o, int base, int size) {
    W w; Ck ck; int n;
    w.b = base + size; w.a = base; w.c = base;
    func_0045B4D8(&ck, &w, "PMDI");
    func_0045AF58(&w, o->f124);
    func_0045B548(&ck, &w);
    func_0045B4D8(&ck, &w, "FILM");
    GT4Model__BinStreamWriter__write8u(&w, 2);
    func_0045AFA0(&w, o->f4);
    func_0045AFA0(&w, o->f8);
    GT4Model__BinStreamWriter__write8(&w, o->fC);
    GT4Model__BinStreamWriter__write8(&w, o->f10);
    GT4Model__BinStreamWriter__writeFloat(&w, o->f14);
    func_0045AF58(&w, o->f18);
    GT4Model__BinStreamWriter__write8(&w, o->f118);
    func_0045AF58(&w, o->f124);
    GT4Model__BinStreamWriter__writeFloat(&w, o->f120);
    GT4Model__BinStreamWriter__writeArray(&w, o->b128, 4);
    GT4Model__BinStreamWriter__writeArray(&w, o->b12C, 4);
    GT4Model__BinStreamWriter__writeArray(&w, o->b130, 4);
    GT4Model__BinStreamWriter__writeArray(&w, o->b134, 4);
    GT4Model__BinStreamWriter__writeArray(&w, o->b138, 4);
    GT4Model__BinStreamWriter__writeArray(&w, o->b13C, 4);
    GT4Model__BinStreamWriter__writeArray(&w, o->b144, 0x20);
    func_0045B548(&ck, &w);
    n = (o->f120 == 0.0f) ? 1 : 2;
    func_0033A2A0(&w, o->f0, n, 0);
    if (n >= 2) func_0033A018(&w, o->f0, 0, 0, 1.0f, 0);
    func_0033A018(&w, o->f0, 1, 1, 0.0f, 1);
    return w.c - w.a;
}
