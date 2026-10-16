struct Obj { unsigned char active; char pad[3]; int count; int key; };
extern "C" int func_00539BE0(int *);
extern "C" int func_00539B40(Obj *, unsigned char *);
extern "C" int func_005398C0(Obj *self, int *out) {
 unsigned char flag = 0;
 int key;
 int r;

 if (!self) return 2;
 if (self->active != 1) return 2;
 if (!out) return 2;
 *out = 0;
 r = func_00539BE0(&key);
 if (r) return r;
 int old = self->count;
 if (old && key == self->key) { r = old + 1; self->count = r; *out = r; goto end; }
 r = func_00539B40(self,&flag);
 if (r) return r;
 if (flag != 1) { goto end; }
 r = func_00539BE0(&self->key);
 if (r) return r;
 r = self->count + 1;
 self->count = r;
 *out = r;
end:
 return 0;
}
