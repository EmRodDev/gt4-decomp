/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub {char pad0[0x441]; unsigned char u441; char pad1[0x466-0x442]; signed char s466; unsigned char u467; char pad2[0x4B2-0x468]; unsigned char u4B2;};
struct Main {char pad[0x84]; char *p84; char pad2[0xE0-0x88]; int e0;};
struct Obj {Main *m; char pad[0x100]; Sub sub;};
extern "C" int Automobile__getDrawMode(Obj *self){
    Sub *s = &self->sub;
    if (s->u441 == 0) return 3;
    int special = s->s466;
    if (special == 4) return s->u4B2 ? 0 : 2;
    Main *m = self->m;
    if (m->e0 == 0) {
        if (*(int *)(m->p84 + 0xF050) == 0) return 1;
    }
    if (s->s466 != 2) {
        unsigned char u = s->u467;
        if (u != 6 && u != 8 && u != 1) return 2;
    }
    return 0;
}
