/* compiler: ee-gcc2.96-nogcse */
#define A(p,o,i) (((struct Array##o *)(p))->value[i])
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define I(p,o) (*(int *)((char *)(p)+(o)))
struct State { char pad[0x9684]; int state[6]; };
struct Vec { float x,y,z; };
struct Pos { char pad[0x8f90]; float v[6][3]; };
struct Rot { char pad[0x8f40]; float v[6][3]; };
struct Pos2 { char pad[0x90f0]; float v[6][3]; };
struct Array0x8f30 { char pad[0x8f30]; float value[128]; };
struct Array0x90fc { char pad[0x90fc]; float value[128]; };
struct Array0x8f90 { char pad[0x8f90]; float value[128]; };
struct Array0x8f94 { char pad[0x8f94]; float value[128]; };
struct Array0x8f98 { char pad[0x8f98]; float value[128]; };
struct Array0x8f44 { char pad[0x8f44]; float value[128]; };
struct Array0x8f40 { char pad[0x8f40]; float value[128]; };
struct Array0x8f48 { char pad[0x8f48]; float value[128]; };
struct Array0x8fd0 { char pad[0x8fd0]; float value[128]; };
struct Array0x9030 { char pad[0x9030]; float value[128]; };
struct Array0x9090 { char pad[0x9090]; float value[128]; };
struct Array0x90f0 { char pad[0x90f0]; float value[128]; };
struct Array0x90f4 { char pad[0x90f4]; float value[128]; };
struct Array0x90f8 { char pad[0x90f8]; float value[128]; };
extern "C" float func_00344798(int,float);
extern "C" float func_003447F8(int,float);
extern "C" float func_00344828(int,float);
extern "C" float func_00344858(int,float);
extern "C" float func_00344888(int,float);
extern "C" float func_003448B8(int,float);
extern "C" float func_00344AA8(int,int,float);
extern "C" float func_00344B40(int,int,float);
extern "C" float func_00344C08(int,int,float);
extern "C" float func_00344CE8(int,int);
extern "C" int func_0034C190(int,int);
extern "C" int func_003CD900(int,int,int) throw();
extern "C" void func_004A7698(int);
extern "C" void func_004A7844(float,float,float);
extern "C" void func_004A7988(float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A79D8(float);
#define DEG(x) (((x)*180.0f)/0x1.91eb84p+1f)
extern "C" void func_003D1488(int self,int idx,int ctx,int mat,int side,int mode) {
    int stride=idx*4;
    int car=func_0034C190(ctx,idx);
    int wheel=func_003CD900(self,idx,side);
    int state=((struct State *)self)->state[idx];
    if ((mode==0 && state<4) || (mode==1 && state>=3)) {
        float x=func_00344798(car,0.0f);
        float y=func_003447F8(car,0.0f);
        func_004A7844(x,y,func_00344828(car,0.0f));
        if(mode==0) func_004A79B0(DEG(func_003448B8(car,0.0f)));
        else func_004A79B0(DEG(F(stride+self,0x8f30)));
        func_004A7988(DEG(func_00344858(car,0.0f)));
        func_004A79D8(DEG(-func_00344888(car,0.0f)));
        float xx=func_00344AA8(car,wheel,0.0f);
        float yy=func_00344B40(car,wheel,0.0f)-0x1.d70a3ap-2f;
        func_004A7844(xx,yy,func_00344C08(car,wheel,0.0f));
    } else if(mode==1 && state==2) {
        float x=func_00344798(car,0.0f);
        float z=func_00344828(car,0.0f);
        func_004A7844(x,A(self,0x90fc,idx*3),z);
        func_004A79B0(DEG(F(stride+self,0x8f30)));
        float xx=func_00344AA8(car,wheel,0.0f);
        func_004A7844(xx,0.0f,func_00344C08(car,wheel,0.0f));
    } else if(mode==0) {
        func_004A7844(((Pos *)self)->v[idx][0],((Pos *)self)->v[idx][1],((Pos *)self)->v[idx][2]);
        int base=self+8;
        func_004A79B0(DEG(((Rot *)base)->v[idx][1]));
        func_004A7988(DEG(((Rot *)base)->v[idx][0]));
        func_004A79D8(DEG(((Rot *)base)->v[idx][2]));
        func_004A7844(A(base,0x8fd0,stride+side),A(base,0x9030,stride+side)-0x1.d70a3ap-2f,A(base,0x9090,stride+side));
    } else {
        func_004A7844(((Pos2 *)(self+8))->v[idx][0],((Pos2 *)(self+8))->v[idx][1],((Pos2 *)(self+8))->v[idx][2]);
        func_004A79B0(DEG(F(stride+self,0x8f30)));
        float xx=func_00344AA8(car,wheel,0.0f);
        func_004A7844(xx,0.0f,func_00344C08(car,wheel,0.0f));
    }
    if(side&1) func_004A79B0(-90.0f); else func_004A79B0(90.0f);
    func_004A7844(0.0f,0.0f,func_00344CE8(car,wheel)*0.5f);
    func_004A7698(mat);
    func_004A7844(0.0f,0.0f,-func_00344CE8(car,wheel)*0.5f);
    func_004A79B0(-90.0f);
}
