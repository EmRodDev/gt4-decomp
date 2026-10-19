struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Obj {
    char pad[8];
    VEntry *vtbl;
    char padC[0xC];
    char car_model[0x5C8];
};
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" float func_00452F70(void *);

extern "C" float RaceCarModel__virtual_39(Obj *arg0, float value) {
    func_004A53F8();
    VEntry *entry = &arg0->vtbl[33];
    entry->fn((char *)arg0 + entry->delta, value);
    float result = func_00452F70(arg0->car_model);
    func_004A5400();
    return result;
}
