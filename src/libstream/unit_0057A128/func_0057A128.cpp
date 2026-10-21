typedef unsigned char u8;
struct VEntry { short delta, pad; void (*fn)(void *, u8 *, int, int); };
struct S { void *base; int size; u8 *head; u8 *tab; virtual void visit(u8 *, int, int); };
static inline int get32(const void *ptr) {
 const u8 *p = (const u8 *)ptr;
 int x = p[0] | (p[3] << 24);
 int y = (p[2] << 16) | (p[1] << 8);
 return x | y;
}
extern "C" void func_0057A128(S *self, void *data, int size) {
 self->base = data;
 self->size = size;
 u8 *p = (u8 *)data;
 p += get32(p + 4);
 int off = get32(p);
 self->head = p;
 p += off;
 off = get32(p);
 int val = get32(p + 4);
 if (off && val) {
  self->tab = p;
  p += off;
  for (;;) {
   off = get32(p);
   val = get32(p + 4);
   if (!off && !val) return;
   u8 *next = p + off;
   self->visit(p, off, val);
   p = next;
  }
 }
}
