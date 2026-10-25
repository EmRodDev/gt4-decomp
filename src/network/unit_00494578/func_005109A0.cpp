struct Cfg { int count; int kind; unsigned int size; void *a; void *b; void *c; };
enum Kind { KIND_ANY };
struct Input { int id; Kind kind; };
#define F(p,o) (*(int *)((char *)(p)+(o)))
extern "C" int func_00538BF8(int *, unsigned long);
extern "C" int func_00538B08(int *, unsigned long);
extern "C" int func_00512120(int, int, int *);
extern "C" int func_00511050();
extern "C" int func_005110C0();
extern "C" int func_005110E0();
extern "C" int func_00511118();
extern "C" int func_00510CD0();
extern "C" int func_005112D0();
extern "C" int func_005113B0();
extern "C" int func_00511528();
extern "C" int func_00510C80();
extern "C" int func_00511648();
extern "C" int func_00511708();
extern "C" int func_005117F8();
extern "C" int func_00511150();
extern "C" int func_005119F0();
extern "C" int func_00510E30();
extern "C" int func_005109A0(Cfg *cfg, Input *input, int *out) {
 int p = 0;
 int r;
 if (!cfg || !out || !cfg->a || !cfg->b || !cfg->c || !cfg->size || !cfg->kind) return 1;
 if (input->kind && input->kind != cfg->kind) return 1;
 *out = 0;
 r = func_00538BF8(&p, 0x70);
 if (r == 0) {
  F(p,0x3c) = cfg->count;
  F(p,0x40) = cfg->kind;
  F(p,0x44) = cfg->size;
  F(p,0x4c) = (int)cfg->a;
  F(p,0x50) = (int)cfg->b;
  F(p,0x54) = (int)cfg->c;
  F(p,0) = (int)func_00511050;
  F(p,4) = (int)func_005110C0;
  F(p,8) = (int)func_005110E0;
  F(p,12) = (int)func_00511118;
  F(p,16) = (int)func_00510CD0;
  F(p,20) = (int)func_005112D0;
  F(p,24) = (int)func_005113B0;
  F(p,28) = (int)func_00511528;
  F(p,36) = (int)func_00511708;
  F(p,40) = (int)func_005117F8;
  F(p,44) = (int)func_00511150;
  F(p,48) = (int)func_005119F0;
  F(p,52) = (int)func_00510E30;
  if (input->kind == 0) F(p,32) = (int)func_00510C80;
  else F(p,32) = (int)func_00511648;
  r = func_00538BF8((int *)(p + 0x48), (unsigned long)(unsigned int)(F(p,0x3c) * 8));
  if (r == 0) {
   r = func_00512120(input->id, input->kind, (int *)(p + 0x64));
   if (r == 0) {
    r = func_00538B08((int *)(p + 0x60), (unsigned long)(unsigned int)F(p,0x44));
    if (r == 0) {
     *out = p;
     return r;
    }
   }
  }
 }
 ((void (*)(int))F(p,16))(p);
 return r;
}
