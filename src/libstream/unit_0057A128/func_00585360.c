/* compiler: ee-gcc2.9-991111 */
struct Node { unsigned int next; int x,y,id; };
struct State { char pad[24]; unsigned int head; int count; volatile int serial; };
extern struct State D_00875898;
int func_005B72A8(void);
int func_005B72F8(void);
void func_00585360(struct Node *n) {
 int intr=func_005B72A8();
 unsigned int *p=&D_00875898.head;
 struct Node *cur;
 if(*p) {
  cur=(struct Node *)*p;
  while(cur && cur<n) {
   p=&cur->next;
   cur=(struct Node *)*p;
  }
 } else cur=0;
 n->next=(unsigned int)cur;
 *p=(unsigned int)n;
 { int serial=D_00875898.serial;
 n->id=serial;
 D_00875898.serial=serial+1; }
 D_00875898.count++;
 if(intr) func_005B72F8();
}
