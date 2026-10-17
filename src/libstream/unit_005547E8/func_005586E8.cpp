/* compiler: ee-gcc2.96-no-strict-aliasing */
struct SceneData {
    char data[0x79C];
};

struct Scene : SceneData {
    virtual ~Scene();
};

extern "C" {
extern int D_0064D260;
extern int D_0064D25C;
extern int D_0064D258;
extern int D_0064D254;
extern Scene *D_00873560;
void func_00578500(int);
void func_00558558(Scene *);
void func_00578908(int);
void func_00578AF0(int);
void func_00558438(Scene *);
void func_00578480(int);
void func_005783A0(int);

void func_005586E8(void)
{
    if (D_0064D260) {
        func_00578500(D_0064D25C);
        func_00558558(D_00873560);
        func_00578908(D_0064D258);
        func_00578AF0(D_0064D258);
        func_00558438(D_00873560);
        func_00578908(D_0064D254);
        func_00578AF0(D_0064D254);
        func_00578480(D_0064D25C);
        func_005783A0(D_0064D25C);
        delete D_00873560;
        D_00873560 = 0;
        D_0064D260 = 0;
    }
}
}
