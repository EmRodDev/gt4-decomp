/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor of a class derived from the one built by func_0047D280 (inferred from the base call made first). It
 * then stores the vtable pointer D_00688A80 at +0x5C, the char pointer r at +0x60, extra at +0x64 and -1 at +0x68,
 * and placement-constructs two containers inside the object: the first (Cont) allocates a 0x1C-byte header node
 * through func_00575E60 whose links point to itself (an empty tree-style container with a one-byte comparator and
 * a count of 0, inferred from the node shape); the second (Cont2) allocates a 0x14-byte node linked to itself (an
 * empty list, inferred). Finally func_0047FC78 is called with the same third argument that the base constructor
 * received. The unused int spare[4] is probably there to reserve stack space (inferred; removing it was not tried), and the comparator is made by a
 * helper and bound to a reference because that is how the temporary lands in the matching stack slot. */
struct Link { Link *a, *b, *c, *d; };
extern "C" Link *func_00575E60(int, int);
inline void *operator new(unsigned int, void *p) { return p; }
struct Cmp { unsigned char v; Cmp() : v(0) {} };
static inline Cmp comparator() { return Cmp(); }
struct Base {
 int alloc; Link *head; int size;
 Base() { head=0; Link *n=func_00575E60(0x10,0x1c); size=0; head=n; }
};
struct Cont : Base {
 Cmp flag; int cnt;
 Cont(const Cmp &v) : Base(), flag(v) {
  head->a=0; head->b=0; head->c=head; head->d=head; cnt=0;
 }
};
struct Cont2 { int alloc; Link *head; Cont2() { Link *n=func_00575E60(0x10,0x14); head=n; n->a=n; head->b=head; } };
struct Src { char pad[0x30]; char *tab; };
struct Rec { char pad[6]; short idx; };
struct Obj { char pad[0x5c]; void *vt; char *p60; int i64, i68; char pad2[0x20]; Cont c1; int pad3; Cont2 c2; };
extern char D_00688A80[];
extern "C" void *func_0047D280(Obj *, Src *, Rec *, int, int, int) throw();
extern "C" void func_0047FC78(Obj *, int);
extern "C" void func_0047FB80(Obj *self, Src *source, char *r, int arg, int extra, int lastArg) {
 func_0047D280(self,source,0,arg,0,lastArg);
 self->vt=D_00688A80;
 self->p60=r;
 self->i64=extra; self->i68=-1;
 int spare[4];
 const Cmp &cmp = comparator();
 new (&self->c1) Cont(cmp);
 new (&self->c2) Cont2;
 func_0047FC78(self,arg);
}
