typedef unsigned char u8;
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
struct Selection { u8 unk0, wheels, count, unk3; u8 data[0x40]; };
struct Wheel { float angle; u8 pad4[0x1C]; float speed; float pad24; float x,z; u8 pad30[0x16]; u8 disabled; u8 pad47[0xA5]; };
struct Scale { u8 pad[0x90]; float value[0]; };
struct Params { u8 data[0]; u8 mode, enabled, pad2, selected; u8 pad4[4]; Scale scale; };
static inline float getScale(Params *prm,int k) {
 float scale=prm->scale.value[k];
 if (prm->enabled) scale=prm->scale.value[prm->selected];
 return scale;
}
struct Output { u8 pad[0x520]; float value[0]; };
struct Obj { u8 pad0[0x10]; u8 *config; u8 pad14[0x150]; Wheel wheel[0]; };
extern "C" Selection *func_00359510(u8 *) throw();
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" void func_0035D990(Obj *p) {
    u8 *s = (u8 *)p+0x104;
    u8 *cfg = p->config;
    Selection *sel = func_00359510(cfg);
    int active[4];
    int i;
    if (cfg[0x234] == 3 && F(s,0x490) != 0.0f && F(s,0x53C) > -0x1.1c71c6p-2f && F(s,0x53C) < 0x1.1c71c6p-2f) return;
    for (i=0; i<sel->count; i++) active[i]=0;
    for (i=0; i<sel->wheels; i++) {
        Wheel *w = &p->wheel[i];
        if (!w->disabled) {
            float a = w->angle;
            float x = func_0057D1F0(a)*w->x;
            x -= func_0057D2B8(a)*w->z;
            w->speed = x;
            active[sel->data[0x28+i]] = 1;
        }
    }
    for (i=0; i<(int)sel->count; i++) {
        Params *prm = (Params *)(cfg+0x234);
        int k = i<(int)sel->count ? sel->data[0xC+i] : 0;
        if (active[i] || prm->data[0x10+k] == 0) {
            int a=sel->data[8+i];
            int b=sel->data[0x20+a];
            if (b==127) b=a;
            u8 *wa = (u8 *)p+a*0xEC;
            u8 *wb = (u8 *)p+b*0xEC;
            float avg=(F(wa,0x184)+F(wb,0x184))*0.5f;
            float scale=getScale(prm,k);
            ((Output *)(s+0xC))->value[i]=scale*avg;
        }
    }
}
