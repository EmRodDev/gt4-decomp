/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct VEntry { short delta; short index; void (*fn)(void *, void *, void *, int, int, float, int, int); };
struct Obj { VEntry *vt; };
struct Model {
    int x0;
    int owner;
    char pad8[0x10];
    char car_model[0x5C8];
    char driver_model[0x840];
    char crew_model[0x840];
    Obj *obj0;
    Obj *obj1;
    int x1668;
    int x166c;
    int flag0;
    int flag1;
};
struct Geo { char data[0x20]; };
extern "C" void CarGeometry__structor_0(void *, int, int) throw();
extern "C" void RaceCarModel__virtual_29(Model *self, int p, int q, float t) {
    Geo a; Geo b;
    if (self->flag0) {
        CarGeometry__structor_0(&a, self->owner, 0);
        Obj *o = self->obj0;
        if (o) {
            VEntry *e = o->vt + 1;
            e->fn((char *)o + e->delta, self->driver_model, &a, self->owner, 1, t, p, q);
        }
        if (self->flag1) {
            Geo *pb = &b;
            CarGeometry__structor_0(pb, self->owner, 1);
            Obj *o = self->obj1;
            if (o) {
                VEntry *e = o->vt + 1;
                e->fn((char *)o + e->delta, self->crew_model, pb, self->owner, 0, t, p, q);
            }
        }
    }
}
