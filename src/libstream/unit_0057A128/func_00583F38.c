/* compiler: ee-gcc2.9-991111 */
struct Node { struct Node *next; unsigned int flags; unsigned int size; };
struct State { int x[3]; char *base; };
extern struct State D_00875878;
int func_005B72A8(void);
int func_005B72F8(void);
int func_00583F38(int *total,int *largest) {
 unsigned int sum=0,max=0;
 struct State *state=&D_00875878;
 struct Node *p;
 int intr;
 if(!state->base) return 0x81058001;
 intr=func_005B72A8();
 p=(struct Node *)(state->base+4);
 while(p) {
 if(!(p->flags&1)) {
 unsigned int n=p->size>>1;
 sum+=n;
 if(max<n) max=n;
 }
 p=p->next;
 }
 if(intr) func_005B72F8();
 if(total) *total=sum<<8;
 if(largest) *largest=max<<8;
 return 0;
}
