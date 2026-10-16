extern "C" int func_00525648(int, int) throw() __attribute__((const));
extern "C" int func_00529FD0(int, int, void *);
extern "C" void func_0053A860(void *);
extern "C" void func_0053A890(void *, unsigned *);
struct Entry { const void *p; int len; };
struct Buffer {
 Entry entries[8];
 int size, count;
 void init() { count = 0; size = 0; }
 void append(const void *p) {
  entries[count].p = p; entries[count].len = 2;
  size += 2; ++count;
 }
};
extern "C" int func_005273B8(char *self) {
 if (*(int *)(self + 0xB4) && *(unsigned *)(self + 0xA0) < 10) {
  char *timer = self + 0xA4;
  Buffer buffer;
  unsigned time;
  short value;
  func_0053A890(timer, &time);
  if (time >= 501) {
   value = func_00525648(4, 2);
   buffer.init();
   buffer.append(&value);
   func_00529FD0(*(int *)self, 0, &buffer);
   (*(unsigned *)(self + 0xA0))++;
   func_0053A860(timer);
  }
 }
 return 0;
}
