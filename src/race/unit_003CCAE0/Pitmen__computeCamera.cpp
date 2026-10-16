/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Camera { char pad[0x789C - 4]; };
struct Blk { char pad0[0x34]; char offset[0xA0 - 0x34]; };
struct Pitmen {
    int unk0;
    Camera camera;
    Blk blk[6];
};
extern "C" int Pitmen__isValid(Pitmen *self) throw();
extern "C" void *func_003CC840(Pitmen *self) throw();
extern "C" int Pitmen__getCameraRandom(Pitmen *self) throw();
extern "C" int Pitmen__Camera__computeCamera(Camera *self, void *motion, void *offset, void *ctx, int id, int sequence) throw();

extern "C" int Pitmen__computeCamera(Pitmen *self, int team, void *ctx) {
    if (!Pitmen__isValid(self)) {
        return Pitmen__Camera__computeCamera(&self->camera, 0, 0, 0, 0, Pitmen__getCameraRandom(self));
    }
    return Pitmen__Camera__computeCamera(&self->camera, func_003CC840(self), self->blk[team].offset, ctx, team, Pitmen__getCameraRandom(self));
}
