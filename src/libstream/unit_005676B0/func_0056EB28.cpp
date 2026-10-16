struct Obj { char pad[0x30]; int size; };
extern "C" void func_005A4724(void *,const void *,unsigned);
extern "C" int func_0056EB28(Obj *arg0,void *arg1,int arg2,int arg3,int arg4) {
 int off = arg3 * 4;
 int avail = arg0->size - off;
 if (!arg1) return 0;
 if (arg4 < 0 || avail < arg4) return -0x21F;
 func_005A4724(arg1,(void *)(off+arg2),arg4);
 return 0;
}
