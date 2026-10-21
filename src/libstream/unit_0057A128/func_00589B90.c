/* compiler: ee-gcc2.9-991111 */
int func_005B31F8(int,int,int);
int func_005B9548(void *,int);
int __attribute__((register_precision ($16, 128))) func_00589B90(int unused, int fd) {
 int size = func_005B31F8(fd,0,2);
 if (size < 0) return func_005B9548(0,size);
 func_005B31F8(fd,0,0);
 return size;
}
