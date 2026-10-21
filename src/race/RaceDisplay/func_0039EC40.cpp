/* Deferred update of a RaceDisplay element driven by a flags word: when byte 1 is set it is cleared and 003A1638 (with the value at +0x24)
 * and 0039D218 (with the signed byte at +0x2E) are run; when byte 2 is also set it is cleared too and the virtual refresh() (the last vtable
 * slot, hence the 52 filler slots in the declaration) and 0039CFD8 follow. Reading the bytes as "update pending" and "refresh pending" is inferred
 * from the clear-then-act pattern; what the element is is purpose unknown. */
struct ObjBase {
    virtual ~ObjBase();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void refresh();
};

struct Obj : ObjBase {
    char pad4[0x20];
    int arg24;
    char pad28[6];
    signed char mode2E;
    char pad2F;
    union {
        unsigned int word;
        unsigned char bytes[4];
    } flags;
};

extern "C" void func_003A1638(Obj *display, int arg);
extern "C" void func_0039D218(Obj *display, int mode);
extern "C" void func_0039CFD8(Obj *display);

extern "C" void func_0039EC40(Obj *display) {
    if (display->flags.bytes[1] == 0)
        return;
    display->flags.word &= 0xFFFF00FF;
    func_003A1638(display, display->arg24);
    func_0039D218(display, display->mode2E);
    if (display->flags.bytes[2]) {
        display->flags.word &= 0xFF00FFFF;
        display->refresh();
        func_0039CFD8(display);
    }
}
