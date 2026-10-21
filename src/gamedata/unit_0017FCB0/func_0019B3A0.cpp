/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds a render/encode job from a camera-like object and returns a result string (or the constant D_006925F8 when self->p is null). It fills a 0x40-byte local descriptor with defaults (a1c..a24 = 1,1,3,1.0f), copies the settings block of the object returned by func_00197788(slot) or, when that is null, the one at self->p, runs the func_00331xxx setup calls on it, then calls func_001CAF30 to produce a byte vector and formats it with func_001CAD08. Both temporary buffers are freed at the end. The exact meaning (looks like a screenshot/thumbnail encoder, inferred from the vector sizing in func_001CAF30) is a guess. */
typedef int s32;

struct Cam {
    char pad[0x18];
    s32 f18;
};

struct Src {
    char pad[0x10];
    s32 a10;
    s32 a14;
    s32 a18;
    s32 a1c;
    s32 a20;
    float a24;
};

struct Obj {
    char pad[0xEC];
    Src *p;
};

struct Loc {
    s32 w0;
    s32 a4;
    s32 a8;
    s32 aC;
    s32 a10;
    s32 a14;
    s32 a18;
    s32 a1c;
    s32 a20;
    float a24;
    char pad[0x18];
};

struct Tmp {
    s32 x;
    char pad[0xC];
};

struct Vec {
    char pad[4];
    s32 b;
    s32 e;
    s32 c;
};

struct Glob {
    char pad[0x39E2C];
    s32 f;
};

extern char D_006925F8[];
extern char D_00692600[];
extern char D_00692608[];
extern Glob *D_00622F4C;

extern "C" Cam *func_00197788(s32 arg0) throw();
extern "C" s32 func_00197808(s32 arg0) throw() __attribute__((const));
extern "C" void func_001CAB90(void *);
extern "C" const char *func_001CAD08(const char *, const char *, s32, s32, s32);
extern "C" void func_001CAF30(void *, void *, void *, s32);
extern "C" void func_00331608(void *);
extern "C" void func_00331930(void *, s32, s32);
extern "C" void func_00331B40(void *);
extern "C" s32 func_00333550(void);
extern "C" void func_00335558(void *);
extern "C" void free(s32) throw();
extern "C" void *func_005CDBE8(void *, void *);

static inline void copy(Loc *d, Src *s) {
    func_005CDBE8(d, s);
    d->a10 = s->a10;
    d->a14 = s->a14;
    d->a18 = s->a18;
    d->a1c = s->a1c;
    d->a20 = s->a20;
    d->a24 = s->a24;
}

extern "C" const char *func_0019B3A0(Obj *self, s32 slot) {
    Loc job;
    Vec buffer;
    Tmp scratch;
    Cam *camera;
    Src *settings;
    Src *unused;
    s32 globalValue;
    const char *result;
    if (self->p == 0) {
        return D_006925F8;
    }
    job.a4 = 0;
    job.a8 = 0;
    job.aC = 0;
    job.a10 = 0;
    job.a14 = 0;
    job.a18 = 1;
    job.a1c = 1;
    job.a20 = 3;
    job.a24 = 1.0f;
    camera = func_00197788(slot);
    if (camera != 0) {
        settings = (Src *)((char *)camera + 0x1C);
        func_00335558(camera);
        copy(&job, settings);
    } else {
        settings = self->p;
        copy(&job, settings);
    }
    func_00331608(&job);
    if (camera != 0 && camera->f18 != 0) {
        func_00331B40(&job);
        func_00331930(&job, 0, 0);
    }
    if (func_00333550() == 0) {
        func_001CAB90(&job);
    }
    globalValue = func_00197808(D_00622F4C->f);
    buffer.b = 0;
    buffer.e = 0;
    buffer.c = 0;
    func_001CAF30(&buffer, &job, camera, globalValue);
    result = func_001CAD08(D_00692600, D_00692608, 10000, buffer.b, buffer.e - buffer.b);
    if (buffer.b != 0) {
        free(buffer.b);
    }
    scratch.x = job.a4;
    if (scratch.x != 0) free(scratch.x);
    return result;
}
