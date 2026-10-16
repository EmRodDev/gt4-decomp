/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { char data[24]; };
extern "C" int func_005B72A8();
extern "C" Blob *func_001C2E90(Blob *out,char *src) {
 int disabled=func_005B72A8();
 Blob b=*(Blob *)(src+0x294);
 if(disabled) { asm volatile("ei" ::: "memory"); }
 *out=b;
 return out;
}
