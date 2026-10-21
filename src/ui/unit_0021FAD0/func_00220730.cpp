/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Default constructor of a settings record (struct Setting is local to this source; name from the source, not RTTI):
 * the name member starts as a reference to the shared empty string D_00659FA8 (refcount incremented by the inlined string copy), size = 0x280, and the other fields get 0 or 1.
 * The field meanings are unknown; the constructor is bound to the original symbol with an asm label. */
struct Rep {int len,cap,ref,sel;};
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);

static inline char *grab(Rep *r){char *d=(char *)(r+1);if(r->sel)d=func_005C2560(r);else r->ref=r->ref+1;return d;}
struct Str {char *p;Str():p(grab(&D_00659FA8)){} };
struct Setting {Str name;int size,f8,fc,f10,f14,f18,f1c,f20;Setting() __asm__("func_00220730");};
Setting::Setting():size(0x280),f8(0),fc(1),f10(0),f14(1),f18(0),f1c(0),f20(0){}
