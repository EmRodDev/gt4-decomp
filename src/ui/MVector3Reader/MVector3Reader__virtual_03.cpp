/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Virtual slot 3 of MVector3Reader (inferred from the symbol name): reads a 3-component vector, one float fewer than the rectangle and region readers.
 * The tag keyword is D_00699890, the empty-token fallback D_00699888. The token loop stops at 3 values (v is 0xC bytes, cleared with a 0xC byte clearing
 * call func_005A48D8), at end of stream (-1) or at '}' (0x7D); each token is converted by func_005A2F70 and narrowed to f32. The three results are stored
 * through the pointer at +4 of dest. When the closing brace was not consumed, func_0020FC58(lexer, 1) skips ahead. */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

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

struct Holder {
    char pad[4];
    f32 *out;
};

extern Rep D_00659FA8;
extern char D_00699890[];
extern char D_00699888[];

extern "C" s32 func_0020EEA0(void *lexer, Str *tokenStr);
extern "C" void func_0020FC58(void *emptyRep, int depth);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_0057F260(const char *tokenStr) throw();
extern "C" double func_005A2F70(const char *tokenStr);
extern "C" void func_005A48D8(void *p, s32 values, u32 n);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *emptyRep);
extern "C" s32 func_005CD320(void *self, const char *tokenStr, u32 pos, u32 n);

extern "C" void MVector3Reader__virtual_03(Holder *dest, void *lexer, void *tagName) {
    Str tokenStr;
    f32 values[3];
    if (func_005CD320(tagName, D_00699890, 0, func_0057F260(D_00699890)) == 0) {
        Rep *emptyRep = &D_00659FA8;
        char *data;
        s32 count;
        s32 tokenType;
        if (emptyRep->sel != 0) {
            data = func_005C2560(emptyRep);
        } else {
            data = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        tokenStr.p = data;
        func_0020EEA0(lexer, &tokenStr);
        count = 0;
        func_005A48D8(values, 0, 0xC);
        while ((tokenType = func_0020EEA0(lexer, &tokenStr)) != -1 && tokenType != 0x7D) {
            const char *tokenText = D_00699888;
            if (*(s32 *)(tokenStr.p - 0x10) != 0) {
                tokenStr.p[*(s32 *)(tokenStr.p - 0x10)] = 0;
                tokenText = tokenStr.p;
            }
            values[count++] = (f32)func_005A2F70(tokenText);
            if (count >= 3) {
                break;
            }
        }
        if (tokenType != 0x7D) {
            func_0020FC58(lexer, 1);
        }
        dest->out[0] = values[0];
        dest->out[1] = values[1];
        dest->out[2] = values[2];
        {
            Rep *rep = (Rep *)(tokenStr.p - 0x10);
            if (--rep->ref == 0) {
                s32 cap = rep->cap + 0x10;
                func_00326798(rep, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
