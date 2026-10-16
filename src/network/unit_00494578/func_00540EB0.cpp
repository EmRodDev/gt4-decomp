struct O { void *m0; char pad[0x20C]; int m210; };
extern "C" int func_00538C68(void *) throw();
extern "C" int func_005410A0(void *);
extern "C" int func_00540EB0(O *obj) {
    O *p = 0;
    if (obj == 0) return 2;
    O *t = obj;
    p = t;
    if (t->m210 != 0) {
        func_00538C68(&t->m210);
        t = p;
    }
    if (t->m0 != 0) func_005410A0(t->m0);
    func_00538C68(&p);
    return 0;
}
