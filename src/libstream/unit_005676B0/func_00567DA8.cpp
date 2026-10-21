/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char pad[0x38]; int value; };
struct Obj { int m0, m4; char pad[0x1c]; Entry *entry[1]; };
extern char D_006C96B0[];
extern "C" void func_00567F50(const char *, int);
extern "C" int func_00567DA8(Obj *o, int mode, int *value) {
    switch (mode) {
    default:
        func_00567F50(D_006C96B0, mode);
        return -1;
    case 0:
        *value = o->m0;
        break;
    case 1:
        if (*value == 0) *value = 5;
        else {
            Entry *p = o->entry[*value];
            if (!p) *value = -1;
            else *value = p->value;
        }
        break;
    }
    return 0;
}
