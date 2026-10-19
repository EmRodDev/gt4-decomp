extern "C" void *func_003B05A8(void *arg0);
extern "C" void *HumanModel__structor_0(void *arg0);
extern char RaceDriverModel__vtable[];

struct RaceDriverModelObj {
    char pad0[0x7DC];
    void *vtable;
    char driver_data[4];
};

extern "C" void *RaceDriverModel__structor_0(RaceDriverModelObj *arg0)
{
    HumanModel__structor_0(arg0);
    arg0->vtable = RaceDriverModel__vtable;
    return func_003B05A8(arg0->driver_data);
}
