extern "C" int func_0056EA50(void*,int,int*,int,int) throw();
extern "C" int func_0056FBD8(void*self,int*src,int*dst,int n,int id)
{
 if(func_0056EA50(self,id,src,0,n*4+4)<0)return -542;
 for(int i=0;i<n;i++)dst[i]=src[i+1];
 return src[0];
}
