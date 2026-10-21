/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void (*fn)(void *, int); };
struct V { Entry *vt; int x[2]; };
struct H { int x[2]; };
struct Node { Node *next; H *value; };
extern char D_0064C6E0[], D_0064C520[], D_0064C590[], D_0064C4C8[], D_0064C4D8[];
extern char D_00654DF8[];
extern V D_0064C6F8[2];
extern int D_0064C6F0[2];
extern H D_0086F7E0[2];
extern Node D_0086F7F0[2];
extern Node *D_00654A44;
extern "C" void func_0055FC10(void *, void *, void *, void *, void *);
extern "C" int func_00560198(V *, void *, void *);
extern "C" void func_0055F3A8(H *, int, V *);
extern "C" void func_0055F3B8(H *, int);
extern "C" void func_0055FC80(void *, int);
static inline void reg(Node *self, H *v) { self->next = D_00654A44; self->value = v; D_00654A44 = self; }
extern "C" void func_005508A0(int init, int prio) {
 if (prio == 65535 && init == 1) func_0055FC10(D_0064C6E0,D_0064C520,D_0064C590,D_0064C4C8,D_0064C4D8);
 if (prio == 65535 && init == 1) {
  func_00560198(D_0064C6F8,D_00654DF8,D_0064C6E0);
  func_00560198(D_0064C6F8+1,D_00654DF8+20,D_0064C6E0);
 }
 if (prio == 65535 && init == 1) {
  func_0055F3A8(D_0086F7E0,D_0064C6F0[0],D_0064C6F8);
  func_0055F3A8(D_0086F7E0+1,D_0064C6F0[1],D_0064C6F8+1);
 }
 if (prio == 65535 && init == 1) {
  Node *nodes = D_0086F7F0;
  Node *n = nodes;
  reg(n, &D_0086F7E0[0]);
  n++;
  reg(n, &D_0086F7E0[1]);
 }
 if (prio == 65535 && init == 0) {
  if (D_0086F7E0) { H *q=D_0086F7E0+2; while (q!=D_0086F7E0) { --q; func_0055F3B8(q,2); } }
 }
 if (prio == 65535 && init == 0) {
  if (D_0064C6F8) { V *q=D_0064C6F8+2; while (q!=D_0064C6F8) { --q; Entry *e=q->vt+1; e->fn((char *)q+e->delta,2); } }
 }
 if (prio == 65535 && init == 0) func_0055FC80(D_0064C6E0,2);
}
