/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 u128 q;
 V() {} V(const V &v) {q=v.q;}
 V &operator=(const V &v) {q=v.q;return *this;}
};
struct M3 {u128 r[3];};
struct Segment;
struct Transform {V pos; M3 m; Transform(Segment &s);};
struct Segment { V pos; M3 m; V delta; };
struct Face { Segment edge; V u,v; };
struct Self { Face first; Segment a[8]; Face second; Segment b[10]; };
extern "C" V func_004187A0(Transform *,const V *) throw();
extern "C" V func_0041B898(Segment *);
extern "C" M3 *func_00421C58(M3 *,void *);
inline Transform::Transform(Segment &s) : pos(s.pos) {
 func_00421C58(&m,&s.m);
}
extern "C" Self *func_0041AA50(Self *self,int unused,const V *v) {
 self->first.edge.pos=*v;
 self->a[0].pos=func_004187A0(&Transform(self->first.edge),&self->first.u);
 self->a[1].pos=func_004187A0(&Transform(self->first.edge),&self->first.v);
 self->a[2].pos=func_0041B898(&self->a[0]);
 self->a[3].pos=func_0041B898(&self->a[1]);
 self->a[4].pos=func_0041B898(&self->a[2]);
 self->a[5].pos=func_0041B898(&self->a[3]);
 self->a[6].pos=func_0041B898(&self->first.edge);
 self->a[7].pos=func_0041B898(&self->a[6]);
 self->second.edge.pos=func_0041B898(&self->a[7]);
 self->b[5].pos=func_004187A0(&Transform(self->second.edge),&self->second.u);
 self->b[6].pos=func_004187A0(&Transform(self->second.edge),&self->second.v);
 self->b[0].pos=func_0041B898(&self->b[5]);
 self->b[1].pos=func_0041B898(&self->b[6]);
 self->b[2].pos=func_0041B898(&self->b[0]);
 self->b[3].pos=func_0041B898(&self->b[1]);
 self->b[9].pos=func_0041B898(&self->second.edge);
 self->b[7].pos=func_0041B898(&self->b[2]);
 self->b[8].pos=func_0041B898(&self->b[3]);
 self->b[4].pos=func_0041B898(&self->b[9]);
 return self;
}
