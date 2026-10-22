/* Virtual slot 68 of mPhotoRenderFace (inferred from the symbol name): releases the photo it holds, after the mTextFace slot 68 has run.
 * The handle at +0xA0 is dropped with func_001C95B0(handle, 3) when non-null and then cleared to 0. For the argument (arg1, purpose unknown) func_00197788 returns a value `first`;
 * if that is non-zero and func_00197798(arg1) is also non-zero, func_00335580(first) is called, presumably freeing or unregistering it (inferred; callee not identified). */
#include "types.h"

extern "C" void mTextFace__virtual_68(void *);
extern "C" void func_001C95B0(void *, s32);
extern "C" s32 func_00197788(s32);
extern "C" s32 func_00197798(s32);
extern "C" void func_00335580(s32);

struct PhotoRenderFace_0019B668 {
    u8 pad0[0xA0];
    void *handle;
};

extern "C" void mPhotoRenderFace__virtual_68(PhotoRenderFace_0019B668 *self, s32 resource) {
    void *face = self;
    mTextFace__virtual_68(face);
    void **handle_slot = (void **)((u8 *)face + 0xA0);
    if (*handle_slot != 0) {
        func_001C95B0(*handle_slot, 3);
    }
    *handle_slot = 0;
    s32 first = func_00197788(resource);
    if (first != 0 && func_00197798(resource) != 0) {
        func_00335580(first);
    }
}
