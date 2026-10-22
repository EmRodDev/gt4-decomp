/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initializes a block of polymorphic parts and then calls func_00419810 with the same two arguments, returning its
 * result (so it is the first half of a constructor, inferred). The block holds a 0x70-byte face part (vtable
 * D_00686518), 8 segment parts (vtable D_00686570, 0x50 bytes each), a second face part and 10 more segments.
 * Every part gets the vector (0, 0, 0, 1) at +0x10, its vtable pointer at +0x20 and the two floats at +0x40 and
 * +0x44 set to 0 (the vector is probably a homogeneous point, inferred from the w = 1). Whether the parts are
 * drawn shapes or something else is unknown. The inline helpers are kept as in the matched source. */
struct Vec { float x,y,z,w; };
struct Segment { char p0[16]; Vec v; void *vt; char p24[28]; float a,b; char p48[8]; };
struct Face { Segment s; char p50[32]; };
struct Self { Face f; Segment a0,a1,a2,a3,a4,a5,a6,a7; Face g; Segment b0,b1,b2,b3,b4,b5,b6,b7,b8,b9; };
extern char D_00686518[], D_00686570[];
extern "C" int func_00419810(Self*,void*);
static inline void vec(Vec *v) { v->x=0.0f; v->y=0.0f; v->z=0.0f; v->w=1.0f; }
static inline void seg(Segment *s,void *vt) { vec(&s->v); s->vt=vt; s->a=0.0f; s->b=0.0f; }
static inline void face(Face *s) { vec(&s->s.v); s->s.a=0.0f; s->s.b=0.0f; s->s.vt=D_00686518; }
extern "C" int func_00419430(Self *s, void *param) {
face(&s->f);
seg(&s->a0,D_00686570); seg(&s->a1,D_00686570); seg(&s->a2,D_00686570); seg(&s->a3,D_00686570);
seg(&s->a4,D_00686570); seg(&s->a5,D_00686570); seg(&s->a6,D_00686570); seg(&s->a7,D_00686570);
face(&s->g);
seg(&s->b0,D_00686570); seg(&s->b1,D_00686570); seg(&s->b2,D_00686570); seg(&s->b3,D_00686570);
seg(&s->b4,D_00686570); seg(&s->b5,D_00686570); seg(&s->b6,D_00686570); seg(&s->b7,D_00686570); seg(&s->b8,D_00686570); seg(&s->b9,D_00686570);
return func_00419810(s,param);
}
