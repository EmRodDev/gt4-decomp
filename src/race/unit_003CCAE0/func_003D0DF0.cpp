/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-slot state machine that fills one of six car-slot records (position, rotation, four wheel values each) from
 * the tables behind func_0034C190(context) (the "sourceHandle"). phase is the requested step; the stored state in body.state[slot] steps
 * -1/0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 0 (cases fall through into each other on purpose, which is why the switch is
 * written with case labels inside the if blocks: that is the shape the compiler needed). State 1 reads the start
 * pose from func_0046BEC0, state 3/4 sample the per-wheel getters (func_00344AA8/B40/C08/E48), state 4 with
 * phase >= 4 samples the rotation. What the data source is in game terms is purpose unknown (inferred from the
 * six-slot, four-wheel layout only). */
typedef int s32; typedef float f32; typedef char s8;
#define NULL 0

#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))

struct V { float x,y,z; };
struct Q { float x,y,z,w; };
struct Inner {
 char pad[0x8f40]; float rot[6][3]; float pos2[6][3]; char pad2[0x8fd0-0x8f40-144];
 float wheel1[6][4]; float wheel2[6][4]; float wheel3[6][4]; float pos[6][3];
};
struct Body { int h; Inner inner; char pad[0x96b0-4-sizeof(Inner)]; int state[6]; };
struct S { int h; Body body; };
struct Pos2 { char pad[0x8f90]; float pos[6][3]; };
struct Rates { char pad[0x8f30]; float rate[6]; };
struct Wheels { char pad[0x95e0]; float wheels[6][4]; };
extern "C" {
f32 func_00344798(s32, f32);                    /* extern */
f32 func_003447F8(s32, f32);                    /* extern */
f32 func_00344828(s32, f32);                    /* extern */
f32 func_00344858(s32, f32);                    /* extern */
f32 func_00344888(s32, f32);                    /* extern */
f32 func_003448B8(s32, f32);                    /* extern */
f32 func_00344AA8(s32, s32, f32);               /* extern */
f32 func_00344B40(s32, s32, f32);               /* extern */
f32 func_00344C08(s32, s32, f32);               /* extern */
f32 func_00344E48(s32, s32, f32);               /* extern */
s32 func_0034C190(s32);                             /* extern */
s32 func_003CD900(S *, s32, s32) throw();               /* extern */
void func_003CDB20(S *, s32, s32) throw(); /* extern */
void func_003CDFD8(S *, s32, s32) throw();               /* extern */
void func_003CE4A0(S *, s32, s32) throw();               /* extern */
void func_003CE930(S *, s32, s32) throw();               /* extern */
void func_0046BEC0(s32, s32, float *, float *, int *); /* extern */

void func_003D0DF0(S *cars, s32 slot, s32 phase, s32 context) {
    struct Stack { int flags[4]; float pos[4]; float rot[4]; } sp_;
    s32 sourceHandle;
    s32 wheel0;
    s32 wheel1;
    s32 wheel2;
    s32 wheel3;
    s32 slotState;



    sourceHandle = func_0034C190(context);
    slotState = cars->body.state[slot];
    switch (slotState) {
    case -1:
    case 0:
        if (phase == 0) {
            
            cars->body.state[slot] = 1;
            ((Wheels *)cars)->wheels[slot][0] = 0;
            ((Wheels *)cars)->wheels[slot][1] = 0;
            ((Wheels *)cars)->wheels[slot][2] = 0;
            ((Wheels *)cars)->wheels[slot][3] = 0;
        case 1: {
            func_0046BEC0(context + 0xDA50, slot, sp_.pos, sp_.rot, sp_.flags);
            
            float z = -sp_.pos[1];
            float r = sp_.rot[2];
            float x = sp_.pos[0];
            float y = sp_.pos[2];
            cars->body.inner.pos[slot][0] = x;
            cars->body.inner.pos[slot][1] = y;
            cars->body.inner.pos[slot][2] = z;
            ((Rates *)cars)->rate[slot] = r;
            cars->body.inner.rot[slot][0] = 0;
            cars->body.inner.rot[slot][1] = r;
            cars->body.inner.rot[slot][2] = 0;
            func_003CDB20(cars, slot, context);
            func_003CE930(cars, slot, context);
            cars->body.state[slot] = 2;
        }
        default:;
        }
        break;
    case 2:
        if (phase == 2) {
            cars->body.state[slot] = 3;
        case 3:
            cars->body.inner.pos[slot][0] = func_00344798(sourceHandle, 0);
            cars->body.inner.pos[slot][2] = func_00344828(sourceHandle, 0);
            ((Wheels *)cars)->wheels[slot][0] = func_00344E48(sourceHandle, func_003CD900(cars, slot, 0), 0);
            ((Wheels *)cars)->wheels[slot][1] = func_00344E48(sourceHandle, func_003CD900(cars, slot, 1), 0);
            ((Wheels *)cars)->wheels[slot][2] = func_00344E48(sourceHandle, func_003CD900(cars, slot, 2), 0);
            ((Wheels *)cars)->wheels[slot][3] = func_00344E48(sourceHandle, func_003CD900(cars, slot, 3), 0);
            func_003CDFD8(cars, slot, sourceHandle);
            func_003CE4A0(cars, slot, context);
            cars->body.state[slot] = 4;
        }
        break;
    case 4:
        if (phase < 4) {
            cars->body.inner.pos[slot][0] = func_00344798(sourceHandle, 0);
            cars->body.inner.pos[slot][2] = func_00344828(sourceHandle, 0);
            ((Pos2 *)cars)->pos[slot][0] = func_00344798(sourceHandle, 0);
            ((Pos2 *)cars)->pos[slot][1] = func_003447F8(sourceHandle, 0);
            ((Pos2 *)cars)->pos[slot][2] = func_00344828(sourceHandle, 0);
            wheel0 = func_003CD900(cars, slot, 0);
            cars->body.inner.wheel1[slot][0] = func_00344AA8(sourceHandle, wheel0, 0);
            cars->body.inner.wheel2[slot][0] = func_00344B40(sourceHandle, wheel0, 0);
            cars->body.inner.wheel3[slot][0] = func_00344C08(sourceHandle, wheel0, 0);
            wheel1 = func_003CD900(cars, slot, 1);
            cars->body.inner.wheel1[slot][1] = func_00344AA8(sourceHandle, wheel1, 0);
            cars->body.inner.wheel2[slot][1] = func_00344B40(sourceHandle, wheel1, 0);
            cars->body.inner.wheel3[slot][1] = func_00344C08(sourceHandle, wheel1, 0);
            wheel2 = func_003CD900(cars, slot, 2);
            cars->body.inner.wheel1[slot][2] = func_00344AA8(sourceHandle, wheel2, 0);
            cars->body.inner.wheel2[slot][2] = func_00344B40(sourceHandle, wheel2, 0);
            cars->body.inner.wheel3[slot][2] = func_00344C08(sourceHandle, wheel2, 0);
            wheel3 = func_003CD900(cars, slot, 3);
            cars->body.inner.wheel1[slot][3] = func_00344AA8(sourceHandle, wheel3, 0);
            cars->body.inner.wheel2[slot][3] = func_00344B40(sourceHandle, wheel3, 0);
            cars->body.inner.wheel3[slot][3] = func_00344C08(sourceHandle, wheel3, 0);
        } else {
            cars->body.inner.rot[slot][0] = func_00344858(sourceHandle, 0);
            cars->body.inner.rot[slot][1] = func_003448B8(sourceHandle, 0);
            cars->body.inner.rot[slot][2] = (f32) -func_00344888(sourceHandle, 0);
            cars->body.state[slot] = 5;
        case 5:
            cars->body.state[slot] = 0;
        }
        break;
    }
}

}
