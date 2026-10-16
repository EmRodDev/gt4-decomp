/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { void *obj; int pad; Node *next; };
extern volatile int D_00631878;
extern Node *D_006318B0;
extern "C" void func_004AD7B0(void *);
extern "C" void func_004B07F8();
extern "C" void func_00577F80();
extern "C" void func_004ACD08() {
    if (D_00631878 == 0) return func_00577F80();
    Node *node = D_006318B0;
    while (node) {
        func_004AD7B0(node->obj);
        node = node->next;
    }
    func_004B07F8();
    D_00631878 = 0;
}
