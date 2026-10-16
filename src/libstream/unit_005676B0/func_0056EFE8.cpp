extern "C" int func_0056EA50(void*,int,int*,int,int);
extern "C" int func_0056EFE8(void* self,int* buffer,int a,int b) {
 buffer[0]=a;buffer[1]=b;
 if(func_0056EA50(self,2,buffer,8,4)<0)return -542;
 return buffer[0];
}
