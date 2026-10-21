/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Params { char pad[0x30]; short a,b,c; };
struct State {
    int f0, f4, f8, n, block, blocks, f18, order, total;
    int f24, f28, f2c, f30, f34;
    int *history0, *output, *history1, *noise, *samples;
    int f4c, f50, f54; short *coeff; int *mem; int f60, delay;
    short level, recent[3]; int recentIndex, f74; Params **params; int paramIndex, enabled;
};
extern "C" void func_00567F28(void *,void *,int);
extern "C" float func_00568020(float);
extern "C" void func_0056DD70(short,short *,short *,int);
extern "C" void func_0056DF58(int *,short *,short *,int *,int,int,int *);
extern "C" void func_0056E170(int *,short *,int *,int,int,int *);
extern "C" float func_0057D488(float);
static inline float root(float x) { float r; __asm__("sqrt.s %0,%1":"=f"(r):"f"(x)); return r; }
static inline short median(State *s) {
    if (s->recent[0] < s->recent[1]) { if (s->recent[1] < s->recent[2]) return s->recent[1]; return s->recent[0] < s->recent[2] ? s->recent[2] : s->recent[0]; }
    if (s->recent[2] < s->recent[1]) return s->recent[1]; return s->recent[2] < s->recent[0] ? s->recent[2] : s->recent[0];
}
#define ALLOC(dst) scratch += (16 - scratch) & 15; scratch += allocSize; short *dst = (short *)(scratch - s->order * 2 - 2);
extern "C" void func_0056A290(State *s, short *out, int scratch) {
    float decay, weight, rms, amplitude;
    int i;
    float x = (float)s->f8;
    decay = func_0057D488(x * -0x1.47ae14p-5f * x);
    short m = median(s);
    if (m < s->level) s->level = m;
    weight = (float)s->level * 0.015625f;
    if (weight > 0x1.e66666p-1f) weight = 0x1.e66666p-1f;
    weight *= decay;
    func_00567F28(s->history0,s->history0+s->n,(s->total-s->n)*4);
    func_00567F28(s->history1,s->history1+s->n,(s->total-s->n)*4);
    scratch += (16 - scratch) & 15;
    int allocSize = s->order * 2 + 2;
    scratch += allocSize;
    short *tmp0 = (short *)(scratch - s->order * 2 - 2);
    ALLOC(tmp1)
    ALLOC(tmp2)
    for (int b = 0; b < s->blocks; ++b) {
        int *dest = s->output + s->block * b;
        int *data = s->noise + s->block * b;
        if (s->enabled) {
            Params *p = s->params[s->paramIndex];
            short a,b,c;
            if (p) { a=p->a; b=p->b; c=p->c; }
            else { b=0x5999; a=0x5999; c=0; }
            func_0056DD70(a,s->coeff,tmp0,s->order);
            func_0056DD70(b,s->coeff,tmp1,s->order);
            func_0056DD70(c,s->coeff,tmp2,s->order);
        }
        rms = 0;
        int n = s->n;
        if (n > 0) { i=n; int *p = s->samples; do { float v = (float)*p++; rms += v*v; } while (--i); }
        __asm__("sqrt.s %0,%1":"=f"(rms):"f"(rms / (float)n));
        i=0;
        if (s->block > 0) {
            int *p = data;
            for (i=0; i<s->block; ++i,++p) {
                __asm__("sqrt.s %0,%1":"=f"(amplitude):"f"(1.0f-weight));
                float r = func_00568020(rms);
                *p = (int)(weight*(float)data[i-s->delay] + decay*amplitude*r);
            }
            for (i=0;i<s->block;++i) dest[i] = data[i];
        }
        if (s->enabled) {
            func_0056DF58(dest,tmp1,tmp0,dest,s->block,s->order,s->mem+s->order);
            func_0056DF58(dest,tmp2,s->coeff,dest,s->block,s->order,s->mem);
        } else {
            for (i=0;i<s->order;++i) s->mem[s->order+i]=0;
            func_0056E170(dest,s->coeff,dest,s->block,s->order,s->mem);
        }
    }
    i=0;
    if (i<s->n) { short *outp = out;
    do {
        int v = (s->output[i]+0x2000)>>14;
        if (v>32767) v=32767;
        if (v<-32767) v=-32767;
        *outp++=v;
        ++i;
    } while(i<s->n); }
    s->f4=0;
    s->f8++;
    int *idx = &s->recentIndex;
    int j = *idx;
    s->recent[j]=(int)(weight*64.0f);
    ++j; *idx = j;
    if (j>=3) *idx=0;
}
