/* Virtual slot 92 of mScrollWindow (inferred from the symbol name): refreshes the two scroll bars from the sizes of the view and its content, then runs the mBox slot 92.
 * mWidget__getWindowSize reads the view window (widget at +0xBC) into the first two floats of buf0; func_00263C40 and func_0025B500 on the widget at +0xC0 fill buf0[2..3] and buf1[0..1].
 * func_002D21E0 is then called twice, once for the bar object at +0xC4 with (buf0[0], buf0[2], buf1[0]) and once for the bar at +0xFC with (buf0[1], buf0[3], buf1[1]);
 * the pairing of x values to the first bar and y values to the second is what the argument order shows. The meaning of each of the six numbers is unknown. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void mWidget__getWindowSize(s32, void *, void *);
extern "C" void func_00263C40(s32);
extern "C" void func_0025B500(s32, void *, void *, void *, void *);
extern "C" void func_002D21E0(void *, f32, f32, f32);
extern "C" void mBox__virtual_92(void *, void *);

struct mScrollWindow__virtual_92_arg0 {
    char pad0[0xBC];
    s32 viewWidget;
    s32 contentWidget;
};
struct mScrollWindow__virtual_92_buf0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct mScrollWindow__virtual_92_buf1 {
    f32 unk0;
    f32 unk4;
};

extern "C" void mScrollWindow__virtual_92(s32 *scrollWindow, void *context) {
    s32 sizes[4];
    s32 extents[4];
    mWidget__getWindowSize(((struct mScrollWindow__virtual_92_arg0 *)scrollWindow)->viewWidget, sizes, (char *)sizes + 0x4);
    func_00263C40(((struct mScrollWindow__virtual_92_arg0 *)scrollWindow)->contentWidget);
    func_0025B500(((struct mScrollWindow__virtual_92_arg0 *)scrollWindow)->contentWidget, (char *)sizes + 0x8, (char *)sizes + 0xc, extents, (char *)extents + 0x4);
    func_002D21E0((char *)scrollWindow + 0xc4, ((struct mScrollWindow__virtual_92_buf0 *)sizes)->unk0, ((struct mScrollWindow__virtual_92_buf0 *)sizes)->unk8, ((struct mScrollWindow__virtual_92_buf1 *)extents)->unk0);
    func_002D21E0((char *)scrollWindow + 0xfc, ((struct mScrollWindow__virtual_92_buf0 *)sizes)->unk4, ((struct mScrollWindow__virtual_92_buf0 *)sizes)->unkC, ((struct mScrollWindow__virtual_92_buf1 *)extents)->unk4);
    mBox__virtual_92(scrollWindow, context);
}
