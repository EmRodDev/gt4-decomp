/* compiler: ee-gcc2.96-no-strict-aliasing */
// Script adapter: obtain the players in the requested lobby, or the current lobby.
// Reference-counted handles use nontrivial copies and indirect class returns.
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Handle {
    void *object;
    Handle();
    Handle(const Handle &);
    Handle &operator=(const Handle &other) {
        if (this != &other) {
            void *next = other.object;
            if (next) func_003285A8(next);
            if (object) func_003285F8(object);
            object = next;
        }
        return *this;
    }
};
struct NetworkHandle : Handle {
    NetworkHandle(void *) __asm__("func_001DC650");
    ~NetworkHandle() __asm__("func_001DC5F8");
};
extern "C" int func_002FE250(void *);
struct IntegerHandle : Handle {
    int value() const { return func_002FE250(object); }
    IntegerHandle(void *) __asm__("func_002FC8C8");
    ~IntegerHandle() __asm__("func_002FC870");
};
struct ArrayHandle : Handle {
    ~ArrayHandle() __asm__("func_002ED5C0");
};
extern "C" int func_001F3398(void *);
extern "C" ArrayHandle func_001F2FF8(void *, int);
extern "C" void MNetwork__getLobbyPlayers(Handle *result, void *context, int argc, void *argv) {
    NetworkHandle network(context);
    int lobby;
    if (argc > 0) {
        IntegerHandle argument(argv);
        lobby = argument.value();
    } else {
        lobby = func_001F3398(network.object);
    }
    ArrayHandle players = func_001F2FF8(network.object, lobby);
    *result = players;
}
