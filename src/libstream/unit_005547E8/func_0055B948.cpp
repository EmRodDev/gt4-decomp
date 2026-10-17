/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct EventCursor {
    u8 *position;

    u8 get() { return *position++; }
};

// Partial MIDI stream view; the event code, cursor, and state offsets are observed.
struct MidiStream {
    char unknown00[0x34];
    s32 eventCode;
    char unknown38[0x20];
    EventCursor cursor;
    s32 unknown5C;
    s32 state60;
};

extern "C" void func_0055A858(MidiStream *self, float beatsPerMinute);

extern "C" void func_0055B948(MidiStream *self) {
    if (self->eventCode == 0xFF) {
        u8 eventType = self->cursor.get();
        u8 eventLength = self->cursor.get();

        switch (eventType) {
        case 0x2F:
            self->state60 = 3;
            self->cursor.position = 0;
            break;
        case 0x51: {
            s32 microsecondsPerQuarter = (s32)self->cursor.get() << 16;
            microsecondsPerQuarter |= (s32)self->cursor.get() << 8;
            microsecondsPerQuarter |= self->cursor.get();
            return func_0055A858(self, 60000000.0f / (float)microsecondsPerQuarter);
        }
        default:
            self->cursor.position += eventLength;
            break;
        }
    }
}
