/* compiler: ee-gcc2.96-stl */
typedef int s32;
typedef long long s64;
typedef float f32;
struct Data { char pad[0xD0]; s32 start; s32 replay; };
struct Path { s32 a; Data *data; };
struct Car { char p[0x18]; void *obj; char p2[0x3444-0x1C]; s32 flags; };
struct Context { char p[8]; s32 mode; s32 c; Car *car; };
struct Obj {
    char p[0xE8]; s32 flags;
    char p2[0x148-0xEC]; s32 type;
    char p3[0x180-0x14C]; Path *path;
    s32 m184; s32 m188; s32 m18C; s32 m190; s32 m194;
    f32 pos[3]; f32 rot[3]; f32 out[3]; f32 last[3];
    char p4[8]; s64 state;
};
struct Output { f32 x; s32 index; f32 *last; s32 pad; };
extern "C" void func_00378CB8(void *) throw();
extern "C" int func_005A48D8(void *, int, unsigned int);
extern "C" void func_003EBBA0(void *, s32, const char *);
extern "C" f32 func_00344798(void *, f32);
extern "C" f32 func_003447F8(void *, f32);
extern "C" f32 func_00344828(void *, f32);
extern "C" f32 func_003448B8(void *, f32);
extern "C" void func_003FCA08(f32 *, Output *, Path *, s32);
extern "C" f32 func_003FE358(Path *, f32 *, s32 *);
extern char D_0069FB48[], D_0069FB60[];
extern "C" void CameraSys__CameraPathanim__initialize(Obj *o, Context *ctx, Path *path, s32 count, s32 mode) {
    Output result;
    func_00378CB8(o);
    o->type = 6;
    o->flags = 1;
    if (count <= 0) o->flags = 3;
    o->path = path;
    o->m194 = -1;
    o->m18C = 0;
    f32 *pos = o->pos;
    f32 *rot = o->rot;
    func_005A48D8(pos, 0, 12);
    f32 *out = o->out;
    f32 *last = o->last;
    func_005A48D8(rot, 0, 12);
    result.last = last;
    s64 mask = ~0xFF00LL;
    func_005A48D8(out, 0, 12);
    func_005A48D8(result.last, 0, 12);
    s64 low = mode & 0xFF;
    o->state = ((o->state & ~0xFFLL) | low) & mask;
    if (path) {
        Data *data = path->data;
        o->m18C = mode ? count + 60 : count - 60;
        s32 *target = &o->m184;
        if (mode) {
            func_003EBBA0(target, data->replay, D_0069FB48);
        } else {
            func_003EBBA0(target, data->start, D_0069FB60);
            s64 state = o->state & mask;
            o->state = state;
            if (ctx->car && (ctx->car->flags & 1)) o->state = state | 0x100;
        }
        if (ctx->mode == 1 && ctx->car) {
            void *car = ctx->car->obj;
            f32 x = func_00344798(car, 0.0f);
            f32 y = func_003447F8(car, 0.0f);
            f32 z = func_00344828(car, 0.0f);
            pos[0] = x;
            o->pos[1] = y;
            o->pos[2] = z;
            rot[0] = -func_003448B8(car, 0.0f) * 0x1.ca5dcp+5f;
        }
        result.index = -1;
        func_003FCA08(out, &result, path, 0);
        result.last[0] = result.x;
        f32 y = func_003FE358(path, out, &result.index);
        if (result.index < 0) y = o->pos[1];
        o->out[1] = y;
    }
}
