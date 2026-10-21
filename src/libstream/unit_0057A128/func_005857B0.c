/* compiler: ee-gcc2.9-991111 */
struct Module { struct Module *next; char *name; unsigned short version, attribute; int id; };
struct ErxInfo { char pad[0x18]; struct Module *modules; };
struct ErxInfo *func_0058B198(int);
int func_005B72A8(void);
int func_005B72F8(void);
int func_005857B0(int id,int flags) {
 int err=0;
 int intr;
 struct Module *m;
 if(flags & ~0x40) { flags &= 0x40; err=0x81050016; }
 intr=func_005B72A8();
 for(m=func_0058B198(0)->modules;m;m=m->next) {
 if(id != m->id) continue;
 m->attribute |= flags;
 break;
 }
 if(intr) func_005B72F8();
 return m ? err : 0x8105902D;
}
