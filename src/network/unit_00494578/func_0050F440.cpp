struct Obj { int pad[3]; int (*get)(Obj *, int *); };
extern Obj *D_0064A550;
extern "C" int func_0050F440() {
    int value;
    Obj *o = D_0064A550;
    if (!o) return -13;
    if (o->get(o, &value)) return 0;
    return value;
}
