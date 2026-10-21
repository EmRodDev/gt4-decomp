/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor of the GT-mode race (a RaceSinglePlayer subclass): runs the RaceSinglePlayer constructor, installs its own vtable, builds the
 * embedded parts in order (a DynamicsConductorSinglePlayer at +0x125C0, six 8-byte elements at +0x22708, a RacePause at +0x22738, then
 * blocks at +0x22770, +0x23AB0, +0x23BB8 and a ResultArcade at +0x23BCC) and links two of them and the conductor into the object (+0xE408,
 * +0xE410, +0x70). When 0033CF48 returns 0 the pause block gets +0x2C = 1 and the four later blocks receive the shared block at +0xE350.
 * +0xD68 is set to 0xD last; its meaning is purpose unknown. */
typedef int s32;
struct Z { char pad[0x2C]; s32 f2C; };
struct Obj {
    char pad0[0x64]; void *vtable; char pad68[8]; void *conductorPtr;
    char pad74[0xD68 - 0x74]; s32 modeValue;
    char padD6C[0xE408 - 0xD6C]; void *linkedBlockA; char pad40C[4]; void *linkedBlockB;
};
struct E { char b[8]; };
extern char RaceGTmode__vtable[];
extern "C" s32 RaceSinglePlayer__structor_0(Obj *);
extern "C" void DynamicsConductorSinglePlayer__structor_1(void *);
extern "C" void func_00393700(void *);
extern "C" void RacePause__structor_0(void *);
extern "C" void func_003D7700(void *);
extern "C" void func_003DCA28(void *);
extern "C" void func_003BAB90(void *);
extern "C" void ResultArcade__structor_0(void *);
extern "C" s32 func_0033CF48(void);
extern "C" void func_003C31C8(void *, void *);
extern "C" void func_003D8490(void *, void *);
extern "C" void func_003DD4B8(void *, void *);
extern "C" void func_003DF898(void *, void *);
extern "C" int RaceGTmode__structor_0(Obj *self) {
    RaceSinglePlayer__structor_0(self);
    self->vtable = RaceGTmode__vtable;
    DynamicsConductorSinglePlayer__structor_1((char *)self + 0x125C0);
    E *array22708 = (E *)((char *)self + 0x22708);
    for (s32 i = 5; i != -1; i--) func_00393700(array22708++);
    Z *pauseBlock = (Z *)((char *)self + 0x22738);
    char *block22770 = (char *)self + 0x22770;
    char *block23AB0 = (char *)self + 0x23AB0;
    RacePause__structor_0(pauseBlock);
    func_003D7700(block22770);
    char *block23BB8 = (char *)self + 0x23BB8;
    func_003DCA28(block23AB0);
    char *resultArcade = (char *)self + 0x23BCC;
    func_003BAB90(block23BB8);
    ResultArcade__structor_0(resultArcade);
    self->linkedBlockA = block23AB0;
    self->linkedBlockB = block23BB8;
    self->conductorPtr = (char *)self + 0x125C0;
    if (func_0033CF48() == 0) {
        char *sharedBlock = (char *)self + 0xE350;
        pauseBlock->f2C = 1;
        func_003C31C8(pauseBlock, sharedBlock);
        func_003D8490(block22770, sharedBlock);
        func_003DD4B8(block23AB0, sharedBlock);
        func_003DF898(resultArcade, sharedBlock);
    }
    self->modeValue = 0xD;
}
