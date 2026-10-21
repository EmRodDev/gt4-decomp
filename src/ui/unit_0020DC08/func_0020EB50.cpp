#include "types.h"

extern char D_00697810[];
extern "C" s32 fptodp(void *);
extern "C" void func_0020ED08(void *, const char *, s32);

extern "C" void func_0020EB50(void *self) {
    const char *name = D_00697810;
    func_0020ED08(self, name, fptodp(self));
}
