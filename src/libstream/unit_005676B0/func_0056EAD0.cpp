struct Obj { char pad[0x30]; int size; };
extern "C" void func_005A4724(void *, const void *, unsigned);
extern "C" int func_0056EAD0(Obj *arg0, int arg1, int arg2, const void *arg3, int arg4) {
 int off = arg2 * 4;
 int avail = arg0->size - off;
 if (!arg3) return 0;
 if (arg4 < 0 || avail < arg4) return -0x21F;
 func_005A4724((void *)(off+arg1),arg3,arg4);
 return 0;
}
