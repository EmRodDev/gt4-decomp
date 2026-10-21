/* Creates a mUpdateContextPS2 object (0x434 bytes), wraps it in a handle (func_0024E348), stores the handle into the field at +0x20 of self with the usual retain/release pair, writes arg1 into the new object's +0xD4 and passes the handle and the data at +0x24 of self to func_00306638. Purpose of the +0xD4 value unknown; the object-creation recipe is inferred from the structor name. */
#include "types.h"

struct Obj1 { char pad[0xD4]; s32 fD4; };
struct Self { char pad[0x20]; Obj1 *f20; char pad24[4]; };
struct H { s32 v; char pad[0xC]; };

extern "C" void *func_00326750(u32, int, const char *);
extern "C" void mUpdateContextPS2__structor_0(void *) throw();
extern "C" s32 func_0024E348(void *, void *);
extern "C" void func_0024E378(void *, int);
extern "C" void func_002EA590(void *, int);
extern "C" s32 func_002EC370(void *, s32);
extern "C" void func_002ECDE0(void *);
extern "C" void func_003041B8(void *, int);
extern "C" void *func_00306638(void *, s32, void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern char D_00697970[];

extern "C" void func_00219570(Self *self, s32 value) {
    H resolved;
    H scratch;
    H created;
    s32 *handlePtr = &created.v;
    void *context = func_00326750(0x434, 4, D_00697970);
    mUpdateContextPS2__structor_0(context);
    *(void **)&created = context;
    func_0024E348(&resolved, handlePtr);
    handlePtr = (s32 *)&self->f20;
    if (handlePtr != &resolved.v) {
        s32 newHandle = resolved.v;
        if (newHandle != 0) func_003285A8(newHandle);
        if (*handlePtr != 0) func_003285F8(*handlePtr);
        *handlePtr = newHandle;
    }
    func_0024E378(&resolved, 2);
    H *scratchPtr = &scratch;
    ((Obj1 *)*handlePtr)->fD4 = value;
    func_002ECDE0(scratchPtr);
    func_002EC370(&resolved, scratchPtr->v);
    func_002EA590(scratchPtr, 2);
    func_00306638(scratchPtr, resolved.v, (char *)self + 0x24);
    func_00323B60(scratchPtr, 2);
    func_003041B8(&resolved, 2);
}
