/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { char pad[0x10]; int handle; char pad14[0x18]; char data[0x18]; };
struct Global { char pad[0x110]; Record *records; };
extern Global D_00854038;
extern "C" void func_00531738(int *);
extern "C" int func_00538068(void *);
extern "C" int func_00518C80() {
 if (!D_00854038.records) return 0;
 for (unsigned int i=0; i<0x200; ++i) {
  if (D_00854038.records[i].handle)
   func_00531738(&D_00854038.records[i].handle);
  int p = (int)(D_00854038.records + i);
  if (p != -0x2c) func_00538068((void *)(p + 0x2c));
 }
 return 0;
}
