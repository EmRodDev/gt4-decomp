/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
// Only the position, displacement amount, and per-worker stride are known.
struct Slot { int state; float a,b,c; float angle, amount; char unknown[0x178-0x18]; };
static inline void set(Slot *p,float a,float b,float c) { p->a=a;p->b=b;p->c=c; }
static inline float &x(Slot *p) {return p->a;}
static inline float &y(Slot *p) {return p->b;}
static inline float &z(Slot *p) {return p->c;}
struct VEntry { short delta; short pad; unsigned short *(*fn)(void *); };
struct Virtual {char pad[8]; VEntry *vt;};
struct Car { char unknown[0x2880]; Virtual *object; };
struct CarList { char unknown[8]; Car **cars; };
struct World { char unknown[0x60]; CarList *list; };
struct Owner { World *world; };
struct Mode { char unknown[8]; int value; };
extern "C" int func_0034C190(Owner *,int);
extern "C" float func_003CCB60(char *,float,float) throw();
extern "C" void func_003CDFD8(char *,int,int);
extern "C" void func_003CDB20(char *arg0, s32 arg1, Owner *arg2) {
    f32 *sp0;
    f32 *sp4;
    f32 *sp8;
    f32 *spC;
    f32 *var_fp;
    f32 *var_s3;
    f32 *var_s6;
    f32 *var_s7;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    Car **temp_a3;
    CarList *temp_a4;
    char *temp_s0;
    char *temp_s1;
    Car *temp_s3;
    char *temp_s4;
    char *temp_s5;
    char *temp_v0;
    char *var_s0;

    int car=func_0034C190(arg2,arg1);
    temp_a4 = arg2->world->list;
    temp_s0 = arg0 + (arg1 * 0x8D0);
    temp_a3 = (Car **)(arg1 * 4 + (int)temp_a4->cars);
    temp_s1 = temp_s0 + 0x3E4;
    temp_s3 = *temp_a3;
    func_003CDFD8(arg0, arg1, car);
    temp_f3 = ((Slot *)(temp_s0+0x3E4))->a;
    temp_f2 = ((Slot *)(temp_s0+0x6D4))->a;
    temp_v0 = temp_s0 + 0x6D4;
    if (temp_f3 < temp_f2) {
        set((Slot *)temp_v0, temp_f3, (f32) ((Slot *)(temp_s0+0x6D4))->b, (f32) ((Slot *)(temp_s0+0x6D4))->c);
    } else {
        set((Slot *)temp_s1, temp_f2, (f32) ((Slot *)(temp_s0+0x3E4))->b, (f32) ((Slot *)(temp_s0+0x3E4))->c);
    }
    temp_s4 = temp_s1 + 0x178;
    sp0 = &x((Slot *)(temp_s1 + 0x178));
    sp4 = &x((Slot *)(temp_s1 + 0x468));
    temp_f3_2 = ((Slot *)temp_s1)[1].a;
    temp_f2_2 = ((Slot *)temp_s1)[3].a;
    temp_s5 = temp_s1 + 0x468;
    if (temp_f2_2 < temp_f3_2) {
        var_s7 = &y((Slot *)(temp_s1 + 0x178));
        sp8 = &y((Slot *)(temp_s1 + 0x468));
        spC = &z((Slot *)(temp_s1 + 0x468));
        var_fp = &z((Slot *)(temp_s1 + 0x178));
        set((Slot *)temp_s5, temp_f3_2, (f32) ((Slot *)temp_s1)[3].b, (f32) ((Slot *)temp_s1)[3].c);
    } else {
        var_s7 = &y((Slot *)(temp_s1 + 0x178));
        var_fp = &z((Slot *)(temp_s1 + 0x178));
        sp8 = &y((Slot *)(temp_s1 + 0x468));
        spC = &z((Slot *)(temp_s1 + 0x468));
        set((Slot *)temp_s4, temp_f2_2, (f32) ((Slot *)temp_s1)[1].b, (f32) ((Slot *)temp_s1)[1].c);
    }
    Virtual *v=temp_s3->object;
    VEntry *e=v->vt+10;
    unsigned int flags=*e->fn((char *)v+e->delta);
    if ((flags>>4)&1) {
        if ((*(Mode **)arg0)->value == 1) {
            var_s3 = &x((Slot *)temp_s1);
            var_s6 = &x((Slot *)(temp_s1 + 0x2F0));
            var_s0 = temp_s1 + 0x2F0;
            set((Slot *)temp_s1, (f32) (*var_s3 - 0x1.0000000000000p+0f), (f32) y((Slot *)temp_s1), (f32) z((Slot *)temp_s1));
            temp_f1 = *sp0 + func_003CCB60(arg0, 0x1.999998p-4f, 0.25f);
            set((Slot *)temp_s4, temp_f1, (f32) *var_s7, (f32) *var_fp);
            set((Slot *)var_s0, (f32) (*var_s6 - 0x1.0000000000000p+0f), (f32) ((Slot *)temp_s1)[2].b, (f32) ((Slot *)temp_s1)[2].c);
            temp_f1_5 = *sp4 + func_003CCB60(arg0, 0x1.333332p-1f, 0x1.666666p-1f);
            set((Slot *)temp_s5, temp_f1_5, *sp8, *spC);
    } else {
        float offset=func_003CCB60(arg0, 0x1.999998p-4f, 0.25f);
        var_s3 = &x((Slot *)temp_s1);
        var_s6 = &x((Slot *)(temp_s1 + 0x2F0));
        var_s0 = temp_s1 + 0x2F0;
        float t=*var_s3 - offset;
        set((Slot *)temp_s1, t, y((Slot *)temp_s1), z((Slot *)temp_s1));
        set((Slot *)temp_s4, (f32) (*sp0 + 0x1.0000000000000p+0f), (f32) *var_s7, (f32) *var_fp);
        temp_f1_2 = *var_s6 - func_003CCB60(arg0, 0x1.333332p-1f, 0x1.666666p-1f);
        set((Slot *)var_s0, temp_f1_2, (f32) ((Slot *)temp_s1)[2].b, (f32) ((Slot *)temp_s1)[2].c);
        set((Slot *)temp_s5, (f32) (*sp4 + 0x1.0000000000000p+0f), (f32) *sp8, (f32) *spC);
        }
    } else {
        float offset=func_003CCB60(arg0, 0x1.999998p-4f, 0.25f);
        var_s3 = &x((Slot *)temp_s1);
        var_s6 = &x((Slot *)(temp_s1 + 0x2F0));
        var_s0 = temp_s1 + 0x2F0;
        float t=*var_s3 - offset;
        set((Slot *)temp_s1, t, y((Slot *)temp_s1), z((Slot *)temp_s1));
        temp_f1_3 = *sp0 + func_003CCB60(arg0, 0x1.999998p-4f, 0.25f);
        set((Slot *)temp_s4, temp_f1_3, (f32) *var_s7, (f32) *var_fp);
        temp_f1_4 = *var_s6 - func_003CCB60(arg0, 0x1.333332p-1f, 0x1.666666p-1f);
        set((Slot *)var_s0, temp_f1_4, (f32) ((Slot *)temp_s1)[2].b, (f32) ((Slot *)temp_s1)[2].c);
        temp_f1_5 = *sp4 + func_003CCB60(arg0, 0x1.333332p-1f, 0x1.666666p-1f);
        set((Slot *)temp_s5, temp_f1_5, (f32) *sp8, (f32) *spC);
    }
    *var_s3 -= ((Slot *)temp_s1)->amount;
    *sp0 += ((Slot *)temp_s4)->amount;
    *var_s6 -= ((Slot *)var_s0)->amount;
    *sp4 += ((Slot *)temp_s5)->amount;
}
