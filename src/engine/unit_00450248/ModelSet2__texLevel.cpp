#include "types.h"

extern s32 tex_level;

extern "C" s32 ModelSet2__texLevel(s32 arg0) {
    s32 old_level = tex_level;
    tex_level = arg0;
    return old_level;
}
