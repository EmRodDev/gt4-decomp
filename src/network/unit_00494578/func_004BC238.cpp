/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Steps back one record in a table of 0xEC-byte entries (cursor in word 0, count in word 4 of the table header; inferred from the
 * arithmetic), re-submits the record's request (func_004C0860 with 0x300) and its payload (func_004BFDA0), and on success
 * decrements the count (cursor reset to 0 when it reaches 0). Purpose unknown. Returns 0 when the table is empty, 0x80000277 when the status
 * word is 0x65, 1 on success, otherwise the failing call's code after func_004BC6E8 cleans up. */
struct Ent {
    int w0;
    int w4;
    int w8;
    char pad[0xEC - 0xC];
};
struct Ctx {
    char pad0[0xC];
    int *p0C;
    char pad10[0x18];
    void *p28;
    int *p2C;
    char pad30[8];
    int *p38;
    char pad3C[4];
    Ent *t40;
};
extern char D_006452D4[];
extern "C" void func_004BC6E8(Ctx *);
extern "C" int func_004BFDA0(Ctx *, void *, void *, int *, int);
extern "C" int func_004C0860(Ctx *, int, int, Ent *);
extern "C" int func_004C0F30(Ctx *, int);
extern "C" void func_004C8F08(void *, void *);
extern "C" void func_004C8FD8(void *, void *);

extern "C" int func_004BC238(void) {
    char buffer[0x60];
    Ctx **context = (Ctx **)D_006452D4;
    int result;
    if (*(*context)->p2C == 0x65) return 0x80000277;
    Ent *table = (*context)->t40;
    if (table->w4 == 0) return 0;
    int cursor = table->w0 - 1;
    table->w0 = cursor;
    if (cursor < 0) (*context)->t40->w0 = 0;
    {
        Ent *entry = (*context)->t40 + (*context)->t40->w0;
        result = func_004C0F30((*context), entry->w8);
    }
    if (result == 0) {
        {
            Ent *entry = (*context)->t40 + (*context)->t40->w0;
            result = func_004C0860(*context, 0x300, entry->w8, entry);
        }
        if (result == 0) {
            Ent *entry = (*context)->t40 + (*context)->t40->w0;
            *(*context)->p0C = entry->w8;
            entry = (*context)->t40 + (*context)->t40->w0;
            func_004C8FD8(buffer, (char *)entry + 0x28);
            func_004C8F08((*context)->p28, buffer);
            *(*context)->p38 = 0;
            entry = (*context)->t40 + (*context)->t40->w0;
            result = func_004BFDA0(*context, (char *)entry + 0xC, (*context)->p28, (*context)->p38, 1);
            if (result >= 0) {
                Ent *table2 = (*context)->t40;
                int remaining = table2->w4 - 1;
                table2->w4 = remaining;
                if (remaining == 0) (*context)->t40->w0 = 0;
                result = 1;
            } else {
                func_004BC6E8(*context);
            }
        } else {
            func_004BC6E8(*context);
        }
    } else {
        func_004BC6E8(*context);
    }
    return result;
}
