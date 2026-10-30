/* compiler: ee-gcc2.96-as2004 */
union Value {
    int i;
    float f;
    unsigned char *p;
    Value *v;
};

struct Word {
    int i;
} __attribute__((packed));

struct Globals {
    Value *seg[4];
};

struct Host {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual int getInt(int id, Value *var);
    virtual float getFloat(int id, Value *var);
};

extern "C" float func_0057D118(float, float);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" float func_0057D380(float);
extern "C" float func_0057D6C0(float, float);
extern "C" float func_0057D788(float, float);
extern "C" int func_005A5600(void);

static inline float fsqrt(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" void func_004569F0(Globals *vars, unsigned char *code, int offset, Host *host)
{
    int pad[4];
    Value stack[256];
    Value spare[16];
    Value *limit = &stack[256];
    Value *sp = &stack[1];
    Value *fp = stack;
    unsigned char *pc = code + offset;
    int steps = 0;

    for (;;) {
        if (++steps > 10000) return;
        if (sp < stack) return;
        if (sp >= limit) return;
        Value *top = sp;
        switch (*pc++) {
        case 0x00:
            break;
        case 0x10: {
            int n = ((signed char)pc[1] << 8) | pc[0];
            pc += 2;
            (++sp)->i = fp[n].i;
            break;
        }
        case 0x11: {
            int w = ((Word *)pc)->i;
            pc += 4;
            (++sp)->i = w;
            break;
        }
        case 0x12: {
            int n = (pc[1] << 8) | pc[0];
            pc += 2;
            Value *base = vars->seg[n >> 14];
            (++sp)->i = base ? base[n & 0x3FFF].i : 0;
            break;
        }
        case 0x13: {
            int n = ((signed char)pc[1] << 8) | pc[0];
            pc += 2;
            fp[n].i = (sp--)->i;
            break;
        }
        case 0x14: {
            int n = (pc[1] << 8) | pc[0];
            pc += 2;
            int v = (sp--)->i;
            Value *base = vars->seg[n >> 14];
            if (base) base[n & 0x3FFF].i = v;
            break;
        }
        case 0x20:
            sp += *pc++;
            break;
        case 0x21:
            (++sp)->v = fp;
            sp++;
            break;
        case 0x22: {
            int n = *pc++;
            Value *frame = sp - n;
            int target = (pc[1] << 8) | pc[0];
            pc += 2;
            frame->p = pc;
            fp = frame - 1;
            pc = code + target;
            break;
        }
        case 0x23: {
            if (fp == stack) return;
            int n = *pc;
            int v = sp->i;
            sp = fp - 1;
            (fp - n)[-1].i = v;
            pc = fp[1].p;
            fp = fp[0].v;
            break;
        }
        case 0x24:
            pc = code + ((pc[1] << 8) | pc[0]);
            break;
        case 0x25: {
            int n = ((signed char)pc[1] << 8) | pc[0];
            pc += 2;
            pc += n;
            break;
        }
        case 0x26: {
            int n = ((signed char)pc[1] << 8) | pc[0];
            pc += 2;
            if ((sp--)->i == 0) pc += n;
            break;
        }
        case 0x27: {
            int n = ((signed char)pc[1] << 8) | pc[0];
            pc += 2;
            if ((sp--)->i != 0) pc += n;
            break;
        }
        case 0x28:
            sp--;
            break;
        case 0x30: sp--; sp->i = sp[0].i + sp[1].i; break;
        case 0x31: sp--; sp->i = sp[0].i - sp[1].i; break;
        case 0x32: sp--; sp->i = sp[0].i * sp[1].i; break;
        case 0x33: sp--; if (sp[1].i != 0) sp->i = sp[0].i / sp[1].i; break;
        case 0x34: sp--; sp->i = sp[0].i % sp[1].i; break;
        case 0x35: sp--; sp->i = sp[0].i < sp[1].i; break;
        case 0x36: sp--; sp->i = sp[0].i <= sp[1].i; break;
        case 0x37: sp--; sp->i = sp[0].i > sp[1].i; break;
        case 0x38: sp--; sp->i = sp[0].i >= sp[1].i; break;
        case 0x39: sp--; sp->i = sp[0].i == sp[1].i; break;
        case 0x3A: sp--; sp->i = sp[0].i != sp[1].i; break;
        case 0x40: sp--; sp->i = sp[0].i & sp[1].i; break;
        case 0x41: sp--; sp->i = sp[0].i | sp[1].i; break;
        case 0x42: sp--; sp->i = sp[0].i ^ sp[1].i; break;
        case 0x46: sp->i = ~sp->i; break;
        case 0x44: sp->i = sp->i << 1; break;
        case 0x45: sp->i = sp->i >> 1; break;
        case 0x3B: sp->i = -sp->i; break;
        case 0x80: { Value *p = sp - 1; p->f = p->f + sp->f; sp = p; break; }
        case 0x81: { Value *p = sp - 1; p->f = p->f - sp->f; sp = p; break; }
        case 0x82: { Value *p = sp - 1; p->f = p->f * sp->f; sp = p; break; }
        case 0x83: { Value *p = sp - 1; p->f = p->f / sp->f; sp = p; break; }
        case 0x84: { Value *p = sp - 1; p->f = func_0057D788(p->f, sp->f); sp = p; break; }
        case 0x85: sp--; sp->i = top[-1].f < top[0].f; break;
        case 0x86: sp--; sp->i = top[-1].f <= top[0].f; break;
        case 0x87: sp--; sp->i = top[-1].f > top[0].f; break;
        case 0x88: sp--; sp->i = top[-1].f >= top[0].f; break;
        case 0x89: sp--; sp->i = top[-1].f == top[0].f; break;
        case 0x8A: sp--; sp->i = top[-1].f != top[0].f; break;
        case 0x8C: sp->i = (int)sp->f; break;
        case 0x3C: sp->f = (float)sp->i; break;
        case 0x8B: sp->f = -sp->f; break;
        case 0xA0: sp->f = sp->f / 0x1.fffffep+30f * (float)func_005A5600(); break;
        case 0xA1: sp->f = func_0057D2B8(sp->f); break;
        case 0xA2: sp->f = func_0057D1F0(sp->f); break;
        case 0xA3: sp->f = func_0057D380(sp->f); break;
        case 0xA4: sp->f = fsqrt(sp->f); break;
        case 0xA5: sp->f = 0.5f - func_0057D1F0(sp->f) * 0.5f; break;
        case 0xB0: { Value *p = sp - 1; p->f = func_0057D6C0(p->f, sp->f); sp = p; break; }
        case 0xB1: { Value *p = sp - 1; p->f = func_0057D118(p->f, sp->f); sp = p; break; }
        case 0xB2: {
            Value *p = sp - 1;
            float b = sp->f;
            float a = p->f;
            float inv = 1.0f / b;
            p->f = (a - (float)(int)(a * inv) * b) * inv;
            sp = p;
            break;
        }
        case 0xC0: {
            int id = (pc[1] << 8) | pc[0];
            pc += 2;
            int n = (pc[1] << 8) | pc[0];
            pc += 2;
            int r;
            sp++;
            if (host) {
                Value *base = vars->seg[n >> 14];
                Value *var = base ? &base[n & 0x3FFF] : 0;
                r = host->getInt(id, var);
            } else {
                r = 0;
            }
            sp->i = r;
            break;
        }
        case 0xC1: {
            int id = (pc[1] << 8) | pc[0];
            pc += 2;
            int n = (pc[1] << 8) | pc[0];
            pc += 2;
            sp++;
            if (host) {
                Value *base = vars->seg[n >> 14];
                Value *var = base ? &base[n & 0x3FFF] : 0;
                sp->f = host->getFloat(id, var);
            } else {
                sp->i = 0;
            }
            break;
        }
        }
    }
}
