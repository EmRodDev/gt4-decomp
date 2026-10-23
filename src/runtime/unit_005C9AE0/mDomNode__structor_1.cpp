/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct TNode { s32 color; TNode *parent; TNode *left; TNode *right; };

struct Map {
    s32 pad0;
    TNode *header;
    s32 size;
    s32 pad_c;
};

struct Obj {
    s32 pad0;
    char *vt;
    char pad8[8];
    Map m1;
    Map m2;
    char *str;
};

extern char mDomNode__vtable[];
extern char D_006974B0[];
extern "C" S00659988 *func_005C11A8(Obj *self) throw();
extern "C" void func_005D7C40(void *, TNode *) throw();
extern "C" void func_005D7D10(void *, TNode *) throw();
extern "C" S00659988 *func_005D8210(void);
extern "C" S00659988 *func_005D8260(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void hObject__structor_2(void *, s32);

extern "C" void mDomNode__structor_1(Obj *self, s32 flags) {
    Map *m1 = &self->m1;
    self->vt = mDomNode__vtable;
    {
        Rep *q = (Rep *)(self->str) - 1;
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8(self)->name);
        }
    }
    Map *m2 = &self->m2;
    if (m2->size != 0) {
        func_005D7D10(m2, m2->header->parent);
        m2->header->left = m2->header;
        m2->header->parent = 0;
        m2->header->right = m2->header;
        m2->size = 0;
    }
    TNode *h2 = m2->header;
    func_00326798(h2, 0x18, 4, func_005D8260()->name);
    if (m1->size != 0) {
        func_005D7C40(m1, m1->header->parent);
        m1->header->left = m1->header;
        m1->header->parent = 0;
        m1->header->right = m1->header;
        m1->size = 0;
    }
    TNode *h1 = m1->header;
    func_00326798(h1, 0x18, 4, func_005D8210()->name);
    hObject__structor_2(self, 0);
    if (flags & 1)
        return func_00326798(self, 0x34, 4, D_006974B0);
}
