/* Answers whether the selection can step down (name from GT HD): false when func_0057CE80 on the member at +0xBC returns true,
 * otherwise true exactly when the float at +0xEC is negative. Twin of mSelectBox::canDecrement; the meaning of the tests is unknown. */
struct Obj;
extern "C" bool func_0057CE80(Obj *member);

struct SelectBar {
    char pad[0xEC];
    float unkEC;
};

extern "C" int mSelectBar__canDecrement(void *obj) {
    SelectBar *self = (SelectBar *)obj;
    int result;

    if (func_0057CE80((Obj *)((char *)obj + 0xBC))) {
        return 0;
    }
    result = 1;
    if (!(self->unkEC < 0.0f)) {
        result = 0;
    }
    return result;
}
