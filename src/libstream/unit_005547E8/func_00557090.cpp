/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int id; char pad[0x280 - 4]; int busy; int enabled; };
extern char D_00655290[];
extern char D_0064D240[];
extern "C" void func_00567018(char *, int, char *, int, int);
extern "C" int func_00557090(Obj *o) {
    if (o->enabled == 0) return 0;
    if (o->busy == 0) {
        func_00567018(D_00655290, o->id, D_0064D240, 4, 1);
        return 0;
    }
    return 1;
}
