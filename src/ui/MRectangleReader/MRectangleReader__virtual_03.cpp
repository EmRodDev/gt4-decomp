/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Virtual slot 3 of MRectangleReader (inferred from the symbol name): parses a rectangle from the script/config token stream into 4 floats.
 * First func_005CD320 compares the current tag (arg2) against the keyword D_00698480 at position 0 (a string compare taking self, char*, pos, count);
 * only on a match (result 0) does it read. It then pulls tokens with func_0020EEA0 until end of stream (-1) or the closing brace (0x7D, '}'), converting each
 * token text with func_005A2F70 (double result, narrowed to f32) into v[0..3]; the cap is 4 values (zero-filled with a 0x10 byte clear first).
 * Without a closing brace func_0020FC58(lexer, 1) is called. The 4 floats are copied through the pointer at +4 of dest. The std::string token buffer is released inline. */
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
extern char D_00698480[];
extern char D_00698490[];

extern "C" s32 func_0020EEA0(void *lexer, Str *tokenStr);
extern "C" void func_0020FC58(void *emptyRep, int depth);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_0057F260(const char *tokenStr) throw();
extern "C" double func_005A2F70(const char *tokenStr);
extern "C" void func_005A48D8(void *p, s32 values, u32 n);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *emptyRep);
extern "C" s32 func_005CD320(void *self, const char *tokenStr, u32 pos, u32 n);

extern "C" void MRectangleReader__virtual_03(Holder *dest, void *lexer, void *tagName) {
    Str tokenStr;
    f32 values[4];
    if (func_005CD320(tagName, D_00698480, 0, func_0057F260(D_00698480)) == 0) {
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
        func_005A48D8(values, 0, 0x10);
        while ((tokenType = func_0020EEA0(lexer, &tokenStr)) != -1 && tokenType != 0x7D) {
            const char *tokenText = D_00698490;
            if (*(s32 *)(tokenStr.p - 0x10) != 0) {
                tokenStr.p[*(s32 *)(tokenStr.p - 0x10)] = 0;
                tokenText = tokenStr.p;
            }
            values[count++] = (f32)func_005A2F70(tokenText);
            if (count >= 4) {
                break;
            }
        }
        if (tokenType != 0x7D) {
            func_0020FC58(lexer, 1);
        }
        dest->out[0] = values[0];
        dest->out[1] = values[1];
        dest->out[2] = values[2];
        dest->out[3] = values[3];
        {
            Rep *rep = (Rep *)(tokenStr.p - 0x10);
            if (--rep->ref == 0) {
                s32 cap = rep->cap + 0x10;
                func_00326798(rep, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
