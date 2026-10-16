struct Node { int value; Node *next; };
struct Queue;
extern "C" Node *func_0052DD60(Queue *) throw();
static inline Node *next(Node *n) { return n ? n->next : 0; }
extern "C" int func_0052E300(Queue *q,Node *target,Node **out) {
 if(!target) return 2;
 if(!out) return 2;
 *out=0;
 Node *n=func_0052DD60(q);
 if(n) {
 if(n->next) {
 do {
  if(n) {
   if(n->next!=target) goto advance;
  } else {
   if(target) goto advance;
  }
  *out=n;
  return 0;
advance:
  n=next(n);
 } while(n && n->next);
 }
 }
 return 300;
}
