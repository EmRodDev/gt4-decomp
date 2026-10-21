/* Walks an array of 20-byte elements (start pointer and element count stored at +4 and +8 of the object) and calls func_0047EF90
 * on each element with the extra argument passed through. The loop compares against the end pointer computed first, like an
 * STL-style for_each over [begin, begin + count). */
struct Sub0047EE50 {
    char *base;
    int count;
};
struct Obj0047EE50 {
    int unk0;
    struct Sub0047EE50 sub;
};
extern "C" void func_0047EF90(char *element, void *arg);

extern "C" void func_0047EE50(struct Obj0047EE50 *self, void *arg) {
    struct Sub0047EE50 *array = &self->sub;
    char *end = array->base + array->count * 20;
    char *element = array->base;

    while (element != end) {
        func_0047EF90(element, arg);
        element += 20;
    }
}
