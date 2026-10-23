/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P { char pad[0x440]; unsigned char index; char pad2[0x587-0x441]; float f588; };
struct Obj { char pad[0x104]; P p; };
extern "C" float D_00845940[3];
extern "C" float D_00845958[3];
extern "C" float D_00845970[][3];
extern "C" float D_008459B8[][3];
extern "C" float func_00345198(void *);
extern "C" float func_003451A0(void *);
extern "C" void func_003EFF98(Obj *self) {
    P *p = &self->p;
    int idx = p->index;
    int i;
    for (i = 0; i < 3; i++) {
        float target = 0.0f;
        switch (i) {
        case 0: target = func_003451A0(self); break;
        case 1: target = func_00345198(self); break;
        case 2: target = p->f588; break;
        }
        float k = D_00845940[i];
        float x = D_00845970[idx][i];
        float c = D_00845958[i];
        float v = D_008459B8[idx][i];
        v += (k * (target - x) - c * v) * 0x1.11111p-6f;
        D_008459B8[idx][i] = v;
        D_00845970[idx][i] = x + v * 0x1.11111p-6f;
    }
}
