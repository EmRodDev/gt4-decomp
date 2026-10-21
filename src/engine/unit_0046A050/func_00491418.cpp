/* Lays out and draws one string in a text box: after resetting the measured size (+0x3C/+0x40) it computes the glyph cell from the font (width/height byte at +0xD/+0xE times the scale at +0x28), the text width and the horizontal alignment from the flags at +0x64 (bits 2..3: 1 = centred, 2 = right-aligned inside the box width +0x60 - +0x58), then either places characters one by one (flags bits 0..1, func_00491028 / func_00491220), or lays out a normal line (func_00491380) and stores the resulting height; other boxes (+0x50 set) only call func_00490D08. The state at +0x44 is saved and restored around a temporary mode switch (func_00491EB0 / func_004924B8) when the caller passed t0 == 0 and +0x7C is clear. Reading of the flag bits is inferred from the arithmetic; their names are not known. */
#include "types.h"

struct Font {
    char p0[0xD];
    u8 glyphWidth;
    signed char glyphHeight;
};
struct Obj {
    char p0[0x14];
    Font *font;
    char p18[0x24 - 0x18];
    f32 f24;
    f32 fontScale;
    char p2C[0x30 - 0x2C];
    f32 f30;
    f32 f34;
    char p38[0x3C - 0x38];
    f32 f3C;
    f32 f40;
    int f44;
    char p48[0x4C - 0x48];
    int f4C;
    int f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    f32 f60;
    int layoutFlags;
    int f68;
    char p6C[0x78 - 0x6C];
    int f78;
    int f7C;
};

extern int D_00624988;
extern "C" int func_00490BF8(const char *) throw();
extern "C" void func_00490D08(Obj *, int, int) throw();
extern "C" void func_00491028(Obj *, int, int, int, int, int, f32) throw();
extern "C" void func_00491220(Obj *, int, int, int, int, f32) throw();
extern "C" void func_00491380(Obj *, int, int, int, int) throw();
extern "C" int func_00491AC0(Font *) throw();
extern "C" void func_00491EB0(void);
extern "C" void func_00491F98(void);
extern "C" void func_004924B8(void);

extern "C" void func_00491418(Obj *textBox, int text, int param2, int param3, int mode)
{
    textBox->f3C = 0.0f;
    int savedState = textBox->f44;
    textBox->f40 = 0.0f;
    int currentState = savedState;
    int stateLock = textBox->f7C;
    if (mode == 0) {
        if (stateLock == 0) {
            func_00491EB0();
            currentState = textBox->f44;
        }
    }
    D_00624988 = currentState;
    func_00491F98();
    if (textBox->f4C != 0) {
        int glyphCount = textBox->f68 == 0 ? 1 : func_00490BF8((const char *)text);
        Font *font = textBox->font;
        f32 glyphCountF = (f32)glyphCount;
        f32 scale = textBox->fontScale;
        f32 cellWidth = (f32)font->glyphWidth * scale;
        f32 cellHeight = (f32)font->glyphHeight * scale;
        int flags = textBox->layoutFlags;
        f32 textWidth = cellWidth * glyphCountF;
        textBox->f40 = textWidth;
        if ((flags & 0xC) != 0) {
            f32 boxWidth = textBox->f60 - textBox->f58;
            int hAlign = (flags >> 2) & 3;
            if (hAlign == 1) {
                textBox->f34 = cellHeight + (boxWidth - textWidth) * 0.5f;
            } else if (hAlign == 2) {
                textBox->f34 = cellHeight + (boxWidth - textWidth);
            }
        } else {
            textBox->f34 = cellHeight;
        }
        if ((flags & 3) != 0) {
            if (textBox->f68 != 0)
                func_00491028(textBox, text, param2, glyphCount, param3, mode, cellWidth);
            else
                func_00491220(textBox, text, param2, param3, mode, cellWidth);
        } else {
            textBox->f30 = 0.0f;
            func_00491380(textBox, text, param2, param3, mode);
            int lineHeight = func_00491AC0(textBox->font);
            textBox->f3C = textBox->f30 - (f32)(lineHeight / 2) * textBox->f24;
        }
    } else if (textBox->f50 != 0) {
        if (param3 == 0)
            func_00490D08(textBox, text, mode);
    } else {
        f32 oldY = textBox->f34;
        func_00491380(textBox, text, param2, param3, mode);
        textBox->f40 = textBox->f34 - oldY;
        textBox->f3C = textBox->f5C - textBox->f54;
    }
    if (mode == 0) {
        if (stateLock == 0)
            func_004924B8();
    }
    textBox->f78 = 0;
    if (mode == 0)
        textBox->f44 = savedState;
}
