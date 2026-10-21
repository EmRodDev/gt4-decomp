/* mSelectBar member (class taken from the directory) that calls a script method on this object from C++ (inferred from the
 * method-handle type and the virtual call below). The method name is built as a refcounted string from the literal D_0069CCB8,
 * turned into a symbol and looked up with func_003069F8. If a handle comes back, the two arguments, the value passed in and the
 * field at +0xBC, are boxed into script Values and handed to the method through the handle's vtable (offset 0xA8). All the
 * temporaries are then released. The nested scopes copy the inlined string and handle constructors/destructors; they decide
 * register allocation, so they are kept as matched. */
#include "types.h"

struct Rep {
    s32 len;
    s32 blockSize;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct VEntryCall {
    short delta;
    short index;
    void (*fn)(void *, s32 *, s32, void *);
};

struct Obj {
    char pad0[0xBC];
    s32 bc;
};

extern Rep D_00659FA8;
extern char D_0069CCB8[];

extern "C" void *func_002FA120(void *arg0);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" void func_002FC870(void *h, int flags);
extern "C" void func_002FE278(void *h, s32 v);
extern "C" void func_003069F8(Obj *obj, void *h, s32 *val);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_0030BB18(void *h);
extern "C" s32 HSymID__GetID(Str *s);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

struct MethodHandle {
    s32 p;
    s32 pad[3];
    MethodHandle() { func_002FA120(this); }
    ~MethodHandle() { func_002F9B38(this, 2); }
};

static inline void vcall20(VObj *o, s32 *result, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, result, n, args);
}

#define DESTROY_ARGS()                          \
    {                                           \
        Value *argEnd = args + 2;               \
        while (args != argEnd) {                \
            --argEnd;                           \
            func_00309378(argEnd, 2);           \
        }                                       \
    }

extern "C" void func_002D6D18(Obj *self, s32 argValue) {
    s32 newVal;
    s32 oldVal;
    MethodHandle method;
    s32 result[4];
    Str methodName;
    s32 *resultPtr;
    resultPtr = result;
    {
        Str *namePtr = &methodName;
        const char *literal = D_0069CCB8;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        *resultPtr = HSymID__GetID(namePtr);
        func_003069F8(self, &method, resultPtr);
        {
            Rep *rep = (Rep *)(namePtr->p - 0x10);
            if (--rep->ref == 0) {
                s32 blockSize = rep->blockSize + 0x10;
                func_00326798(rep, blockSize, 4, func_005C11A8()->name);
            }
        }
    }
    if (method.p != 0) {
        func_0030BB18(resultPtr);
        {
            Value args[2];
            s32 scratch[4];
            s32 boxedArg;
            s32 *tmpValue;
            Value *argSlot;

            tmpValue = scratch;
            argSlot = args;
            boxedArg = argValue;
            func_00309348(tmpValue, &boxedArg);
            if (argSlot != (Value *)tmpValue) {
                newVal = *tmpValue;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = argSlot->p;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                argSlot->p = newVal;
            }
            func_00309378(tmpValue, 2);

            argSlot = &args[1];
            func_002FE278(tmpValue, self->bc);
            if (argSlot != (Value *)tmpValue) {
                newVal = *tmpValue;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = argSlot->p;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                argSlot->p = newVal;
            }
            func_002FC870(tmpValue, 2);

            vcall20((VObj *)method.p, resultPtr, 2, args);
            DESTROY_ARGS();
            func_00309378(resultPtr, 2);
        }
    }
}
