/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { unsigned char tag, count; char pad[0x1a]; unsigned char modes[16]; unsigned char map[16]; signed char signs[16]; };
struct State { char pad[0xC]; float a0, a1; char gap[4]; float b0, b1; };
struct Car { char pad[0x10]; float first[1]; };
struct Part { char pad[0x20]; float second[1]; };
struct Entry { char pad[0xC]; float v0, v1; char rest[0xec-0x14]; };
struct Obj { char pad[0x10]; Car *car; };
extern "C" Info *func_00359510(void *);
static inline float value(Part *p, int n) { return p->second[n]; }
static inline int positive(Info *p, int n) { if(n >= p->count) return 0; return p->signs[n] > 0; }
static inline unsigned int negative(Info *p, int n) { if(n >= p->count) return 0; return p->signs[n] < 0; }
extern "C" void func_003458D0(Obj *self) {
    State *state = (State *)((char *)self + 0x104);
    Car *car = self->car;
    Info *info = func_00359510(car);
    int i = 0;
    if(info->count != 0) {
        Entry *e = (Entry *)((char *)self + 0x164);
        do {
            int j = info->map[i];
            float v = value((Part *)((char *)car + 8), j);
            float x0 = state->b0 * v;
            float x1 = state->b1 * v;
            int mode = info->modes[i];
            if(mode == 0) { e->v0 = -x0; e->v1 = -x1; }
            else if((mode ^ 1) == 0) { e->v0 = x0; e->v1 = x1; }
            else { e->v0 = 0; e->v1 = 0; }
            float w = car->first[j];
            float y0 = state->a0 * w;
            float y1 = state->a1 * w;
            if(positive(info,i)) { e->v0 += y0; e->v1 += y1; }
            else if(negative(info,i)) { e->v0 -= y0; e->v1 -= y1; }
            i++;
            e++;
        } while(i < info->count);
    }
}
