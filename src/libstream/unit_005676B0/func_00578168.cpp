struct S{int x;char pad[0x28];int a,b,flag;};
extern "C" void func_00577F80();extern "C" void func_00578480(int);
extern "C" void func_005780F8();
extern "C" int func_00579D30(void*,int,int,int,int,int,int,void(*)(),S*);
extern "C" int func_00578168(S*self,int a,int b,int c,int d){self->flag=b&1;while(func_00579D30((char*)self+4,a,b,self->a,self->b,c,d,func_005780F8,self))func_00577F80();if(!self->flag)func_00578480(self->x);return 0;}
