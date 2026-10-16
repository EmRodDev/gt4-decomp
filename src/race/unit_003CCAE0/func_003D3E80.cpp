/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned int u32; typedef float f32;
extern "C" f32 func_00344798(void *,f32);
extern "C" f32 func_003447F8(void *,f32);
extern "C" f32 func_00344828(void *,f32);
extern "C" f32 func_00344AA8(void *,s32,f32);
extern "C" f32 func_00344C08(void *,s32,f32);
extern "C" f32 func_00344CE8(void *,s32);
extern "C" void *func_0034C190(void *,s32);
extern "C" f32 func_003CCB60(void *,f32,f32);
extern "C" void func_003D3490(void *) throw();
extern "C" void func_003D34A8(void *) throw();
extern "C" s32 func_003D34D8(void *,void *) throw();
extern "C" f32 func_003D35C0(s32) throw() __attribute__((const));
extern "C" f32 func_003D35F0(s32) throw() __attribute__((const));
extern "C" void func_003D3830(void *,void *,s32,s32) throw();
extern "C" s32 func_003D3910(void *,s32 *,f32,f32,f32) throw();
extern "C" s32 func_003D3930(void *,s32 *,f32,f32,f32) throw();
extern "C" void func_003D3D80(void *) throw();
extern "C" s32 func_003D3D98(void *,f32,f32) throw();
extern "C" s32 func_003D3DA8(void *,f32,f32) throw();
extern "C" s32 func_003D3DD0(void *,f32) throw();
extern "C" s32 func_003D3E00(void *,f32) throw();
extern "C" void func_003D3E70(void *,s32) throw();
extern "C" f32 func_003F3708(void *);
extern "C" f32 func_003F3720(void *);
extern "C" f32 func_003F3738(void *);
extern "C" void func_004573B8(s32,s32 *,void *);
extern "C" f32 func_0057D118(f32,f32);

