/* compiler: ee-gcc2.96-no-strict-aliasing */
/* RaceDisplay::get_session_best_time: the race's best time in modes 3-11 and 15-18, otherwise the
   session's. The cases are separate labels, as in the original: merged into ranges they would not
   compile to the jump table at 0x6A06C0, and the epilogue at 0x39F1E0 is that table's target. */
struct VEntry { short delta, index; int (*fn)(void *); };
struct Mode { char pad[0x64]; char *vtable; };
struct Race { char pad[0x84]; Mode *mode; char pad88[0x968 - 0x88]; int best_time; };
struct RaceDisplay { int word; Race *race; };
struct Session { char pad[0x18]; int id; };
extern "C" int func_0035E3F0(int);

extern "C" int RaceDisplay__get_session_best_time(RaceDisplay *self, Session *session) {
    Mode *mode = self->race->mode;
    if (mode) {
        VEntry *e = (VEntry *)(mode->vtable + 0x2F8);
        switch (e->fn((char *)mode + e->delta)) {
        case 3: goto best;
        case 4: goto best;
        case 5: goto best;
        case 6: goto best;
        case 7: goto best;
        case 8: goto best;
        case 9: goto best;
        case 10: goto best;
        case 11: goto best;
        case 12: case 13: case 14: break;
        case 15: goto best;
        case 16: goto best;
        case 17: goto best;
        case 18: goto best;
        }
    }
    return func_0035E3F0(session->id);
best:
    return self->race->best_time;
}
