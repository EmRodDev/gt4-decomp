/* Refreshes per-group output values from the wheels (inferred from the table func_00359510 returns: wheel count, group count,
 * index tables). It returns early when the config byte at +0x234 is 3, the value at block+0x490 is non-zero and the value at +0x53C is
 * within +-0.22 (a nearly stopped state; meaning inferred, not confirmed). Otherwise every enabled wheel gets its +0x20 value from
 * rotating its (x, z) by its own angle (func_0057D1F0 / func_0057D2B8 are the trig pair) and marks its group active; then, for each group
 * that is active or whose parameter byte is 0, the output at block+0x52C+4*i is the scale times the average of the +0x184 values of the
 * group's two wheels (127 in the partner table means the wheel is its own partner). */
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
extern "C" void func_0035D990(Obj *car) {
    u8 *block = (u8 *)car+0x104;
    u8 *config = car->config;
    Selection *selection = func_00359510(config);
    int active[4];
    int i;
    if (config[0x234] == 3 && F(block,0x490) != 0.0f && F(block,0x53C) > -0x1.1c71c6p-2f && F(block,0x53C) < 0x1.1c71c6p-2f) return;
    for (i=0; i<selection->count; i++) active[i]=0;
    for (i=0; i<selection->wheels; i++) {
        Wheel *wheel = &car->wheel[i];
        if (!wheel->disabled) {
            float angle = wheel->angle;
            float rotated = func_0057D1F0(angle)*wheel->x;
            rotated -= func_0057D2B8(angle)*wheel->z;
            wheel->speed = rotated;
            active[selection->data[0x28+i]] = 1;
        }
    }
    for (i=0; i<(int)selection->count; i++) {
        Params *params = (Params *)(config+0x234);
        int paramIndex = i<(int)selection->count ? selection->data[0xC+i] : 0;
        if (active[i] || params->data[0x10+paramIndex] == 0) {
            int wheelIndexA=selection->data[8+i];
            int wheelIndexB=selection->data[0x20+wheelIndexA];
            if (wheelIndexB==127) wheelIndexB=wheelIndexA;
            u8 *wheelA = (u8 *)car+wheelIndexA*0xEC;
            u8 *wheelB = (u8 *)car+wheelIndexB*0xEC;
            float average=(F(wheelA,0x184)+F(wheelB,0x184))*0.5f;
            float scale=getScale(params,paramIndex);
            ((Output *)(block+0xC))->value[i]=scale*average;
        }
    }
}
