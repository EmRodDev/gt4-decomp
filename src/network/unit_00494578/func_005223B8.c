/* compiler: ee-gcc2.9-991111 */
/* Thin wrapper: passes its 8-byte value (two words, by value) straight on to func_00522510 together
   with the object pointer. Purpose of the value unknown. */
struct Value { int words[2]; };
extern int func_00522510(void *, struct Value);
void func_005223B8(void *self, struct Value value) {
    func_00522510(self, value);
}
