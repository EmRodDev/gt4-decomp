struct Info { char pad[2]; unsigned char kind; };
struct Obj {
    char pad0[4];
    char special[8];
    char implementation0C;
    char padD[3];
    char implementation10;
    char pad11[0xB];
    void *implementation;
};

extern "C" void func_0038CFD8(void *, void *, int);
extern "C" void func_0038D088(void *, void *, int);
extern "C" Info *func_0038DC18(Obj *);
extern "C" void func_0038C108(void *, int);

extern "C" void func_0038DC30(Obj *arg0, void *arg1, void *arg2, int arg3) {
    if (arg1 != 0) {
        func_0038CFD8(&arg0->implementation10, arg1, arg3);
    } else if (arg2 != 0) {
        func_0038D088(&arg0->implementation10, arg2, arg3);
    }
    unsigned char kind = func_0038DC18(arg0)->kind;
    switch(kind) {
    case 10:
        arg0->implementation = &arg0->implementation0C;
        break;
    case 15: {
        void *special = arg0->special;
        func_0038C108(special, arg3);
        arg0->implementation = special;
        break;
    }
    default:
        arg0->implementation = &arg0->implementation10;
        break;
    }
}
