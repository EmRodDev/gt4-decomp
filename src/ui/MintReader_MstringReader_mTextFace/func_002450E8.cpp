/* Looks a text key up and applies the translated text to the widget, or logs the missing key (a text-face setter; inferred from the directory name mTextFace).
 * func_002B7118 first hands the key (*arg1, a std::string) to the member at +0x104. If the key is not empty, func_0025A7E0 and func_0026A4D0 look the
 * key up in a table, giving a C string or 0. A hit is copied into a new std::string (empty clone + assign with string length), passed to func_00245270(widget, str)
 * and released; a miss calls func_005DB110(D_00699138, key), a formatted-print report of the unknown key (inferred from the format-string call shape). An empty key does nothing. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *keyData;
    char pad[0xC];
};

struct Obj {
    char pad[0x104];
    void *p104;
};

struct S00659988 {
    const char *name;
};

extern Rep D_00659FA8;
extern char D_00699138[];
extern char D_00699158[];

extern "C" void func_002B7118(void *self, void **src);
extern "C" s32 func_0025A7E0(void *a0, void *a1);
extern "C" s32 func_0026A4D0(void *a0, void **a1);
extern "C" void func_0026A118(void *a0, s32 a1);
extern "C" void func_00245270(void *a0, void *a1);
extern "C" char *func_005C2560(Rep *src);
extern "C" s32 func_0057F260(s32 s);
extern "C" void *func_005C2630(void *str, s32 pos, s32 n1, s32 s, s32 n2);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *keyData, s32 n, s32 align, const char *name);
extern "C" void func_005DB110(const char *fmt, ...);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->keyData - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_002450E8(Obj *face, void **key) {
    Str lookupStr;
    Str *strPtr;
    s32 translated;

    func_002B7118(face->p104, key);
    if (*(s32 *)((char *)*key - 0x10) != 0) {
        func_0025A7E0(&lookupStr, face);
        translated = func_0026A4D0(lookupStr.keyData, key);
        func_0026A118(&lookupStr, 2);
        if (translated != 0) {
            Rep *emptyRep;
            char *data;
            strPtr = &lookupStr;
            emptyRep = &D_00659FA8;
            if (emptyRep->sel != 0) {
                data = func_005C2560(emptyRep);
            } else {
                data = (char *)(emptyRep + 1);
                emptyRep->ref++;
            }
            strPtr->keyData = data;
            func_005C2630(strPtr, 0, -1, translated, func_0057F260(translated));
            func_00245270(face, &lookupStr);
            str_release(&lookupStr);
        } else {
            char *keyData = (char *)*key;
            s32 len = *(s32 *)(keyData - 0x10);
            char *keyText;
            if (len == 0) {
                keyText = D_00699158;
            } else {
                keyData[len] = 0;
                keyText = (char *)*key;
            }
            func_005DB110(D_00699138, keyText);
        }
    }
}
