/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Finds a record in the same paged store func_004B30B8 searches (inferred: it uses the same helpers func_004B2388 / func_004B2518 /
 * func_004B23F0 / func_004B27D0 / func_004B22D8). With selector 1 and an empty text the record id is 1; otherwise func_004B3270 resolves the id
 * and a failed lookup (flag bit 0 clear) returns the default result through func_004B2CD0. The id is written in four big-endian bytes,
 * pages are chased while their tag is 1, and func_004B2CF8 fills `result` from the page, the entry count and the id.
 * Returns `result`. The roles of the selector and the text are not known beyond how they are tested. */
struct VT { short adj; short pad2; int (*fn)(void *); };
struct Obj { VT *vt; };
struct Sentry { int pad0; int val; unsigned char *cur; char pad1[0x30 - 0xC - 0x10 + 0x10 - 0x10 - 0xC]; };
struct Sen { int pad0; int val; unsigned char *cur; char pad1[0x30 - 0xC - 0x20]; };
struct SI { int pad0; int val; unsigned char *cur; char pad2[0x14]; unsigned char flag; char pad3[0xF]; };
extern "C" void func_004B22D8(SI *, int) throw();
extern "C" void func_004B2388(SI *, Obj *, int) throw();
extern "C" void func_004B23F0(SI *, int) throw();
extern "C" int func_004B2518(SI *, char *, int) throw();
extern "C" void func_004B27D0(SI *, char *, int, int *) throw();
extern "C" void func_004B2CD0(void *) throw();
extern "C" void func_004B2CF8(void *, Obj *, int, int, int) throw();
extern "C" void func_004B3270(SI *, Obj *, int, char *);

extern "C" void *func_004B33D8(void *result, Obj *store, int selector, char *text) {
    char idBytes[4];
    SI lookup;
    int entryCount;
    int pageRef, recordId;
    if (selector == 1 && (text == 0 || *text == 0)) {
        recordId = 1;
    } else {
        func_004B3270(&lookup, store, selector, text);
        recordId = lookup.val;
        if ((unsigned char)(lookup.flag & 1) == 0) {
            func_004B2CD0(result);
            goto done;
        }
    }
    {
    VT *idSlot = (VT *)((char *)store->vt + 0x18);
    idBytes[0] = recordId >> 24;
    idBytes[1] = recordId >> 16;
    idBytes[2] = recordId >> 8;
    idBytes[3] = recordId;
    pageRef = 0;
    int handleId = idSlot->fn((char *)store + idSlot->adj);
    func_004B2388(&lookup, store, handleId);
    while ((lookup.cur[0] | (lookup.cur[1] << 8)) == 1) {
        pageRef = func_004B2518(&lookup, idBytes, 4);
        func_004B23F0(&lookup, pageRef);
    }
    entryCount = 0;
    func_004B27D0(&lookup, idBytes, 4, &entryCount);
    func_004B2CF8(result, store, pageRef, entryCount, recordId);
    func_004B22D8(&lookup, 2);
    }
done:
    return result;
}
