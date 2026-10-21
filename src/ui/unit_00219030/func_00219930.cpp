/* Builds a refcounted name string from the literal D_00697C40 and passes it, with the source, to func_00213090 to fill a handle. After
 * releasing the string it calls virtual slot 0x190 of the handle's object with callArg (the same vtable offset the registration
 * functions use to set a class name, see func_002B9E40; purpose here unknown), registers the result with func_00306638, and stores
 * the handle through func_002292F8 into the returned object. Class not identified (directory unit_00219030). */
#include "types.h"

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct VE { short d; short i; void (*fn)(void *, s32); };
struct Inner { char pad[4]; char *vt; };
struct Handle { Inner *handleObj; char pad[0xC]; };
struct Arg1 { char pad[0x24]; void *f24; };

extern Rep D_00659FA8;
extern "C" void func_00213090(void *, void *, void *) throw();
extern "C" void func_002292F8(void *, void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_00306638(void *, void *, void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);
extern char D_00697C40[];

extern "C" void *func_00219930(void *result, Arg1 *source, s32 callArg) {
    Handle handle;
    Str nameStr;
    Str *namePtr = &nameStr;
    const char *name = D_00697C40;
    {
        Rep *emptyRep = &D_00659FA8;
        char *p = (char *)(emptyRep + 1);
        if (emptyRep->sel != 0)
            p = func_005C2560(emptyRep);
        else
            emptyRep->ref++;
        namePtr->p = p;
    }
    func_005C2630(namePtr, 0, -1, name, func_0057F260(name));
    func_00213090(&handle, source, namePtr);
    {
        Rep *rep = (Rep *)(namePtr->p - 0x10);
        if (--rep->ref == 0) {
            s32 blockSize = rep->cap + 0x10;
            func_00326798(rep, blockSize, 4, func_005C11A8()->name);
        }
    }
    {
        Inner *handleObj = handle.handleObj;
        VE *entry = (VE *)(handleObj->vt + 0x190);
        entry->fn((char *)handleObj + entry->d, callArg);
    }
    func_00306638(namePtr, source->f24, &handle);
    func_00323B60(namePtr, 2);
    func_002292F8(result, &handle);
    func_002550B8(&handle, 2);
    return result;
}
