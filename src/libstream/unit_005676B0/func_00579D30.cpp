/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00576AD8(void *,int);
extern "C" int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
extern "C" int func_00579D30(void *s,int id,int mode,void *a,int size,void *b,int n,void *c,void *d) {
    if(a) {
        size=(size+15)&~15;
        func_00576AD8(a,size);
    }
    if(b) func_00576AD8(b,n);
    return func_005B19B0(s,id,mode|2,a,size,b,n,c,d);
}
