/* Looks up an object from a handle (func_002405A8), and only if it exists and its vtable slot at +0x198 (a boolean check, inferred from its use as a
 * condition) accepts it, passes it with the other two arguments to func_0018FDD8; returns 0 otherwise. The handle is always released (mode 2). */
struct VEntry{short delta,index;int(*fn)(void*);};
struct Obj{int m0;VEntry*vt;};
struct Handle{Obj*p;char pad[12];};
extern "C" void func_002405A8(void*,void*);
extern "C" void func_002403C8(void*,int);
extern "C" int func_0018FDD8(void*,Obj*,void*);
static inline int valid(Obj*obj){VEntry*e=(VEntry*)((char*)obj->vt+0x198);return e->fn((char*)obj+e->delta);}
extern "C" int func_0018FF68(void*self,void*handleSource,void*extra){Handle handle;func_002405A8(&handle,handleSource);
if(handle.p==0){func_002403C8(&handle,2);return 0;}if(!valid(handle.p)){func_002403C8(&handle,2);return 0;}int result=func_0018FDD8(self,handle.p,extra);func_002403C8(&handle,2);return result;}
