extern char *D_0064C3E4;
extern "C" void func_00576788(char *);
extern "C" void func_005767C0(char *);
extern "C" int func_0054A370(int) throw();
extern "C" int func_0054A8A8(int,int) throw() __attribute__((const));
extern "C" void func_00549858(char *,int,int) throw();
extern "C" int func_00562330(int,int,char *,int);
extern "C" int func_005624E8(int,int,int);
extern "C" int func_005623C8(int,void *,int);
extern "C" int func_00561E00(int);
extern "C" int func_0054B698(int id,char *name,void *buf,int off,int size) {
 int error=1;
 func_00576788(D_0064C3E4+0x34);
 int result=-1;
 if(func_0054A370(id)) {
  int negative;
  int r=func_00562330(id/4,id%4,name,1);
  if(id<0) negative=1; else negative=0;
  error=10;
  int fd=r;
  if(r>=0) {
   error=13;
   if(off==0 || (r=func_005624E8(fd,off,0))==off) {
    error=11;
    r=func_005623C8(fd,buf,size);
    if(r>=0) {
     result=r;
     r=func_00561E00(fd);
     error=(r==0)?0:4;
    }
   }
  }
  error=func_0054A8A8(error,r);
  int q=id;
  if(negative) q=(id+3);
  q >>= 2;
  int offset=(q*111+(id-q*4)*27)*4;
  func_00549858((char *)(offset+(int)D_0064C3E4+0x78),r,error);
  offset+=(int)D_0064C3E4;
  *(char *)(offset+0x78)=0;
 }
 int offset=((id/4)*111+(id%4)*27)*4;
 *(int *)(offset+(int)D_0064C3E4+0xc0)=result;
 func_005767C0(D_0064C3E4+0x34);
 return error==0 ? result : -error;
}
