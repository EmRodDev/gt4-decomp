extern "C" int func_0056EA50(void*,int,void*,int,int);
struct Request {int value;int option;};
extern "C" int func_0056F030(void*self,Request*request,int value,int option){request->value=value;request->option=option;if(func_0056EA50(self,3,request,8,4)<0)return -542;return request->value;}
