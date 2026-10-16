/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x30]; void (*handler)(Obj *); int handlerArg; };
struct Node { Obj *object; Node *prev; Node *next; };
struct List { Node *head; Node *tail; };
struct Pool { char pad[0x10]; char mutex[0x98]; List list; };
extern Pool D_0084B480;
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_0057CB80(List *, Node *);
extern "C" void func_004AC5D0(Obj *) throw();
extern "C" void func_004AC758(Obj *);
static inline Obj *pop(List *list) {
 Obj *result=0;
 Node *node=list->head;
 if(node) {
  func_0057CB80(list,node);
  result=node->object;
 }
 return result;
}
static inline Obj *allocate(Pool *pool) {
 func_00576788(pool->mutex);
 Obj *result=pop(&pool->list);
 func_005767C0(pool->mutex);
 return result;
}
extern "C" Obj *func_004AC660() {
 Obj *result=allocate(&D_0084B480);
 if(result) {
  func_004AC5D0(result);
  result->handlerArg=0;
  result->handler=func_004AC758;
 }
 return result;
}
