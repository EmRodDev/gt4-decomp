/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Root { virtual ~Root(); };
struct Base : Root {
    virtual ~Base();
    char pad[0xC40 - 4];
    Base() __asm__("func_003721D8");
};
struct DevelopCamera : Base {
    int fC40;
    const int fC44;
    DevelopCamera(int) __asm__("func_005FD9F0");
    virtual ~DevelopCamera();
};
DevelopCamera::DevelopCamera(int a) : Base(), fC40(0), fC44(a) {}
