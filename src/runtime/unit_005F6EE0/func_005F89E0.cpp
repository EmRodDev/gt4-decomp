typedef float f32;
struct Obj;

extern "C" void Oscillator__setWaveform(Obj *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_005F89E0(char *arg0, f32 fparg0, f32 fparg1) {
    Oscillator__setWaveform((Obj *)(arg0 + 0x44), fparg0, fparg1);
}
