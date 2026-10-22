/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Notifies the model of every eligible record in a list. The tester object comes from a virtual query at
 * vtable+0xD0 of the object at self+0x64; the list is at holder+0x60 (count at +0, pointer array at +8) with
 * holder at self+0x6C. For each entry the tester virtual at vtable+0x1A8 is asked about (holder, entry); when it
 * says yes and the byte at entryOwner+0x545 is zero (entryOwner is the pointer at entry+0x18), the model at
 * entry+0x2880 gets a virtual call at its vtable+0xE0 with param, the int at self+0x3624 and amount. The same 0x18
 * / 0x2880 pair appears in func_0038CFD8, which suggests the list items are the same record type (inferred).  The holder is re-read through self inside the loop, as in the matched source. */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct List { s32 count; s32 pad; s32 *items; };
struct R6C { char pad[0x60]; List *list; };

typedef char *(*GetFn)(char *, s32);
typedef s32 (*Test2)(char *, R6C *, char *);
typedef void (*Act)(char *, char *, s32, float);

extern "C" void func_00341BA0(char *self, char *param, float amount) {
    s32 i = 0;
    VEntry *e1 = (VEntry *)(*(char **)(self + 0x64) + 0xD0);
    char *tester = ((GetFn)e1->fn)(self + e1->delta, 0);
    R6C *holder = *(R6C **)(self + 0x6C);
    s32 entryCount = holder->list->count;
    if (entryCount > 0) {
        do {
            VEntry *e3 = (VEntry *)(*(char **)tester + 0x1A8);
            char *entry = (char *)(*(R6C **)(self + 0x6C))->list->items[i];
            i++;
            char *entryOwner = *(char **)(entry + 0x18);
            if (((Test2)e3->fn)(tester + e3->delta, *(R6C **)(self + 0x6C), entry) != 0 && *(unsigned char *)(entryOwner + 0x545) == 0) {
                char *model = *(char **)(entry + 0x2880);
                VEntry *e4 = (VEntry *)(*(char **)(model + 8) + 0xE0);
                ((Act)e4->fn)(model + e4->delta, param, *(s32 *)(self + 0x3624), amount);
            }
        } while (i < entryCount);
    }
}
