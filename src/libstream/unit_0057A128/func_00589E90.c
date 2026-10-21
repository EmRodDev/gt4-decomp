/* compiler: ee-gcc2.9-991111 */
struct Ops {
 char pad[28];
 int (*close)(int);
 int (*unused)(void);
 int (*seek)(int,int,int);
 int (*sync)(int,int,int *);
 int (*error)(int,int);
};
extern struct Ops D_0087E1C0;
int __attribute__((register_precision ($16, 128))) func_00589E90(int unused, int fd) {
 int result, r;
 do { result = D_0087E1C0.close(fd); } while (result < 0);
 D_0087E1C0.sync(0,0,&result);
 r = 0;
 if (result < 0) { result = D_0087E1C0.error(3,result); return result; }
 return r;
}
