extern "C" int func_0056EAD0(void *,int *,int,int,int) throw();
extern "C" int func_0056EA50(void *,int,int *,int,int) throw();
static inline int send(void *s,int *p,int value,int dest,int size,int *option,int extra) {
    p[0]=value;
    if(option) p[1]=*option; else p[1]=0;
    p[2]=size;
    p[3]=extra;
    return func_0056EAD0(s,p,4,dest,size);
}
extern "C" int func_0056F250(void *s,int *p,int value,int dest,int size,int *option,int extra) {
    int r=send(s,p,value,dest,size,option,extra);
    if(r<0) return r;
    if(func_0056EA50(s,5,p,size+16,8)<0) return -542;
    if(option) *option=p[1];
    return p[0];
}
