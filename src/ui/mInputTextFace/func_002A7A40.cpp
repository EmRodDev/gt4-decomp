/* mInputTextFace: feeds each character of a NUL-terminated string to the text editor at +0x578
   (func_004B6C80(editor, c, 0)), then calls func_004B8270(editor), as func_002A7AA0 does after
   its own edit. The character is an int (a char local gives other registers). */
#include "types.h"

struct func_002A7A40_a0 {
    char pad0[0x578];
    char editor[4];
};

extern "C" void func_004B6C80(void *editor, s32 c, s32 a2);
extern "C" void func_004B8270(void *editor);

extern "C" void func_002A7A40(struct func_002A7A40_a0 *self, const char *s) {
    void *editor = self->editor;
    s32 c;
    while ((c = *s++) != 0)
        func_004B6C80(editor, c, 0);
    func_004B8270(editor);
}
