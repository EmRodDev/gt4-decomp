/* compiler: ee-gcc2.9-991111 */
struct Ops { char pad[36]; int (*seek)(int,int,int); int (*sync)(int,int,int *); int (*error)(int,int); };
extern struct Ops D_0087E1C0;
int __attribute__((register_precision ($16, 128))) func_00589FD0(int unused,int a,int b,int c) {
 int result, r;
 do { result = D_0087E1C0.seek(a,b,c); } while (result < 0);
 D_0087E1C0.sync(0,0,&result);
 r = result;
 if (result < 0) { result = D_0087E1C0.error(4,result); return result; }
 return r;
}
