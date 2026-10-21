/* compiler: ee-gcc2.9-991111 */
extern int D_00658354;
struct Buf { void *addr; char name[252]; };
extern struct Buf D_00889B80;
extern char D_00889AC0[];
extern int D_00889B00;
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_005B5F28(const char *name, void *addr) {
 int i, r;
 if (D_00658354 < 0) return 0;
 for (i=0; i<252 && (D_00889B80.name[i]=name[i]); i++);
 if (i==252) { D_00889B80.name[251]=0; i=251; }
 D_00889B80.addr=addr;
 D_00889B80.name[251]=0;
 r=func_005B19B0(D_00889AC0,3,0,&D_00889B80,i+5,&D_00889B00,4,0,0);
 if (r<0) return -1;
 return D_00889B00;
}
