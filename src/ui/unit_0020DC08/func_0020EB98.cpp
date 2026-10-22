/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Writes the string between double quotes to the stream at +8, escaping '"' and '\\' with a backslash
 * (libstdc++ v2 basic_string: the length sits in the Rep 16 bytes before the text, and the const
 * operator[] returns eos() == 0 at pos == length()). */
struct Rep {
    int len;
    int res;
    int ref;
    int selfish;
    char *data() { return (char *)(this + 1); }
};

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    int length() const { return rep()->len; }
    const char *data() const { return rep()->data(); }
    static char eos() { return 0; }
    char operator[](int pos) const {
        if (pos == length()) return eos();
        return data()[pos];
    }
};

struct Strm { int pad0;
 virtual void unused0();
 virtual void unused1();
 virtual void unused2();
 virtual void unused3();
 virtual void unused4();
 virtual void unused5();
 virtual void unused6();
 virtual void unused7();
 virtual void unused8();
 virtual void unused9();
 virtual void unused10();
 virtual void unused11();
 virtual void unused12();
 virtual void unused13();
 virtual void unused14();
 virtual void unused15();
 virtual void unused16();
 virtual void unused17();
 virtual void unused18();
 virtual void unused19();
 virtual void unused20();
 virtual void unused21();
 virtual void unused22();
 virtual void unused23();
 virtual void unused24();
 virtual void unused25();
 virtual void unused26();
 virtual void unused27();
 virtual void unused28();
 virtual void unused29();
 virtual void unused30();
 virtual void unused31();
 virtual void unused32();
 virtual void unused33();
 virtual void unused34();
 virtual void unused35();
 virtual void unused36();
 virtual void unused37();
 virtual void unused38();
 virtual void unused39();
 virtual void unused40();
 virtual void unused41();
 virtual void unused42();
 virtual void unused43();
 virtual void unused44();
 virtual void unused45();
 virtual void unused46();
 virtual void unused47();
 virtual void unused48();
 virtual void unused49();
 virtual void unused50();
 virtual void unused51();
 virtual void unused52();
 virtual void unused53();
 virtual void unused54();
 virtual void put(int);
};

struct StrmRef {
    Strm *p;
    Strm *operator->() const { return p; }
};

struct Self {
    int pad0[2];
    StrmRef out;
};

extern "C" void func_0020EB98(Self *self, const String &s) {
    self->out->put('"');
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '"') self->out->put('\\');
        if (s[i] == '\\') self->out->put('\\');
        self->out->put(s[i]);
    }
    self->out->put('"');
}
