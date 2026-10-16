struct S{char pad[0x30];int a30;int a34;int a38;int a3c;};
extern "C" int D_0065534C;
extern "C" int D_00654D7C;
extern "C" int D_00654D74;
extern "C" int D_00654D70;
extern "C" int D_00654DA0;
extern "C" void func_00568A38(int,int,int,int,int,int);
extern "C" void func_00569848(int,int,int,int);
extern "C" int func_00569EB8(int,int,int,int);
extern "C" int func_00568940(S*s0,int a1,int a2,int a3){
 int s1 = a2 * 16;
 int s2 = a3 * 16;
 int s4 = 0;
 func_00569848(D_0065534C, D_00654D7C, s1, s2);
 if ((a1 & 8) || D_00654DA0 == 2) {
  s4 = 1;
  func_00568A38(D_00654D74, s1, s2, s0->a30, s0->a34, 0);
 }
 if (a1 & 4)
  func_00568A38(D_00654D70, s1, s2, s0->a38, s0->a3c, s4);
 return func_00569EB8(D_0065534C, D_00654D7C, s1, s2);
}
