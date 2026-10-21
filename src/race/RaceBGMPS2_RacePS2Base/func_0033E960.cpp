/* Builds a temporary 0x70-byte CameraBase-derived object (destroyed at the end through CameraBase::structor_1), fills it from a
 * parameter id, a position and a float, and hands it to func_0044E660 together with the value at +0xE330 and its half. The
 * directory name (BGM) does not look like what the code does; purpose unknown. */
struct Vec3 { float x; float y; float z; };
struct Y4 { char pad0[4]; void *p4; };
struct X80 { char pad0[0x80]; Y4 *y80; };
struct Self { char pad0[0x6C]; X80 *x6c; char pad1[0xE330 - 0x70]; int e330; };

extern char D_006883F8[];

extern "C" void func_0044EEA8(void *self);
extern "C" void func_0044F058(void *self, int firstArg, float paramId, float position, float lastArg, float arg5);
extern "C" void func_0044E660(int self, void *firstArg, void *paramId, int position, int lastArg, int arg5);
extern "C" void CameraBase__structor_1(void *self, int firstArg);

extern "C" void func_0033E960(Self *self, int firstArg, int paramId, Vec3 *position, int lastArg, float value) {
    char cameraTemp[0x70];
    int e330Value = self->e330;
    func_0044EEA8(cameraTemp);
    func_0044F058(cameraTemp, paramId, position->x, position->y, position->z, value);
    func_0044E660(firstArg, self->x6c->y80->p4, cameraTemp, lastArg, e330Value >> 1, e330Value);
    *(int *)cameraTemp = (int)D_006883F8;
    CameraBase__structor_1(cameraTemp, 0);
}
