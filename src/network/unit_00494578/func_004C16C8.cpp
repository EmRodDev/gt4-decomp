typedef unsigned short u16;
struct Data { int second; u16 *count; u16 *zero; };
struct E { int head; int enabled; char pad[20]; int first; Data data; };
struct Obj { E elems[1]; };
extern "C" void func_004C3F90(int, int);
extern "C" void func_004C16C8(Obj *obj, int i) {
    if (obj->elems[i].enabled) {
        func_004C3F90(obj->elems[i].first, *obj->elems[i].data.count * 4 + 24);
        func_004C3F90(obj->elems[i].data.second, *obj->elems[i].data.count * 2 + 12);
        *obj->elems[i].data.zero = 0;
    }
}
