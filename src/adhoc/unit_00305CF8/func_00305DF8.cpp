/* compiler: ee-gcc2.96-stl */
#include <stl_tree.h>
typedef int s32;
typedef pair<const unsigned int, s32> Value;
typedef _Rb_tree_node<Value> Node;
typedef _Rb_tree_iterator<Value, const Value&, const Value*> It;
extern s32 D_0083EF28;
extern "C" void hModule__findModuleValue(void *, void *, const void *);
extern "C" void func_003062B0(void *, const void *, const void *);
extern "C" It func_003065D8(const void *);
extern "C" It func_003065E8(const void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_00323D08(void *);
struct Handle { s32 p; Handle() { func_00323D08(this); } Handle(const Handle &); ~Handle() { func_00323B60(this, 2); } bool isNull() const { return p == 0; } };
extern "C" void func_00305DF8(void *arg0, void **arg1, s32 *arg2) {
    if (*arg2 == D_0083EF28) {
        const void *m = *arg1;
        for (It it = func_003065D8(m); it != func_003065E8(m); it++) {
            func_003062B0(arg0, &(*it).first, &(*it).second);
        }
        return;
    }
    Handle buf;
    hModule__findModuleValue(*arg1, &buf, arg2);
    if (!buf.isNull())
        func_003062B0(arg0, arg2, &buf);

}
