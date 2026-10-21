/* compiler: ee-gcc2.9-991111 */
struct Node {struct Node *next;};
extern struct Node *D_00875884;
int func_005B72A8(void);
int func_005B72F8(void);
int func_00584F18(struct Node *);
void func_005850C0(void);
int func_00584488(struct Node *p) {
 int intr=func_005B72A8();
 struct Node *n;
 int result;
 for(n=D_00875884;n;n=n->next) {
 if(p==n) {
 if(intr) func_005B72F8();
 return -1;
 }
 }
 result=func_00584F18(p);
 if(result==0) func_005850C0();
 else result=0x8105000E;
 if(intr) func_005B72F8();
 return result;
}
