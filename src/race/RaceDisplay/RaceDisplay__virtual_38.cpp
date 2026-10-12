/* RaceDisplay__virtual_38 (func_0039CC98). */
typedef int s32;
typedef unsigned char u8;

struct Obj {
    s32 f0;
    s32 f4;
    char pad[0x2F];
    u8 f37;
};

struct Ev {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
};

extern "C" s32 func_003A1628(Obj *arg0);
extern "C" void *func_003A37D0(Ev *arg0);
extern "C" void func_003A3148(Ev *o, s32 t);

extern "C" void func_0039CC98(Obj *arg0) {
    if (func_003A1628(arg0) != 0) {
        if (arg0->f37 != 0) {
            Ev ev;
            func_003A37D0(&ev);
            ev.f8 = 4;
            s32 t = arg0->f4;
            ev.f0 = 0;
            func_003A3148(&ev, t);
        }
    }
}
