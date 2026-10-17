/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { int p; };
struct Vector { int alloc; Handle *start, *finish, *end; };
struct Obj { int first; void *vt; char pad8[8]; Vector vec; };
extern char mDomNodeList__vtable[], D_006974B0[];
extern "C" void func_00208F18(void *, int);
extern "C" void hObject__structor_2(void *, int);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" const char **MDomNode__tf();
static inline Handle *value_type(Handle *const &) { return 0; }
static inline void destroy_aux(Handle *first, Handle *last, Handle *) {
    for (; first != last; ++first) func_00208F18(first, 2);
}
static inline void destroy(Handle *first, Handle *last) {
    destroy_aux(first, last, value_type(first));
}
static inline void deallocate(Handle *p, int n) {
    if (p) func_00326798(p, n * 4, 4, *MDomNode__tf());
}
static inline void release(Vector *v) {
    destroy(v->start, v->finish);
    deallocate(v->start, v->end - v->start);
}
extern "C" void mDomNodeList__structor_1(Obj *self, int flags) {
    self->vt = mDomNodeList__vtable;
    release(&self->vec);
    hObject__structor_2(self, 0);
    if (flags & 1) func_00326798(self, 0x20, 4, D_006974B0);
}
