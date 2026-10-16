struct Obj { char pad[16]; char *p; };

extern "C" void func_005CCF08(Obj *o, const void *source) {
    __builtin_memcpy(o->p + 0x13F8, source, 0x258);
}
