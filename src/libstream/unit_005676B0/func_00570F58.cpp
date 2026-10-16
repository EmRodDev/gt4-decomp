typedef unsigned int u32;
struct Copy { int x[4]; };
struct Entry {
 int a0, busy, size; u32 len;
 Copy meta;
 int a20, a24, a28, a2c;
 char pad30[12]; int a3c;
};
struct Ring { char pad[0x18]; int limit; char *base; int a20; char pad24[24]; int pos; };
struct Obj { char pad[0x20]; Ring *ring; };
extern "C" int func_00570EC0(int,int,int) throw();
extern "C" int func_00571798(Ring *,int,int,unsigned char *);
extern "C" void *func_005A4724(void *,const void *,unsigned);
extern "C" void func_005ADF20(int);
extern "C" int func_00570F58(Obj *arg0,void *arg1,int arg2,int *arg3,Copy *arg4,int *arg5,int *arg6,int *arg7) {
 int r = 2;
 unsigned char ready = 0;
 if (!arg6) return r;
 *arg6 = 0;
 if (!arg1) return r;
 if (arg2 <= 0) return r;
 if (!arg3) return r;
 *arg3 = 0;
 if (!arg4) return r;
 if (!arg5) return r;
 if (!arg7) return r;
 *arg7 = 0;
 if (!arg0) return r;
 Ring *ring = arg0->ring;
 if (!ring) return r;
      func_005ADF20(0);
      r = func_00571798(ring,1,0,&ready);
      if (r == 0) {
       if (!ready) {
        *arg6 = 0;
        *arg3 = 0;
        *arg7 = 0;
        return r;
       } else {
        Entry *entry = (Entry *)(ring->base + ring->pos);
        int busy = entry->busy != 0;
        if (!busy) {
         int n = entry->len < (u32)arg2 ? entry->len : arg2;
         if (n) func_005A4724(arg1,(char *)entry + 0x40,n);
         *arg4 = entry->meta;
         *arg3 = entry->a24;
         *arg5 = entry->a20;
         *arg6 = n;
         *arg7 = entry->a28;
        }
        entry->a0 = 0;
        entry->len = entry->size;
        entry->a3c = 0;
        entry->busy = 0;
        r = func_00570EC0((int)entry,entry->a2c,0x40);
        if (r == 0) {
         int pos = ring->pos + entry->size + 0x40;
         ring->pos = pos;
         if (pos >= ring->limit) ring->pos = 0;
         if (busy != 1 || (r = func_00570F58(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7)) == 0) r = 0;
        }
        return r;
       }
      }
 return r;
}
