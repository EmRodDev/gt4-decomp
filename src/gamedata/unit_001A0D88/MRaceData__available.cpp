/* compiler: ee-gcc2.96-no-strict-aliasing */
// MRaceData script adapter: a missing argument yields false; otherwise query by name.
// Nontrivial handle copies preserve the original indirect class-return ABI.
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" long func_00447C50(const char *);
extern "C" void func_00326798(void *, int, int, const char *);
struct AllocationTag { const char *name; };
extern "C" AllocationTag *func_005C11A8();
extern char D_006927F0[];
struct StringRep {
    int length, capacity, references, selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](unsigned int n) { return data()[n]; }
};
struct String {
    char *data;
    String();
    String(const String &);
    StringRep *rep() const { return (StringRep *)data - 1; }
    unsigned int length() const { return rep()->length; }
    char *characters() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (!length()) return D_006927F0;
        terminate();
        return characters();
    }
    ~String() {
        StringRep *rep = (StringRep *)data - 1;
        if (--rep->references == 0) {
            int bytes = rep->capacity + 16;
            func_00326798(rep, bytes, 4, func_005C11A8()->name);
        }
    }
};
struct Object;
struct VirtualString { short delta, index; String (*call)(Object *); };
struct Object { int references; char *vtable; };
struct Handle {
    void *object;
    Handle();
    Handle(const Handle &);
    void operator=(const Handle &other) {
        if (this != &other) {
            void *next = other.object;
            if (next) func_003285A8(next);
            if (object) func_003285F8(object);
            object = next;
        }
    }
};
struct IntegerHandle: Handle {
    IntegerHandle(int) __asm__("func_002FE278");
    ~IntegerHandle() __asm__("func_002FC870");
};
extern "C" void MRaceData__available(Handle *result, int argc, Object **argv) {
    int success = 0;
    if (argc > 0) {
        const char *text;
        // The temporary string is released before the lookup, following the
        // original full-expression lifetime.
        {
            Object *object = *argv;
            VirtualString *entry = (VirtualString *)(object->vtable + 0x18);
            String string = entry->call((Object *)((char *)object + entry->delta));
            text = string.c_str();
        }
        success = func_00447C50(text) != -1;
    }
    IntegerHandle answer(success);
    *result = answer;
}
