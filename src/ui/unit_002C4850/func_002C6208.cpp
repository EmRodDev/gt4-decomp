/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { int p; char *v[4]; int rest[4]; };
struct T { char pad[0x34]; int a,b,c,d,e,pad2; E *arr; };
extern char D_0069C668[];
extern "C" char *func_002C6208(T *self,int i,int j,int k){
 E *e=self->arr+(self->b*self->d*self->a+self->d*i+j);
 char **field=&e->v[k];
 char *p=*field;
 int len=*(int*)(p-0x10);
 if(len==0) return D_0069C668;
 p[len]=0;
 return *field;
}
