struct S{char pad[0x30];int cap;};extern char D_006CBED0[];extern "C" void func_005B0750(const char*,...);extern "C" int func_00590FD8(S*,int,int,int,int,int,int,int,int);
extern "C" int func_0056EA50(S*self,int id,int mode,int a,int b){a=(a+63)&-64;b=(b+63)&-64;int cap=self->cap;if(cap<a||cap<b){func_005B0750(D_006CBED0,a,b,cap);return -543;}return func_00590FD8(self,id,0,mode,a,mode,b,0,0);}
