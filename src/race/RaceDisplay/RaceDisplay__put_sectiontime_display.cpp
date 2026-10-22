struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Global { char pad[0x144]; const char *text; };
extern Global *DisplayRText__rtext_ptrs_;
extern char D_006A0770[];
extern char D_006A0470[];
extern "C" void RaceDisplayUtil__timeToString(char *, int);
extern "C" int func_0057DA20(char *, const char *, ...);
extern "C" void func_003A5268(void *, const char *, int);
extern "C" void RaceEventDisplay__addEvent(void *, const char *, float, float, float, float);
extern "C" void RaceDisplay__put_sectiontime_display(char *self, int section, int time) {
    char buf[0x40];
    char timebuf[0x20];
    char *p = self + 0x17BC;
    RaceDisplayUtil__timeToString(timebuf, time);
    const char *text = DisplayRText__rtext_ptrs_->text;
    func_0057DA20(buf, D_006A0770, text, section, timebuf);
    *(unsigned int *)(p + 0x20) = 0x80C8C8C8;
    func_003A5268(p, D_006A0470, 0);
    RaceEventDisplay__addEvent(p, buf, 3.0f, 0.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    VEntry *e = (VEntry *)(*(char **)self + 0x190);
    e->fn(self + e->delta, 0x1.6CCCCCp+1f);
}