struct Rect { float v[8]; Rect() __asm__("func_003D34A8"); void set(float a,float b,float c,float d){v[0]=a;v[1]=b;v[2]=c;v[3]=d;} };
struct Sphere { float v[4]; Sphere() __asm__("func_003D3490"); };
struct Target { int type, side; float x,y; };
struct Obj { int id; unsigned state; Target *target; Target a,b; int active,id2; float destx,desty,x,y; char pad44[0x20]; float angle,anim,rate,time; };
struct Team { char pad[0x9680]; int state[32]; };
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
static inline void set2(float *x, float *y, float a, float b) { *x=a; *y=b; }
static inline void transform_ref(float *ox, float *oy, const float *x, const float *y,
    float a, float b, float c, float d, float e, float f) {
    *ox = a * *x + b * *y + c;
    *oy = d * *x + e * *y + f;
}
extern "C" void func_003D3E80(Obj *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 self, char *arg5, u32 arg6, s32 arg7, f32 fparg0) {
    s32 collision[4] __attribute__((aligned(16)));
    s32 offset;
    u32 sp64;
    s32 sp68;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f21;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_s6;
    s32 var_s3_2;
    s32 var_s5;
    u32 temp_a0;
    u32 var_v0_2;
    char *temp_s0_2;
    char *temp_s0_3;
    char *temp_s0_4;
    char *temp_s2;
    char *temp_s2_2;
    Target *temp_v0_3;
    Target *temp_v0_4;
    Target *temp_v0_5;
    char *temp_v0_6;
    Target *temp_v1;
    char *var_s3_3;

    char *arg4 = (char *)self;
    if (arg0->active != 0) {
        temp_s4 = arg2 - (arg2 > 0);
        offset = arg2 * 4;
        temp_s0 = ((Team *)(arg4 + 4))->state[arg2];
        temp_s6 = ((Team *)(arg4 + 4))->state[temp_s4];
        temp_s2 = (char *)func_0034C190(arg5, arg2);
        if (arg2 != temp_s4) {
            func_0034C190(arg5, temp_s4);
        }
        temp_a1 = temp_s0 == 0;
        var_s5 = 0;
        if ((temp_a1 != 0) || (temp_s0 >= 5)) {
            var_s5 = 1;
        }
        if (arg7 != 0) {
            arg7 = 0;
            if (arg2 != temp_s4) {
                arg7 = temp_s6 == 1;
            }
        }
        temp_a0 = arg0->state;
        sp64 = 0;
        collision[0] = 0;
        switch (temp_a0) {
        case 0:
            sp64 = 1;
            arg0->target = &arg0->b;
            if (temp_s0 > 0) {
                arg0->time = (f32) (arg0->time + fparg0);
                if (arg6 < 2U) {
                    arg0->time = 0x0.0p+0f;
                } else if (func_003CCB60(arg4, 0x0.0p+0f, 0x1.8000000000000p-1f) <= arg0->time) {
                    if (arg7 != 0) {
                        arg0->time = 0x0.0p+0f;
                        arg0->state = sp64;
                    } else {
                        arg0->time = 0x0.0p+0f;
                        arg0->state = 4U;
                    }
                }
            } else {
            default:;
            }
            break;
        case 1:
            if (func_003D3D98(arg0, fparg0, func_0057D118(arg0->a.x - arg0->x, arg0->a.y - arg0->y)) != 0) {
                arg0->state = 2U;
            }
            break;
        case 2:
            if (arg7 == 0) {
                func_003D3D80(arg0);
                arg0->target = &arg0->b;
                arg0->state = 4;
            } else {
                if (func_003D3910(arg0, collision, fparg0, arg0->a.x, arg0->a.y)) {
                    func_003D3D80(arg0);
                    arg0->state = 3;
                } else if (collision[0]) {
                    func_003D3D80(arg0);
                    arg0->state = 15;
                }
            }
            break;
        case 3:
            if (arg7 == 0) {
                float carx = func_00344798(temp_s2, 0.0f);
                temp_s0_2 = arg4 + ((offset + arg2) << 5);
                temp_f20 = carx - (arg0->x + M2C_FIELD(temp_s0_2, f32 *, 0x78A8));
                temp_f0 = func_00344828(temp_s2, 0x0.0p+0f) - (arg0->y + M2C_FIELD(temp_s0_2, f32 *, 0x78B0));
                if (((temp_f20 * temp_f20) + (temp_f0 * temp_f0)) > 0x1.81cd6c0000000p+13f) {
                    arg0->target = &arg0->b;
                } else {
                    arg0->target = &arg0->a;
                }
                arg0->state = 4U;
            }
            break;
        case 4:
            temp_v0_3 = arg0->target;
            if (func_003D3D98(arg0, fparg0, func_0057D118(temp_v0_3->x - arg0->x, temp_v0_3->y - arg0->y)) != 0) {
                arg0->state = 5U;
            }
            break;
        case 5:
            temp_v0_4 = arg0->target;
            if (func_003D3910(arg0, collision, fparg0, temp_v0_4->x, temp_v0_4->y) != 0) {
                func_003D3D80(arg0);
                arg0->state = 6U;
            } else if (collision[0] != 0) {
                func_003D3D80(arg0);
                arg0->state = 15;
            }
            break;
        case 6:
            if (func_003D3D98(arg0, fparg0, func_003D35C0(arg0->target->side)) != 0) {
                arg0->state = 7U;
            }
            break;
        case 7:
            if (var_s5 == 0) {
                if (temp_s0 >= 2) {
                    temp_f21 = func_00344AA8(temp_s2, arg0->target->type, 0x0.0p+0f);
                    temp_f20_2 = func_00344C08(temp_s2, arg0->target->type, 0x0.0p+0f);
                    temp_f0_2 = (func_00344CE8(temp_s2, arg0->target->type) * 0x1.0000000000000p-1f) + 0x1.0000000000000p+0f;
                    temp_v1 = arg0->target;
                    float *targetx = &temp_v1->x;
                    if ((temp_v1->side & 1) == 0) {
                        var_f0 = temp_f21 - temp_f0_2;
                    } else {
                        var_f0 = temp_f21 + temp_f0_2;
                    }
                    *targetx = var_f0;
                    arg0->target->y = temp_f20_2;
                    arg0->state = 8U;
                }
            } else {
                arg0->state = 15;
            }
            break;
        case 8:
        case 9:
            if (var_s5 == 0) {
                if (temp_a0 == 8) {
                    temp_v0_5 = arg0->target;
                    if (func_003D3930(arg0, collision, fparg0, temp_v0_5->x, temp_v0_5->y) != 0) {
                        func_003D3D80(arg0);
                        arg0->state = 9U;
                    }
                } else if (func_003D3DA8(arg0, fparg0, 0x1.0000000000000p+0f) != 0) {
                    arg0->state = 0xAU;
                }
            } else {
                arg0->state = 15;
            }
            break;
        case 10:
            if (var_s5 != 0) {
                arg0->state = 15;
                break;
            }
            if (temp_s0 >= 3) {
                arg0->time = (f32) (arg0->time + fparg0);
                if (func_003CCB60(arg4, 0x0.0p+0f, 0x1.8000000000000p-1f) <= arg0->time) {
                    arg0->time = 0x0.0p+0f;
                    func_003D3E70(arg0, 1);
                    var_f0_2 = func_003CCB60(arg4, 0x1.8000000000000p-1f, 0x1.0000000000000p+0f);
                    var_v0_2 = 0xB;
                    arg0->rate = var_f0_2;
                    arg0->state = var_v0_2;
                }
            }
            break;
        case 11:
            if (func_003D3DD0(arg0, fparg0 * arg0->rate) != 0) {
                if (var_s5 != 0) {
                    arg0->rate = 0x0.0p+0f;
                    arg0->state = 0xCU;
                } else if (temp_s0 >= 4) {
                    var_f0_2 = func_003CCB60(arg4, 0x0.0p+0f, 0x1.0000000000000p+0f);
                    var_v0_2 = 0xC;
                    arg0->rate = var_f0_2; arg0->state = var_v0_2;
                }
            }
            break;
        case 12:
            temp_f0_3 = arg0->time + fparg0;
            arg0->time = temp_f0_3;
            if ((arg0->rate <= temp_f0_3) && (func_003D3E00(arg0, fparg0) != 0)) {
                arg0->state = 0xDU;
            }
            break;
        case 13:
            var_s3_2 = 0;
            if ((temp_a1 != 0) || ((var_s5 != 0) && (temp_f20_3 = func_00344798(temp_s2, 0.0f), temp_s0_3 = arg4 + ((offset + arg2) << 5), temp_f20_3 = temp_f20_3 - (arg0->x + M2C_FIELD(temp_s0_3, f32 *, 0x78A8)), temp_f0_4 = func_00344828(temp_s2, 0x0.0p+0f) - (arg0->y + M2C_FIELD(temp_s0_3, f32 *, 0x78B0)), (((temp_f20_3 * temp_f20_3) + (temp_f0_4 * temp_f0_4)) >= 0x1.9000000000000p+8f)))) {
                var_s3_2 = 1;
            }
            if (var_s3_2 != 0) {
                arg0->time = 0x0.0p+0f;
                var_f0_2 = func_003CCB60(arg4, 0x1.0000000000000p+1f, 0x1.4000000000000p+2f);
                var_v0_2 = 0xE;
                arg0->rate = var_f0_2; arg0->state = var_v0_2;
            }
            break;
        case 14:
            temp_f12 = arg0->time + fparg0;
            arg0->time = temp_f12;
            if ((arg7 != 0) || (arg0->rate <= temp_f12)) {
                arg0->time = 0x0.0p+0f;
                arg0->state = 0xFU;
            }
            break;
        case 15:
            func_003D3E70(arg0, 0);
            arg0->state = 0x10U;
            func_003D3830(arg0, arg4, arg0->id, arg1);
            /* fallthrough */
        case 16:
            if (func_003D3D98(arg0, fparg0, func_0057D118(arg0->destx - arg0->x, arg0->desty - arg0->y)) != 0) {
                arg0->state = 0x11U;
            }
            break;
        case 17:
            if ((arg0->target != &arg0->b) || (temp_f20_4 = func_00344798(temp_s2, 0.0f), temp_s0_4 = arg4 + ((offset + arg2) << 5), temp_f20_4 = temp_f20_4 - (arg0->x + M2C_FIELD(temp_s0_4, f32 *, 0x78A8)), temp_f0_5 = func_00344828(temp_s2, 0x0.0p+0f) - (arg0->y + M2C_FIELD(temp_s0_4, f32 *, 0x78B0)), (((temp_f20_4 * temp_f20_4) + (temp_f0_5 * temp_f0_5)) >= 0x1.9000000000000p+8f))) {
                arg0->state = 0x12U;
            }
            break;
        case 18:
            if (func_003D3930(arg0, collision, fparg0, arg0->destx, arg0->desty) != 0) {
                func_003D3D80(arg0);
                temp_f20_5 = func_003D35F0(arg1);
                temp_f20_6 = temp_f20_5 + func_003CCB60(arg4, -0x1.41b2f00000000p-1f, 0x1.41b2f00000000p-1f);
                arg0->state = 0x13U;
                arg0->angle = temp_f20_6;
            }
            break;
        case 19:
            if (func_003D3D98(arg0, fparg0, arg0->angle) != 0) {
                if (temp_s0 == 0) {
                    arg0->state = 0U;
                }
            }
            break;
        }
        sp68 = 0;
        s32 *callback = arg3;
        func_004573B8(*callback, callback, &arg0->anim);
        Rect rect __attribute__((aligned(16)));
        float q[4] __attribute__((aligned(16)));

        if (M2C_FIELD(arg5, s32 *, 0xF8A0) > 0) {
            temp_s2_2 = arg4 + ((offset + arg2) << 5);
            var_s3_3 = arg4;
            do {
                temp_v0_6 = (char *)func_0034C190(arg5, sp68);
                if (!(__builtin_fabsf(func_003447F8(temp_v0_6, 0x0.0p+0f) - M2C_FIELD(temp_s2_2, f32 *, 0x78AC)) > 0x1.0000000000000p+1f)) {
                    float *ox = &arg0->x;
                    float *oy = &arg0->y;
                    float cx = func_00344798(temp_v0_6, 0x0.0p+0f);
                    float tx = M2C_FIELD(temp_s2_2, f32 *, 0x78A8);
                    float x = *ox;
                    temp_f20_7 = cx - (x + tx);
                    float cy = func_00344828(temp_v0_6, 0x0.0p+0f);
                    float ty = M2C_FIELD(temp_s2_2, f32 *, 0x78B0);
                    float y = *oy;
                    temp_f0_6 = cy - (y + ty);
                    if (!(((temp_f20_7 * temp_f20_7) + (temp_f0_6 * temp_f0_6)) >= 0x1.9000000000000p+8f)) {
                        rect.set(-func_003F3738(temp_v0_6) * 0x1.0p-1f, -func_003F3708(temp_v0_6), func_003F3738(temp_v0_6) * 0x1.0p-1f, func_003F3720(temp_v0_6));
                        float *px = &rect.v[4], *py = &rect.v[5];
                        float x = *ox, y = *oy;
                        *px = M2C_FIELD(temp_s2_2,float *,0x78DC)*x + M2C_FIELD(temp_s2_2,float *,0x78E0)*y + M2C_FIELD(temp_s2_2,float *,0x78E4);
                        *py = M2C_FIELD(temp_s2_2,float *,0x78E8)*x + M2C_FIELD(temp_s2_2,float *,0x78EC)*y + M2C_FIELD(temp_s2_2,float *,0x78F0);
                        transform_ref(&q[0], &q[1], px, py,
                            M2C_FIELD(var_s3_3,float *,0x7924), M2C_FIELD(var_s3_3,float *,0x7928), M2C_FIELD(var_s3_3,float *,0x792C),
                            M2C_FIELD(var_s3_3,float *,0x7930), M2C_FIELD(var_s3_3,float *,0x7934), M2C_FIELD(var_s3_3,float *,0x7938));
                        Sphere sph __attribute__((aligned(16)));
                        float *sphere = sph.v;
                        sphere[0] = 0x1.0000000000000p-2f;
                        float *sx = &sphere[1], *sy = &sphere[2];
                        set2(sx,sy,q[0],q[1]);
                        if (func_003D34D8(rect.v, &sphere[0]) != 0) {
                            *px = M2C_FIELD(var_s3_3,float *,0x790C) * *sx + M2C_FIELD(var_s3_3,float *,0x7910) * *sy + M2C_FIELD(var_s3_3,float *,0x7914);
                            *py = M2C_FIELD(var_s3_3,float *,0x7918) * *sx + M2C_FIELD(var_s3_3,float *,0x791C) * *sy + M2C_FIELD(var_s3_3,float *,0x7920);
                            float x = *px, y = *py;
                            *ox = M2C_FIELD(temp_s2_2,float *,0x78F4)*x + M2C_FIELD(temp_s2_2,float *,0x78F8)*y + M2C_FIELD(temp_s2_2,float *,0x78FC);
                            *oy = M2C_FIELD(temp_s2_2,float *,0x7900)*x + M2C_FIELD(temp_s2_2,float *,0x7904)*y + M2C_FIELD(temp_s2_2,float *,0x7908);
                            if (sp64 != 0) {
                                arg0->state = 0x10U;
                            }
                        }
                    }
                }
                var_s3_3 += 0xA0;
                sp68++;
            } while (sp68 < M2C_FIELD(arg5, s32 *, 0xF8A0));
        }
    }
}
