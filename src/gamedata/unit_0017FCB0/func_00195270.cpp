struct Entry { short delta; short index; char *(*fn)(void *); };
struct Obj { char pad[0x64]; Entry *vt; };
extern "C" Obj *func_00192E20(void *);
extern "C" void func_00370DB0(void *, void *);
extern "C" int func_00370D70(void *);
extern "C" int func_00195270(void *, void *arg1, void *arg2) {
    Obj *o = func_00192E20(arg1);
    Entry *e = (Entry *)((char *)o->vt + 0x4B0);
    char *p = e->fn((char *)o + e->delta) + 0xE28;
    func_00370DB0(p, arg2);
    return func_00370D70(p);
}
