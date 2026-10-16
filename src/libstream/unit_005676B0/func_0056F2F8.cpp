extern "C" int func_0056EAD0(void *,int *,int,int,int) throw();
extern "C" int func_0056EA50(void *,int,int *,int,int) throw();
extern "C" int func_0056F2F8(void *s,int *p,int value,int dest,int size,int *option,int name,int extra,int last) {
    p[0]=value;
    if(option) p[1]=*option; else p[1]=0;
    p[2]=size;
    p[3]=last;
    p[4]=extra;
    int r=func_0056EAD0(s,p,5,name,16);
    if(r>=0) {
        r=func_0056EAD0(s,p,9,dest,size);
        if(r>=0) {
            if(func_0056EA50(s,14,p,size+36,8)<0) return -542;
            if(option) *option=p[1];
            r=p[0];
        }
    }
    return r;
}
