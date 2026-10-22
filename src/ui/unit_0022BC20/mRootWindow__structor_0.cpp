/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor of mRootWindow: runs the mFBox constructor, installs the mRootWindow vtable and zero-initialises its own members.
 * +0xC0 is a circular list whose sentinel node (0xC bytes) is allocated by func_00326750 and points to itself both ways (an empty list); +0xCC is a three-int vector set to 0;
 * the std::string at +0xDC is built from the literal D_00698888 (empty-rep clone, then assign with string length) and the one at +0xE0 stays an empty clone.
 * The flags word at +0xE8 gets bit 1 set and bits 0, 2, 3, 4 and 5 cleared (masks ~1, -5, -9, ~0x10, ~0x20); then func_00206858(self, 1) is called.
 * The spare array and the constants kept in locals only reproduce the stack frame and register use the compiler needs. */
typedef int s32;
typedef unsigned int u32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct Node { Node *a; Node *b; s32 c; };
struct List { s32 pad; Node *head; };
struct Vec { s32 pad; s32 a; s32 b; s32 c; };
struct Obj {
    char pad0[4];
    char *vptr;
    char pad1[0xB8];
    List list;           /* 0xC0 */
    s32 unkC8;
    Vec vec;             /* 0xCC */
    Str s1;              /* 0xDC */
    Str s2;              /* 0xE0 */
    s32 unkE4;
    u32 flags;           /* 0xE8 */
    s32 unkEC;
};
extern Rep D_00659FA8;
extern char mRootWindow__vtable[];
extern char D_00698888[];
extern "C" void func_00206858(void *, s32);
extern "C" void *mFBox__structor_0(void *);
extern "C" void *func_00326750(s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *, s32, s32, const char *, s32);
extern "C" const char **func_005DBBC0(void);

static inline void vinit(Vec *v) { v->a = 0; v->b = 0; v->c = 0; }

extern "C" void mRootWindow__structor_0(Obj *self) {
    s32 spare[4];
    (void)&spare;
    Str *text1Ptr = &self->s1;
    Str *text2Ptr = &self->s2;
    List *listPtr = &self->list;
    mFBox__structor_0(self);
    self->vptr = mRootWindow__vtable;
    Node *sentinel = (Node *)func_00326750(0xC, 4, *func_005DBBC0());
    listPtr->head = sentinel;
    sentinel->a = sentinel;
    listPtr->head->b = listPtr->head;
    self->unkC8 = 0;
    vinit(&self->vec);
    const char *initialText = D_00698888;
    {
        Rep *emptyRep = &D_00659FA8;
        char *data = (char *)(emptyRep + 1);
        if (emptyRep->sel != 0) {
            data = func_005C2560(emptyRep);
        } else {
            emptyRep->ref++;
        }
        text1Ptr->p = data;
    }
    func_005C2630(text1Ptr, 0, -1, initialText, func_0057F260(initialText));
    {
        Rep *emptyRep = &D_00659FA8;
        char *data = (char *)(emptyRep + 1);
        if (emptyRep->sel != 0) {
            data = func_005C2560(emptyRep);
        } else {
            emptyRep->ref++;
        }
        text2Ptr->p = data;
    }
    self->unkE4 = 0;
    self->unkEC = 0;
    s32 one = 1, c5 = -5, c9 = -9;
    u32 flagBits = self->flags;
    flagBits &= ~1u;
    flagBits |= 2;
    flagBits &= c5;
    flagBits &= c9;
    flagBits &= ~0x10u;
    flagBits &= ~0x20u;
    self->flags = flagBits;
    func_00206858(self, one);
}
