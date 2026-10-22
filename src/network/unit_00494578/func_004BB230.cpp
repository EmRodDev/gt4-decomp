/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub { u8 x,len; short z,amount; char pad[6]; };
struct Rec { u32 flags; char pad[6]; u8 code; char pad2[3]; signed char state; char pad3; Sub sub; };
struct Block { Rec entries[42]; u8 count,len; short pad; int total; };
struct Work { Rec entries[42]; u8 count,len; short pad; int total; Rec *ptrs[42]; };
struct Ctx { char p[0x28]; u16 *text; int *state; Work *work; };
extern Ctx *D_006452D4;
extern "C" {
int func_004BAF78(Ctx *, Block *, u8 *, int) throw();
void func_004BC740(u8 *, u8 *);
void func_004C3F90(void *, u32);
int func_004C5D48(Ctx *, u16 *, int, u8 *);
int func_004C6778(Ctx *, u16 *, int, Block *);
int func_004C8718(Ctx *, void *, u32, u16 *, Rec *);
void *func_004C8C20(Ctx *, u32);
void func_004C8C38(Ctx *, void *);
u16 *func_004C8E08(u16 *, u16 *);
u16 *func_004C8E38(u16 *, u16 *, int);
int func_004C8ED0(u16 *);
void func_004C8F08(u16 *, u16 *);
void func_004C9138(u8 *, u16 *, int);
u8 *func_004C9198(u8 *, u8 *);
int func_004C9330(u8 *);
int func_004C9410(u8 *);
}
static inline Ctx **context() { return &D_006452D4; }
extern "C" int func_004BB230(int index, int n, u8 *out, u32 size, u8 sep) {
 u8 record[0x1c];
 Block block;
 u8 suffix[0x7f];
 u16 first[43], second[43], text[43];
 int i, pos, ret;
 if (size-1 >= 0x7fff) return 0x80001542;
 if (!out) return 0x80001642;
 if (index < 0) return 0x80001942;
 if (n <= 0) return 0x80001a42;
 if (*(*context())->state != 0x65) return 0x80000142;
 if (index >= (*context())->work->count) return 0x80001342;
 if (!sep) return 0x80001242;
 Block *pb = &block;
 u8 *prec = record;
 func_004C3F90(first, 0x56);
 pos = 0;
 int reverse = (*context())->work->count - 1;
 for (i = 0; i < (*context())->work->count; i++) {
  func_004C8E38(first + pos, (*context())->text + pos, (*context())->work->entries[i].sub.len);
  pos += (*context())->work->entries[i].sub.len;
  if (reverse-- == index) break;
 }
 if (pos < n) n = pos;
 func_004C8F08(text, first);
 func_004C3F90(first, 0x56);
 func_004C8E38(first, text, n);
 func_004C3F90(second, 0x56);
 func_004C8E08(second, text + n);
 func_004C3F90(text, 0x56);
 func_004C8F08(text, first);
 func_004C3F90(prec, 0x1c);
 ret = func_004C5D48(*context(), text, 0, prec);
 if (ret < 0) return ret;
 func_004C8F08(text, second);
 func_004C3F90(pb, 0x4a0);
 if (func_004C8ED0(text) == 0) pb->count = 0;
 else {
  ret = func_004C6778(*context(), text, 0, pb);
  if (ret < 0) return ret;
 }
 ret = func_004BAF78(*context(), pb, prec, index);
 if (ret < 0) return ret;
 void *buf;
 u32 allocsize = (size >> 1) * 2 + 2;
 buf = func_004C8C20(*context(), allocsize);
 if (!buf) return 0x80000342;
 u8 *converted = (u8 *)func_004C8C20(*context(), allocsize);
 if (!converted) {
  func_004C8C38(*context(), buf);
  return 0x80000342;
 }
 u8 *result = (u8 *)func_004C8C20(*context(), size);
 if (!result) {
  func_004C8C38(*context(), buf);
  func_004C8C38(*context(), converted);
  return 0x80000342;
 }
 u8 *dest = result;
 func_004C3F90(result, size);
 func_004C3F90(suffix, 0x7f);
 func_004C3F90(first, 0x56);
 u16 *src = first;
 u8 *tail = suffix;
 func_004C8E08(text, (*context())->text);
 func_004C8F08(src, (*context())->text);
 pos = (*context())->work->len;
 for (i = (*context())->work->count - 1; i >= 0; i--) {
  Ctx *ctx = *context();
  Work *w = ctx->work;
  pos -= w->entries[i].sub.len;
  Rec *ptr = w->ptrs[i];
  Rec *item = &w->entries[i];
  if (ptr) item = ptr;
  ret = func_004C8718(ctx, buf, allocsize, text + pos, item);
  if (ret < 0) {
   func_004C8C38(*context(), buf);
   func_004C8C38(*context(), converted);
   func_004C8C38(*context(), result);
   return ret;
  }
  func_004C9138(converted, (u16 *)buf, ret);
  if (size < (u32)(dest - result + func_004C9330(converted) + 1)) {
   func_004C8C38(*context(), result);
   func_004C8C38(*context(), buf);
   func_004C8C38(*context(), converted);
   return 0x80001042;
  }
  func_004C9198(dest, converted);
  dest += func_004C9330(converted);
  *dest++ = sep;
  func_004C9138(tail, src, (*context())->work->entries[i].sub.len);
  tail += func_004C9330(tail);
  *tail++ = sep;
  src += (*context())->work->entries[i].sub.len;
 }
 dest[-1] = 0;
 tail[-1] = 0;
 func_004C8C38(*context(), buf);
 func_004C8C38(*context(), converted);
 if (size < (u32)(func_004C9410(result) + func_004C9410(suffix) + 2)) {
  func_004C8C38(*context(), result);
  return 0x80001042;
 }
 func_004BC740(out, result);
 func_004C8C38(*context(), result);
 func_004BC740(out + func_004C9330(out) + 1, suffix);
 return (*context())->work->count;
}
