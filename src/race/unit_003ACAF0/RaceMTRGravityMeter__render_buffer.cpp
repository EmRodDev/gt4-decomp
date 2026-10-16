/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { char pad[0x20]; unsigned long bits; };
struct Texture { char pad[0x18]; Image *image; };
struct Self { char pad[0x18]; Texture *back,*dot,*horizontal,*vertical; float x,y; };
struct Buffer { int id,field4; };
extern "C" {
void func_00105460(Buffer*,int,int);
int func_00105528(Buffer*);
void func_001056A0(Buffer*);
void RaceMTRGravityMeter__init_texset(Self*);
void func_003AEF18(Texture*,float,float,unsigned,unsigned);
void func_003AF2F0(Texture*,float,float,unsigned,unsigned,int,int);
void func_003AF4F8(Texture*,float,float,float,float,int,int);
void func_004A1638(int);
void func_004A2750(int,float);
void func_004A27C8(int);
void func_004A2808(int,float);
void func_004A2980(int);
void func_004A29A8(int);
void func_004A3078(int);
void func_004A3230(int);
void RaceEntryCar__update(int);
void func_004A53F8();
void func_004A5400();
void pglPushAttrib(int);
void func_004A5688();
void func_004A5A90(float,float,float,float,float,float);
void func_004A7454();
void func_004AA168(int);
void func_004AB040(int);
}
static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" void RaceMTRGravityMeter__render_buffer(Self *s, Buffer *b) {
    pglPushAttrib(1);
    RaceMTRGravityMeter__init_texset(s);
    unsigned long bits = s->back->image->bits;
    int w = ((bits >> 14) & 1023) + 1;
    int h = ((bits >> 34) & 1023) + 1;
    if (b->id == -1) {
        func_00105460(b, w, h);
        b->field4 = 0;
        func_00105528(b);
    }
    func_001056A0(b);
    func_004A2980(-1);
    func_004A3078(0);
    func_004A3230(1);
    float width = (float)w;
    func_004AA168(0x80ffffff);
    func_004A1638(6);
    func_004AB040(15);
    func_004AB040(4);
    func_004AB040(5);
    float height = (float)h;
    func_004A29A8(0);
    func_004A2808(0x44, 0.0f);
    RaceEntryCar__update(1);
    func_004A53F8();
    func_004A7454();
    func_004A5A90(0.0f, width, height, 0.0f, -1.0f, 1.0f);
    RaceEntryCar__update(0);
    func_004A53F8();
    func_004A7454();
    func_003AF4F8(s->back, 0.0f, 0.0f, width, height, 0, 0);
    func_004A1638(4);
    func_004A2750(6, 0.5f);
    func_004A27C8(0);
    float x = minf(maxf(-s->x, -1.5f), 1.5f);
    float y = minf(maxf(s->y, -1.5f), 1.5f);
    x = x * 47.5f * 0x1.555554p-1f + 69.5f;
    y = y * 47.5f * 0x1.555554p-1f + 69.5f;
    func_003AEF18(s->dot, x, y, 2, 2);
    func_003AF2F0(s->horizontal, 0.0f, y, 0, 2, 0, 0);
    func_003AF2F0(s->vertical, x, 0.0f, 2, 0, 0, 0);
    func_004AB040(4);
    func_004A5400();
    RaceEntryCar__update(1);
    func_004A5400();
    RaceEntryCar__update(0);
    func_004A5688();
}
