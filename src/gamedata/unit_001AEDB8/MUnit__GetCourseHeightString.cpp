/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script method GetCourseHeightString(value): formats the float returned by virtual slot +0x60 of args[0] (a course height, from the method name), converted with the unit manager (func_00472C90) and rounded to tenths (value*10+0.5), with the unit text from func_004728D0 and format D_00693040 (func_00490A40) into a 0x80-byte buffer, and returns it as a new script string through *out. Sibling of GetCourseLengthString (hundredths, func_00472C28). */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct VE { short d; short i; f32 (*fn)(void *); };
struct Obj { char pad[4]; void *vt; };

extern Rep D_00659FA8;
extern s32 PDISTD__UNIT_MANAGER[];
extern void *D_00624984;
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" char *func_004728D0(s32 *);
extern "C" f32 func_00472C90(s32 *, f32);
extern "C" void func_00490A40(void *, char *, const char *, int, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);
extern char D_00693040[];

extern "C" void MUnit__GetCourseHeightString(s32 *out, s32 argCount, Obj **args) {
    char text[0x80];
    s32 result[8];
    Str textStr;
    if (argCount > 0) {
        Obj *o = *args;
        VE *valueSlot = (VE *)((char *)o->vt + 0x60);
        f32 heightValue = func_00472C90(PDISTD__UNIT_MANAGER, valueSlot->fn((char *)o + valueSlot->d));
        func_00490A40(D_00624984, text, D_00693040, (s32)(heightValue * 10.0f + 0.5f), func_004728D0(PDISTD__UNIT_MANAGER));
        Str *textStrPtr = &textStr;
        char *textPtr = text;
        {
            Rep *r = &D_00659FA8;
            char *p;
            if (r->sel != 0) {
                p = func_005C2560(r);
            } else {
                p = (char *)(r + 1);
                r->ref++;
            }
            textStrPtr->p = p;
        }
        func_005C2630(textStrPtr, 0, -1, textPtr, func_0057F260(textPtr));
        s32 *resultPtr = result;
        func_00314B20(resultPtr, textStrPtr);
        if (out != resultPtr) {
            s32 newHandle = *resultPtr;
            if (newHandle != 0) func_003285A8(newHandle);
            if (*out != 0) func_003285F8(*out);
            *out = newHandle;
        }
        func_00312318(resultPtr, 2);
        {
            Rep *q = (Rep *)(textStrPtr->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
    }
}

