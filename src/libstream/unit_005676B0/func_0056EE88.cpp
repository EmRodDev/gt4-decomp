struct B { int flag, size, x, y; int pad[4]; int extra; };
extern "C" int func_0056EAD0(void *,B *,int,const char *,int) throw();
extern "C" int func_0056EA50(void *,int,B *,int,int) throw();
extern "C" int func_0056EC10(void *,int,B *,int) throw();
extern "C" int func_0056EE88(void *s,B *b,int flag,int id,int size,const char *name,int x,int y,...) {
    b->x=x;
    b->y=y;
    b->extra=0;
    b->flag=flag;
    b->size=size;
    if(flag&0x80) {
        char *ap=(char *)__builtin_next_arg(y)-((8-__builtin_args_info(2))*8);
        b->extra=*(int *)ap;
    }
    int r=func_0056EAD0(s,b,4,name,16);
    if(r>=0) {
        if(func_0056EA50(s,0x12,b,0x24,size+0x20)<0) return -0x21e;
        r=func_0056EC10(s,id,b,8);
        if(r>=0) r=b->flag;
        return r;
    }
    return r;
}
