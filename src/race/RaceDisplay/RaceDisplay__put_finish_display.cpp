/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void (*fn)(void *, float); };
struct Message { char pad[0x18]; float x; float y; unsigned int color; };
struct Obj {
    char *vt;
    char pad4[0xbc - 4];
    char unkBC[1];
    char padBD[0x252c - 0xbc - 1];
    Message msg252C;
};
struct Text { char pad[0x12c]; const char *start; const char *finish; };
extern Text *DisplayRText__rtext_ptrs_;
extern "C" int RaceDisplay__is_play_mode(Obj *);
extern "C" const char *RaceDisplay__get_race_signal_font(Obj *) throw();
extern "C" void RaceMessageDisplay__setFont(void *, const char *, long);
extern "C" void AutomaticFader__oneshot(void *, float, float, float, float);
extern "C" void RaceMessageDisplay__setMessage(void *, const char *, float, float);
static inline void position(Message *m, float x, float y) { m->x = x; m->y = y; }
extern "C" void RaceDisplay__put_finish_display(Obj *self) {
    if (RaceDisplay__is_play_mode(self)) {
        const char *font = RaceDisplay__get_race_signal_font(self);
        Message *m = &self->msg252C;
        RaceMessageDisplay__setFont(m, font, 0);
        m->color = 0x80c8c8c8;
        position(m, 0.0f, 0x1.333332p-2f);
        RaceMessageDisplay__setMessage(m, DisplayRText__rtext_ptrs_->finish, 0x1.d99998p+1f, 0.0f);
        AutomaticFader__oneshot(self->unkBC, 0.0f, 1.0f, 0.0f, 0.25f);
    }
}
