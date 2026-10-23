/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Object;

struct Ref {
    Object *p;
    Object *operator->() { return p; }
};

struct Object {
    int refCount;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual float toFloat();
    virtual void v12();
    virtual Ref &at(int index);
};

struct Widget {
    float getX() __asm__("func_00238F78");
    void setX(float x) __asm__("func_00238F80");
    float getY() __asm__("func_00238F90");
    void setY(float y) __asm__("func_00238F98");
};

struct WidgetRef {
    Widget *p;
    WidgetRef(void *src) throw() __asm__("func_002366D8");
    WidgetRef(const WidgetRef &);
    ~WidgetRef() throw() __asm__("func_00236680");
    Widget *operator->() { return p; }
};

struct Value {
    Object *p;
    Value(float f) __asm__("func_002F9360");
    Value(const Value &);
    ~Value() __asm__("func_002F7B68");
};

struct Result {
    Object *p;
    Result(const Result &);
    ~Result() __asm__("func_00309378");
};

struct Array : Object {
    Result push(const Value &v) __asm__("func_002EEEB0");
};

extern "C" void func_003285A8(Array *p);
extern "C" void func_003285F8(Array *p);

struct List {
    Array *p;
    List() __asm__("func_002EFBF0");
    List(void *src) __asm__("func_002ED618");
    List(const List &) __asm__("func_00309360");
    ~List() __asm__("func_002ED5C0");
    Array *operator->() { return p; }
    List &operator=(const List &o) {
        if (this != &o) {
            Array *q = o.p;
            if (q)
                func_003285A8(q);
            if (p)
                func_003285F8(p);
            p = q;
        }
        return *this;
    }
};

extern "C" void MScaleBar__get_range(List *out, void *widget, int direction, void *other) {
    if (direction > 0) {
        WidgetRef w(widget);
        List in(other);
        w->setX(in->at(0)->toFloat());
        w->setY(in->at(1)->toFloat());
        return;
    }
    WidgetRef w(widget);
    List list;
    list->push(Value(w->getX()));
    list->push(Value(w->getY()));
    *out = list;
}
