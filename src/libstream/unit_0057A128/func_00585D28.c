/* compiler: ee-gcc2.9-as296 */
struct Node {
 int magic0,magic4;
 struct Node *link,*next;
 char pad10[6]; unsigned short flags; char pad18[8];
 void (*fn)(int,struct Node *);
};
extern volatile struct Node *D_00875898;
void func_005ADF20(int);
int func_005B72A8(void);
int func_005B72F8(void);
int func_00585D28(struct Node *arg) {
 int intr;
 unsigned short flags;
 struct Node *old;
 if(!arg || arg->magic0!=0x4c785265 || arg->magic4!=0x41004269) return 0x81059039;
 intr=func_005B72A8();
 flags=arg->flags | 1;
 old=D_00875898;
 D_00875898=arg;
 arg->flags=flags;
 arg->link=old;
 func_005ADF20(2);
 if(intr) func_005B72F8();
 arg->fn(0,arg);
 return 0;
}
