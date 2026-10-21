/* Same as func_0018FF68 but forwards to func_00190008: handle lookup, vtable +0x198 check (a boolean, inferred from its use as a condition),
 * then the real work; returns 0 when the object is missing or refused. */
struct VEntry{short delta,index;int(*fn)(void*);};
struct Obj{int m0;VEntry*vt;};
struct Handle{Obj*p;char pad[12];};
extern "C" void func_002405A8(void*,void*);
extern "C" void func_002403C8(void*,int);
extern "C" int func_00190008(void*,Obj*,void*);
static inline int valid(Obj*obj){VEntry*e=(VEntry*)((char*)obj->vt+0x198);return e->fn((char*)obj+e->delta);}
extern "C" int func_001900E0(void*self,void*handleSource,void*extra){Handle handle;func_002405A8(&handle,handleSource);
if(handle.p==0){func_002403C8(&handle,2);return 0;}if(!valid(handle.p)){func_002403C8(&handle,2);return 0;}int result=func_00190008(self,handle.p,extra);func_002403C8(&handle,2);return result;}
