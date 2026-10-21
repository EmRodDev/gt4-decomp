/* compiler: ee-gcc2.9-991111 */
struct Node { struct Node *next; const char *name; int x,id; };
struct Root { char pad[24]; struct Node *head; };
extern int D_00657A80;
int func_0057F238(const char *,const char *);
struct Root *func_0058B198(int);
int func_005B72A8(void);
int func_005B72F8(void);
int func_00585560(const char *name,int *out,int max,int *total) {
 int count,intr,n;
 struct Node *p;
 if(!D_00657A80) return (int)0x81058001;
 count=0;
 intr=func_005B72A8();
 p=func_0058B198(0)->head;
 n=0;
 while(p) {
  if(!name || func_0057F238(name,p->name)==0) {
   n++;
   if(count<max) { *out++=p->id; count++; }
  }
  p=p->next;
 }
 if(intr) func_005B72F8();
 if(total) *total=n;
 return count;
}
