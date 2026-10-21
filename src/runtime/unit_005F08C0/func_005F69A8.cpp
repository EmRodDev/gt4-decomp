/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Value {
    int type;
    bool isGe() const { return type >= 3; }
};
extern "C" int func_005F69A8(int arg0) {
    Value value;
    value.type = arg0;
    return value.isGe() && arg0 < 19;
}
