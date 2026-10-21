/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Bytes { char b[4]; };
extern "C" unsigned func_005389D8(signed char*);
extern "C" int func_00505A30(Bytes *out,signed char *text) {
 int result;
 if(!text) result=-6;
 else if(!out) result=-6;
 else {
  unsigned value=func_005389D8(text);
  *out=*(Bytes*)&value;
  return 0;
 }
 return -6;
}
