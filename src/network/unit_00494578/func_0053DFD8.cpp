/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Allocates a 0x50-byte control block plus a 0x2E7C-byte buffer (func_00538BF8, returns 2 when out is null or arg1 is 0, or the allocator's error), runs the callback D_0064B4B0+0x40 on the block at +4, and on success stores arg2 at +0x14, arg1 at +0 and the block into *out. On any failure the allocations are released again (func_00538C68). The goto success label is the compiler-forced layout of the error path. Block purpose not determined. */
struct Blk { int f0; char pad[0x10]; int f14; char rest[0x2c]; int f44; };
struct Obj { char pad[0x40]; int (*f40)(void *); };
extern Obj *D_0064B4B0;
extern "C" int func_00538BF8(void *, int) throw();
extern "C" int func_00538C68(void *) throw();
extern "C" int func_0053DFD8(Blk **result,int first,int second) {
 int status=2;
 Blk *block=0;
 int secondStatus;
 if(result==0) return status;
 *result=0;
 if(first==0) return status;
 status=func_00538BF8(&block,0x50);
 if(status) return status;
 secondStatus=func_00538BF8(&block->f44,0x2e7c);
 if(secondStatus!=0) {
  func_00538C68(&block);
  return secondStatus;
 }
 {
  status=D_0064B4B0->f40((char *)block+4);
  secondStatus=status;
  if(secondStatus==0) goto success;
  func_00538C68(&block->f44);
 }
 func_00538C68(&block);
 return secondStatus;
success:
 block->f14=second;
 block->f0=first;
 *result=block;
 return status;
}
