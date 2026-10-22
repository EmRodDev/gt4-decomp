/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Heap { const char *name; };
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" u32 func_0057F260(const char *) throw();

struct Rep {
    s32 len, cap, ref, sel;
    char *data() { return (char *)(this + 1); }
    char *grab();
    void release()
    {
        if (--ref == 0) {
            s32 size = cap + sizeof(Rep);
            func_00326798(this, size, 4, func_005C11A8()->name);
        }
    }
};
extern "C" char *func_005C2560(Rep *);
inline char *Rep::grab()
{
    if (sel)
        return func_005C2560(this);
    ++ref;
    return data();
}
extern Rep D_00659FA8;

struct String {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    String &replace(u32, u32, const char *, u32) __asm__("func_005C2630");
    String(const char *s)
    {
        p = D_00659FA8.grab();
        replace(0, (u32)-1, s, func_0057F260(s));
    }
    String(const String &o) { p = o.rep()->grab(); }
    ~String() { rep()->release(); }
};

struct Ref {
    void *p;
    Ref(const int &) __asm__("func_00309348");
    Ref(const Ref &) __asm__("func_00309360");
    ~Ref() __asm__("func_00309378");
    Ref &operator=(const Ref &o)
    {
        if (this != &o) {
            void *v = o.p;
            if (v)
                func_003285A8(v);
            if (p)
                func_003285F8(p);
            p = v;
        }
        return *this;
    }
};

struct StringRef : Ref {
    StringRef(const String &) __asm__("func_00314B20");
    ~StringRef() __asm__("func_00312318");
};

struct IntRef : Ref {
    IntRef(int) __asm__("func_002FE278");
    ~IntRef() __asm__("func_002FC870");
};

struct ArrayObj {
    Ref push(const Ref &) __asm__("func_002EEEB0");
};

struct Array : Ref {
    Array() __asm__("func_002EFBF0");
    ~Array() __asm__("func_002ED5C0");
    ArrayObj *operator->() { return (ArrayObj *)p; }
};

struct CalendarObj {
    char pad[0x10];
    void *data;
};

struct Calendar {
    CalendarObj *p;
    Calendar(void *ctx) throw() __asm__("func_00132DB8");
    Calendar(const Calendar &);
    ~Calendar() throw() __asm__("func_00132D60");
    CalendarObj *operator->() { return p; }
};

struct Event {
    u8 type;
    u8 b1;
    union {
        struct {
            u8 b2;
            u8 b3;
        } c;
        u16 h2;
    } u;
    u32 time;
    long id;
};

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *);
};
struct ScriptObj {
    int pad;
    char *vtbl;
    int toInt()
    {
        VEntry *e = (VEntry *)(vtbl + 0x58);
        return e->fn((char *)this + e->delta);
    }
};

extern char D_0068EAA0[];
extern "C" void func_0042EFF0(void *, int *, int *, int *);
extern "C" Event *func_0042F060(void *, int, int, int);
extern "C" const char *func_0042EE70(Event *);
extern "C" const char *func_0042EEA0(int);
extern "C" const char *func_0042EEF0(int);
extern "C" const char *func_0042EF40(int);
extern "C" const char *func_00431C38(int);
extern "C" const char *func_00431C90(int);
extern "C" int func_00447CA0(long, char *);
extern "C" void GranTurismo4__GetTimeString(u32, char *, u32);

extern "C" void MCalendar__getEvent(Ref *ret, void *self, int argc, ScriptObj **argv)
{
    int year, month, day;

    if (argc >= 3) {
        year = argv[0]->toInt();
        month = argv[1]->toInt();
        day = argv[2]->toInt();
    } else {
        func_0042EFF0(Calendar(self)->data, &year, &month, &day);
    }
    Event *e = func_0042F060(Calendar(self)->data, year, month, day);
    if (e && func_0042EE70(e)) {
        char buf[0x80];
        buf[0] = 0;
        Array arr;
        arr->push(StringRef(String(func_0042EE70(e))));
        switch (e->type) {
        case 0:
            break;
        case 1: {
            func_00447CA0(e->id, buf);
            arr->push(StringRef(String(buf)));
            arr->push(IntRef(e->b1));
            const char *reason = func_0042EEA0(e->u.c.b2);
            if (!reason)
                reason = D_0068EAA0;
            arr->push(StringRef(String(reason)));
            break;
        }
        case 2:
            func_00447CA0(e->id, buf);
            arr->push(StringRef(String(buf)));
            arr->push(IntRef(e->b1));
            arr->push(IntRef(e->u.h2));
            break;
        case 3: {
            func_00447CA0(e->id, buf);
            arr->push(StringRef(String(buf)));
            const char *s = func_00431C38(e->b1);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            s = func_00431C90(e->u.c.b2);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            GranTurismo4__GetTimeString(e->time, buf, sizeof(buf));
            arr->push(StringRef(String(buf)));
            break;
        }
        case 4: {
            func_00447CA0(e->id, buf);
            arr->push(StringRef(String(buf)));
            const char *s = func_00431C38(e->b1);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            s = func_00431C90(e->u.c.b2);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            GranTurismo4__GetTimeString(e->time, buf, sizeof(buf));
            arr->push(StringRef(String(buf)));
            break;
        }
        case 5: {
            func_00447CA0(e->id, buf);
            arr->push(StringRef(String(buf)));
            const char *s = func_00431C38(e->b1);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            s = func_00431C90(e->u.c.b2);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            GranTurismo4__GetTimeString(e->time, buf, sizeof(buf));
            arr->push(StringRef(String(buf)));
            break;
        }
        case 6:
            func_00447CA0(e->id, buf);
            arr->push(StringRef(String(buf)));
            arr->push(StringRef(String(func_0042EEF0(e->b1))));
            arr->push(IntRef(e->u.c.b2));
            break;
        case 7:
            if (e->id != -1) {
                func_00447CA0(e->id, buf);
                arr->push(StringRef(String(buf)));
            } else {
                arr->push(Ref(0));
            }
            break;
        case 8: {
            func_00447CA0(e->id, buf);
            arr->push(StringRef(String(buf)));
            arr->push(StringRef(String(func_0042EF40(e->u.c.b3))));
            const char *s = func_00431C38(e->b1);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            s = func_00431C90(e->u.c.b2);
            arr->push(s ? Ref(StringRef(String(s))) : Ref(0));
            GranTurismo4__GetTimeString(e->time, buf, sizeof(buf));
            arr->push(StringRef(String(buf)));
            break;
        }
        case 9:
            break;
        }
        *ret = arr;
    } else {
        *ret = Ref(0);
    }
}
