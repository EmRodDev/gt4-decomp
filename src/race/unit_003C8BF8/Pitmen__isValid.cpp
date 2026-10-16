/* compiler: ee-gcc2.96-no-strict-aliasing */
struct ScenePack;
struct Pitmen { ScenePack *pack; char pad[0x9904]; int flag; };
extern "C" int ScenePack__isValid(ScenePack *);
extern "C" int Pitmen__isValid(Pitmen *self) {
    if (self->flag == 0 || self->pack == 0 || ScenePack__isValid(self->pack) == 0) {
        return 0;
    }
    return 1;
}
