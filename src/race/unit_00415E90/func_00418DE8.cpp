/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00422150(void *, float *, float *);
extern "C" float *func_00421168(float *, float *);
extern "C" double fptodp(float);
extern "C" void func_0057D9C0(const char *, ...);
extern char D_006A4818[];
extern "C" void func_00418DE8(float *o) {
    float pos[4], rot[4], tmp[4];
    func_00422150(o+4,pos,rot);
    double a = fptodp(o[0]);
    double b = fptodp(o[1]);
    double c = fptodp(o[2]);
    double d = fptodp(pos[0]);
    double e = fptodp(pos[1]);
    double f = fptodp(pos[2]);
    float *p = tmp;
    func_00421168(p,rot);
    double g = fptodp(*p);
    func_0057D9C0(D_006A4818,a,b,c,d,e,f,g);
}
