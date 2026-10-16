struct B { int flag, x, y, extra, size; };
extern "C" int func_0056EA50(void *,int,B *,int,int) throw();
extern "C" int func_0056EB28(void *,int,B *,int,int) throw();
extern "C" int func_0056EB80(void *,B *,int,const char *) throw();
extern "C" int func_0056ECF8(void *s,B *b,int flag,int id,const char *name,int x,int y,...) {
    char *ap;
    b->x=x;
    b->y=y;
    b->extra=0;
    b->flag=flag;
    if(flag&0x80) {
      ap=(char *)__builtin_next_arg(y)-((8-__builtin_args_info(2))*8);
      int extra=*(int *)ap;
      b->extra=extra;
    }
    int r=func_0056EB80(s,b,5,name);
    if(r>=0) {
        b->size=r;
        if(func_0056EA50(s,6,b,r+0x14,0x14)<0) return -0x21e;
        int result=func_0056EB28(s,id,b,1,0x10);
        if(result>=0) result=b->flag;
        return result;
    }
    return r;
}
