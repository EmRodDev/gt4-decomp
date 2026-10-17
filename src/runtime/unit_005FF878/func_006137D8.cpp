/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct FifoBase {
    u32 writeIndex;
    u32 readIndex;
    s32 count;
    char *storage;
    u32 elementSize;
    u32 capacity;
    char unknown18[4];
};

struct InterruptSection {
    s32 depth;
    s32 previouslyEnabled;
};

struct RecursiveMutex {
    char opaque[0x28];
};

extern "C" void func_00576100(InterruptSection *);
extern "C" void func_00576140(InterruptSection *);
extern "C" void func_00576788(void *mutex);
extern "C" void func_005767C0(void *mutex);
extern "C" void *func_005A4724(void *, const void *, unsigned int);

struct ScopedInterruptGuard {
    InterruptSection *section;
    ScopedInterruptGuard(InterruptSection *s) : section(s) { func_00576100(section); }
    ~ScopedInterruptGuard() { func_00576140(section); }
};

struct ScopedRecursiveMutex {
    void *mutex;
    ScopedRecursiveMutex(void *m) : mutex(m) { func_00576788(mutex); }
    ~ScopedRecursiveMutex() { func_005767C0(mutex); }
};

struct CSFifoBase : FifoBase {
    InterruptSection interruptSection;
};

struct MTFifoBase : FifoBase {
    RecursiveMutex mutex;
};

extern "C" void func_0057B410(FifoBase *, s32);
extern "C" void func_006137D8(MTFifoBase *self, const void *input) {
    ScopedRecursiveMutex guard(&self->mutex);
    char *storage = self->storage;
    u32 elementSize = self->elementSize;
    u32 writeIndex = self->writeIndex;
    func_005A4724(storage + writeIndex * elementSize, input, elementSize);
    func_0057B410(self, 1);
}
